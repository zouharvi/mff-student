/*
	GEN_AINSTR.HPP

	GENERATED, DO NOT MODIFY!!!!
*/
#ifndef GEN_AINSTR_HPP_
#define GEN_AINSTR_HPP_

#include "abstract_instr.hpp"

namespace ai {

	class ADDI;
	class ADDP;
	class ADDR;
	class ADDS;
	class AND;
	class CALL;
	class CVRTIR;
	class CVRTRI;
	class DIVI;
	class DIVR;
	class DTORB;
	class DTORI;
	class DTORP;
	class DTORR;
	class DTORS;
	class EADDI;
	class EADDP;
	class EADDR;
	class EADDS;
	class EAND;
	class ECVRTIR;
	class ECVRTRI;
	class EDIVI;
	class EDIVR;
	class EEQB;
	class EEQI;
	class EEQR;
	class EEQS;
	class EGEB;
	class EGEI;
	class EGER;
	class EGES;
	class EGTB;
	class EGTI;
	class EGTR;
	class EGTS;
	class EINITB;
	class EINITI;
	class EINITR;
	class EINITS;
	class ELDLITB;
	class ELDLITI;
	class ELDLITR;
	class ELDLITS;
	class ELEB;
	class ELEI;
	class ELER;
	class ELES;
	class ELTB;
	class ELTI;
	class ELTR;
	class ELTS;
	class EMINUSI;
	class EMINUSR;
	class EMODI;
	class EMOVB;
	class EMOVI;
	class EMOVP;
	class EMOVR;
	class EMOVS;
	class EMULI;
	class EMULR;
	class ENEB;
	class ENEI;
	class ENER;
	class ENES;
	class ENOT;
	class EOR;
	class EPOP;
	class EPOPB;
	class EPOPI;
	class EPOPP;
	class EPOPR;
	class EPOPS;
	class EPUSH;
	class EPUSHB;
	class EPUSHI;
	class EPUSHP;
	class EPUSHR;
	class EPUSHS;
	class EQB;
	class EQI;
	class EQR;
	class EQS;
	class ESUBI;
	class ESUBP;
	class ESUBR;
	class FNCREADI;
	class FNCREADR;
	class FNCREADS;
	class FNCWRITEI;
	class FNCWRITELN;
	class FNCWRITER;
	class FNCWRITES;
	class GEB;
	class GEI;
	class GELDB;
	class GELDI;
	class GELDR;
	class GELDS;
	class GER;
	class GEREF;
	class GES;
	class GESTB;
	class GESTI;
	class GESTR;
	class GESTS;
	class GLDB;
	class GLDI;
	class GLDR;
	class GLDS;
	class GREF;
	class GSTB;
	class GSTI;
	class GSTR;
	class GSTS;
	class GTB;
	class GTI;
	class GTR;
	class GTS;
	class HALT;
	class INITB;
	class INITI;
	class INITR;
	class INITS;
	class JEF;
	class JET;
	class JF;
	class JMP;
	class JT;
	class LDLITB;
	class LDLITI;
	class LDLITR;
	class LDLITS;
	class LEB;
	class LEI;
	class LELDB;
	class LELDI;
	class LELDP;
	class LELDR;
	class LELDS;
	class LER;
	class LEREF;
	class LES;
	class LESTB;
	class LESTI;
	class LESTP;
	class LESTR;
	class LESTS;
	class LLDB;
	class LLDI;
	class LLDP;
	class LLDR;
	class LLDS;
	class LREF;
	class LSTB;
	class LSTI;
	class LSTR;
	class LSTS;
	class LTB;
	class LTI;
	class LTR;
	class LTS;
	class MINUSI;
	class MINUSR;
	class MODI;
	class MULI;
	class MULR;
	class NEB;
	class NEI;
	class NER;
	class NES;
	class NOP;
	class NOT;
	class OR;
	class RET;
	class SADD;
	class SLDB;
	class SLDI;
	class SLDP;
	class SLDR;
	class SLDS;
	class SREF;
	class SSTB;
	class SSTI;
	class SSTP;
	class SSTR;
	class SSTS;
	class SUBI;
	class SUBP;
	class SUBR;
	class XELDB;
	class XELDI;
	class XELDR;
	class XELDS;
	class XESTB;
	class XESTI;
	class XESTR;
	class XESTS;
	class XLDB;
	class XLDI;
	class XLDR;
	class XLDS;
	class XSTB;
	class XSTI;
	class XSTR;
	class XSTS;


	class ai_visitor {
	public:
		virtual ~ai_visitor() { }
		virtual void visit_ADDI(ai::ADDI *instr)=0;
		virtual void visit_ADDP(ai::ADDP *instr)=0;
		virtual void visit_ADDR(ai::ADDR *instr)=0;
		virtual void visit_ADDS(ai::ADDS *instr)=0;
		virtual void visit_AND(ai::AND *instr)=0;
		virtual void visit_CALL(ai::CALL *instr)=0;
		virtual void visit_CVRTIR(ai::CVRTIR *instr)=0;
		virtual void visit_CVRTRI(ai::CVRTRI *instr)=0;
		virtual void visit_DIVI(ai::DIVI *instr)=0;
		virtual void visit_DIVR(ai::DIVR *instr)=0;
		virtual void visit_DTORB(ai::DTORB *instr)=0;
		virtual void visit_DTORI(ai::DTORI *instr)=0;
		virtual void visit_DTORP(ai::DTORP *instr)=0;
		virtual void visit_DTORR(ai::DTORR *instr)=0;
		virtual void visit_DTORS(ai::DTORS *instr)=0;
		virtual void visit_EADDI(ai::EADDI *instr)=0;
		virtual void visit_EADDP(ai::EADDP *instr)=0;
		virtual void visit_EADDR(ai::EADDR *instr)=0;
		virtual void visit_EADDS(ai::EADDS *instr)=0;
		virtual void visit_EAND(ai::EAND *instr)=0;
		virtual void visit_ECVRTIR(ai::ECVRTIR *instr)=0;
		virtual void visit_ECVRTRI(ai::ECVRTRI *instr)=0;
		virtual void visit_EDIVI(ai::EDIVI *instr)=0;
		virtual void visit_EDIVR(ai::EDIVR *instr)=0;
		virtual void visit_EEQB(ai::EEQB *instr)=0;
		virtual void visit_EEQI(ai::EEQI *instr)=0;
		virtual void visit_EEQR(ai::EEQR *instr)=0;
		virtual void visit_EEQS(ai::EEQS *instr)=0;
		virtual void visit_EGEB(ai::EGEB *instr)=0;
		virtual void visit_EGEI(ai::EGEI *instr)=0;
		virtual void visit_EGER(ai::EGER *instr)=0;
		virtual void visit_EGES(ai::EGES *instr)=0;
		virtual void visit_EGTB(ai::EGTB *instr)=0;
		virtual void visit_EGTI(ai::EGTI *instr)=0;
		virtual void visit_EGTR(ai::EGTR *instr)=0;
		virtual void visit_EGTS(ai::EGTS *instr)=0;
		virtual void visit_EINITB(ai::EINITB *instr)=0;
		virtual void visit_EINITI(ai::EINITI *instr)=0;
		virtual void visit_EINITR(ai::EINITR *instr)=0;
		virtual void visit_EINITS(ai::EINITS *instr)=0;
		virtual void visit_ELDLITB(ai::ELDLITB *instr)=0;
		virtual void visit_ELDLITI(ai::ELDLITI *instr)=0;
		virtual void visit_ELDLITR(ai::ELDLITR *instr)=0;
		virtual void visit_ELDLITS(ai::ELDLITS *instr)=0;
		virtual void visit_ELEB(ai::ELEB *instr)=0;
		virtual void visit_ELEI(ai::ELEI *instr)=0;
		virtual void visit_ELER(ai::ELER *instr)=0;
		virtual void visit_ELES(ai::ELES *instr)=0;
		virtual void visit_ELTB(ai::ELTB *instr)=0;
		virtual void visit_ELTI(ai::ELTI *instr)=0;
		virtual void visit_ELTR(ai::ELTR *instr)=0;
		virtual void visit_ELTS(ai::ELTS *instr)=0;
		virtual void visit_EMINUSI(ai::EMINUSI *instr)=0;
		virtual void visit_EMINUSR(ai::EMINUSR *instr)=0;
		virtual void visit_EMODI(ai::EMODI *instr)=0;
		virtual void visit_EMOVB(ai::EMOVB *instr)=0;
		virtual void visit_EMOVI(ai::EMOVI *instr)=0;
		virtual void visit_EMOVP(ai::EMOVP *instr)=0;
		virtual void visit_EMOVR(ai::EMOVR *instr)=0;
		virtual void visit_EMOVS(ai::EMOVS *instr)=0;
		virtual void visit_EMULI(ai::EMULI *instr)=0;
		virtual void visit_EMULR(ai::EMULR *instr)=0;
		virtual void visit_ENEB(ai::ENEB *instr)=0;
		virtual void visit_ENEI(ai::ENEI *instr)=0;
		virtual void visit_ENER(ai::ENER *instr)=0;
		virtual void visit_ENES(ai::ENES *instr)=0;
		virtual void visit_ENOT(ai::ENOT *instr)=0;
		virtual void visit_EOR(ai::EOR *instr)=0;
		virtual void visit_EPOP(ai::EPOP *instr)=0;
		virtual void visit_EPOPB(ai::EPOPB *instr)=0;
		virtual void visit_EPOPI(ai::EPOPI *instr)=0;
		virtual void visit_EPOPP(ai::EPOPP *instr)=0;
		virtual void visit_EPOPR(ai::EPOPR *instr)=0;
		virtual void visit_EPOPS(ai::EPOPS *instr)=0;
		virtual void visit_EPUSH(ai::EPUSH *instr)=0;
		virtual void visit_EPUSHB(ai::EPUSHB *instr)=0;
		virtual void visit_EPUSHI(ai::EPUSHI *instr)=0;
		virtual void visit_EPUSHP(ai::EPUSHP *instr)=0;
		virtual void visit_EPUSHR(ai::EPUSHR *instr)=0;
		virtual void visit_EPUSHS(ai::EPUSHS *instr)=0;
		virtual void visit_EQB(ai::EQB *instr)=0;
		virtual void visit_EQI(ai::EQI *instr)=0;
		virtual void visit_EQR(ai::EQR *instr)=0;
		virtual void visit_EQS(ai::EQS *instr)=0;
		virtual void visit_ESUBI(ai::ESUBI *instr)=0;
		virtual void visit_ESUBP(ai::ESUBP *instr)=0;
		virtual void visit_ESUBR(ai::ESUBR *instr)=0;
		virtual void visit_FNCREADI(ai::FNCREADI *instr)=0;
		virtual void visit_FNCREADR(ai::FNCREADR *instr)=0;
		virtual void visit_FNCREADS(ai::FNCREADS *instr)=0;
		virtual void visit_FNCWRITEI(ai::FNCWRITEI *instr)=0;
		virtual void visit_FNCWRITELN(ai::FNCWRITELN *instr)=0;
		virtual void visit_FNCWRITER(ai::FNCWRITER *instr)=0;
		virtual void visit_FNCWRITES(ai::FNCWRITES *instr)=0;
		virtual void visit_GEB(ai::GEB *instr)=0;
		virtual void visit_GEI(ai::GEI *instr)=0;
		virtual void visit_GELDB(ai::GELDB *instr)=0;
		virtual void visit_GELDI(ai::GELDI *instr)=0;
		virtual void visit_GELDR(ai::GELDR *instr)=0;
		virtual void visit_GELDS(ai::GELDS *instr)=0;
		virtual void visit_GER(ai::GER *instr)=0;
		virtual void visit_GEREF(ai::GEREF *instr)=0;
		virtual void visit_GES(ai::GES *instr)=0;
		virtual void visit_GESTB(ai::GESTB *instr)=0;
		virtual void visit_GESTI(ai::GESTI *instr)=0;
		virtual void visit_GESTR(ai::GESTR *instr)=0;
		virtual void visit_GESTS(ai::GESTS *instr)=0;
		virtual void visit_GLDB(ai::GLDB *instr)=0;
		virtual void visit_GLDI(ai::GLDI *instr)=0;
		virtual void visit_GLDR(ai::GLDR *instr)=0;
		virtual void visit_GLDS(ai::GLDS *instr)=0;
		virtual void visit_GREF(ai::GREF *instr)=0;
		virtual void visit_GSTB(ai::GSTB *instr)=0;
		virtual void visit_GSTI(ai::GSTI *instr)=0;
		virtual void visit_GSTR(ai::GSTR *instr)=0;
		virtual void visit_GSTS(ai::GSTS *instr)=0;
		virtual void visit_GTB(ai::GTB *instr)=0;
		virtual void visit_GTI(ai::GTI *instr)=0;
		virtual void visit_GTR(ai::GTR *instr)=0;
		virtual void visit_GTS(ai::GTS *instr)=0;
		virtual void visit_HALT(ai::HALT *instr)=0;
		virtual void visit_INITB(ai::INITB *instr)=0;
		virtual void visit_INITI(ai::INITI *instr)=0;
		virtual void visit_INITR(ai::INITR *instr)=0;
		virtual void visit_INITS(ai::INITS *instr)=0;
		virtual void visit_JEF(ai::JEF *instr)=0;
		virtual void visit_JET(ai::JET *instr)=0;
		virtual void visit_JF(ai::JF *instr)=0;
		virtual void visit_JMP(ai::JMP *instr)=0;
		virtual void visit_JT(ai::JT *instr)=0;
		virtual void visit_LDLITB(ai::LDLITB *instr)=0;
		virtual void visit_LDLITI(ai::LDLITI *instr)=0;
		virtual void visit_LDLITR(ai::LDLITR *instr)=0;
		virtual void visit_LDLITS(ai::LDLITS *instr)=0;
		virtual void visit_LEB(ai::LEB *instr)=0;
		virtual void visit_LEI(ai::LEI *instr)=0;
		virtual void visit_LELDB(ai::LELDB *instr)=0;
		virtual void visit_LELDI(ai::LELDI *instr)=0;
		virtual void visit_LELDP(ai::LELDP *instr)=0;
		virtual void visit_LELDR(ai::LELDR *instr)=0;
		virtual void visit_LELDS(ai::LELDS *instr)=0;
		virtual void visit_LER(ai::LER *instr)=0;
		virtual void visit_LEREF(ai::LEREF *instr)=0;
		virtual void visit_LES(ai::LES *instr)=0;
		virtual void visit_LESTB(ai::LESTB *instr)=0;
		virtual void visit_LESTI(ai::LESTI *instr)=0;
		virtual void visit_LESTP(ai::LESTP *instr)=0;
		virtual void visit_LESTR(ai::LESTR *instr)=0;
		virtual void visit_LESTS(ai::LESTS *instr)=0;
		virtual void visit_LLDB(ai::LLDB *instr)=0;
		virtual void visit_LLDI(ai::LLDI *instr)=0;
		virtual void visit_LLDP(ai::LLDP *instr)=0;
		virtual void visit_LLDR(ai::LLDR *instr)=0;
		virtual void visit_LLDS(ai::LLDS *instr)=0;
		virtual void visit_LREF(ai::LREF *instr)=0;
		virtual void visit_LSTB(ai::LSTB *instr)=0;
		virtual void visit_LSTI(ai::LSTI *instr)=0;
		virtual void visit_LSTR(ai::LSTR *instr)=0;
		virtual void visit_LSTS(ai::LSTS *instr)=0;
		virtual void visit_LTB(ai::LTB *instr)=0;
		virtual void visit_LTI(ai::LTI *instr)=0;
		virtual void visit_LTR(ai::LTR *instr)=0;
		virtual void visit_LTS(ai::LTS *instr)=0;
		virtual void visit_MINUSI(ai::MINUSI *instr)=0;
		virtual void visit_MINUSR(ai::MINUSR *instr)=0;
		virtual void visit_MODI(ai::MODI *instr)=0;
		virtual void visit_MULI(ai::MULI *instr)=0;
		virtual void visit_MULR(ai::MULR *instr)=0;
		virtual void visit_NEB(ai::NEB *instr)=0;
		virtual void visit_NEI(ai::NEI *instr)=0;
		virtual void visit_NER(ai::NER *instr)=0;
		virtual void visit_NES(ai::NES *instr)=0;
		virtual void visit_NOP(ai::NOP *instr)=0;
		virtual void visit_NOT(ai::NOT *instr)=0;
		virtual void visit_OR(ai::OR *instr)=0;
		virtual void visit_RET(ai::RET *instr)=0;
		virtual void visit_SADD(ai::SADD *instr)=0;
		virtual void visit_SLDB(ai::SLDB *instr)=0;
		virtual void visit_SLDI(ai::SLDI *instr)=0;
		virtual void visit_SLDP(ai::SLDP *instr)=0;
		virtual void visit_SLDR(ai::SLDR *instr)=0;
		virtual void visit_SLDS(ai::SLDS *instr)=0;
		virtual void visit_SREF(ai::SREF *instr)=0;
		virtual void visit_SSTB(ai::SSTB *instr)=0;
		virtual void visit_SSTI(ai::SSTI *instr)=0;
		virtual void visit_SSTP(ai::SSTP *instr)=0;
		virtual void visit_SSTR(ai::SSTR *instr)=0;
		virtual void visit_SSTS(ai::SSTS *instr)=0;
		virtual void visit_SUBI(ai::SUBI *instr)=0;
		virtual void visit_SUBP(ai::SUBP *instr)=0;
		virtual void visit_SUBR(ai::SUBR *instr)=0;
		virtual void visit_XELDB(ai::XELDB *instr)=0;
		virtual void visit_XELDI(ai::XELDI *instr)=0;
		virtual void visit_XELDR(ai::XELDR *instr)=0;
		virtual void visit_XELDS(ai::XELDS *instr)=0;
		virtual void visit_XESTB(ai::XESTB *instr)=0;
		virtual void visit_XESTI(ai::XESTI *instr)=0;
		virtual void visit_XESTR(ai::XESTR *instr)=0;
		virtual void visit_XESTS(ai::XESTS *instr)=0;
		virtual void visit_XLDB(ai::XLDB *instr)=0;
		virtual void visit_XLDI(ai::XLDI *instr)=0;
		virtual void visit_XLDR(ai::XLDR *instr)=0;
		virtual void visit_XLDS(ai::XLDS *instr)=0;
		virtual void visit_XSTB(ai::XSTB *instr)=0;
		virtual void visit_XSTI(ai::XSTI *instr)=0;
		virtual void visit_XSTR(ai::XSTR *instr)=0;
		virtual void visit_XSTS(ai::XSTS *instr)=0;
	};

	class ai_const_visitor {
	public:
		virtual ~ai_const_visitor() { }
		virtual void visit_ADDI(const ai::ADDI *instr)=0;
		virtual void visit_ADDP(const ai::ADDP *instr)=0;
		virtual void visit_ADDR(const ai::ADDR *instr)=0;
		virtual void visit_ADDS(const ai::ADDS *instr)=0;
		virtual void visit_AND(const ai::AND *instr)=0;
		virtual void visit_CALL(const ai::CALL *instr)=0;
		virtual void visit_CVRTIR(const ai::CVRTIR *instr)=0;
		virtual void visit_CVRTRI(const ai::CVRTRI *instr)=0;
		virtual void visit_DIVI(const ai::DIVI *instr)=0;
		virtual void visit_DIVR(const ai::DIVR *instr)=0;
		virtual void visit_DTORB(const ai::DTORB *instr)=0;
		virtual void visit_DTORI(const ai::DTORI *instr)=0;
		virtual void visit_DTORP(const ai::DTORP *instr)=0;
		virtual void visit_DTORR(const ai::DTORR *instr)=0;
		virtual void visit_DTORS(const ai::DTORS *instr)=0;
		virtual void visit_EADDI(const ai::EADDI *instr)=0;
		virtual void visit_EADDP(const ai::EADDP *instr)=0;
		virtual void visit_EADDR(const ai::EADDR *instr)=0;
		virtual void visit_EADDS(const ai::EADDS *instr)=0;
		virtual void visit_EAND(const ai::EAND *instr)=0;
		virtual void visit_ECVRTIR(const ai::ECVRTIR *instr)=0;
		virtual void visit_ECVRTRI(const ai::ECVRTRI *instr)=0;
		virtual void visit_EDIVI(const ai::EDIVI *instr)=0;
		virtual void visit_EDIVR(const ai::EDIVR *instr)=0;
		virtual void visit_EEQB(const ai::EEQB *instr)=0;
		virtual void visit_EEQI(const ai::EEQI *instr)=0;
		virtual void visit_EEQR(const ai::EEQR *instr)=0;
		virtual void visit_EEQS(const ai::EEQS *instr)=0;
		virtual void visit_EGEB(const ai::EGEB *instr)=0;
		virtual void visit_EGEI(const ai::EGEI *instr)=0;
		virtual void visit_EGER(const ai::EGER *instr)=0;
		virtual void visit_EGES(const ai::EGES *instr)=0;
		virtual void visit_EGTB(const ai::EGTB *instr)=0;
		virtual void visit_EGTI(const ai::EGTI *instr)=0;
		virtual void visit_EGTR(const ai::EGTR *instr)=0;
		virtual void visit_EGTS(const ai::EGTS *instr)=0;
		virtual void visit_EINITB(const ai::EINITB *instr)=0;
		virtual void visit_EINITI(const ai::EINITI *instr)=0;
		virtual void visit_EINITR(const ai::EINITR *instr)=0;
		virtual void visit_EINITS(const ai::EINITS *instr)=0;
		virtual void visit_ELDLITB(const ai::ELDLITB *instr)=0;
		virtual void visit_ELDLITI(const ai::ELDLITI *instr)=0;
		virtual void visit_ELDLITR(const ai::ELDLITR *instr)=0;
		virtual void visit_ELDLITS(const ai::ELDLITS *instr)=0;
		virtual void visit_ELEB(const ai::ELEB *instr)=0;
		virtual void visit_ELEI(const ai::ELEI *instr)=0;
		virtual void visit_ELER(const ai::ELER *instr)=0;
		virtual void visit_ELES(const ai::ELES *instr)=0;
		virtual void visit_ELTB(const ai::ELTB *instr)=0;
		virtual void visit_ELTI(const ai::ELTI *instr)=0;
		virtual void visit_ELTR(const ai::ELTR *instr)=0;
		virtual void visit_ELTS(const ai::ELTS *instr)=0;
		virtual void visit_EMINUSI(const ai::EMINUSI *instr)=0;
		virtual void visit_EMINUSR(const ai::EMINUSR *instr)=0;
		virtual void visit_EMODI(const ai::EMODI *instr)=0;
		virtual void visit_EMOVB(const ai::EMOVB *instr)=0;
		virtual void visit_EMOVI(const ai::EMOVI *instr)=0;
		virtual void visit_EMOVP(const ai::EMOVP *instr)=0;
		virtual void visit_EMOVR(const ai::EMOVR *instr)=0;
		virtual void visit_EMOVS(const ai::EMOVS *instr)=0;
		virtual void visit_EMULI(const ai::EMULI *instr)=0;
		virtual void visit_EMULR(const ai::EMULR *instr)=0;
		virtual void visit_ENEB(const ai::ENEB *instr)=0;
		virtual void visit_ENEI(const ai::ENEI *instr)=0;
		virtual void visit_ENER(const ai::ENER *instr)=0;
		virtual void visit_ENES(const ai::ENES *instr)=0;
		virtual void visit_ENOT(const ai::ENOT *instr)=0;
		virtual void visit_EOR(const ai::EOR *instr)=0;
		virtual void visit_EPOP(const ai::EPOP *instr)=0;
		virtual void visit_EPOPB(const ai::EPOPB *instr)=0;
		virtual void visit_EPOPI(const ai::EPOPI *instr)=0;
		virtual void visit_EPOPP(const ai::EPOPP *instr)=0;
		virtual void visit_EPOPR(const ai::EPOPR *instr)=0;
		virtual void visit_EPOPS(const ai::EPOPS *instr)=0;
		virtual void visit_EPUSH(const ai::EPUSH *instr)=0;
		virtual void visit_EPUSHB(const ai::EPUSHB *instr)=0;
		virtual void visit_EPUSHI(const ai::EPUSHI *instr)=0;
		virtual void visit_EPUSHP(const ai::EPUSHP *instr)=0;
		virtual void visit_EPUSHR(const ai::EPUSHR *instr)=0;
		virtual void visit_EPUSHS(const ai::EPUSHS *instr)=0;
		virtual void visit_EQB(const ai::EQB *instr)=0;
		virtual void visit_EQI(const ai::EQI *instr)=0;
		virtual void visit_EQR(const ai::EQR *instr)=0;
		virtual void visit_EQS(const ai::EQS *instr)=0;
		virtual void visit_ESUBI(const ai::ESUBI *instr)=0;
		virtual void visit_ESUBP(const ai::ESUBP *instr)=0;
		virtual void visit_ESUBR(const ai::ESUBR *instr)=0;
		virtual void visit_FNCREADI(const ai::FNCREADI *instr)=0;
		virtual void visit_FNCREADR(const ai::FNCREADR *instr)=0;
		virtual void visit_FNCREADS(const ai::FNCREADS *instr)=0;
		virtual void visit_FNCWRITEI(const ai::FNCWRITEI *instr)=0;
		virtual void visit_FNCWRITELN(const ai::FNCWRITELN *instr)=0;
		virtual void visit_FNCWRITER(const ai::FNCWRITER *instr)=0;
		virtual void visit_FNCWRITES(const ai::FNCWRITES *instr)=0;
		virtual void visit_GEB(const ai::GEB *instr)=0;
		virtual void visit_GEI(const ai::GEI *instr)=0;
		virtual void visit_GELDB(const ai::GELDB *instr)=0;
		virtual void visit_GELDI(const ai::GELDI *instr)=0;
		virtual void visit_GELDR(const ai::GELDR *instr)=0;
		virtual void visit_GELDS(const ai::GELDS *instr)=0;
		virtual void visit_GER(const ai::GER *instr)=0;
		virtual void visit_GEREF(const ai::GEREF *instr)=0;
		virtual void visit_GES(const ai::GES *instr)=0;
		virtual void visit_GESTB(const ai::GESTB *instr)=0;
		virtual void visit_GESTI(const ai::GESTI *instr)=0;
		virtual void visit_GESTR(const ai::GESTR *instr)=0;
		virtual void visit_GESTS(const ai::GESTS *instr)=0;
		virtual void visit_GLDB(const ai::GLDB *instr)=0;
		virtual void visit_GLDI(const ai::GLDI *instr)=0;
		virtual void visit_GLDR(const ai::GLDR *instr)=0;
		virtual void visit_GLDS(const ai::GLDS *instr)=0;
		virtual void visit_GREF(const ai::GREF *instr)=0;
		virtual void visit_GSTB(const ai::GSTB *instr)=0;
		virtual void visit_GSTI(const ai::GSTI *instr)=0;
		virtual void visit_GSTR(const ai::GSTR *instr)=0;
		virtual void visit_GSTS(const ai::GSTS *instr)=0;
		virtual void visit_GTB(const ai::GTB *instr)=0;
		virtual void visit_GTI(const ai::GTI *instr)=0;
		virtual void visit_GTR(const ai::GTR *instr)=0;
		virtual void visit_GTS(const ai::GTS *instr)=0;
		virtual void visit_HALT(const ai::HALT *instr)=0;
		virtual void visit_INITB(const ai::INITB *instr)=0;
		virtual void visit_INITI(const ai::INITI *instr)=0;
		virtual void visit_INITR(const ai::INITR *instr)=0;
		virtual void visit_INITS(const ai::INITS *instr)=0;
		virtual void visit_JEF(const ai::JEF *instr)=0;
		virtual void visit_JET(const ai::JET *instr)=0;
		virtual void visit_JF(const ai::JF *instr)=0;
		virtual void visit_JMP(const ai::JMP *instr)=0;
		virtual void visit_JT(const ai::JT *instr)=0;
		virtual void visit_LDLITB(const ai::LDLITB *instr)=0;
		virtual void visit_LDLITI(const ai::LDLITI *instr)=0;
		virtual void visit_LDLITR(const ai::LDLITR *instr)=0;
		virtual void visit_LDLITS(const ai::LDLITS *instr)=0;
		virtual void visit_LEB(const ai::LEB *instr)=0;
		virtual void visit_LEI(const ai::LEI *instr)=0;
		virtual void visit_LELDB(const ai::LELDB *instr)=0;
		virtual void visit_LELDI(const ai::LELDI *instr)=0;
		virtual void visit_LELDP(const ai::LELDP *instr)=0;
		virtual void visit_LELDR(const ai::LELDR *instr)=0;
		virtual void visit_LELDS(const ai::LELDS *instr)=0;
		virtual void visit_LER(const ai::LER *instr)=0;
		virtual void visit_LEREF(const ai::LEREF *instr)=0;
		virtual void visit_LES(const ai::LES *instr)=0;
		virtual void visit_LESTB(const ai::LESTB *instr)=0;
		virtual void visit_LESTI(const ai::LESTI *instr)=0;
		virtual void visit_LESTP(const ai::LESTP *instr)=0;
		virtual void visit_LESTR(const ai::LESTR *instr)=0;
		virtual void visit_LESTS(const ai::LESTS *instr)=0;
		virtual void visit_LLDB(const ai::LLDB *instr)=0;
		virtual void visit_LLDI(const ai::LLDI *instr)=0;
		virtual void visit_LLDP(const ai::LLDP *instr)=0;
		virtual void visit_LLDR(const ai::LLDR *instr)=0;
		virtual void visit_LLDS(const ai::LLDS *instr)=0;
		virtual void visit_LREF(const ai::LREF *instr)=0;
		virtual void visit_LSTB(const ai::LSTB *instr)=0;
		virtual void visit_LSTI(const ai::LSTI *instr)=0;
		virtual void visit_LSTR(const ai::LSTR *instr)=0;
		virtual void visit_LSTS(const ai::LSTS *instr)=0;
		virtual void visit_LTB(const ai::LTB *instr)=0;
		virtual void visit_LTI(const ai::LTI *instr)=0;
		virtual void visit_LTR(const ai::LTR *instr)=0;
		virtual void visit_LTS(const ai::LTS *instr)=0;
		virtual void visit_MINUSI(const ai::MINUSI *instr)=0;
		virtual void visit_MINUSR(const ai::MINUSR *instr)=0;
		virtual void visit_MODI(const ai::MODI *instr)=0;
		virtual void visit_MULI(const ai::MULI *instr)=0;
		virtual void visit_MULR(const ai::MULR *instr)=0;
		virtual void visit_NEB(const ai::NEB *instr)=0;
		virtual void visit_NEI(const ai::NEI *instr)=0;
		virtual void visit_NER(const ai::NER *instr)=0;
		virtual void visit_NES(const ai::NES *instr)=0;
		virtual void visit_NOP(const ai::NOP *instr)=0;
		virtual void visit_NOT(const ai::NOT *instr)=0;
		virtual void visit_OR(const ai::OR *instr)=0;
		virtual void visit_RET(const ai::RET *instr)=0;
		virtual void visit_SADD(const ai::SADD *instr)=0;
		virtual void visit_SLDB(const ai::SLDB *instr)=0;
		virtual void visit_SLDI(const ai::SLDI *instr)=0;
		virtual void visit_SLDP(const ai::SLDP *instr)=0;
		virtual void visit_SLDR(const ai::SLDR *instr)=0;
		virtual void visit_SLDS(const ai::SLDS *instr)=0;
		virtual void visit_SREF(const ai::SREF *instr)=0;
		virtual void visit_SSTB(const ai::SSTB *instr)=0;
		virtual void visit_SSTI(const ai::SSTI *instr)=0;
		virtual void visit_SSTP(const ai::SSTP *instr)=0;
		virtual void visit_SSTR(const ai::SSTR *instr)=0;
		virtual void visit_SSTS(const ai::SSTS *instr)=0;
		virtual void visit_SUBI(const ai::SUBI *instr)=0;
		virtual void visit_SUBP(const ai::SUBP *instr)=0;
		virtual void visit_SUBR(const ai::SUBR *instr)=0;
		virtual void visit_XELDB(const ai::XELDB *instr)=0;
		virtual void visit_XELDI(const ai::XELDI *instr)=0;
		virtual void visit_XELDR(const ai::XELDR *instr)=0;
		virtual void visit_XELDS(const ai::XELDS *instr)=0;
		virtual void visit_XESTB(const ai::XESTB *instr)=0;
		virtual void visit_XESTI(const ai::XESTI *instr)=0;
		virtual void visit_XESTR(const ai::XESTR *instr)=0;
		virtual void visit_XESTS(const ai::XESTS *instr)=0;
		virtual void visit_XLDB(const ai::XLDB *instr)=0;
		virtual void visit_XLDI(const ai::XLDI *instr)=0;
		virtual void visit_XLDR(const ai::XLDR *instr)=0;
		virtual void visit_XLDS(const ai::XLDS *instr)=0;
		virtual void visit_XSTB(const ai::XSTB *instr)=0;
		virtual void visit_XSTI(const ai::XSTI *instr)=0;
		virtual void visit_XSTR(const ai::XSTR *instr)=0;
		virtual void visit_XSTS(const ai::XSTS *instr)=0;
	};

	template <typename P>
	class ai_templated_visitor : public ai_visitor, public P {
	public:
		ai_templated_visitor( const P & r) : P( r) {}
	private:
		virtual void visit_ADDI(ai::ADDI *instr) { this->template visit<ai::ADDI>(instr); }
		virtual void visit_ADDP(ai::ADDP *instr) { this->template visit<ai::ADDP>(instr); }
		virtual void visit_ADDR(ai::ADDR *instr) { this->template visit<ai::ADDR>(instr); }
		virtual void visit_ADDS(ai::ADDS *instr) { this->template visit<ai::ADDS>(instr); }
		virtual void visit_AND(ai::AND *instr) { this->template visit<ai::AND>(instr); }
		virtual void visit_CALL(ai::CALL *instr) { this->template visit<ai::CALL>(instr); }
		virtual void visit_CVRTIR(ai::CVRTIR *instr) { this->template visit<ai::CVRTIR>(instr); }
		virtual void visit_CVRTRI(ai::CVRTRI *instr) { this->template visit<ai::CVRTRI>(instr); }
		virtual void visit_DIVI(ai::DIVI *instr) { this->template visit<ai::DIVI>(instr); }
		virtual void visit_DIVR(ai::DIVR *instr) { this->template visit<ai::DIVR>(instr); }
		virtual void visit_DTORB(ai::DTORB *instr) { this->template visit<ai::DTORB>(instr); }
		virtual void visit_DTORI(ai::DTORI *instr) { this->template visit<ai::DTORI>(instr); }
		virtual void visit_DTORP(ai::DTORP *instr) { this->template visit<ai::DTORP>(instr); }
		virtual void visit_DTORR(ai::DTORR *instr) { this->template visit<ai::DTORR>(instr); }
		virtual void visit_DTORS(ai::DTORS *instr) { this->template visit<ai::DTORS>(instr); }
		virtual void visit_EADDI(ai::EADDI *instr) { this->template visit<ai::EADDI>(instr); }
		virtual void visit_EADDP(ai::EADDP *instr) { this->template visit<ai::EADDP>(instr); }
		virtual void visit_EADDR(ai::EADDR *instr) { this->template visit<ai::EADDR>(instr); }
		virtual void visit_EADDS(ai::EADDS *instr) { this->template visit<ai::EADDS>(instr); }
		virtual void visit_EAND(ai::EAND *instr) { this->template visit<ai::EAND>(instr); }
		virtual void visit_ECVRTIR(ai::ECVRTIR *instr) { this->template visit<ai::ECVRTIR>(instr); }
		virtual void visit_ECVRTRI(ai::ECVRTRI *instr) { this->template visit<ai::ECVRTRI>(instr); }
		virtual void visit_EDIVI(ai::EDIVI *instr) { this->template visit<ai::EDIVI>(instr); }
		virtual void visit_EDIVR(ai::EDIVR *instr) { this->template visit<ai::EDIVR>(instr); }
		virtual void visit_EEQB(ai::EEQB *instr) { this->template visit<ai::EEQB>(instr); }
		virtual void visit_EEQI(ai::EEQI *instr) { this->template visit<ai::EEQI>(instr); }
		virtual void visit_EEQR(ai::EEQR *instr) { this->template visit<ai::EEQR>(instr); }
		virtual void visit_EEQS(ai::EEQS *instr) { this->template visit<ai::EEQS>(instr); }
		virtual void visit_EGEB(ai::EGEB *instr) { this->template visit<ai::EGEB>(instr); }
		virtual void visit_EGEI(ai::EGEI *instr) { this->template visit<ai::EGEI>(instr); }
		virtual void visit_EGER(ai::EGER *instr) { this->template visit<ai::EGER>(instr); }
		virtual void visit_EGES(ai::EGES *instr) { this->template visit<ai::EGES>(instr); }
		virtual void visit_EGTB(ai::EGTB *instr) { this->template visit<ai::EGTB>(instr); }
		virtual void visit_EGTI(ai::EGTI *instr) { this->template visit<ai::EGTI>(instr); }
		virtual void visit_EGTR(ai::EGTR *instr) { this->template visit<ai::EGTR>(instr); }
		virtual void visit_EGTS(ai::EGTS *instr) { this->template visit<ai::EGTS>(instr); }
		virtual void visit_EINITB(ai::EINITB *instr) { this->template visit<ai::EINITB>(instr); }
		virtual void visit_EINITI(ai::EINITI *instr) { this->template visit<ai::EINITI>(instr); }
		virtual void visit_EINITR(ai::EINITR *instr) { this->template visit<ai::EINITR>(instr); }
		virtual void visit_EINITS(ai::EINITS *instr) { this->template visit<ai::EINITS>(instr); }
		virtual void visit_ELDLITB(ai::ELDLITB *instr) { this->template visit<ai::ELDLITB>(instr); }
		virtual void visit_ELDLITI(ai::ELDLITI *instr) { this->template visit<ai::ELDLITI>(instr); }
		virtual void visit_ELDLITR(ai::ELDLITR *instr) { this->template visit<ai::ELDLITR>(instr); }
		virtual void visit_ELDLITS(ai::ELDLITS *instr) { this->template visit<ai::ELDLITS>(instr); }
		virtual void visit_ELEB(ai::ELEB *instr) { this->template visit<ai::ELEB>(instr); }
		virtual void visit_ELEI(ai::ELEI *instr) { this->template visit<ai::ELEI>(instr); }
		virtual void visit_ELER(ai::ELER *instr) { this->template visit<ai::ELER>(instr); }
		virtual void visit_ELES(ai::ELES *instr) { this->template visit<ai::ELES>(instr); }
		virtual void visit_ELTB(ai::ELTB *instr) { this->template visit<ai::ELTB>(instr); }
		virtual void visit_ELTI(ai::ELTI *instr) { this->template visit<ai::ELTI>(instr); }
		virtual void visit_ELTR(ai::ELTR *instr) { this->template visit<ai::ELTR>(instr); }
		virtual void visit_ELTS(ai::ELTS *instr) { this->template visit<ai::ELTS>(instr); }
		virtual void visit_EMINUSI(ai::EMINUSI *instr) { this->template visit<ai::EMINUSI>(instr); }
		virtual void visit_EMINUSR(ai::EMINUSR *instr) { this->template visit<ai::EMINUSR>(instr); }
		virtual void visit_EMODI(ai::EMODI *instr) { this->template visit<ai::EMODI>(instr); }
		virtual void visit_EMOVB(ai::EMOVB *instr) { this->template visit<ai::EMOVB>(instr); }
		virtual void visit_EMOVI(ai::EMOVI *instr) { this->template visit<ai::EMOVI>(instr); }
		virtual void visit_EMOVP(ai::EMOVP *instr) { this->template visit<ai::EMOVP>(instr); }
		virtual void visit_EMOVR(ai::EMOVR *instr) { this->template visit<ai::EMOVR>(instr); }
		virtual void visit_EMOVS(ai::EMOVS *instr) { this->template visit<ai::EMOVS>(instr); }
		virtual void visit_EMULI(ai::EMULI *instr) { this->template visit<ai::EMULI>(instr); }
		virtual void visit_EMULR(ai::EMULR *instr) { this->template visit<ai::EMULR>(instr); }
		virtual void visit_ENEB(ai::ENEB *instr) { this->template visit<ai::ENEB>(instr); }
		virtual void visit_ENEI(ai::ENEI *instr) { this->template visit<ai::ENEI>(instr); }
		virtual void visit_ENER(ai::ENER *instr) { this->template visit<ai::ENER>(instr); }
		virtual void visit_ENES(ai::ENES *instr) { this->template visit<ai::ENES>(instr); }
		virtual void visit_ENOT(ai::ENOT *instr) { this->template visit<ai::ENOT>(instr); }
		virtual void visit_EOR(ai::EOR *instr) { this->template visit<ai::EOR>(instr); }
		virtual void visit_EPOP(ai::EPOP *instr) { this->template visit<ai::EPOP>(instr); }
		virtual void visit_EPOPB(ai::EPOPB *instr) { this->template visit<ai::EPOPB>(instr); }
		virtual void visit_EPOPI(ai::EPOPI *instr) { this->template visit<ai::EPOPI>(instr); }
		virtual void visit_EPOPP(ai::EPOPP *instr) { this->template visit<ai::EPOPP>(instr); }
		virtual void visit_EPOPR(ai::EPOPR *instr) { this->template visit<ai::EPOPR>(instr); }
		virtual void visit_EPOPS(ai::EPOPS *instr) { this->template visit<ai::EPOPS>(instr); }
		virtual void visit_EPUSH(ai::EPUSH *instr) { this->template visit<ai::EPUSH>(instr); }
		virtual void visit_EPUSHB(ai::EPUSHB *instr) { this->template visit<ai::EPUSHB>(instr); }
		virtual void visit_EPUSHI(ai::EPUSHI *instr) { this->template visit<ai::EPUSHI>(instr); }
		virtual void visit_EPUSHP(ai::EPUSHP *instr) { this->template visit<ai::EPUSHP>(instr); }
		virtual void visit_EPUSHR(ai::EPUSHR *instr) { this->template visit<ai::EPUSHR>(instr); }
		virtual void visit_EPUSHS(ai::EPUSHS *instr) { this->template visit<ai::EPUSHS>(instr); }
		virtual void visit_EQB(ai::EQB *instr) { this->template visit<ai::EQB>(instr); }
		virtual void visit_EQI(ai::EQI *instr) { this->template visit<ai::EQI>(instr); }
		virtual void visit_EQR(ai::EQR *instr) { this->template visit<ai::EQR>(instr); }
		virtual void visit_EQS(ai::EQS *instr) { this->template visit<ai::EQS>(instr); }
		virtual void visit_ESUBI(ai::ESUBI *instr) { this->template visit<ai::ESUBI>(instr); }
		virtual void visit_ESUBP(ai::ESUBP *instr) { this->template visit<ai::ESUBP>(instr); }
		virtual void visit_ESUBR(ai::ESUBR *instr) { this->template visit<ai::ESUBR>(instr); }
		virtual void visit_FNCREADI(ai::FNCREADI *instr) { this->template visit<ai::FNCREADI>(instr); }
		virtual void visit_FNCREADR(ai::FNCREADR *instr) { this->template visit<ai::FNCREADR>(instr); }
		virtual void visit_FNCREADS(ai::FNCREADS *instr) { this->template visit<ai::FNCREADS>(instr); }
		virtual void visit_FNCWRITEI(ai::FNCWRITEI *instr) { this->template visit<ai::FNCWRITEI>(instr); }
		virtual void visit_FNCWRITELN(ai::FNCWRITELN *instr) { this->template visit<ai::FNCWRITELN>(instr); }
		virtual void visit_FNCWRITER(ai::FNCWRITER *instr) { this->template visit<ai::FNCWRITER>(instr); }
		virtual void visit_FNCWRITES(ai::FNCWRITES *instr) { this->template visit<ai::FNCWRITES>(instr); }
		virtual void visit_GEB(ai::GEB *instr) { this->template visit<ai::GEB>(instr); }
		virtual void visit_GEI(ai::GEI *instr) { this->template visit<ai::GEI>(instr); }
		virtual void visit_GELDB(ai::GELDB *instr) { this->template visit<ai::GELDB>(instr); }
		virtual void visit_GELDI(ai::GELDI *instr) { this->template visit<ai::GELDI>(instr); }
		virtual void visit_GELDR(ai::GELDR *instr) { this->template visit<ai::GELDR>(instr); }
		virtual void visit_GELDS(ai::GELDS *instr) { this->template visit<ai::GELDS>(instr); }
		virtual void visit_GER(ai::GER *instr) { this->template visit<ai::GER>(instr); }
		virtual void visit_GEREF(ai::GEREF *instr) { this->template visit<ai::GEREF>(instr); }
		virtual void visit_GES(ai::GES *instr) { this->template visit<ai::GES>(instr); }
		virtual void visit_GESTB(ai::GESTB *instr) { this->template visit<ai::GESTB>(instr); }
		virtual void visit_GESTI(ai::GESTI *instr) { this->template visit<ai::GESTI>(instr); }
		virtual void visit_GESTR(ai::GESTR *instr) { this->template visit<ai::GESTR>(instr); }
		virtual void visit_GESTS(ai::GESTS *instr) { this->template visit<ai::GESTS>(instr); }
		virtual void visit_GLDB(ai::GLDB *instr) { this->template visit<ai::GLDB>(instr); }
		virtual void visit_GLDI(ai::GLDI *instr) { this->template visit<ai::GLDI>(instr); }
		virtual void visit_GLDR(ai::GLDR *instr) { this->template visit<ai::GLDR>(instr); }
		virtual void visit_GLDS(ai::GLDS *instr) { this->template visit<ai::GLDS>(instr); }
		virtual void visit_GREF(ai::GREF *instr) { this->template visit<ai::GREF>(instr); }
		virtual void visit_GSTB(ai::GSTB *instr) { this->template visit<ai::GSTB>(instr); }
		virtual void visit_GSTI(ai::GSTI *instr) { this->template visit<ai::GSTI>(instr); }
		virtual void visit_GSTR(ai::GSTR *instr) { this->template visit<ai::GSTR>(instr); }
		virtual void visit_GSTS(ai::GSTS *instr) { this->template visit<ai::GSTS>(instr); }
		virtual void visit_GTB(ai::GTB *instr) { this->template visit<ai::GTB>(instr); }
		virtual void visit_GTI(ai::GTI *instr) { this->template visit<ai::GTI>(instr); }
		virtual void visit_GTR(ai::GTR *instr) { this->template visit<ai::GTR>(instr); }
		virtual void visit_GTS(ai::GTS *instr) { this->template visit<ai::GTS>(instr); }
		virtual void visit_HALT(ai::HALT *instr) { this->template visit<ai::HALT>(instr); }
		virtual void visit_INITB(ai::INITB *instr) { this->template visit<ai::INITB>(instr); }
		virtual void visit_INITI(ai::INITI *instr) { this->template visit<ai::INITI>(instr); }
		virtual void visit_INITR(ai::INITR *instr) { this->template visit<ai::INITR>(instr); }
		virtual void visit_INITS(ai::INITS *instr) { this->template visit<ai::INITS>(instr); }
		virtual void visit_JEF(ai::JEF *instr) { this->template visit<ai::JEF>(instr); }
		virtual void visit_JET(ai::JET *instr) { this->template visit<ai::JET>(instr); }
		virtual void visit_JF(ai::JF *instr) { this->template visit<ai::JF>(instr); }
		virtual void visit_JMP(ai::JMP *instr) { this->template visit<ai::JMP>(instr); }
		virtual void visit_JT(ai::JT *instr) { this->template visit<ai::JT>(instr); }
		virtual void visit_LDLITB(ai::LDLITB *instr) { this->template visit<ai::LDLITB>(instr); }
		virtual void visit_LDLITI(ai::LDLITI *instr) { this->template visit<ai::LDLITI>(instr); }
		virtual void visit_LDLITR(ai::LDLITR *instr) { this->template visit<ai::LDLITR>(instr); }
		virtual void visit_LDLITS(ai::LDLITS *instr) { this->template visit<ai::LDLITS>(instr); }
		virtual void visit_LEB(ai::LEB *instr) { this->template visit<ai::LEB>(instr); }
		virtual void visit_LEI(ai::LEI *instr) { this->template visit<ai::LEI>(instr); }
		virtual void visit_LELDB(ai::LELDB *instr) { this->template visit<ai::LELDB>(instr); }
		virtual void visit_LELDI(ai::LELDI *instr) { this->template visit<ai::LELDI>(instr); }
		virtual void visit_LELDP(ai::LELDP *instr) { this->template visit<ai::LELDP>(instr); }
		virtual void visit_LELDR(ai::LELDR *instr) { this->template visit<ai::LELDR>(instr); }
		virtual void visit_LELDS(ai::LELDS *instr) { this->template visit<ai::LELDS>(instr); }
		virtual void visit_LER(ai::LER *instr) { this->template visit<ai::LER>(instr); }
		virtual void visit_LEREF(ai::LEREF *instr) { this->template visit<ai::LEREF>(instr); }
		virtual void visit_LES(ai::LES *instr) { this->template visit<ai::LES>(instr); }
		virtual void visit_LESTB(ai::LESTB *instr) { this->template visit<ai::LESTB>(instr); }
		virtual void visit_LESTI(ai::LESTI *instr) { this->template visit<ai::LESTI>(instr); }
		virtual void visit_LESTP(ai::LESTP *instr) { this->template visit<ai::LESTP>(instr); }
		virtual void visit_LESTR(ai::LESTR *instr) { this->template visit<ai::LESTR>(instr); }
		virtual void visit_LESTS(ai::LESTS *instr) { this->template visit<ai::LESTS>(instr); }
		virtual void visit_LLDB(ai::LLDB *instr) { this->template visit<ai::LLDB>(instr); }
		virtual void visit_LLDI(ai::LLDI *instr) { this->template visit<ai::LLDI>(instr); }
		virtual void visit_LLDP(ai::LLDP *instr) { this->template visit<ai::LLDP>(instr); }
		virtual void visit_LLDR(ai::LLDR *instr) { this->template visit<ai::LLDR>(instr); }
		virtual void visit_LLDS(ai::LLDS *instr) { this->template visit<ai::LLDS>(instr); }
		virtual void visit_LREF(ai::LREF *instr) { this->template visit<ai::LREF>(instr); }
		virtual void visit_LSTB(ai::LSTB *instr) { this->template visit<ai::LSTB>(instr); }
		virtual void visit_LSTI(ai::LSTI *instr) { this->template visit<ai::LSTI>(instr); }
		virtual void visit_LSTR(ai::LSTR *instr) { this->template visit<ai::LSTR>(instr); }
		virtual void visit_LSTS(ai::LSTS *instr) { this->template visit<ai::LSTS>(instr); }
		virtual void visit_LTB(ai::LTB *instr) { this->template visit<ai::LTB>(instr); }
		virtual void visit_LTI(ai::LTI *instr) { this->template visit<ai::LTI>(instr); }
		virtual void visit_LTR(ai::LTR *instr) { this->template visit<ai::LTR>(instr); }
		virtual void visit_LTS(ai::LTS *instr) { this->template visit<ai::LTS>(instr); }
		virtual void visit_MINUSI(ai::MINUSI *instr) { this->template visit<ai::MINUSI>(instr); }
		virtual void visit_MINUSR(ai::MINUSR *instr) { this->template visit<ai::MINUSR>(instr); }
		virtual void visit_MODI(ai::MODI *instr) { this->template visit<ai::MODI>(instr); }
		virtual void visit_MULI(ai::MULI *instr) { this->template visit<ai::MULI>(instr); }
		virtual void visit_MULR(ai::MULR *instr) { this->template visit<ai::MULR>(instr); }
		virtual void visit_NEB(ai::NEB *instr) { this->template visit<ai::NEB>(instr); }
		virtual void visit_NEI(ai::NEI *instr) { this->template visit<ai::NEI>(instr); }
		virtual void visit_NER(ai::NER *instr) { this->template visit<ai::NER>(instr); }
		virtual void visit_NES(ai::NES *instr) { this->template visit<ai::NES>(instr); }
		virtual void visit_NOP(ai::NOP *instr) { this->template visit<ai::NOP>(instr); }
		virtual void visit_NOT(ai::NOT *instr) { this->template visit<ai::NOT>(instr); }
		virtual void visit_OR(ai::OR *instr) { this->template visit<ai::OR>(instr); }
		virtual void visit_RET(ai::RET *instr) { this->template visit<ai::RET>(instr); }
		virtual void visit_SADD(ai::SADD *instr) { this->template visit<ai::SADD>(instr); }
		virtual void visit_SLDB(ai::SLDB *instr) { this->template visit<ai::SLDB>(instr); }
		virtual void visit_SLDI(ai::SLDI *instr) { this->template visit<ai::SLDI>(instr); }
		virtual void visit_SLDP(ai::SLDP *instr) { this->template visit<ai::SLDP>(instr); }
		virtual void visit_SLDR(ai::SLDR *instr) { this->template visit<ai::SLDR>(instr); }
		virtual void visit_SLDS(ai::SLDS *instr) { this->template visit<ai::SLDS>(instr); }
		virtual void visit_SREF(ai::SREF *instr) { this->template visit<ai::SREF>(instr); }
		virtual void visit_SSTB(ai::SSTB *instr) { this->template visit<ai::SSTB>(instr); }
		virtual void visit_SSTI(ai::SSTI *instr) { this->template visit<ai::SSTI>(instr); }
		virtual void visit_SSTP(ai::SSTP *instr) { this->template visit<ai::SSTP>(instr); }
		virtual void visit_SSTR(ai::SSTR *instr) { this->template visit<ai::SSTR>(instr); }
		virtual void visit_SSTS(ai::SSTS *instr) { this->template visit<ai::SSTS>(instr); }
		virtual void visit_SUBI(ai::SUBI *instr) { this->template visit<ai::SUBI>(instr); }
		virtual void visit_SUBP(ai::SUBP *instr) { this->template visit<ai::SUBP>(instr); }
		virtual void visit_SUBR(ai::SUBR *instr) { this->template visit<ai::SUBR>(instr); }
		virtual void visit_XELDB(ai::XELDB *instr) { this->template visit<ai::XELDB>(instr); }
		virtual void visit_XELDI(ai::XELDI *instr) { this->template visit<ai::XELDI>(instr); }
		virtual void visit_XELDR(ai::XELDR *instr) { this->template visit<ai::XELDR>(instr); }
		virtual void visit_XELDS(ai::XELDS *instr) { this->template visit<ai::XELDS>(instr); }
		virtual void visit_XESTB(ai::XESTB *instr) { this->template visit<ai::XESTB>(instr); }
		virtual void visit_XESTI(ai::XESTI *instr) { this->template visit<ai::XESTI>(instr); }
		virtual void visit_XESTR(ai::XESTR *instr) { this->template visit<ai::XESTR>(instr); }
		virtual void visit_XESTS(ai::XESTS *instr) { this->template visit<ai::XESTS>(instr); }
		virtual void visit_XLDB(ai::XLDB *instr) { this->template visit<ai::XLDB>(instr); }
		virtual void visit_XLDI(ai::XLDI *instr) { this->template visit<ai::XLDI>(instr); }
		virtual void visit_XLDR(ai::XLDR *instr) { this->template visit<ai::XLDR>(instr); }
		virtual void visit_XLDS(ai::XLDS *instr) { this->template visit<ai::XLDS>(instr); }
		virtual void visit_XSTB(ai::XSTB *instr) { this->template visit<ai::XSTB>(instr); }
		virtual void visit_XSTI(ai::XSTI *instr) { this->template visit<ai::XSTI>(instr); }
		virtual void visit_XSTR(ai::XSTR *instr) { this->template visit<ai::XSTR>(instr); }
		virtual void visit_XSTS(ai::XSTS *instr) { this->template visit<ai::XSTS>(instr); }
	};

	template <typename P>
	class ai_templated_const_visitor : public ai_const_visitor, public P {
	public:
		ai_templated_const_visitor( const P & r) : P( r) {}
	private:
		virtual void visit_ADDI(const ai::ADDI *instr) { this->template visit<ai::ADDI>(instr); }
		virtual void visit_ADDP(const ai::ADDP *instr) { this->template visit<ai::ADDP>(instr); }
		virtual void visit_ADDR(const ai::ADDR *instr) { this->template visit<ai::ADDR>(instr); }
		virtual void visit_ADDS(const ai::ADDS *instr) { this->template visit<ai::ADDS>(instr); }
		virtual void visit_AND(const ai::AND *instr) { this->template visit<ai::AND>(instr); }
		virtual void visit_CALL(const ai::CALL *instr) { this->template visit<ai::CALL>(instr); }
		virtual void visit_CVRTIR(const ai::CVRTIR *instr) { this->template visit<ai::CVRTIR>(instr); }
		virtual void visit_CVRTRI(const ai::CVRTRI *instr) { this->template visit<ai::CVRTRI>(instr); }
		virtual void visit_DIVI(const ai::DIVI *instr) { this->template visit<ai::DIVI>(instr); }
		virtual void visit_DIVR(const ai::DIVR *instr) { this->template visit<ai::DIVR>(instr); }
		virtual void visit_DTORB(const ai::DTORB *instr) { this->template visit<ai::DTORB>(instr); }
		virtual void visit_DTORI(const ai::DTORI *instr) { this->template visit<ai::DTORI>(instr); }
		virtual void visit_DTORP(const ai::DTORP *instr) { this->template visit<ai::DTORP>(instr); }
		virtual void visit_DTORR(const ai::DTORR *instr) { this->template visit<ai::DTORR>(instr); }
		virtual void visit_DTORS(const ai::DTORS *instr) { this->template visit<ai::DTORS>(instr); }
		virtual void visit_EADDI(const ai::EADDI *instr) { this->template visit<ai::EADDI>(instr); }
		virtual void visit_EADDP(const ai::EADDP *instr) { this->template visit<ai::EADDP>(instr); }
		virtual void visit_EADDR(const ai::EADDR *instr) { this->template visit<ai::EADDR>(instr); }
		virtual void visit_EADDS(const ai::EADDS *instr) { this->template visit<ai::EADDS>(instr); }
		virtual void visit_EAND(const ai::EAND *instr) { this->template visit<ai::EAND>(instr); }
		virtual void visit_ECVRTIR(const ai::ECVRTIR *instr) { this->template visit<ai::ECVRTIR>(instr); }
		virtual void visit_ECVRTRI(const ai::ECVRTRI *instr) { this->template visit<ai::ECVRTRI>(instr); }
		virtual void visit_EDIVI(const ai::EDIVI *instr) { this->template visit<ai::EDIVI>(instr); }
		virtual void visit_EDIVR(const ai::EDIVR *instr) { this->template visit<ai::EDIVR>(instr); }
		virtual void visit_EEQB(const ai::EEQB *instr) { this->template visit<ai::EEQB>(instr); }
		virtual void visit_EEQI(const ai::EEQI *instr) { this->template visit<ai::EEQI>(instr); }
		virtual void visit_EEQR(const ai::EEQR *instr) { this->template visit<ai::EEQR>(instr); }
		virtual void visit_EEQS(const ai::EEQS *instr) { this->template visit<ai::EEQS>(instr); }
		virtual void visit_EGEB(const ai::EGEB *instr) { this->template visit<ai::EGEB>(instr); }
		virtual void visit_EGEI(const ai::EGEI *instr) { this->template visit<ai::EGEI>(instr); }
		virtual void visit_EGER(const ai::EGER *instr) { this->template visit<ai::EGER>(instr); }
		virtual void visit_EGES(const ai::EGES *instr) { this->template visit<ai::EGES>(instr); }
		virtual void visit_EGTB(const ai::EGTB *instr) { this->template visit<ai::EGTB>(instr); }
		virtual void visit_EGTI(const ai::EGTI *instr) { this->template visit<ai::EGTI>(instr); }
		virtual void visit_EGTR(const ai::EGTR *instr) { this->template visit<ai::EGTR>(instr); }
		virtual void visit_EGTS(const ai::EGTS *instr) { this->template visit<ai::EGTS>(instr); }
		virtual void visit_EINITB(const ai::EINITB *instr) { this->template visit<ai::EINITB>(instr); }
		virtual void visit_EINITI(const ai::EINITI *instr) { this->template visit<ai::EINITI>(instr); }
		virtual void visit_EINITR(const ai::EINITR *instr) { this->template visit<ai::EINITR>(instr); }
		virtual void visit_EINITS(const ai::EINITS *instr) { this->template visit<ai::EINITS>(instr); }
		virtual void visit_ELDLITB(const ai::ELDLITB *instr) { this->template visit<ai::ELDLITB>(instr); }
		virtual void visit_ELDLITI(const ai::ELDLITI *instr) { this->template visit<ai::ELDLITI>(instr); }
		virtual void visit_ELDLITR(const ai::ELDLITR *instr) { this->template visit<ai::ELDLITR>(instr); }
		virtual void visit_ELDLITS(const ai::ELDLITS *instr) { this->template visit<ai::ELDLITS>(instr); }
		virtual void visit_ELEB(const ai::ELEB *instr) { this->template visit<ai::ELEB>(instr); }
		virtual void visit_ELEI(const ai::ELEI *instr) { this->template visit<ai::ELEI>(instr); }
		virtual void visit_ELER(const ai::ELER *instr) { this->template visit<ai::ELER>(instr); }
		virtual void visit_ELES(const ai::ELES *instr) { this->template visit<ai::ELES>(instr); }
		virtual void visit_ELTB(const ai::ELTB *instr) { this->template visit<ai::ELTB>(instr); }
		virtual void visit_ELTI(const ai::ELTI *instr) { this->template visit<ai::ELTI>(instr); }
		virtual void visit_ELTR(const ai::ELTR *instr) { this->template visit<ai::ELTR>(instr); }
		virtual void visit_ELTS(const ai::ELTS *instr) { this->template visit<ai::ELTS>(instr); }
		virtual void visit_EMINUSI(const ai::EMINUSI *instr) { this->template visit<ai::EMINUSI>(instr); }
		virtual void visit_EMINUSR(const ai::EMINUSR *instr) { this->template visit<ai::EMINUSR>(instr); }
		virtual void visit_EMODI(const ai::EMODI *instr) { this->template visit<ai::EMODI>(instr); }
		virtual void visit_EMOVB(const ai::EMOVB *instr) { this->template visit<ai::EMOVB>(instr); }
		virtual void visit_EMOVI(const ai::EMOVI *instr) { this->template visit<ai::EMOVI>(instr); }
		virtual void visit_EMOVP(const ai::EMOVP *instr) { this->template visit<ai::EMOVP>(instr); }
		virtual void visit_EMOVR(const ai::EMOVR *instr) { this->template visit<ai::EMOVR>(instr); }
		virtual void visit_EMOVS(const ai::EMOVS *instr) { this->template visit<ai::EMOVS>(instr); }
		virtual void visit_EMULI(const ai::EMULI *instr) { this->template visit<ai::EMULI>(instr); }
		virtual void visit_EMULR(const ai::EMULR *instr) { this->template visit<ai::EMULR>(instr); }
		virtual void visit_ENEB(const ai::ENEB *instr) { this->template visit<ai::ENEB>(instr); }
		virtual void visit_ENEI(const ai::ENEI *instr) { this->template visit<ai::ENEI>(instr); }
		virtual void visit_ENER(const ai::ENER *instr) { this->template visit<ai::ENER>(instr); }
		virtual void visit_ENES(const ai::ENES *instr) { this->template visit<ai::ENES>(instr); }
		virtual void visit_ENOT(const ai::ENOT *instr) { this->template visit<ai::ENOT>(instr); }
		virtual void visit_EOR(const ai::EOR *instr) { this->template visit<ai::EOR>(instr); }
		virtual void visit_EPOP(const ai::EPOP *instr) { this->template visit<ai::EPOP>(instr); }
		virtual void visit_EPOPB(const ai::EPOPB *instr) { this->template visit<ai::EPOPB>(instr); }
		virtual void visit_EPOPI(const ai::EPOPI *instr) { this->template visit<ai::EPOPI>(instr); }
		virtual void visit_EPOPP(const ai::EPOPP *instr) { this->template visit<ai::EPOPP>(instr); }
		virtual void visit_EPOPR(const ai::EPOPR *instr) { this->template visit<ai::EPOPR>(instr); }
		virtual void visit_EPOPS(const ai::EPOPS *instr) { this->template visit<ai::EPOPS>(instr); }
		virtual void visit_EPUSH(const ai::EPUSH *instr) { this->template visit<ai::EPUSH>(instr); }
		virtual void visit_EPUSHB(const ai::EPUSHB *instr) { this->template visit<ai::EPUSHB>(instr); }
		virtual void visit_EPUSHI(const ai::EPUSHI *instr) { this->template visit<ai::EPUSHI>(instr); }
		virtual void visit_EPUSHP(const ai::EPUSHP *instr) { this->template visit<ai::EPUSHP>(instr); }
		virtual void visit_EPUSHR(const ai::EPUSHR *instr) { this->template visit<ai::EPUSHR>(instr); }
		virtual void visit_EPUSHS(const ai::EPUSHS *instr) { this->template visit<ai::EPUSHS>(instr); }
		virtual void visit_EQB(const ai::EQB *instr) { this->template visit<ai::EQB>(instr); }
		virtual void visit_EQI(const ai::EQI *instr) { this->template visit<ai::EQI>(instr); }
		virtual void visit_EQR(const ai::EQR *instr) { this->template visit<ai::EQR>(instr); }
		virtual void visit_EQS(const ai::EQS *instr) { this->template visit<ai::EQS>(instr); }
		virtual void visit_ESUBI(const ai::ESUBI *instr) { this->template visit<ai::ESUBI>(instr); }
		virtual void visit_ESUBP(const ai::ESUBP *instr) { this->template visit<ai::ESUBP>(instr); }
		virtual void visit_ESUBR(const ai::ESUBR *instr) { this->template visit<ai::ESUBR>(instr); }
		virtual void visit_FNCREADI(const ai::FNCREADI *instr) { this->template visit<ai::FNCREADI>(instr); }
		virtual void visit_FNCREADR(const ai::FNCREADR *instr) { this->template visit<ai::FNCREADR>(instr); }
		virtual void visit_FNCREADS(const ai::FNCREADS *instr) { this->template visit<ai::FNCREADS>(instr); }
		virtual void visit_FNCWRITEI(const ai::FNCWRITEI *instr) { this->template visit<ai::FNCWRITEI>(instr); }
		virtual void visit_FNCWRITELN(const ai::FNCWRITELN *instr) { this->template visit<ai::FNCWRITELN>(instr); }
		virtual void visit_FNCWRITER(const ai::FNCWRITER *instr) { this->template visit<ai::FNCWRITER>(instr); }
		virtual void visit_FNCWRITES(const ai::FNCWRITES *instr) { this->template visit<ai::FNCWRITES>(instr); }
		virtual void visit_GEB(const ai::GEB *instr) { this->template visit<ai::GEB>(instr); }
		virtual void visit_GEI(const ai::GEI *instr) { this->template visit<ai::GEI>(instr); }
		virtual void visit_GELDB(const ai::GELDB *instr) { this->template visit<ai::GELDB>(instr); }
		virtual void visit_GELDI(const ai::GELDI *instr) { this->template visit<ai::GELDI>(instr); }
		virtual void visit_GELDR(const ai::GELDR *instr) { this->template visit<ai::GELDR>(instr); }
		virtual void visit_GELDS(const ai::GELDS *instr) { this->template visit<ai::GELDS>(instr); }
		virtual void visit_GER(const ai::GER *instr) { this->template visit<ai::GER>(instr); }
		virtual void visit_GEREF(const ai::GEREF *instr) { this->template visit<ai::GEREF>(instr); }
		virtual void visit_GES(const ai::GES *instr) { this->template visit<ai::GES>(instr); }
		virtual void visit_GESTB(const ai::GESTB *instr) { this->template visit<ai::GESTB>(instr); }
		virtual void visit_GESTI(const ai::GESTI *instr) { this->template visit<ai::GESTI>(instr); }
		virtual void visit_GESTR(const ai::GESTR *instr) { this->template visit<ai::GESTR>(instr); }
		virtual void visit_GESTS(const ai::GESTS *instr) { this->template visit<ai::GESTS>(instr); }
		virtual void visit_GLDB(const ai::GLDB *instr) { this->template visit<ai::GLDB>(instr); }
		virtual void visit_GLDI(const ai::GLDI *instr) { this->template visit<ai::GLDI>(instr); }
		virtual void visit_GLDR(const ai::GLDR *instr) { this->template visit<ai::GLDR>(instr); }
		virtual void visit_GLDS(const ai::GLDS *instr) { this->template visit<ai::GLDS>(instr); }
		virtual void visit_GREF(const ai::GREF *instr) { this->template visit<ai::GREF>(instr); }
		virtual void visit_GSTB(const ai::GSTB *instr) { this->template visit<ai::GSTB>(instr); }
		virtual void visit_GSTI(const ai::GSTI *instr) { this->template visit<ai::GSTI>(instr); }
		virtual void visit_GSTR(const ai::GSTR *instr) { this->template visit<ai::GSTR>(instr); }
		virtual void visit_GSTS(const ai::GSTS *instr) { this->template visit<ai::GSTS>(instr); }
		virtual void visit_GTB(const ai::GTB *instr) { this->template visit<ai::GTB>(instr); }
		virtual void visit_GTI(const ai::GTI *instr) { this->template visit<ai::GTI>(instr); }
		virtual void visit_GTR(const ai::GTR *instr) { this->template visit<ai::GTR>(instr); }
		virtual void visit_GTS(const ai::GTS *instr) { this->template visit<ai::GTS>(instr); }
		virtual void visit_HALT(const ai::HALT *instr) { this->template visit<ai::HALT>(instr); }
		virtual void visit_INITB(const ai::INITB *instr) { this->template visit<ai::INITB>(instr); }
		virtual void visit_INITI(const ai::INITI *instr) { this->template visit<ai::INITI>(instr); }
		virtual void visit_INITR(const ai::INITR *instr) { this->template visit<ai::INITR>(instr); }
		virtual void visit_INITS(const ai::INITS *instr) { this->template visit<ai::INITS>(instr); }
		virtual void visit_JEF(const ai::JEF *instr) { this->template visit<ai::JEF>(instr); }
		virtual void visit_JET(const ai::JET *instr) { this->template visit<ai::JET>(instr); }
		virtual void visit_JF(const ai::JF *instr) { this->template visit<ai::JF>(instr); }
		virtual void visit_JMP(const ai::JMP *instr) { this->template visit<ai::JMP>(instr); }
		virtual void visit_JT(const ai::JT *instr) { this->template visit<ai::JT>(instr); }
		virtual void visit_LDLITB(const ai::LDLITB *instr) { this->template visit<ai::LDLITB>(instr); }
		virtual void visit_LDLITI(const ai::LDLITI *instr) { this->template visit<ai::LDLITI>(instr); }
		virtual void visit_LDLITR(const ai::LDLITR *instr) { this->template visit<ai::LDLITR>(instr); }
		virtual void visit_LDLITS(const ai::LDLITS *instr) { this->template visit<ai::LDLITS>(instr); }
		virtual void visit_LEB(const ai::LEB *instr) { this->template visit<ai::LEB>(instr); }
		virtual void visit_LEI(const ai::LEI *instr) { this->template visit<ai::LEI>(instr); }
		virtual void visit_LELDB(const ai::LELDB *instr) { this->template visit<ai::LELDB>(instr); }
		virtual void visit_LELDI(const ai::LELDI *instr) { this->template visit<ai::LELDI>(instr); }
		virtual void visit_LELDP(const ai::LELDP *instr) { this->template visit<ai::LELDP>(instr); }
		virtual void visit_LELDR(const ai::LELDR *instr) { this->template visit<ai::LELDR>(instr); }
		virtual void visit_LELDS(const ai::LELDS *instr) { this->template visit<ai::LELDS>(instr); }
		virtual void visit_LER(const ai::LER *instr) { this->template visit<ai::LER>(instr); }
		virtual void visit_LEREF(const ai::LEREF *instr) { this->template visit<ai::LEREF>(instr); }
		virtual void visit_LES(const ai::LES *instr) { this->template visit<ai::LES>(instr); }
		virtual void visit_LESTB(const ai::LESTB *instr) { this->template visit<ai::LESTB>(instr); }
		virtual void visit_LESTI(const ai::LESTI *instr) { this->template visit<ai::LESTI>(instr); }
		virtual void visit_LESTP(const ai::LESTP *instr) { this->template visit<ai::LESTP>(instr); }
		virtual void visit_LESTR(const ai::LESTR *instr) { this->template visit<ai::LESTR>(instr); }
		virtual void visit_LESTS(const ai::LESTS *instr) { this->template visit<ai::LESTS>(instr); }
		virtual void visit_LLDB(const ai::LLDB *instr) { this->template visit<ai::LLDB>(instr); }
		virtual void visit_LLDI(const ai::LLDI *instr) { this->template visit<ai::LLDI>(instr); }
		virtual void visit_LLDP(const ai::LLDP *instr) { this->template visit<ai::LLDP>(instr); }
		virtual void visit_LLDR(const ai::LLDR *instr) { this->template visit<ai::LLDR>(instr); }
		virtual void visit_LLDS(const ai::LLDS *instr) { this->template visit<ai::LLDS>(instr); }
		virtual void visit_LREF(const ai::LREF *instr) { this->template visit<ai::LREF>(instr); }
		virtual void visit_LSTB(const ai::LSTB *instr) { this->template visit<ai::LSTB>(instr); }
		virtual void visit_LSTI(const ai::LSTI *instr) { this->template visit<ai::LSTI>(instr); }
		virtual void visit_LSTR(const ai::LSTR *instr) { this->template visit<ai::LSTR>(instr); }
		virtual void visit_LSTS(const ai::LSTS *instr) { this->template visit<ai::LSTS>(instr); }
		virtual void visit_LTB(const ai::LTB *instr) { this->template visit<ai::LTB>(instr); }
		virtual void visit_LTI(const ai::LTI *instr) { this->template visit<ai::LTI>(instr); }
		virtual void visit_LTR(const ai::LTR *instr) { this->template visit<ai::LTR>(instr); }
		virtual void visit_LTS(const ai::LTS *instr) { this->template visit<ai::LTS>(instr); }
		virtual void visit_MINUSI(const ai::MINUSI *instr) { this->template visit<ai::MINUSI>(instr); }
		virtual void visit_MINUSR(const ai::MINUSR *instr) { this->template visit<ai::MINUSR>(instr); }
		virtual void visit_MODI(const ai::MODI *instr) { this->template visit<ai::MODI>(instr); }
		virtual void visit_MULI(const ai::MULI *instr) { this->template visit<ai::MULI>(instr); }
		virtual void visit_MULR(const ai::MULR *instr) { this->template visit<ai::MULR>(instr); }
		virtual void visit_NEB(const ai::NEB *instr) { this->template visit<ai::NEB>(instr); }
		virtual void visit_NEI(const ai::NEI *instr) { this->template visit<ai::NEI>(instr); }
		virtual void visit_NER(const ai::NER *instr) { this->template visit<ai::NER>(instr); }
		virtual void visit_NES(const ai::NES *instr) { this->template visit<ai::NES>(instr); }
		virtual void visit_NOP(const ai::NOP *instr) { this->template visit<ai::NOP>(instr); }
		virtual void visit_NOT(const ai::NOT *instr) { this->template visit<ai::NOT>(instr); }
		virtual void visit_OR(const ai::OR *instr) { this->template visit<ai::OR>(instr); }
		virtual void visit_RET(const ai::RET *instr) { this->template visit<ai::RET>(instr); }
		virtual void visit_SADD(const ai::SADD *instr) { this->template visit<ai::SADD>(instr); }
		virtual void visit_SLDB(const ai::SLDB *instr) { this->template visit<ai::SLDB>(instr); }
		virtual void visit_SLDI(const ai::SLDI *instr) { this->template visit<ai::SLDI>(instr); }
		virtual void visit_SLDP(const ai::SLDP *instr) { this->template visit<ai::SLDP>(instr); }
		virtual void visit_SLDR(const ai::SLDR *instr) { this->template visit<ai::SLDR>(instr); }
		virtual void visit_SLDS(const ai::SLDS *instr) { this->template visit<ai::SLDS>(instr); }
		virtual void visit_SREF(const ai::SREF *instr) { this->template visit<ai::SREF>(instr); }
		virtual void visit_SSTB(const ai::SSTB *instr) { this->template visit<ai::SSTB>(instr); }
		virtual void visit_SSTI(const ai::SSTI *instr) { this->template visit<ai::SSTI>(instr); }
		virtual void visit_SSTP(const ai::SSTP *instr) { this->template visit<ai::SSTP>(instr); }
		virtual void visit_SSTR(const ai::SSTR *instr) { this->template visit<ai::SSTR>(instr); }
		virtual void visit_SSTS(const ai::SSTS *instr) { this->template visit<ai::SSTS>(instr); }
		virtual void visit_SUBI(const ai::SUBI *instr) { this->template visit<ai::SUBI>(instr); }
		virtual void visit_SUBP(const ai::SUBP *instr) { this->template visit<ai::SUBP>(instr); }
		virtual void visit_SUBR(const ai::SUBR *instr) { this->template visit<ai::SUBR>(instr); }
		virtual void visit_XELDB(const ai::XELDB *instr) { this->template visit<ai::XELDB>(instr); }
		virtual void visit_XELDI(const ai::XELDI *instr) { this->template visit<ai::XELDI>(instr); }
		virtual void visit_XELDR(const ai::XELDR *instr) { this->template visit<ai::XELDR>(instr); }
		virtual void visit_XELDS(const ai::XELDS *instr) { this->template visit<ai::XELDS>(instr); }
		virtual void visit_XESTB(const ai::XESTB *instr) { this->template visit<ai::XESTB>(instr); }
		virtual void visit_XESTI(const ai::XESTI *instr) { this->template visit<ai::XESTI>(instr); }
		virtual void visit_XESTR(const ai::XESTR *instr) { this->template visit<ai::XESTR>(instr); }
		virtual void visit_XESTS(const ai::XESTS *instr) { this->template visit<ai::XESTS>(instr); }
		virtual void visit_XLDB(const ai::XLDB *instr) { this->template visit<ai::XLDB>(instr); }
		virtual void visit_XLDI(const ai::XLDI *instr) { this->template visit<ai::XLDI>(instr); }
		virtual void visit_XLDR(const ai::XLDR *instr) { this->template visit<ai::XLDR>(instr); }
		virtual void visit_XLDS(const ai::XLDS *instr) { this->template visit<ai::XLDS>(instr); }
		virtual void visit_XSTB(const ai::XSTB *instr) { this->template visit<ai::XSTB>(instr); }
		virtual void visit_XSTI(const ai::XSTI *instr) { this->template visit<ai::XSTI>(instr); }
		virtual void visit_XSTR(const ai::XSTR *instr) { this->template visit<ai::XSTR>(instr); }
		virtual void visit_XSTS(const ai::XSTS *instr) { this->template visit<ai::XSTS>(instr); }
	};



	class ADDI : public mlaskal::abstract_instr {
	public:
		ADDI() : mlaskal::abstract_instr(ai::ICOP_ADDI, 0, 0, 0, 0, 0) { }
		ADDI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_ADDI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_ADDI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_ADDI(this); }
	};

	class ADDP : public mlaskal::abstract_instr {
	public:
		ADDP() : mlaskal::abstract_instr(ai::ICOP_ADDP, 0, 0, 0, 0, 0) { }
		ADDP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_ADDP, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_ADDP(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_ADDP(this); }
	};

	class ADDR : public mlaskal::abstract_instr {
	public:
		ADDR() : mlaskal::abstract_instr(ai::ICOP_ADDR, 0, 0, 0, 0, 0) { }
		ADDR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_ADDR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_ADDR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_ADDR(this); }
	};

	class ADDS : public mlaskal::abstract_instr {
	public:
		ADDS() : mlaskal::abstract_instr(ai::ICOP_ADDS, 0, 0, 0, 0, 0) { }
		ADDS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_ADDS, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_ADDS(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_ADDS(this); }
	};

	class AND : public mlaskal::abstract_instr {
	public:
		AND() : mlaskal::abstract_instr(ai::ICOP_AND, 0, 0, 0, 0, 0) { }
		AND(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_AND, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_AND(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_AND(this); }
	};

	class CALL : public mlaskal::abstract_instr {
	public:
		CALL(mlaskal::abstract_functions::const_iterator tgt) : mlaskal::abstract_instr(ai::ICOP_CALL, 0, tgt, 0, 0, 0, 0) { }
		CALL(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_CALL, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator tgt) { absjump_=tgt; }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_CALL(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_CALL(this); }
	};

	class CVRTIR : public mlaskal::abstract_instr {
	public:
		CVRTIR() : mlaskal::abstract_instr(ai::ICOP_CVRTIR, 0, 0, 0, 0, 0) { }
		CVRTIR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_CVRTIR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_CVRTIR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_CVRTIR(this); }
	};

	class CVRTRI : public mlaskal::abstract_instr {
	public:
		CVRTRI() : mlaskal::abstract_instr(ai::ICOP_CVRTRI, 0, 0, 0, 0, 0) { }
		CVRTRI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_CVRTRI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_CVRTRI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_CVRTRI(this); }
	};

	class DIVI : public mlaskal::abstract_instr {
	public:
		DIVI() : mlaskal::abstract_instr(ai::ICOP_DIVI, 0, 0, 0, 0, 0) { }
		DIVI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_DIVI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_DIVI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_DIVI(this); }
	};

	class DIVR : public mlaskal::abstract_instr {
	public:
		DIVR() : mlaskal::abstract_instr(ai::ICOP_DIVR, 0, 0, 0, 0, 0) { }
		DIVR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_DIVR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_DIVR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_DIVR(this); }
	};

	class DTORB : public mlaskal::abstract_instr {
	public:
		DTORB() : mlaskal::abstract_instr(ai::ICOP_DTORB, 0, 0, 0, 0, 0) { }
		DTORB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_DTORB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_DTORB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_DTORB(this); }
	};

	class DTORI : public mlaskal::abstract_instr {
	public:
		DTORI() : mlaskal::abstract_instr(ai::ICOP_DTORI, 0, 0, 0, 0, 0) { }
		DTORI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_DTORI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_DTORI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_DTORI(this); }
	};

	class DTORP : public mlaskal::abstract_instr {
	public:
		DTORP() : mlaskal::abstract_instr(ai::ICOP_DTORP, 0, 0, 0, 0, 0) { }
		DTORP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_DTORP, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_DTORP(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_DTORP(this); }
	};

	class DTORR : public mlaskal::abstract_instr {
	public:
		DTORR() : mlaskal::abstract_instr(ai::ICOP_DTORR, 0, 0, 0, 0, 0) { }
		DTORR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_DTORR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_DTORR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_DTORR(this); }
	};

	class DTORS : public mlaskal::abstract_instr {
	public:
		DTORS() : mlaskal::abstract_instr(ai::ICOP_DTORS, 0, 0, 0, 0, 0) { }
		DTORS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_DTORS, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_DTORS(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_DTORS(this); }
	};

	class EADDI : public mlaskal::abstract_instr {
	public:
		EADDI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_EADDI, out, in1, in2, 0, 0) { }
		EADDI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EADDI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EADDI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EADDI(this); }
	};

	class EADDP : public mlaskal::abstract_instr {
	public:
		EADDP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_EADDP, out, in1, in2, 0, 0) { }
		EADDP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EADDP, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EADDP(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EADDP(this); }
	};

	class EADDR : public mlaskal::abstract_instr {
	public:
		EADDR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_EADDR, out, in1, in2, 0, 0) { }
		EADDR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EADDR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EADDR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EADDR(this); }
	};

	class EADDS : public mlaskal::abstract_instr {
	public:
		EADDS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_EADDS, out, in1, in2, 0, 0) { }
		EADDS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EADDS, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EADDS(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EADDS(this); }
	};

	class EAND : public mlaskal::abstract_instr {
	public:
		EAND(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_EAND, out, in1, in2, 0, 0) { }
		EAND(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EAND, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EAND(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EAND(this); }
	};

	class ECVRTIR : public mlaskal::abstract_instr {
	public:
		ECVRTIR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1) : mlaskal::abstract_instr(ai::ICOP_ECVRTIR, out, in1, 0, 0, 0) { }
		ECVRTIR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_ECVRTIR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_ECVRTIR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_ECVRTIR(this); }
	};

	class ECVRTRI : public mlaskal::abstract_instr {
	public:
		ECVRTRI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1) : mlaskal::abstract_instr(ai::ICOP_ECVRTRI, out, in1, 0, 0, 0) { }
		ECVRTRI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_ECVRTRI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_ECVRTRI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_ECVRTRI(this); }
	};

	class EDIVI : public mlaskal::abstract_instr {
	public:
		EDIVI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_EDIVI, out, in1, in2, 0, 0) { }
		EDIVI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EDIVI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EDIVI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EDIVI(this); }
	};

	class EDIVR : public mlaskal::abstract_instr {
	public:
		EDIVR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_EDIVR, out, in1, in2, 0, 0) { }
		EDIVR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EDIVR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EDIVR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EDIVR(this); }
	};

	class EEQB : public mlaskal::abstract_instr {
	public:
		EEQB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_EEQB, out, in1, in2, 0, 0) { }
		EEQB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EEQB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EEQB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EEQB(this); }
	};

	class EEQI : public mlaskal::abstract_instr {
	public:
		EEQI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_EEQI, out, in1, in2, 0, 0) { }
		EEQI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EEQI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EEQI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EEQI(this); }
	};

	class EEQR : public mlaskal::abstract_instr {
	public:
		EEQR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_EEQR, out, in1, in2, 0, 0) { }
		EEQR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EEQR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EEQR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EEQR(this); }
	};

	class EEQS : public mlaskal::abstract_instr {
	public:
		EEQS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_EEQS, out, in1, in2, 0, 0) { }
		EEQS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EEQS, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EEQS(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EEQS(this); }
	};

	class EGEB : public mlaskal::abstract_instr {
	public:
		EGEB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_EGEB, out, in1, in2, 0, 0) { }
		EGEB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EGEB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EGEB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EGEB(this); }
	};

	class EGEI : public mlaskal::abstract_instr {
	public:
		EGEI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_EGEI, out, in1, in2, 0, 0) { }
		EGEI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EGEI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EGEI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EGEI(this); }
	};

	class EGER : public mlaskal::abstract_instr {
	public:
		EGER(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_EGER, out, in1, in2, 0, 0) { }
		EGER(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EGER, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EGER(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EGER(this); }
	};

	class EGES : public mlaskal::abstract_instr {
	public:
		EGES(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_EGES, out, in1, in2, 0, 0) { }
		EGES(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EGES, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EGES(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EGES(this); }
	};

	class EGTB : public mlaskal::abstract_instr {
	public:
		EGTB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_EGTB, out, in1, in2, 0, 0) { }
		EGTB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EGTB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EGTB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EGTB(this); }
	};

	class EGTI : public mlaskal::abstract_instr {
	public:
		EGTI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_EGTI, out, in1, in2, 0, 0) { }
		EGTI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EGTI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EGTI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EGTI(this); }
	};

	class EGTR : public mlaskal::abstract_instr {
	public:
		EGTR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_EGTR, out, in1, in2, 0, 0) { }
		EGTR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EGTR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EGTR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EGTR(this); }
	};

	class EGTS : public mlaskal::abstract_instr {
	public:
		EGTS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_EGTS, out, in1, in2, 0, 0) { }
		EGTS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EGTS, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EGTS(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EGTS(this); }
	};

	class EINITB : public mlaskal::abstract_instr {
	public:
		EINITB(mlaskal::ICREGNUM out) : mlaskal::abstract_instr(ai::ICOP_EINITB, out, 0, 0, 0, 0) { }
		EINITB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EINITB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EINITB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EINITB(this); }
	};

	class EINITI : public mlaskal::abstract_instr {
	public:
		EINITI(mlaskal::ICREGNUM out) : mlaskal::abstract_instr(ai::ICOP_EINITI, out, 0, 0, 0, 0) { }
		EINITI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EINITI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EINITI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EINITI(this); }
	};

	class EINITR : public mlaskal::abstract_instr {
	public:
		EINITR(mlaskal::ICREGNUM out) : mlaskal::abstract_instr(ai::ICOP_EINITR, out, 0, 0, 0, 0) { }
		EINITR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EINITR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EINITR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EINITR(this); }
	};

	class EINITS : public mlaskal::abstract_instr {
	public:
		EINITS(mlaskal::ICREGNUM out) : mlaskal::abstract_instr(ai::ICOP_EINITS, out, 0, 0, 0, 0) { }
		EINITS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EINITS, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EINITS(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EINITS(this); }
	};

	class ELDLITB : public mlaskal::abstract_instr {
	public:
		ELDLITB(mlaskal::ICREGNUM out, mlaskal::ICABSNUM absnum) : mlaskal::abstract_instr(ai::ICOP_ELDLITB, out, absnum, 0, 0, 0, 0) { }
		ELDLITB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_ELDLITB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM absnum) { absnum_=absnum; }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_ELDLITB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_ELDLITB(this); }
	};

	class ELDLITI : public mlaskal::abstract_instr {
	public:
		ELDLITI(mlaskal::ICREGNUM out, mlaskal::aic_literal_storage_int_type::const_pointer litint) : mlaskal::abstract_instr(ai::ICOP_ELDLITI, out, litint, 0, 0, 0, 0) { }
		ELDLITI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_ELDLITI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer litint) { litint_=litint; }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_ELDLITI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_ELDLITI(this); }
	};

	class ELDLITR : public mlaskal::abstract_instr {
	public:
		ELDLITR(mlaskal::ICREGNUM out, mlaskal::aic_literal_storage_real_type::const_pointer litreal) : mlaskal::abstract_instr(ai::ICOP_ELDLITR, out, litreal, 0, 0, 0, 0) { }
		ELDLITR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_ELDLITR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer litreal) { litreal_=litreal; }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_ELDLITR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_ELDLITR(this); }
	};

	class ELDLITS : public mlaskal::abstract_instr {
	public:
		ELDLITS(mlaskal::ICREGNUM out, mlaskal::aic_literal_storage_string_type::const_pointer litstr) : mlaskal::abstract_instr(ai::ICOP_ELDLITS, out, litstr, 0, 0, 0, 0) { }
		ELDLITS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_ELDLITS, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer litstr) { litstr_=litstr; }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_ELDLITS(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_ELDLITS(this); }
	};

	class ELEB : public mlaskal::abstract_instr {
	public:
		ELEB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_ELEB, out, in1, in2, 0, 0) { }
		ELEB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_ELEB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_ELEB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_ELEB(this); }
	};

	class ELEI : public mlaskal::abstract_instr {
	public:
		ELEI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_ELEI, out, in1, in2, 0, 0) { }
		ELEI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_ELEI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_ELEI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_ELEI(this); }
	};

	class ELER : public mlaskal::abstract_instr {
	public:
		ELER(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_ELER, out, in1, in2, 0, 0) { }
		ELER(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_ELER, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_ELER(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_ELER(this); }
	};

	class ELES : public mlaskal::abstract_instr {
	public:
		ELES(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_ELES, out, in1, in2, 0, 0) { }
		ELES(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_ELES, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_ELES(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_ELES(this); }
	};

	class ELTB : public mlaskal::abstract_instr {
	public:
		ELTB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_ELTB, out, in1, in2, 0, 0) { }
		ELTB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_ELTB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_ELTB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_ELTB(this); }
	};

	class ELTI : public mlaskal::abstract_instr {
	public:
		ELTI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_ELTI, out, in1, in2, 0, 0) { }
		ELTI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_ELTI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_ELTI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_ELTI(this); }
	};

	class ELTR : public mlaskal::abstract_instr {
	public:
		ELTR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_ELTR, out, in1, in2, 0, 0) { }
		ELTR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_ELTR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_ELTR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_ELTR(this); }
	};

	class ELTS : public mlaskal::abstract_instr {
	public:
		ELTS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_ELTS, out, in1, in2, 0, 0) { }
		ELTS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_ELTS, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_ELTS(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_ELTS(this); }
	};

	class EMINUSI : public mlaskal::abstract_instr {
	public:
		EMINUSI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1) : mlaskal::abstract_instr(ai::ICOP_EMINUSI, out, in1, 0, 0, 0) { }
		EMINUSI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EMINUSI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EMINUSI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EMINUSI(this); }
	};

	class EMINUSR : public mlaskal::abstract_instr {
	public:
		EMINUSR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1) : mlaskal::abstract_instr(ai::ICOP_EMINUSR, out, in1, 0, 0, 0) { }
		EMINUSR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EMINUSR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EMINUSR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EMINUSR(this); }
	};

	class EMODI : public mlaskal::abstract_instr {
	public:
		EMODI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_EMODI, out, in1, in2, 0, 0) { }
		EMODI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EMODI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EMODI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EMODI(this); }
	};

	class EMOVB : public mlaskal::abstract_instr {
	public:
		EMOVB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1) : mlaskal::abstract_instr(ai::ICOP_EMOVB, out, in1, 0, 0, 0) { }
		EMOVB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EMOVB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EMOVB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EMOVB(this); }
	};

	class EMOVI : public mlaskal::abstract_instr {
	public:
		EMOVI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1) : mlaskal::abstract_instr(ai::ICOP_EMOVI, out, in1, 0, 0, 0) { }
		EMOVI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EMOVI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EMOVI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EMOVI(this); }
	};

	class EMOVP : public mlaskal::abstract_instr {
	public:
		EMOVP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1) : mlaskal::abstract_instr(ai::ICOP_EMOVP, out, in1, 0, 0, 0) { }
		EMOVP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EMOVP, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EMOVP(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EMOVP(this); }
	};

	class EMOVR : public mlaskal::abstract_instr {
	public:
		EMOVR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1) : mlaskal::abstract_instr(ai::ICOP_EMOVR, out, in1, 0, 0, 0) { }
		EMOVR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EMOVR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EMOVR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EMOVR(this); }
	};

	class EMOVS : public mlaskal::abstract_instr {
	public:
		EMOVS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1) : mlaskal::abstract_instr(ai::ICOP_EMOVS, out, in1, 0, 0, 0) { }
		EMOVS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EMOVS, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EMOVS(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EMOVS(this); }
	};

	class EMULI : public mlaskal::abstract_instr {
	public:
		EMULI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_EMULI, out, in1, in2, 0, 0) { }
		EMULI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EMULI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EMULI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EMULI(this); }
	};

	class EMULR : public mlaskal::abstract_instr {
	public:
		EMULR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_EMULR, out, in1, in2, 0, 0) { }
		EMULR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EMULR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EMULR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EMULR(this); }
	};

	class ENEB : public mlaskal::abstract_instr {
	public:
		ENEB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_ENEB, out, in1, in2, 0, 0) { }
		ENEB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_ENEB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_ENEB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_ENEB(this); }
	};

	class ENEI : public mlaskal::abstract_instr {
	public:
		ENEI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_ENEI, out, in1, in2, 0, 0) { }
		ENEI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_ENEI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_ENEI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_ENEI(this); }
	};

	class ENER : public mlaskal::abstract_instr {
	public:
		ENER(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_ENER, out, in1, in2, 0, 0) { }
		ENER(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_ENER, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_ENER(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_ENER(this); }
	};

	class ENES : public mlaskal::abstract_instr {
	public:
		ENES(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_ENES, out, in1, in2, 0, 0) { }
		ENES(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_ENES, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_ENES(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_ENES(this); }
	};

	class ENOT : public mlaskal::abstract_instr {
	public:
		ENOT(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1) : mlaskal::abstract_instr(ai::ICOP_ENOT, out, in1, 0, 0, 0) { }
		ENOT(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_ENOT, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_ENOT(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_ENOT(this); }
	};

	class EOR : public mlaskal::abstract_instr {
	public:
		EOR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_EOR, out, in1, in2, 0, 0) { }
		EOR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EOR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EOR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EOR(this); }
	};

	class EPOP : public mlaskal::abstract_instr {
	public:
		EPOP(mlaskal::ICREGNUM out) : mlaskal::abstract_instr(ai::ICOP_EPOP, out, 0, 0, 0, 0) { }
		EPOP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EPOP, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EPOP(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EPOP(this); }
	};

	class EPOPB : public mlaskal::abstract_instr {
	public:
		EPOPB(mlaskal::ICREGNUM out) : mlaskal::abstract_instr(ai::ICOP_EPOPB, out, 0, 0, 0, 0) { }
		EPOPB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EPOPB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EPOPB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EPOPB(this); }
	};

	class EPOPI : public mlaskal::abstract_instr {
	public:
		EPOPI(mlaskal::ICREGNUM out) : mlaskal::abstract_instr(ai::ICOP_EPOPI, out, 0, 0, 0, 0) { }
		EPOPI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EPOPI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EPOPI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EPOPI(this); }
	};

	class EPOPP : public mlaskal::abstract_instr {
	public:
		EPOPP(mlaskal::ICREGNUM out) : mlaskal::abstract_instr(ai::ICOP_EPOPP, out, 0, 0, 0, 0) { }
		EPOPP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EPOPP, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EPOPP(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EPOPP(this); }
	};

	class EPOPR : public mlaskal::abstract_instr {
	public:
		EPOPR(mlaskal::ICREGNUM out) : mlaskal::abstract_instr(ai::ICOP_EPOPR, out, 0, 0, 0, 0) { }
		EPOPR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EPOPR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EPOPR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EPOPR(this); }
	};

	class EPOPS : public mlaskal::abstract_instr {
	public:
		EPOPS(mlaskal::ICREGNUM out) : mlaskal::abstract_instr(ai::ICOP_EPOPS, out, 0, 0, 0, 0) { }
		EPOPS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EPOPS, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EPOPS(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EPOPS(this); }
	};

	class EPUSH : public mlaskal::abstract_instr {
	public:
		EPUSH(mlaskal::ICREGNUM in1) : mlaskal::abstract_instr(ai::ICOP_EPUSH, 0, in1, 0, 0, 0) { }
		EPUSH(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EPUSH, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EPUSH(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EPUSH(this); }
	};

	class EPUSHB : public mlaskal::abstract_instr {
	public:
		EPUSHB(mlaskal::ICREGNUM in1) : mlaskal::abstract_instr(ai::ICOP_EPUSHB, 0, in1, 0, 0, 0) { }
		EPUSHB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EPUSHB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EPUSHB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EPUSHB(this); }
	};

	class EPUSHI : public mlaskal::abstract_instr {
	public:
		EPUSHI(mlaskal::ICREGNUM in1) : mlaskal::abstract_instr(ai::ICOP_EPUSHI, 0, in1, 0, 0, 0) { }
		EPUSHI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EPUSHI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EPUSHI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EPUSHI(this); }
	};

	class EPUSHP : public mlaskal::abstract_instr {
	public:
		EPUSHP(mlaskal::ICREGNUM in1) : mlaskal::abstract_instr(ai::ICOP_EPUSHP, 0, in1, 0, 0, 0) { }
		EPUSHP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EPUSHP, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EPUSHP(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EPUSHP(this); }
	};

	class EPUSHR : public mlaskal::abstract_instr {
	public:
		EPUSHR(mlaskal::ICREGNUM in1) : mlaskal::abstract_instr(ai::ICOP_EPUSHR, 0, in1, 0, 0, 0) { }
		EPUSHR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EPUSHR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EPUSHR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EPUSHR(this); }
	};

	class EPUSHS : public mlaskal::abstract_instr {
	public:
		EPUSHS(mlaskal::ICREGNUM in1) : mlaskal::abstract_instr(ai::ICOP_EPUSHS, 0, in1, 0, 0, 0) { }
		EPUSHS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EPUSHS, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EPUSHS(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EPUSHS(this); }
	};

	class EQB : public mlaskal::abstract_instr {
	public:
		EQB() : mlaskal::abstract_instr(ai::ICOP_EQB, 0, 0, 0, 0, 0) { }
		EQB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EQB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EQB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EQB(this); }
	};

	class EQI : public mlaskal::abstract_instr {
	public:
		EQI() : mlaskal::abstract_instr(ai::ICOP_EQI, 0, 0, 0, 0, 0) { }
		EQI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EQI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EQI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EQI(this); }
	};

	class EQR : public mlaskal::abstract_instr {
	public:
		EQR() : mlaskal::abstract_instr(ai::ICOP_EQR, 0, 0, 0, 0, 0) { }
		EQR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EQR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EQR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EQR(this); }
	};

	class EQS : public mlaskal::abstract_instr {
	public:
		EQS() : mlaskal::abstract_instr(ai::ICOP_EQS, 0, 0, 0, 0, 0) { }
		EQS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_EQS, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_EQS(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_EQS(this); }
	};

	class ESUBI : public mlaskal::abstract_instr {
	public:
		ESUBI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_ESUBI, out, in1, in2, 0, 0) { }
		ESUBI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_ESUBI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_ESUBI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_ESUBI(this); }
	};

	class ESUBP : public mlaskal::abstract_instr {
	public:
		ESUBP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_ESUBP, out, in1, in2, 0, 0) { }
		ESUBP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_ESUBP, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_ESUBP(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_ESUBP(this); }
	};

	class ESUBR : public mlaskal::abstract_instr {
	public:
		ESUBR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_ESUBR, out, in1, in2, 0, 0) { }
		ESUBR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_ESUBR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_ESUBR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_ESUBR(this); }
	};

	class FNCREADI : public mlaskal::abstract_instr {
	public:
		FNCREADI() : mlaskal::abstract_instr(ai::ICOP_FNCREADI, 0, 0, 0, 0, 0) { }
		FNCREADI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_FNCREADI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_FNCREADI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_FNCREADI(this); }
	};

	class FNCREADR : public mlaskal::abstract_instr {
	public:
		FNCREADR() : mlaskal::abstract_instr(ai::ICOP_FNCREADR, 0, 0, 0, 0, 0) { }
		FNCREADR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_FNCREADR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_FNCREADR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_FNCREADR(this); }
	};

	class FNCREADS : public mlaskal::abstract_instr {
	public:
		FNCREADS() : mlaskal::abstract_instr(ai::ICOP_FNCREADS, 0, 0, 0, 0, 0) { }
		FNCREADS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_FNCREADS, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_FNCREADS(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_FNCREADS(this); }
	};

	class FNCWRITEI : public mlaskal::abstract_instr {
	public:
		FNCWRITEI() : mlaskal::abstract_instr(ai::ICOP_FNCWRITEI, 0, 0, 0, 0, 0) { }
		FNCWRITEI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_FNCWRITEI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_FNCWRITEI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_FNCWRITEI(this); }
	};

	class FNCWRITELN : public mlaskal::abstract_instr {
	public:
		FNCWRITELN() : mlaskal::abstract_instr(ai::ICOP_FNCWRITELN, 0, 0, 0, 0, 0) { }
		FNCWRITELN(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_FNCWRITELN, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_FNCWRITELN(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_FNCWRITELN(this); }
	};

	class FNCWRITER : public mlaskal::abstract_instr {
	public:
		FNCWRITER() : mlaskal::abstract_instr(ai::ICOP_FNCWRITER, 0, 0, 0, 0, 0) { }
		FNCWRITER(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_FNCWRITER, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_FNCWRITER(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_FNCWRITER(this); }
	};

	class FNCWRITES : public mlaskal::abstract_instr {
	public:
		FNCWRITES() : mlaskal::abstract_instr(ai::ICOP_FNCWRITES, 0, 0, 0, 0, 0) { }
		FNCWRITES(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_FNCWRITES, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_FNCWRITES(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_FNCWRITES(this); }
	};

	class GEB : public mlaskal::abstract_instr {
	public:
		GEB() : mlaskal::abstract_instr(ai::ICOP_GEB, 0, 0, 0, 0, 0) { }
		GEB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_GEB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_GEB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_GEB(this); }
	};

	class GEI : public mlaskal::abstract_instr {
	public:
		GEI() : mlaskal::abstract_instr(ai::ICOP_GEI, 0, 0, 0, 0, 0) { }
		GEI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_GEI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_GEI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_GEI(this); }
	};

	class GELDB : public mlaskal::abstract_instr {
	public:
		GELDB(mlaskal::ICREGNUM out, mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_GELDB, out, stkoffs, 0, 0, 0, 0) { }
		GELDB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_GELDB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_GELDB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_GELDB(this); }
	};

	class GELDI : public mlaskal::abstract_instr {
	public:
		GELDI(mlaskal::ICREGNUM out, mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_GELDI, out, stkoffs, 0, 0, 0, 0) { }
		GELDI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_GELDI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_GELDI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_GELDI(this); }
	};

	class GELDR : public mlaskal::abstract_instr {
	public:
		GELDR(mlaskal::ICREGNUM out, mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_GELDR, out, stkoffs, 0, 0, 0, 0) { }
		GELDR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_GELDR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_GELDR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_GELDR(this); }
	};

	class GELDS : public mlaskal::abstract_instr {
	public:
		GELDS(mlaskal::ICREGNUM out, mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_GELDS, out, stkoffs, 0, 0, 0, 0) { }
		GELDS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_GELDS, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_GELDS(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_GELDS(this); }
	};

	class GER : public mlaskal::abstract_instr {
	public:
		GER() : mlaskal::abstract_instr(ai::ICOP_GER, 0, 0, 0, 0, 0) { }
		GER(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_GER, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_GER(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_GER(this); }
	};

	class GEREF : public mlaskal::abstract_instr {
	public:
		GEREF(mlaskal::ICREGNUM out, mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_GEREF, out, stkoffs, 0, 0, 0, 0) { }
		GEREF(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_GEREF, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_GEREF(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_GEREF(this); }
	};

	class GES : public mlaskal::abstract_instr {
	public:
		GES() : mlaskal::abstract_instr(ai::ICOP_GES, 0, 0, 0, 0, 0) { }
		GES(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_GES, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_GES(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_GES(this); }
	};

	class GESTB : public mlaskal::abstract_instr {
	public:
		GESTB(mlaskal::ICRELNUM stkoffs, mlaskal::ICREGNUM in1) : mlaskal::abstract_instr(ai::ICOP_GESTB, 0, stkoffs, in1, 0, 0, 0) { }
		GESTB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_GESTB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_GESTB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_GESTB(this); }
	};

	class GESTI : public mlaskal::abstract_instr {
	public:
		GESTI(mlaskal::ICRELNUM stkoffs, mlaskal::ICREGNUM in1) : mlaskal::abstract_instr(ai::ICOP_GESTI, 0, stkoffs, in1, 0, 0, 0) { }
		GESTI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_GESTI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_GESTI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_GESTI(this); }
	};

	class GESTR : public mlaskal::abstract_instr {
	public:
		GESTR(mlaskal::ICRELNUM stkoffs, mlaskal::ICREGNUM in1) : mlaskal::abstract_instr(ai::ICOP_GESTR, 0, stkoffs, in1, 0, 0, 0) { }
		GESTR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_GESTR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_GESTR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_GESTR(this); }
	};

	class GESTS : public mlaskal::abstract_instr {
	public:
		GESTS(mlaskal::ICRELNUM stkoffs, mlaskal::ICREGNUM in1) : mlaskal::abstract_instr(ai::ICOP_GESTS, 0, stkoffs, in1, 0, 0, 0) { }
		GESTS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_GESTS, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_GESTS(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_GESTS(this); }
	};

	class GLDB : public mlaskal::abstract_instr {
	public:
		GLDB(mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_GLDB, 0, stkoffs, 0, 0, 0, 0) { }
		GLDB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_GLDB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_GLDB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_GLDB(this); }
	};

	class GLDI : public mlaskal::abstract_instr {
	public:
		GLDI(mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_GLDI, 0, stkoffs, 0, 0, 0, 0) { }
		GLDI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_GLDI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_GLDI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_GLDI(this); }
	};

	class GLDR : public mlaskal::abstract_instr {
	public:
		GLDR(mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_GLDR, 0, stkoffs, 0, 0, 0, 0) { }
		GLDR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_GLDR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_GLDR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_GLDR(this); }
	};

	class GLDS : public mlaskal::abstract_instr {
	public:
		GLDS(mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_GLDS, 0, stkoffs, 0, 0, 0, 0) { }
		GLDS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_GLDS, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_GLDS(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_GLDS(this); }
	};

	class GREF : public mlaskal::abstract_instr {
	public:
		GREF(mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_GREF, 0, stkoffs, 0, 0, 0, 0) { }
		GREF(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_GREF, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_GREF(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_GREF(this); }
	};

	class GSTB : public mlaskal::abstract_instr {
	public:
		GSTB(mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_GSTB, 0, stkoffs, 0, 0, 0, 0) { }
		GSTB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_GSTB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_GSTB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_GSTB(this); }
	};

	class GSTI : public mlaskal::abstract_instr {
	public:
		GSTI(mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_GSTI, 0, stkoffs, 0, 0, 0, 0) { }
		GSTI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_GSTI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_GSTI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_GSTI(this); }
	};

	class GSTR : public mlaskal::abstract_instr {
	public:
		GSTR(mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_GSTR, 0, stkoffs, 0, 0, 0, 0) { }
		GSTR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_GSTR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_GSTR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_GSTR(this); }
	};

	class GSTS : public mlaskal::abstract_instr {
	public:
		GSTS(mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_GSTS, 0, stkoffs, 0, 0, 0, 0) { }
		GSTS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_GSTS, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_GSTS(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_GSTS(this); }
	};

	class GTB : public mlaskal::abstract_instr {
	public:
		GTB() : mlaskal::abstract_instr(ai::ICOP_GTB, 0, 0, 0, 0, 0) { }
		GTB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_GTB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_GTB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_GTB(this); }
	};

	class GTI : public mlaskal::abstract_instr {
	public:
		GTI() : mlaskal::abstract_instr(ai::ICOP_GTI, 0, 0, 0, 0, 0) { }
		GTI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_GTI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_GTI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_GTI(this); }
	};

	class GTR : public mlaskal::abstract_instr {
	public:
		GTR() : mlaskal::abstract_instr(ai::ICOP_GTR, 0, 0, 0, 0, 0) { }
		GTR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_GTR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_GTR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_GTR(this); }
	};

	class GTS : public mlaskal::abstract_instr {
	public:
		GTS() : mlaskal::abstract_instr(ai::ICOP_GTS, 0, 0, 0, 0, 0) { }
		GTS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_GTS, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_GTS(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_GTS(this); }
	};

	class HALT : public mlaskal::abstract_instr {
	public:
		HALT() : mlaskal::abstract_instr(ai::ICOP_HALT, 0, 0, 0, 0, 0) { }
		HALT(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_HALT, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_HALT(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_HALT(this); }
	};

	class INITB : public mlaskal::abstract_instr {
	public:
		INITB() : mlaskal::abstract_instr(ai::ICOP_INITB, 0, 0, 0, 0, 0) { }
		INITB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_INITB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_INITB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_INITB(this); }
	};

	class INITI : public mlaskal::abstract_instr {
	public:
		INITI() : mlaskal::abstract_instr(ai::ICOP_INITI, 0, 0, 0, 0, 0) { }
		INITI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_INITI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_INITI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_INITI(this); }
	};

	class INITR : public mlaskal::abstract_instr {
	public:
		INITR() : mlaskal::abstract_instr(ai::ICOP_INITR, 0, 0, 0, 0, 0) { }
		INITR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_INITR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_INITR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_INITR(this); }
	};

	class INITS : public mlaskal::abstract_instr {
	public:
		INITS() : mlaskal::abstract_instr(ai::ICOP_INITS, 0, 0, 0, 0, 0) { }
		INITS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_INITS, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_INITS(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_INITS(this); }
	};

	class JEF : public mlaskal::abstract_instr {
	public:
		JEF(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator tgt, mlaskal::ICREGNUM in1) : mlaskal::abstract_instr(ai::ICOP_JEF, 0, tgt, in1, 0, 0, 0) { }
		JEF(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_JEF, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator tgt) { reljump_=tgt; }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_JEF(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_JEF(this); }
	};

	class JET : public mlaskal::abstract_instr {
	public:
		JET(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator tgt, mlaskal::ICREGNUM in1) : mlaskal::abstract_instr(ai::ICOP_JET, 0, tgt, in1, 0, 0, 0) { }
		JET(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_JET, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator tgt) { reljump_=tgt; }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_JET(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_JET(this); }
	};

	class JF : public mlaskal::abstract_instr {
	public:
		JF(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator tgt) : mlaskal::abstract_instr(ai::ICOP_JF, 0, tgt, 0, 0, 0, 0) { }
		JF(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_JF, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator tgt) { reljump_=tgt; }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_JF(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_JF(this); }
	};

	class JMP : public mlaskal::abstract_instr {
	public:
		JMP(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator tgt) : mlaskal::abstract_instr(ai::ICOP_JMP, 0, tgt, 0, 0, 0, 0) { }
		JMP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_JMP, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator tgt) { reljump_=tgt; }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_JMP(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_JMP(this); }
	};

	class JT : public mlaskal::abstract_instr {
	public:
		JT(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator tgt) : mlaskal::abstract_instr(ai::ICOP_JT, 0, tgt, 0, 0, 0, 0) { }
		JT(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_JT, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator tgt) { reljump_=tgt; }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_JT(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_JT(this); }
	};

	class LDLITB : public mlaskal::abstract_instr {
	public:
		LDLITB(mlaskal::ICABSNUM absnum) : mlaskal::abstract_instr(ai::ICOP_LDLITB, 0, absnum, 0, 0, 0, 0) { }
		LDLITB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_LDLITB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM absnum) { absnum_=absnum; }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_LDLITB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_LDLITB(this); }
	};

	class LDLITI : public mlaskal::abstract_instr {
	public:
		LDLITI(mlaskal::aic_literal_storage_int_type::const_pointer litint) : mlaskal::abstract_instr(ai::ICOP_LDLITI, 0, litint, 0, 0, 0, 0) { }
		LDLITI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_LDLITI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer litint) { litint_=litint; }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_LDLITI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_LDLITI(this); }
	};

	class LDLITR : public mlaskal::abstract_instr {
	public:
		LDLITR(mlaskal::aic_literal_storage_real_type::const_pointer litreal) : mlaskal::abstract_instr(ai::ICOP_LDLITR, 0, litreal, 0, 0, 0, 0) { }
		LDLITR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_LDLITR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer litreal) { litreal_=litreal; }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_LDLITR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_LDLITR(this); }
	};

	class LDLITS : public mlaskal::abstract_instr {
	public:
		LDLITS(mlaskal::aic_literal_storage_string_type::const_pointer litstr) : mlaskal::abstract_instr(ai::ICOP_LDLITS, 0, litstr, 0, 0, 0, 0) { }
		LDLITS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_LDLITS, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer litstr) { litstr_=litstr; }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_LDLITS(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_LDLITS(this); }
	};

	class LEB : public mlaskal::abstract_instr {
	public:
		LEB() : mlaskal::abstract_instr(ai::ICOP_LEB, 0, 0, 0, 0, 0) { }
		LEB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_LEB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_LEB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_LEB(this); }
	};

	class LEI : public mlaskal::abstract_instr {
	public:
		LEI() : mlaskal::abstract_instr(ai::ICOP_LEI, 0, 0, 0, 0, 0) { }
		LEI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_LEI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_LEI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_LEI(this); }
	};

	class LELDB : public mlaskal::abstract_instr {
	public:
		LELDB(mlaskal::ICREGNUM out, mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_LELDB, out, stkoffs, 0, 0, 0, 0) { }
		LELDB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_LELDB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_LELDB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_LELDB(this); }
	};

	class LELDI : public mlaskal::abstract_instr {
	public:
		LELDI(mlaskal::ICREGNUM out, mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_LELDI, out, stkoffs, 0, 0, 0, 0) { }
		LELDI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_LELDI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_LELDI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_LELDI(this); }
	};

	class LELDP : public mlaskal::abstract_instr {
	public:
		LELDP(mlaskal::ICREGNUM out, mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_LELDP, out, stkoffs, 0, 0, 0, 0) { }
		LELDP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_LELDP, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_LELDP(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_LELDP(this); }
	};

	class LELDR : public mlaskal::abstract_instr {
	public:
		LELDR(mlaskal::ICREGNUM out, mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_LELDR, out, stkoffs, 0, 0, 0, 0) { }
		LELDR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_LELDR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_LELDR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_LELDR(this); }
	};

	class LELDS : public mlaskal::abstract_instr {
	public:
		LELDS(mlaskal::ICREGNUM out, mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_LELDS, out, stkoffs, 0, 0, 0, 0) { }
		LELDS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_LELDS, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_LELDS(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_LELDS(this); }
	};

	class LER : public mlaskal::abstract_instr {
	public:
		LER() : mlaskal::abstract_instr(ai::ICOP_LER, 0, 0, 0, 0, 0) { }
		LER(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_LER, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_LER(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_LER(this); }
	};

	class LEREF : public mlaskal::abstract_instr {
	public:
		LEREF(mlaskal::ICREGNUM out, mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_LEREF, out, stkoffs, 0, 0, 0, 0) { }
		LEREF(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_LEREF, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_LEREF(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_LEREF(this); }
	};

	class LES : public mlaskal::abstract_instr {
	public:
		LES() : mlaskal::abstract_instr(ai::ICOP_LES, 0, 0, 0, 0, 0) { }
		LES(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_LES, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_LES(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_LES(this); }
	};

	class LESTB : public mlaskal::abstract_instr {
	public:
		LESTB(mlaskal::ICRELNUM stkoffs, mlaskal::ICREGNUM in1) : mlaskal::abstract_instr(ai::ICOP_LESTB, 0, stkoffs, in1, 0, 0, 0) { }
		LESTB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_LESTB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_LESTB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_LESTB(this); }
	};

	class LESTI : public mlaskal::abstract_instr {
	public:
		LESTI(mlaskal::ICRELNUM stkoffs, mlaskal::ICREGNUM in1) : mlaskal::abstract_instr(ai::ICOP_LESTI, 0, stkoffs, in1, 0, 0, 0) { }
		LESTI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_LESTI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_LESTI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_LESTI(this); }
	};

	class LESTP : public mlaskal::abstract_instr {
	public:
		LESTP(mlaskal::ICRELNUM stkoffs, mlaskal::ICREGNUM in1) : mlaskal::abstract_instr(ai::ICOP_LESTP, 0, stkoffs, in1, 0, 0, 0) { }
		LESTP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_LESTP, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_LESTP(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_LESTP(this); }
	};

	class LESTR : public mlaskal::abstract_instr {
	public:
		LESTR(mlaskal::ICRELNUM stkoffs, mlaskal::ICREGNUM in1) : mlaskal::abstract_instr(ai::ICOP_LESTR, 0, stkoffs, in1, 0, 0, 0) { }
		LESTR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_LESTR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_LESTR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_LESTR(this); }
	};

	class LESTS : public mlaskal::abstract_instr {
	public:
		LESTS(mlaskal::ICRELNUM stkoffs, mlaskal::ICREGNUM in1) : mlaskal::abstract_instr(ai::ICOP_LESTS, 0, stkoffs, in1, 0, 0, 0) { }
		LESTS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_LESTS, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_LESTS(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_LESTS(this); }
	};

	class LLDB : public mlaskal::abstract_instr {
	public:
		LLDB(mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_LLDB, 0, stkoffs, 0, 0, 0, 0) { }
		LLDB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_LLDB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_LLDB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_LLDB(this); }
	};

	class LLDI : public mlaskal::abstract_instr {
	public:
		LLDI(mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_LLDI, 0, stkoffs, 0, 0, 0, 0) { }
		LLDI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_LLDI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_LLDI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_LLDI(this); }
	};

	class LLDP : public mlaskal::abstract_instr {
	public:
		LLDP(mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_LLDP, 0, stkoffs, 0, 0, 0, 0) { }
		LLDP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_LLDP, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_LLDP(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_LLDP(this); }
	};

	class LLDR : public mlaskal::abstract_instr {
	public:
		LLDR(mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_LLDR, 0, stkoffs, 0, 0, 0, 0) { }
		LLDR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_LLDR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_LLDR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_LLDR(this); }
	};

	class LLDS : public mlaskal::abstract_instr {
	public:
		LLDS(mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_LLDS, 0, stkoffs, 0, 0, 0, 0) { }
		LLDS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_LLDS, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_LLDS(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_LLDS(this); }
	};

	class LREF : public mlaskal::abstract_instr {
	public:
		LREF(mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_LREF, 0, stkoffs, 0, 0, 0, 0) { }
		LREF(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_LREF, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_LREF(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_LREF(this); }
	};

	class LSTB : public mlaskal::abstract_instr {
	public:
		LSTB(mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_LSTB, 0, stkoffs, 0, 0, 0, 0) { }
		LSTB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_LSTB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_LSTB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_LSTB(this); }
	};

	class LSTI : public mlaskal::abstract_instr {
	public:
		LSTI(mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_LSTI, 0, stkoffs, 0, 0, 0, 0) { }
		LSTI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_LSTI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_LSTI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_LSTI(this); }
	};

	class LSTR : public mlaskal::abstract_instr {
	public:
		LSTR(mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_LSTR, 0, stkoffs, 0, 0, 0, 0) { }
		LSTR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_LSTR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_LSTR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_LSTR(this); }
	};

	class LSTS : public mlaskal::abstract_instr {
	public:
		LSTS(mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_LSTS, 0, stkoffs, 0, 0, 0, 0) { }
		LSTS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_LSTS, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_LSTS(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_LSTS(this); }
	};

	class LTB : public mlaskal::abstract_instr {
	public:
		LTB() : mlaskal::abstract_instr(ai::ICOP_LTB, 0, 0, 0, 0, 0) { }
		LTB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_LTB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_LTB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_LTB(this); }
	};

	class LTI : public mlaskal::abstract_instr {
	public:
		LTI() : mlaskal::abstract_instr(ai::ICOP_LTI, 0, 0, 0, 0, 0) { }
		LTI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_LTI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_LTI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_LTI(this); }
	};

	class LTR : public mlaskal::abstract_instr {
	public:
		LTR() : mlaskal::abstract_instr(ai::ICOP_LTR, 0, 0, 0, 0, 0) { }
		LTR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_LTR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_LTR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_LTR(this); }
	};

	class LTS : public mlaskal::abstract_instr {
	public:
		LTS() : mlaskal::abstract_instr(ai::ICOP_LTS, 0, 0, 0, 0, 0) { }
		LTS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_LTS, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_LTS(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_LTS(this); }
	};

	class MINUSI : public mlaskal::abstract_instr {
	public:
		MINUSI() : mlaskal::abstract_instr(ai::ICOP_MINUSI, 0, 0, 0, 0, 0) { }
		MINUSI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_MINUSI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_MINUSI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_MINUSI(this); }
	};

	class MINUSR : public mlaskal::abstract_instr {
	public:
		MINUSR() : mlaskal::abstract_instr(ai::ICOP_MINUSR, 0, 0, 0, 0, 0) { }
		MINUSR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_MINUSR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_MINUSR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_MINUSR(this); }
	};

	class MODI : public mlaskal::abstract_instr {
	public:
		MODI() : mlaskal::abstract_instr(ai::ICOP_MODI, 0, 0, 0, 0, 0) { }
		MODI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_MODI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_MODI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_MODI(this); }
	};

	class MULI : public mlaskal::abstract_instr {
	public:
		MULI() : mlaskal::abstract_instr(ai::ICOP_MULI, 0, 0, 0, 0, 0) { }
		MULI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_MULI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_MULI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_MULI(this); }
	};

	class MULR : public mlaskal::abstract_instr {
	public:
		MULR() : mlaskal::abstract_instr(ai::ICOP_MULR, 0, 0, 0, 0, 0) { }
		MULR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_MULR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_MULR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_MULR(this); }
	};

	class NEB : public mlaskal::abstract_instr {
	public:
		NEB() : mlaskal::abstract_instr(ai::ICOP_NEB, 0, 0, 0, 0, 0) { }
		NEB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_NEB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_NEB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_NEB(this); }
	};

	class NEI : public mlaskal::abstract_instr {
	public:
		NEI() : mlaskal::abstract_instr(ai::ICOP_NEI, 0, 0, 0, 0, 0) { }
		NEI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_NEI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_NEI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_NEI(this); }
	};

	class NER : public mlaskal::abstract_instr {
	public:
		NER() : mlaskal::abstract_instr(ai::ICOP_NER, 0, 0, 0, 0, 0) { }
		NER(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_NER, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_NER(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_NER(this); }
	};

	class NES : public mlaskal::abstract_instr {
	public:
		NES() : mlaskal::abstract_instr(ai::ICOP_NES, 0, 0, 0, 0, 0) { }
		NES(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_NES, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_NES(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_NES(this); }
	};

	class NOP : public mlaskal::abstract_instr {
	public:
		NOP() : mlaskal::abstract_instr(ai::ICOP_NOP, 0, 0, 0, 0, 0) { }
		NOP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_NOP, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_NOP(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_NOP(this); }
	};

	class NOT : public mlaskal::abstract_instr {
	public:
		NOT() : mlaskal::abstract_instr(ai::ICOP_NOT, 0, 0, 0, 0, 0) { }
		NOT(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_NOT, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_NOT(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_NOT(this); }
	};

	class OR : public mlaskal::abstract_instr {
	public:
		OR() : mlaskal::abstract_instr(ai::ICOP_OR, 0, 0, 0, 0, 0) { }
		OR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_OR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_OR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_OR(this); }
	};

	class RET : public mlaskal::abstract_instr {
	public:
		RET() : mlaskal::abstract_instr(ai::ICOP_RET, 0, 0, 0, 0, 0) { }
		RET(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_RET, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_RET(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_RET(this); }
	};

	class SADD : public mlaskal::abstract_instr {
	public:
		SADD(mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_SADD, 0, stkoffs, 0, 0, 0, 0) { }
		SADD(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_SADD, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_SADD(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_SADD(this); }
	};

	class SLDB : public mlaskal::abstract_instr {
	public:
		SLDB(mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_SLDB, 0, stkoffs, 0, 0, 0, 0) { }
		SLDB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_SLDB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_SLDB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_SLDB(this); }
	};

	class SLDI : public mlaskal::abstract_instr {
	public:
		SLDI(mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_SLDI, 0, stkoffs, 0, 0, 0, 0) { }
		SLDI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_SLDI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_SLDI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_SLDI(this); }
	};

	class SLDP : public mlaskal::abstract_instr {
	public:
		SLDP(mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_SLDP, 0, stkoffs, 0, 0, 0, 0) { }
		SLDP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_SLDP, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_SLDP(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_SLDP(this); }
	};

	class SLDR : public mlaskal::abstract_instr {
	public:
		SLDR(mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_SLDR, 0, stkoffs, 0, 0, 0, 0) { }
		SLDR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_SLDR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_SLDR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_SLDR(this); }
	};

	class SLDS : public mlaskal::abstract_instr {
	public:
		SLDS(mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_SLDS, 0, stkoffs, 0, 0, 0, 0) { }
		SLDS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_SLDS, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_SLDS(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_SLDS(this); }
	};

	class SREF : public mlaskal::abstract_instr {
	public:
		SREF(mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_SREF, 0, stkoffs, 0, 0, 0, 0) { }
		SREF(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_SREF, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_SREF(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_SREF(this); }
	};

	class SSTB : public mlaskal::abstract_instr {
	public:
		SSTB(mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_SSTB, 0, stkoffs, 0, 0, 0, 0) { }
		SSTB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_SSTB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_SSTB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_SSTB(this); }
	};

	class SSTI : public mlaskal::abstract_instr {
	public:
		SSTI(mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_SSTI, 0, stkoffs, 0, 0, 0, 0) { }
		SSTI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_SSTI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_SSTI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_SSTI(this); }
	};

	class SSTP : public mlaskal::abstract_instr {
	public:
		SSTP(mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_SSTP, 0, stkoffs, 0, 0, 0, 0) { }
		SSTP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_SSTP, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_SSTP(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_SSTP(this); }
	};

	class SSTR : public mlaskal::abstract_instr {
	public:
		SSTR(mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_SSTR, 0, stkoffs, 0, 0, 0, 0) { }
		SSTR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_SSTR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_SSTR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_SSTR(this); }
	};

	class SSTS : public mlaskal::abstract_instr {
	public:
		SSTS(mlaskal::ICRELNUM stkoffs) : mlaskal::abstract_instr(ai::ICOP_SSTS, 0, stkoffs, 0, 0, 0, 0) { }
		SSTS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_SSTS, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM stkoffs) { stkoffs_=stkoffs; }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_SSTS(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_SSTS(this); }
	};

	class SUBI : public mlaskal::abstract_instr {
	public:
		SUBI() : mlaskal::abstract_instr(ai::ICOP_SUBI, 0, 0, 0, 0, 0) { }
		SUBI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_SUBI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_SUBI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_SUBI(this); }
	};

	class SUBP : public mlaskal::abstract_instr {
	public:
		SUBP() : mlaskal::abstract_instr(ai::ICOP_SUBP, 0, 0, 0, 0, 0) { }
		SUBP(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_SUBP, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_SUBP(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_SUBP(this); }
	};

	class SUBR : public mlaskal::abstract_instr {
	public:
		SUBR() : mlaskal::abstract_instr(ai::ICOP_SUBR, 0, 0, 0, 0, 0) { }
		SUBR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_SUBR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_SUBR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_SUBR(this); }
	};

	class XELDB : public mlaskal::abstract_instr {
	public:
		XELDB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1) : mlaskal::abstract_instr(ai::ICOP_XELDB, out, in1, 0, 0, 0) { }
		XELDB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_XELDB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_XELDB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_XELDB(this); }
	};

	class XELDI : public mlaskal::abstract_instr {
	public:
		XELDI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1) : mlaskal::abstract_instr(ai::ICOP_XELDI, out, in1, 0, 0, 0) { }
		XELDI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_XELDI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_XELDI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_XELDI(this); }
	};

	class XELDR : public mlaskal::abstract_instr {
	public:
		XELDR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1) : mlaskal::abstract_instr(ai::ICOP_XELDR, out, in1, 0, 0, 0) { }
		XELDR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_XELDR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_XELDR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_XELDR(this); }
	};

	class XELDS : public mlaskal::abstract_instr {
	public:
		XELDS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1) : mlaskal::abstract_instr(ai::ICOP_XELDS, out, in1, 0, 0, 0) { }
		XELDS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_XELDS, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM reg) { out_=reg; }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_XELDS(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_XELDS(this); }
	};

	class XESTB : public mlaskal::abstract_instr {
	public:
		XESTB(mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_XESTB, 0, in1, in2, 0, 0) { }
		XESTB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_XESTB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_XESTB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_XESTB(this); }
	};

	class XESTI : public mlaskal::abstract_instr {
	public:
		XESTI(mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_XESTI, 0, in1, in2, 0, 0) { }
		XESTI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_XESTI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_XESTI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_XESTI(this); }
	};

	class XESTR : public mlaskal::abstract_instr {
	public:
		XESTR(mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_XESTR, 0, in1, in2, 0, 0) { }
		XESTR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_XESTR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_XESTR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_XESTR(this); }
	};

	class XESTS : public mlaskal::abstract_instr {
	public:
		XESTS(mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2) : mlaskal::abstract_instr(ai::ICOP_XESTS, 0, in1, in2, 0, 0) { }
		XESTS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_XESTS, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM reg) { in1_=reg; }
		virtual void patch_in2_int_(mlaskal::ICREGNUM reg) { in2_=reg; }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_XESTS(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_XESTS(this); }
	};

	class XLDB : public mlaskal::abstract_instr {
	public:
		XLDB() : mlaskal::abstract_instr(ai::ICOP_XLDB, 0, 0, 0, 0, 0) { }
		XLDB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_XLDB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_XLDB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_XLDB(this); }
	};

	class XLDI : public mlaskal::abstract_instr {
	public:
		XLDI() : mlaskal::abstract_instr(ai::ICOP_XLDI, 0, 0, 0, 0, 0) { }
		XLDI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_XLDI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_XLDI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_XLDI(this); }
	};

	class XLDR : public mlaskal::abstract_instr {
	public:
		XLDR() : mlaskal::abstract_instr(ai::ICOP_XLDR, 0, 0, 0, 0, 0) { }
		XLDR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_XLDR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_XLDR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_XLDR(this); }
	};

	class XLDS : public mlaskal::abstract_instr {
	public:
		XLDS() : mlaskal::abstract_instr(ai::ICOP_XLDS, 0, 0, 0, 0, 0) { }
		XLDS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_XLDS, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_XLDS(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_XLDS(this); }
	};

	class XSTB : public mlaskal::abstract_instr {
	public:
		XSTB() : mlaskal::abstract_instr(ai::ICOP_XSTB, 0, 0, 0, 0, 0) { }
		XSTB(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_XSTB, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_XSTB(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_XSTB(this); }
	};

	class XSTI : public mlaskal::abstract_instr {
	public:
		XSTI() : mlaskal::abstract_instr(ai::ICOP_XSTI, 0, 0, 0, 0, 0) { }
		XSTI(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_XSTI, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_XSTI(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_XSTI(this); }
	};

	class XSTR : public mlaskal::abstract_instr {
	public:
		XSTR() : mlaskal::abstract_instr(ai::ICOP_XSTR, 0, 0, 0, 0, 0) { }
		XSTR(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_XSTR, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_XSTR(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_XSTR(this); }
	};

	class XSTS : public mlaskal::abstract_instr {
	public:
		XSTS() : mlaskal::abstract_instr(ai::ICOP_XSTS, 0, 0, 0, 0, 0) { }
		XSTS(mlaskal::ICREGNUM out, mlaskal::ICREGNUM in1, mlaskal::ICREGNUM in2, mlaskal::ICREGNUM in3, mlaskal::ICREGNUM in4) : mlaskal::abstract_instr(ai::ICOP_XSTS, out, in1, in2, in3, in4) { }
	private:
		virtual void patch_in1_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN1"); }
		virtual void patch_in2_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN2"); }
		virtual void patch_in3_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN3"); }
		virtual void patch_in4_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no IN4"); }
		virtual void patch_out_int_(mlaskal::ICREGNUM) { throw std::logic_error("Instruction has no OUT/INOUT"); }
		virtual void patch_litint_int_(mlaskal::aic_literal_storage_int_type::const_pointer) { throw std::logic_error("Instruction has no LITINT"); }
		virtual void patch_litreal_int_(mlaskal::aic_literal_storage_real_type::const_pointer) { throw std::logic_error("Instruction has no LITREAL"); }
		virtual void patch_litstr_int_(mlaskal::aic_literal_storage_string_type::const_pointer) { throw std::logic_error("Instruction has no LITSTR"); }
		virtual void patch_absnum_int_(mlaskal::ICABSNUM) { throw std::logic_error("Instruction has no ABSNUM"); }
		virtual void patch_stkoffs_int_(mlaskal::ICRELNUM) { throw std::logic_error("Instruction has no STKOFFS"); }
		virtual void patch_reljump_int_(mlaskal::plain_icblock<mlaskal::abstract_instr>::const_iterator) { throw std::logic_error("Instruction has no RELJUMP"); }
		virtual void patch_absjump_int_(mlaskal::abstract_functions::const_iterator) { throw std::logic_error("Instruction has no ABSJUMP"); }
		virtual void accept_int_(ai_visitor *visitor) { visitor->visit_XSTS(this); }
		virtual void accept_int_(ai_const_visitor *visitor) const { visitor->visit_XSTS(this); }
	};

}
#endif
