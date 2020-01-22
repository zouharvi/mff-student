#ifndef GUARD_MLASKAL_PLAIN_ICBLOCK_H_
#define GUARD_MLASKAL_PLAIN_ICBLOCK_H_

/*

	plain_icblock.hpp

	Plain IC block template (only instructions)

	Kuba, 2006

*/

#include <list>
#include <stdexcept>

#include "common_types.hpp"

namespace mlaskal {

	/// @cond INTERNAL

	template <typename T>
	class plain_icblock {
	public:
		// container requirements
		typedef T * value_type;
		typedef T * & reference;
		typedef T * const & const_reference;
		typedef typename std::list<T *>::size_type size_type;
		typedef typename std::list<T *>::iterator iterator;
		typedef typename std::list<T *>::const_iterator const_iterator;

		size_type size() const { return block_.size(); }
		bool empty() const { return block_.empty(); }
		iterator begin() { return block_.begin(); }
		const_iterator begin() const { return block_.begin(); }
		iterator end() { return block_.end(); }
		const_iterator end() const { return block_.end(); }
		void swap(plain_icblock &pb) { block_.swap(pb.block_); }

		// constructors, dectructor
		plain_icblock() { }
		~plain_icblock()
		{
			for(iterator i=block_.begin();i!=block_.end();++i)
				delete *i;
		}

		// non-trivial destructor => prohibit copying
		plain_icblock(const plain_icblock &pb) = delete;
		plain_icblock &operator=(const plain_icblock &pb) = delete;

		// allow moving
		plain_icblock(plain_icblock &&pb) = default;
		plain_icblock &operator=(plain_icblock &&pb) = default;

		// public interface
		void push_back(const value_type &v) { block_.push_back(v); }

		const_iterator at_iter(ICABSNUM idx) const
		{
		const_iterator ci;

			for(ci=block_.begin();idx && ci!=block_.end();++ci,--idx);
			return ci;
		}

		const_iterator rel_iter(const_iterator base, ICRELNUM idx) const
		{
		const_iterator ci;

			if(idx>0)
				for(ci=base;idx && ci!=block_.end();++ci,--idx);
			else if(idx<0)
				for(ci=base;idx && ci!=block_.begin();--ci,++idx);
			else
				ci = base;
			return ci;
		}

		ICABSNUM compute_index(const_iterator cr) const			// revert operation to at_iter
		{
			ICABSNUM idx=0;
			const_iterator ci;
			for(ci=block_.begin();ci!=cr && ci!=block_.end();++ci,++idx);
			if(ci!=cr)
				throw std::out_of_range("Computing index into a plain_block");
			return idx;
		}

		void clear() { block_.clear(); }

	private:
		std::list<T *>			block_;
	};

	/// @endcond

}

#endif
