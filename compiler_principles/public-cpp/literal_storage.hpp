#ifndef GUARD_MLASKAL_LITERAL_STORAGE_HPP_
#define GUARD_MLASKAL_LITERAL_STORAGE_HPP_

/*

	literal_storage.hpp

	Literal storage

	Kuba, 2006

*/

#include <list>
#include <algorithm>
#include <utility>
#include <stdexcept>

#include "common_types.hpp"

namespace mlaskal {

	template <typename T, bool ISID>
	class cptr_lit_storage {
	public:
		cptr_lit_storage() : ptr_(0) { }
		cptr_lit_storage(const T* ptr) : ptr_(ptr) { }
		const T& operator*() const { return * operator->(); }
		bool operator!() const { return !ptr_; }
		const T* operator->() const { return ptr_ ? ptr_ : object_traits< T>::get_dummy_object(); }
	private:
		const T*	ptr_;

		template <typename TT, bool ISIDISID>
		friend bool operator==(const cptr_lit_storage<TT, ISIDISID> &lhs, const cptr_lit_storage<TT, ISIDISID> &rhs);
		template <typename TT, bool ISIDISID>
		friend bool operator!=(const cptr_lit_storage<TT, ISIDISID> &lhs, const cptr_lit_storage<TT, ISIDISID> &rhs);
		template <typename TT, bool ISIDISID>
		friend bool operator!=(const TT *lhs, const cptr_lit_storage<TT, ISIDISID> &rhs);
	};

	template <typename T, bool ISID>
	bool operator==(const cptr_lit_storage<T, ISID> &lhs, const cptr_lit_storage<T, ISID> &rhs) { return lhs.ptr_==rhs.ptr_; }
	template <typename T, bool ISID>
	bool operator!=(const cptr_lit_storage<T, ISID> &lhs, const cptr_lit_storage<T, ISID> &rhs) { return lhs.ptr_!=rhs.ptr_; }
	template <typename T, bool ISID>
	bool operator!=(const T *lhs, const cptr_lit_storage<T, ISID> &rhs) { return lhs!=rhs.ptr_; }

	/// literal/identifier storage
	template <typename T, bool ISID>
	class lit_storage
	{
	public:

		// container requirements
		typedef T value_type;		///< container requirement
		typedef T & reference;		///< container requirement
		typedef const T & const_reference;		///< container requirement
		typedef typename std::list<T>::size_type size_type;		///< container requirement
		typedef typename std::list<T>::const_iterator const_iterator;		///< container requirement
//		typedef const T * const_pointer;
		typedef cptr_lit_storage<T, ISID> const_pointer;

		size_type size() const { return lit_.size(); }		///< container requirement
		const_iterator begin() const { return lit_.begin(); }		///< container requirement
		const_iterator end() const { return lit_.end(); }		///< container requirement
		bool empty() const { return lit_.empty(); }		///< container requirement

		// additional functions and types

		/// @cond INTERNAL
		typedef ICLITIDX index_type;
		/// @endcond

		/// store a literal/identifier
		/**
			creates new entry if not found

			returns an iterator 
		**/
		const_pointer add(const T &sval)
		{
			const_iterator tmp=std::find(lit_.begin(), lit_.end(), sval);

			if(tmp==lit_.end())				// not_found
			{
				lit_.push_back(sval);
				tmp = --lit_.end();
			}

			return &*tmp;
		}

		// container
		void push_back(const T &v) { add(v); }		///< container requirement (partially conforming implementation)

		/// @cond INTERNAL

		const_pointer at_iter(index_type idx) const {
			const_iterator ci;
			for(ci=lit_.begin();idx && ci!=lit_.end();--idx,++ci);
			return & * ci;
		}

		const_reference at(index_type idx) const {
			const_pointer ci=at_iter(idx);
			if(!ci)
				throw std::out_of_range("Indexing into a literal storage");
			return *ci;
		}

		index_type compute_index(const_pointer cr) const {
			index_type idx=0;
			const_iterator ci;
			for(ci=lit_.begin();&*ci!=cr && ci!=lit_.end();++ci,++idx);
			if(ci==lit_.end())
				throw std::out_of_range("Computing index into a literal storage");
			return idx;
		}

		/// @endcond

	private:
		std::list<T>   lit_;
	};

/*
	template <typename T>
	std::ostream &operator<<(std::ostream &os, const lit_storage_proxy<T> &lsp)
	{
		if(!lsp.ls_)
			throw invalid_argument("Uninitialized lit_storage_proxy");
		os << lsp.ls_->at(lsp.idx_);
		return os;
	};
*/
}

#endif
