#ifndef GUARD_MLASKAL_LABELED_ICBLOCK_H_
#define GUARD_MLASKAL_LABELED_ICBLOCK_H_

/*

	labeled_icblock.hpp

	Labeled IC block (instructions with abstract labels and literals)

	Kuba, 2006

*/

#include <map>
#include <vector>
#include <set>
#include <stdexcept>
#include <utility>

#include "plain_icblock.hpp"
#include "abstract_instr.hpp"
#include "ic_instr.hpp"
#include "flat_icblock.hpp"

/// namespace containing concrete instruction classes
namespace ai {}

namespace mlaskal {

	class ftor_fnc_trans_body;	// publisher for a functor which uses the private constructor
	struct less_labels_bkmap;
	struct ftor_labels_bkmap_label;

	/// owner pointer to instruction
	typedef abstract_instr * ai_ptr;

	/// creates one instruction without a target
	template< typename I, typename ... AL>
	ai_ptr make_ai(AL && ... al)
	{
		return new I(std::forward< AL>(al) ...);
	}

	/// intermediate code block
	typedef std::shared_ptr< labeled_icblock> labeled_icblock_pointer;

	/// code block 
	/** 
		contains a sequence of instructions and labels
	**/
	class labeled_icblock {
	public:
		/// constructs an empty labeled_icblock
		labeled_icblock() { }			// an empty block

		labeled_icblock(plain_icblock<ic_instr>::const_iterator first, 
						plain_icblock<ic_instr>::const_iterator last, 
						const abstract_ic &aic, 
						const flat_icblock &ficb); // constructing from flat block - do not use this one

		// container requirements
		/// container requirement: value_type
		typedef plain_icblock<abstract_instr>::value_type value_type;
		/// container requirement: reference
		typedef plain_icblock<abstract_instr>::value_type & reference;
		/// container requirement: const_reference
		typedef const plain_icblock<abstract_instr>::value_type & const_reference;
		/// container requirement: size_type
		typedef plain_icblock<abstract_instr>::size_type size_type;
		/// container requirement: iterator
		typedef plain_icblock<abstract_instr>::iterator iterator;
		/// container requirement: const_iterator
		typedef plain_icblock<abstract_instr>::const_iterator const_iterator;

		/// container requirement: size
		size_type size() const { return block_.size(); }
		/// container requirement: empty
		bool empty() const { return !block_.size(); }
		/// container requirement: begin
		iterator begin() { return block_.begin(); }
		/// container requirement: begin
		const_iterator begin() const { return block_.begin(); }
		/// container requirement: end
		iterator end() { return block_.end(); }		
		/// container requirement: end
		const_iterator end() const { return block_.end(); }		

	private:
		void push_back(const_reference v);		// should be public, but we don't want to be used by anyone

	public:
		// custom functions

		/// @cond INTERNAL

		/// \internal
		const_iterator rel_iter(const_iterator base, ICRELNUM idx) const { return block_. rel_iter(base, idx); }
		/// \internal
		ICABSNUM compute_index(const_iterator cr) const { return block_.compute_index(cr); }

		/// @endcond

		/// type of labels
		/** 
			UIDs are used as labels
		**/
		typedef uid_all_type::UID_type label_type;

		/// appends a label to the end of the block
		/** resolves instruction targets pointing to this label **/
		void add_label(label_type lbl) { empty_labels_.insert(lbl); }

		/// locates a label in the block
		/** finds the instruction labeled with this label **/
		const_iterator locate_label(label_type lbl) 
		{ 
			std::map<label_type, const_iterator>::const_iterator it = labels_.find( lbl);
			if ( it == labels_.end() )
				return end();
			return it->second; 
		}

		/// find labels for a position
		/** finds labels for the position ci **/
		std::set<label_type> find_labels( const_iterator ci) const;

		/// appends one instruction without a target
		/** labels appended to the end of the block using add_label now point to this instruction **/
		const_iterator append_instruction(const_reference ai) 
		{ 
			if (!ai)	// ignore null instructions
				return end();
			push_back(ai); 
			return --end();
		}

		/// appends one instruction without a target
		template< typename I, typename ... AL>
		const_iterator append(AL && ... al)
		{
			return append_instruction(make_ai< I>(std::forward< AL>(al) ...));
		}

		/// appends one instruction with a target
		template< typename I, typename ... AL>
		const_iterator append_with_target(label_type tgt_lbl, AL && ... al)
		{
			return append_instruction_with_target(make_ai< I>(end(), std::forward< AL>(al) ...), tgt_lbl);
		}

		/// appends one instruction with a target
		/** labels appended to the end of the block using add_label now point to this instruction

			target label is either directly resolved, if it already existed in the block, or it is marked as unresolved and waiting for a label
		**/
		const_iterator append_instruction_with_target(const_reference ai, label_type tgt_lbl);

		template< typename ... L>
		void append_and_kill(const labeled_icblock_pointer & sicb, const L & ... sicbl)
		{
			append_clear_block(std::move(*sicb));
			append_and_kill(sicbl ...);
		}

		void append_and_kill()
		{}

	private:
		/// appends licb to the end of the block and clears the contents of the source block (source block is then empty)
		void append_clear_block(labeled_icblock &&licb);   // clears source block

		plain_icblock<abstract_instr>										block_;
		std::map<label_type, const_iterator>								labels_;
		std::set<label_type>												empty_labels_;					// labels on an empty block
		std::multimap<label_type, iterator>								targets_;
		typedef std::pair<const_iterator, label_type>						labels_bkmap_type_;
		std::vector<labels_bkmap_type_>										labels_bkmap_;
		typedef std::pair<const_iterator, label_type>						targets_bkmap_type_;
		std::vector<targets_bkmap_type_>								targets_bkmap_;

		friend class ftor_fnc_trans_body;
		friend struct less_labels_bkmap;
		friend struct ftor_labels_bkmap_label;
	};

}

#endif
