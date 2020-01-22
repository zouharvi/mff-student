/*
	GEN_ICFACTORY.CPP

	GENERATED, DO NOT MODIFY!!!!
*/

#include "common_types.hpp"
#include "ic_opcodes.hpp"
#include "ic_factory.hpp"
#include "ic_instr.hpp"

namespace icfcr_int_ {

	static mlaskal::ic_instr *icfcr_ADDI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::ADDI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_ADDP(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::ADDP(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_ADDR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::ADDR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_ADDS(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::ADDS(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_AND(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::AND(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_CALL(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::CALL(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_CVRTIR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::CVRTIR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_CVRTRI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::CVRTRI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_DIVI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::DIVI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_DIVR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::DIVR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_DTORB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::DTORB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_DTORI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::DTORI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_DTORP(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::DTORP(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_DTORR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::DTORR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_DTORS(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::DTORS(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EADDI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EADDI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EADDP(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EADDP(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EADDR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EADDR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EADDS(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EADDS(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EAND(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EAND(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_ECVRTIR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::ECVRTIR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_ECVRTRI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::ECVRTRI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EDIVI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EDIVI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EDIVR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EDIVR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EEQB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EEQB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EEQI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EEQI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EEQR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EEQR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EEQS(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EEQS(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EGEB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EGEB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EGEI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EGEI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EGER(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EGER(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EGES(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EGES(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EGTB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EGTB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EGTI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EGTI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EGTR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EGTR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EGTS(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EGTS(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EINITB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EINITB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EINITI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EINITI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EINITR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EINITR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EINITS(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EINITS(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_ELDLITB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::ELDLITB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_ELDLITI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::ELDLITI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_ELDLITR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::ELDLITR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_ELDLITS(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::ELDLITS(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_ELEB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::ELEB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_ELEI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::ELEI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_ELER(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::ELER(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_ELES(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::ELES(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_ELTB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::ELTB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_ELTI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::ELTI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_ELTR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::ELTR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_ELTS(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::ELTS(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EMINUSI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EMINUSI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EMINUSR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EMINUSR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EMODI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EMODI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EMOVB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EMOVB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EMOVI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EMOVI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EMOVP(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EMOVP(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EMOVR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EMOVR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EMOVS(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EMOVS(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EMULI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EMULI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EMULR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EMULR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_ENEB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::ENEB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_ENEI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::ENEI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_ENER(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::ENER(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_ENES(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::ENES(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_ENOT(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::ENOT(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EOR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EOR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EPOP(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EPOP(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EPOPB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EPOPB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EPOPI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EPOPI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EPOPP(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EPOPP(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EPOPR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EPOPR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EPOPS(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EPOPS(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EPUSH(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EPUSH(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EPUSHB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EPUSHB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EPUSHI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EPUSHI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EPUSHP(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EPUSHP(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EPUSHR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EPUSHR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EPUSHS(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EPUSHS(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EQB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EQB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EQI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EQI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EQR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EQR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_EQS(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::EQS(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_ESUBI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::ESUBI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_ESUBP(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::ESUBP(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_ESUBR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::ESUBR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_FNCREADI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::FNCREADI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_FNCREADR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::FNCREADR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_FNCREADS(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::FNCREADS(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_FNCWRITEI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::FNCWRITEI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_FNCWRITELN(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::FNCWRITELN(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_FNCWRITER(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::FNCWRITER(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_FNCWRITES(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::FNCWRITES(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_GEB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::GEB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_GEI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::GEI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_GELDB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::GELDB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_GELDI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::GELDI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_GELDR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::GELDR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_GELDS(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::GELDS(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_GER(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::GER(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_GEREF(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::GEREF(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_GES(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::GES(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_GESTB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::GESTB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_GESTI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::GESTI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_GESTR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::GESTR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_GESTS(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::GESTS(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_GLDB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::GLDB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_GLDI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::GLDI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_GLDR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::GLDR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_GLDS(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::GLDS(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_GREF(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::GREF(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_GSTB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::GSTB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_GSTI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::GSTI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_GSTR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::GSTR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_GSTS(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::GSTS(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_GTB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::GTB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_GTI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::GTI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_GTR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::GTR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_GTS(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::GTS(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_HALT(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::HALT(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_INITB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::INITB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_INITI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::INITI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_INITR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::INITR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_INITS(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::INITS(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_JEF(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::JEF(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_JET(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::JET(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_JF(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::JF(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_JMP(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::JMP(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_JT(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::JT(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_LDLITB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::LDLITB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_LDLITI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::LDLITI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_LDLITR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::LDLITR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_LDLITS(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::LDLITS(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_LEB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::LEB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_LEI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::LEI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_LELDB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::LELDB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_LELDI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::LELDI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_LELDP(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::LELDP(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_LELDR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::LELDR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_LELDS(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::LELDS(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_LER(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::LER(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_LEREF(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::LEREF(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_LES(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::LES(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_LESTB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::LESTB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_LESTI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::LESTI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_LESTP(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::LESTP(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_LESTR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::LESTR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_LESTS(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::LESTS(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_LLDB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::LLDB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_LLDI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::LLDI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_LLDP(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::LLDP(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_LLDR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::LLDR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_LLDS(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::LLDS(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_LREF(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::LREF(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_LSTB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::LSTB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_LSTI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::LSTI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_LSTR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::LSTR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_LSTS(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::LSTS(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_LTB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::LTB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_LTI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::LTI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_LTR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::LTR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_LTS(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::LTS(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_MINUSI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::MINUSI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_MINUSR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::MINUSR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_MODI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::MODI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_MULI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::MULI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_MULR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::MULR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_NEB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::NEB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_NEI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::NEI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_NER(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::NER(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_NES(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::NES(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_NOP(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::NOP(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_NOT(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::NOT(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_OR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::OR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_RET(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::RET(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_SADD(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::SADD(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_SLDB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::SLDB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_SLDI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::SLDI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_SLDP(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::SLDP(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_SLDR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::SLDR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_SLDS(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::SLDS(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_SREF(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::SREF(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_SSTB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::SSTB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_SSTI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::SSTI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_SSTP(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::SSTP(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_SSTR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::SSTR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_SSTS(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::SSTS(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_SUBI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::SUBI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_SUBP(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::SUBP(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_SUBR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::SUBR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_XELDB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::XELDB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_XELDI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::XELDI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_XELDR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::XELDR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_XELDS(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::XELDS(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_XESTB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::XESTB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_XESTI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::XESTI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_XESTR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::XESTR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_XESTS(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::XESTS(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_XLDB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::XLDB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_XLDI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::XLDI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_XLDR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::XLDR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_XLDS(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::XLDS(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_XSTB(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::XSTB(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_XSTI(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::XSTI(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_XSTR(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::XSTR(opc, n, in1, in2, in3, in4, out);
	}

	static mlaskal::ic_instr *icfcr_XSTS(ai::IC_OPCODE opc, mlaskal::ICRELNUM n, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4, mlaskal::ICREGNUM out) {
		return new icinstr_int_::XSTS(opc, n, in1, in2, in3, in4, out);
	}

}

namespace mlaskal {

ic_factory_creator_type ic_factory::creators_[ai::ICOP_DNOTUSE_MAX_]={
	icfcr_int_::icfcr_ADDI,
	icfcr_int_::icfcr_ADDP,
	icfcr_int_::icfcr_ADDR,
	icfcr_int_::icfcr_ADDS,
	icfcr_int_::icfcr_AND,
	icfcr_int_::icfcr_CALL,
	icfcr_int_::icfcr_CVRTIR,
	icfcr_int_::icfcr_CVRTRI,
	icfcr_int_::icfcr_DIVI,
	icfcr_int_::icfcr_DIVR,
	icfcr_int_::icfcr_DTORB,
	icfcr_int_::icfcr_DTORI,
	icfcr_int_::icfcr_DTORP,
	icfcr_int_::icfcr_DTORR,
	icfcr_int_::icfcr_DTORS,
	icfcr_int_::icfcr_EADDI,
	icfcr_int_::icfcr_EADDP,
	icfcr_int_::icfcr_EADDR,
	icfcr_int_::icfcr_EADDS,
	icfcr_int_::icfcr_EAND,
	icfcr_int_::icfcr_ECVRTIR,
	icfcr_int_::icfcr_ECVRTRI,
	icfcr_int_::icfcr_EDIVI,
	icfcr_int_::icfcr_EDIVR,
	icfcr_int_::icfcr_EEQB,
	icfcr_int_::icfcr_EEQI,
	icfcr_int_::icfcr_EEQR,
	icfcr_int_::icfcr_EEQS,
	icfcr_int_::icfcr_EGEB,
	icfcr_int_::icfcr_EGEI,
	icfcr_int_::icfcr_EGER,
	icfcr_int_::icfcr_EGES,
	icfcr_int_::icfcr_EGTB,
	icfcr_int_::icfcr_EGTI,
	icfcr_int_::icfcr_EGTR,
	icfcr_int_::icfcr_EGTS,
	icfcr_int_::icfcr_EINITB,
	icfcr_int_::icfcr_EINITI,
	icfcr_int_::icfcr_EINITR,
	icfcr_int_::icfcr_EINITS,
	icfcr_int_::icfcr_ELDLITB,
	icfcr_int_::icfcr_ELDLITI,
	icfcr_int_::icfcr_ELDLITR,
	icfcr_int_::icfcr_ELDLITS,
	icfcr_int_::icfcr_ELEB,
	icfcr_int_::icfcr_ELEI,
	icfcr_int_::icfcr_ELER,
	icfcr_int_::icfcr_ELES,
	icfcr_int_::icfcr_ELTB,
	icfcr_int_::icfcr_ELTI,
	icfcr_int_::icfcr_ELTR,
	icfcr_int_::icfcr_ELTS,
	icfcr_int_::icfcr_EMINUSI,
	icfcr_int_::icfcr_EMINUSR,
	icfcr_int_::icfcr_EMODI,
	icfcr_int_::icfcr_EMOVB,
	icfcr_int_::icfcr_EMOVI,
	icfcr_int_::icfcr_EMOVP,
	icfcr_int_::icfcr_EMOVR,
	icfcr_int_::icfcr_EMOVS,
	icfcr_int_::icfcr_EMULI,
	icfcr_int_::icfcr_EMULR,
	icfcr_int_::icfcr_ENEB,
	icfcr_int_::icfcr_ENEI,
	icfcr_int_::icfcr_ENER,
	icfcr_int_::icfcr_ENES,
	icfcr_int_::icfcr_ENOT,
	icfcr_int_::icfcr_EOR,
	icfcr_int_::icfcr_EPOP,
	icfcr_int_::icfcr_EPOPB,
	icfcr_int_::icfcr_EPOPI,
	icfcr_int_::icfcr_EPOPP,
	icfcr_int_::icfcr_EPOPR,
	icfcr_int_::icfcr_EPOPS,
	icfcr_int_::icfcr_EPUSH,
	icfcr_int_::icfcr_EPUSHB,
	icfcr_int_::icfcr_EPUSHI,
	icfcr_int_::icfcr_EPUSHP,
	icfcr_int_::icfcr_EPUSHR,
	icfcr_int_::icfcr_EPUSHS,
	icfcr_int_::icfcr_EQB,
	icfcr_int_::icfcr_EQI,
	icfcr_int_::icfcr_EQR,
	icfcr_int_::icfcr_EQS,
	icfcr_int_::icfcr_ESUBI,
	icfcr_int_::icfcr_ESUBP,
	icfcr_int_::icfcr_ESUBR,
	icfcr_int_::icfcr_FNCREADI,
	icfcr_int_::icfcr_FNCREADR,
	icfcr_int_::icfcr_FNCREADS,
	icfcr_int_::icfcr_FNCWRITEI,
	icfcr_int_::icfcr_FNCWRITELN,
	icfcr_int_::icfcr_FNCWRITER,
	icfcr_int_::icfcr_FNCWRITES,
	icfcr_int_::icfcr_GEB,
	icfcr_int_::icfcr_GEI,
	icfcr_int_::icfcr_GELDB,
	icfcr_int_::icfcr_GELDI,
	icfcr_int_::icfcr_GELDR,
	icfcr_int_::icfcr_GELDS,
	icfcr_int_::icfcr_GER,
	icfcr_int_::icfcr_GEREF,
	icfcr_int_::icfcr_GES,
	icfcr_int_::icfcr_GESTB,
	icfcr_int_::icfcr_GESTI,
	icfcr_int_::icfcr_GESTR,
	icfcr_int_::icfcr_GESTS,
	icfcr_int_::icfcr_GLDB,
	icfcr_int_::icfcr_GLDI,
	icfcr_int_::icfcr_GLDR,
	icfcr_int_::icfcr_GLDS,
	icfcr_int_::icfcr_GREF,
	icfcr_int_::icfcr_GSTB,
	icfcr_int_::icfcr_GSTI,
	icfcr_int_::icfcr_GSTR,
	icfcr_int_::icfcr_GSTS,
	icfcr_int_::icfcr_GTB,
	icfcr_int_::icfcr_GTI,
	icfcr_int_::icfcr_GTR,
	icfcr_int_::icfcr_GTS,
	icfcr_int_::icfcr_HALT,
	icfcr_int_::icfcr_INITB,
	icfcr_int_::icfcr_INITI,
	icfcr_int_::icfcr_INITR,
	icfcr_int_::icfcr_INITS,
	icfcr_int_::icfcr_JEF,
	icfcr_int_::icfcr_JET,
	icfcr_int_::icfcr_JF,
	icfcr_int_::icfcr_JMP,
	icfcr_int_::icfcr_JT,
	icfcr_int_::icfcr_LDLITB,
	icfcr_int_::icfcr_LDLITI,
	icfcr_int_::icfcr_LDLITR,
	icfcr_int_::icfcr_LDLITS,
	icfcr_int_::icfcr_LEB,
	icfcr_int_::icfcr_LEI,
	icfcr_int_::icfcr_LELDB,
	icfcr_int_::icfcr_LELDI,
	icfcr_int_::icfcr_LELDP,
	icfcr_int_::icfcr_LELDR,
	icfcr_int_::icfcr_LELDS,
	icfcr_int_::icfcr_LER,
	icfcr_int_::icfcr_LEREF,
	icfcr_int_::icfcr_LES,
	icfcr_int_::icfcr_LESTB,
	icfcr_int_::icfcr_LESTI,
	icfcr_int_::icfcr_LESTP,
	icfcr_int_::icfcr_LESTR,
	icfcr_int_::icfcr_LESTS,
	icfcr_int_::icfcr_LLDB,
	icfcr_int_::icfcr_LLDI,
	icfcr_int_::icfcr_LLDP,
	icfcr_int_::icfcr_LLDR,
	icfcr_int_::icfcr_LLDS,
	icfcr_int_::icfcr_LREF,
	icfcr_int_::icfcr_LSTB,
	icfcr_int_::icfcr_LSTI,
	icfcr_int_::icfcr_LSTR,
	icfcr_int_::icfcr_LSTS,
	icfcr_int_::icfcr_LTB,
	icfcr_int_::icfcr_LTI,
	icfcr_int_::icfcr_LTR,
	icfcr_int_::icfcr_LTS,
	icfcr_int_::icfcr_MINUSI,
	icfcr_int_::icfcr_MINUSR,
	icfcr_int_::icfcr_MODI,
	icfcr_int_::icfcr_MULI,
	icfcr_int_::icfcr_MULR,
	icfcr_int_::icfcr_NEB,
	icfcr_int_::icfcr_NEI,
	icfcr_int_::icfcr_NER,
	icfcr_int_::icfcr_NES,
	icfcr_int_::icfcr_NOP,
	icfcr_int_::icfcr_NOT,
	icfcr_int_::icfcr_OR,
	icfcr_int_::icfcr_RET,
	icfcr_int_::icfcr_SADD,
	icfcr_int_::icfcr_SLDB,
	icfcr_int_::icfcr_SLDI,
	icfcr_int_::icfcr_SLDP,
	icfcr_int_::icfcr_SLDR,
	icfcr_int_::icfcr_SLDS,
	icfcr_int_::icfcr_SREF,
	icfcr_int_::icfcr_SSTB,
	icfcr_int_::icfcr_SSTI,
	icfcr_int_::icfcr_SSTP,
	icfcr_int_::icfcr_SSTR,
	icfcr_int_::icfcr_SSTS,
	icfcr_int_::icfcr_SUBI,
	icfcr_int_::icfcr_SUBP,
	icfcr_int_::icfcr_SUBR,
	icfcr_int_::icfcr_XELDB,
	icfcr_int_::icfcr_XELDI,
	icfcr_int_::icfcr_XELDR,
	icfcr_int_::icfcr_XELDS,
	icfcr_int_::icfcr_XESTB,
	icfcr_int_::icfcr_XESTI,
	icfcr_int_::icfcr_XESTR,
	icfcr_int_::icfcr_XESTS,
	icfcr_int_::icfcr_XLDB,
	icfcr_int_::icfcr_XLDI,
	icfcr_int_::icfcr_XLDR,
	icfcr_int_::icfcr_XLDS,
	icfcr_int_::icfcr_XSTB,
	icfcr_int_::icfcr_XSTI,
	icfcr_int_::icfcr_XSTR,
	icfcr_int_::icfcr_XSTS,
};

}
