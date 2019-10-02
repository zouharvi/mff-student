#include <vector>
#include <memory>
#include <iostream>

template<typename T> class Pole {
public:
    Pole( size_t chunk = 100) : chunk_(chunk), size_(0) {};
    void push_back( const T& x) {
        resize( ++size_); (*this)[size_-1] = x;
    };
    T& operator[] ( size_t i) {
        return hrabe_[i / chunk_][i%chunk_];
    };
    T& at( size_t i) {
        check(i);
        return (*this)[i];
    }
    
    struct iterator { 
        iterator(typename std::vector< std::unique_ptr<T[]>>::iterator ptr, size_t chunk, size_t total) :
        ptr_(ptr), chunk_(chunk), total_(total) {};
        bool operator!= (const iterator a) {
            return total_ != a.total_;
        }
        void operator++() {
            if(cur_i_ >= chunk_-1) {
                cur_i_ = 0;
                ptr_++;
            } else {
                cur_i_ ++;
            }
            total_++;
        }
        T operator*() {
            return (*ptr_).get()[cur_i_];
        }
        typename std::vector< std::unique_ptr<T[]>>::iterator ptr_;
        size_t chunk_;
        size_t cur_i_ = 0;
        size_t total_ = 0;
    };
    
    iterator begin() {
        return iterator(hrabe_.begin(), chunk_, 0);
    };
    iterator end() {
        return iterator(hrabe_.end(), chunk_, size_);
    };
    
private:
    void check( size_t i) {
        if (i >= size_) 
            throw new std::exception(); //"Invalid access index"
    }
    void resize( size_t i) {
        for( size_t k = hrabe_.size(); k <= i / chunk_; ++k)
            hrabe_.push_back( std::make_unique< T[]>(chunk_));
    }
    
    size_t chunk_;
    size_t size_;
    std::vector< std::unique_ptr<T[]>> hrabe_;
};
