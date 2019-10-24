#ifndef GUARD_MLASKAL_COMMON_TYPES_HPP_
#define GUARD_MLASKAL_COMMON_TYPES_HPP_

/*

	common_types.hpp

	Common types

	Kuba, 2006

*/

#include <iostream>

namespace mlaskal {

	/// function kind
	enum fnc_signature_type { FNCSIG_PROGRAM, FNCSIG_PROC, FNCSIG_FNC };
	/// variable kind
	enum fnc_signature_var_type { FNCSIG_LOCVAR, FNCSIG_GLOBVAR };

	/// physical type
	enum physical_type { PTYPE_UNDEF, PTYPE_ADDR, PTYPE_BOOL, PTYPE_INTEGER, PTYPE_REAL, PTYPE_STRING, PTYPE_ANY };

	/// @cond INTERNAL

	inline std::ostream &operator<<(std::ostream &os, physical_type ptype) {
		static const char *ptypes[] = {
			"UNDEF", "ADDR", "BOOLEAN", "INTEGER", "REAL", "STRING", "ANY"
		};
		os << ptypes[ptype];
		return os;
	}

	/// @endcond

	// types for instruction parameters

	/// @cond INTERNAL
	typedef int				ICRELNUM;   
	/// @endcond

	typedef int				ICSTKOFFS;  ///< stack offset
	typedef unsigned		ICABSNUM;   ///< unsigned integer

	/// @cond INTERNAL
	typedef ICABSNUM		ICLITIDX;   
	/// @endcond

	typedef ICABSNUM		ICREGNUM;   ///< register number

	/*************************************************************************/

	template< typename T> struct object_traits
	{
		static T * get_dummy_object()
		{
			static T dummy;
			return &dummy;
		}
	};

	/// limited-feature pointer to \p T
	/** \internal **/
	template< typename T> class dumb_pointer
	{
	public:
		dumb_pointer() : ptr_( nullptr) {}
		explicit dumb_pointer( T * p) : ptr_( p) {}
		template< typename T2>
		dumb_pointer( const dumb_pointer< T2> & b) : ptr_( b.ptr_) {}
		T & operator*() const { return * operator->(); }
		T * operator->() const { return ptr_ == nullptr ? object_traits< T>::get_dummy_object() : ptr_; }
		bool operator!() const { return ptr_ == nullptr; }
	private:
		T * ptr_;
		template< typename T2>
		friend class dumb_pointer;
	};

}

#endif
