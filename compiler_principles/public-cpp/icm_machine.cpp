/*

	icm_machine.cpp

	ICM machine implementation

	Kuba, 2006

*/

#include <algorithm>
#include <iterator>
#include <utility>
#include <cassert>
#include <set>
#include <sstream>

#include <iostream>

#include "icm_machine.hpp"
#include "mops.hpp"
#include "ic_instrtab.hpp"
#include "ic_instr.hpp"
#include "icm_flat_icblock.hpp"

using namespace std;
using namespace mlaskal;

namespace {

	instr_decode_::instr_mop fetcher_mop_int_[] = {
			{ mops::MOPC_RDIP,				"rdip",				0,				0,				0				 },
			{ mops::MOPC_FETCH,				"fetch",		"rdip",				0,				0				 },
	};

	const carray<instr_decode_::instr_mop> fetcher_mop(fetcher_mop_int_);

	class ftor_check_instr {
	public:
		ftor_check_instr(   ICREGNUM regs,
							const carray<ai::IC_OPCODE> &allowed_instr,
							mlaskal::lit_storage<int, false>::size_type int_sz, 
							mlaskal::lit_storage<double, false>::size_type real_sz, 
							mlaskal::lit_storage<string, false>::size_type str_sz,
							vector<ic_instr *>::size_type instr_sz) 
			: int_sz_(int_sz),real_sz_(real_sz),str_sz_(str_sz),instr_sz_(instr_sz),regs_(regs),ip_(0)
		{
			// create the set of allowed instructions
			copy(allowed_instr.begin(), allowed_instr.end(), inserter(allowed_instr_, allowed_instr_.begin()));
		}
		void operator()(const mlaskal::ic_instr *instr)
		{
			// check for allowed instructions
			if(allowed_instr_.find(instr->get_opcode())==allowed_instr_.end())
				throw ic_except(ICET_INSTR_NOT_ALLOWED, ip_);

			// check registers
			if(ai::ic_instrtab[instr->get_opcode()].in1_ptype_!=PTYPE_UNDEF && instr->get_in1()>=regs_)
				throw ic_except(ICET_REG_IDX_OUT_RANGE, ip_);
			if(ai::ic_instrtab[instr->get_opcode()].in2_ptype_!=PTYPE_UNDEF && instr->get_in2()>=regs_)
				throw ic_except(ICET_REG_IDX_OUT_RANGE, ip_);
			if(ai::ic_instrtab[instr->get_opcode()].in3_ptype_!=PTYPE_UNDEF && instr->get_in3()>=regs_)
				throw ic_except(ICET_REG_IDX_OUT_RANGE, ip_);
			if(ai::ic_instrtab[instr->get_opcode()].in4_ptype_!=PTYPE_UNDEF && instr->get_in4()>=regs_)
				throw ic_except(ICET_REG_IDX_OUT_RANGE, ip_);
			if(ai::ic_instrtab[instr->get_opcode()].out_ptype_!=PTYPE_UNDEF && instr->get_out()>=regs_)
				throw ic_except(ICET_REG_IDX_OUT_RANGE, ip_);

			// check literals & jumps
			switch(ai::ic_instrtab[instr->get_opcode()].stkp_type_)
			{
			case ICSPT_LITINT:
				if(static_cast<ICLITIDX>(instr->get_stkn())>=int_sz_)
					throw ic_except(ICET_LIT_IDX_OUT_RANGE, ip_);
				break;
			case ICSPT_LITREAL:
				if(static_cast<ICLITIDX>(instr->get_stkn())>=real_sz_)
					throw ic_except(ICET_LIT_IDX_OUT_RANGE, ip_);
				break;
			case ICSPT_LITSTR:
				if(static_cast<ICLITIDX>(instr->get_stkn())>=str_sz_)
					throw ic_except(ICET_LIT_IDX_OUT_RANGE, ip_);
				break;
			case ICSPT_ABSJUMP:
				if(static_cast<ICABSNUM>(instr->get_stkn())>=instr_sz_)
					throw ic_except(ICET_JUMP_OUT_CODE, ip_);
				break;
			case ICSPT_RELJUMP:
				if(static_cast<ICABSNUM>(ip_+instr->get_stkn())>=instr_sz_)
					throw ic_except(ICET_JUMP_OUT_CODE, ip_);
				break;
			default:
				// ignore the rest - added for fucking off with GCC
				break;
			}

			// change state
			++ip_;
		}
	private:
		std::set<ai::IC_OPCODE>		allowed_instr_;
		mlaskal::lit_storage<int, false>::size_type int_sz_;
		mlaskal::lit_storage<double, false>::size_type real_sz_;
		mlaskal::lit_storage<string, false>::size_type str_sz_;
		vector<ic_instr *>::size_type instr_sz_;
		ICREGNUM	regs_;
		ICABSNUM	ip_;					// !!!!!stateful
	};

	struct ftor_kill_unit_pool {
		void operator()(icm_machine_unit_pool *up) { delete up; }
	};

	carray<icm_machines_::unit_map> empty_unit_map;

	struct ftor_find_main {
		bool operator()(const file_function &ff) { return ff.get_type()==FNCSIG_PROGRAM; }
	};
}

namespace mlaskal {

	icm_machine::icm_machine(const icm_machines_::machine *m, ICABSNUM regs, const icm_flat_icblock *inic, ostream *os, const icm_machine_trace_options &to) 
		: name_(m->name_),regs_(regs),ip_(0),fp_(0),sp_(static_cast<ICMT_PTR>(-1)),halted_(false),mops_in_pools_(0),os_(os),
		regs_read_(regs, 0),regs_write_(regs, 0),to_(to),rrq_(0)
	{
		// copy instructions & literal storages
		copy(inic->get_icblock().begin(), inic->get_icblock().end(), back_inserter(instrs_));
		copy(inic->get_ls_int().begin(), inic->get_ls_int().end(), back_inserter(ls_int_));
		copy(inic->get_ls_real().begin(), inic->get_ls_real().end(), back_inserter(ls_real_));
		copy(inic->get_ls_string().begin(), inic->get_ls_string().end(), back_inserter(ls_string_));

		// create DBWQI for registers
		for(ICABSNUM r=0;r<regs;++r)
			reg_dbwqi_.push_back(new icm_machine_unit_pool_dbwqi_reg(this, r, empty_unit_map));

		// carefully build units
		for(carray<icm_machines_::machine_unit>::const_iterator cui=m->units_.begin();cui!=m->units_.end();++cui)
			switch(cui->unit_->unit_type_)
			{
			case mops::UT_MEM:
				{
					rrq_ = new icm_machine_unit_pool_rrq(   this,
															empty_unit_map,
															cui->n_units_);
					unit_pools_.push_back(rrq_);
					icm_machine_unit_pool *abrq = new icm_machine_unit_pool_abrq(this, empty_unit_map);
					unit_pools_.push_back(abrq);
					icm_machine_unit_pool *abwq = new icm_machine_unit_pool_abwq(this, abrq, cui->unit_->umap_);
					unit_pools_.push_back(abwq);
				}
				break;
			case mops::UT_REG:				// this is not a true register unit, it is only register dispatcher
				unit_pools_.push_back(new icm_machine_unit_pool_reg_dispatch(
															this,
															cui->unit_->name_,
															cui->unit_->unit_type_,
															cui->unit_->umap_
															));

				break;
			default:			// all others (including FETCHER, HALT, IPREG, SPREG, FPREG) are default
				unit_pools_.push_back(new icm_machine_unit_pool_default(
															this,
															cui->unit_->name_,
															cui->unit_->unit_type_,
															cui->unit_->umap_,
															cui->n_units_));
				break;
			}

		assert(rrq_!=0);		// there MUST be back end memory unit

		// find my mops and build mop->unit map - do it by hand: check for duplicates and get iterators
		for(vector<icm_machine_unit_pool *>::iterator iu=unit_pools_.begin();iu!=unit_pools_.end();++iu)
			for(carray<icm_machines_::unit_map>::const_iterator ccum=(*iu)->get_cum().begin();ccum!=(*iu)->get_cum().end();++ccum)
			{
				mop_worker uw = { *iu, ccum->timing_ };
				pair<map<mops::MOP_MOPCODE, mop_worker>::iterator, bool> prv = map_mop2unit_.insert(make_pair(ccum->mop_code_, uw));
				assert(prv.second==true);	// this mop can be 
			}

		static_check_ic(m->allowed_instrs_);

		icm_flat_icblock::file_functions_type::const_iterator mainit=find_if(inic->get_fncs().begin(), inic->get_fncs().end(), ftor_find_main());
		assert(mainit!=inic->get_fncs().end());			// no PROGRAM?
		if (mainit == inic->get_fncs().end()) throw std::domain_error("No main function detected");
		ip_ = mainit->get_icip_start();

	}

	icm_machine::~icm_machine()
	{
		for_each(unit_pools_.begin(), unit_pools_.end(), ftor_kill_unit_pool());
		for_each(stack_dbwqi_.begin(), stack_dbwqi_.end(), ftor_kill_unit_pool());
		for_each(stack_rwqi_.begin(), stack_rwqi_.end(), ftor_kill_unit_pool());
		for_each(reg_dbwqi_.begin(), reg_dbwqi_.end(), ftor_kill_unit_pool());
	}

	void icm_machine::static_check_ic(const carray<ai::IC_OPCODE> &allowed_instrs) const
	{
		for_each(instrs_.begin(), instrs_.end(), 
				ftor_check_instr(static_cast<ICREGNUM>(regs_.size()), allowed_instrs, 
									ls_int_.size(), ls_real_.size(), ls_string_.size(), instrs_.size()));
	}

	void icm_machine::simulate()
	{
		// inject initial mops
		instructions_ = 0;
		inject_mops(fetcher_mop, static_cast<ICMT_ICIP>(-1));
		for(tick_=0;!halted_ || mops_in_pools_!=0;++tick_)
		{
			if(os_)
			{
				*os_ << "\t\t<tick>\n";
				*os_ << "\t\t\t<tick_number>" << tick_ << "</tick_number>\n";
				if(to_.trace_state)
				{
					*os_ << "\t\t\t<state>\n";
					*os_ << "\t\t\t\t<IP>" << ip_ << "</IP>\n";
					*os_ << "\t\t\t\t<FP>" << fp_ << "</FP>\n";
					*os_ << "\t\t\t\t<SP>" << sp_ << "</SP>\n";
					*os_ << "\t\t\t\t<unit_pools>\n";
					// queue for normal units
					for(vector<icm_machine_unit_pool *>::const_iterator upi=unit_pools_.begin();upi!=unit_pools_.end();++upi)
					{
						*os_ << "\t\t\t<unit_pool>\n";
						*os_ << "\t\t\t\t<unit_name>" << (*upi)->get_name() << "</unit_name>\n";
						*os_ << "\t\t\t\t<queue>\n";
						(*upi)->trace_queue(os_);
						*os_ << "\t\t\t\t</queue>\n";
						*os_ << "\t\t\t</unit_pool>\n";
					}
					// queue for registers
					for(vector<icm_machine_unit_pool *>::const_iterator upi=reg_dbwqi_.begin();upi!=reg_dbwqi_.end();++upi)
					{
						*os_ << "\t\t\t<unit_pool>\n";
						*os_ << "\t\t\t\t<unit_name>" << (*upi)->get_name() << "</unit_name>\n";
						*os_ << "\t\t\t\t<unit_instance>" << (*upi)->get_instance() << "</unit_instance>\n";
						*os_ << "\t\t\t\t<queue>\n";
						(*upi)->trace_queue(os_);
						*os_ << "\t\t\t\t</queue>\n";
						*os_ << "\t\t\t</unit_pool>\n";
					}
					// queue for memory
					for(vector<icm_machine_unit_pool_rwqi *>::const_iterator upi=stack_rwqi_.begin();upi!=stack_rwqi_.end();++upi)
					{
						*os_ << "\t\t\t<unit_pool>\n";
						*os_ << "\t\t\t\t<unit_name>" << (*upi)->get_name() << "</unit_name>\n";
						*os_ << "\t\t\t\t<unit_instance>" << (*upi)->get_instance() << "</unit_instance>\n";
						*os_ << "\t\t\t\t<queue>\n";
						(*upi)->trace_queue(os_);
						*os_ << "\t\t\t\t</queue>\n";
						*os_ << "\t\t\t</unit_pool>\n";
					}
					*os_ << "\t\t\t\t</unit_pools>\n";
					*os_ << "\t\t\t</state>\n";
				}
				*os_ << "\t\t\t<actions>\n";
			}

			// run ready mops
			while(!ready_unit_pools_.empty())
			{
				set<icm_machine_unit_pool *>::iterator iup=ready_unit_pools_.begin();
				icm_machine_unit_pool *up=*iup;

				up->exec_all(ready_unit_pools_, os_);			// does everything possible in this unit pool and inserts new ready units

				ready_unit_pools_.erase(iup);
			}

			// do tick

			// tick normal units
			for(vector<icm_machine_unit_pool *>::iterator upi=unit_pools_.begin();upi!=unit_pools_.end();++upi)
				if((*upi)->tick())
					ready_unit_pools_.insert(*upi);
			// tick registers
			for(vector<icm_machine_unit_pool *>::iterator upi=reg_dbwqi_.begin();upi!=reg_dbwqi_.end();++upi)
				if((*upi)->tick())
					ready_unit_pools_.insert(*upi);
			// tick memory
			// commented out by Bobulka: icm_machine_unit_pool_rwqi::tick() always returns false!
			/*
			for(vector<icm_machine_unit_pool_rwqi *>::iterator upi=stack_rwqi_.begin();upi!=stack_rwqi_.end();++upi)
				if((*upi)->tick())
					ready_unit_pools_.insert(*upi);
			*/
			if(os_)
			{
				*os_ << "\t\t\t</actions>\n";
				*os_ << "\t\t</tick>\n";
			}

		}
	}

	void icm_machine::fetch(ICMT_ICIP ip)
	{
		if(to_.instruction_limit_!=0 && to_.instruction_limit_<=instructions_)
			throw ic_except(ICET_INSTR_LIMIT_REACHED, ip);
		++instructions_;

		if(os_)
		{
			*os_ << "\t\t\t\t<fetch>\n";
			*os_ << "\t\t\t\t\t<IP>" << ip << "</IP>\n";
			*os_ << "\t\t\t\t</fetch>\n";
		}

		inject_mops(instr_decode_::instr_decodes[instrs_[ip]->get_opcode()], ip);
		if(instrs_[ip]->get_opcode()!=ai::ICOP_HALT)			// it is not HALT - read others
			inject_mops(fetcher_mop, static_cast<ICMT_ICIP>(-1));
	}

	SHRVAL icm_machine::get_mem(ICABSNUM adr, ICMT_ICIP ip)
	{
		if(adr>=stack_.size())
			throw ic_except(ICET_STKOFFS_OUT_RANGE, ip);
		++stack_read_[adr];
		return stack_[adr];
	}

	void icm_machine::set_mem(ICABSNUM adr, SHRVAL v, ICMT_ICIP ip)
	{
		if(adr>=stack_.size())
			throw ic_except(ICET_STKOFFS_OUT_RANGE, ip);
		++stack_write_[adr];
		stack_[adr] = v;
	}

	void icm_machine::set_sp(ICMT_PTR sp)
	{
		if(static_cast<ICRELNUM>(sp)>=static_cast<ICRELNUM>(stack_.size()))
			resize_stack(sp);
		sp_ = sp;
	}

	void icm_machine::inject_mops(const carray<instr_decode_::instr_mop> &mops, ICMT_ICIP ip)
	{
		map<string, mop *> mop_id_map;
		vector<mop *> new_mops;

		// create new mops and map ids
		for(carray<instr_decode_::instr_mop>::const_iterator cdmi=mops.begin();cdmi!=mops.end();++cdmi)
		{
			map<mops::MOP_MOPCODE, mop_worker>::const_iterator mw=map_mop2unit_.find(cdmi->mop_code_);
			assert(mw!=map_mop2unit_.end());			// mop without a unit
			mop *m=mop_factory::create_mop(cdmi->mop_code_, static_cast<int>(ip)<0?0:instrs_[ip], this, mw->second.unit_pool_, ip, string(cdmi->id_), mw->second.timing_);
			pair<map<string, mop *>::iterator, bool> mim = mop_id_map.insert(make_pair(string(cdmi->id_), m));
			assert(mim.second);		// instruction decode contains the same ID
			new_mops.push_back(m);

			// set output patches
			if(cdmi->in1_id_)
			{
				map<string, mop *>::iterator i1=mop_id_map.find(string(cdmi->in1_id_));
				assert(i1!=mop_id_map.end());				// IN1 is unknown ID
				i1->second->push_back_tgt(m, 1);
			}
			if(cdmi->in2_id_)
			{
				map<string, mop *>::iterator i2=mop_id_map.find(string(cdmi->in2_id_));
				assert(i2!=mop_id_map.end());				// IN2 is unknown ID
				i2->second->push_back_tgt(m, 2);
			}
			if(cdmi->in3_id_)
			{
				map<string, mop *>::iterator i3=mop_id_map.find(string(cdmi->in3_id_));
				assert(i3!=mop_id_map.end());				// IN3 is unknown ID
				i3->second->push_back_tgt(m, 3);
			}
		}

		// now injects new mops into proper unit pools and checks, if the unit pool becomes ready
		for(vector<mop *>::const_iterator cim=new_mops.begin();cim!=new_mops.end();++cim)
		{
			++mops_in_pools_;
			if((*cim)->get_unit_pool()->push_back(*cim))	// the unit pool reports, that it becomes ready due to this mop
				ready_unit_pools_.insert((*cim)->get_unit_pool());
		}
	}

	void icm_machine::resize_stack(ICMT_PTR new_size)
	{
		/*
		if(os_)
			*os_ << "Resizing stack to " << new_size << '\n';
		*/
		if(to_.stack_limit_!=0 && to_.stack_limit_<=new_size)
			throw ic_except(ICET_STACK_LIMIT_REACHED, ip_);

		for(ICMT_PTR p=static_cast<ICMT_PTR>(stack_.size());p<=new_size;++p)
		{
			stack_.push_back(SHRVAL(new icv::NOTHING()));
			stack_read_.push_back(0);
			stack_write_.push_back(0);
			icm_machine_unit_pool_rwqi *rwqi=new icm_machine_unit_pool_rwqi(this, p, rrq_, empty_unit_map);
			stack_rwqi_.push_back(rwqi);
			stack_dbwqi_.push_back(new icm_machine_unit_pool_dbwqi_mem(this, p, rwqi, empty_unit_map));
		}
	}

	icm_machine_unit_pool * icm_machine::icm_machine_unit_pool_abrq::exec_int_(mlaskal::mop *m)
	{
		ICMT_PTR adr;
		if((adr=m->get_addr()->getPTR(m->get_ip()))>=m_->stack_dbwqi_.size())			// problem with memory size
		{
			if(m->is_read())									// if it is a read, it is problem
				throw ic_except(ICET_STKOFFS_OUT_RANGE, m->get_ip());
			// write resizes memory
			m_->resize_stack(adr);
		}
		return m_->stack_dbwqi_[adr];
	}

	icm_machine_unit_pool * icm_machine::icm_machine_unit_pool_reg_dispatch::exec_int_(mop *m)
	{
		assert(m->get_regnum()<m_->reg_dbwqi_.size());		// should be already checked by static check
		return m_->reg_dbwqi_[m->get_regnum()];
	}

	bool icm_machine_unit_pool::push_back(mop *m)
	{
		m->set_unit_pool(this);
		if(!q_.empty() || !is_ready(m) || free_units_==0)   // do not support advancing, mop is not ready or there is no free unit
		{
			q_.push_back(m);			// so push to the queue and report the unit pool is NOT ready
			return false;
		}

		return setup_free_unit(m);
	}

	void icm_machine_unit_pool::exec_all(set<icm_machine_unit_pool *> &rdy_up, ostream *os)
	{
		// go arround and arround and finish after all units are empty or need ticks or on the front of the queue is not a ready mop
		for(vunits_type::size_type cnt=0;cnt<units_.size();)
		{
			mop *m;
			if(!units_[unit_exec_idx_].is_free() && check_timing(m=units_[unit_exec_idx_].get_mop()))   // it is not a free unit and is ready to execute
			{
				icm_machine_unit_pool *up = exec(m);
				++mops_;
				if(up)						// forwarding
				{
					if(os)
					{
						*os << "\t\t\t\t<forward>\n";
						*os << "\t\t\t\t\t<mop>\n";
						*os << "\t\t\t\t\t\t<IP>" << m->get_ip() << "</IP>\n";
						*os << "\t\t\t\t\t\t<mod_id>" << m->get_id() << "</mod_id>\n";
						*os << "\t\t\t\t\t</mop>\n";
						*os << "\t\t\t\t\t<from_unit>\n";
						*os << "\t\t\t\t\t\t<name>" << name_ << "</name>\n";
						*os << "\t\t\t\t\t\t<instance>" << instance_ << "</instance>\n";
						*os << "\t\t\t\t\t</from_unit>\n";
						*os << "\t\t\t\t\t<to_unit>\n";
						*os << "\t\t\t\t\t\t<name>" << up->get_name() << "</name>\n";
						*os << "\t\t\t\t\t\t<instance>" << up->get_instance() << "</instance>\n";
						*os << "\t\t\t\t\t</to_unit>\n";
						*os << "\t\t\t\t</forward>\n";
					}

					if(up->push_back(m))
						rdy_up.insert(up);
				}
				else						// finally it has done something, so patch targets and kill the mop
				{
					if(os)
					{
						*os << "\t\t\t\t<execute>\n";
						*os << "\t\t\t\t\t<mop>\n";
						if(static_cast<int>(m->get_ip())>=0)
							*os << "\t\t\t\t\t\t<IP>" << m->get_ip() << "</IP>\n";
						*os << "\t\t\t\t\t\t<mod_id>" << m->get_id() << "</mod_id>\n";
						*os << "\t\t\t\t\t</mop>\n";
						*os << "\t\t\t\t\t<unit>\n";
						*os << "\t\t\t\t\t\t<name>" << name_ << "</name>\n";
						*os << "\t\t\t\t\t\t<instance>" << instance_ << "</instance>\n";
						*os << "\t\t\t\t\t</unit>\n";
						*os << "\t\t\t\t</execute>\n";
					}

					// patch targets
					for(vector<mop::mop_target>::const_iterator cit=m->begin_tgt();cit!=m->end_tgt();++cit)
					{
						mop *tm=cit->tgt_mop_;
						if(tm->get_unit_pool()->patch_mop(tm, cit->idx, m->get_out()))		// unit pool is ready
							rdy_up.insert(tm->get_unit_pool());						
					}
					// kill it - this is the only place, where mops are destroyed
					m_->mop_destroyed();
					delete m;
				}

				// so the unit becomes free - is there anything to do?
				if(!q_.empty() && is_ready(m=q_.front()))
				{
					units_[unit_exec_idx_].set_mop(m);
					q_.pop_front();		// remove the head from the queue

					if(check_timing(m))
						cnt = 0;				// something has changed - begin again
					else
						++cnt;
				}
				else
				{
					units_[unit_exec_idx_].set_mop(0);			// it is free now
					++free_units_;
					++cnt;
					if(!q_.empty())		// the queue is not empty, so now it is stalling
						++stalling_;
				}
			}
			else
				++cnt;
			if(++unit_exec_idx_>=units_.size()) // cycle around
				unit_exec_idx_ = 0;
		}
	}

	bool icm_machine_unit_pool::patch_mop(mop *m, int idx, SHRVAL v)
	{
		m->set_in(idx, v);
		if(!q_.empty() && q_.front()==m && is_ready(m))			// it is my head and it becomes ready
		{
			bool ready=false;
			// suck everything ready from queue into free units
			while(free_units_>0 && !q_.empty() && is_ready(m=q_.front()))
			{
				q_.pop_front();
				if(setup_free_unit(m))
					ready = true;
			}
			return ready;
		}
		return false;
	}

	bool icm_machine_unit_pool::setup_free_unit(mop *m)
	{
		// begin with search
		vunits_type::size_type cnt;
		for(cnt=0;cnt<units_.size();++cnt)
		{
			if(units_[unit_dispatch_idx_].is_free())
				break;
			if(++unit_dispatch_idx_>=units_.size()) // cycle around
				unit_dispatch_idx_ = 0;
		}
		assert(cnt<units_.size());		// wtf, free_units_ reports a free unit, but nothing has been found
		units_[unit_dispatch_idx_].set_mop(m);
		--free_units_;						
		return check_timing(m);
	}

	bool icm_machine_unit_pool::tick()
	{
		bool ready=false;
		// go through all units and make a tick
		for(vunits_type::iterator ui=units_.begin();ui!=units_.end();++ui)
			if(!ui->is_free())
			{
				mop *m = ui->get_mop();
				assert(m->get_timing()!=0);		// it must NOT be 0
				if(tick(m))
					ready = true;

			}
		if(ready)
			++working_;
		return ready;
	}

	void icm_machine_unit_pool::trace_queue(ostream *os) const
	{
		for(deque<mop*>::const_iterator dci=q_.begin();dci!=q_.end();++dci)
		{
			*os << "\t\t\t\t\t<mop>\n";
			*os << "\t\t\t\t\t\t<IP>" << (*dci)->get_ip() << "</IP>\n";
			*os << "\t\t\t\t\t\t<mop_id>" << (*dci)->get_id() << "</mop_id>\n";
			*os << "\t\t\t\t\t</mop>\n";
		}
	}

	icm_machine_unit_pool *icm_machine::icm_machine_unit_pool_rrq::exec_int_(mop *m)
	{
		m->exec(); 
		icm_machine_unit_pool_rwqi *rwqi = m_->stack_rwqi_[m->get_addr()->getPTR(m->get_ip())];
		if(rwqi->decr_pending())
			m_->ready_unit_pools_.insert(rwqi);
		return 0;
	}

	icm_machine_unit_pool *icm_machine::icm_machine_unit_pool_rwqi::exec_int_(mop *m)
	{
		 if(m->is_read())
			 ++pending_;
		 else
			 --pending_;
		 return rrq_; 
	}

	bool icm_machine::icm_machine_unit_pool_rwqi::decr_pending()
	{
		if(pending_>0)			// reads
			--pending_;
		else
			++pending_;

		if(pending_==0 && !q_.empty())		// now everything is consumed in RRQ, is there anything, which awaits?
		{
			mop *m=q_.front();
			q_.pop_front();
			setup_free_unit(m);
			return true;
		}
		else
			return false;
	}

	void icm_machine::write_stats() const
	{
		if(!*os_)
			return;

		*os_ << "\t<stats>\n";
		*os_ << "\t\t<ticks>" << tick_ << "</ticks>\n";
		*os_ << "\t\t<instructions>" << instructions_ << "</instructions>\n";
		*os_ << "\t\t<registers>\n";
		*os_ << "\t\t\t<used>" << regs_.size() << "</used>\n";
		for(vector<unsigned>::size_type rn=0;rn<regs_.size();++rn)
		{
			*os_ << "\t\t\t<register>\n";
			*os_ << "\t\t\t\t<regnum>" << rn <<"</regnum>\n";
			*os_ << "\t\t\t\t<reads>" << regs_read_[rn] <<"</reads>\n";
			*os_ << "\t\t\t\t<writes>" << regs_write_[rn] <<"</writes>\n";
			*os_ << "\t\t\t</register>\n";
		}
		*os_ << "\t\t</registers>\n";
		*os_ << "\t\t<stack>\n";
		*os_ << "\t\t\t<used>" << stack_.size() << "</used>\n";
		for(vector<unsigned>::size_type a=0;a<stack_.size();++a)
		{
			*os_ << "\t\t\t<register>\n";
			*os_ << "\t\t\t\t<addr>" << a <<"</addr>\n";
			*os_ << "\t\t\t\t<reads>" << stack_read_[a] <<"</reads>\n";
			*os_ << "\t\t\t\t<writes>" << stack_write_[a] <<"</writes>\n";
			*os_ << "\t\t\t</register>\n";
		}
		*os_ << "\t\t</stack>\n";
		*os_ << "\t\t<unit_pools>\n";
		// stats for normal units
		for(vector<icm_machine_unit_pool *>::const_iterator upi=unit_pools_.begin();upi!=unit_pools_.end();++upi)
		{
			*os_ << "\t\t\t<unit_pool_type>\n";
			*os_ << "\t\t\t\t<name>" << (*upi)->get_name() << "</name>\n";
			*os_ << "\t\t\t\t<unit_pool>\n";
			*os_ << "\t\t\t\t\t<working>" << (*upi)->get_working() << "</working>\n";
			*os_ << "\t\t\t\t\t<stalling>" << (*upi)->get_stalling() << "</stalling>\n";
			*os_ << "\t\t\t\t\t<mops>" << (*upi)->get_mops() << "</mops>\n";
			*os_ << "\t\t\t\t</unit_pool>\n";
			*os_ << "\t\t\t</unit_pool_type>\n";
		}
		// stats for registers
		if(reg_dbwqi_.size())
		{
			*os_ << "\t\t\t<unit_pool_type>\n";
			*os_ << "\t\t\t\t<name>" << reg_dbwqi_.front()->get_name() << "</name>\n";
			for(vector<icm_machine_unit_pool *>::const_iterator upi=reg_dbwqi_.begin();upi!=reg_dbwqi_.end();++upi)
			{
				*os_ << "\t\t\t\t<unit_pool>\n";
				*os_ << "\t\t\t\t\t<instance>" << (*upi)->get_instance() << "</instance>\n";
				*os_ << "\t\t\t\t\t<working>" << (*upi)->get_working() << "</working>\n";
				*os_ << "\t\t\t\t\t<stalling>" << (*upi)->get_stalling() << "</stalling>\n";
				*os_ << "\t\t\t\t\t<mops>" << (*upi)->get_mops() << "</mops>\n";
				*os_ << "\t\t\t\t</unit_pool>\n";
			}
			*os_ << "\t\t\t</unit_pool_type>\n";
		}
		// stats for memory
		if(stack_rwqi_.size())
		{
			*os_ << "\t\t\t<unit_pool_type>\n";
			*os_ << "\t\t\t\t<name>" << stack_rwqi_.front()->get_name() << "</name>\n";
			for(vector<icm_machine_unit_pool_rwqi *>::const_iterator upi=stack_rwqi_.begin();upi!=stack_rwqi_.end();++upi)
			{
				*os_ << "\t\t\t\t<unit_pool>\n";
				*os_ << "\t\t\t\t\t<instance>" << (*upi)->get_instance() << "</instance>\n";
				*os_ << "\t\t\t\t\t<working>" << (*upi)->get_working() << "</working>\n";
				*os_ << "\t\t\t\t\t<stalling>" << (*upi)->get_stalling() << "</stalling>\n";
				*os_ << "\t\t\t\t\t<mops>" << (*upi)->get_mops() << "</mops>\n";
				*os_ << "\t\t\t\t</unit_pool>\n";
			}
			*os_ << "\t\t\t</unit_pool_type>\n";
		}
		*os_ << "\t\t</unit_pools>\n";
		*os_ << "\t</stats>\n";
	}

}
