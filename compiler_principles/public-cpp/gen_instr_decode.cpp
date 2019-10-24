/*
	GEN_INSTR_DECODE.CPP

	GENERATED, DO NOT MODIFY!!!!
*/

#include "icm_machine.hpp"

using namespace mlaskal;

namespace {

	instr_decode_::instr_mop inco_ADDI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMI,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMI,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_ADDI,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMI,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_ADDI(inco_ADDI_int_);

	instr_decode_::instr_mop inco_ADDP_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMI,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMP,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_ADDP,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMP,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_ADDP(inco_ADDP_int_);

	instr_decode_::instr_mop inco_ADDR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMR,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMR,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_ADDR,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMR,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_ADDR(inco_ADDR_int_);

	instr_decode_::instr_mop inco_ADDS_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMS,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMS,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_ADDS,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMS,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_ADDS(inco_ADDS_int_);

	instr_decode_::instr_mop inco_AND_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMB,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMB,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_AND,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_AND(inco_AND_int_);

	instr_decode_::instr_mop inco_CALL_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_RDFP,		"rdfp",		0,		0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"newip",	"rdip",		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_MERGERA,		"mrgrv",	"newip",	"rdfp",		0		 },
		{ mops::MOPC_WRMEMF,		"wrmemf",	"newsp",	"mrgrv",	0		 },
		{ mops::MOPC_WRFP,		"wrfp",		"newsp",	0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_ABSNUMC,		"nextip",	0,		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_CALL(inco_CALL_int_);

	instr_decode_::instr_mop inco_CVRTIR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_RDMEMI,		"op1",		"rdsp",		0,		0		 },
		{ mops::MOPC_CVRTIR,		"res",		"op1",		0,		0		 },
		{ mops::MOPC_WRMEMR,		"wrres",	"rdsp",		"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_CVRTIR(inco_CVRTIR_int_);

	instr_decode_::instr_mop inco_CVRTRI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_RDMEMR,		"op1",		"rdsp",		0,		0		 },
		{ mops::MOPC_CVRTRI,		"res",		"op1",		0,		0		 },
		{ mops::MOPC_WRMEMI,		"wrres",	"rdsp",		"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_CVRTRI(inco_CVRTRI_int_);

	instr_decode_::instr_mop inco_DIVI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMI,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMI,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_DIVI,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMI,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_DIVI(inco_DIVI_int_);

	instr_decode_::instr_mop inco_DIVR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMR,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMR,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_DIVR,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMR,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_DIVR(inco_DIVR_int_);

	instr_decode_::instr_mop inco_DTORB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEM,		"op",		"rdsp",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_DTORB(inco_DTORB_int_);

	instr_decode_::instr_mop inco_DTORI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEM,		"op",		"rdsp",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_DTORI(inco_DTORI_int_);

	instr_decode_::instr_mop inco_DTORP_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEM,		"op",		"rdsp",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_DTORP(inco_DTORP_int_);

	instr_decode_::instr_mop inco_DTORR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEM,		"op",		"rdsp",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_DTORR(inco_DTORR_int_);

	instr_decode_::instr_mop inco_DTORS_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEM,		"op",		"rdsp",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_DTORS(inco_DTORS_int_);

	instr_decode_::instr_mop inco_EADDI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2I,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1I,		"op1",		0,		0,		0		 },
		{ mops::MOPC_ADDI,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTI,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EADDI(inco_EADDI_int_);

	instr_decode_::instr_mop inco_EADDP_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2I,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1P,		"op1",		0,		0,		0		 },
		{ mops::MOPC_ADDP,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTP,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EADDP(inco_EADDP_int_);

	instr_decode_::instr_mop inco_EADDR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2R,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1R,		"op1",		0,		0,		0		 },
		{ mops::MOPC_ADDR,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTR,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EADDR(inco_EADDR_int_);

	instr_decode_::instr_mop inco_EADDS_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2S,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1S,		"op1",		0,		0,		0		 },
		{ mops::MOPC_ADDS,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTS,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EADDS(inco_EADDS_int_);

	instr_decode_::instr_mop inco_EAND_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2B,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1B,		"op1",		0,		0,		0		 },
		{ mops::MOPC_AND,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTB,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EAND(inco_EAND_int_);

	instr_decode_::instr_mop inco_ECVRTIR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN1I,		"op1",		0,		0,		0		 },
		{ mops::MOPC_CVRTIR,		"res",		"op1",		0,		0		 },
		{ mops::MOPC_WROUTR,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_ECVRTIR(inco_ECVRTIR_int_);

	instr_decode_::instr_mop inco_ECVRTRI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN1R,		"op1",		0,		0,		0		 },
		{ mops::MOPC_CVRTRI,		"res",		"op1",		0,		0		 },
		{ mops::MOPC_WROUTI,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_ECVRTRI(inco_ECVRTRI_int_);

	instr_decode_::instr_mop inco_EDIVI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2I,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1I,		"op1",		0,		0,		0		 },
		{ mops::MOPC_DIVI,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTI,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EDIVI(inco_EDIVI_int_);

	instr_decode_::instr_mop inco_EDIVR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2R,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1R,		"op1",		0,		0,		0		 },
		{ mops::MOPC_DIVR,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTR,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EDIVR(inco_EDIVR_int_);

	instr_decode_::instr_mop inco_EEQB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2B,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1B,		"op1",		0,		0,		0		 },
		{ mops::MOPC_EQB,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTB,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EEQB(inco_EEQB_int_);

	instr_decode_::instr_mop inco_EEQI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2I,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1I,		"op1",		0,		0,		0		 },
		{ mops::MOPC_EQI,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTB,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EEQI(inco_EEQI_int_);

	instr_decode_::instr_mop inco_EEQR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2R,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1R,		"op1",		0,		0,		0		 },
		{ mops::MOPC_EQR,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTB,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EEQR(inco_EEQR_int_);

	instr_decode_::instr_mop inco_EEQS_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2S,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1S,		"op1",		0,		0,		0		 },
		{ mops::MOPC_EQS,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTB,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EEQS(inco_EEQS_int_);

	instr_decode_::instr_mop inco_EGEB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2B,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1B,		"op1",		0,		0,		0		 },
		{ mops::MOPC_GEB,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTB,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EGEB(inco_EGEB_int_);

	instr_decode_::instr_mop inco_EGEI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2I,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1I,		"op1",		0,		0,		0		 },
		{ mops::MOPC_GEI,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTB,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EGEI(inco_EGEI_int_);

	instr_decode_::instr_mop inco_EGER_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2R,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1R,		"op1",		0,		0,		0		 },
		{ mops::MOPC_GER,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTB,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EGER(inco_EGER_int_);

	instr_decode_::instr_mop inco_EGES_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2S,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1S,		"op1",		0,		0,		0		 },
		{ mops::MOPC_GES,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTB,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EGES(inco_EGES_int_);

	instr_decode_::instr_mop inco_EGTB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2B,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1B,		"op1",		0,		0,		0		 },
		{ mops::MOPC_GTB,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTB,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EGTB(inco_EGTB_int_);

	instr_decode_::instr_mop inco_EGTI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2I,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1I,		"op1",		0,		0,		0		 },
		{ mops::MOPC_GTI,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTB,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EGTI(inco_EGTI_int_);

	instr_decode_::instr_mop inco_EGTR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2R,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1R,		"op1",		0,		0,		0		 },
		{ mops::MOPC_GTR,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTB,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EGTR(inco_EGTR_int_);

	instr_decode_::instr_mop inco_EGTS_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2S,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1S,		"op1",		0,		0,		0		 },
		{ mops::MOPC_GTS,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTB,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EGTS(inco_EGTS_int_);

	instr_decode_::instr_mop inco_EINITB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_INITB,		"res",		0,		0,		0		 },
		{ mops::MOPC_WROUTB,		"wrout",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EINITB(inco_EINITB_int_);

	instr_decode_::instr_mop inco_EINITI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_INITI,		"res",		0,		0,		0		 },
		{ mops::MOPC_WROUTI,		"wrout",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EINITI(inco_EINITI_int_);

	instr_decode_::instr_mop inco_EINITR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_INITR,		"res",		0,		0,		0		 },
		{ mops::MOPC_WROUTR,		"wrout",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EINITR(inco_EINITR_int_);

	instr_decode_::instr_mop inco_EINITS_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_INITS,		"res",		0,		0,		0		 },
		{ mops::MOPC_WROUTS,		"wrout",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EINITS(inco_EINITS_int_);

	instr_decode_::instr_mop inco_ELDLITB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_LDLITB,		"res",		0,		0,		0		 },
		{ mops::MOPC_WROUTB,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_ELDLITB(inco_ELDLITB_int_);

	instr_decode_::instr_mop inco_ELDLITI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_LDLITI,		"res",		0,		0,		0		 },
		{ mops::MOPC_WROUTI,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_ELDLITI(inco_ELDLITI_int_);

	instr_decode_::instr_mop inco_ELDLITR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_LDLITR,		"res",		0,		0,		0		 },
		{ mops::MOPC_WROUTR,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_ELDLITR(inco_ELDLITR_int_);

	instr_decode_::instr_mop inco_ELDLITS_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_LDLITS,		"res",		0,		0,		0		 },
		{ mops::MOPC_WROUTS,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_ELDLITS(inco_ELDLITS_int_);

	instr_decode_::instr_mop inco_ELEB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2B,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1B,		"op1",		0,		0,		0		 },
		{ mops::MOPC_LEB,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTB,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_ELEB(inco_ELEB_int_);

	instr_decode_::instr_mop inco_ELEI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2I,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1I,		"op1",		0,		0,		0		 },
		{ mops::MOPC_LEI,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTB,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_ELEI(inco_ELEI_int_);

	instr_decode_::instr_mop inco_ELER_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2R,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1R,		"op1",		0,		0,		0		 },
		{ mops::MOPC_LER,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTB,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_ELER(inco_ELER_int_);

	instr_decode_::instr_mop inco_ELES_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2S,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1S,		"op1",		0,		0,		0		 },
		{ mops::MOPC_LES,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTB,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_ELES(inco_ELES_int_);

	instr_decode_::instr_mop inco_ELTB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2B,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1B,		"op1",		0,		0,		0		 },
		{ mops::MOPC_LTB,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTB,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_ELTB(inco_ELTB_int_);

	instr_decode_::instr_mop inco_ELTI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2I,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1I,		"op1",		0,		0,		0		 },
		{ mops::MOPC_LTI,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTB,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_ELTI(inco_ELTI_int_);

	instr_decode_::instr_mop inco_ELTR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2R,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1R,		"op1",		0,		0,		0		 },
		{ mops::MOPC_LTR,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTB,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_ELTR(inco_ELTR_int_);

	instr_decode_::instr_mop inco_ELTS_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2S,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1S,		"op1",		0,		0,		0		 },
		{ mops::MOPC_LTS,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTB,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_ELTS(inco_ELTS_int_);

	instr_decode_::instr_mop inco_EMINUSI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN1I,		"op1",		0,		0,		0		 },
		{ mops::MOPC_MINUSI,		"res",		"op1",		0,		0		 },
		{ mops::MOPC_WROUTI,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EMINUSI(inco_EMINUSI_int_);

	instr_decode_::instr_mop inco_EMINUSR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN1R,		"op1",		0,		0,		0		 },
		{ mops::MOPC_MINUSR,		"res",		"op1",		0,		0		 },
		{ mops::MOPC_WROUTR,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EMINUSR(inco_EMINUSR_int_);

	instr_decode_::instr_mop inco_EMODI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2I,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1I,		"op1",		0,		0,		0		 },
		{ mops::MOPC_MODI,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTI,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EMODI(inco_EMODI_int_);

	instr_decode_::instr_mop inco_EMOVB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN1B,		"res",		0,		0,		0		 },
		{ mops::MOPC_WROUTB,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EMOVB(inco_EMOVB_int_);

	instr_decode_::instr_mop inco_EMOVI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN1I,		"res",		0,		0,		0		 },
		{ mops::MOPC_WROUTI,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EMOVI(inco_EMOVI_int_);

	instr_decode_::instr_mop inco_EMOVP_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN1P,		"res",		0,		0,		0		 },
		{ mops::MOPC_WROUTP,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EMOVP(inco_EMOVP_int_);

	instr_decode_::instr_mop inco_EMOVR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN1R,		"res",		0,		0,		0		 },
		{ mops::MOPC_WROUTR,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EMOVR(inco_EMOVR_int_);

	instr_decode_::instr_mop inco_EMOVS_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN1S,		"res",		0,		0,		0		 },
		{ mops::MOPC_WROUTS,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EMOVS(inco_EMOVS_int_);

	instr_decode_::instr_mop inco_EMULI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2I,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1I,		"op1",		0,		0,		0		 },
		{ mops::MOPC_MULI,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTI,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EMULI(inco_EMULI_int_);

	instr_decode_::instr_mop inco_EMULR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2R,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1R,		"op1",		0,		0,		0		 },
		{ mops::MOPC_MULR,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTR,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EMULR(inco_EMULR_int_);

	instr_decode_::instr_mop inco_ENEB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2B,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1B,		"op1",		0,		0,		0		 },
		{ mops::MOPC_NEB,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTB,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_ENEB(inco_ENEB_int_);

	instr_decode_::instr_mop inco_ENEI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2I,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1I,		"op1",		0,		0,		0		 },
		{ mops::MOPC_NEI,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTB,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_ENEI(inco_ENEI_int_);

	instr_decode_::instr_mop inco_ENER_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2R,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1R,		"op1",		0,		0,		0		 },
		{ mops::MOPC_NER,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTB,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_ENER(inco_ENER_int_);

	instr_decode_::instr_mop inco_ENES_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2S,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1S,		"op1",		0,		0,		0		 },
		{ mops::MOPC_NES,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTB,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_ENES(inco_ENES_int_);

	instr_decode_::instr_mop inco_ENOT_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN1B,		"op1",		0,		0,		0		 },
		{ mops::MOPC_NOT,		"res",		"op1",		0,		0		 },
		{ mops::MOPC_WROUTB,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_ENOT(inco_ENOT_int_);

	instr_decode_::instr_mop inco_EOR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2B,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1B,		"op1",		0,		0,		0		 },
		{ mops::MOPC_OR,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTB,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EOR(inco_EOR_int_);

	instr_decode_::instr_mop inco_EPOP_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEM,		"res",		"rdsp",		0,		0		 },
		{ mops::MOPC_WROUT,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EPOP(inco_EPOP_int_);

	instr_decode_::instr_mop inco_EPOPB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMB,		"res",		"rdsp",		0,		0		 },
		{ mops::MOPC_WROUTB,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EPOPB(inco_EPOPB_int_);

	instr_decode_::instr_mop inco_EPOPI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMI,		"res",		"rdsp",		0,		0		 },
		{ mops::MOPC_WROUTI,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EPOPI(inco_EPOPI_int_);

	instr_decode_::instr_mop inco_EPOPP_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMP,		"res",		"rdsp",		0,		0		 },
		{ mops::MOPC_WROUTP,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EPOPP(inco_EPOPP_int_);

	instr_decode_::instr_mop inco_EPOPR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMR,		"res",		"rdsp",		0,		0		 },
		{ mops::MOPC_WROUTR,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EPOPR(inco_EPOPR_int_);

	instr_decode_::instr_mop inco_EPOPS_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMS,		"res",		"rdsp",		0,		0		 },
		{ mops::MOPC_WROUTS,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EPOPS(inco_EPOPS_int_);

	instr_decode_::instr_mop inco_EPUSH_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDIN1,		"res",		0,		0,		0		 },
		{ mops::MOPC_WRMEM,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EPUSH(inco_EPUSH_int_);

	instr_decode_::instr_mop inco_EPUSHB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDIN1B,		"res",		0,		0,		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EPUSHB(inco_EPUSHB_int_);

	instr_decode_::instr_mop inco_EPUSHI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDIN1I,		"res",		0,		0,		0		 },
		{ mops::MOPC_WRMEMI,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EPUSHI(inco_EPUSHI_int_);

	instr_decode_::instr_mop inco_EPUSHP_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDIN1P,		"res",		0,		0,		0		 },
		{ mops::MOPC_WRMEMP,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EPUSHP(inco_EPUSHP_int_);

	instr_decode_::instr_mop inco_EPUSHR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDIN1R,		"res",		0,		0,		0		 },
		{ mops::MOPC_WRMEMR,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EPUSHR(inco_EPUSHR_int_);

	instr_decode_::instr_mop inco_EPUSHS_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDIN1S,		"res",		0,		0,		0		 },
		{ mops::MOPC_WRMEMS,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EPUSHS(inco_EPUSHS_int_);

	instr_decode_::instr_mop inco_EQB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMB,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMB,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_EQB,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EQB(inco_EQB_int_);

	instr_decode_::instr_mop inco_EQI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMI,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMI,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_EQI,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EQI(inco_EQI_int_);

	instr_decode_::instr_mop inco_EQR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMR,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMR,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_EQR,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EQR(inco_EQR_int_);

	instr_decode_::instr_mop inco_EQS_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMS,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMS,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_EQS,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_EQS(inco_EQS_int_);

	instr_decode_::instr_mop inco_ESUBI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2I,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1I,		"op1",		0,		0,		0		 },
		{ mops::MOPC_SUBI,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTI,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_ESUBI(inco_ESUBI_int_);

	instr_decode_::instr_mop inco_ESUBP_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2I,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1P,		"op1",		0,		0,		0		 },
		{ mops::MOPC_SUBP,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTP,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_ESUBP(inco_ESUBP_int_);

	instr_decode_::instr_mop inco_ESUBR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2R,		"op2",		0,		0,		0		 },
		{ mops::MOPC_RDIN1R,		"op1",		0,		0,		0		 },
		{ mops::MOPC_SUBR,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WROUTR,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_ESUBR(inco_ESUBR_int_);

	instr_decode_::instr_mop inco_FNCREADI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_FNCREADI,		"res",		0,		0,		0		 },
		{ mops::MOPC_WRMEMI,		"wrmem",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_FNCREADI(inco_FNCREADI_int_);

	instr_decode_::instr_mop inco_FNCREADR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_FNCREADR,		"res",		0,		0,		0		 },
		{ mops::MOPC_WRMEMR,		"wrmem",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_FNCREADR(inco_FNCREADR_int_);

	instr_decode_::instr_mop inco_FNCREADS_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_FNCREADS,		"res",		0,		0,		0		 },
		{ mops::MOPC_WRMEMS,		"wrmem",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_FNCREADS(inco_FNCREADS_int_);

	instr_decode_::instr_mop inco_FNCWRITEI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMI,		"op",		"rdsp",		0,		0		 },
		{ mops::MOPC_FNCWRITEI,		"fnc",		"op",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_FNCWRITEI(inco_FNCWRITEI_int_);

	instr_decode_::instr_mop inco_FNCWRITELN_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_FNCWRITELN,	"fnc",		0,		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_FNCWRITELN(inco_FNCWRITELN_int_);

	instr_decode_::instr_mop inco_FNCWRITER_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMR,		"op",		"rdsp",		0,		0		 },
		{ mops::MOPC_FNCWRITER,		"fnc",		"op",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_FNCWRITER(inco_FNCWRITER_int_);

	instr_decode_::instr_mop inco_FNCWRITES_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMS,		"op",		"rdsp",		0,		0		 },
		{ mops::MOPC_FNCWRITES,		"fnc",		"op",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_FNCWRITES(inco_FNCWRITES_int_);

	instr_decode_::instr_mop inco_GEB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMB,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMB,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_GEB,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_GEB(inco_GEB_int_);

	instr_decode_::instr_mop inco_GEI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMI,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMI,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_GEI,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_GEI(inco_GEI_int_);

	instr_decode_::instr_mop inco_GELDB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_GSTKOFFS,		"gstkoffs",	0,		0,		0		 },
		{ mops::MOPC_RDMEMB,		"res",		"gstkoffs",	0,		0		 },
		{ mops::MOPC_WROUTB,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_GELDB(inco_GELDB_int_);

	instr_decode_::instr_mop inco_GELDI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_GSTKOFFS,		"gstkoffs",	0,		0,		0		 },
		{ mops::MOPC_RDMEMI,		"res",		"gstkoffs",	0,		0		 },
		{ mops::MOPC_WROUTI,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_GELDI(inco_GELDI_int_);

	instr_decode_::instr_mop inco_GELDR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_GSTKOFFS,		"gstkoffs",	0,		0,		0		 },
		{ mops::MOPC_RDMEMR,		"res",		"gstkoffs",	0,		0		 },
		{ mops::MOPC_WROUTR,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_GELDR(inco_GELDR_int_);

	instr_decode_::instr_mop inco_GELDS_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_GSTKOFFS,		"gstkoffs",	0,		0,		0		 },
		{ mops::MOPC_RDMEMS,		"res",		"gstkoffs",	0,		0		 },
		{ mops::MOPC_WROUTS,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_GELDS(inco_GELDS_int_);

	instr_decode_::instr_mop inco_GER_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMR,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMR,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_GER,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_GER(inco_GER_int_);

	instr_decode_::instr_mop inco_GEREF_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_GSTKOFFS,		"res",		0,		0,		0		 },
		{ mops::MOPC_WROUTP,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_GEREF(inco_GEREF_int_);

	instr_decode_::instr_mop inco_GES_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMS,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMS,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_GES,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_GES(inco_GES_int_);

	instr_decode_::instr_mop inco_GESTB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_GSTKOFFS,		"gstkoffs",	0,		0,		0		 },
		{ mops::MOPC_RDIN1B,		"res",		0,		0,		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"gstkoffs",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_GESTB(inco_GESTB_int_);

	instr_decode_::instr_mop inco_GESTI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_GSTKOFFS,		"gstkoffs",	0,		0,		0		 },
		{ mops::MOPC_RDIN1I,		"res",		0,		0,		0		 },
		{ mops::MOPC_WRMEMI,		"wrres",	"gstkoffs",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_GESTI(inco_GESTI_int_);

	instr_decode_::instr_mop inco_GESTR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_GSTKOFFS,		"gstkoffs",	0,		0,		0		 },
		{ mops::MOPC_RDIN1R,		"res",		0,		0,		0		 },
		{ mops::MOPC_WRMEMR,		"wrres",	"gstkoffs",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_GESTR(inco_GESTR_int_);

	instr_decode_::instr_mop inco_GESTS_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_GSTKOFFS,		"gstkoffs",	0,		0,		0		 },
		{ mops::MOPC_RDIN1S,		"res",		0,		0,		0		 },
		{ mops::MOPC_WRMEMS,		"wrres",	"gstkoffs",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_GESTS(inco_GESTS_int_);

	instr_decode_::instr_mop inco_GLDB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_GSTKOFFS,		"gstkoffs",	0,		0,		0		 },
		{ mops::MOPC_RDMEMB,		"res",		"gstkoffs",	0,		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_GLDB(inco_GLDB_int_);

	instr_decode_::instr_mop inco_GLDI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_GSTKOFFS,		"gstkoffs",	0,		0,		0		 },
		{ mops::MOPC_RDMEMI,		"res",		"gstkoffs",	0,		0		 },
		{ mops::MOPC_WRMEMI,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_GLDI(inco_GLDI_int_);

	instr_decode_::instr_mop inco_GLDR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_GSTKOFFS,		"gstkoffs",	0,		0,		0		 },
		{ mops::MOPC_RDMEMR,		"res",		"gstkoffs",	0,		0		 },
		{ mops::MOPC_WRMEMR,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_GLDR(inco_GLDR_int_);

	instr_decode_::instr_mop inco_GLDS_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_GSTKOFFS,		"gstkoffs",	0,		0,		0		 },
		{ mops::MOPC_RDMEMS,		"res",		"gstkoffs",	0,		0		 },
		{ mops::MOPC_WRMEMS,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_GLDS(inco_GLDS_int_);

	instr_decode_::instr_mop inco_GREF_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_GSTKOFFS,		"gstkoffs",	0,		0,		0		 },
		{ mops::MOPC_WRMEMP,		"wrres",	"newsp",	"gstkoffs",	0		 },
	};

	const carray<instr_decode_::instr_mop> inco_GREF(inco_GREF_int_);

	instr_decode_::instr_mop inco_GSTB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_GSTKOFFS,		"gstkoffs",	0,		0,		0		 },
		{ mops::MOPC_RDMEMB,		"res",		"rdsp",		0,		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"gstkoffs",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_GSTB(inco_GSTB_int_);

	instr_decode_::instr_mop inco_GSTI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_GSTKOFFS,		"gstkoffs",	0,		0,		0		 },
		{ mops::MOPC_RDMEMI,		"res",		"rdsp",		0,		0		 },
		{ mops::MOPC_WRMEMI,		"wrres",	"gstkoffs",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_GSTI(inco_GSTI_int_);

	instr_decode_::instr_mop inco_GSTR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_GSTKOFFS,		"gstkoffs",	0,		0,		0		 },
		{ mops::MOPC_RDMEMR,		"res",		"rdsp",		0,		0		 },
		{ mops::MOPC_WRMEMR,		"wrres",	"gstkoffs",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_GSTR(inco_GSTR_int_);

	instr_decode_::instr_mop inco_GSTS_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_GSTKOFFS,		"gstkoffs",	0,		0,		0		 },
		{ mops::MOPC_RDMEMS,		"res",		"rdsp",		0,		0		 },
		{ mops::MOPC_WRMEMS,		"wrres",	"gstkoffs",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_GSTS(inco_GSTS_int_);

	instr_decode_::instr_mop inco_GTB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMB,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMB,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_GTB,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_GTB(inco_GTB_int_);

	instr_decode_::instr_mop inco_GTI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMI,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMI,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_GTI,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_GTI(inco_GTI_int_);

	instr_decode_::instr_mop inco_GTR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMR,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMR,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_GTR,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_GTR(inco_GTR_int_);

	instr_decode_::instr_mop inco_GTS_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMS,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMS,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_GTS,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_GTS(inco_GTS_int_);

	instr_decode_::instr_mop inco_HALT_int_[] = {
		{ mops::MOPC_HALT,		"halt",		0,		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"halt",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_HALT(inco_HALT_int_);

	instr_decode_::instr_mop inco_INITB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_INITB,		"res",		0,		0,		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_INITB(inco_INITB_int_);

	instr_decode_::instr_mop inco_INITI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_INITI,		"res",		0,		0,		0		 },
		{ mops::MOPC_WRMEMI,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_INITI(inco_INITI_int_);

	instr_decode_::instr_mop inco_INITR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_INITR,		"res",		0,		0,		0		 },
		{ mops::MOPC_WRMEMR,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_INITR(inco_INITR_int_);

	instr_decode_::instr_mop inco_INITS_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_INITS,		"res",		0,		0,		0		 },
		{ mops::MOPC_WRMEMS,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_INITS(inco_INITS_int_);

	instr_decode_::instr_mop inco_JEF_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_RDIN1B,		"flag",		0,		0,		0		 },
		{ mops::MOPC_ADDRELNUMIFFC,	"nextip",	"rdip",		"flag",		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_JEF(inco_JEF_int_);

	instr_decode_::instr_mop inco_JET_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_RDIN1B,		"flag",		0,		0,		0		 },
		{ mops::MOPC_ADDRELNUMIFTC,	"nextip",	"rdip",		"flag",		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_JET(inco_JET_int_);

	instr_decode_::instr_mop inco_JF_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_RDMEMB,		"flag",		"rdsp",		0,		0		 },
		{ mops::MOPC_ADDRELNUMIFFC,	"nextip",	"rdip",		"flag",		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_JF(inco_JF_int_);

	instr_decode_::instr_mop inco_JMP_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_ADDRELNUMC,	"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_JMP(inco_JMP_int_);

	instr_decode_::instr_mop inco_JT_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_RDMEMB,		"flag",		"rdsp",		0,		0		 },
		{ mops::MOPC_ADDRELNUMIFTC,	"nextip",	"rdip",		"flag",		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_JT(inco_JT_int_);

	instr_decode_::instr_mop inco_LDLITB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_LDLITB,		"ldlit",	0,		0,		0		 },
		{ mops::MOPC_WRMEMB,		"wrmem",	"newsp",	"ldlit",	0		 },
	};

	const carray<instr_decode_::instr_mop> inco_LDLITB(inco_LDLITB_int_);

	instr_decode_::instr_mop inco_LDLITI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_LDLITI,		"ldlit",	0,		0,		0		 },
		{ mops::MOPC_WRMEMI,		"wrmem",	"newsp",	"ldlit",	0		 },
	};

	const carray<instr_decode_::instr_mop> inco_LDLITI(inco_LDLITI_int_);

	instr_decode_::instr_mop inco_LDLITR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_LDLITR,		"ldlit",	0,		0,		0		 },
		{ mops::MOPC_WRMEMR,		"wrmem",	"newsp",	"ldlit",	0		 },
	};

	const carray<instr_decode_::instr_mop> inco_LDLITR(inco_LDLITR_int_);

	instr_decode_::instr_mop inco_LDLITS_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_LDLITS,		"ldlit",	0,		0,		0		 },
		{ mops::MOPC_WRMEMS,		"wrmem",	"newsp",	"ldlit",	0		 },
	};

	const carray<instr_decode_::instr_mop> inco_LDLITS(inco_LDLITS_int_);

	instr_decode_::instr_mop inco_LEB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMB,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMB,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_LEB,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_LEB(inco_LEB_int_);

	instr_decode_::instr_mop inco_LEI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMI,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMI,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_LEI,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_LEI(inco_LEI_int_);

	instr_decode_::instr_mop inco_LELDB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDFP,		"rdfp",		0,		0,		0		 },
		{ mops::MOPC_ADDLSTKOFFS,	"addr",		"rdfp",		0,		0		 },
		{ mops::MOPC_RDMEMB,		"res",		"addr",		0,		0		 },
		{ mops::MOPC_WROUTB,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_LELDB(inco_LELDB_int_);

	instr_decode_::instr_mop inco_LELDI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDFP,		"rdfp",		0,		0,		0		 },
		{ mops::MOPC_ADDLSTKOFFS,	"addr",		"rdfp",		0,		0		 },
		{ mops::MOPC_RDMEMI,		"res",		"addr",		0,		0		 },
		{ mops::MOPC_WROUTI,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_LELDI(inco_LELDI_int_);

	instr_decode_::instr_mop inco_LELDP_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDFP,		"rdfp",		0,		0,		0		 },
		{ mops::MOPC_ADDLSTKOFFS,	"addr",		"rdfp",		0,		0		 },
		{ mops::MOPC_RDMEMP,		"res",		"addr",		0,		0		 },
		{ mops::MOPC_WROUTP,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_LELDP(inco_LELDP_int_);

	instr_decode_::instr_mop inco_LELDR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDFP,		"rdfp",		0,		0,		0		 },
		{ mops::MOPC_ADDLSTKOFFS,	"addr",		"rdfp",		0,		0		 },
		{ mops::MOPC_RDMEMR,		"res",		"addr",		0,		0		 },
		{ mops::MOPC_WROUTR,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_LELDR(inco_LELDR_int_);

	instr_decode_::instr_mop inco_LELDS_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDFP,		"rdfp",		0,		0,		0		 },
		{ mops::MOPC_ADDLSTKOFFS,	"addr",		"rdfp",		0,		0		 },
		{ mops::MOPC_RDMEMS,		"res",		"addr",		0,		0		 },
		{ mops::MOPC_WROUTS,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_LELDS(inco_LELDS_int_);

	instr_decode_::instr_mop inco_LER_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMR,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMR,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_LER,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_LER(inco_LER_int_);

	instr_decode_::instr_mop inco_LEREF_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDFP,		"rdfp",		0,		0,		0		 },
		{ mops::MOPC_ADDLSTKOFFS,	"res",		"rdfp",		0,		0		 },
		{ mops::MOPC_WROUTP,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_LEREF(inco_LEREF_int_);

	instr_decode_::instr_mop inco_LES_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMS,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMS,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_LES,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_LES(inco_LES_int_);

	instr_decode_::instr_mop inco_LESTB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDFP,		"rdfp",		0,		0,		0		 },
		{ mops::MOPC_ADDLSTKOFFS,	"addr",		"rdfp",		0,		0		 },
		{ mops::MOPC_RDIN1B,		"res",		0,		0,		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"addr",		"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_LESTB(inco_LESTB_int_);

	instr_decode_::instr_mop inco_LESTI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDFP,		"rdfp",		0,		0,		0		 },
		{ mops::MOPC_ADDLSTKOFFS,	"addr",		"rdfp",		0,		0		 },
		{ mops::MOPC_RDIN1I,		"res",		0,		0,		0		 },
		{ mops::MOPC_WRMEMI,		"wrres",	"addr",		"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_LESTI(inco_LESTI_int_);

	instr_decode_::instr_mop inco_LESTP_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDFP,		"rdfp",		0,		0,		0		 },
		{ mops::MOPC_ADDLSTKOFFS,	"addr",		"rdfp",		0,		0		 },
		{ mops::MOPC_RDIN1P,		"res",		0,		0,		0		 },
		{ mops::MOPC_WRMEMP,		"wrres",	"addr",		"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_LESTP(inco_LESTP_int_);

	instr_decode_::instr_mop inco_LESTR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDFP,		"rdfp",		0,		0,		0		 },
		{ mops::MOPC_ADDLSTKOFFS,	"addr",		"rdfp",		0,		0		 },
		{ mops::MOPC_RDIN1R,		"res",		0,		0,		0		 },
		{ mops::MOPC_WRMEMR,		"wrres",	"addr",		"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_LESTR(inco_LESTR_int_);

	instr_decode_::instr_mop inco_LESTS_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDFP,		"rdfp",		0,		0,		0		 },
		{ mops::MOPC_ADDLSTKOFFS,	"addr",		"rdfp",		0,		0		 },
		{ mops::MOPC_RDIN1S,		"res",		0,		0,		0		 },
		{ mops::MOPC_WRMEMS,		"wrres",	"addr",		"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_LESTS(inco_LESTS_int_);

	instr_decode_::instr_mop inco_LLDB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDFP,		"rdfp",		0,		0,		0		 },
		{ mops::MOPC_ADDLSTKOFFS,	"addr",		"rdfp",		0,		0		 },
		{ mops::MOPC_RDMEMB,		"res",		"addr",		0,		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_LLDB(inco_LLDB_int_);

	instr_decode_::instr_mop inco_LLDI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDFP,		"rdfp",		0,		0,		0		 },
		{ mops::MOPC_ADDLSTKOFFS,	"addr",		"rdfp",		0,		0		 },
		{ mops::MOPC_RDMEMI,		"res",		"addr",		0,		0		 },
		{ mops::MOPC_WRMEMI,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_LLDI(inco_LLDI_int_);

	instr_decode_::instr_mop inco_LLDP_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDFP,		"rdfp",		0,		0,		0		 },
		{ mops::MOPC_ADDLSTKOFFS,	"addr",		"rdfp",		0,		0		 },
		{ mops::MOPC_RDMEMP,		"res",		"addr",		0,		0		 },
		{ mops::MOPC_WRMEMP,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_LLDP(inco_LLDP_int_);

	instr_decode_::instr_mop inco_LLDR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDFP,		"rdfp",		0,		0,		0		 },
		{ mops::MOPC_ADDLSTKOFFS,	"addr",		"rdfp",		0,		0		 },
		{ mops::MOPC_RDMEMR,		"res",		"addr",		0,		0		 },
		{ mops::MOPC_WRMEMR,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_LLDR(inco_LLDR_int_);

	instr_decode_::instr_mop inco_LLDS_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDFP,		"rdfp",		0,		0,		0		 },
		{ mops::MOPC_ADDLSTKOFFS,	"addr",		"rdfp",		0,		0		 },
		{ mops::MOPC_RDMEMS,		"res",		"addr",		0,		0		 },
		{ mops::MOPC_WRMEMS,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_LLDS(inco_LLDS_int_);

	instr_decode_::instr_mop inco_LREF_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDFP,		"rdfp",		0,		0,		0		 },
		{ mops::MOPC_ADDLSTKOFFS,	"addr",		"rdfp",		0,		0		 },
		{ mops::MOPC_WRMEMP,		"wrres",	"newsp",	"addr",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_LREF(inco_LREF_int_);

	instr_decode_::instr_mop inco_LSTB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDFP,		"rdfp",		0,		0,		0		 },
		{ mops::MOPC_ADDLSTKOFFS,	"addr",		"rdfp",		0,		0		 },
		{ mops::MOPC_RDMEMB,		"res",		"rdsp",		0,		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"addr",		"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_LSTB(inco_LSTB_int_);

	instr_decode_::instr_mop inco_LSTI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDFP,		"rdfp",		0,		0,		0		 },
		{ mops::MOPC_ADDLSTKOFFS,	"addr",		"rdfp",		0,		0		 },
		{ mops::MOPC_RDMEMI,		"res",		"rdsp",		0,		0		 },
		{ mops::MOPC_WRMEMI,		"wrres",	"addr",		"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_LSTI(inco_LSTI_int_);

	instr_decode_::instr_mop inco_LSTR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDFP,		"rdfp",		0,		0,		0		 },
		{ mops::MOPC_ADDLSTKOFFS,	"addr",		"rdfp",		0,		0		 },
		{ mops::MOPC_RDMEMR,		"res",		"rdsp",		0,		0		 },
		{ mops::MOPC_WRMEMR,		"wrres",	"addr",		"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_LSTR(inco_LSTR_int_);

	instr_decode_::instr_mop inco_LSTS_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDFP,		"rdfp",		0,		0,		0		 },
		{ mops::MOPC_ADDLSTKOFFS,	"addr",		"rdfp",		0,		0		 },
		{ mops::MOPC_RDMEMS,		"res",		"rdsp",		0,		0		 },
		{ mops::MOPC_WRMEMS,		"wrres",	"addr",		"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_LSTS(inco_LSTS_int_);

	instr_decode_::instr_mop inco_LTB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMB,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMB,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_LTB,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_LTB(inco_LTB_int_);

	instr_decode_::instr_mop inco_LTI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMI,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMI,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_LTI,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_LTI(inco_LTI_int_);

	instr_decode_::instr_mop inco_LTR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMR,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMR,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_LTR,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_LTR(inco_LTR_int_);

	instr_decode_::instr_mop inco_LTS_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMS,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMS,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_LTS,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMS,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_LTS(inco_LTS_int_);

	instr_decode_::instr_mop inco_MINUSI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_RDMEMI,		"op1",		"rdsp",		0,		0		 },
		{ mops::MOPC_MINUSI,		"res",		"op1",		0,		0		 },
		{ mops::MOPC_WRMEMI,		"wrres",	"rdsp",		"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_MINUSI(inco_MINUSI_int_);

	instr_decode_::instr_mop inco_MINUSR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_RDMEMR,		"op1",		"rdsp",		0,		0		 },
		{ mops::MOPC_MINUSR,		"res",		"op1",		0,		0		 },
		{ mops::MOPC_WRMEMR,		"wrres",	"rdsp",		"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_MINUSR(inco_MINUSR_int_);

	instr_decode_::instr_mop inco_MODI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMI,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMI,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_MODI,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMI,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_MODI(inco_MODI_int_);

	instr_decode_::instr_mop inco_MULI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMI,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMI,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_MULI,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMI,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_MULI(inco_MULI_int_);

	instr_decode_::instr_mop inco_MULR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMR,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMR,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_MULR,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMR,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_MULR(inco_MULR_int_);

	instr_decode_::instr_mop inco_NEB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMB,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMB,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_NEB,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_NEB(inco_NEB_int_);

	instr_decode_::instr_mop inco_NEI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMI,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMI,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_NEI,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_NEI(inco_NEI_int_);

	instr_decode_::instr_mop inco_NER_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMR,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMR,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_NER,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_NER(inco_NER_int_);

	instr_decode_::instr_mop inco_NES_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMS,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMS,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_NES,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_NES(inco_NES_int_);

	instr_decode_::instr_mop inco_NOP_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_NOP(inco_NOP_int_);

	instr_decode_::instr_mop inco_NOT_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_RDMEMB,		"op1",		"rdsp",		0,		0		 },
		{ mops::MOPC_NOT,		"res",		"op1",		0,		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"rdsp",		"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_NOT(inco_NOT_int_);

	instr_decode_::instr_mop inco_OR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMB,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMB,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_OR,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_OR(inco_OR_int_);

	instr_decode_::instr_mop inco_RET_int_[] = {
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMF,		"rdmemf",	"rdsp",		0,		0		 },
		{ mops::MOPC_EXTRACTFP,		"newfp",	"rdmemf",	0,		0		 },
		{ mops::MOPC_WRFP,		"wrfp",		"newfp",	0,		0		 },
		{ mops::MOPC_EXTRACTIP,		"nextip",	"rdmemf",	0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_RET(inco_RET_int_);

	instr_decode_::instr_mop inco_SADD_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_ADDSSTKOFFS,	"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_SADD(inco_SADD_int_);

	instr_decode_::instr_mop inco_SLDB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_ADDSSTKOFFS,	"addr",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMB,		"res",		"addr",		0,		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_SLDB(inco_SLDB_int_);

	instr_decode_::instr_mop inco_SLDI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_ADDSSTKOFFS,	"addr",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMI,		"res",		"addr",		0,		0		 },
		{ mops::MOPC_WRMEMI,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_SLDI(inco_SLDI_int_);

	instr_decode_::instr_mop inco_SLDP_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_ADDSSTKOFFS,	"addr",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMP,		"res",		"addr",		0,		0		 },
		{ mops::MOPC_WRMEMP,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_SLDP(inco_SLDP_int_);

	instr_decode_::instr_mop inco_SLDR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_ADDSSTKOFFS,	"addr",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMR,		"res",		"addr",		0,		0		 },
		{ mops::MOPC_WRMEMR,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_SLDR(inco_SLDR_int_);

	instr_decode_::instr_mop inco_SLDS_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_ADDSSTKOFFS,	"addr",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMS,		"res",		"addr",		0,		0		 },
		{ mops::MOPC_WRMEMS,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_SLDS(inco_SLDS_int_);

	instr_decode_::instr_mop inco_SREF_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_INCP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_ADDSSTKOFFS,	"addr",		"rdsp",		0,		0		 },
		{ mops::MOPC_WRMEMP,		"wrres",	"newsp",	"addr",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_SREF(inco_SREF_int_);

	instr_decode_::instr_mop inco_SSTB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_ADDSSTKOFFS,	"addr",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMB,		"res",		"rdsp",		0,		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"addr",		"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_SSTB(inco_SSTB_int_);

	instr_decode_::instr_mop inco_SSTI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_ADDSSTKOFFS,	"addr",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMI,		"res",		"rdsp",		0,		0		 },
		{ mops::MOPC_WRMEMI,		"wrres",	"addr",		"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_SSTI(inco_SSTI_int_);

	instr_decode_::instr_mop inco_SSTP_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_ADDSSTKOFFS,	"addr",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMP,		"res",		"rdsp",		0,		0		 },
		{ mops::MOPC_WRMEMP,		"wrres",	"addr",		"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_SSTP(inco_SSTP_int_);

	instr_decode_::instr_mop inco_SSTR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_ADDSSTKOFFS,	"addr",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMR,		"res",		"rdsp",		0,		0		 },
		{ mops::MOPC_WRMEMR,		"wrres",	"addr",		"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_SSTR(inco_SSTR_int_);

	instr_decode_::instr_mop inco_SSTS_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_ADDSSTKOFFS,	"addr",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMS,		"res",		"rdsp",		0,		0		 },
		{ mops::MOPC_WRMEMS,		"wrres",	"addr",		"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_SSTS(inco_SSTS_int_);

	instr_decode_::instr_mop inco_SUBI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMI,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMI,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_SUBI,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMI,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_SUBI(inco_SUBI_int_);

	instr_decode_::instr_mop inco_SUBP_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMI,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMP,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_SUBP,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMP,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_SUBP(inco_SUBP_int_);

	instr_decode_::instr_mop inco_SUBR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMR,		"op2",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMR,		"op1",		"newsp",	0,		0		 },
		{ mops::MOPC_SUBR,		"res",		"op1",		"op2",		0		 },
		{ mops::MOPC_WRMEMR,		"wrres",	"newsp",	"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_SUBR(inco_SUBR_int_);

	instr_decode_::instr_mop inco_XELDB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN1P,		"addr",		0,		0,		0		 },
		{ mops::MOPC_RDMEMB,		"res",		"addr",		0,		0		 },
		{ mops::MOPC_WROUTB,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_XELDB(inco_XELDB_int_);

	instr_decode_::instr_mop inco_XELDI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN1P,		"addr",		0,		0,		0		 },
		{ mops::MOPC_RDMEMI,		"res",		"addr",		0,		0		 },
		{ mops::MOPC_WROUTI,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_XELDI(inco_XELDI_int_);

	instr_decode_::instr_mop inco_XELDR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN1P,		"addr",		0,		0,		0		 },
		{ mops::MOPC_RDMEMR,		"res",		"addr",		0,		0		 },
		{ mops::MOPC_WROUTR,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_XELDR(inco_XELDR_int_);

	instr_decode_::instr_mop inco_XELDS_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN1P,		"addr",		0,		0,		0		 },
		{ mops::MOPC_RDMEMS,		"res",		"addr",		0,		0		 },
		{ mops::MOPC_WROUTS,		"wrres",	"res",		0,		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_XELDS(inco_XELDS_int_);

	instr_decode_::instr_mop inco_XESTB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2P,		"addr",		0,		0,		0		 },
		{ mops::MOPC_RDIN1B,		"res",		0,		0,		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"addr",		"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_XESTB(inco_XESTB_int_);

	instr_decode_::instr_mop inco_XESTI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2P,		"addr",		0,		0,		0		 },
		{ mops::MOPC_RDIN1I,		"res",		0,		0,		0		 },
		{ mops::MOPC_WRMEMI,		"wrres",	"addr",		"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_XESTI(inco_XESTI_int_);

	instr_decode_::instr_mop inco_XESTR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2P,		"addr",		0,		0,		0		 },
		{ mops::MOPC_RDIN1R,		"res",		0,		0,		0		 },
		{ mops::MOPC_WRMEMR,		"wrres",	"addr",		"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_XESTR(inco_XESTR_int_);

	instr_decode_::instr_mop inco_XESTS_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDIN2P,		"addr",		0,		0,		0		 },
		{ mops::MOPC_RDIN1S,		"res",		0,		0,		0		 },
		{ mops::MOPC_WRMEMS,		"wrres",	"addr",		"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_XESTS(inco_XESTS_int_);

	instr_decode_::instr_mop inco_XLDB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_RDMEMP,		"addr",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMB,		"res",		"addr",		0,		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"rdsp",		"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_XLDB(inco_XLDB_int_);

	instr_decode_::instr_mop inco_XLDI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_RDMEMP,		"addr",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMI,		"res",		"addr",		0,		0		 },
		{ mops::MOPC_WRMEMI,		"wrres",	"rdsp",		"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_XLDI(inco_XLDI_int_);

	instr_decode_::instr_mop inco_XLDR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_RDMEMP,		"addr",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMR,		"res",		"addr",		0,		0		 },
		{ mops::MOPC_WRMEMR,		"wrres",	"rdsp",		"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_XLDR(inco_XLDR_int_);

	instr_decode_::instr_mop inco_XLDS_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_RDMEMP,		"addr",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMS,		"res",		"addr",		0,		0		 },
		{ mops::MOPC_WRMEMS,		"wrres",	"rdsp",		"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_XLDS(inco_XLDS_int_);

	instr_decode_::instr_mop inco_XSTB_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"midsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_DEC2P,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMP,		"addr",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMB,		"res",		"midsp",	0,		0		 },
		{ mops::MOPC_WRMEMB,		"wrres",	"addr",		"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_XSTB(inco_XSTB_int_);

	instr_decode_::instr_mop inco_XSTI_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"midsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_DEC2P,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMP,		"addr",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMI,		"res",		"midsp",	0,		0		 },
		{ mops::MOPC_WRMEMI,		"wrres",	"addr",		"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_XSTI(inco_XSTI_int_);

	instr_decode_::instr_mop inco_XSTR_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"midsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_DEC2P,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMP,		"addr",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMR,		"res",		"midsp",	0,		0		 },
		{ mops::MOPC_WRMEMR,		"wrres",	"addr",		"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_XSTR(inco_XSTR_int_);

	instr_decode_::instr_mop inco_XSTS_int_[] = {
		{ mops::MOPC_RDIP,		"rdip",		0,		0,		0		 },
		{ mops::MOPC_INCC,		"nextip",	"rdip",		0,		0		 },
		{ mops::MOPC_WRIP,		"wrip",		"nextip",	0,		0		 },
		{ mops::MOPC_RDSP,		"rdsp",		0,		0,		0		 },
		{ mops::MOPC_DECP,		"midsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_DEC2P,		"newsp",	"rdsp",		0,		0		 },
		{ mops::MOPC_WRSP,		"wrsp",		"newsp",	0,		0		 },
		{ mops::MOPC_RDMEMP,		"addr",		"rdsp",		0,		0		 },
		{ mops::MOPC_RDMEMS,		"res",		"midsp",	0,		0		 },
		{ mops::MOPC_WRMEMS,		"wrres",	"addr",		"res",		0		 },
	};

	const carray<instr_decode_::instr_mop> inco_XSTS(inco_XSTS_int_);

	instr_decode_::instr_code instr_decodes_int_[] = {
		inco_ADDI,
		inco_ADDP,
		inco_ADDR,
		inco_ADDS,
		inco_AND,
		inco_CALL,
		inco_CVRTIR,
		inco_CVRTRI,
		inco_DIVI,
		inco_DIVR,
		inco_DTORB,
		inco_DTORI,
		inco_DTORP,
		inco_DTORR,
		inco_DTORS,
		inco_EADDI,
		inco_EADDP,
		inco_EADDR,
		inco_EADDS,
		inco_EAND,
		inco_ECVRTIR,
		inco_ECVRTRI,
		inco_EDIVI,
		inco_EDIVR,
		inco_EEQB,
		inco_EEQI,
		inco_EEQR,
		inco_EEQS,
		inco_EGEB,
		inco_EGEI,
		inco_EGER,
		inco_EGES,
		inco_EGTB,
		inco_EGTI,
		inco_EGTR,
		inco_EGTS,
		inco_EINITB,
		inco_EINITI,
		inco_EINITR,
		inco_EINITS,
		inco_ELDLITB,
		inco_ELDLITI,
		inco_ELDLITR,
		inco_ELDLITS,
		inco_ELEB,
		inco_ELEI,
		inco_ELER,
		inco_ELES,
		inco_ELTB,
		inco_ELTI,
		inco_ELTR,
		inco_ELTS,
		inco_EMINUSI,
		inco_EMINUSR,
		inco_EMODI,
		inco_EMOVB,
		inco_EMOVI,
		inco_EMOVP,
		inco_EMOVR,
		inco_EMOVS,
		inco_EMULI,
		inco_EMULR,
		inco_ENEB,
		inco_ENEI,
		inco_ENER,
		inco_ENES,
		inco_ENOT,
		inco_EOR,
		inco_EPOP,
		inco_EPOPB,
		inco_EPOPI,
		inco_EPOPP,
		inco_EPOPR,
		inco_EPOPS,
		inco_EPUSH,
		inco_EPUSHB,
		inco_EPUSHI,
		inco_EPUSHP,
		inco_EPUSHR,
		inco_EPUSHS,
		inco_EQB,
		inco_EQI,
		inco_EQR,
		inco_EQS,
		inco_ESUBI,
		inco_ESUBP,
		inco_ESUBR,
		inco_FNCREADI,
		inco_FNCREADR,
		inco_FNCREADS,
		inco_FNCWRITEI,
		inco_FNCWRITELN,
		inco_FNCWRITER,
		inco_FNCWRITES,
		inco_GEB,
		inco_GEI,
		inco_GELDB,
		inco_GELDI,
		inco_GELDR,
		inco_GELDS,
		inco_GER,
		inco_GEREF,
		inco_GES,
		inco_GESTB,
		inco_GESTI,
		inco_GESTR,
		inco_GESTS,
		inco_GLDB,
		inco_GLDI,
		inco_GLDR,
		inco_GLDS,
		inco_GREF,
		inco_GSTB,
		inco_GSTI,
		inco_GSTR,
		inco_GSTS,
		inco_GTB,
		inco_GTI,
		inco_GTR,
		inco_GTS,
		inco_HALT,
		inco_INITB,
		inco_INITI,
		inco_INITR,
		inco_INITS,
		inco_JEF,
		inco_JET,
		inco_JF,
		inco_JMP,
		inco_JT,
		inco_LDLITB,
		inco_LDLITI,
		inco_LDLITR,
		inco_LDLITS,
		inco_LEB,
		inco_LEI,
		inco_LELDB,
		inco_LELDI,
		inco_LELDP,
		inco_LELDR,
		inco_LELDS,
		inco_LER,
		inco_LEREF,
		inco_LES,
		inco_LESTB,
		inco_LESTI,
		inco_LESTP,
		inco_LESTR,
		inco_LESTS,
		inco_LLDB,
		inco_LLDI,
		inco_LLDP,
		inco_LLDR,
		inco_LLDS,
		inco_LREF,
		inco_LSTB,
		inco_LSTI,
		inco_LSTR,
		inco_LSTS,
		inco_LTB,
		inco_LTI,
		inco_LTR,
		inco_LTS,
		inco_MINUSI,
		inco_MINUSR,
		inco_MODI,
		inco_MULI,
		inco_MULR,
		inco_NEB,
		inco_NEI,
		inco_NER,
		inco_NES,
		inco_NOP,
		inco_NOT,
		inco_OR,
		inco_RET,
		inco_SADD,
		inco_SLDB,
		inco_SLDI,
		inco_SLDP,
		inco_SLDR,
		inco_SLDS,
		inco_SREF,
		inco_SSTB,
		inco_SSTI,
		inco_SSTP,
		inco_SSTR,
		inco_SSTS,
		inco_SUBI,
		inco_SUBP,
		inco_SUBR,
		inco_XELDB,
		inco_XELDI,
		inco_XELDR,
		inco_XELDS,
		inco_XESTB,
		inco_XESTI,
		inco_XESTR,
		inco_XESTS,
		inco_XLDB,
		inco_XLDI,
		inco_XLDR,
		inco_XLDS,
		inco_XSTB,
		inco_XSTI,
		inco_XSTR,
		inco_XSTS,
	};

} // anonymous namespace

namespace mlaskal {

namespace instr_decode_ {

	const carray<instr_code> instr_decodes(instr_decodes_int_);

} // namespace instr_decode_

} // namespace mlaskal
