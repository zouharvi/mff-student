#ifndef GUARD_MLASKAL_ICM_FLAT_ICBLOCK_HPP_
#define GUARD_MLASKAL_ICM_FLAT_ICBLOCK_HPP_

/*

	icm_flat_icblock.hpp

	Flat IC block from file - specialization for ICM

	Kuba, 2006

*/

#include <string>

#include "flat_icblock.hpp"
#include "icexcept.hpp"

namespace mlaskal {

	class icm_flat_icblock : public flat_icblock {
	public:
		explicit icm_flat_icblock(const std::string &filename)
			try : flat_icblock(filename) { }
			catch(const flat_icblock_exception &f)
			{
				switch(f.reason_)
				{
				case flat_icblock_exception::FICBER_OPEN:
					throw ic_except(ICET_BAD_INPUT_FILE, 0);
					break;
				case flat_icblock_exception::FICBER_ERR:
					throw ic_except(ICET_INPUT_FILE_ERROR, 0);
					break;
				case flat_icblock_exception::FICBER_CORRUPT:
					throw ic_except(ICET_INPUT_FILE_CORRUPTED, 0);
					break;
				}
			}
		explicit icm_flat_icblock(const mlaskal::abstract_ic &abstract_ic)
			: flat_icblock(abstract_ic) { }
	};

}

#endif
