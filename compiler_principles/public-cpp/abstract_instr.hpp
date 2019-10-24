#ifndef GUARD_MLASKAL_ABSTRACT_INSTR_HPP_
#define GUARD_MLASKAL_ABSTRACT_INSTR_HPP_

/*

	abstract_instr.hpp

	Abstract IC instruction

	Kuba, 2006

*/

#include <stdexcept>		// needed by generated code

#include "ic_opcodes.hpp"
#include "abstract_ic.hpp"
#include "plain_icblock.hpp"

namespace ai {

	class ai_visitor;
	class ai_const_visitor;

};

namespace mlaskal {

	/// instruction (abstract base class)
	class abstract_instr {
	public:
		/// @cond INTERNAL
		abstract_instr(ai::IC_OPCODE opc, ICREGNUM out, ICREGNUM in1, ICREGNUM in2, ICREGNUM in3, ICREGNUM in4) 
											: opc_(opc), in1_(in1), in2_(in2), in3_(in3), in4_(in4), out_(out), uid_(uid_all.get_UID()) { }
		abstract_instr(ai::IC_OPCODE opc, ICREGNUM out, aic_literal_storage_int_type::const_pointer litint, ICREGNUM in1, ICREGNUM in2, ICREGNUM in3, ICREGNUM in4) 
											: opc_(opc), in1_(in1), in2_(in2), in3_(in3), in4_(in4), out_(out), litint_(litint), uid_(uid_all.get_UID()) { }
		abstract_instr(ai::IC_OPCODE opc, ICREGNUM out, aic_literal_storage_real_type::const_pointer litreal, ICREGNUM in1, ICREGNUM in2, ICREGNUM in3, ICREGNUM in4) 
											: opc_(opc), in1_(in1), in2_(in2), in3_(in3), in4_(in4), out_(out), litreal_(litreal), uid_(uid_all.get_UID()) { }
		abstract_instr(ai::IC_OPCODE opc, ICREGNUM out, aic_literal_storage_string_type::const_pointer litstr, ICREGNUM in1, ICREGNUM in2, ICREGNUM in3, ICREGNUM in4) 
											: opc_(opc), in1_(in1), in2_(in2), in3_(in3), in4_(in4), out_(out), litstr_(litstr), uid_(uid_all.get_UID()) { }
		abstract_instr(ai::IC_OPCODE opc, ICREGNUM out, ICRELNUM stkoffs, ICREGNUM in1, ICREGNUM in2, ICREGNUM in3, ICREGNUM in4) 
											: opc_(opc), in1_(in1), in2_(in2), in3_(in3), in4_(in4), out_(out), stkoffs_(stkoffs), uid_(uid_all.get_UID()) { }
		abstract_instr(ai::IC_OPCODE opc, ICREGNUM out, ICABSNUM absnum, ICREGNUM in1, ICREGNUM in2, ICREGNUM in3, ICREGNUM in4) 
											: opc_(opc), in1_(in1), in2_(in2), in3_(in3), in4_(in4), out_(out), absnum_(absnum), uid_(uid_all.get_UID()) { }
		abstract_instr(ai::IC_OPCODE opc, ICREGNUM out, plain_icblock<abstract_instr>::const_iterator tgt, ICREGNUM in1, ICREGNUM in2, ICREGNUM in3, ICREGNUM in4) 
											: opc_(opc), in1_(in1), in2_(in2), in3_(in3), in4_(in4), out_(out), reljump_(tgt), uid_(uid_all.get_UID()) { }
		abstract_instr(ai::IC_OPCODE opc, ICREGNUM out, abstract_functions::const_iterator tgt, ICREGNUM in1, ICREGNUM in2, ICREGNUM in3, ICREGNUM in4) 
											: opc_(opc), in1_(in1), in2_(in2), in3_(in3), in4_(in4), out_(out), absjump_(tgt), uid_(uid_all.get_UID()) { }
		/// @endcond

		virtual ~abstract_instr() { };

		/// opcode
		ai::IC_OPCODE get_opcode() const { return opc_; }
		/// first input register operand
		ICREGNUM get_in1() const { return in1_; }
		/// second input register operand
		ICREGNUM get_in2() const { return in2_; }
		/// third input register operand
		ICREGNUM get_in3() const { return in3_; }
		/// fourth input register operand
		ICREGNUM get_in4() const { return in4_; }
		/// output register operand
		ICREGNUM get_out() const { return out_; }

		// this will be probably virtual and checked in the near future as well
		/// integer literal parameter
		aic_literal_storage_int_type::const_pointer get_litint() const { return litint_; }
		/// real literal parameter
		aic_literal_storage_real_type::const_pointer get_litreal() const { return litreal_; }
		/// string literal parameter
		aic_literal_storage_string_type::const_pointer get_litstr() const { return litstr_; }
		/// stack offset parameter
		ICRELNUM get_stkoffs() const { return stkoffs_; }
		/// boolean value parameter
		ICABSNUM get_absnum() const { return absnum_; }
		/// relative code address
		/** 
			returns iterator pointing to the target instruction
			or end of this function code block
		**/
		plain_icblock<abstract_instr>::const_iterator get_reljump() const { return reljump_; }
		/// absolute code address
		/** 
			returns iterator pointing to the target function
		**/
		abstract_functions::const_iterator get_absjump() const { return absjump_; }

		/// my UID (generated automatically)
		uid_all_type::UID_type get_UID() const { return uid_; }

		/// set first input register
		void patch_in1(ICREGNUM reg) { patch_in1_int_(reg); }
		/// set second input register
		void patch_in2(ICREGNUM reg) { patch_in2_int_(reg); }
		/// set third input register
		void patch_in3(ICREGNUM reg) { patch_in3_int_(reg); }
		/// set fourth input register
		void patch_in4(ICREGNUM reg) { patch_in4_int_(reg); }
		/// set output register
		void patch_out(ICREGNUM reg) { patch_out_int_(reg); }
		/// set integer literal parameter
		void patch_litint(aic_literal_storage_int_type::const_pointer litint) { patch_litint_int_(litint); }
		/// set real literal parameter
		void patch_litreal(aic_literal_storage_real_type::const_pointer litreal) { patch_litreal_int_(litreal); }
		/// set string literal parameter
		void patch_litstr(aic_literal_storage_string_type::const_pointer litstr) { patch_litstr_int_(litstr); }
		/// set stack offset parameter
		void patch_stkoffs(ICRELNUM stkoffs) { patch_stkoffs_int_(stkoffs); }
		/// set boolean value parameter
		void patch_absnum(ICABSNUM absnum) { patch_absnum_int_(absnum); }
		/// set relative code address
		/** 
			\param tgt iterator pointing to the target instruction
			or end of this function code block
		**/
		void patch_reljump(plain_icblock<abstract_instr>::const_iterator tgt) { patch_reljump_int_(tgt); }
		/// absolute code address
		/** 
			\param tgt iterator pointing to the target function
		**/
		void patch_absjump(abstract_functions::const_iterator tgt) { patch_absjump_int_(tgt); }

		/// @cond INTERNAL

		// visitor action
		void accept(ai::ai_visitor *visitor) { accept_int_(visitor); }
		void accept(ai::ai_const_visitor *visitor) const { accept_int_(visitor); }

		/// @endcond

	protected:
		/// @cond INTERNAL

		ai::IC_OPCODE													opc_;
		ICREGNUM													in1_, in2_, in3_, in4_, out_;
		aic_literal_storage_int_type::const_pointer					litint_;
		aic_literal_storage_real_type::const_pointer					litreal_;
		aic_literal_storage_string_type::const_pointer					litstr_;
		ICRELNUM													stkoffs_;
		ICABSNUM													absnum_;
		plain_icblock<abstract_instr>::const_iterator					reljump_;
		abstract_functions::const_iterator							absjump_;

		/// @endcond

	private:
		uid_all_type::UID_type											uid_;

		virtual void patch_in1_int_(ICREGNUM reg)=0;
		virtual void patch_in2_int_(ICREGNUM reg)=0;
		virtual void patch_in3_int_(ICREGNUM reg)=0;
		virtual void patch_in4_int_(ICREGNUM reg)=0;
		virtual void patch_out_int_(ICREGNUM reg)=0;
		virtual void patch_litint_int_(aic_literal_storage_int_type::const_pointer litint)=0;
		virtual void patch_litreal_int_(aic_literal_storage_real_type::const_pointer litreal)=0;
		virtual void patch_litstr_int_(aic_literal_storage_string_type::const_pointer litstr)=0;
		virtual void patch_stkoffs_int_(ICRELNUM stkoffs)=0;
		virtual void patch_absnum_int_(ICABSNUM stkoffs)=0;
		virtual void patch_reljump_int_(plain_icblock<abstract_instr>::const_iterator tgt)=0;
		virtual void patch_absjump_int_(abstract_functions::const_iterator tgt)=0;

		virtual void accept_int_(ai::ai_visitor *visitor)=0;
		virtual void accept_int_(ai::ai_const_visitor *visitor) const =0;
	};

}

#include "gen_ainstr.hpp"

#endif
