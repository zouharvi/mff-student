/*

	labeled_icblock.cpp

	Labeled IC block implementation

	Kuba, 2006

*/

#include <iterator>

#include "labeled_icblock.hpp"
#include "ic_instrtab.hpp"
#include "ai_factory.hpp"

using namespace std;

namespace {

	class ftor_elbl2lbl {
	public:
		ftor_elbl2lbl(::mlaskal::labeled_icblock::const_iterator ntgt) : ntgt_(ntgt) { }
		pair< ::mlaskal::labeled_icblock::label_type, ::mlaskal::labeled_icblock::const_iterator>
			operator()(::mlaskal::labeled_icblock::label_type elbl) const { return make_pair(elbl, ntgt_); }
	private:
		::mlaskal::labeled_icblock::const_iterator ntgt_;
	};

	class ftor_lblbk {
	public:
		ftor_lblbk(::mlaskal::labeled_icblock::const_iterator ntgt) : ntgt_(ntgt) { }
		pair< ::mlaskal::labeled_icblock::const_iterator, ::mlaskal::labeled_icblock::label_type>
			operator()(::mlaskal::labeled_icblock::label_type elbl) const { return make_pair(ntgt_, elbl); }
	private:
		::mlaskal::labeled_icblock::const_iterator ntgt_;
	};

	class ftor_patch_tgt {
	public:
		ftor_patch_tgt(::mlaskal::labeled_icblock::const_iterator cit) : cit_(cit) { }
		void operator()(const pair< ::mlaskal::labeled_icblock::label_type, ::mlaskal::labeled_icblock::iterator> &itgt)
		{
			(*itgt.second)->patch_reljump(cit_);
		}
	private:
		::mlaskal::labeled_icblock::const_iterator cit_;
	};

	class ftor_patch_targets {
	public:
		ftor_patch_targets(std::multimap< ::mlaskal::labeled_icblock::label_type, ::mlaskal::labeled_icblock::iterator> &tgts,
								::mlaskal::labeled_icblock::const_iterator cit) : tgts_(&tgts),cit_(cit) { }
		void operator()(::mlaskal::labeled_icblock::label_type elbl) const
		{
			std::multimap< ::mlaskal::labeled_icblock::label_type, ::mlaskal::labeled_icblock::iterator>::const_iterator lb, ub;
			lb = tgts_->lower_bound(elbl);
			ub = tgts_->upper_bound(elbl);
			for_each(lb, ub, ftor_patch_tgt(cit_));
		}
	private:
		std::multimap< ::mlaskal::labeled_icblock::label_type, ::mlaskal::labeled_icblock::iterator> *tgts_;
		::mlaskal::labeled_icblock::const_iterator cit_;
	};

}

namespace mlaskal {

	struct less_labels_bkmap {
		bool operator()( const mlaskal::labeled_icblock::labels_bkmap_type_ & a, const mlaskal::labeled_icblock::labels_bkmap_type_ & b) const
		{
			return (*a.first)->get_UID() < (*b.first)->get_UID();
		}
	};

	struct ftor_labels_bkmap_label {
		mlaskal::labeled_icblock::label_type operator()( const mlaskal::labeled_icblock::labels_bkmap_type_ & a) const
		{
			return a.second;
		}
	};

	labeled_icblock::labeled_icblock(plain_icblock<ic_instr>::const_iterator first,
									 plain_icblock<ic_instr>::const_iterator last, 
									 const abstract_ic &aic, 
									 const flat_icblock &ficb)
	{
		for(plain_icblock<ic_instr>::const_iterator pic=first;pic!=last;++pic)
		{
			abstract_instr *ai = ai_factory::create_ai_instr(
												(*pic)->get_opcode(),
												(*pic)->get_out(),
												(*pic)->get_in1(),
												(*pic)->get_in2(),
												(*pic)->get_in3(),
												(*pic)->get_in4()
												);
			block_.push_back(ai);
			switch(ai::ic_instrtab[ai->get_opcode()].stkp_type_)
			{
			case ICSPT_LITINT:
				{
					aic_literal_storage_int_type::const_pointer li = aic.get_ls_int().at_iter((*pic)->get_stkn());
					ai->patch_litint(li);
				}
				break;
			case ICSPT_LITREAL:
				{
					aic_literal_storage_real_type::const_pointer lr = aic.get_ls_real().at_iter((*pic)->get_stkn());
					ai->patch_litreal(lr);
				}
				break;
			case ICSPT_LITSTR:
				{
					aic_literal_storage_string_type::const_pointer ls = aic.get_ls_string().at_iter((*pic)->get_stkn());
					ai->patch_litstr(ls);
				}
				break;
			case ICSPT_GSTKOFFS:
			case ICSPT_LSTKOFFS:
			case ICSPT_SSTKOFFS:
				{
					ICRELNUM rn = (*pic)->get_stkn();
					ai->patch_stkoffs(rn);
				}
				break;
			case ICSPT_ABSNUM:
				{
					ICABSNUM an = static_cast<ICABSNUM>((*pic)->get_stkn());
					ai->patch_absnum(an);
				}
				break;
			case ICSPT_RELJUMP:
				// now do nothing
				break;
			case ICSPT_ABSJUMP:
				{
					// this hell looks up a function using name index
					aic_literal_storage_id_type::const_pointer fname = aic.get_ls_id().at_iter(ficb.find_fnc((*pic)->get_stkn())->second->get_name());
					abstract_functions::const_iterator af=aic.get_abstract_functions().find_name(fname);
					ai->patch_absjump(af);
				}
				break;
			default:		// dazed GCC
				break;
			}
		}

		// recompute relative jumps
		plain_icblock<ic_instr>::const_iterator pic2 = first;
		for(plain_icblock<abstract_instr>::const_iterator ci=block_.begin();ci!=block_.end();++ci,++pic2)
		{
			if(ai::ic_instrtab[(*ci)->get_opcode()].stkp_type_==ICSPT_RELJUMP)
				(*ci)->patch_reljump(block_.rel_iter(ci, (*pic2)->get_stkn()));
		}
	}

	void labeled_icblock::push_back(const_reference v)
	{ 
		block_.push_back(v);

		// patch targets
		labeled_icblock::const_iterator cit = --block_.end();
		for_each(empty_labels_.begin(), empty_labels_.end(), ftor_patch_targets(targets_, cit));

		// move targeted labels from empty set
		transform(empty_labels_.begin(), empty_labels_.end(), inserter(labels_, labels_.end()), ftor_elbl2lbl(cit));
		transform(empty_labels_.begin(), empty_labels_.end(), back_inserter(labels_bkmap_), ftor_lblbk(cit));
		empty_labels_.clear();
	}

	labeled_icblock::const_iterator labeled_icblock::append_instruction_with_target(const_reference ai, label_type tgt_lbl)
	{
		push_back(ai);

		labeled_icblock::iterator it = --block_.end();

		targets_.insert(make_pair(tgt_lbl, it));
		targets_bkmap_.push_back(targets_bkmap_type_(it, tgt_lbl));

		// resolve this target, if it is a known label
		std::map<label_type, labeled_icblock::const_iterator>::const_iterator tgtci = labels_.find(tgt_lbl);
		if(tgtci!=labels_.end())
			(*it)->patch_reljump(tgtci->second);

		return it;
	}

	void labeled_icblock::append_clear_block(labeled_icblock &&licb)
	{
		if (!& licb)
		{
			// null-pointer robustness
			return;
		}

		std::vector<labels_bkmap_type_>::const_iterator citlbk=licb.labels_bkmap_.begin();
		std::vector<targets_bkmap_type_>::const_iterator cittbk=licb.targets_bkmap_.begin();

		// foreach :) source instruction check the situation and use proper functions
		for(const_iterator cit=licb.begin();cit!=licb.end();++cit)
		{
			// setup labels
			for(;citlbk!=licb.labels_bkmap_.end() && citlbk->first==cit;++citlbk)
				add_label(citlbk->second);
			// check for an instruction with target
			if(cittbk!=licb.targets_bkmap_.end() && cittbk->first==cit)
			{
				(*cit)->patch_reljump(end());
				const_iterator lasti = append_instruction_with_target(*cit, cittbk->second);
				++cittbk;
			}
			else
				append_instruction(*cit);
		}

		// append empty_labels from the source block to the target block
		empty_labels_.insert(licb.empty_labels_.begin(), licb.empty_labels_.end());

		// kill the source block
		licb.block_.clear();
		licb.empty_labels_.clear();
		licb.targets_.clear();
		licb.labels_.clear();
		licb.labels_bkmap_.clear();
		licb.targets_bkmap_.clear();
	}

	std::set<labeled_icblock::label_type> labeled_icblock::find_labels( labeled_icblock::const_iterator ci) const
	{
		if ( ci == block_.end() )
			return empty_labels_;

		std::set<label_type> buf;
		::std::transform( 
			::std::lower_bound( 
				labels_bkmap_.begin(),
				labels_bkmap_.end(),
				labeled_icblock::labels_bkmap_type_( ci, 0),
				less_labels_bkmap()),
			::std::upper_bound( 
				labels_bkmap_.begin(),
				labels_bkmap_.end(),
				labeled_icblock::labels_bkmap_type_( ci, 0),
				less_labels_bkmap()),
			::std::inserter( buf, buf.end()),
			ftor_labels_bkmap_label());
		return buf;
	}
}
