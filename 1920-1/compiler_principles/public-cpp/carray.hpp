#ifndef GUARD_MLASKAL_CARRAY_HPP_
#define GUARD_MLASKAL_CARRAY_HPP_

/*

	carray.hpp

	Tiny wrapper above C-style array

	Kuba, 2006

*/

#include <cstddef>
#include <utility>
#include <algorithm>
#include <stdexcept>

namespace mlaskal {

	template <typename T>
	class carray {
	public:
		carray() : ptr_(0),n_(0) { }		// must be here for container requirements

		template <std::size_t N>
		explicit carray(const T (&a)[N]) : ptr_(a),n_(N) { }

		// container requirements
		typedef T				value_type;
		typedef T &				reference;
		typedef T const &		const_reference;
		typedef T const *		const_iterator;
		typedef std::ptrdiff_t		difference_type;
		typedef std::size_t		size_type;

		const_iterator begin() const { return ptr_; }
		const_iterator end() const { return ptr_+n_; }

		size_type size() const { return n_; }
		size_type max_size() const { return n_; }
		bool empty() const { return n_==0; }

		template <typename U>
		void swap(carray<U> &u)
		{
			std::swap(ptr_, u.ptr_);
			std::swap(n_, u.n_);
		}

		const_reference operator[](size_type idx) const { return ptr_[idx]; }
		const_reference at(size_type idx) const { if(idx>=n_) throw std::out_of_range("carray index out of range"); return ptr_[idx]; }

		// custom functions
		const T *data() const { return ptr_; }

	private:
		const T			*ptr_;
		std::size_t n_;
	};

	template <typename T>
	bool operator==(const carray<T> &lhs, const carray<T> &rhs) {
		return lhs.size()==rhs.size() && (lhs.empty() || std::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
	template <typename T>
	bool operator!=(const carray<T> &lhs, const carray<T> &rhs) {
		return lhs.size()!=rhs.size() || (!lhs.empty() && !std::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
	template <typename T>
	bool operator<(const carray<T> &lhs, const carray<T> &rhs) {
		return lhs.size()<rhs.size() || std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	template <typename T>
	bool operator>(const carray<T> &lhs, const carray<T> &rhs) {
		return rhs.size()<lhs.size() || std::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
	}
	template <typename T>
	bool operator<=(const carray<T> &lhs, const carray<T> &rhs) {
		return rhs.size()>=lhs.size() && !std::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());;
	}
	template <typename T>
	bool operator>=(const carray<T> &lhs, const carray<T> &rhs) {
		return lhs.size()>=rhs.size() && !std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

}

#endif
