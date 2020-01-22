/*
	GEN_MOPS.CPP

	GENERATED, DO NOT MODIFY!!!!
*/

#include <iostream>
#include <cassert>
#include "mops.hpp"
#include "ic_instr.hpp"
#include "icm_machine.hpp"

namespace mlaskal {

namespace mops {

	class ABSNUMC : public mop {
	public:
		ABSNUMC(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return true; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void ABSNUMC::exec_int_() {
		ICMT_ICIP out;
		out = static_cast<ICMT_ICIP>(instr_->get_stkn());	
		out_ = SHRVAL(new icv::ICIP(out));
	}

	class ADDI : public mop {
	public:
		ADDI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void ADDI::exec_int_() {
		ICMT_INT in1 = in1_->getINT(ip_);
		ICMT_INT in2 = in2_->getINT(ip_);
		ICMT_INT out;
		out = in1+in2;
		out_ = SHRVAL(new icv::INT(out));
	}

	class ADDLSTKOFFS : public mop {
	public:
		ADDLSTKOFFS(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void ADDLSTKOFFS::exec_int_() {
		ICMT_PTR in1 = in1_->getPTR(ip_);
		ICMT_PTR out;
		out = instr_->get_stkn()+in1;		
		out_ = SHRVAL(new icv::PTR(out));
	}

	class ADDP : public mop {
	public:
		ADDP(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void ADDP::exec_int_() {
		ICMT_PTR in1 = in1_->getPTR(ip_);
		ICMT_INT in2 = in2_->getINT(ip_);
		ICMT_PTR out;
		out = in1+in2;
		out_ = SHRVAL(new icv::PTR(out));
	}

	class ADDR : public mop {
	public:
		ADDR(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void ADDR::exec_int_() {
		ICMT_REAL in1 = in1_->getREAL(ip_);
		ICMT_REAL in2 = in2_->getREAL(ip_);
		ICMT_REAL out;
		out = in1+in2;
		out_ = SHRVAL(new icv::REAL(out));
	}

	class ADDRELNUMC : public mop {
	public:
		ADDRELNUMC(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void ADDRELNUMC::exec_int_() {
		ICMT_ICIP in1 = in1_->getICIP(ip_);
		ICMT_ICIP out;
		out = instr_->get_stkn()+in1;		
		out_ = SHRVAL(new icv::ICIP(out));
	}

	class ADDRELNUMIFFC : public mop {
	public:
		ADDRELNUMIFFC(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void ADDRELNUMIFFC::exec_int_() {
		ICMT_ICIP in1 = in1_->getICIP(ip_);
		ICMT_BOOL in2 = in2_->getBOOL(ip_);
		ICMT_ICIP out;
		out = in1+(in2==false?instr_->get_stkn():1);
		out_ = SHRVAL(new icv::ICIP(out));
	}

	class ADDRELNUMIFTC : public mop {
	public:
		ADDRELNUMIFTC(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void ADDRELNUMIFTC::exec_int_() {
		ICMT_ICIP in1 = in1_->getICIP(ip_);
		ICMT_BOOL in2 = in2_->getBOOL(ip_);
		ICMT_ICIP out;
		out = in1+(in2==true?instr_->get_stkn():1);
		out_ = SHRVAL(new icv::ICIP(out));
	}

	class ADDS : public mop {
	public:
		ADDS(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void ADDS::exec_int_() {
		ICMT_STRING in1 = in1_->getSTRING(ip_);
		ICMT_STRING in2 = in2_->getSTRING(ip_);
		ICMT_STRING out;
		out = in1+in2;
		out_ = SHRVAL(new icv::STRING(out));
	}

	class ADDSSTKOFFS : public mop {
	public:
		ADDSSTKOFFS(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void ADDSSTKOFFS::exec_int_() {
		ICMT_PTR in1 = in1_->getPTR(ip_);
		ICMT_PTR out;
		out = instr_->get_stkn()+in1;		
		out_ = SHRVAL(new icv::PTR(out));
	}

	class AND : public mop {
	public:
		AND(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void AND::exec_int_() {
		ICMT_BOOL in1 = in1_->getBOOL(ip_);
		ICMT_BOOL in2 = in2_->getBOOL(ip_);
		ICMT_BOOL out;
		out = in1 && in2;
		out_ = SHRVAL(new icv::BOOL(out));
	}

	class BEI : public mop {
	public:
		BEI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void BEI::exec_int_() {
		ICMT_INT in1 = in1_->getINT(ip_);
		ICMT_INT in2 = in2_->getINT(ip_);
		ICMT_BOOL out;
		out = in1==in2;
		out_ = SHRVAL(new icv::BOOL(out));
	}

	class CVRTIR : public mop {
	public:
		CVRTIR(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void CVRTIR::exec_int_() {
		ICMT_INT in1 = in1_->getINT(ip_);
		ICMT_REAL out;
		out = static_cast<ICMT_REAL>(in1);
		out_ = SHRVAL(new icv::REAL(out));
	}

	class CVRTRI : public mop {
	public:
		CVRTRI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void CVRTRI::exec_int_() {
		ICMT_REAL in1 = in1_->getREAL(ip_);
		ICMT_INT out;
		out = static_cast<ICMT_INT>(in1);	
		out_ = SHRVAL(new icv::INT(out));
	}

	class DEC2P : public mop {
	public:
		DEC2P(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void DEC2P::exec_int_() {
		ICMT_PTR in1 = in1_->getPTR(ip_);
		ICMT_PTR out;
		out = in1-2;	
		out_ = SHRVAL(new icv::PTR(out));
	}

	class DECP : public mop {
	public:
		DECP(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void DECP::exec_int_() {
		ICMT_PTR in1 = in1_->getPTR(ip_);
		ICMT_PTR out;
		out = in1-1;	
		out_ = SHRVAL(new icv::PTR(out));
	}

	class DIVI : public mop {
	public:
		DIVI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void DIVI::exec_int_() {
		ICMT_INT in1 = in1_->getINT(ip_);
		ICMT_INT in2 = in2_->getINT(ip_);
		ICMT_INT out;
		out = in1/in2;
		out_ = SHRVAL(new icv::INT(out));
	}

	class DIVR : public mop {
	public:
		DIVR(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void DIVR::exec_int_() {
		ICMT_REAL in1 = in1_->getREAL(ip_);
		ICMT_REAL in2 = in2_->getREAL(ip_);
		ICMT_REAL out;
		out = in1/in2;
		out_ = SHRVAL(new icv::REAL(out));
	}

	class EQB : public mop {
	public:
		EQB(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void EQB::exec_int_() {
		ICMT_BOOL in1 = in1_->getBOOL(ip_);
		ICMT_BOOL in2 = in2_->getBOOL(ip_);
		ICMT_BOOL out;
		out = in1==in2;
		out_ = SHRVAL(new icv::BOOL(out));
	}

	class EQI : public mop {
	public:
		EQI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void EQI::exec_int_() {
		ICMT_INT in1 = in1_->getINT(ip_);
		ICMT_INT in2 = in2_->getINT(ip_);
		ICMT_BOOL out;
		out = in1==in2;
		out_ = SHRVAL(new icv::BOOL(out));
	}

	class EQR : public mop {
	public:
		EQR(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void EQR::exec_int_() {
		ICMT_REAL in1 = in1_->getREAL(ip_);
		ICMT_REAL in2 = in2_->getREAL(ip_);
		ICMT_BOOL out;
		out = in1==in2;
		out_ = SHRVAL(new icv::BOOL(out));
	}

	class EQS : public mop {
	public:
		EQS(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void EQS::exec_int_() {
		ICMT_STRING in1 = in1_->getSTRING(ip_);
		ICMT_STRING in2 = in2_->getSTRING(ip_);
		ICMT_BOOL out;
		out = in1==in2;
		out_ = SHRVAL(new icv::BOOL(out));
	}

	class EXTRACTFP : public mop {
	public:
		EXTRACTFP(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void EXTRACTFP::exec_int_() {
		ICMT_RA in1 = in1_->getRA(ip_);
		ICMT_PTR out;
		out = in1.prev_fp_;
		out_ = SHRVAL(new icv::PTR(out));
	}

	class EXTRACTIP : public mop {
	public:
		EXTRACTIP(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void EXTRACTIP::exec_int_() {
		ICMT_RA in1 = in1_->getRA(ip_);
		ICMT_ICIP out;
		out = in1.ra_;
		out_ = SHRVAL(new icv::ICIP(out));
	}

	class FETCH : public mop {
	public:
		FETCH(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void FETCH::exec_int_() {
		ICMT_ICIP in1 = in1_->getICIP(ip_);
		mach_->fetch(in1);
	}

	class FNCREADI : public mop {
	public:
		FNCREADI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return true; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void FNCREADI::exec_int_() {
		ICMT_INT out;
		std::cin >> out;
		out_ = SHRVAL(new icv::INT(out));
	}

	class FNCREADR : public mop {
	public:
		FNCREADR(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return true; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void FNCREADR::exec_int_() {
		ICMT_REAL out;
		std::cin >> out;
		out_ = SHRVAL(new icv::REAL(out));
	}

	class FNCREADS : public mop {
	public:
		FNCREADS(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return true; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void FNCREADS::exec_int_() {
		ICMT_STRING out;
		std::cin >> out;
		out_ = SHRVAL(new icv::STRING(out));
	}

	class FNCWRITEI : public mop {
	public:
		FNCWRITEI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void FNCWRITEI::exec_int_() {
		ICMT_INT in1 = in1_->getINT(ip_);
		std::cout << in1;
	}

	class FNCWRITELN : public mop {
	public:
		FNCWRITELN(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return true; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void FNCWRITELN::exec_int_() {
		std::cout << '\n';
	}

	class FNCWRITER : public mop {
	public:
		FNCWRITER(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void FNCWRITER::exec_int_() {
		ICMT_REAL in1 = in1_->getREAL(ip_);
		std::cout << in1;
	}

	class FNCWRITES : public mop {
	public:
		FNCWRITES(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void FNCWRITES::exec_int_() {
		ICMT_STRING in1 = in1_->getSTRING(ip_);
		std::cout << in1;
	}

	class GEB : public mop {
	public:
		GEB(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void GEB::exec_int_() {
		ICMT_BOOL in1 = in1_->getBOOL(ip_);
		ICMT_BOOL in2 = in2_->getBOOL(ip_);
		ICMT_BOOL out;
		out = in1>=in2;
		out_ = SHRVAL(new icv::BOOL(out));
	}

	class GEI : public mop {
	public:
		GEI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void GEI::exec_int_() {
		ICMT_INT in1 = in1_->getINT(ip_);
		ICMT_INT in2 = in2_->getINT(ip_);
		ICMT_BOOL out;
		out = in1>=in2;
		out_ = SHRVAL(new icv::BOOL(out));
	}

	class GER : public mop {
	public:
		GER(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void GER::exec_int_() {
		ICMT_REAL in1 = in1_->getREAL(ip_);
		ICMT_REAL in2 = in2_->getREAL(ip_);
		ICMT_BOOL out;
		out = in1>=in2;
		out_ = SHRVAL(new icv::BOOL(out));
	}

	class GES : public mop {
	public:
		GES(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void GES::exec_int_() {
		ICMT_STRING in1 = in1_->getSTRING(ip_);
		ICMT_STRING in2 = in2_->getSTRING(ip_);
		ICMT_BOOL out;
		out = in1>=in2;
		out_ = SHRVAL(new icv::BOOL(out));
	}

	class GSTKOFFS : public mop {
	public:
		GSTKOFFS(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return true; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void GSTKOFFS::exec_int_() {
		ICMT_PTR out;
		out = static_cast<ICMT_PTR>(instr_->get_stkn());	
		out_ = SHRVAL(new icv::PTR(out));
	}

	class GTB : public mop {
	public:
		GTB(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void GTB::exec_int_() {
		ICMT_BOOL in1 = in1_->getBOOL(ip_);
		ICMT_BOOL in2 = in2_->getBOOL(ip_);
		ICMT_BOOL out;
		out = in1>in2;
		out_ = SHRVAL(new icv::BOOL(out));
	}

	class GTI : public mop {
	public:
		GTI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void GTI::exec_int_() {
		ICMT_INT in1 = in1_->getINT(ip_);
		ICMT_INT in2 = in2_->getINT(ip_);
		ICMT_BOOL out;
		out = in1>in2;
		out_ = SHRVAL(new icv::BOOL(out));
	}

	class GTR : public mop {
	public:
		GTR(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void GTR::exec_int_() {
		ICMT_REAL in1 = in1_->getREAL(ip_);
		ICMT_REAL in2 = in2_->getREAL(ip_);
		ICMT_BOOL out;
		out = in1>in2;
		out_ = SHRVAL(new icv::BOOL(out));
	}

	class GTS : public mop {
	public:
		GTS(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void GTS::exec_int_() {
		ICMT_STRING in1 = in1_->getSTRING(ip_);
		ICMT_STRING in2 = in2_->getSTRING(ip_);
		ICMT_BOOL out;
		out = in1>in2;
		out_ = SHRVAL(new icv::BOOL(out));
	}

	class HALT : public mop {
	public:
		HALT(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return true; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void HALT::exec_int_() {
		ICMT_ICIP out;
		out = mach_->halt(ip_);
		out_ = SHRVAL(new icv::ICIP(out));
	}

	class INCC : public mop {
	public:
		INCC(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void INCC::exec_int_() {
		ICMT_ICIP in1 = in1_->getICIP(ip_);
		ICMT_ICIP out;
		out = in1+1;	
		out_ = SHRVAL(new icv::ICIP(out));
	}

	class INCP : public mop {
	public:
		INCP(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void INCP::exec_int_() {
		ICMT_PTR in1 = in1_->getPTR(ip_);
		ICMT_PTR out;
		out = in1+1;	
		out_ = SHRVAL(new icv::PTR(out));
	}

	class INITB : public mop {
	public:
		INITB(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return true; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void INITB::exec_int_() {
		
		out_ = SHRVAL(new icv::BOOL());
	}

	class INITI : public mop {
	public:
		INITI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return true; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void INITI::exec_int_() {
		
		out_ = SHRVAL(new icv::INT());
	}

	class INITR : public mop {
	public:
		INITR(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return true; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void INITR::exec_int_() {
		
		out_ = SHRVAL(new icv::REAL());
	}

	class INITS : public mop {
	public:
		INITS(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return true; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void INITS::exec_int_() {
		
		out_ = SHRVAL(new icv::STRING());
	}

	class LDLITB : public mop {
	public:
		LDLITB(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return true; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void LDLITB::exec_int_() {
		ICMT_BOOL out;
		out = !!instr_->get_stkn();
		out_ = SHRVAL(new icv::BOOL(out));
	}

	class LDLITI : public mop {
	public:
		LDLITI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return true; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void LDLITI::exec_int_() {
		ICMT_INT out;
		out = mach_->get_ls_int(static_cast<ICLITIDX>(instr_->get_stkn()));
		out_ = SHRVAL(new icv::INT(out));
	}

	class LDLITR : public mop {
	public:
		LDLITR(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return true; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void LDLITR::exec_int_() {
		ICMT_REAL out;
		out = mach_->get_ls_real(static_cast<ICLITIDX>(instr_->get_stkn()));
		out_ = SHRVAL(new icv::REAL(out));
	}

	class LDLITS : public mop {
	public:
		LDLITS(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return true; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void LDLITS::exec_int_() {
		ICMT_STRING out;
		out = mach_->get_ls_string(static_cast<ICLITIDX>(instr_->get_stkn()));
		out_ = SHRVAL(new icv::STRING(out));
	}

	class LEB : public mop {
	public:
		LEB(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void LEB::exec_int_() {
		ICMT_BOOL in1 = in1_->getBOOL(ip_);
		ICMT_BOOL in2 = in2_->getBOOL(ip_);
		ICMT_BOOL out;
		out = in1<=in2;
		out_ = SHRVAL(new icv::BOOL(out));
	}

	class LEI : public mop {
	public:
		LEI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void LEI::exec_int_() {
		ICMT_INT in1 = in1_->getINT(ip_);
		ICMT_INT in2 = in2_->getINT(ip_);
		ICMT_BOOL out;
		out = in1<=in2;
		out_ = SHRVAL(new icv::BOOL(out));
	}

	class LER : public mop {
	public:
		LER(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void LER::exec_int_() {
		ICMT_REAL in1 = in1_->getREAL(ip_);
		ICMT_REAL in2 = in2_->getREAL(ip_);
		ICMT_BOOL out;
		out = in1<=in2;
		out_ = SHRVAL(new icv::BOOL(out));
	}

	class LES : public mop {
	public:
		LES(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void LES::exec_int_() {
		ICMT_STRING in1 = in1_->getSTRING(ip_);
		ICMT_STRING in2 = in2_->getSTRING(ip_);
		ICMT_BOOL out;
		out = in1<=in2;
		out_ = SHRVAL(new icv::BOOL(out));
	}

	class LTB : public mop {
	public:
		LTB(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void LTB::exec_int_() {
		ICMT_BOOL in1 = in1_->getBOOL(ip_);
		ICMT_BOOL in2 = in2_->getBOOL(ip_);
		ICMT_BOOL out;
		out = in1<in2;
		out_ = SHRVAL(new icv::BOOL(out));
	}

	class LTI : public mop {
	public:
		LTI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void LTI::exec_int_() {
		ICMT_INT in1 = in1_->getINT(ip_);
		ICMT_INT in2 = in2_->getINT(ip_);
		ICMT_BOOL out;
		out = in1<in2;
		out_ = SHRVAL(new icv::BOOL(out));
	}

	class LTR : public mop {
	public:
		LTR(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void LTR::exec_int_() {
		ICMT_REAL in1 = in1_->getREAL(ip_);
		ICMT_REAL in2 = in2_->getREAL(ip_);
		ICMT_BOOL out;
		out = in1<in2;
		out_ = SHRVAL(new icv::BOOL(out));
	}

	class LTS : public mop {
	public:
		LTS(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void LTS::exec_int_() {
		ICMT_STRING in1 = in1_->getSTRING(ip_);
		ICMT_STRING in2 = in2_->getSTRING(ip_);
		ICMT_BOOL out;
		out = in1<in2;
		out_ = SHRVAL(new icv::BOOL(out));
	}

	class MERGERA : public mop {
	public:
		MERGERA(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void MERGERA::exec_int_() {
		ICMT_ICIP in1 = in1_->getICIP(ip_);
		ICMT_PTR in2 = in2_->getPTR(ip_);
		ICMT_RA out;
		out.prev_fp_ = in2;out.ra_ = in1;
		out_ = SHRVAL(new icv::RA(out));
	}

	class MINUSI : public mop {
	public:
		MINUSI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void MINUSI::exec_int_() {
		ICMT_INT in1 = in1_->getINT(ip_);
		ICMT_INT out;
		out = -in1;	
		out_ = SHRVAL(new icv::INT(out));
	}

	class MINUSR : public mop {
	public:
		MINUSR(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void MINUSR::exec_int_() {
		ICMT_REAL in1 = in1_->getREAL(ip_);
		ICMT_REAL out;
		out = -in1;	
		out_ = SHRVAL(new icv::REAL(out));
	}

	class MODI : public mop {
	public:
		MODI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void MODI::exec_int_() {
		ICMT_INT in1 = in1_->getINT(ip_);
		ICMT_INT in2 = in2_->getINT(ip_);
		ICMT_INT out;
		out = in1%in2;
		out_ = SHRVAL(new icv::INT(out));
	}

	class MULI : public mop {
	public:
		MULI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void MULI::exec_int_() {
		ICMT_INT in1 = in1_->getINT(ip_);
		ICMT_INT in2 = in2_->getINT(ip_);
		ICMT_INT out;
		out = in1*in2;
		out_ = SHRVAL(new icv::INT(out));
	}

	class MULR : public mop {
	public:
		MULR(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void MULR::exec_int_() {
		ICMT_REAL in1 = in1_->getREAL(ip_);
		ICMT_REAL in2 = in2_->getREAL(ip_);
		ICMT_REAL out;
		out = in1*in2;
		out_ = SHRVAL(new icv::REAL(out));
	}

	class NEB : public mop {
	public:
		NEB(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void NEB::exec_int_() {
		ICMT_BOOL in1 = in1_->getBOOL(ip_);
		ICMT_BOOL in2 = in2_->getBOOL(ip_);
		ICMT_BOOL out;
		out = in1!=in2;
		out_ = SHRVAL(new icv::BOOL(out));
	}

	class NEI : public mop {
	public:
		NEI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void NEI::exec_int_() {
		ICMT_INT in1 = in1_->getINT(ip_);
		ICMT_INT in2 = in2_->getINT(ip_);
		ICMT_BOOL out;
		out = in1!=in2;
		out_ = SHRVAL(new icv::BOOL(out));
	}

	class NER : public mop {
	public:
		NER(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void NER::exec_int_() {
		ICMT_REAL in1 = in1_->getREAL(ip_);
		ICMT_REAL in2 = in2_->getREAL(ip_);
		ICMT_BOOL out;
		out = in1!=in2;
		out_ = SHRVAL(new icv::BOOL(out));
	}

	class NES : public mop {
	public:
		NES(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void NES::exec_int_() {
		ICMT_STRING in1 = in1_->getSTRING(ip_);
		ICMT_STRING in2 = in2_->getSTRING(ip_);
		ICMT_BOOL out;
		out = in1!=in2;
		out_ = SHRVAL(new icv::BOOL(out));
	}

	class NOT : public mop {
	public:
		NOT(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void NOT::exec_int_() {
		ICMT_BOOL in1 = in1_->getBOOL(ip_);
		ICMT_BOOL out;
		out = !in1;	
		out_ = SHRVAL(new icv::BOOL(out));
	}

	class OR : public mop {
	public:
		OR(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void OR::exec_int_() {
		ICMT_BOOL in1 = in1_->getBOOL(ip_);
		ICMT_BOOL in2 = in2_->getBOOL(ip_);
		ICMT_BOOL out;
		out = in1 || in2;
		out_ = SHRVAL(new icv::BOOL(out));
	}

	class RDFP : public mop {
	public:
		RDFP(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return true; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return true; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void RDFP::exec_int_() {
		ICMT_PTR out;
		out = mach_->get_fp();
		out_ = SHRVAL(new icv::PTR(out));
	}

	class RDIN1 : public mop {
	public:
		RDIN1(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return true; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return true; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { return instr_->get_in1(); }
		virtual void exec_int_();
	};

	void RDIN1::exec_int_() {
		out_ = mach_->get_reg(instr_->get_in1());if(out_.get()==0) out_=SHRVAL(new icv::BOOL());
	}

	class RDIN1B : public mop {
	public:
		RDIN1B(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return true; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return true; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { return instr_->get_in1(); }
		virtual void exec_int_();
	};

	void RDIN1B::exec_int_() {
		ICMT_BOOL out;
		out = mach_->get_reg(instr_->get_in1())->getBOOL(ip_);
		out_ = SHRVAL(new icv::BOOL(out));
	}

	class RDIN1I : public mop {
	public:
		RDIN1I(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return true; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return true; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { return instr_->get_in1(); }
		virtual void exec_int_();
	};

	void RDIN1I::exec_int_() {
		ICMT_INT out;
		out = mach_->get_reg(instr_->get_in1())->getINT(ip_);
		out_ = SHRVAL(new icv::INT(out));
	}

	class RDIN1P : public mop {
	public:
		RDIN1P(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return true; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return true; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { return instr_->get_in1(); }
		virtual void exec_int_();
	};

	void RDIN1P::exec_int_() {
		ICMT_PTR out;
		out = mach_->get_reg(instr_->get_in1())->getPTR(ip_);
		out_ = SHRVAL(new icv::PTR(out));
	}

	class RDIN1R : public mop {
	public:
		RDIN1R(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return true; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return true; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { return instr_->get_in1(); }
		virtual void exec_int_();
	};

	void RDIN1R::exec_int_() {
		ICMT_REAL out;
		out = mach_->get_reg(instr_->get_in1())->getREAL(ip_);
		out_ = SHRVAL(new icv::REAL(out));
	}

	class RDIN1S : public mop {
	public:
		RDIN1S(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return true; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return true; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { return instr_->get_in1(); }
		virtual void exec_int_();
	};

	void RDIN1S::exec_int_() {
		ICMT_STRING out;
		out = mach_->get_reg(instr_->get_in1())->getSTRING(ip_);
		out_ = SHRVAL(new icv::STRING(out));
	}

	class RDIN2B : public mop {
	public:
		RDIN2B(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return true; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return true; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { return instr_->get_in2(); }
		virtual void exec_int_();
	};

	void RDIN2B::exec_int_() {
		ICMT_BOOL out;
		out = mach_->get_reg(instr_->get_in2())->getBOOL(ip_);
		out_ = SHRVAL(new icv::BOOL(out));
	}

	class RDIN2I : public mop {
	public:
		RDIN2I(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return true; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return true; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { return instr_->get_in2(); }
		virtual void exec_int_();
	};

	void RDIN2I::exec_int_() {
		ICMT_INT out;
		out = mach_->get_reg(instr_->get_in2())->getINT(ip_);
		out_ = SHRVAL(new icv::INT(out));
	}

	class RDIN2P : public mop {
	public:
		RDIN2P(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return true; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return true; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { return instr_->get_in2(); }
		virtual void exec_int_();
	};

	void RDIN2P::exec_int_() {
		ICMT_PTR out;
		out = mach_->get_reg(instr_->get_in2())->getPTR(ip_);
		out_ = SHRVAL(new icv::PTR(out));
	}

	class RDIN2R : public mop {
	public:
		RDIN2R(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return true; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return true; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { return instr_->get_in2(); }
		virtual void exec_int_();
	};

	void RDIN2R::exec_int_() {
		ICMT_REAL out;
		out = mach_->get_reg(instr_->get_in2())->getREAL(ip_);
		out_ = SHRVAL(new icv::REAL(out));
	}

	class RDIN2S : public mop {
	public:
		RDIN2S(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return true; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return true; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { return instr_->get_in2(); }
		virtual void exec_int_();
	};

	void RDIN2S::exec_int_() {
		ICMT_STRING out;
		out = mach_->get_reg(instr_->get_in2())->getSTRING(ip_);
		out_ = SHRVAL(new icv::STRING(out));
	}

	class RDIN3P : public mop {
	public:
		RDIN3P(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return true; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return true; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { return instr_->get_in3(); }
		virtual void exec_int_();
	};

	void RDIN3P::exec_int_() {
		ICMT_PTR out;
		out = mach_->get_reg(instr_->get_in3())->getPTR(ip_);
		out_ = SHRVAL(new icv::PTR(out));
	}

	class RDIN4P : public mop {
	public:
		RDIN4P(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return true; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return true; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { return instr_->get_in4(); }
		virtual void exec_int_();
	};

	void RDIN4P::exec_int_() {
		ICMT_PTR out;
		out = mach_->get_reg(instr_->get_in4())->getPTR(ip_);
		out_ = SHRVAL(new icv::PTR(out));
	}

	class RDIP : public mop {
	public:
		RDIP(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return true; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return true; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void RDIP::exec_int_() {
		ICMT_ICIP out;
		out = mach_->get_ip();
		out_ = SHRVAL(new icv::ICIP(out));
	}

	class RDMEM : public mop {
	public:
		RDMEM(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { return in1_.get()!=0; }
		virtual bool is_read_int_() const { return true; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void RDMEM::exec_int_() {
		ICMT_PTR in1 = in1_->getPTR(ip_);
		out_ = mach_->get_mem(in1, ip_);
	}

	class RDMEMB : public mop {
	public:
		RDMEMB(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { return in1_.get()!=0; }
		virtual bool is_read_int_() const { return true; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void RDMEMB::exec_int_() {
		ICMT_PTR in1 = in1_->getPTR(ip_);
		ICMT_BOOL out;
		out = mach_->get_mem(in1, ip_)->getBOOL(ip_);
		out_ = SHRVAL(new icv::BOOL(out));
	}

	class RDMEMF : public mop {
	public:
		RDMEMF(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { return in1_.get()!=0; }
		virtual bool is_read_int_() const { return true; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void RDMEMF::exec_int_() {
		ICMT_PTR in1 = in1_->getPTR(ip_);
		ICMT_RA out;
		out = mach_->get_mem(in1, ip_)->getRA(ip_);
		out_ = SHRVAL(new icv::RA(out));
	}

	class RDMEMI : public mop {
	public:
		RDMEMI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { return in1_.get()!=0; }
		virtual bool is_read_int_() const { return true; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void RDMEMI::exec_int_() {
		ICMT_PTR in1 = in1_->getPTR(ip_);
		ICMT_INT out;
		out = mach_->get_mem(in1, ip_)->getINT(ip_);
		out_ = SHRVAL(new icv::INT(out));
	}

	class RDMEMP : public mop {
	public:
		RDMEMP(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { return in1_.get()!=0; }
		virtual bool is_read_int_() const { return true; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void RDMEMP::exec_int_() {
		ICMT_PTR in1 = in1_->getPTR(ip_);
		ICMT_PTR out;
		out = mach_->get_mem(in1, ip_)->getPTR(ip_);
		out_ = SHRVAL(new icv::PTR(out));
	}

	class RDMEMR : public mop {
	public:
		RDMEMR(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { return in1_.get()!=0; }
		virtual bool is_read_int_() const { return true; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void RDMEMR::exec_int_() {
		ICMT_PTR in1 = in1_->getPTR(ip_);
		ICMT_REAL out;
		out = mach_->get_mem(in1, ip_)->getREAL(ip_);
		out_ = SHRVAL(new icv::REAL(out));
	}

	class RDMEMS : public mop {
	public:
		RDMEMS(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { return in1_.get()!=0; }
		virtual bool is_read_int_() const { return true; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void RDMEMS::exec_int_() {
		ICMT_PTR in1 = in1_->getPTR(ip_);
		ICMT_STRING out;
		out = mach_->get_mem(in1, ip_)->getSTRING(ip_);
		out_ = SHRVAL(new icv::STRING(out));
	}

	class RDSP : public mop {
	public:
		RDSP(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return true; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return true; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void RDSP::exec_int_() {
		ICMT_PTR out;
		out = mach_->get_sp();
		out_ = SHRVAL(new icv::PTR(out));
	}

	class SUBI : public mop {
	public:
		SUBI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void SUBI::exec_int_() {
		ICMT_INT in1 = in1_->getINT(ip_);
		ICMT_INT in2 = in2_->getINT(ip_);
		ICMT_INT out;
		out = in1-in2;
		out_ = SHRVAL(new icv::INT(out));
	}

	class SUBP : public mop {
	public:
		SUBP(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void SUBP::exec_int_() {
		ICMT_PTR in1 = in1_->getPTR(ip_);
		ICMT_INT in2 = in2_->getINT(ip_);
		ICMT_PTR out;
		out = in1-in2;
		out_ = SHRVAL(new icv::PTR(out));
	}

	class SUBR : public mop {
	public:
		SUBR(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return false; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void SUBR::exec_int_() {
		ICMT_REAL in1 = in1_->getREAL(ip_);
		ICMT_REAL in2 = in2_->getREAL(ip_);
		ICMT_REAL out;
		out = in1-in2;
		out_ = SHRVAL(new icv::REAL(out));
	}

	class WRFP : public mop {
	public:
		WRFP(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return true; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void WRFP::exec_int_() {
		ICMT_PTR in1 = in1_->getPTR(ip_);
		mach_->set_fp(in1);
	}

	class WRIP : public mop {
	public:
		WRIP(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return true; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void WRIP::exec_int_() {
		ICMT_ICIP in1 = in1_->getICIP(ip_);
		mach_->set_ip(in1);
	}

	class WRMEM : public mop {
	public:
		WRMEM(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { return in1_.get()!=0; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return true; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void WRMEM::exec_int_() {
		ICMT_PTR in1 = in1_->getPTR(ip_);
		mach_->set_mem(in1, in2_, ip_);
	}

	class WRMEMB : public mop {
	public:
		WRMEMB(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { return in1_.get()!=0; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return true; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void WRMEMB::exec_int_() {
		ICMT_PTR in1 = in1_->getPTR(ip_);
		mach_->set_mem(in1, in2_, ip_);
	}

	class WRMEMF : public mop {
	public:
		WRMEMF(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { return in1_.get()!=0; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return true; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void WRMEMF::exec_int_() {
		ICMT_PTR in1 = in1_->getPTR(ip_);
		mach_->set_mem(in1, in2_, ip_);
	}

	class WRMEMI : public mop {
	public:
		WRMEMI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { return in1_.get()!=0; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return true; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void WRMEMI::exec_int_() {
		ICMT_PTR in1 = in1_->getPTR(ip_);
		mach_->set_mem(in1, in2_, ip_);
	}

	class WRMEMP : public mop {
	public:
		WRMEMP(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { return in1_.get()!=0; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return true; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void WRMEMP::exec_int_() {
		ICMT_PTR in1 = in1_->getPTR(ip_);
		mach_->set_mem(in1, in2_, ip_);
	}

	class WRMEMR : public mop {
	public:
		WRMEMR(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { return in1_.get()!=0; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return true; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void WRMEMR::exec_int_() {
		ICMT_PTR in1 = in1_->getPTR(ip_);
		mach_->set_mem(in1, in2_, ip_);
	}

	class WRMEMS : public mop {
	public:
		WRMEMS(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0 && in2_.get()!=0; }
		virtual bool is_ready_addr_int_() const { return in1_.get()!=0; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return true; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void WRMEMS::exec_int_() {
		ICMT_PTR in1 = in1_->getPTR(ip_);
		mach_->set_mem(in1, in2_, ip_);
	}

	class WROUT : public mop {
	public:
		WROUT(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return true; }
		virtual ICREGNUM get_regnum_int_() const { return instr_->get_out(); }
		virtual void exec_int_();
	};

	void WROUT::exec_int_() {
		mach_->set_reg(instr_->get_out(), in1_);
	}

	class WROUTB : public mop {
	public:
		WROUTB(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return true; }
		virtual ICREGNUM get_regnum_int_() const { return instr_->get_out(); }
		virtual void exec_int_();
	};

	void WROUTB::exec_int_() {
		mach_->set_reg(instr_->get_out(), in1_);
	}

	class WROUTI : public mop {
	public:
		WROUTI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return true; }
		virtual ICREGNUM get_regnum_int_() const { return instr_->get_out(); }
		virtual void exec_int_();
	};

	void WROUTI::exec_int_() {
		mach_->set_reg(instr_->get_out(), in1_);
	}

	class WROUTP : public mop {
	public:
		WROUTP(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return true; }
		virtual ICREGNUM get_regnum_int_() const { return instr_->get_out(); }
		virtual void exec_int_();
	};

	void WROUTP::exec_int_() {
		mach_->set_reg(instr_->get_out(), in1_);
	}

	class WROUTR : public mop {
	public:
		WROUTR(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return true; }
		virtual ICREGNUM get_regnum_int_() const { return instr_->get_out(); }
		virtual void exec_int_();
	};

	void WROUTR::exec_int_() {
		mach_->set_reg(instr_->get_out(), in1_);
	}

	class WROUTS : public mop {
	public:
		WROUTS(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return true; }
		virtual ICREGNUM get_regnum_int_() const { return instr_->get_out(); }
		virtual void exec_int_();
	};

	void WROUTS::exec_int_() {
		mach_->set_reg(instr_->get_out(), in1_);
	}

	class WRSP : public mop {
	public:
		WRSP(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) : mop(instr, mach, up, ip, mop_id, timing) { }
	private:
		virtual bool is_ready_int_() const { return in1_.get()!=0; }
		virtual bool is_ready_addr_int_() const { assert(0); return true; }
		virtual bool is_read_int_() const { return false; }
		virtual bool is_write_int_() const { return true; }
		virtual ICREGNUM get_regnum_int_() const { assert(0); return static_cast<ICREGNUM>(-1); }
		virtual void exec_int_();
	};

	void WRSP::exec_int_() {
		ICMT_PTR in1 = in1_->getPTR(ip_);
		mach_->set_sp(in1);
	}

	mop *create_ABSNUMC(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new ABSNUMC(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_ADDI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new ADDI(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_ADDLSTKOFFS(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new ADDLSTKOFFS(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_ADDP(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new ADDP(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_ADDR(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new ADDR(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_ADDRELNUMC(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new ADDRELNUMC(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_ADDRELNUMIFFC(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new ADDRELNUMIFFC(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_ADDRELNUMIFTC(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new ADDRELNUMIFTC(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_ADDS(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new ADDS(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_ADDSSTKOFFS(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new ADDSSTKOFFS(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_AND(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new AND(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_BEI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new BEI(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_CVRTIR(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new CVRTIR(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_CVRTRI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new CVRTRI(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_DEC2P(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new DEC2P(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_DECP(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new DECP(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_DIVI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new DIVI(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_DIVR(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new DIVR(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_EQB(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new EQB(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_EQI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new EQI(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_EQR(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new EQR(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_EQS(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new EQS(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_EXTRACTFP(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new EXTRACTFP(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_EXTRACTIP(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new EXTRACTIP(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_FETCH(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new FETCH(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_FNCREADI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new FNCREADI(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_FNCREADR(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new FNCREADR(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_FNCREADS(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new FNCREADS(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_FNCWRITEI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new FNCWRITEI(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_FNCWRITELN(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new FNCWRITELN(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_FNCWRITER(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new FNCWRITER(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_FNCWRITES(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new FNCWRITES(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_GEB(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new GEB(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_GEI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new GEI(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_GER(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new GER(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_GES(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new GES(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_GSTKOFFS(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new GSTKOFFS(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_GTB(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new GTB(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_GTI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new GTI(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_GTR(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new GTR(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_GTS(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new GTS(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_HALT(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new HALT(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_INCC(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new INCC(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_INCP(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new INCP(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_INITB(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new INITB(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_INITI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new INITI(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_INITR(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new INITR(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_INITS(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new INITS(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_LDLITB(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new LDLITB(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_LDLITI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new LDLITI(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_LDLITR(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new LDLITR(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_LDLITS(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new LDLITS(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_LEB(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new LEB(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_LEI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new LEI(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_LER(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new LER(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_LES(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new LES(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_LTB(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new LTB(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_LTI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new LTI(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_LTR(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new LTR(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_LTS(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new LTS(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_MERGERA(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new MERGERA(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_MINUSI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new MINUSI(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_MINUSR(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new MINUSR(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_MODI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new MODI(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_MULI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new MULI(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_MULR(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new MULR(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_NEB(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new NEB(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_NEI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new NEI(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_NER(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new NER(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_NES(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new NES(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_NOT(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new NOT(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_OR(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new OR(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_RDFP(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new RDFP(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_RDIN1(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new RDIN1(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_RDIN1B(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new RDIN1B(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_RDIN1I(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new RDIN1I(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_RDIN1P(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new RDIN1P(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_RDIN1R(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new RDIN1R(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_RDIN1S(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new RDIN1S(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_RDIN2B(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new RDIN2B(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_RDIN2I(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new RDIN2I(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_RDIN2P(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new RDIN2P(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_RDIN2R(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new RDIN2R(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_RDIN2S(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new RDIN2S(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_RDIN3P(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new RDIN3P(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_RDIN4P(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new RDIN4P(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_RDIP(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new RDIP(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_RDMEM(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new RDMEM(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_RDMEMB(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new RDMEMB(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_RDMEMF(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new RDMEMF(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_RDMEMI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new RDMEMI(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_RDMEMP(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new RDMEMP(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_RDMEMR(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new RDMEMR(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_RDMEMS(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new RDMEMS(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_RDSP(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new RDSP(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_SUBI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new SUBI(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_SUBP(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new SUBP(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_SUBR(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new SUBR(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_WRFP(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new WRFP(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_WRIP(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new WRIP(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_WRMEM(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new WRMEM(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_WRMEMB(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new WRMEMB(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_WRMEMF(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new WRMEMF(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_WRMEMI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new WRMEMI(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_WRMEMP(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new WRMEMP(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_WRMEMR(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new WRMEMR(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_WRMEMS(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new WRMEMS(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_WROUT(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new WROUT(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_WROUTB(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new WROUTB(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_WROUTI(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new WROUTI(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_WROUTP(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new WROUTP(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_WROUTR(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new WROUTR(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_WROUTS(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new WROUTS(instr, mach, up, ip, mop_id, timing);
	}

	mop *create_WRSP(const ic_instr *instr, icm_machine *mach, icm_machine_unit_pool *up, ICMT_ICIP ip, std::string mop_id, unsigned timing) {
		return new WRSP(instr, mach, up, ip, mop_id, timing);
	}

} // namespace mops

	mop_factory::mop_creator mop_factory::creators[mops::MOPC_DNOTUSE_MAX_] = {
		mops::create_ABSNUMC,
		mops::create_ADDI,
		mops::create_ADDLSTKOFFS,
		mops::create_ADDP,
		mops::create_ADDR,
		mops::create_ADDRELNUMC,
		mops::create_ADDRELNUMIFFC,
		mops::create_ADDRELNUMIFTC,
		mops::create_ADDS,
		mops::create_ADDSSTKOFFS,
		mops::create_AND,
		mops::create_BEI,
		mops::create_CVRTIR,
		mops::create_CVRTRI,
		mops::create_DEC2P,
		mops::create_DECP,
		mops::create_DIVI,
		mops::create_DIVR,
		mops::create_EQB,
		mops::create_EQI,
		mops::create_EQR,
		mops::create_EQS,
		mops::create_EXTRACTFP,
		mops::create_EXTRACTIP,
		mops::create_FETCH,
		mops::create_FNCREADI,
		mops::create_FNCREADR,
		mops::create_FNCREADS,
		mops::create_FNCWRITEI,
		mops::create_FNCWRITELN,
		mops::create_FNCWRITER,
		mops::create_FNCWRITES,
		mops::create_GEB,
		mops::create_GEI,
		mops::create_GER,
		mops::create_GES,
		mops::create_GSTKOFFS,
		mops::create_GTB,
		mops::create_GTI,
		mops::create_GTR,
		mops::create_GTS,
		mops::create_HALT,
		mops::create_INCC,
		mops::create_INCP,
		mops::create_INITB,
		mops::create_INITI,
		mops::create_INITR,
		mops::create_INITS,
		mops::create_LDLITB,
		mops::create_LDLITI,
		mops::create_LDLITR,
		mops::create_LDLITS,
		mops::create_LEB,
		mops::create_LEI,
		mops::create_LER,
		mops::create_LES,
		mops::create_LTB,
		mops::create_LTI,
		mops::create_LTR,
		mops::create_LTS,
		mops::create_MERGERA,
		mops::create_MINUSI,
		mops::create_MINUSR,
		mops::create_MODI,
		mops::create_MULI,
		mops::create_MULR,
		mops::create_NEB,
		mops::create_NEI,
		mops::create_NER,
		mops::create_NES,
		mops::create_NOT,
		mops::create_OR,
		mops::create_RDFP,
		mops::create_RDIN1,
		mops::create_RDIN1B,
		mops::create_RDIN1I,
		mops::create_RDIN1P,
		mops::create_RDIN1R,
		mops::create_RDIN1S,
		mops::create_RDIN2B,
		mops::create_RDIN2I,
		mops::create_RDIN2P,
		mops::create_RDIN2R,
		mops::create_RDIN2S,
		mops::create_RDIN3P,
		mops::create_RDIN4P,
		mops::create_RDIP,
		mops::create_RDMEM,
		mops::create_RDMEMB,
		mops::create_RDMEMF,
		mops::create_RDMEMI,
		mops::create_RDMEMP,
		mops::create_RDMEMR,
		mops::create_RDMEMS,
		mops::create_RDSP,
		mops::create_SUBI,
		mops::create_SUBP,
		mops::create_SUBR,
		mops::create_WRFP,
		mops::create_WRIP,
		mops::create_WRMEM,
		mops::create_WRMEMB,
		mops::create_WRMEMF,
		mops::create_WRMEMI,
		mops::create_WRMEMP,
		mops::create_WRMEMR,
		mops::create_WRMEMS,
		mops::create_WROUT,
		mops::create_WROUTB,
		mops::create_WROUTI,
		mops::create_WROUTP,
		mops::create_WROUTR,
		mops::create_WROUTS,
		mops::create_WRSP,
	};

	mop_info_t mop_info[] = {
		{ mops::UT_EXEC, false, false},	// ABSNUMC
		{ mops::UT_EXEC, false, false},	// ADDI
		{ mops::UT_EXEC, false, false},	// ADDLSTKOFFS
		{ mops::UT_EXEC, false, false},	// ADDP
		{ mops::UT_EXEC, false, false},	// ADDR
		{ mops::UT_EXEC, false, false},	// ADDRELNUMC
		{ mops::UT_EXEC, false, false},	// ADDRELNUMIFFC
		{ mops::UT_EXEC, false, false},	// ADDRELNUMIFTC
		{ mops::UT_EXEC, false, false},	// ADDS
		{ mops::UT_EXEC, false, false},	// ADDSSTKOFFS
		{ mops::UT_EXEC, false, false},	// AND
		{ mops::UT_EXEC, false, false},	// BEI
		{ mops::UT_EXEC, false, false},	// CVRTIR
		{ mops::UT_EXEC, false, false},	// CVRTRI
		{ mops::UT_EXEC, false, false},	// DEC2P
		{ mops::UT_EXEC, false, false},	// DECP
		{ mops::UT_EXEC, false, false},	// DIVI
		{ mops::UT_EXEC, false, false},	// DIVR
		{ mops::UT_EXEC, false, false},	// EQB
		{ mops::UT_EXEC, false, false},	// EQI
		{ mops::UT_EXEC, false, false},	// EQR
		{ mops::UT_EXEC, false, false},	// EQS
		{ mops::UT_EXEC, false, false},	// EXTRACTFP
		{ mops::UT_EXEC, false, false},	// EXTRACTIP
		{ mops::UT_FETCH, false, false},	// FETCH
		{ mops::UT_EXTERNAL, false, false},	// FNCREADI
		{ mops::UT_EXTERNAL, false, false},	// FNCREADR
		{ mops::UT_EXTERNAL, false, false},	// FNCREADS
		{ mops::UT_EXTERNAL, false, false},	// FNCWRITEI
		{ mops::UT_EXTERNAL, false, false},	// FNCWRITELN
		{ mops::UT_EXTERNAL, false, false},	// FNCWRITER
		{ mops::UT_EXTERNAL, false, false},	// FNCWRITES
		{ mops::UT_EXEC, false, false},	// GEB
		{ mops::UT_EXEC, false, false},	// GEI
		{ mops::UT_EXEC, false, false},	// GER
		{ mops::UT_EXEC, false, false},	// GES
		{ mops::UT_EXEC, false, false},	// GSTKOFFS
		{ mops::UT_EXEC, false, false},	// GTB
		{ mops::UT_EXEC, false, false},	// GTI
		{ mops::UT_EXEC, false, false},	// GTR
		{ mops::UT_EXEC, false, false},	// GTS
		{ mops::UT_HALT, false, false},	// HALT
		{ mops::UT_EXEC, false, false},	// INCC
		{ mops::UT_EXEC, false, false},	// INCP
		{ mops::UT_EXEC, false, false},	// INITB
		{ mops::UT_EXEC, false, false},	// INITI
		{ mops::UT_EXEC, false, false},	// INITR
		{ mops::UT_EXEC, false, false},	// INITS
		{ mops::UT_EXEC, false, false},	// LDLITB
		{ mops::UT_EXEC, false, false},	// LDLITI
		{ mops::UT_EXEC, false, false},	// LDLITR
		{ mops::UT_EXEC, false, false},	// LDLITS
		{ mops::UT_EXEC, false, false},	// LEB
		{ mops::UT_EXEC, false, false},	// LEI
		{ mops::UT_EXEC, false, false},	// LER
		{ mops::UT_EXEC, false, false},	// LES
		{ mops::UT_EXEC, false, false},	// LTB
		{ mops::UT_EXEC, false, false},	// LTI
		{ mops::UT_EXEC, false, false},	// LTR
		{ mops::UT_EXEC, false, false},	// LTS
		{ mops::UT_EXEC, false, false},	// MERGERA
		{ mops::UT_EXEC, false, false},	// MINUSI
		{ mops::UT_EXEC, false, false},	// MINUSR
		{ mops::UT_EXEC, false, false},	// MODI
		{ mops::UT_EXEC, false, false},	// MULI
		{ mops::UT_EXEC, false, false},	// MULR
		{ mops::UT_EXEC, false, false},	// NEB
		{ mops::UT_EXEC, false, false},	// NEI
		{ mops::UT_EXEC, false, false},	// NER
		{ mops::UT_EXEC, false, false},	// NES
		{ mops::UT_EXEC, false, false},	// NOT
		{ mops::UT_EXEC, false, false},	// OR
		{ mops::UT_FPREG, true, false},	// RDFP
		{ mops::UT_REG, true, false},	// RDIN1
		{ mops::UT_REG, true, false},	// RDIN1B
		{ mops::UT_REG, true, false},	// RDIN1I
		{ mops::UT_REG, true, false},	// RDIN1P
		{ mops::UT_REG, true, false},	// RDIN1R
		{ mops::UT_REG, true, false},	// RDIN1S
		{ mops::UT_REG, true, false},	// RDIN2B
		{ mops::UT_REG, true, false},	// RDIN2I
		{ mops::UT_REG, true, false},	// RDIN2P
		{ mops::UT_REG, true, false},	// RDIN2R
		{ mops::UT_REG, true, false},	// RDIN2S
		{ mops::UT_REG, true, false},	// RDIN3P
		{ mops::UT_REG, true, false},	// RDIN4P
		{ mops::UT_IPREG, true, false},	// RDIP
		{ mops::UT_MEM, true, false},	// RDMEM
		{ mops::UT_MEM, true, false},	// RDMEMB
		{ mops::UT_MEM, true, false},	// RDMEMF
		{ mops::UT_MEM, true, false},	// RDMEMI
		{ mops::UT_MEM, true, false},	// RDMEMP
		{ mops::UT_MEM, true, false},	// RDMEMR
		{ mops::UT_MEM, true, false},	// RDMEMS
		{ mops::UT_SPREG, true, false},	// RDSP
		{ mops::UT_EXEC, false, false},	// SUBI
		{ mops::UT_EXEC, false, false},	// SUBP
		{ mops::UT_EXEC, false, false},	// SUBR
		{ mops::UT_FPREG, false, true},	// WRFP
		{ mops::UT_IPREG, false, true},	// WRIP
		{ mops::UT_MEM, false, true},	// WRMEM
		{ mops::UT_MEM, false, true},	// WRMEMB
		{ mops::UT_MEM, false, true},	// WRMEMF
		{ mops::UT_MEM, false, true},	// WRMEMI
		{ mops::UT_MEM, false, true},	// WRMEMP
		{ mops::UT_MEM, false, true},	// WRMEMR
		{ mops::UT_MEM, false, true},	// WRMEMS
		{ mops::UT_REG, false, true},	// WROUT
		{ mops::UT_REG, false, true},	// WROUTB
		{ mops::UT_REG, false, true},	// WROUTI
		{ mops::UT_REG, false, true},	// WROUTP
		{ mops::UT_REG, false, true},	// WROUTR
		{ mops::UT_REG, false, true},	// WROUTS
		{ mops::UT_SPREG, false, true},	// WRSP
	};

} // namespace mlaskal
