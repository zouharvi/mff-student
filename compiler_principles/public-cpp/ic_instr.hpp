#ifndef GUARD_MLASKAL_IC_INSTR_HPP_
#define GUARD_MLASKAL_IC_INSTR_HPP_

/*

	ic_instr.hpp

	IC instruction for Mlaskal

	Kuba, 2006

*/

#include <string>

#include "common_types.hpp"
#include "ic_opcodes.hpp"

namespace mlaskal {

	/// @cond INTERNAL 

	// abstract base class
	class ic_instr {
	public:
		ic_instr(ai::IC_OPCODE opc, ICRELNUM n, ICREGNUM in1, ICREGNUM in2, ICREGNUM in3, ICREGNUM in4, ICREGNUM out) 
												: opc_(opc), n_(n), in1_(in1), in2_(in2), in3_(in3), in4_(in4), out_(out) { }
		virtual ~ic_instr() { };

		void get_asm(std::string &opc, std::string &oper) const;

		ai::IC_OPCODE get_opcode() const { return opc_; }
		ICRELNUM get_stkn() const { return n_; }
		ICREGNUM get_in1() const { return in1_; }
		ICREGNUM get_in2() const { return in2_; }
		ICREGNUM get_in3() const { return in3_; }
		ICREGNUM get_in4() const { return in4_; }
		ICREGNUM get_out() const { return out_; }
	protected:
		ai::IC_OPCODE   opc_;
		ICRELNUM	n_;
		ICREGNUM	in1_, in2_, in3_, in4_, out_;
	};

	/// @endcond

}

#include "gen_icinstr.hpp"

#endif
