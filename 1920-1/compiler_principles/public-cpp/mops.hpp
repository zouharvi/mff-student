#ifndef GUARD_MLASKAL_MOPS_HPP_
#define GUARD_MLASKAL_MOPS_HPP_

/*

	mops.hpp

	Microoperations

	Kuba, 2006

*/

#include <vector>
#include <string>
#include <memory>

#include "icm_types.hpp"
#include "icm_val.hpp"

#include "gen_mopcodes.hpp"

namespace mlaskal {

	class ic_instr;
	class icm_machine;
	class icm_machine_unit_pool;

	typedef std::shared_ptr<icm_val> SHRVAL;

	// base class
	class mop {
	public:
		mop(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) 
			: instr_(instr),mach_(mach),ip_(ip),mop_id_(mop_id),up_(up),timing_(timing) { }
		virtual ~mop() { }

		void set_in(int idx, SHRVAL in)
		{ 
			switch(idx)
			{
			case 1:
				in1_=in; 
				break;
			case 2:
				in2_=in; 
				break;
			case 3:
				in3_=in; 
				break;
			}
		}
		SHRVAL get_out() const { return out_; }
		SHRVAL get_addr() const { return in1_; }	// shortcut
		ICMT_ICIP get_ip() const { return ip_; }

		bool is_ready() const { return is_ready_int_(); }
		bool is_ready_addr() const { return is_ready_addr_int_(); }
		bool is_read() const { return is_read_int_(); }
		bool is_write() const { return is_write_int_(); }
		ICREGNUM get_regnum() const { return get_regnum_int_(); }

		void exec() { exec_int_(); }
		icm_machine_unit_pool *get_unit_pool() const { return up_; }
		void set_unit_pool(icm_machine_unit_pool *up) { up_ = up; }
		unsigned get_timing() const { return timing_; }
		bool decr_timing() { return --timing_==0; }
		std::string get_id() const { return mop_id_; }

		// targets
		struct mop_target {
			mop			*tgt_mop_;
			int			idx;
		};
		void push_back_tgt(mop *tgt, int idx) { mop_target mt={ tgt, idx }; targets_.push_back(mt); }
		std::vector<mop_target>::const_iterator begin_tgt() const { return targets_.begin(); }
		std::vector<mop_target>::const_iterator end_tgt() const { return targets_.end(); }

	protected:
		const ic_instr		*instr_;
		icm_machine		*mach_;
		ICMT_ICIP		ip_;
		std::string		mop_id_;
		SHRVAL				in1_, in2_, in3_, out_;

	private:
		icm_machine_unit_pool			*up_;
		unsigned					timing_;
		std::vector<mop_target>			targets_;

		virtual bool is_ready_int_() const =0;
		virtual bool is_ready_addr_int_() const =0;
		virtual bool is_read_int_() const =0;
		virtual bool is_write_int_() const =0;
		virtual ICREGNUM get_regnum_int_() const =0;
		virtual void exec_int_()=0;
	};

	class mop_factory {
	private:
		typedef mop* (*mop_creator)(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing);
		static mop_creator creators[mops::MOPC_DNOTUSE_MAX_];
	public:
		static mop *create_mop(mops::MOP_MOPCODE mopc, const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing)
		{
			return creators[mopc](instr, mach, up, ip, mop_id, timing);
		}
	};

	struct mop_info_t {
		mops::UNIT_TYPE			unit_type_;
		bool					is_read_;
		bool					is_write_;
	};

	extern mop_info_t mop_info[mops::MOPC_DNOTUSE_MAX_];

}

#endif
