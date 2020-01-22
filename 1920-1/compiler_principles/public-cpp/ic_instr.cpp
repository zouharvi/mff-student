/*

	ic_instr.cpp

	IC instruction for Mlaskal

	Kuba, 2006

*/

#include <sstream>

#include "ic_instr.hpp"
#include "ic_instrtab.hpp"

using namespace std;

namespace mlaskal {

	void ic_instr::get_asm(string &opc, string &oper) const
	{
		opc = ai::ic_instrtab[opc_].text_;

		bool first=true;
		stringstream ss;
		if(ai::ic_instrtab[opc_].out_ptype_!=PTYPE_UNDEF)		// out register
		{
			ss << "R" << out_;
			first = false;
		}
		if(ai::ic_instrtab[opc_].stkp_type_!=ICSPT_NONE)				// operand
		{
			if(!first)
				ss << ',';
			first = false;
		}
		switch(ai::ic_instrtab[opc_].stkp_type_)
		{
		case ICSPT_NONE:
			break;
		case ICSPT_LITINT:
			ss << "LITINT[" << static_cast<ICABSNUM>(n_) << ']';
			break;
		case ICSPT_LITREAL:
			ss << "LITREAL[" << static_cast<ICABSNUM>(n_) << ']';
			break;
		case ICSPT_LITSTR:
			ss << "LITSTR[" << static_cast<ICABSNUM>(n_) << ']';
			break;
		case ICSPT_ABSNUM:
			ss << static_cast<ICABSNUM>(n_);
			break;
		case ICSPT_RELNUM:
			ss << n_;
			break;
		case ICSPT_GSTKOFFS:
		case ICSPT_LSTKOFFS:
		case ICSPT_SSTKOFFS:
			ss << '[' << n_ << ']';
			break;
		case ICSPT_RELJUMP:
			ss << n_;
			break;
		case ICSPT_ABSJUMP:
			ss << static_cast<ICABSNUM>(n_);
			break;
		}
		if(ai::ic_instrtab[opc_].in1_ptype_!=PTYPE_UNDEF)	// inreg1
		{
			if(!first)
				ss << ',';
			ss << 'R' << in1_;
		}
		if(ai::ic_instrtab[opc_].in2_ptype_!=PTYPE_UNDEF)	// inreg2
			ss << ",R" << in2_;
		if(ai::ic_instrtab[opc_].in3_ptype_!=PTYPE_UNDEF)	// inreg3
			ss << ",R" << in3_;
		if(ai::ic_instrtab[opc_].in4_ptype_!=PTYPE_UNDEF)	// inreg4
			ss << ",R" << in4_;

		oper = ss.str();
	}

}
