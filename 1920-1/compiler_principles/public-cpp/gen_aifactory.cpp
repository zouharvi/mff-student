/*
	GEN_AIFACTORY.CPP

	GENERATED, DO NOT MODIFY!!!!
*/

#include "ai_factory.hpp"
#include "abstract_instr.hpp"

namespace aifcr_int_ {

	static mlaskal::abstract_instr *aifcr_ADDI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::ADDI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_ADDP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::ADDP(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_ADDR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::ADDR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_ADDS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::ADDS(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_AND(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::AND(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_CALL(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::CALL(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_CVRTIR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::CVRTIR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_CVRTRI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::CVRTRI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_DIVI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::DIVI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_DIVR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::DIVR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_DTORB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::DTORB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_DTORI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::DTORI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_DTORP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::DTORP(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_DTORR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::DTORR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_DTORS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::DTORS(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EADDI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EADDI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EADDP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EADDP(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EADDR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EADDR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EADDS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EADDS(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EAND(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EAND(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_ECVRTIR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::ECVRTIR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_ECVRTRI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::ECVRTRI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EDIVI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EDIVI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EDIVR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EDIVR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EEQB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EEQB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EEQI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EEQI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EEQR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EEQR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EEQS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EEQS(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EGEB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EGEB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EGEI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EGEI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EGER(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EGER(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EGES(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EGES(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EGTB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EGTB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EGTI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EGTI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EGTR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EGTR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EGTS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EGTS(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EINITB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EINITB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EINITI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EINITI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EINITR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EINITR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EINITS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EINITS(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_ELDLITB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::ELDLITB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_ELDLITI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::ELDLITI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_ELDLITR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::ELDLITR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_ELDLITS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::ELDLITS(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_ELEB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::ELEB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_ELEI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::ELEI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_ELER(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::ELER(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_ELES(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::ELES(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_ELTB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::ELTB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_ELTI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::ELTI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_ELTR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::ELTR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_ELTS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::ELTS(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EMINUSI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EMINUSI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EMINUSR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EMINUSR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EMODI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EMODI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EMOVB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EMOVB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EMOVI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EMOVI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EMOVP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EMOVP(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EMOVR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EMOVR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EMOVS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EMOVS(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EMULI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EMULI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EMULR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EMULR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_ENEB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::ENEB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_ENEI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::ENEI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_ENER(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::ENER(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_ENES(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::ENES(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_ENOT(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::ENOT(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EOR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EOR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EPOP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EPOP(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EPOPB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EPOPB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EPOPI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EPOPI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EPOPP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EPOPP(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EPOPR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EPOPR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EPOPS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EPOPS(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EPUSH(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EPUSH(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EPUSHB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EPUSHB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EPUSHI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EPUSHI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EPUSHP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EPUSHP(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EPUSHR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EPUSHR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EPUSHS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EPUSHS(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EQB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EQB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EQI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EQI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EQR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EQR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_EQS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::EQS(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_ESUBI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::ESUBI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_ESUBP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::ESUBP(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_ESUBR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::ESUBR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_FNCREADI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::FNCREADI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_FNCREADR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::FNCREADR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_FNCREADS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::FNCREADS(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_FNCWRITEI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::FNCWRITEI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_FNCWRITELN(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::FNCWRITELN(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_FNCWRITER(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::FNCWRITER(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_FNCWRITES(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::FNCWRITES(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_GEB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::GEB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_GEI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::GEI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_GELDB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::GELDB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_GELDI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::GELDI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_GELDR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::GELDR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_GELDS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::GELDS(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_GER(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::GER(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_GEREF(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::GEREF(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_GES(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::GES(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_GESTB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::GESTB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_GESTI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::GESTI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_GESTR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::GESTR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_GESTS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::GESTS(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_GLDB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::GLDB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_GLDI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::GLDI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_GLDR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::GLDR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_GLDS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::GLDS(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_GREF(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::GREF(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_GSTB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::GSTB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_GSTI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::GSTI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_GSTR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::GSTR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_GSTS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::GSTS(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_GTB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::GTB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_GTI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::GTI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_GTR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::GTR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_GTS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::GTS(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_HALT(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::HALT(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_INITB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::INITB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_INITI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::INITI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_INITR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::INITR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_INITS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::INITS(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_JEF(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::JEF(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_JET(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::JET(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_JF(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::JF(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_JMP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::JMP(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_JT(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::JT(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_LDLITB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::LDLITB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_LDLITI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::LDLITI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_LDLITR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::LDLITR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_LDLITS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::LDLITS(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_LEB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::LEB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_LEI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::LEI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_LELDB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::LELDB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_LELDI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::LELDI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_LELDP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::LELDP(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_LELDR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::LELDR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_LELDS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::LELDS(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_LER(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::LER(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_LEREF(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::LEREF(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_LES(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::LES(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_LESTB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::LESTB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_LESTI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::LESTI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_LESTP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::LESTP(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_LESTR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::LESTR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_LESTS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::LESTS(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_LLDB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::LLDB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_LLDI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::LLDI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_LLDP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::LLDP(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_LLDR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::LLDR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_LLDS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::LLDS(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_LREF(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::LREF(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_LSTB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::LSTB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_LSTI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::LSTI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_LSTR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::LSTR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_LSTS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::LSTS(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_LTB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::LTB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_LTI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::LTI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_LTR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::LTR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_LTS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::LTS(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_MINUSI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::MINUSI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_MINUSR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::MINUSR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_MODI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::MODI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_MULI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::MULI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_MULR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::MULR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_NEB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::NEB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_NEI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::NEI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_NER(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::NER(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_NES(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::NES(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_NOP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::NOP(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_NOT(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::NOT(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_OR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::OR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_RET(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::RET(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_SADD(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::SADD(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_SLDB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::SLDB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_SLDI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::SLDI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_SLDP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::SLDP(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_SLDR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::SLDR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_SLDS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::SLDS(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_SREF(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::SREF(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_SSTB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::SSTB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_SSTI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::SSTI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_SSTP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::SSTP(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_SSTR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::SSTR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_SSTS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::SSTS(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_SUBI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::SUBI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_SUBP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::SUBP(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_SUBR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::SUBR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_XELDB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::XELDB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_XELDI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::XELDI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_XELDR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::XELDR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_XELDS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::XELDS(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_XESTB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::XESTB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_XESTI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::XESTI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_XESTR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::XESTR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_XESTS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::XESTS(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_XLDB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::XLDB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_XLDI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::XLDI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_XLDR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::XLDR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_XLDS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::XLDS(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_XSTB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::XSTB(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_XSTI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::XSTI(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_XSTR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::XSTR(out, in1, in2, in3, in4);
	}

	static mlaskal::abstract_instr *aifcr_XSTS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) {
		return new ai::XSTS(out, in1, in2, in3, in4);
	}

}

namespace aifcl_int_ {

	static mlaskal::abstract_instr *aifcl_ADDI(const mlaskal::abstract_instr *) {
		return new ai::ADDI();
	}

	static mlaskal::abstract_instr *aifcl_ADDP(const mlaskal::abstract_instr *) {
		return new ai::ADDP();
	}

	static mlaskal::abstract_instr *aifcl_ADDR(const mlaskal::abstract_instr *) {
		return new ai::ADDR();
	}

	static mlaskal::abstract_instr *aifcl_ADDS(const mlaskal::abstract_instr *) {
		return new ai::ADDS();
	}

	static mlaskal::abstract_instr *aifcl_AND(const mlaskal::abstract_instr *) {
		return new ai::AND();
	}

	static mlaskal::abstract_instr *aifcl_CALL(const mlaskal::abstract_instr *oldai) {
		return new ai::CALL(oldai->get_absjump());
	}

	static mlaskal::abstract_instr *aifcl_CVRTIR(const mlaskal::abstract_instr *) {
		return new ai::CVRTIR();
	}

	static mlaskal::abstract_instr *aifcl_CVRTRI(const mlaskal::abstract_instr *) {
		return new ai::CVRTRI();
	}

	static mlaskal::abstract_instr *aifcl_DIVI(const mlaskal::abstract_instr *) {
		return new ai::DIVI();
	}

	static mlaskal::abstract_instr *aifcl_DIVR(const mlaskal::abstract_instr *) {
		return new ai::DIVR();
	}

	static mlaskal::abstract_instr *aifcl_DTORB(const mlaskal::abstract_instr *) {
		return new ai::DTORB();
	}

	static mlaskal::abstract_instr *aifcl_DTORI(const mlaskal::abstract_instr *) {
		return new ai::DTORI();
	}

	static mlaskal::abstract_instr *aifcl_DTORP(const mlaskal::abstract_instr *) {
		return new ai::DTORP();
	}

	static mlaskal::abstract_instr *aifcl_DTORR(const mlaskal::abstract_instr *) {
		return new ai::DTORR();
	}

	static mlaskal::abstract_instr *aifcl_DTORS(const mlaskal::abstract_instr *) {
		return new ai::DTORS();
	}

	static mlaskal::abstract_instr *aifcl_EADDI(const mlaskal::abstract_instr *oldai) {
		return new ai::EADDI(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_EADDP(const mlaskal::abstract_instr *oldai) {
		return new ai::EADDP(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_EADDR(const mlaskal::abstract_instr *oldai) {
		return new ai::EADDR(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_EADDS(const mlaskal::abstract_instr *oldai) {
		return new ai::EADDS(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_EAND(const mlaskal::abstract_instr *oldai) {
		return new ai::EAND(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_ECVRTIR(const mlaskal::abstract_instr *oldai) {
		return new ai::ECVRTIR(oldai->get_out(), oldai->get_in1());
	}

	static mlaskal::abstract_instr *aifcl_ECVRTRI(const mlaskal::abstract_instr *oldai) {
		return new ai::ECVRTRI(oldai->get_out(), oldai->get_in1());
	}

	static mlaskal::abstract_instr *aifcl_EDIVI(const mlaskal::abstract_instr *oldai) {
		return new ai::EDIVI(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_EDIVR(const mlaskal::abstract_instr *oldai) {
		return new ai::EDIVR(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_EEQB(const mlaskal::abstract_instr *oldai) {
		return new ai::EEQB(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_EEQI(const mlaskal::abstract_instr *oldai) {
		return new ai::EEQI(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_EEQR(const mlaskal::abstract_instr *oldai) {
		return new ai::EEQR(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_EEQS(const mlaskal::abstract_instr *oldai) {
		return new ai::EEQS(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_EGEB(const mlaskal::abstract_instr *oldai) {
		return new ai::EGEB(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_EGEI(const mlaskal::abstract_instr *oldai) {
		return new ai::EGEI(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_EGER(const mlaskal::abstract_instr *oldai) {
		return new ai::EGER(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_EGES(const mlaskal::abstract_instr *oldai) {
		return new ai::EGES(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_EGTB(const mlaskal::abstract_instr *oldai) {
		return new ai::EGTB(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_EGTI(const mlaskal::abstract_instr *oldai) {
		return new ai::EGTI(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_EGTR(const mlaskal::abstract_instr *oldai) {
		return new ai::EGTR(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_EGTS(const mlaskal::abstract_instr *oldai) {
		return new ai::EGTS(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_EINITB(const mlaskal::abstract_instr *oldai) {
		return new ai::EINITB(oldai->get_out());
	}

	static mlaskal::abstract_instr *aifcl_EINITI(const mlaskal::abstract_instr *oldai) {
		return new ai::EINITI(oldai->get_out());
	}

	static mlaskal::abstract_instr *aifcl_EINITR(const mlaskal::abstract_instr *oldai) {
		return new ai::EINITR(oldai->get_out());
	}

	static mlaskal::abstract_instr *aifcl_EINITS(const mlaskal::abstract_instr *oldai) {
		return new ai::EINITS(oldai->get_out());
	}

	static mlaskal::abstract_instr *aifcl_ELDLITB(const mlaskal::abstract_instr *oldai) {
		return new ai::ELDLITB(oldai->get_out(), oldai->get_absnum());
	}

	static mlaskal::abstract_instr *aifcl_ELDLITI(const mlaskal::abstract_instr *oldai) {
		return new ai::ELDLITI(oldai->get_out(), oldai->get_litint());
	}

	static mlaskal::abstract_instr *aifcl_ELDLITR(const mlaskal::abstract_instr *oldai) {
		return new ai::ELDLITR(oldai->get_out(), oldai->get_litreal());
	}

	static mlaskal::abstract_instr *aifcl_ELDLITS(const mlaskal::abstract_instr *oldai) {
		return new ai::ELDLITS(oldai->get_out(), oldai->get_litstr());
	}

	static mlaskal::abstract_instr *aifcl_ELEB(const mlaskal::abstract_instr *oldai) {
		return new ai::ELEB(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_ELEI(const mlaskal::abstract_instr *oldai) {
		return new ai::ELEI(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_ELER(const mlaskal::abstract_instr *oldai) {
		return new ai::ELER(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_ELES(const mlaskal::abstract_instr *oldai) {
		return new ai::ELES(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_ELTB(const mlaskal::abstract_instr *oldai) {
		return new ai::ELTB(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_ELTI(const mlaskal::abstract_instr *oldai) {
		return new ai::ELTI(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_ELTR(const mlaskal::abstract_instr *oldai) {
		return new ai::ELTR(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_ELTS(const mlaskal::abstract_instr *oldai) {
		return new ai::ELTS(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_EMINUSI(const mlaskal::abstract_instr *oldai) {
		return new ai::EMINUSI(oldai->get_out(), oldai->get_in1());
	}

	static mlaskal::abstract_instr *aifcl_EMINUSR(const mlaskal::abstract_instr *oldai) {
		return new ai::EMINUSR(oldai->get_out(), oldai->get_in1());
	}

	static mlaskal::abstract_instr *aifcl_EMODI(const mlaskal::abstract_instr *oldai) {
		return new ai::EMODI(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_EMOVB(const mlaskal::abstract_instr *oldai) {
		return new ai::EMOVB(oldai->get_out(), oldai->get_in1());
	}

	static mlaskal::abstract_instr *aifcl_EMOVI(const mlaskal::abstract_instr *oldai) {
		return new ai::EMOVI(oldai->get_out(), oldai->get_in1());
	}

	static mlaskal::abstract_instr *aifcl_EMOVP(const mlaskal::abstract_instr *oldai) {
		return new ai::EMOVP(oldai->get_out(), oldai->get_in1());
	}

	static mlaskal::abstract_instr *aifcl_EMOVR(const mlaskal::abstract_instr *oldai) {
		return new ai::EMOVR(oldai->get_out(), oldai->get_in1());
	}

	static mlaskal::abstract_instr *aifcl_EMOVS(const mlaskal::abstract_instr *oldai) {
		return new ai::EMOVS(oldai->get_out(), oldai->get_in1());
	}

	static mlaskal::abstract_instr *aifcl_EMULI(const mlaskal::abstract_instr *oldai) {
		return new ai::EMULI(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_EMULR(const mlaskal::abstract_instr *oldai) {
		return new ai::EMULR(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_ENEB(const mlaskal::abstract_instr *oldai) {
		return new ai::ENEB(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_ENEI(const mlaskal::abstract_instr *oldai) {
		return new ai::ENEI(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_ENER(const mlaskal::abstract_instr *oldai) {
		return new ai::ENER(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_ENES(const mlaskal::abstract_instr *oldai) {
		return new ai::ENES(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_ENOT(const mlaskal::abstract_instr *oldai) {
		return new ai::ENOT(oldai->get_out(), oldai->get_in1());
	}

	static mlaskal::abstract_instr *aifcl_EOR(const mlaskal::abstract_instr *oldai) {
		return new ai::EOR(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_EPOP(const mlaskal::abstract_instr *oldai) {
		return new ai::EPOP(oldai->get_out());
	}

	static mlaskal::abstract_instr *aifcl_EPOPB(const mlaskal::abstract_instr *oldai) {
		return new ai::EPOPB(oldai->get_out());
	}

	static mlaskal::abstract_instr *aifcl_EPOPI(const mlaskal::abstract_instr *oldai) {
		return new ai::EPOPI(oldai->get_out());
	}

	static mlaskal::abstract_instr *aifcl_EPOPP(const mlaskal::abstract_instr *oldai) {
		return new ai::EPOPP(oldai->get_out());
	}

	static mlaskal::abstract_instr *aifcl_EPOPR(const mlaskal::abstract_instr *oldai) {
		return new ai::EPOPR(oldai->get_out());
	}

	static mlaskal::abstract_instr *aifcl_EPOPS(const mlaskal::abstract_instr *oldai) {
		return new ai::EPOPS(oldai->get_out());
	}

	static mlaskal::abstract_instr *aifcl_EPUSH(const mlaskal::abstract_instr *oldai) {
		return new ai::EPUSH(oldai->get_in1());
	}

	static mlaskal::abstract_instr *aifcl_EPUSHB(const mlaskal::abstract_instr *oldai) {
		return new ai::EPUSHB(oldai->get_in1());
	}

	static mlaskal::abstract_instr *aifcl_EPUSHI(const mlaskal::abstract_instr *oldai) {
		return new ai::EPUSHI(oldai->get_in1());
	}

	static mlaskal::abstract_instr *aifcl_EPUSHP(const mlaskal::abstract_instr *oldai) {
		return new ai::EPUSHP(oldai->get_in1());
	}

	static mlaskal::abstract_instr *aifcl_EPUSHR(const mlaskal::abstract_instr *oldai) {
		return new ai::EPUSHR(oldai->get_in1());
	}

	static mlaskal::abstract_instr *aifcl_EPUSHS(const mlaskal::abstract_instr *oldai) {
		return new ai::EPUSHS(oldai->get_in1());
	}

	static mlaskal::abstract_instr *aifcl_EQB(const mlaskal::abstract_instr *) {
		return new ai::EQB();
	}

	static mlaskal::abstract_instr *aifcl_EQI(const mlaskal::abstract_instr *) {
		return new ai::EQI();
	}

	static mlaskal::abstract_instr *aifcl_EQR(const mlaskal::abstract_instr *) {
		return new ai::EQR();
	}

	static mlaskal::abstract_instr *aifcl_EQS(const mlaskal::abstract_instr *) {
		return new ai::EQS();
	}

	static mlaskal::abstract_instr *aifcl_ESUBI(const mlaskal::abstract_instr *oldai) {
		return new ai::ESUBI(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_ESUBP(const mlaskal::abstract_instr *oldai) {
		return new ai::ESUBP(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_ESUBR(const mlaskal::abstract_instr *oldai) {
		return new ai::ESUBR(oldai->get_out(), oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_FNCREADI(const mlaskal::abstract_instr *) {
		return new ai::FNCREADI();
	}

	static mlaskal::abstract_instr *aifcl_FNCREADR(const mlaskal::abstract_instr *) {
		return new ai::FNCREADR();
	}

	static mlaskal::abstract_instr *aifcl_FNCREADS(const mlaskal::abstract_instr *) {
		return new ai::FNCREADS();
	}

	static mlaskal::abstract_instr *aifcl_FNCWRITEI(const mlaskal::abstract_instr *) {
		return new ai::FNCWRITEI();
	}

	static mlaskal::abstract_instr *aifcl_FNCWRITELN(const mlaskal::abstract_instr *) {
		return new ai::FNCWRITELN();
	}

	static mlaskal::abstract_instr *aifcl_FNCWRITER(const mlaskal::abstract_instr *) {
		return new ai::FNCWRITER();
	}

	static mlaskal::abstract_instr *aifcl_FNCWRITES(const mlaskal::abstract_instr *) {
		return new ai::FNCWRITES();
	}

	static mlaskal::abstract_instr *aifcl_GEB(const mlaskal::abstract_instr *) {
		return new ai::GEB();
	}

	static mlaskal::abstract_instr *aifcl_GEI(const mlaskal::abstract_instr *) {
		return new ai::GEI();
	}

	static mlaskal::abstract_instr *aifcl_GELDB(const mlaskal::abstract_instr *oldai) {
		return new ai::GELDB(oldai->get_out(), oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_GELDI(const mlaskal::abstract_instr *oldai) {
		return new ai::GELDI(oldai->get_out(), oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_GELDR(const mlaskal::abstract_instr *oldai) {
		return new ai::GELDR(oldai->get_out(), oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_GELDS(const mlaskal::abstract_instr *oldai) {
		return new ai::GELDS(oldai->get_out(), oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_GER(const mlaskal::abstract_instr *) {
		return new ai::GER();
	}

	static mlaskal::abstract_instr *aifcl_GEREF(const mlaskal::abstract_instr *oldai) {
		return new ai::GEREF(oldai->get_out(), oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_GES(const mlaskal::abstract_instr *) {
		return new ai::GES();
	}

	static mlaskal::abstract_instr *aifcl_GESTB(const mlaskal::abstract_instr *oldai) {
		return new ai::GESTB(oldai->get_stkoffs(), oldai->get_in1());
	}

	static mlaskal::abstract_instr *aifcl_GESTI(const mlaskal::abstract_instr *oldai) {
		return new ai::GESTI(oldai->get_stkoffs(), oldai->get_in1());
	}

	static mlaskal::abstract_instr *aifcl_GESTR(const mlaskal::abstract_instr *oldai) {
		return new ai::GESTR(oldai->get_stkoffs(), oldai->get_in1());
	}

	static mlaskal::abstract_instr *aifcl_GESTS(const mlaskal::abstract_instr *oldai) {
		return new ai::GESTS(oldai->get_stkoffs(), oldai->get_in1());
	}

	static mlaskal::abstract_instr *aifcl_GLDB(const mlaskal::abstract_instr *oldai) {
		return new ai::GLDB(oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_GLDI(const mlaskal::abstract_instr *oldai) {
		return new ai::GLDI(oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_GLDR(const mlaskal::abstract_instr *oldai) {
		return new ai::GLDR(oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_GLDS(const mlaskal::abstract_instr *oldai) {
		return new ai::GLDS(oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_GREF(const mlaskal::abstract_instr *oldai) {
		return new ai::GREF(oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_GSTB(const mlaskal::abstract_instr *oldai) {
		return new ai::GSTB(oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_GSTI(const mlaskal::abstract_instr *oldai) {
		return new ai::GSTI(oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_GSTR(const mlaskal::abstract_instr *oldai) {
		return new ai::GSTR(oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_GSTS(const mlaskal::abstract_instr *oldai) {
		return new ai::GSTS(oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_GTB(const mlaskal::abstract_instr *) {
		return new ai::GTB();
	}

	static mlaskal::abstract_instr *aifcl_GTI(const mlaskal::abstract_instr *) {
		return new ai::GTI();
	}

	static mlaskal::abstract_instr *aifcl_GTR(const mlaskal::abstract_instr *) {
		return new ai::GTR();
	}

	static mlaskal::abstract_instr *aifcl_GTS(const mlaskal::abstract_instr *) {
		return new ai::GTS();
	}

	static mlaskal::abstract_instr *aifcl_HALT(const mlaskal::abstract_instr *) {
		return new ai::HALT();
	}

	static mlaskal::abstract_instr *aifcl_INITB(const mlaskal::abstract_instr *) {
		return new ai::INITB();
	}

	static mlaskal::abstract_instr *aifcl_INITI(const mlaskal::abstract_instr *) {
		return new ai::INITI();
	}

	static mlaskal::abstract_instr *aifcl_INITR(const mlaskal::abstract_instr *) {
		return new ai::INITR();
	}

	static mlaskal::abstract_instr *aifcl_INITS(const mlaskal::abstract_instr *) {
		return new ai::INITS();
	}

	static mlaskal::abstract_instr *aifcl_JEF(const mlaskal::abstract_instr *oldai) {
		return new ai::JEF(oldai->get_reljump(), oldai->get_in1());
	}

	static mlaskal::abstract_instr *aifcl_JET(const mlaskal::abstract_instr *oldai) {
		return new ai::JET(oldai->get_reljump(), oldai->get_in1());
	}

	static mlaskal::abstract_instr *aifcl_JF(const mlaskal::abstract_instr *oldai) {
		return new ai::JF(oldai->get_reljump());
	}

	static mlaskal::abstract_instr *aifcl_JMP(const mlaskal::abstract_instr *oldai) {
		return new ai::JMP(oldai->get_reljump());
	}

	static mlaskal::abstract_instr *aifcl_JT(const mlaskal::abstract_instr *oldai) {
		return new ai::JT(oldai->get_reljump());
	}

	static mlaskal::abstract_instr *aifcl_LDLITB(const mlaskal::abstract_instr *oldai) {
		return new ai::LDLITB(oldai->get_absnum());
	}

	static mlaskal::abstract_instr *aifcl_LDLITI(const mlaskal::abstract_instr *oldai) {
		return new ai::LDLITI(oldai->get_litint());
	}

	static mlaskal::abstract_instr *aifcl_LDLITR(const mlaskal::abstract_instr *oldai) {
		return new ai::LDLITR(oldai->get_litreal());
	}

	static mlaskal::abstract_instr *aifcl_LDLITS(const mlaskal::abstract_instr *oldai) {
		return new ai::LDLITS(oldai->get_litstr());
	}

	static mlaskal::abstract_instr *aifcl_LEB(const mlaskal::abstract_instr *) {
		return new ai::LEB();
	}

	static mlaskal::abstract_instr *aifcl_LEI(const mlaskal::abstract_instr *) {
		return new ai::LEI();
	}

	static mlaskal::abstract_instr *aifcl_LELDB(const mlaskal::abstract_instr *oldai) {
		return new ai::LELDB(oldai->get_out(), oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_LELDI(const mlaskal::abstract_instr *oldai) {
		return new ai::LELDI(oldai->get_out(), oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_LELDP(const mlaskal::abstract_instr *oldai) {
		return new ai::LELDP(oldai->get_out(), oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_LELDR(const mlaskal::abstract_instr *oldai) {
		return new ai::LELDR(oldai->get_out(), oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_LELDS(const mlaskal::abstract_instr *oldai) {
		return new ai::LELDS(oldai->get_out(), oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_LER(const mlaskal::abstract_instr *) {
		return new ai::LER();
	}

	static mlaskal::abstract_instr *aifcl_LEREF(const mlaskal::abstract_instr *oldai) {
		return new ai::LEREF(oldai->get_out(), oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_LES(const mlaskal::abstract_instr *) {
		return new ai::LES();
	}

	static mlaskal::abstract_instr *aifcl_LESTB(const mlaskal::abstract_instr *oldai) {
		return new ai::LESTB(oldai->get_stkoffs(), oldai->get_in1());
	}

	static mlaskal::abstract_instr *aifcl_LESTI(const mlaskal::abstract_instr *oldai) {
		return new ai::LESTI(oldai->get_stkoffs(), oldai->get_in1());
	}

	static mlaskal::abstract_instr *aifcl_LESTP(const mlaskal::abstract_instr *oldai) {
		return new ai::LESTP(oldai->get_stkoffs(), oldai->get_in1());
	}

	static mlaskal::abstract_instr *aifcl_LESTR(const mlaskal::abstract_instr *oldai) {
		return new ai::LESTR(oldai->get_stkoffs(), oldai->get_in1());
	}

	static mlaskal::abstract_instr *aifcl_LESTS(const mlaskal::abstract_instr *oldai) {
		return new ai::LESTS(oldai->get_stkoffs(), oldai->get_in1());
	}

	static mlaskal::abstract_instr *aifcl_LLDB(const mlaskal::abstract_instr *oldai) {
		return new ai::LLDB(oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_LLDI(const mlaskal::abstract_instr *oldai) {
		return new ai::LLDI(oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_LLDP(const mlaskal::abstract_instr *oldai) {
		return new ai::LLDP(oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_LLDR(const mlaskal::abstract_instr *oldai) {
		return new ai::LLDR(oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_LLDS(const mlaskal::abstract_instr *oldai) {
		return new ai::LLDS(oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_LREF(const mlaskal::abstract_instr *oldai) {
		return new ai::LREF(oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_LSTB(const mlaskal::abstract_instr *oldai) {
		return new ai::LSTB(oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_LSTI(const mlaskal::abstract_instr *oldai) {
		return new ai::LSTI(oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_LSTR(const mlaskal::abstract_instr *oldai) {
		return new ai::LSTR(oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_LSTS(const mlaskal::abstract_instr *oldai) {
		return new ai::LSTS(oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_LTB(const mlaskal::abstract_instr *) {
		return new ai::LTB();
	}

	static mlaskal::abstract_instr *aifcl_LTI(const mlaskal::abstract_instr *) {
		return new ai::LTI();
	}

	static mlaskal::abstract_instr *aifcl_LTR(const mlaskal::abstract_instr *) {
		return new ai::LTR();
	}

	static mlaskal::abstract_instr *aifcl_LTS(const mlaskal::abstract_instr *) {
		return new ai::LTS();
	}

	static mlaskal::abstract_instr *aifcl_MINUSI(const mlaskal::abstract_instr *) {
		return new ai::MINUSI();
	}

	static mlaskal::abstract_instr *aifcl_MINUSR(const mlaskal::abstract_instr *) {
		return new ai::MINUSR();
	}

	static mlaskal::abstract_instr *aifcl_MODI(const mlaskal::abstract_instr *) {
		return new ai::MODI();
	}

	static mlaskal::abstract_instr *aifcl_MULI(const mlaskal::abstract_instr *) {
		return new ai::MULI();
	}

	static mlaskal::abstract_instr *aifcl_MULR(const mlaskal::abstract_instr *) {
		return new ai::MULR();
	}

	static mlaskal::abstract_instr *aifcl_NEB(const mlaskal::abstract_instr *) {
		return new ai::NEB();
	}

	static mlaskal::abstract_instr *aifcl_NEI(const mlaskal::abstract_instr *) {
		return new ai::NEI();
	}

	static mlaskal::abstract_instr *aifcl_NER(const mlaskal::abstract_instr *) {
		return new ai::NER();
	}

	static mlaskal::abstract_instr *aifcl_NES(const mlaskal::abstract_instr *) {
		return new ai::NES();
	}

	static mlaskal::abstract_instr *aifcl_NOP(const mlaskal::abstract_instr *) {
		return new ai::NOP();
	}

	static mlaskal::abstract_instr *aifcl_NOT(const mlaskal::abstract_instr *) {
		return new ai::NOT();
	}

	static mlaskal::abstract_instr *aifcl_OR(const mlaskal::abstract_instr *) {
		return new ai::OR();
	}

	static mlaskal::abstract_instr *aifcl_RET(const mlaskal::abstract_instr *) {
		return new ai::RET();
	}

	static mlaskal::abstract_instr *aifcl_SADD(const mlaskal::abstract_instr *oldai) {
		return new ai::SADD(oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_SLDB(const mlaskal::abstract_instr *oldai) {
		return new ai::SLDB(oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_SLDI(const mlaskal::abstract_instr *oldai) {
		return new ai::SLDI(oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_SLDP(const mlaskal::abstract_instr *oldai) {
		return new ai::SLDP(oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_SLDR(const mlaskal::abstract_instr *oldai) {
		return new ai::SLDR(oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_SLDS(const mlaskal::abstract_instr *oldai) {
		return new ai::SLDS(oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_SREF(const mlaskal::abstract_instr *oldai) {
		return new ai::SREF(oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_SSTB(const mlaskal::abstract_instr *oldai) {
		return new ai::SSTB(oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_SSTI(const mlaskal::abstract_instr *oldai) {
		return new ai::SSTI(oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_SSTP(const mlaskal::abstract_instr *oldai) {
		return new ai::SSTP(oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_SSTR(const mlaskal::abstract_instr *oldai) {
		return new ai::SSTR(oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_SSTS(const mlaskal::abstract_instr *oldai) {
		return new ai::SSTS(oldai->get_stkoffs());
	}

	static mlaskal::abstract_instr *aifcl_SUBI(const mlaskal::abstract_instr *) {
		return new ai::SUBI();
	}

	static mlaskal::abstract_instr *aifcl_SUBP(const mlaskal::abstract_instr *) {
		return new ai::SUBP();
	}

	static mlaskal::abstract_instr *aifcl_SUBR(const mlaskal::abstract_instr *) {
		return new ai::SUBR();
	}

	static mlaskal::abstract_instr *aifcl_XELDB(const mlaskal::abstract_instr *oldai) {
		return new ai::XELDB(oldai->get_out(), oldai->get_in1());
	}

	static mlaskal::abstract_instr *aifcl_XELDI(const mlaskal::abstract_instr *oldai) {
		return new ai::XELDI(oldai->get_out(), oldai->get_in1());
	}

	static mlaskal::abstract_instr *aifcl_XELDR(const mlaskal::abstract_instr *oldai) {
		return new ai::XELDR(oldai->get_out(), oldai->get_in1());
	}

	static mlaskal::abstract_instr *aifcl_XELDS(const mlaskal::abstract_instr *oldai) {
		return new ai::XELDS(oldai->get_out(), oldai->get_in1());
	}

	static mlaskal::abstract_instr *aifcl_XESTB(const mlaskal::abstract_instr *oldai) {
		return new ai::XESTB(oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_XESTI(const mlaskal::abstract_instr *oldai) {
		return new ai::XESTI(oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_XESTR(const mlaskal::abstract_instr *oldai) {
		return new ai::XESTR(oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_XESTS(const mlaskal::abstract_instr *oldai) {
		return new ai::XESTS(oldai->get_in1(), oldai->get_in2());
	}

	static mlaskal::abstract_instr *aifcl_XLDB(const mlaskal::abstract_instr *) {
		return new ai::XLDB();
	}

	static mlaskal::abstract_instr *aifcl_XLDI(const mlaskal::abstract_instr *) {
		return new ai::XLDI();
	}

	static mlaskal::abstract_instr *aifcl_XLDR(const mlaskal::abstract_instr *) {
		return new ai::XLDR();
	}

	static mlaskal::abstract_instr *aifcl_XLDS(const mlaskal::abstract_instr *) {
		return new ai::XLDS();
	}

	static mlaskal::abstract_instr *aifcl_XSTB(const mlaskal::abstract_instr *) {
		return new ai::XSTB();
	}

	static mlaskal::abstract_instr *aifcl_XSTI(const mlaskal::abstract_instr *) {
		return new ai::XSTI();
	}

	static mlaskal::abstract_instr *aifcl_XSTR(const mlaskal::abstract_instr *) {
		return new ai::XSTR();
	}

	static mlaskal::abstract_instr *aifcl_XSTS(const mlaskal::abstract_instr *) {
		return new ai::XSTS();
	}

}

namespace mlaskal {

ai_factory_creator_type ai_factory::creators_[ai::ICOP_DNOTUSE_MAX_]={
	aifcr_int_::aifcr_ADDI,
	aifcr_int_::aifcr_ADDP,
	aifcr_int_::aifcr_ADDR,
	aifcr_int_::aifcr_ADDS,
	aifcr_int_::aifcr_AND,
	aifcr_int_::aifcr_CALL,
	aifcr_int_::aifcr_CVRTIR,
	aifcr_int_::aifcr_CVRTRI,
	aifcr_int_::aifcr_DIVI,
	aifcr_int_::aifcr_DIVR,
	aifcr_int_::aifcr_DTORB,
	aifcr_int_::aifcr_DTORI,
	aifcr_int_::aifcr_DTORP,
	aifcr_int_::aifcr_DTORR,
	aifcr_int_::aifcr_DTORS,
	aifcr_int_::aifcr_EADDI,
	aifcr_int_::aifcr_EADDP,
	aifcr_int_::aifcr_EADDR,
	aifcr_int_::aifcr_EADDS,
	aifcr_int_::aifcr_EAND,
	aifcr_int_::aifcr_ECVRTIR,
	aifcr_int_::aifcr_ECVRTRI,
	aifcr_int_::aifcr_EDIVI,
	aifcr_int_::aifcr_EDIVR,
	aifcr_int_::aifcr_EEQB,
	aifcr_int_::aifcr_EEQI,
	aifcr_int_::aifcr_EEQR,
	aifcr_int_::aifcr_EEQS,
	aifcr_int_::aifcr_EGEB,
	aifcr_int_::aifcr_EGEI,
	aifcr_int_::aifcr_EGER,
	aifcr_int_::aifcr_EGES,
	aifcr_int_::aifcr_EGTB,
	aifcr_int_::aifcr_EGTI,
	aifcr_int_::aifcr_EGTR,
	aifcr_int_::aifcr_EGTS,
	aifcr_int_::aifcr_EINITB,
	aifcr_int_::aifcr_EINITI,
	aifcr_int_::aifcr_EINITR,
	aifcr_int_::aifcr_EINITS,
	aifcr_int_::aifcr_ELDLITB,
	aifcr_int_::aifcr_ELDLITI,
	aifcr_int_::aifcr_ELDLITR,
	aifcr_int_::aifcr_ELDLITS,
	aifcr_int_::aifcr_ELEB,
	aifcr_int_::aifcr_ELEI,
	aifcr_int_::aifcr_ELER,
	aifcr_int_::aifcr_ELES,
	aifcr_int_::aifcr_ELTB,
	aifcr_int_::aifcr_ELTI,
	aifcr_int_::aifcr_ELTR,
	aifcr_int_::aifcr_ELTS,
	aifcr_int_::aifcr_EMINUSI,
	aifcr_int_::aifcr_EMINUSR,
	aifcr_int_::aifcr_EMODI,
	aifcr_int_::aifcr_EMOVB,
	aifcr_int_::aifcr_EMOVI,
	aifcr_int_::aifcr_EMOVP,
	aifcr_int_::aifcr_EMOVR,
	aifcr_int_::aifcr_EMOVS,
	aifcr_int_::aifcr_EMULI,
	aifcr_int_::aifcr_EMULR,
	aifcr_int_::aifcr_ENEB,
	aifcr_int_::aifcr_ENEI,
	aifcr_int_::aifcr_ENER,
	aifcr_int_::aifcr_ENES,
	aifcr_int_::aifcr_ENOT,
	aifcr_int_::aifcr_EOR,
	aifcr_int_::aifcr_EPOP,
	aifcr_int_::aifcr_EPOPB,
	aifcr_int_::aifcr_EPOPI,
	aifcr_int_::aifcr_EPOPP,
	aifcr_int_::aifcr_EPOPR,
	aifcr_int_::aifcr_EPOPS,
	aifcr_int_::aifcr_EPUSH,
	aifcr_int_::aifcr_EPUSHB,
	aifcr_int_::aifcr_EPUSHI,
	aifcr_int_::aifcr_EPUSHP,
	aifcr_int_::aifcr_EPUSHR,
	aifcr_int_::aifcr_EPUSHS,
	aifcr_int_::aifcr_EQB,
	aifcr_int_::aifcr_EQI,
	aifcr_int_::aifcr_EQR,
	aifcr_int_::aifcr_EQS,
	aifcr_int_::aifcr_ESUBI,
	aifcr_int_::aifcr_ESUBP,
	aifcr_int_::aifcr_ESUBR,
	aifcr_int_::aifcr_FNCREADI,
	aifcr_int_::aifcr_FNCREADR,
	aifcr_int_::aifcr_FNCREADS,
	aifcr_int_::aifcr_FNCWRITEI,
	aifcr_int_::aifcr_FNCWRITELN,
	aifcr_int_::aifcr_FNCWRITER,
	aifcr_int_::aifcr_FNCWRITES,
	aifcr_int_::aifcr_GEB,
	aifcr_int_::aifcr_GEI,
	aifcr_int_::aifcr_GELDB,
	aifcr_int_::aifcr_GELDI,
	aifcr_int_::aifcr_GELDR,
	aifcr_int_::aifcr_GELDS,
	aifcr_int_::aifcr_GER,
	aifcr_int_::aifcr_GEREF,
	aifcr_int_::aifcr_GES,
	aifcr_int_::aifcr_GESTB,
	aifcr_int_::aifcr_GESTI,
	aifcr_int_::aifcr_GESTR,
	aifcr_int_::aifcr_GESTS,
	aifcr_int_::aifcr_GLDB,
	aifcr_int_::aifcr_GLDI,
	aifcr_int_::aifcr_GLDR,
	aifcr_int_::aifcr_GLDS,
	aifcr_int_::aifcr_GREF,
	aifcr_int_::aifcr_GSTB,
	aifcr_int_::aifcr_GSTI,
	aifcr_int_::aifcr_GSTR,
	aifcr_int_::aifcr_GSTS,
	aifcr_int_::aifcr_GTB,
	aifcr_int_::aifcr_GTI,
	aifcr_int_::aifcr_GTR,
	aifcr_int_::aifcr_GTS,
	aifcr_int_::aifcr_HALT,
	aifcr_int_::aifcr_INITB,
	aifcr_int_::aifcr_INITI,
	aifcr_int_::aifcr_INITR,
	aifcr_int_::aifcr_INITS,
	aifcr_int_::aifcr_JEF,
	aifcr_int_::aifcr_JET,
	aifcr_int_::aifcr_JF,
	aifcr_int_::aifcr_JMP,
	aifcr_int_::aifcr_JT,
	aifcr_int_::aifcr_LDLITB,
	aifcr_int_::aifcr_LDLITI,
	aifcr_int_::aifcr_LDLITR,
	aifcr_int_::aifcr_LDLITS,
	aifcr_int_::aifcr_LEB,
	aifcr_int_::aifcr_LEI,
	aifcr_int_::aifcr_LELDB,
	aifcr_int_::aifcr_LELDI,
	aifcr_int_::aifcr_LELDP,
	aifcr_int_::aifcr_LELDR,
	aifcr_int_::aifcr_LELDS,
	aifcr_int_::aifcr_LER,
	aifcr_int_::aifcr_LEREF,
	aifcr_int_::aifcr_LES,
	aifcr_int_::aifcr_LESTB,
	aifcr_int_::aifcr_LESTI,
	aifcr_int_::aifcr_LESTP,
	aifcr_int_::aifcr_LESTR,
	aifcr_int_::aifcr_LESTS,
	aifcr_int_::aifcr_LLDB,
	aifcr_int_::aifcr_LLDI,
	aifcr_int_::aifcr_LLDP,
	aifcr_int_::aifcr_LLDR,
	aifcr_int_::aifcr_LLDS,
	aifcr_int_::aifcr_LREF,
	aifcr_int_::aifcr_LSTB,
	aifcr_int_::aifcr_LSTI,
	aifcr_int_::aifcr_LSTR,
	aifcr_int_::aifcr_LSTS,
	aifcr_int_::aifcr_LTB,
	aifcr_int_::aifcr_LTI,
	aifcr_int_::aifcr_LTR,
	aifcr_int_::aifcr_LTS,
	aifcr_int_::aifcr_MINUSI,
	aifcr_int_::aifcr_MINUSR,
	aifcr_int_::aifcr_MODI,
	aifcr_int_::aifcr_MULI,
	aifcr_int_::aifcr_MULR,
	aifcr_int_::aifcr_NEB,
	aifcr_int_::aifcr_NEI,
	aifcr_int_::aifcr_NER,
	aifcr_int_::aifcr_NES,
	aifcr_int_::aifcr_NOP,
	aifcr_int_::aifcr_NOT,
	aifcr_int_::aifcr_OR,
	aifcr_int_::aifcr_RET,
	aifcr_int_::aifcr_SADD,
	aifcr_int_::aifcr_SLDB,
	aifcr_int_::aifcr_SLDI,
	aifcr_int_::aifcr_SLDP,
	aifcr_int_::aifcr_SLDR,
	aifcr_int_::aifcr_SLDS,
	aifcr_int_::aifcr_SREF,
	aifcr_int_::aifcr_SSTB,
	aifcr_int_::aifcr_SSTI,
	aifcr_int_::aifcr_SSTP,
	aifcr_int_::aifcr_SSTR,
	aifcr_int_::aifcr_SSTS,
	aifcr_int_::aifcr_SUBI,
	aifcr_int_::aifcr_SUBP,
	aifcr_int_::aifcr_SUBR,
	aifcr_int_::aifcr_XELDB,
	aifcr_int_::aifcr_XELDI,
	aifcr_int_::aifcr_XELDR,
	aifcr_int_::aifcr_XELDS,
	aifcr_int_::aifcr_XESTB,
	aifcr_int_::aifcr_XESTI,
	aifcr_int_::aifcr_XESTR,
	aifcr_int_::aifcr_XESTS,
	aifcr_int_::aifcr_XLDB,
	aifcr_int_::aifcr_XLDI,
	aifcr_int_::aifcr_XLDR,
	aifcr_int_::aifcr_XLDS,
	aifcr_int_::aifcr_XSTB,
	aifcr_int_::aifcr_XSTI,
	aifcr_int_::aifcr_XSTR,
	aifcr_int_::aifcr_XSTS,
};

ai_factory_cloner_type ai_factory::cloners_[ai::ICOP_DNOTUSE_MAX_]={
	aifcl_int_::aifcl_ADDI,
	aifcl_int_::aifcl_ADDP,
	aifcl_int_::aifcl_ADDR,
	aifcl_int_::aifcl_ADDS,
	aifcl_int_::aifcl_AND,
	aifcl_int_::aifcl_CALL,
	aifcl_int_::aifcl_CVRTIR,
	aifcl_int_::aifcl_CVRTRI,
	aifcl_int_::aifcl_DIVI,
	aifcl_int_::aifcl_DIVR,
	aifcl_int_::aifcl_DTORB,
	aifcl_int_::aifcl_DTORI,
	aifcl_int_::aifcl_DTORP,
	aifcl_int_::aifcl_DTORR,
	aifcl_int_::aifcl_DTORS,
	aifcl_int_::aifcl_EADDI,
	aifcl_int_::aifcl_EADDP,
	aifcl_int_::aifcl_EADDR,
	aifcl_int_::aifcl_EADDS,
	aifcl_int_::aifcl_EAND,
	aifcl_int_::aifcl_ECVRTIR,
	aifcl_int_::aifcl_ECVRTRI,
	aifcl_int_::aifcl_EDIVI,
	aifcl_int_::aifcl_EDIVR,
	aifcl_int_::aifcl_EEQB,
	aifcl_int_::aifcl_EEQI,
	aifcl_int_::aifcl_EEQR,
	aifcl_int_::aifcl_EEQS,
	aifcl_int_::aifcl_EGEB,
	aifcl_int_::aifcl_EGEI,
	aifcl_int_::aifcl_EGER,
	aifcl_int_::aifcl_EGES,
	aifcl_int_::aifcl_EGTB,
	aifcl_int_::aifcl_EGTI,
	aifcl_int_::aifcl_EGTR,
	aifcl_int_::aifcl_EGTS,
	aifcl_int_::aifcl_EINITB,
	aifcl_int_::aifcl_EINITI,
	aifcl_int_::aifcl_EINITR,
	aifcl_int_::aifcl_EINITS,
	aifcl_int_::aifcl_ELDLITB,
	aifcl_int_::aifcl_ELDLITI,
	aifcl_int_::aifcl_ELDLITR,
	aifcl_int_::aifcl_ELDLITS,
	aifcl_int_::aifcl_ELEB,
	aifcl_int_::aifcl_ELEI,
	aifcl_int_::aifcl_ELER,
	aifcl_int_::aifcl_ELES,
	aifcl_int_::aifcl_ELTB,
	aifcl_int_::aifcl_ELTI,
	aifcl_int_::aifcl_ELTR,
	aifcl_int_::aifcl_ELTS,
	aifcl_int_::aifcl_EMINUSI,
	aifcl_int_::aifcl_EMINUSR,
	aifcl_int_::aifcl_EMODI,
	aifcl_int_::aifcl_EMOVB,
	aifcl_int_::aifcl_EMOVI,
	aifcl_int_::aifcl_EMOVP,
	aifcl_int_::aifcl_EMOVR,
	aifcl_int_::aifcl_EMOVS,
	aifcl_int_::aifcl_EMULI,
	aifcl_int_::aifcl_EMULR,
	aifcl_int_::aifcl_ENEB,
	aifcl_int_::aifcl_ENEI,
	aifcl_int_::aifcl_ENER,
	aifcl_int_::aifcl_ENES,
	aifcl_int_::aifcl_ENOT,
	aifcl_int_::aifcl_EOR,
	aifcl_int_::aifcl_EPOP,
	aifcl_int_::aifcl_EPOPB,
	aifcl_int_::aifcl_EPOPI,
	aifcl_int_::aifcl_EPOPP,
	aifcl_int_::aifcl_EPOPR,
	aifcl_int_::aifcl_EPOPS,
	aifcl_int_::aifcl_EPUSH,
	aifcl_int_::aifcl_EPUSHB,
	aifcl_int_::aifcl_EPUSHI,
	aifcl_int_::aifcl_EPUSHP,
	aifcl_int_::aifcl_EPUSHR,
	aifcl_int_::aifcl_EPUSHS,
	aifcl_int_::aifcl_EQB,
	aifcl_int_::aifcl_EQI,
	aifcl_int_::aifcl_EQR,
	aifcl_int_::aifcl_EQS,
	aifcl_int_::aifcl_ESUBI,
	aifcl_int_::aifcl_ESUBP,
	aifcl_int_::aifcl_ESUBR,
	aifcl_int_::aifcl_FNCREADI,
	aifcl_int_::aifcl_FNCREADR,
	aifcl_int_::aifcl_FNCREADS,
	aifcl_int_::aifcl_FNCWRITEI,
	aifcl_int_::aifcl_FNCWRITELN,
	aifcl_int_::aifcl_FNCWRITER,
	aifcl_int_::aifcl_FNCWRITES,
	aifcl_int_::aifcl_GEB,
	aifcl_int_::aifcl_GEI,
	aifcl_int_::aifcl_GELDB,
	aifcl_int_::aifcl_GELDI,
	aifcl_int_::aifcl_GELDR,
	aifcl_int_::aifcl_GELDS,
	aifcl_int_::aifcl_GER,
	aifcl_int_::aifcl_GEREF,
	aifcl_int_::aifcl_GES,
	aifcl_int_::aifcl_GESTB,
	aifcl_int_::aifcl_GESTI,
	aifcl_int_::aifcl_GESTR,
	aifcl_int_::aifcl_GESTS,
	aifcl_int_::aifcl_GLDB,
	aifcl_int_::aifcl_GLDI,
	aifcl_int_::aifcl_GLDR,
	aifcl_int_::aifcl_GLDS,
	aifcl_int_::aifcl_GREF,
	aifcl_int_::aifcl_GSTB,
	aifcl_int_::aifcl_GSTI,
	aifcl_int_::aifcl_GSTR,
	aifcl_int_::aifcl_GSTS,
	aifcl_int_::aifcl_GTB,
	aifcl_int_::aifcl_GTI,
	aifcl_int_::aifcl_GTR,
	aifcl_int_::aifcl_GTS,
	aifcl_int_::aifcl_HALT,
	aifcl_int_::aifcl_INITB,
	aifcl_int_::aifcl_INITI,
	aifcl_int_::aifcl_INITR,
	aifcl_int_::aifcl_INITS,
	aifcl_int_::aifcl_JEF,
	aifcl_int_::aifcl_JET,
	aifcl_int_::aifcl_JF,
	aifcl_int_::aifcl_JMP,
	aifcl_int_::aifcl_JT,
	aifcl_int_::aifcl_LDLITB,
	aifcl_int_::aifcl_LDLITI,
	aifcl_int_::aifcl_LDLITR,
	aifcl_int_::aifcl_LDLITS,
	aifcl_int_::aifcl_LEB,
	aifcl_int_::aifcl_LEI,
	aifcl_int_::aifcl_LELDB,
	aifcl_int_::aifcl_LELDI,
	aifcl_int_::aifcl_LELDP,
	aifcl_int_::aifcl_LELDR,
	aifcl_int_::aifcl_LELDS,
	aifcl_int_::aifcl_LER,
	aifcl_int_::aifcl_LEREF,
	aifcl_int_::aifcl_LES,
	aifcl_int_::aifcl_LESTB,
	aifcl_int_::aifcl_LESTI,
	aifcl_int_::aifcl_LESTP,
	aifcl_int_::aifcl_LESTR,
	aifcl_int_::aifcl_LESTS,
	aifcl_int_::aifcl_LLDB,
	aifcl_int_::aifcl_LLDI,
	aifcl_int_::aifcl_LLDP,
	aifcl_int_::aifcl_LLDR,
	aifcl_int_::aifcl_LLDS,
	aifcl_int_::aifcl_LREF,
	aifcl_int_::aifcl_LSTB,
	aifcl_int_::aifcl_LSTI,
	aifcl_int_::aifcl_LSTR,
	aifcl_int_::aifcl_LSTS,
	aifcl_int_::aifcl_LTB,
	aifcl_int_::aifcl_LTI,
	aifcl_int_::aifcl_LTR,
	aifcl_int_::aifcl_LTS,
	aifcl_int_::aifcl_MINUSI,
	aifcl_int_::aifcl_MINUSR,
	aifcl_int_::aifcl_MODI,
	aifcl_int_::aifcl_MULI,
	aifcl_int_::aifcl_MULR,
	aifcl_int_::aifcl_NEB,
	aifcl_int_::aifcl_NEI,
	aifcl_int_::aifcl_NER,
	aifcl_int_::aifcl_NES,
	aifcl_int_::aifcl_NOP,
	aifcl_int_::aifcl_NOT,
	aifcl_int_::aifcl_OR,
	aifcl_int_::aifcl_RET,
	aifcl_int_::aifcl_SADD,
	aifcl_int_::aifcl_SLDB,
	aifcl_int_::aifcl_SLDI,
	aifcl_int_::aifcl_SLDP,
	aifcl_int_::aifcl_SLDR,
	aifcl_int_::aifcl_SLDS,
	aifcl_int_::aifcl_SREF,
	aifcl_int_::aifcl_SSTB,
	aifcl_int_::aifcl_SSTI,
	aifcl_int_::aifcl_SSTP,
	aifcl_int_::aifcl_SSTR,
	aifcl_int_::aifcl_SSTS,
	aifcl_int_::aifcl_SUBI,
	aifcl_int_::aifcl_SUBP,
	aifcl_int_::aifcl_SUBR,
	aifcl_int_::aifcl_XELDB,
	aifcl_int_::aifcl_XELDI,
	aifcl_int_::aifcl_XELDR,
	aifcl_int_::aifcl_XELDS,
	aifcl_int_::aifcl_XESTB,
	aifcl_int_::aifcl_XESTI,
	aifcl_int_::aifcl_XESTR,
	aifcl_int_::aifcl_XESTS,
	aifcl_int_::aifcl_XLDB,
	aifcl_int_::aifcl_XLDI,
	aifcl_int_::aifcl_XLDR,
	aifcl_int_::aifcl_XLDS,
	aifcl_int_::aifcl_XSTB,
	aifcl_int_::aifcl_XSTI,
	aifcl_int_::aifcl_XSTR,
	aifcl_int_::aifcl_XSTS,
};

}
