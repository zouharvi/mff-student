#ifndef GUARD_MLASKAL_ICM_MACHINE_HPP_
#define GUARD_MLASKAL_ICM_MACHINE_HPP_

/*

	icm_machine.hpp

	ICM machine

	Kuba, 2006

*/

#include <string>
#include <vector>
#include <map>
#include <set>
#include <deque>

#include <iosfwd>
#include <cassert>

#include "common_types.hpp"
#include "ic_opcodes.hpp"
#include "icm_val.hpp"
#include "mops.hpp"
#include "carray.hpp"
#include "literal_storage.hpp"
#include "flat_icblock.hpp"
#include "icm_flat_icblock.hpp"

namespace mlaskal {

	class icm_machine;
	class icm_flat_icblock;
	struct icm_machine_trace_options;

	namespace icm_machines_ {

		struct unit_map {
			mops::MOP_MOPCODE		mop_code_;
			unsigned				timing_;
		};

		struct unit {
			const char				*name_;
			mops::UNIT_TYPE			unit_type_;
			carray<unit_map>		umap_;
		};

		struct machine_unit {
			const unit		*unit_;
			int				n_units_;
		};

		struct machine {
			
			typedef icm_machine* (machine_creator)(const machine *m, ICABSNUM regs, const icm_flat_icblock *inic, std::ostream *os, const icm_machine_trace_options &to);

			const char					*name_;
			carray<machine_unit>		units_;
			carray<ai::IC_OPCODE>		allowed_instrs_;
			machine_creator				*creator_;
		};

		extern const carray<machine> machines;

	}		// namespace icm_machines_

	namespace instr_decode_ {

		struct instr_mop {
			mops::MOP_MOPCODE		mop_code_;
			const char				*id_;
			const char				*in1_id_;
			const char				*in2_id_;
			const char				*in3_id_;
		};

		typedef const carray<instr_mop> instr_code;

		extern const carray<instr_code> instr_decodes;

	}		// namespace instr_decode_

	class icm_machine_unit {
	public:
		icm_machine_unit() : cur_mop_(0) { }

		bool is_free() const { return cur_mop_==0; }
		mop *get_mop() const { return cur_mop_; }
		void set_mop(mop *m) { cur_mop_ = m; }

	private:
		mop		*cur_mop_;
	};

	class icm_machine_unit_pool {		// base class for a unit pool
	public:
		icm_machine_unit_pool(icm_machine *m, const std::string &name, unsigned instance, mops::UNIT_TYPE ut, const carray<icm_machines_::unit_map> &cum, int units) 
					: m_(m),name_(name),instance_(instance),unit_type_(ut),cum_(cum),units_(units),
					  free_units_(units),unit_dispatch_idx_(0),unit_exec_idx_(0),
					  working_(0),stalling_(0),mops_(0) { assert(units); } // unit pool must have at least one unit 
		virtual ~icm_machine_unit_pool() { }		// kill everything in the queue?

		std::string get_name() const { return name_; }
		unsigned get_instance() const { return instance_; }
		mops::UNIT_TYPE get_type() const { return unit_type_; }
		const carray<icm_machines_::unit_map> & get_cum() const { return cum_; }

		// queue interface
		bool push_back(mop *m);			// reports true, if the unit pool becomes ready by this incoming mop

		// simulation interface
		bool tick();					// reports true, if the unit pool becomes ready by this tick
		void exec_all(std::set<icm_machine_unit_pool *> &rdy_up, std::ostream *os);
		bool patch_mop(mop *m, int idx, SHRVAL v);  // reports true, if the unit pool becomes ready by this patch

		// trace interface
		unsigned get_working() const { return working_; }
		unsigned get_stalling() const { return stalling_; }
		unsigned get_mops() const { return mops_; }
		void trace_queue(std::ostream *os) const;

	private:
		typedef std::vector<icm_machine_unit>		vunits_type;

	public:
		// units interface - container
		typedef vunits_type::value_type				value_type;
		typedef vunits_type::const_iterator		const_iterator;
		typedef vunits_type::iterator				iterator;

		iterator						begin() { return units_.begin(); }
		const_iterator						begin() const { return units_.begin(); }
		iterator						end() { return units_.end(); }
		const_iterator						end() const { return units_.end(); }

	protected:
		icm_machine						*m_;
		std::deque<mop*>				q_;
		bool setup_free_unit(mop *m);		// reports true, if the unit pool becomes ready

	private:
		std::string						name_;
		unsigned						instance_;
		mops::UNIT_TYPE						unit_type_;
		carray<icm_machines_::unit_map>		cum_;
		vunits_type						units_;
		vunits_type::size_type				free_units_;		// constant time check for readiness
		vunits_type::size_type				unit_dispatch_idx_;
		vunits_type::size_type				unit_exec_idx_;

		unsigned						working_, stalling_, mops_;

		// nonvirtual but internal interface
		bool tick(mop *m) { return tick_int_(m); }
		bool is_ready(const mop *m) const { return is_ready_int_(m); }
		bool check_timing(const mop *m) const { return check_timing_int_(m); }
		icm_machine_unit_pool *exec(mop *m) { return exec_int_(m); }

		// virtual internal^2 interface
		virtual bool tick_int_(mop *m)=0;
		virtual bool is_ready_int_(const mop *m) const =0;
		virtual bool check_timing_int_(const mop *m) const =0;
		virtual icm_machine_unit_pool *exec_int_(mop *m)=0;
	};

	struct icm_machine_trace_options {
		bool		trace_state;
		std::size_t	stack_limit_;
		std::size_t	instruction_limit_;
	};

	class icm_machine {
	public:
		explicit icm_machine(const icm_machines_::machine *m, ICABSNUM regs, const icm_flat_icblock *inic, std::ostream *os, const icm_machine_trace_options &to);
		virtual ~icm_machine();

		std::string get_name() const { return name_; }

		void simulate();
		void write_stats() const;

		// mop interface
		ICMT_ICIP get_ip() const { return ip_; }
		void set_ip(ICMT_ICIP ip) { ip_ = ip; }
		ICMT_PTR get_sp() const { return sp_; }
		void set_sp(ICMT_PTR sp);
		ICMT_PTR get_fp() const { return fp_; }
		void set_fp(ICMT_PTR fp) { fp_ = fp; }
		SHRVAL get_reg(ICREGNUM rn) { ++regs_read_[rn]; return regs_[rn]; }
		void set_reg(ICREGNUM rn, SHRVAL v) { ++regs_write_[rn]; regs_[rn] = v; }
		SHRVAL get_mem(ICABSNUM adr, ICMT_ICIP ip);
		void set_mem(ICABSNUM adr, SHRVAL v, ICMT_ICIP ip);
		void fetch(ICMT_ICIP ip);
		ICMT_ICIP halt(ICMT_ICIP ip) { halted_ = true; return ip; }
		ICMT_INT get_ls_int(ICLITIDX litidx) { return static_cast<ICMT_INT>(ls_int_.at(litidx)); }
		ICMT_REAL get_ls_real(ICLITIDX litidx) { return static_cast<ICMT_REAL>(ls_real_.at(litidx)); }
		ICMT_STRING get_ls_string(ICLITIDX litidx) { return static_cast<ICMT_STRING>(ls_string_.at(litidx)); }
		void mop_destroyed() { --mops_in_pools_; }

	private:
		void static_check_ic(const carray<ai::IC_OPCODE> &allowed_instrs) const;
		void inject_mops(const carray<instr_decode_::instr_mop> &mops, ICMT_ICIP ip);
		void resize_stack(ICMT_PTR new_size);

		std::vector<ic_instr *>					instrs_;
		lit_storage<int, false>					ls_int_;
		lit_storage<double, false>				ls_real_;
		lit_storage<std::string, false>			ls_string_;

		std::string								name_;
		std::vector<icm_machine_unit_pool *>	unit_pools_;
		std::vector<SHRVAL>						regs_;
		std::vector<SHRVAL>						stack_;

		ICMT_ICIP								ip_;
		ICMT_PTR								fp_;
		ICMT_PTR								sp_;

		bool									halted_;
		unsigned								mops_in_pools_;

		// trace
		std::ostream							*os_;
		unsigned								tick_;
		unsigned								instructions_;
		std::vector<unsigned>					regs_read_;
		std::vector<unsigned>					regs_write_;
		std::vector<unsigned>					stack_read_;
		std::vector<unsigned>					stack_write_;
		icm_machine_trace_options				to_;

		struct mop_worker {
			icm_machine_unit_pool						*unit_pool_;
			unsigned									timing_;
		};
		
		class icm_machine_unit_pool_rwqi;

		std::map<mops::MOP_MOPCODE, mop_worker> map_mop2unit_;
		std::set<icm_machine_unit_pool *>		ready_unit_pools_;
		icm_machine_unit_pool						*rrq_;
		std::vector<icm_machine_unit_pool *>		stack_dbwqi_;
		std::vector<icm_machine_unit_pool_rwqi *>   stack_rwqi_;
		std::vector<icm_machine_unit_pool *>	reg_dbwqi_;

		// internal classes
		class icm_machine_unit_pool_default : public icm_machine_unit_pool {
		public:
			icm_machine_unit_pool_default(icm_machine *m, const std::string &name, mops::UNIT_TYPE ut, const carray<icm_machines_::unit_map> &cum, int units)
				: icm_machine_unit_pool(m, name, 0, ut, cum, units) { }
		private:
			virtual bool tick_int_(mop *m) { return m->decr_timing(); }
			virtual bool is_ready_int_(const mop *m) const { return m->is_ready(); }
			virtual bool check_timing_int_(const mop *m) const { return m->get_timing()==0; }
			virtual icm_machine_unit_pool *exec_int_(mop *m) { m->exec(); return 0; }
		};

		class icm_machine_unit_pool_abrq : public icm_machine_unit_pool {
		public:
			icm_machine_unit_pool_abrq(icm_machine *m, const carray<icm_machines_::unit_map> &ecum)
				: icm_machine_unit_pool(m, "ABRQ", 0, mops::UT_MEM, ecum, 1) { }
		private:
			virtual bool tick_int_(mop *) { return false; }
			virtual bool is_ready_int_(const mop *m) const { return m->is_write() || m->is_read() && m->is_ready_addr(); }
			virtual bool check_timing_int_(const mop *) const { return true; } // ignore timing, it is only forwarder
			virtual icm_machine_unit_pool *exec_int_(mop *m);
		};

		class icm_machine_unit_pool_abwq : public icm_machine_unit_pool {
		public:
			icm_machine_unit_pool_abwq(icm_machine *m, icm_machine_unit_pool *abrq, const carray<icm_machines_::unit_map> &cum)
				: icm_machine_unit_pool(m, "ABWQ", 0, mops::UT_MEM, cum, 1),abrq_(abrq) { }
		private:
			icm_machine_unit_pool   *abrq_;
			virtual bool tick_int_(mop *) { return false; }
			virtual bool is_ready_int_(const mop *m) const { return m->is_read() || m->is_write() && m->is_ready_addr(); }
			virtual bool check_timing_int_(const mop *) const { return true; } // ignore timing, it is only forwarder
			virtual icm_machine_unit_pool *exec_int_(mop *) { return abrq_; }
		};

		class icm_machine_unit_pool_dbwqi_mem : public icm_machine_unit_pool {
		public:
			icm_machine_unit_pool_dbwqi_mem(icm_machine *m, unsigned a, icm_machine_unit_pool *rwqi, const carray<icm_machines_::unit_map> &ecum)
				: icm_machine_unit_pool(m, "DBWQI_MEM", a, mops::UT_MEM, ecum, 1),rwqi_(rwqi) { }
		private:
			icm_machine_unit_pool   *rwqi_;
			virtual bool tick_int_(mop *) { return false; }
			virtual bool is_ready_int_(const mop *m) const { return m->is_ready(); }
			virtual bool check_timing_int_(const mop *) const { return true; } // ignore timing, it is only forwarder
			virtual icm_machine_unit_pool *exec_int_(mop *) { return rwqi_; }
		};

		class icm_machine_unit_pool_dbwqi_reg : public icm_machine_unit_pool {
		public:
			icm_machine_unit_pool_dbwqi_reg(icm_machine *m, unsigned a, const carray<icm_machines_::unit_map> &ecum)
				: icm_machine_unit_pool(m, "DBWQI_REG", a, mops::UT_REG, ecum, 1) { }
		private:
			virtual bool tick_int_(mop *m) { return m->decr_timing(); }
			virtual bool is_ready_int_(const mop *m) const { return m->is_ready(); }
			virtual bool check_timing_int_(const mop *m) const { return m->get_timing()==0; }
			virtual icm_machine_unit_pool *exec_int_(mop *m) { m->exec(); return 0; }
		};

		class icm_machine_unit_pool_rwqi : public icm_machine_unit_pool {
		public:
			icm_machine_unit_pool_rwqi(icm_machine *m, unsigned a, icm_machine_unit_pool *rrq, const carray<icm_machines_::unit_map> &ecum)
				: icm_machine_unit_pool(m, "RWQI", a, mops::UT_MEM, ecum, 1),rrq_(rrq),pending_(0) { }
			bool decr_pending(); // this unit may become ready
		private:
			icm_machine_unit_pool   *rrq_;
			int							pending_;
			virtual bool tick_int_(mop *) { return false; }
			virtual bool is_ready_int_(const mop *m) const { return m->is_write()?pending_==0:pending_>=0; } // write is ready, when there is nothing issued yet, read is ready, when there is no pending WRITE
			virtual bool check_timing_int_(const mop *) const { return true; } // ignore timing, it is only forwarder
			virtual icm_machine_unit_pool *exec_int_(mop *m);
		};

		class icm_machine_unit_pool_rrq : public icm_machine_unit_pool {
		public:
			icm_machine_unit_pool_rrq(icm_machine *m, const carray<icm_machines_::unit_map> &ecum, int units)
				: icm_machine_unit_pool(m, "RRQ", 0, mops::UT_MEM, ecum, units) { }
		private:
			virtual bool tick_int_(mop *m) { return m->decr_timing(); }
			virtual bool is_ready_int_(const mop *) const { return true; }
			virtual bool check_timing_int_(const mop *m) const { return m->get_timing()==0; }
			virtual icm_machine_unit_pool *exec_int_(mop *m);
		};

		class icm_machine_unit_pool_reg_dispatch : public icm_machine_unit_pool {
		public:
			icm_machine_unit_pool_reg_dispatch(icm_machine *m, const std::string &name, mops::UNIT_TYPE ut, const carray<icm_machines_::unit_map> &cum)
				: icm_machine_unit_pool(m, name, 0, ut, cum, 1) { }
		private:
			virtual bool tick_int_(mop *) { return false; }
			virtual bool is_ready_int_(const mop *) const { return true; }
			virtual bool check_timing_int_(const mop *) const { return true; } // ignore timing, it is only forwarder
			virtual icm_machine_unit_pool *exec_int_(mop *);
		};

	};

	class ftor_max_reg
	{
	public:
		ftor_max_reg() : mr_(0) { }
		mlaskal::ICABSNUM get_max_reg() const { return mr_; }
		void operator()(const mlaskal::file_function &ff) { if (ff.get_used_regs()>mr_) mr_ = ff.get_used_regs(); }
	private:
		mlaskal::ICABSNUM mr_;
	};

	struct machine_factory {
		static icm_machine *create_machine(const icm_machines_::machine &m, const icm_flat_icblock *inic, std::ostream *os, const icm_machine_trace_options &to)
		{
			// compute required number of registers
			ftor_max_reg fmv;
			fmv = std::for_each(inic->get_fncs().begin(), inic->get_fncs().end(), fmv);
			ICABSNUM regs = fmv.get_max_reg();

			return m.creator_(&m, regs, inic, os, to);
		}
	};

}

#endif
