/*

	DUERR.H

	JY

	Error facility

*/

#ifndef DUERR_H_
#define DUERR_H_

#include "carray.hpp"
#include "dubaseerr.hpp"

namespace mlc {

	enum err_type { DUERRT_VOID, DUERRT_S, DUERRT_CI, DUERRT_I, DUERRT_SI, DUERRT_II, DUERRT_IS };

	struct errs {
		int						errc;
		enum err_type		errt;
		const char				*msg;
	};

	void message(int err, unsigned line);
	void message(int err, unsigned line, const char *s);
	void message(int err, unsigned line, char c, int i);
	void message(int err, unsigned line, int i);
	void message(int err, unsigned line, const char *s, int i);
	void message(int err, unsigned line, int i, int j);
	void message(int err, unsigned line, int i, const char *s);

	inline void message(int err, unsigned line, const std::string & s)
	{
		message( err, line, s.c_str());
	}

	extern int n_warnings, n_errors;

	void final_message();

	extern mlaskal::carray<errs> base_errors;

	struct config
	{
		config() : debug_symtab(false) {}
		std::string asm_file;
		bool debug_symtab;
		std::string dump_fname;
		std::string in_file;
		std::string obj_file;
	};

	config read_args12(int argc, char * * argv);

	config read_args3(int argc, char * * argv);

	config read_args4(int argc, char * * argv);

	config read_args56(int argc, char * * argv);
}

#endif
