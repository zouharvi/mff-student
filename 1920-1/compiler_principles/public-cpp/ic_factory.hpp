#ifndef GUARD_MLASKAL_IC_FACTORY_H_
#define GUARD_MLASKAL_IC_FACTORY_H_

/*

	ic_factory.hpp

	IC factory

	Kuba, 2006

*/

#include <stdexcept>

#include "common_types.hpp"
#include "ic_opcodes.hpp"

namespace mlaskal {

	class ic_instr;

	typedef ic_instr*(*ic_factory_creator_type)(ai::IC_OPCODE opc, ICRELNUM n, ICREGNUM in1, ICREGNUM in2, ICREGNUM in3, ICREGNUM in4, ICREGNUM out);

	class ic_factory {
	public:
		static ic_instr *create_ic_instr(ai::IC_OPCODE opc, ICRELNUM n, ICREGNUM in1, ICREGNUM in2, ICREGNUM in3, ICREGNUM in4, ICREGNUM out)
		{
			if(opc>=ai::ICOP_DNOTUSE_MAX_)
				throw std::out_of_range("Instruction opcode out of range");

			return creators_[opc](opc, n, in1, in2, in3, in4, out);
		}
	private:
		static ic_factory_creator_type creators_[ai::ICOP_DNOTUSE_MAX_];
	};

};

#endif
