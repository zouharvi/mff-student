#ifndef GUARD_MLASKAL_IC_INSTRTAB_HPP_
#define GUARD_MLASKAL_IC_INSTRTAB_HPP_

/*

	ic_instrtab.hpp

	IC instruction table for Mlaskal

	Kuba, 2006

*/

#include "common_types.hpp"
#include "ic_opcodes.hpp"

namespace mlaskal {

	/// instruction parameter kind
	enum ic_stkparm_type { 
		ICSPT_NONE,		/**< no parameter */
		ICSPT_LITINT,		/**< index of integer literal */
		ICSPT_LITREAL,		/**< index of real literal */
		ICSPT_LITSTR,		/**< index of string literal */
		ICSPT_RELNUM,		/**< (unused) */
		ICSPT_ABSNUM,		/**< immediate value (boolean) */
		ICSPT_GSTKOFFS, /**< absolute stack offset */
		ICSPT_LSTKOFFS, /**< FP-based stack offset */
		ICSPT_SSTKOFFS, /**< SP-based stack offset */
		ICSPT_RELJUMP,		/**< relative code address */
		ICSPT_ABSJUMP		/**< absolute code address */
	};

	/// instruction properties
	struct ic_instrtab_type {
		/// opcode
		ai::IC_OPCODE		opc_;
		/// mnemonics
		const char		*text_;
		/// parameter kind
		ic_stkparm_type		stkp_type_;
		/// first register operand type
		physical_type		in1_ptype_;
		/// second register operand type
		physical_type		in2_ptype_;
		/// third register operand type
		physical_type		in3_ptype_;
		/// fourth register operand type
		physical_type		in4_ptype_;
		/// output register operand type
		physical_type		out_ptype_;
	};

}

namespace ai {

	/// instruction properties 
	/** 
		indexed by opcode

		generated from icminstr.xml 
	**/
	extern mlaskal::ic_instrtab_type ic_instrtab[];

}

#endif
