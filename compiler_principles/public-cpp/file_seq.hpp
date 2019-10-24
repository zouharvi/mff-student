#ifndef GUARD_MLASKAL_FILE_SEQ_H_
#define GUARD_MLASKAL_FILE_SEQ_H_

/*

	file_seq.hpp

	File sequence operation

	Kuba, 2006

*/

#include <iostream>
#include <algorithm>
#include <string>

namespace mlaskal {

	template <typename T>
	struct rwtrait_gen {
		class read_bin_ftor {
		public:
			read_bin_ftor(std::istream &is) : is_(&is) { }
			T operator()()
			{
			T tmp;

				is_->read(reinterpret_cast<char *>(&tmp), sizeof(T));
				return tmp;
			}
		private:
			std::istream *is_;
		};
		class write_bin_ftor {
		public:
			write_bin_ftor(std::ostream &os) : os_(&os) { }
			void operator()(const T &v)
			{
				os_->write(reinterpret_cast<const char *>(&v), sizeof(T));
			}
		private:
			std::ostream *os_;
		};
		template <typename U>
		class write_asm_ftor {
		public:
			write_asm_ftor(std::ostream &os, const U &) : os_(&os),count_(0) { }
			void operator()(const T &v)
			{
				*os_ << count_++ << ":\t" << v << '\n';
			}
		private:
			std::ostream	*os_;
			int					count_;
		};
	};

	template <typename T, typename RWTrait>
	struct file_seq {

		template <typename Container>
		static void read_bin(Container &cont, std::istream &is)
		{
		unsigned u;

			is.read(reinterpret_cast<char *>(&u), sizeof(unsigned));
			for(;u;--u)
				cont.push_back(typename RWTrait::read_bin_ftor(is)());
		}

		template <typename Container>
		static void write_bin(const Container &cont, std::ostream &os)
		{
		unsigned u;

			u = static_cast<unsigned>(cont.size());
			os.write(reinterpret_cast<const char *>(&u), sizeof(unsigned));
			std::for_each(cont.begin(), cont.end(), typename RWTrait::write_bin_ftor(os));
		}

		template <typename Container, typename IdContainer>
		static void write_asm(const Container &cont, std::ostream &os, const std::string &msg, const IdContainer &ids)
		{
			if(!msg.empty())
				os << msg << '\n';
			std::for_each(cont.begin(), cont.end(), typename RWTrait::template write_asm_ftor<IdContainer>(os, ids));
			if(!msg.empty())
				os << '\n';
		}
	};

	template <typename Cont>
	void file_seq_read_cont_bin(Cont &cont, std::istream &is)
	{
		file_seq<typename Cont::value_type, rwtrait_gen<typename Cont::value_type> >::read_bin(cont, is);
	}
	template <typename Cont>
	void file_seq_write_cont_bin(const Cont &cont, std::ostream &os)
	{
		file_seq<typename Cont::value_type, rwtrait_gen<typename Cont::value_type> >::write_bin(cont, os);
	}
	template <typename Cont, typename IdCont>
	void file_seq_write_cont_asm(const Cont &cont, std::ostream &os, const std::string &msg, const IdCont &ids)
	{
		file_seq<typename Cont::value_type, rwtrait_gen<typename Cont::value_type> >::write_asm(cont, os, msg, ids);
	}

	// explicit specialization for complicated types
	template <>
	struct rwtrait_gen<std::string> {
		class read_bin_ftor {
		public:
			read_bin_ftor(std::istream &is) : is_(&is) { }
			std::string operator()()
			{
			std::string tmp;
			char ch;

				file_seq_read_cont_bin(tmp, *is_);
				is_->read(&ch, sizeof(char));		// skip the ending 0
				return tmp;
			}
		private:
			std::istream *is_;
		};
		class write_bin_ftor {
		public:
			write_bin_ftor(std::ostream &os) : os_(&os) { }
			void operator()(const std::string &v)
			{
			unsigned u;

				u = static_cast<unsigned>(v.size());
				os_->write(reinterpret_cast<const char *>(&u), sizeof(unsigned));
				os_->write(v.c_str(), u+1);
			}
		private:
			std::ostream *os_;
		};
		template <typename U>
		class write_asm_ftor {
		public:
			write_asm_ftor(std::ostream &os, const U &) : os_(&os),count_(0) { }
			void operator()(const std::string &v)
			{
				*os_ << count_++ << ":\t\"" << v << "\"\n";
			}
		private:
			std::ostream	*os_;
			int					count_;
		};
	};

}

#endif
