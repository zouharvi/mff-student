#ifndef GUARD_MLASKAL_ICEXCEPT_HPP_
#define GUARD_MLASKAL_ICEXCEPT_HPP_

/*

	icexcept.hpp

	ICM exceptions

	Kuba, 2006

*/

#include "icm_types.hpp"

namespace mlaskal {

	enum ic_except_type {
		ICET_FINISHED,							/* interpreter successfully finished */
		ICET_VAL_UNINIT,						/* stack value uninitialized */
		ICET_BAD_VAL_TYPE,						/* requested bad value type */
		ICET_STKOFFS_OUT_RANGE,					/* stack offset is out of range */
		ICET_LIT_IDX_OUT_RANGE,					/* literal index out of range */
		ICET_REG_IDX_OUT_RANGE,					/* register index out of range */
		ICET_JUMP_OUT_CODE,						/* jump out of code */
		ICET_INSTR_NOT_ALLOWED,					/* instruction is not allowed for this machine */
		ICET_BAD_INPUT_FILE,					/* bad input file */
		ICET_INPUT_FILE_ERROR,					/* error reading input file */
		ICET_INPUT_FILE_CORRUPTED,				/* input file corrupted */
		ICET_BAD_TRACE_FILE,					/* bad trace file */
		ICET_INSTR_LIMIT_REACHED,				/* instruction limit reached */
		ICET_STACK_LIMIT_REACHED,				/* stack limit reached */

		ICET_MAX_DO_NOT_USE_
	};

	class ic_except {
	public:
		ic_except(ic_except_type reason, ICMT_ICIP icip) : reason_(reason),icip_(icip) { };

		ic_except_type get_reason() const { return reason_; }
		ICMT_ICIP get_ip() const { return icip_; }
		const char *get_msg() const { return exc_msgs_[reason_].str_; }
		bool has_ip() const { return exc_msgs_[reason_].has_ip_; }

	private:
		ic_except_type			reason_;
		ICMT_ICIP			icip_;

		struct exc_msg {
			bool		has_ip_;
			const char *str_;
		};

		static exc_msg exc_msgs_[ICET_MAX_DO_NOT_USE_];
	};

}

#endif
