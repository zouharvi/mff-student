#ifndef GUARD_MLASKAL_FLAT_ICBLOCK_HPP_
#define GUARD_MLASKAL_FLAT_ICBLOCK_HPP_

/*

	flat_icblock.hpp

	Flat IC block from file - base class

	Kuba, 2006

*/

#include <vector>
#include <string>
#include <map>

#include "common_types.hpp"
#include "literal_storage.hpp"
#include "plain_icblock.hpp"
#include "ic_instr.hpp"

namespace mlaskal {

	class abstract_ic;

	/// @cond INTERNAL

	class file_function_rv {
	public:
		file_function_rv(physical_type ptype, ICABSNUM size, ICSTKOFFS stkoffs) : ptype_(ptype),size_(size),stkoffs_(stkoffs) { }

		physical_type get_ptype() const { return ptype_; }
		ICABSNUM get_size() const { return size_; }
		ICSTKOFFS get_stkoffs() const { return stkoffs_; }
	private:
		physical_type   ptype_;
		ICABSNUM		size_;
		ICSTKOFFS		stkoffs_;
	};

	class file_function_param {
	public:
		file_function_param(ICLITIDX name, physical_type ptype, ICABSNUM size, ICSTKOFFS stkoffs) 
								: name_(name),ptype_(ptype),size_(size),stkoffs_(stkoffs) { }

		ICLITIDX get_name() const { return name_; }
		physical_type get_ptype() const { return ptype_; }
		ICABSNUM get_size() const { return size_; }
		ICSTKOFFS get_stkoffs() const { return stkoffs_; }
	private:
		ICLITIDX		name_;
		physical_type		ptype_;
		ICABSNUM		size_;
		ICSTKOFFS		stkoffs_;
	};

	class file_function_params {
	public:
		typedef file_function_param value_type;
		typedef file_function_param & reference;
		typedef const file_function_param & const_reference;
		typedef std::vector<file_function_param>::size_type size_type;
		typedef std::vector<file_function_param>::const_iterator const_iterator;

		size_type size() const { return params_.size(); }
		bool empty() const { return params_.empty(); }
		const_iterator begin() const { return params_.begin(); }
		const_iterator end() const { return params_.end(); }

		void push_back(const file_function_param &ffp) { params_.push_back(ffp); }
	private:
		std::vector<file_function_param>  params_;
	};

	class file_function_var {
	public:
		file_function_var(ICLITIDX name,
						  physical_type ptype,
						  ICABSNUM icip_start,
						  ICABSNUM icip_end, 
						  ICABSNUM size, 
						  ICSTKOFFS stkoffs
						  ) : name_(name),ptype_(ptype),icip_start_(icip_start),icip_end_(icip_end),size_(size),stkoffs_(stkoffs) { }

		ICLITIDX get_name() const { return name_; }
		physical_type get_ptype() const { return ptype_; }
		ICABSNUM get_icip_start() const { return icip_start_; }
		ICABSNUM get_icip_end() const { return icip_end_; }
		ICABSNUM get_size() const { return size_; }
		ICSTKOFFS get_stkoffs() const { return stkoffs_; }
	private:
		ICLITIDX		name_;
		physical_type		ptype_;
		ICABSNUM		icip_start_;
		ICABSNUM		icip_end_;
		ICABSNUM		size_;
		ICSTKOFFS		stkoffs_;
	};

	class file_function_vars {
	public:
		typedef file_function_var value_type;
		typedef file_function_var & reference;
		typedef const file_function_var & const_reference;
		typedef std::vector<file_function_var>::size_type size_type;
		typedef std::vector<file_function_var>::const_iterator const_iterator;

		size_type size() const { return vars_.size(); }
		bool empty() const { return vars_.empty(); }
		const_iterator begin() const { return vars_.begin(); }
		const_iterator end() const { return vars_.end(); }

		void push_back(const file_function_var &ffv) { vars_.push_back(ffv); }
	private:
		std::vector<file_function_var>  vars_;
	};

	class file_function {
	public:
		file_function(fnc_signature_type fs_type,			// procedure or program
					  ICLITIDX name,
					  ICABSNUM icip_start,
					  ICABSNUM icip_end,
					  ICABSNUM used_regs,
					  const file_function_params &params,
					  const file_function_vars &vars
					  ) : fs_type_(fs_type),name_(name),icip_start_(icip_start),icip_end_(icip_end),used_regs_(used_regs),
								rv_(PTYPE_UNDEF,0,0),params_(params),vars_(vars) { }
		file_function(const file_function_rv &rv,			// function
					  ICLITIDX name,
					  ICABSNUM icip_start,
					  ICABSNUM icip_end,
					  ICABSNUM used_regs,
					  const file_function_params &params,
					  const file_function_vars &vars
					  ) : fs_type_(FNCSIG_FNC),name_(name),icip_start_(icip_start),icip_end_(icip_end),used_regs_(used_regs),
								rv_(rv),params_(params),vars_(vars) { }

		fnc_signature_type get_type() const { return fs_type_; }
		ICLITIDX get_name() const { return name_; }
		ICABSNUM get_icip_start() const { return icip_start_; }
		ICABSNUM get_icip_end() const { return icip_end_; }
		ICABSNUM get_used_regs() const { return used_regs_; }
		const file_function_rv &get_rv() const { return rv_; }
		const file_function_params &get_params() const { return params_; }
		const file_function_vars &get_vars() const { return vars_; }

	private:
		fnc_signature_type								fs_type_;
		ICLITIDX										name_;
		ICABSNUM										icip_start_;
		ICABSNUM										icip_end_;
		ICABSNUM										used_regs_;
		file_function_rv								rv_;
		file_function_params								params_;
		file_function_vars								vars_;
	};

	class file_functions {
	public:
		typedef file_function value_type;
		typedef file_function & reference;
		typedef const file_function & const_reference;
		typedef std::vector<file_function>::size_type size_type;
		typedef std::vector<file_function>::const_iterator const_iterator;

		size_type size() const { return ffs_.size(); }
		const_iterator begin() const { return ffs_.begin(); }
		const_iterator end() const { return ffs_.end(); }

		void push_back(const file_function &ff) { ffs_.push_back(ff); }
	private:
		std::vector<file_function>  ffs_;
	};

	struct flat_icblock_exception {
		enum reason { FICBER_OPEN, FICBER_ERR, FICBER_CORRUPT };
		flat_icblock_exception(reason r) : reason_(r) { }
		reason reason_;
	};

	class flat_icblock {
	public:
		explicit flat_icblock(const std::string &filename); // loading from a file
		explicit flat_icblock(const abstract_ic &aic);			// creating from abstract IC
		flat_icblock() { }
		~flat_icblock() { }

		// file operations
		void save(const std::string &filename);
		void save_asm(const std::string &filename);

		// container types
		typedef lit_storage<int, false>			literal_storage_int_type;
		typedef lit_storage<double, false>		literal_storage_real_type;
		typedef lit_storage<std::string, false>	literal_storage_string_type;
		typedef lit_storage<std::string, true>	literal_storage_id_type;
		typedef file_functions					file_functions_type;
		typedef plain_icblock<ic_instr>			plain_icblock_type;
		typedef std::map<ICABSNUM, const file_function *>   fncs_map_type;

		// container getters
		const literal_storage_int_type &get_ls_int() const { return ls_int_; }
		const literal_storage_real_type &get_ls_real() const { return ls_real_; }
		const literal_storage_string_type &get_ls_string() const { return ls_string_; }
		const literal_storage_id_type &get_ls_id() const { return ls_id_; }
		const file_functions_type &get_fncs() const { return fncs_; }
		plain_icblock_type &get_icblock() { return icblock_; }
		const plain_icblock_type &get_icblock() const { return icblock_; }
		const fncs_map_type &get_fncs_map() const { return fncs_map_; }

		// custom functions
		fncs_map_type::const_iterator find_fnc(ICABSNUM ic) const { return fncs_map_.find(ic); }

	protected:
		literal_storage_int_type			ls_int_;
		literal_storage_real_type			ls_real_;
		literal_storage_string_type			ls_string_;
		literal_storage_id_type					ls_id_;
		file_functions_type					fncs_;
		plain_icblock_type					icblock_;

		fncs_map_type							fncs_map_;
	};

	/// @endcond
}

#endif
