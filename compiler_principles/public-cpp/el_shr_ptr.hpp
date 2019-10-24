#ifndef GUARD_MLASKAL_EL_SHR_PTR_HPP_
#define GUARD_MLASKAL_EL_SHR_PTR_HPP_

#include <memory>

#if defined( DEBUG_MEMORY_LEAKS) && defined( _MSC_VER) && defined( _DEBUG)
#define _AFXDLL
#include "afx.h"
#endif

namespace mlc {

struct protection_data
{
	protection_data() {}
	protection_data(const protection_data &) = delete;
	protection_data & operator=(const protection_data &) = delete;
	~protection_data();

#if defined( DEBUG_MEMORY_LEAKS) && defined( _MSC_VER) && defined( _DEBUG)
	CMemoryState msOld;
#endif
};

std::unique_ptr< protection_data> protection_start();

}
#endif
