#ifndef GUARD_MLASKAL_ABSTRACT_IC_HPP_
#define GUARD_MLASKAL_ABSTRACT_IC_HPP_

/*

	abstract_ic.hpp

	Abstract IC

	Kuba, 2006

*/

#include <vector>
#include <list>
#include <cassert>
#include <map>
#include <memory>

#include "common_types.hpp"
#include "literal_storage.hpp"
#include "plain_icblock.hpp"
#include "uid_gen.hpp"

namespace mlaskal {

	class flat_icblock;
	class file_function;
	class abstract_function;
	class abstract_instr;
	class labeled_icblock;

	/// integer literal storage
	typedef lit_storage<int, false>				aic_literal_storage_int_type;
	/// real literal storage
	typedef lit_storage<double, false>			aic_literal_storage_real_type;
	/// string literal storage
	typedef lit_storage<std::string, false>		aic_literal_storage_string_type;
	/// identifier storage
	typedef lit_storage<std::string, true>		aic_literal_storage_id_type;

	/// return value type info
	class abstract_function_rv {
	public:
		/// @cond INTERNAL
		abstract_function_rv() : ptype_(PTYPE_UNDEF),size_(0),stkoffs_(0) { }
		/// @endcond

		/**
			\param ptype physical type (elementary)
			\param size return value size (in memory cells)
			\param stkoffs return value location (first cell wrt FP)
		**/
		abstract_function_rv(physical_type ptype, ICABSNUM size, ICSTKOFFS stkoffs) : ptype_(ptype),size_(size),stkoffs_(stkoffs) { }

		/// physical type (elementary)
		physical_type get_ptype() const { return ptype_; }
		/// return value size (in memory cells)
		ICABSNUM get_size() const { return size_; }
		/// return value location (first cell wrt FP)
		ICSTKOFFS get_stkoffs() const { return stkoffs_; }

		void swap(abstract_function_rv &arv)
		{
			std::swap(ptype_, arv.ptype_);
			std::swap(size_, arv.size_);
			std::swap(stkoffs_, arv.stkoffs_);
		}

	private:
		physical_type   ptype_;
		ICABSNUM		size_;
		ICSTKOFFS		stkoffs_;
	};

	/// function parameter info
	class abstract_function_param {
	public:
		/**
			\param name parameter name
			\param ptype physical type (elementary)
			\param size parameter size (in memory cells)
			\param stkoffs parameter location (first cell wrt FP)
		**/
		abstract_function_param(
			aic_literal_storage_id_type::const_pointer name, 
			physical_type ptype, 
			ICABSNUM size, 
			ICSTKOFFS stkoffs) 
					: name_(name),ptype_(ptype),size_(size),stkoffs_(stkoffs) { }

		/// parameter name
		aic_literal_storage_id_type::const_pointer get_name() const { return name_; }
		/// physical type (elementary)
		physical_type get_ptype() const { return ptype_; }
		/// parameter size (in memory cells)
		ICABSNUM get_size() const { return size_; }
		/// parameter location (first cell wrt FP)
		ICSTKOFFS get_stkoffs() const { return stkoffs_; }
	private:
		aic_literal_storage_id_type::const_pointer				name_;
		physical_type												ptype_;
		ICABSNUM												size_;
		ICSTKOFFS												stkoffs_;
	};

	/// parameter list
	class abstract_function_params {
	public:
		typedef abstract_function_param value_type;   ///< container requirement
		typedef abstract_function_param & reference;   ///< container requirement
		typedef const abstract_function_param & const_reference;   ///< container requirement
		typedef std::vector<abstract_function_param>::size_type size_type;   ///< container requirement
		typedef std::vector<abstract_function_param>::const_iterator const_iterator;   ///< container requirement

		size_type size() const { return params_.size(); }   ///< container requirement
		bool empty() const { return params_.empty(); }   ///< container requirement
		const_iterator begin() const { return params_.begin(); }   ///< container requirement
		const_iterator end() const { return params_.end(); }   ///< container requirement

		void swap(abstract_function_params &afp) { params_.swap(afp.params_); }   ///< container requirement

		void push_back(const abstract_function_param &afp) { params_.push_back(afp); }   ///< container requirement

	private:
		std::vector<abstract_function_param>  params_;
	};

	/// variable info
	class abstract_function_var {
	public:
		/**
			\param name variable name
			\param ptype physical type (elementary)
			\param icip_start start of initialization code inside the function code block
			\param icip_end end of initialization code inside the function code block
			\param size variable size (in memory cells)
			\param stkoffs variable location (first cell wrt FP)
		**/
		abstract_function_var(aic_literal_storage_id_type::const_pointer name,
							  physical_type ptype,
							  plain_icblock<abstract_instr>::const_iterator icip_start,
							  plain_icblock<abstract_instr>::const_iterator icip_end, 
							  ICABSNUM size, 
							  ICSTKOFFS stkoffs
							 ) : name_(name),ptype_(ptype),icip_start_(icip_start),icip_end_(icip_end),size_(size),stkoffs_(stkoffs) { }

		/// variable name
		aic_literal_storage_id_type::const_pointer get_name() const { return name_; }
		/// physical type (elementary)
		physical_type get_ptype() const { return ptype_; }
		/// start of initialization code inside the function code block
		plain_icblock<abstract_instr>::const_iterator get_icip_start() const { return icip_start_; }
		/// end of initialization code inside the function code block
		plain_icblock<abstract_instr>::const_iterator get_icip_end() const { return icip_end_; }
		/// start of initialization code inside the function code block
		void set_icip_start(plain_icblock<abstract_instr>::const_iterator i) { icip_start_ = i; }
		/// end of initialization code inside the function code block
		void set_icip_end(plain_icblock<abstract_instr>::const_iterator i) { icip_end_ = i; }
		/// variable size (in memory cells)
		ICABSNUM get_size() const { return size_; }
		/// variable location (first cell wrt FP)
		ICSTKOFFS get_stkoffs() const { return stkoffs_; }
	private:
		aic_literal_storage_id_type::const_pointer				name_;
		physical_type												ptype_;
		plain_icblock<abstract_instr>::const_iterator				icip_start_;
		plain_icblock<abstract_instr>::const_iterator				icip_end_;
		ICABSNUM												size_;
		ICSTKOFFS												stkoffs_;
	};

	/// variable list
	class abstract_function_vars {
	public:
		typedef abstract_function_var value_type;   ///< container requirement
		typedef abstract_function_var & reference;  ///< container requirement
		typedef const abstract_function_var & const_reference;		///< container requirement
		typedef std::vector<abstract_function_var>::size_type size_type;	///< container requirement
		typedef std::vector<abstract_function_var>::iterator iterator;  ///< container requirement
		typedef std::vector<abstract_function_var>::const_iterator const_iterator;  ///< container requirement

		size_type size() const { return vars_.size(); }		///< container requirement
		bool empty() const { return vars_.empty(); }		///< container requirement
		const_iterator begin() const { return vars_.begin(); }		///< container requirement
		iterator begin() { return vars_.begin(); }		///< container requirement
		const_iterator end() const { return vars_.end(); }  ///< container requirement
		iterator end() { return vars_.end(); }  ///< container requirement

		void swap(abstract_function_vars &afv) { vars_.swap(afv.vars_); }   ///< container requirement

		void push_back(const abstract_function_var &afv) { vars_.push_back(afv); }  ///< container requirement

	private:
		std::vector<abstract_function_var>  vars_;
	};

	/// function info
	class abstract_function {
	public:
		/// @cond INTERNAL
		abstract_function() : rv_(PTYPE_UNDEF, 0, 0) { assert(0); }		// required by MSVC 2005 <list>
		/// @endcond

		/// @cond FOR_MLC
		abstract_function(aic_literal_storage_id_type::const_pointer name,		// for a MLC function
						  const abstract_function_rv &rv,
						  const abstract_function_params &params,
						  const abstract_function_vars &vars,
						  std::shared_ptr<labeled_icblock> block) 
						  : block_(block),name_(name),fs_type_(FNCSIG_FNC),rv_(rv),params_(params),vars_(vars),
							uid_(uid_all.get_UID()),other_uid_(0),used_regs_(0) { }
		abstract_function(aic_literal_storage_id_type::const_pointer name,		// for a procedure
						  const abstract_function_params &params,
						  const abstract_function_vars &vars,
						  std::shared_ptr<labeled_icblock> block) 
						  : block_(block),name_(name),fs_type_(FNCSIG_PROC),rv_(abstract_function_rv()),params_(params),vars_(vars),
							uid_(uid_all.get_UID()),other_uid_(0),used_regs_(0) { }
		abstract_function(aic_literal_storage_id_type::const_pointer name,		// for a program
						  const abstract_function_vars &vars,
						  std::shared_ptr<labeled_icblock> block) 
						  : block_(block),name_(name),fs_type_(FNCSIG_PROGRAM),rv_(abstract_function_rv()),params_(abstract_function_params()),vars_(vars),
							uid_(uid_all.get_UID()),other_uid_(0),used_regs_(0) { }
		/// @endcond 
		
		/**
			\param fs_type procedure/function/main
			\param name function name
			\param rv return value type information
			\param used_regs number of registers used
			\param params list of parameters
			\param vars list of variables
			\param other_UID client UID to be returned by \c get_UID
			\param block function code block
	   **/
		abstract_function(fnc_signature_type fs_type,						// full prototype - do not use it
						  aic_literal_storage_id_type::const_pointer name,
						  const abstract_function_rv &rv,
						  ICREGNUM used_regs,
						  const abstract_function_params &params,
						  const abstract_function_vars &vars,
						  uid_all_type::UID_type other_UID,
						  std::shared_ptr<labeled_icblock> block) 
						  : block_(block),name_(name),fs_type_(fs_type),rv_(rv),params_(params),vars_(vars),
							uid_(uid_all.get_UID()),other_uid_(other_UID),used_regs_(used_regs) { }

		/// @cond INTERNAL
		void swap(abstract_function &af)
		{ 
			std::swap(block_, af.block_); 
			std::swap(name_, af.name_);
			std::swap(fs_type_, af.fs_type_);
			params_.swap(af.params_);
			vars_.swap(af.vars_);
			std::swap(uid_, af.uid_);
			std::swap(other_uid_, af.other_uid_);
			std::swap(used_regs_, af.used_regs_);
			std::swap(rv_, af.rv_);
		}
		/// @endcond

		/// function name
		aic_literal_storage_id_type::const_pointer get_name() const { return name_; }
		/// procedure/function/main
		fnc_signature_type get_type() const { return fs_type_; }
		/// function code block
		const std::shared_ptr<labeled_icblock> & get_block() const { return block_; }
		/// return value type information
		const abstract_function_rv &get_rv() const { return rv_; }
		/// parameter list
		const abstract_function_params &get_params() const { return params_; }
		/// variable list
		abstract_function_vars &get_vars() { return vars_; }
		/// variable list
		const abstract_function_vars &get_vars() const { return vars_; }
		/// my UID (assigned automatically)
		uid_all_type::UID_type get_UID() const { return uid_; }
		/// client UID (see constructor)
		uid_all_type::UID_type get_other_UID() const { return other_uid_; }
		/// number of registers used
		ICREGNUM get_used_regs() const { return used_regs_; }
		/// number of registers used
		void set_used_regs( ICREGNUM used_regs) { used_regs_ = used_regs; }

		/// @cond FOR_MLC
		void assign_block(std::shared_ptr<labeled_icblock> block);
		/// @endcond 

	private:
		std::shared_ptr<labeled_icblock>						block_;
		aic_literal_storage_id_type::const_pointer				name_;
		fnc_signature_type										fs_type_;
		abstract_function_rv										rv_;
		abstract_function_params								params_;
		abstract_function_vars										vars_;
		uid_all_type::UID_type										uid_;
		uid_all_type::UID_type										other_uid_;
		ICREGNUM												used_regs_;
	};

	/// list of functions
	class abstract_functions {
	public:
		abstract_functions() ///< container requirement
		{ }
		
		typedef abstract_function value_type;		///< container requirement
		typedef abstract_function & reference;		///< container requirement
		typedef const abstract_function & const_reference;  ///< container requirement
		typedef std::list<abstract_function>::size_type size_type;  ///< container requirement
		typedef std::list<abstract_function>::iterator iterator;	///< container requirement
		typedef std::list<abstract_function>::const_iterator const_iterator;		///< container requirement

		size_type size() const { return fncs_.size(); }		///< container requirement
		iterator begin() { return fncs_.begin(); }  ///< container requirement
		const_iterator begin() const { return fncs_.begin(); }		///< container requirement
		iterator end() { return fncs_.end(); }		///< container requirement
		const_iterator end() const { return fncs_.end(); }  ///< container requirement
		void swap(abstract_functions &af) { fncs_.swap(af.fncs_); } ///< container requirement

		/// container requirement
		void push_back(const_reference v)   
		{
			fncs_.push_back(v);
			fnc_map_.insert(std::make_pair(v.get_UID(), --fncs_.end()));
			fnc_map_other_.insert(std::make_pair(v.get_other_UID(), --fncs_.end()));
		}

		/// find function by name
		iterator find_name(aic_literal_storage_id_type::const_pointer name);
		/// find function by name
		const_iterator find_name(aic_literal_storage_id_type::const_pointer name) const;

		/// find function by its UID
		iterator find_UID(uid_all_type::UID_type uid) { return fnc_map_.find(uid)->second; }
		/// find function by its UID
		const_iterator find_UID(uid_all_type::UID_type uid) const { return fnc_map_.find(uid)->second; }

		/// find function by client UID
		iterator find_other_UID(uid_all_type::UID_type uid) { return fnc_map_other_.find(uid)->second; }
		/// find function by client UID
		const_iterator find_other_UID(uid_all_type::UID_type uid) const { return fnc_map_other_.find(uid)->second; }

		/// @cond INTERNAL
		ICABSNUM compute_index(const_iterator cr) const			// revert operation to at_iter
		{
			ICABSNUM idx=0;
			const_iterator ci;
			for(ci=fncs_.begin();ci!=cr && ci!=fncs_.end();++ci,++idx);
			if(ci==fncs_.end())
				throw std::out_of_range("Computing index into abstract_functions");
			return idx;
		}
		/// @endcond

	private:
		std::list<abstract_function>							fncs_;							// functions
		std::map<uid_all_type::UID_type, iterator>			fnc_map_;
		std::map<uid_all_type::UID_type, iterator>			fnc_map_other_;
	};

	//typedef abstract_functions aic_abstract_functions_type;

	/// complete intermediate code
	class abstract_ic {
	public:
		/// @cond INTERNAL
		abstract_ic() { }
		/// @endcond

		/// @cond INTERNAL
		explicit abstract_ic(const flat_icblock &ficb);
		/// @endcond

		/// function list
		abstract_functions &get_abstract_functions() { return fncs_; }
		/// function list
		const abstract_functions &get_abstract_functions() const { return fncs_; }
		/// integer literal storage
		aic_literal_storage_int_type &get_ls_int() { return ls_int_; }
		/// integer literal storage
		const aic_literal_storage_int_type &get_ls_int() const { return ls_int_; }
		/// real literal storage
		aic_literal_storage_real_type &get_ls_real() { return ls_real_; }
		/// real literal storage
		const aic_literal_storage_real_type &get_ls_real() const { return ls_real_; }
		/// string literal storage
		aic_literal_storage_string_type &get_ls_string() { return ls_string_; }
		/// string literal storage
		const aic_literal_storage_string_type &get_ls_string() const { return ls_string_; }
		/// identifier storage
		aic_literal_storage_id_type &get_ls_id() { return ls_id_; }
		/// identifier storage
		const aic_literal_storage_id_type &get_ls_id() const { return ls_id_; }

	private:
		abstract_functions			fncs_;
		aic_literal_storage_int_type			ls_int_;
		aic_literal_storage_real_type			ls_real_;
		aic_literal_storage_string_type			ls_string_;
		aic_literal_storage_id_type			ls_id_;

		// disabling copy-constructor & assign
		abstract_ic(const abstract_ic &aic);
		abstract_ic &operator=(const abstract_ic &aic);
	};

}

#endif
