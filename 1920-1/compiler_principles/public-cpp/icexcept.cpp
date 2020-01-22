/*

	icexcept.cpp

	ICM exceptions - implementation

	Kuba, 2006
*/

#include "icexcept.hpp"

namespace mlaskal {

	ic_except::exc_msg ic_except::exc_msgs_[ICET_MAX_DO_NOT_USE_]= {
		{ false,	"OK" },
		{ true,		"Used uninitialized value" },
		{ true,		"Requested bad value type" },
		{ true,		"Stack offset out of range" },
		{ true,		"Literal index out of range" },
		{ true,		"Register index out of range" },
		{ true,		"Jump out of code" },
		{ true,		"Instruction is not allowed for this machine" },
		{ false,	"Bad input file" },
		{ false,	"Error reading input file" },
		{ false,	"Input file corrupted" },
		{ false,	"Bad trace file" },
		{ true,		"Instruction limit reached" },
		{ true,		"Stack limit reached" },
	};

}
