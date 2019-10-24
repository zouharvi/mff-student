#ifndef GUARD_MLASKAL_ICM_TYPES_HPP_
#define GUARD_MLASKAL_ICM_TYPES_HPP_

/*

	icm_types.hpp

	ICM types

	Kuba, 2006

*/

#include <string>

#include "common_types.hpp"

namespace mlaskal {

	typedef void *		ICMT_NOTHING;
	typedef bool		ICMT_BOOL;
	typedef int				ICMT_INT;
	typedef double		ICMT_REAL;
	typedef std::string		ICMT_STRING;
	typedef ICABSNUM		ICMT_PTR;
	typedef ICABSNUM		ICMT_ICIP;
	typedef struct {
		ICMT_ICIP   ra_;
		ICMT_PTR	prev_fp_;
	}						ICMT_RA;

}

#endif
