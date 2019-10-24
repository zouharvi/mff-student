/*
	GEN_MACHINES.CPP

	GENERATED, DO NOT MODIFY!!!!
*/

#include <iostream>

#include "icm_machine.hpp"

using namespace std;
using namespace mlaskal;

namespace {

	icm_machines_::unit_map unit_map_FAST_FETCH[] = {
		{ mops::MOPC_FETCH, 0 },
	};

	icm_machines_::unit unit_FAST_FETCH = {
		"FAST_FETCH",
		mops::UT_FETCH,
		carray<icm_machines_::unit_map>(unit_map_FAST_FETCH)
	};

	icm_machines_::unit_map unit_map_NORMAL_FETCH[] = {
		{ mops::MOPC_FETCH, 1 },
	};

	icm_machines_::unit unit_NORMAL_FETCH = {
		"NORMAL_FETCH",
		mops::UT_FETCH,
		carray<icm_machines_::unit_map>(unit_map_NORMAL_FETCH)
	};

	icm_machines_::unit_map unit_map_HALT[] = {
		{ mops::MOPC_HALT, 1 },
	};

	icm_machines_::unit unit_HALT = {
		"HALT",
		mops::UT_HALT,
		carray<icm_machines_::unit_map>(unit_map_HALT)
	};

	icm_machines_::unit_map unit_map_EXTERNAL[] = {
		{ mops::MOPC_FNCREADI, 1 },
		{ mops::MOPC_FNCREADR, 1 },
		{ mops::MOPC_FNCREADS, 1 },
		{ mops::MOPC_FNCWRITEI, 1 },
		{ mops::MOPC_FNCWRITELN, 1 },
		{ mops::MOPC_FNCWRITER, 1 },
		{ mops::MOPC_FNCWRITES, 1 },
	};

	icm_machines_::unit unit_EXTERNAL = {
		"EXTERNAL",
		mops::UT_EXTERNAL,
		carray<icm_machines_::unit_map>(unit_map_EXTERNAL)
	};

	icm_machines_::unit_map unit_map_MEM[] = {
		{ mops::MOPC_RDMEM, 4 },
		{ mops::MOPC_RDMEMB, 4 },
		{ mops::MOPC_RDMEMF, 4 },
		{ mops::MOPC_RDMEMI, 4 },
		{ mops::MOPC_RDMEMP, 4 },
		{ mops::MOPC_RDMEMR, 4 },
		{ mops::MOPC_RDMEMS, 4 },
		{ mops::MOPC_WRMEM, 4 },
		{ mops::MOPC_WRMEMB, 4 },
		{ mops::MOPC_WRMEMF, 4 },
		{ mops::MOPC_WRMEMI, 4 },
		{ mops::MOPC_WRMEMP, 4 },
		{ mops::MOPC_WRMEMR, 4 },
		{ mops::MOPC_WRMEMS, 4 },
	};

	icm_machines_::unit unit_MEM = {
		"MEM",
		mops::UT_MEM,
		carray<icm_machines_::unit_map>(unit_map_MEM)
	};

	icm_machines_::unit_map unit_map_REG[] = {
		{ mops::MOPC_RDIN1, 1 },
		{ mops::MOPC_RDIN1B, 1 },
		{ mops::MOPC_RDIN1I, 1 },
		{ mops::MOPC_RDIN1P, 1 },
		{ mops::MOPC_RDIN1R, 1 },
		{ mops::MOPC_RDIN1S, 1 },
		{ mops::MOPC_RDIN2B, 1 },
		{ mops::MOPC_RDIN2I, 1 },
		{ mops::MOPC_RDIN2P, 1 },
		{ mops::MOPC_RDIN2R, 1 },
		{ mops::MOPC_RDIN2S, 1 },
		{ mops::MOPC_RDIN3P, 1 },
		{ mops::MOPC_RDIN4P, 1 },
		{ mops::MOPC_WROUT, 1 },
		{ mops::MOPC_WROUTB, 1 },
		{ mops::MOPC_WROUTI, 1 },
		{ mops::MOPC_WROUTP, 1 },
		{ mops::MOPC_WROUTR, 1 },
		{ mops::MOPC_WROUTS, 1 },
	};

	icm_machines_::unit unit_REG = {
		"REG",
		mops::UT_REG,
		carray<icm_machines_::unit_map>(unit_map_REG)
	};

	icm_machines_::unit_map unit_map_FAST_ADR[] = {
		{ mops::MOPC_ABSNUMC, 0 },
		{ mops::MOPC_ADDLSTKOFFS, 0 },
		{ mops::MOPC_ADDP, 1 },
		{ mops::MOPC_ADDRELNUMC, 0 },
		{ mops::MOPC_ADDSSTKOFFS, 0 },
		{ mops::MOPC_DECP, 0 },
		{ mops::MOPC_GSTKOFFS, 0 },
		{ mops::MOPC_INCC, 0 },
		{ mops::MOPC_INCP, 0 },
		{ mops::MOPC_SUBP, 1 },
	};

	icm_machines_::unit unit_FAST_ADR = {
		"FAST_ADR",
		mops::UT_EXEC,
		carray<icm_machines_::unit_map>(unit_map_FAST_ADR)
	};

	icm_machines_::unit_map unit_map_NORMAL_ADR[] = {
		{ mops::MOPC_ABSNUMC, 1 },
		{ mops::MOPC_ADDLSTKOFFS, 1 },
		{ mops::MOPC_ADDP, 1 },
		{ mops::MOPC_ADDRELNUMC, 1 },
		{ mops::MOPC_ADDSSTKOFFS, 1 },
		{ mops::MOPC_DECP, 1 },
		{ mops::MOPC_GSTKOFFS, 1 },
		{ mops::MOPC_INCC, 1 },
		{ mops::MOPC_INCP, 1 },
		{ mops::MOPC_SUBP, 1 },
	};

	icm_machines_::unit unit_NORMAL_ADR = {
		"NORMAL_ADR",
		mops::UT_EXEC,
		carray<icm_machines_::unit_map>(unit_map_NORMAL_ADR)
	};

	icm_machines_::unit_map unit_map_FAST_IP[] = {
		{ mops::MOPC_RDIP, 0 },
		{ mops::MOPC_WRIP, 0 },
	};

	icm_machines_::unit unit_FAST_IP = {
		"FAST_IP",
		mops::UT_IPREG,
		carray<icm_machines_::unit_map>(unit_map_FAST_IP)
	};

	icm_machines_::unit_map unit_map_NORMAL_IP[] = {
		{ mops::MOPC_RDIP, 1 },
		{ mops::MOPC_WRIP, 1 },
	};

	icm_machines_::unit unit_NORMAL_IP = {
		"NORMAL_IP",
		mops::UT_IPREG,
		carray<icm_machines_::unit_map>(unit_map_NORMAL_IP)
	};

	icm_machines_::unit_map unit_map_FAST_FP[] = {
		{ mops::MOPC_RDFP, 0 },
		{ mops::MOPC_WRFP, 0 },
	};

	icm_machines_::unit unit_FAST_FP = {
		"FAST_FP",
		mops::UT_FPREG,
		carray<icm_machines_::unit_map>(unit_map_FAST_FP)
	};

	icm_machines_::unit_map unit_map_NORMAL_FP[] = {
		{ mops::MOPC_RDFP, 1 },
		{ mops::MOPC_WRFP, 1 },
	};

	icm_machines_::unit unit_NORMAL_FP = {
		"NORMAL_FP",
		mops::UT_FPREG,
		carray<icm_machines_::unit_map>(unit_map_NORMAL_FP)
	};

	icm_machines_::unit_map unit_map_FAST_SP[] = {
		{ mops::MOPC_RDSP, 0 },
		{ mops::MOPC_WRSP, 0 },
	};

	icm_machines_::unit unit_FAST_SP = {
		"FAST_SP",
		mops::UT_SPREG,
		carray<icm_machines_::unit_map>(unit_map_FAST_SP)
	};

	icm_machines_::unit_map unit_map_NORMAL_SP[] = {
		{ mops::MOPC_RDSP, 1 },
		{ mops::MOPC_WRSP, 1 },
	};

	icm_machines_::unit unit_NORMAL_SP = {
		"NORMAL_SP",
		mops::UT_SPREG,
		carray<icm_machines_::unit_map>(unit_map_NORMAL_SP)
	};

	icm_machines_::unit_map unit_map_ALMIGHTY[] = {
		{ mops::MOPC_ADDI, 1 },
		{ mops::MOPC_ADDR, 1 },
		{ mops::MOPC_ADDRELNUMIFFC, 1 },
		{ mops::MOPC_ADDRELNUMIFTC, 1 },
		{ mops::MOPC_ADDS, 1 },
		{ mops::MOPC_AND, 1 },
		{ mops::MOPC_BEI, 1 },
		{ mops::MOPC_CVRTIR, 1 },
		{ mops::MOPC_CVRTRI, 1 },
		{ mops::MOPC_DEC2P, 1 },
		{ mops::MOPC_DIVI, 1 },
		{ mops::MOPC_DIVR, 1 },
		{ mops::MOPC_EQB, 1 },
		{ mops::MOPC_EQI, 1 },
		{ mops::MOPC_EQR, 1 },
		{ mops::MOPC_EQS, 1 },
		{ mops::MOPC_EXTRACTFP, 1 },
		{ mops::MOPC_EXTRACTIP, 1 },
		{ mops::MOPC_GEB, 1 },
		{ mops::MOPC_GEI, 1 },
		{ mops::MOPC_GER, 1 },
		{ mops::MOPC_GES, 1 },
		{ mops::MOPC_GTB, 1 },
		{ mops::MOPC_GTI, 1 },
		{ mops::MOPC_GTR, 1 },
		{ mops::MOPC_GTS, 1 },
		{ mops::MOPC_INITB, 1 },
		{ mops::MOPC_INITI, 1 },
		{ mops::MOPC_INITR, 1 },
		{ mops::MOPC_INITS, 1 },
		{ mops::MOPC_LDLITB, 1 },
		{ mops::MOPC_LDLITI, 1 },
		{ mops::MOPC_LDLITR, 1 },
		{ mops::MOPC_LDLITS, 1 },
		{ mops::MOPC_LEB, 1 },
		{ mops::MOPC_LEI, 1 },
		{ mops::MOPC_LER, 1 },
		{ mops::MOPC_LES, 1 },
		{ mops::MOPC_LTB, 1 },
		{ mops::MOPC_LTI, 1 },
		{ mops::MOPC_LTR, 1 },
		{ mops::MOPC_LTS, 1 },
		{ mops::MOPC_MERGERA, 1 },
		{ mops::MOPC_MINUSI, 1 },
		{ mops::MOPC_MINUSR, 1 },
		{ mops::MOPC_MODI, 1 },
		{ mops::MOPC_MULI, 1 },
		{ mops::MOPC_MULR, 1 },
		{ mops::MOPC_NEB, 1 },
		{ mops::MOPC_NEI, 1 },
		{ mops::MOPC_NER, 1 },
		{ mops::MOPC_NES, 1 },
		{ mops::MOPC_NOT, 1 },
		{ mops::MOPC_OR, 1 },
		{ mops::MOPC_SUBI, 1 },
		{ mops::MOPC_SUBR, 1 },
	};

	icm_machines_::unit unit_ALMIGHTY = {
		"ALMIGHTY",
		mops::UT_EXEC,
		carray<icm_machines_::unit_map>(unit_map_ALMIGHTY)
	};

	ai::IC_OPCODE alin_stack_int_[] = {
		ai::ICOP_LDLITB,
		ai::ICOP_LDLITI,
		ai::ICOP_LDLITR,
		ai::ICOP_LDLITS,
		ai::ICOP_INITB,
		ai::ICOP_INITI,
		ai::ICOP_INITR,
		ai::ICOP_INITS,
		ai::ICOP_DTORB,
		ai::ICOP_DTORI,
		ai::ICOP_DTORP,
		ai::ICOP_DTORR,
		ai::ICOP_DTORS,
		ai::ICOP_GLDB,
		ai::ICOP_GLDI,
		ai::ICOP_GLDR,
		ai::ICOP_GLDS,
		ai::ICOP_GSTB,
		ai::ICOP_GSTI,
		ai::ICOP_GSTR,
		ai::ICOP_GSTS,
		ai::ICOP_LLDB,
		ai::ICOP_LLDI,
		ai::ICOP_LLDP,
		ai::ICOP_LLDR,
		ai::ICOP_LLDS,
		ai::ICOP_LSTB,
		ai::ICOP_LSTI,
		ai::ICOP_LSTR,
		ai::ICOP_LSTS,
		ai::ICOP_XLDB,
		ai::ICOP_XLDI,
		ai::ICOP_XLDR,
		ai::ICOP_XLDS,
		ai::ICOP_XSTB,
		ai::ICOP_XSTI,
		ai::ICOP_XSTR,
		ai::ICOP_XSTS,
		ai::ICOP_SLDB,
		ai::ICOP_SLDI,
		ai::ICOP_SLDP,
		ai::ICOP_SLDR,
		ai::ICOP_SLDS,
		ai::ICOP_SSTB,
		ai::ICOP_SSTI,
		ai::ICOP_SSTP,
		ai::ICOP_SSTR,
		ai::ICOP_SSTS,
		ai::ICOP_GREF,
		ai::ICOP_LREF,
		ai::ICOP_SREF,
		ai::ICOP_CALL,
		ai::ICOP_HALT,
		ai::ICOP_JMP,
		ai::ICOP_RET,
		ai::ICOP_JF,
		ai::ICOP_JT,
		ai::ICOP_AND,
		ai::ICOP_OR,
		ai::ICOP_ADDI,
		ai::ICOP_ADDP,
		ai::ICOP_DIVI,
		ai::ICOP_MODI,
		ai::ICOP_MULI,
		ai::ICOP_SUBI,
		ai::ICOP_SUBP,
		ai::ICOP_ADDR,
		ai::ICOP_DIVR,
		ai::ICOP_MULR,
		ai::ICOP_SUBR,
		ai::ICOP_ADDS,
		ai::ICOP_EQS,
		ai::ICOP_GES,
		ai::ICOP_GTS,
		ai::ICOP_LES,
		ai::ICOP_LTS,
		ai::ICOP_NES,
		ai::ICOP_CVRTIR,
		ai::ICOP_CVRTRI,
		ai::ICOP_MINUSI,
		ai::ICOP_MINUSR,
		ai::ICOP_NOT,
		ai::ICOP_EQB,
		ai::ICOP_GEB,
		ai::ICOP_GTB,
		ai::ICOP_LEB,
		ai::ICOP_LTB,
		ai::ICOP_NEB,
		ai::ICOP_EQI,
		ai::ICOP_GEI,
		ai::ICOP_GTI,
		ai::ICOP_LEI,
		ai::ICOP_LTI,
		ai::ICOP_NEI,
		ai::ICOP_EQR,
		ai::ICOP_GER,
		ai::ICOP_GTR,
		ai::ICOP_LER,
		ai::ICOP_LTR,
		ai::ICOP_NER,
		ai::ICOP_FNCREADI,
		ai::ICOP_FNCREADR,
		ai::ICOP_FNCREADS,
		ai::ICOP_FNCWRITEI,
		ai::ICOP_FNCWRITELN,
		ai::ICOP_FNCWRITER,
		ai::ICOP_FNCWRITES,
		ai::ICOP_NOP,
		ai::ICOP_SADD,
	};

	const carray<ai::IC_OPCODE> alin_stack(alin_stack_int_);

	class machine_stack : public icm_machine {
	public:
		explicit machine_stack(const icm_machines_::machine *m, ICABSNUM regs, const icm_flat_icblock *inic, ostream *os, const icm_machine_trace_options &to) : icm_machine(m, regs, inic, os, to) { }
	};

	ai::IC_OPCODE alin_regall_int_[] = {
		ai::ICOP_ELDLITB,
		ai::ICOP_ELDLITI,
		ai::ICOP_ELDLITR,
		ai::ICOP_ELDLITS,
		ai::ICOP_INITB,
		ai::ICOP_INITI,
		ai::ICOP_INITR,
		ai::ICOP_INITS,
		ai::ICOP_DTORB,
		ai::ICOP_DTORI,
		ai::ICOP_DTORP,
		ai::ICOP_DTORR,
		ai::ICOP_DTORS,
		ai::ICOP_EINITB,
		ai::ICOP_EINITI,
		ai::ICOP_EINITR,
		ai::ICOP_EINITS,
		ai::ICOP_EMOVB,
		ai::ICOP_EMOVI,
		ai::ICOP_EMOVP,
		ai::ICOP_EMOVR,
		ai::ICOP_EMOVS,
		ai::ICOP_GELDB,
		ai::ICOP_GELDI,
		ai::ICOP_GELDR,
		ai::ICOP_GELDS,
		ai::ICOP_GESTB,
		ai::ICOP_GESTI,
		ai::ICOP_GESTR,
		ai::ICOP_GESTS,
		ai::ICOP_LELDB,
		ai::ICOP_LELDI,
		ai::ICOP_LELDP,
		ai::ICOP_LELDR,
		ai::ICOP_LELDS,
		ai::ICOP_LESTB,
		ai::ICOP_LESTI,
		ai::ICOP_LESTP,
		ai::ICOP_LESTR,
		ai::ICOP_LESTS,
		ai::ICOP_XELDB,
		ai::ICOP_XELDI,
		ai::ICOP_XELDR,
		ai::ICOP_XELDS,
		ai::ICOP_XESTB,
		ai::ICOP_XESTI,
		ai::ICOP_XESTR,
		ai::ICOP_XESTS,
		ai::ICOP_GEREF,
		ai::ICOP_LEREF,
		ai::ICOP_CALL,
		ai::ICOP_HALT,
		ai::ICOP_JMP,
		ai::ICOP_RET,
		ai::ICOP_JEF,
		ai::ICOP_JET,
		ai::ICOP_EAND,
		ai::ICOP_EOR,
		ai::ICOP_EADDI,
		ai::ICOP_EADDP,
		ai::ICOP_EDIVI,
		ai::ICOP_EMODI,
		ai::ICOP_EMULI,
		ai::ICOP_ESUBI,
		ai::ICOP_ESUBP,
		ai::ICOP_EADDR,
		ai::ICOP_EDIVR,
		ai::ICOP_EMULR,
		ai::ICOP_ESUBR,
		ai::ICOP_EADDS,
		ai::ICOP_EEQS,
		ai::ICOP_EGES,
		ai::ICOP_EGTS,
		ai::ICOP_ELES,
		ai::ICOP_ELTS,
		ai::ICOP_ENES,
		ai::ICOP_ECVRTIR,
		ai::ICOP_ECVRTRI,
		ai::ICOP_EMINUSI,
		ai::ICOP_EMINUSR,
		ai::ICOP_ENOT,
		ai::ICOP_EEQB,
		ai::ICOP_EGEB,
		ai::ICOP_EGTB,
		ai::ICOP_ELEB,
		ai::ICOP_ELTB,
		ai::ICOP_ENEB,
		ai::ICOP_EEQI,
		ai::ICOP_EGEI,
		ai::ICOP_EGTI,
		ai::ICOP_ELEI,
		ai::ICOP_ELTI,
		ai::ICOP_ENEI,
		ai::ICOP_EEQR,
		ai::ICOP_EGER,
		ai::ICOP_EGTR,
		ai::ICOP_ELER,
		ai::ICOP_ELTR,
		ai::ICOP_ENER,
		ai::ICOP_FNCREADI,
		ai::ICOP_FNCREADR,
		ai::ICOP_FNCREADS,
		ai::ICOP_FNCWRITEI,
		ai::ICOP_FNCWRITELN,
		ai::ICOP_FNCWRITER,
		ai::ICOP_FNCWRITES,
		ai::ICOP_NOP,
		ai::ICOP_SADD,
		ai::ICOP_EPUSH,
		ai::ICOP_EPUSHB,
		ai::ICOP_EPUSHI,
		ai::ICOP_EPUSHP,
		ai::ICOP_EPUSHR,
		ai::ICOP_EPUSHS,
		ai::ICOP_EPOP,
		ai::ICOP_EPOPB,
		ai::ICOP_EPOPI,
		ai::ICOP_EPOPP,
		ai::ICOP_EPOPR,
		ai::ICOP_EPOPS,
	};

	const carray<ai::IC_OPCODE> alin_regall(alin_regall_int_);

	class machine_regall : public icm_machine {
	public:
		explicit machine_regall(const icm_machines_::machine *m, ICABSNUM regs, const icm_flat_icblock *inic, ostream *os, const icm_machine_trace_options &to) : icm_machine(m, regs, inic, os, to) { }
	};

	ai::IC_OPCODE alin_regmem2_int_[] = {
		ai::ICOP_ELDLITB,
		ai::ICOP_ELDLITI,
		ai::ICOP_ELDLITR,
		ai::ICOP_ELDLITS,
		ai::ICOP_INITB,
		ai::ICOP_INITI,
		ai::ICOP_INITR,
		ai::ICOP_INITS,
		ai::ICOP_DTORB,
		ai::ICOP_DTORI,
		ai::ICOP_DTORP,
		ai::ICOP_DTORR,
		ai::ICOP_DTORS,
		ai::ICOP_EINITB,
		ai::ICOP_EINITI,
		ai::ICOP_EINITR,
		ai::ICOP_EINITS,
		ai::ICOP_EMOVB,
		ai::ICOP_EMOVI,
		ai::ICOP_EMOVP,
		ai::ICOP_EMOVR,
		ai::ICOP_EMOVS,
		ai::ICOP_GELDB,
		ai::ICOP_GELDI,
		ai::ICOP_GELDR,
		ai::ICOP_GELDS,
		ai::ICOP_GESTB,
		ai::ICOP_GESTI,
		ai::ICOP_GESTR,
		ai::ICOP_GESTS,
		ai::ICOP_LELDB,
		ai::ICOP_LELDI,
		ai::ICOP_LELDP,
		ai::ICOP_LELDR,
		ai::ICOP_LELDS,
		ai::ICOP_LESTB,
		ai::ICOP_LESTI,
		ai::ICOP_LESTP,
		ai::ICOP_LESTR,
		ai::ICOP_LESTS,
		ai::ICOP_XELDB,
		ai::ICOP_XELDI,
		ai::ICOP_XELDR,
		ai::ICOP_XELDS,
		ai::ICOP_XESTB,
		ai::ICOP_XESTI,
		ai::ICOP_XESTR,
		ai::ICOP_XESTS,
		ai::ICOP_GEREF,
		ai::ICOP_LEREF,
		ai::ICOP_CALL,
		ai::ICOP_HALT,
		ai::ICOP_JMP,
		ai::ICOP_RET,
		ai::ICOP_JEF,
		ai::ICOP_JET,
		ai::ICOP_EAND,
		ai::ICOP_EOR,
		ai::ICOP_EADDI,
		ai::ICOP_EADDP,
		ai::ICOP_EDIVI,
		ai::ICOP_EMODI,
		ai::ICOP_EMULI,
		ai::ICOP_ESUBI,
		ai::ICOP_ESUBP,
		ai::ICOP_EADDR,
		ai::ICOP_EDIVR,
		ai::ICOP_EMULR,
		ai::ICOP_ESUBR,
		ai::ICOP_EADDS,
		ai::ICOP_EEQS,
		ai::ICOP_EGES,
		ai::ICOP_EGTS,
		ai::ICOP_ELES,
		ai::ICOP_ELTS,
		ai::ICOP_ENES,
		ai::ICOP_ECVRTIR,
		ai::ICOP_ECVRTRI,
		ai::ICOP_EMINUSI,
		ai::ICOP_EMINUSR,
		ai::ICOP_ENOT,
		ai::ICOP_EEQB,
		ai::ICOP_EGEB,
		ai::ICOP_EGTB,
		ai::ICOP_ELEB,
		ai::ICOP_ELTB,
		ai::ICOP_ENEB,
		ai::ICOP_EEQI,
		ai::ICOP_EGEI,
		ai::ICOP_EGTI,
		ai::ICOP_ELEI,
		ai::ICOP_ELTI,
		ai::ICOP_ENEI,
		ai::ICOP_EEQR,
		ai::ICOP_EGER,
		ai::ICOP_EGTR,
		ai::ICOP_ELER,
		ai::ICOP_ELTR,
		ai::ICOP_ENER,
		ai::ICOP_FNCREADI,
		ai::ICOP_FNCREADR,
		ai::ICOP_FNCREADS,
		ai::ICOP_FNCWRITEI,
		ai::ICOP_FNCWRITELN,
		ai::ICOP_FNCWRITER,
		ai::ICOP_FNCWRITES,
		ai::ICOP_NOP,
		ai::ICOP_SADD,
		ai::ICOP_EPUSH,
		ai::ICOP_EPUSHB,
		ai::ICOP_EPUSHI,
		ai::ICOP_EPUSHP,
		ai::ICOP_EPUSHR,
		ai::ICOP_EPUSHS,
		ai::ICOP_EPOP,
		ai::ICOP_EPOPB,
		ai::ICOP_EPOPI,
		ai::ICOP_EPOPP,
		ai::ICOP_EPOPR,
		ai::ICOP_EPOPS,
	};

	const carray<ai::IC_OPCODE> alin_regmem2(alin_regmem2_int_);

	class machine_regmem2 : public icm_machine {
	public:
		explicit machine_regmem2(const icm_machines_::machine *m, ICABSNUM regs, const icm_flat_icblock *inic, ostream *os, const icm_machine_trace_options &to) : icm_machine(m, regs, inic, os, to) { }
	};

	ai::IC_OPCODE alin_fast_stack_int_[] = {
		ai::ICOP_LDLITB,
		ai::ICOP_LDLITI,
		ai::ICOP_LDLITR,
		ai::ICOP_LDLITS,
		ai::ICOP_INITB,
		ai::ICOP_INITI,
		ai::ICOP_INITR,
		ai::ICOP_INITS,
		ai::ICOP_DTORB,
		ai::ICOP_DTORI,
		ai::ICOP_DTORP,
		ai::ICOP_DTORR,
		ai::ICOP_DTORS,
		ai::ICOP_GLDB,
		ai::ICOP_GLDI,
		ai::ICOP_GLDR,
		ai::ICOP_GLDS,
		ai::ICOP_GSTB,
		ai::ICOP_GSTI,
		ai::ICOP_GSTR,
		ai::ICOP_GSTS,
		ai::ICOP_LLDB,
		ai::ICOP_LLDI,
		ai::ICOP_LLDP,
		ai::ICOP_LLDR,
		ai::ICOP_LLDS,
		ai::ICOP_LSTB,
		ai::ICOP_LSTI,
		ai::ICOP_LSTR,
		ai::ICOP_LSTS,
		ai::ICOP_XLDB,
		ai::ICOP_XLDI,
		ai::ICOP_XLDR,
		ai::ICOP_XLDS,
		ai::ICOP_XSTB,
		ai::ICOP_XSTI,
		ai::ICOP_XSTR,
		ai::ICOP_XSTS,
		ai::ICOP_SLDB,
		ai::ICOP_SLDI,
		ai::ICOP_SLDP,
		ai::ICOP_SLDR,
		ai::ICOP_SLDS,
		ai::ICOP_SSTB,
		ai::ICOP_SSTI,
		ai::ICOP_SSTP,
		ai::ICOP_SSTR,
		ai::ICOP_SSTS,
		ai::ICOP_GREF,
		ai::ICOP_LREF,
		ai::ICOP_SREF,
		ai::ICOP_CALL,
		ai::ICOP_HALT,
		ai::ICOP_JMP,
		ai::ICOP_RET,
		ai::ICOP_JF,
		ai::ICOP_JT,
		ai::ICOP_AND,
		ai::ICOP_OR,
		ai::ICOP_ADDI,
		ai::ICOP_ADDP,
		ai::ICOP_DIVI,
		ai::ICOP_MODI,
		ai::ICOP_MULI,
		ai::ICOP_SUBI,
		ai::ICOP_SUBP,
		ai::ICOP_ADDR,
		ai::ICOP_DIVR,
		ai::ICOP_MULR,
		ai::ICOP_SUBR,
		ai::ICOP_ADDS,
		ai::ICOP_EQS,
		ai::ICOP_GES,
		ai::ICOP_GTS,
		ai::ICOP_LES,
		ai::ICOP_LTS,
		ai::ICOP_NES,
		ai::ICOP_CVRTIR,
		ai::ICOP_CVRTRI,
		ai::ICOP_MINUSI,
		ai::ICOP_MINUSR,
		ai::ICOP_NOT,
		ai::ICOP_EQB,
		ai::ICOP_GEB,
		ai::ICOP_GTB,
		ai::ICOP_LEB,
		ai::ICOP_LTB,
		ai::ICOP_NEB,
		ai::ICOP_EQI,
		ai::ICOP_GEI,
		ai::ICOP_GTI,
		ai::ICOP_LEI,
		ai::ICOP_LTI,
		ai::ICOP_NEI,
		ai::ICOP_EQR,
		ai::ICOP_GER,
		ai::ICOP_GTR,
		ai::ICOP_LER,
		ai::ICOP_LTR,
		ai::ICOP_NER,
		ai::ICOP_FNCREADI,
		ai::ICOP_FNCREADR,
		ai::ICOP_FNCREADS,
		ai::ICOP_FNCWRITEI,
		ai::ICOP_FNCWRITELN,
		ai::ICOP_FNCWRITER,
		ai::ICOP_FNCWRITES,
		ai::ICOP_NOP,
		ai::ICOP_SADD,
	};

	const carray<ai::IC_OPCODE> alin_fast_stack(alin_fast_stack_int_);

	class machine_fast_stack : public icm_machine {
	public:
		explicit machine_fast_stack(const icm_machines_::machine *m, ICABSNUM regs, const icm_flat_icblock *inic, ostream *os, const icm_machine_trace_options &to) : icm_machine(m, regs, inic, os, to) { }
	};

	ai::IC_OPCODE alin_fast_regall_int_[] = {
		ai::ICOP_ELDLITB,
		ai::ICOP_ELDLITI,
		ai::ICOP_ELDLITR,
		ai::ICOP_ELDLITS,
		ai::ICOP_INITB,
		ai::ICOP_INITI,
		ai::ICOP_INITR,
		ai::ICOP_INITS,
		ai::ICOP_DTORB,
		ai::ICOP_DTORI,
		ai::ICOP_DTORP,
		ai::ICOP_DTORR,
		ai::ICOP_DTORS,
		ai::ICOP_EINITB,
		ai::ICOP_EINITI,
		ai::ICOP_EINITR,
		ai::ICOP_EINITS,
		ai::ICOP_EMOVB,
		ai::ICOP_EMOVI,
		ai::ICOP_EMOVP,
		ai::ICOP_EMOVR,
		ai::ICOP_EMOVS,
		ai::ICOP_GELDB,
		ai::ICOP_GELDI,
		ai::ICOP_GELDR,
		ai::ICOP_GELDS,
		ai::ICOP_GESTB,
		ai::ICOP_GESTI,
		ai::ICOP_GESTR,
		ai::ICOP_GESTS,
		ai::ICOP_LELDB,
		ai::ICOP_LELDI,
		ai::ICOP_LELDP,
		ai::ICOP_LELDR,
		ai::ICOP_LELDS,
		ai::ICOP_LESTB,
		ai::ICOP_LESTI,
		ai::ICOP_LESTP,
		ai::ICOP_LESTR,
		ai::ICOP_LESTS,
		ai::ICOP_XELDB,
		ai::ICOP_XELDI,
		ai::ICOP_XELDR,
		ai::ICOP_XELDS,
		ai::ICOP_XESTB,
		ai::ICOP_XESTI,
		ai::ICOP_XESTR,
		ai::ICOP_XESTS,
		ai::ICOP_GEREF,
		ai::ICOP_LEREF,
		ai::ICOP_CALL,
		ai::ICOP_HALT,
		ai::ICOP_JMP,
		ai::ICOP_RET,
		ai::ICOP_JEF,
		ai::ICOP_JET,
		ai::ICOP_EAND,
		ai::ICOP_EOR,
		ai::ICOP_EADDI,
		ai::ICOP_EADDP,
		ai::ICOP_EDIVI,
		ai::ICOP_EMODI,
		ai::ICOP_EMULI,
		ai::ICOP_ESUBI,
		ai::ICOP_ESUBP,
		ai::ICOP_EADDR,
		ai::ICOP_EDIVR,
		ai::ICOP_EMULR,
		ai::ICOP_ESUBR,
		ai::ICOP_EADDS,
		ai::ICOP_EEQS,
		ai::ICOP_EGES,
		ai::ICOP_EGTS,
		ai::ICOP_ELES,
		ai::ICOP_ELTS,
		ai::ICOP_ENES,
		ai::ICOP_ECVRTIR,
		ai::ICOP_ECVRTRI,
		ai::ICOP_EMINUSI,
		ai::ICOP_EMINUSR,
		ai::ICOP_ENOT,
		ai::ICOP_EEQB,
		ai::ICOP_EGEB,
		ai::ICOP_EGTB,
		ai::ICOP_ELEB,
		ai::ICOP_ELTB,
		ai::ICOP_ENEB,
		ai::ICOP_EEQI,
		ai::ICOP_EGEI,
		ai::ICOP_EGTI,
		ai::ICOP_ELEI,
		ai::ICOP_ELTI,
		ai::ICOP_ENEI,
		ai::ICOP_EEQR,
		ai::ICOP_EGER,
		ai::ICOP_EGTR,
		ai::ICOP_ELER,
		ai::ICOP_ELTR,
		ai::ICOP_ENER,
		ai::ICOP_FNCREADI,
		ai::ICOP_FNCREADR,
		ai::ICOP_FNCREADS,
		ai::ICOP_FNCWRITEI,
		ai::ICOP_FNCWRITELN,
		ai::ICOP_FNCWRITER,
		ai::ICOP_FNCWRITES,
		ai::ICOP_NOP,
		ai::ICOP_SADD,
		ai::ICOP_EPUSH,
		ai::ICOP_EPUSHB,
		ai::ICOP_EPUSHI,
		ai::ICOP_EPUSHP,
		ai::ICOP_EPUSHR,
		ai::ICOP_EPUSHS,
		ai::ICOP_EPOP,
		ai::ICOP_EPOPB,
		ai::ICOP_EPOPI,
		ai::ICOP_EPOPP,
		ai::ICOP_EPOPR,
		ai::ICOP_EPOPS,
	};

	const carray<ai::IC_OPCODE> alin_fast_regall(alin_fast_regall_int_);

	class machine_fast_regall : public icm_machine {
	public:
		explicit machine_fast_regall(const icm_machines_::machine *m, ICABSNUM regs, const icm_flat_icblock *inic, ostream *os, const icm_machine_trace_options &to) : icm_machine(m, regs, inic, os, to) { }
	};

	ai::IC_OPCODE alin_fast_regmem2_int_[] = {
		ai::ICOP_ELDLITB,
		ai::ICOP_ELDLITI,
		ai::ICOP_ELDLITR,
		ai::ICOP_ELDLITS,
		ai::ICOP_INITB,
		ai::ICOP_INITI,
		ai::ICOP_INITR,
		ai::ICOP_INITS,
		ai::ICOP_DTORB,
		ai::ICOP_DTORI,
		ai::ICOP_DTORP,
		ai::ICOP_DTORR,
		ai::ICOP_DTORS,
		ai::ICOP_EINITB,
		ai::ICOP_EINITI,
		ai::ICOP_EINITR,
		ai::ICOP_EINITS,
		ai::ICOP_EMOVB,
		ai::ICOP_EMOVI,
		ai::ICOP_EMOVP,
		ai::ICOP_EMOVR,
		ai::ICOP_EMOVS,
		ai::ICOP_GELDB,
		ai::ICOP_GELDI,
		ai::ICOP_GELDR,
		ai::ICOP_GELDS,
		ai::ICOP_GESTB,
		ai::ICOP_GESTI,
		ai::ICOP_GESTR,
		ai::ICOP_GESTS,
		ai::ICOP_LELDB,
		ai::ICOP_LELDI,
		ai::ICOP_LELDP,
		ai::ICOP_LELDR,
		ai::ICOP_LELDS,
		ai::ICOP_LESTB,
		ai::ICOP_LESTI,
		ai::ICOP_LESTP,
		ai::ICOP_LESTR,
		ai::ICOP_LESTS,
		ai::ICOP_XELDB,
		ai::ICOP_XELDI,
		ai::ICOP_XELDR,
		ai::ICOP_XELDS,
		ai::ICOP_XESTB,
		ai::ICOP_XESTI,
		ai::ICOP_XESTR,
		ai::ICOP_XESTS,
		ai::ICOP_GEREF,
		ai::ICOP_LEREF,
		ai::ICOP_CALL,
		ai::ICOP_HALT,
		ai::ICOP_JMP,
		ai::ICOP_RET,
		ai::ICOP_JEF,
		ai::ICOP_JET,
		ai::ICOP_EAND,
		ai::ICOP_EOR,
		ai::ICOP_EADDI,
		ai::ICOP_EADDP,
		ai::ICOP_EDIVI,
		ai::ICOP_EMODI,
		ai::ICOP_EMULI,
		ai::ICOP_ESUBI,
		ai::ICOP_ESUBP,
		ai::ICOP_EADDR,
		ai::ICOP_EDIVR,
		ai::ICOP_EMULR,
		ai::ICOP_ESUBR,
		ai::ICOP_EADDS,
		ai::ICOP_EEQS,
		ai::ICOP_EGES,
		ai::ICOP_EGTS,
		ai::ICOP_ELES,
		ai::ICOP_ELTS,
		ai::ICOP_ENES,
		ai::ICOP_ECVRTIR,
		ai::ICOP_ECVRTRI,
		ai::ICOP_EMINUSI,
		ai::ICOP_EMINUSR,
		ai::ICOP_ENOT,
		ai::ICOP_EEQB,
		ai::ICOP_EGEB,
		ai::ICOP_EGTB,
		ai::ICOP_ELEB,
		ai::ICOP_ELTB,
		ai::ICOP_ENEB,
		ai::ICOP_EEQI,
		ai::ICOP_EGEI,
		ai::ICOP_EGTI,
		ai::ICOP_ELEI,
		ai::ICOP_ELTI,
		ai::ICOP_ENEI,
		ai::ICOP_EEQR,
		ai::ICOP_EGER,
		ai::ICOP_EGTR,
		ai::ICOP_ELER,
		ai::ICOP_ELTR,
		ai::ICOP_ENER,
		ai::ICOP_FNCREADI,
		ai::ICOP_FNCREADR,
		ai::ICOP_FNCREADS,
		ai::ICOP_FNCWRITEI,
		ai::ICOP_FNCWRITELN,
		ai::ICOP_FNCWRITER,
		ai::ICOP_FNCWRITES,
		ai::ICOP_NOP,
		ai::ICOP_SADD,
		ai::ICOP_EPUSH,
		ai::ICOP_EPUSHB,
		ai::ICOP_EPUSHI,
		ai::ICOP_EPUSHP,
		ai::ICOP_EPUSHR,
		ai::ICOP_EPUSHS,
		ai::ICOP_EPOP,
		ai::ICOP_EPOPB,
		ai::ICOP_EPOPI,
		ai::ICOP_EPOPP,
		ai::ICOP_EPOPR,
		ai::ICOP_EPOPS,
	};

	const carray<ai::IC_OPCODE> alin_fast_regmem2(alin_fast_regmem2_int_);

	class machine_fast_regmem2 : public icm_machine {
	public:
		explicit machine_fast_regmem2(const icm_machines_::machine *m, ICABSNUM regs, const icm_flat_icblock *inic, ostream *os, const icm_machine_trace_options &to) : icm_machine(m, regs, inic, os, to) { }
	};

	icm_machines_::machine_unit units_stack[9] = {
		{ &unit_NORMAL_FETCH, 1 },
		{ &unit_HALT, 1 },
		{ &unit_EXTERNAL, 1 },
		{ &unit_MEM, 1 },
		{ &unit_FAST_ADR, 1 },
		{ &unit_FAST_IP, 1 },
		{ &unit_FAST_SP, 1 },
		{ &unit_FAST_FP, 1 },
		{ &unit_ALMIGHTY, 1 },
	};

	icm_machines_::machine_unit units_regall[10] = {
		{ &unit_NORMAL_FETCH, 1 },
		{ &unit_HALT, 1 },
		{ &unit_EXTERNAL, 1 },
		{ &unit_MEM, 1 },
		{ &unit_REG, 1 },
		{ &unit_FAST_ADR, 1 },
		{ &unit_FAST_IP, 1 },
		{ &unit_FAST_SP, 1 },
		{ &unit_FAST_FP, 1 },
		{ &unit_ALMIGHTY, 1 },
	};

	icm_machines_::machine_unit units_regmem2[10] = {
		{ &unit_NORMAL_FETCH, 1 },
		{ &unit_HALT, 1 },
		{ &unit_EXTERNAL, 1 },
		{ &unit_MEM, 2 },
		{ &unit_REG, 1 },
		{ &unit_FAST_ADR, 1 },
		{ &unit_FAST_IP, 1 },
		{ &unit_FAST_SP, 1 },
		{ &unit_FAST_FP, 1 },
		{ &unit_ALMIGHTY, 1 },
	};

	icm_machines_::machine_unit units_fast_stack[9] = {
		{ &unit_FAST_FETCH, 1 },
		{ &unit_HALT, 1 },
		{ &unit_EXTERNAL, 1 },
		{ &unit_MEM, 1 },
		{ &unit_FAST_ADR, 1 },
		{ &unit_FAST_IP, 1 },
		{ &unit_FAST_SP, 1 },
		{ &unit_FAST_FP, 1 },
		{ &unit_ALMIGHTY, 1 },
	};

	icm_machines_::machine_unit units_fast_regall[10] = {
		{ &unit_FAST_FETCH, 1 },
		{ &unit_HALT, 1 },
		{ &unit_EXTERNAL, 1 },
		{ &unit_MEM, 1 },
		{ &unit_REG, 1 },
		{ &unit_FAST_ADR, 1 },
		{ &unit_FAST_IP, 1 },
		{ &unit_FAST_SP, 1 },
		{ &unit_FAST_FP, 1 },
		{ &unit_ALMIGHTY, 1 },
	};

	icm_machines_::machine_unit units_fast_regmem2[10] = {
		{ &unit_FAST_FETCH, 1 },
		{ &unit_HALT, 1 },
		{ &unit_EXTERNAL, 1 },
		{ &unit_MEM, 2 },
		{ &unit_REG, 1 },
		{ &unit_FAST_ADR, 1 },
		{ &unit_FAST_IP, 1 },
		{ &unit_FAST_SP, 1 },
		{ &unit_FAST_FP, 1 },
		{ &unit_ALMIGHTY, 1 },
	};

	icm_machine *creator_stack(const icm_machines_::machine *m, ICABSNUM regs, const icm_flat_icblock *inic, ostream *os, const icm_machine_trace_options &to) {
		return new machine_stack(m, regs, inic, os, to);
	}

	icm_machine *creator_regall(const icm_machines_::machine *m, ICABSNUM regs, const icm_flat_icblock *inic, ostream *os, const icm_machine_trace_options &to) {
		return new machine_regall(m, regs, inic, os, to);
	}

	icm_machine *creator_regmem2(const icm_machines_::machine *m, ICABSNUM regs, const icm_flat_icblock *inic, ostream *os, const icm_machine_trace_options &to) {
		return new machine_regmem2(m, regs, inic, os, to);
	}

	icm_machine *creator_fast_stack(const icm_machines_::machine *m, ICABSNUM regs, const icm_flat_icblock *inic, ostream *os, const icm_machine_trace_options &to) {
		return new machine_fast_stack(m, regs, inic, os, to);
	}

	icm_machine *creator_fast_regall(const icm_machines_::machine *m, ICABSNUM regs, const icm_flat_icblock *inic, ostream *os, const icm_machine_trace_options &to) {
		return new machine_fast_regall(m, regs, inic, os, to);
	}

	icm_machine *creator_fast_regmem2(const icm_machines_::machine *m, ICABSNUM regs, const icm_flat_icblock *inic, ostream *os, const icm_machine_trace_options &to) {
		return new machine_fast_regmem2(m, regs, inic, os, to);
	}

	icm_machines_::machine machines_int_[6] = {
		{ "stack", carray<icm_machines_::machine_unit>(units_stack), alin_stack, creator_stack },
		{ "regall", carray<icm_machines_::machine_unit>(units_regall), alin_regall, creator_regall },
		{ "regmem2", carray<icm_machines_::machine_unit>(units_regmem2), alin_regmem2, creator_regmem2 },
		{ "fast_stack", carray<icm_machines_::machine_unit>(units_fast_stack), alin_fast_stack, creator_fast_stack },
		{ "fast_regall", carray<icm_machines_::machine_unit>(units_fast_regall), alin_fast_regall, creator_fast_regall },
		{ "fast_regmem2", carray<icm_machines_::machine_unit>(units_fast_regmem2), alin_fast_regmem2, creator_fast_regmem2 },
	};

} // anonymous namespace

namespace mlaskal {

namespace icm_machines_ {

	const carray<icm_machines_::machine> machines(machines_int_);

} // namespace icm_machines_

} // namespace mlaskal
