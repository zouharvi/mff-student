#ifndef GUARD_MLASKAL_AI_FACTORY_HPP_
#define GUARD_MLASKAL_AI_FACTORY_HPP_

/*

	ai_factory.hpp

	AI factory

	Kuba, 2006

*/

#include <stdexcept>

#include "common_types.hpp"
#include "ic_opcodes.hpp"
#include "abstract_instr.hpp"

namespace mlaskal {

	/// @cond INTERNAL

	typedef abstract_instr*(*ai_factory_creator_type)(ICREGNUM out, ICREGNUM in1, ICREGNUM in2, ICREGNUM in3, ICREGNUM in4);
	typedef abstract_instr*(*ai_factory_cloner_type)(const abstract_instr *oldai);

	/// @endcond

	/// instruction factory
	class ai_factory {
	public:
		/// @cond INTERNAL
		static abstract_instr *create_ai_instr(ai::IC_OPCODE opc, ICREGNUM out, ICREGNUM in1, ICREGNUM in2, ICREGNUM in3, ICREGNUM in4)
		{
			if(opc>=ai::ICOP_DNOTUSE_MAX_)
				throw std::out_of_range("Instruction opcode out of range");

			return creators_[opc](out, in1, in2, in3, in4);
		}
		/// @endcond

		/// clones an instruction
		/**
			\note cloning assigns new UID
		**/
		static abstract_instr *clone_ai_instr(const abstract_instr *oldai)
		{
			if(oldai->get_opcode()>=ai::ICOP_DNOTUSE_MAX_)
				throw std::out_of_range("Instruction opcode out of range");

			return cloners_[oldai->get_opcode()](oldai);
		}
	private:
		static ai_factory_creator_type creators_[ai::ICOP_DNOTUSE_MAX_];
		static ai_factory_cloner_type cloners_[ai::ICOP_DNOTUSE_MAX_];
	};

};

#endif
