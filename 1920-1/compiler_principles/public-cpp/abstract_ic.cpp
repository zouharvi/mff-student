/*

	abstract_ic.cpp

	Abstract IC

	Kuba, 2006

*/

#include <algorithm>
#include <iterator>

#include "abstract_ic.hpp"
#include "flat_icblock.hpp"
#include "labeled_icblock.hpp"

using namespace std;

namespace {

	class pred_find_name {
	public:
		pred_find_name(::mlaskal::aic_literal_storage_id_type::const_pointer name) : name_(name) { }
		bool operator()(::mlaskal::abstract_functions::const_reference af) { return af.get_name()==name_; }
	private:
		::mlaskal::aic_literal_storage_id_type::const_pointer name_;
	};

	class ftor_afncparm_trans {
	public:
		ftor_afncparm_trans(const ::mlaskal::abstract_ic &aic) : aic_(&aic) { }
		::mlaskal::abstract_function_param operator()(const ::mlaskal::file_function_param &fp)
		{
			return ::mlaskal::abstract_function_param(aic_->get_ls_id().at_iter(fp.get_name()), fp.get_ptype(), fp.get_size(), fp.get_stkoffs());
		}
	private:
		const ::mlaskal::abstract_ic *aic_;
	};

	class ftor_afncvar_trans {
	public:
		ftor_afncvar_trans(const ::mlaskal::abstract_ic &aic, ::mlaskal::abstract_function &af, ::mlaskal::ICABSNUM fncsip) 
									: aic_(&aic),af_(&af),fncsip_(fncsip) { }
		::mlaskal::abstract_function_var operator()(const ::mlaskal::file_function_var &fv)
		{
			::std::shared_ptr< ::mlaskal::labeled_icblock> lic(af_->get_block());
			return ::mlaskal::abstract_function_var(
									aic_->get_ls_id().at_iter(fv.get_name()), 
									fv.get_ptype(),
									lic->rel_iter(lic->begin(), fv.get_icip_start()-fncsip_),
									lic->rel_iter(lic->begin(), fv.get_icip_end()-fncsip_ + 1), // make it excluded end - see ftor_afv2ffv_trans
									fv.get_size(),
									fv.get_stkoffs()
									);
		}
	private:
		const ::mlaskal::abstract_ic *aic_;
		::mlaskal::abstract_function *af_;
		::mlaskal::ICABSNUM fncsip_;
	};

	class ftor_fnc_trans {
	public:
		ftor_fnc_trans(const ::mlaskal::abstract_ic &aic) : aic_(&aic) { }
		::mlaskal::abstract_functions::value_type operator()(const ::mlaskal::file_function &ff)
		{
			::mlaskal::abstract_function_vars vars;		// we will pass empty vars, because we need valid labeled_icblock for function
			::mlaskal::abstract_function_params params;

			transform(ff.get_params().begin(), ff.get_params().end(), back_inserter(params), ftor_afncparm_trans(*aic_));

			return ::mlaskal::abstract_function(ff.get_type(), 
										aic_->get_ls_id().at_iter(ff.get_name()),
										::mlaskal::abstract_function_rv(ff.get_rv().get_ptype(), ff.get_rv().get_size(), ff.get_rv().get_stkoffs()),
										ff.get_used_regs(),
										params,
										vars,
										::mlaskal::uid_all_type::null_value,
										::std::shared_ptr< ::mlaskal::labeled_icblock>(static_cast< ::mlaskal::labeled_icblock*>(0))
									);
		}

	private:
		const ::mlaskal::abstract_ic		*aic_;
	};


}

namespace mlaskal {

	// this functor has been moved here to publish it as a friend of labeled_icblock
	class ftor_fnc_trans_body {
	public:
		ftor_fnc_trans_body(abstract_ic &aic, const flat_icblock &fic) : aic_(&aic),fic_(&fic) { }
		void operator()(const file_function &ff)
		{
			// constructing instructions
			std::shared_ptr<labeled_icblock> licb = std::make_shared< labeled_icblock>(
				fic_->get_icblock().at_iter(ff.get_icip_start()),
				++(fic_->get_icblock().at_iter(ff.get_icip_end())),
				*aic_,
				*fic_);
			
			abstract_function &af=*aic_->get_abstract_functions().find_name(aic_->get_ls_id().at_iter(ff.get_name()));
			af.assign_block(licb);

			// copying variables
			transform(ff.get_vars().begin(), ff.get_vars().end(), back_inserter(af.get_vars()), ftor_afncvar_trans(*aic_, af, ff.get_icip_start()));
		}

	private:
		abstract_ic *aic_;
		const flat_icblock *fic_;
	};

	void abstract_function::assign_block(std::shared_ptr<labeled_icblock> block)
	{
//		delete block_;
		block_ = block;
	}

	abstract_ic::abstract_ic(const flat_icblock &ficb)
	{
		// copy literals
		copy(ficb.get_ls_int().begin(), ficb.get_ls_int().end(), back_inserter(ls_int_));
		copy(ficb.get_ls_real().begin(), ficb.get_ls_real().end(), back_inserter(ls_real_));
		copy(ficb.get_ls_string().begin(), ficb.get_ls_string().end(), back_inserter(ls_string_));
		copy(ficb.get_ls_id().begin(), ficb.get_ls_id().end(), back_inserter(ls_id_));

		// transform functions
		// the first sweep only creates abstract functions with an empty labeled_block
		transform(ficb.get_fncs().begin(), ficb.get_fncs().end(), back_inserter(fncs_), ftor_fnc_trans(*this));
		// the second sweep assigns labeled icblock 
		for_each(ficb.get_fncs().begin(), ficb.get_fncs().end(), ftor_fnc_trans_body(*this, ficb));
	}

	abstract_functions::iterator abstract_functions::find_name(aic_literal_storage_id_type::const_pointer name)
	{ 
		return find_if(fncs_.begin(), fncs_.end(), pred_find_name(name)); 
	}

	abstract_functions::const_iterator abstract_functions::find_name(aic_literal_storage_id_type::const_pointer name) const
	{ 
		return find_if(fncs_.begin(), fncs_.end(), pred_find_name(name)); 
	}

}
