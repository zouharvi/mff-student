/*

	DUERR.CPP

	JY

	Error facility

*/

#include <cstdio>
#include <cstdlib>
#include <utility>
#include <map>
#include <cassert>
#include <algorithm>
#include <iostream>

#include "duerr.hpp"
#include "el_shr_ptr.hpp"

using namespace std;

namespace {

	typedef pair<int, const mlc::errs *> ERRMP;
	typedef map<int, const mlc::errs *> ERRMM;
	typedef ERRMM::const_iterator ERRMCI;

	ERRMM err_map;

	class ftor_err_map_insert {
	public:
		ftor_err_map_insert(ERRMM &em) : em_(&em) { }
		void operator()(const mlc::errs &e) const {
			bool rv = em_->insert(ERRMP(e.errc, &e)).second;
			assert(rv);
		}
	private:
		ERRMM		*em_;
	};


}

namespace mlc {

	int n_warnings, n_errors;

	void final_message()
	{
		if (n_errors)
			message(DUERR_ERRS, 0, n_errors, n_warnings);
		else if (n_warnings)
			message(DUERR_NOK, 0, n_warnings);
		else
			message(DUERR_OK, 0);
	}

	void error_common(int err, unsigned line)
	{
		if(err_map.empty())		// the map is empty
		{
			for_each(base_errors.begin(), base_errors.end(), ftor_err_map_insert(err_map));
		}

		if(err>=DUERR_WARNING && err<DUERR_ERROR)
			++n_warnings;
		else if(err>=DUERR_ERROR && err<DUERR_FATAL)
			++n_errors;

		fputs(err>=DUERR_FATAL?"Fatal error":err>=DUERR_ERROR?"Error":err>=DUERR_WARNING?"Warning":"", stdout);
		if(line)
			printf(" (line %u)", line);
		if(err>=DUERR_WARNING)
			fputs(": ", stdout);
	}

	void message(int err, unsigned line)
	{
		error_common( err, line);

		ERRMCI mci = err_map.find(err);

		if(mci!=err_map.end())
		{
			const errs *e = mci->second;
			if ( e->errt == DUERRT_VOID )
				fputs(e->msg, stdout);
			else
				printf("Missing error parameter %d: %s", err, e->msg);
		}
		else
			printf("Unknown error %d", err);

		puts("");

		if(err>=DUERR_FATAL)
			exit(16);
	}

	void message(int err, unsigned line, const char *s)
	{
		error_common( err, line);

		ERRMCI mci = err_map.find(err);

		if(mci!=err_map.end())
		{
			const errs * e = mci->second;
			if ( e->errt == DUERRT_S )
				printf(e->msg, s);
			else
				printf("Missing error parameter %d: %s", err, e->msg);
		}
		else
			printf("Unknown error %d", err);

		puts("");

		if(err>=DUERR_FATAL)
			exit(16);
	}

	void message(int err, unsigned line, char c, int i)
	{
		error_common( err, line);

		ERRMCI mci = err_map.find(err);

		if(mci!=err_map.end())
		{
			const errs *e = mci->second;
			if ( e->errt == DUERRT_CI )
				printf(e->msg, c, i);
			else
				printf("Missing error parameter %d: %s", err, e->msg);
		}
		else
			printf("Unknown error %d", err);

		puts("");

		if(err>=DUERR_FATAL)
			exit(16);
	}

	void message(int err, unsigned line, int i)
	{
		error_common( err, line);

		ERRMCI mci = err_map.find(err);

		if(mci!=err_map.end())
		{
			const errs *e = mci->second;
			if ( e->errt == DUERRT_I )
				printf(e->msg, i);
			else
				printf("Missing error parameter %d: %s", err, e->msg);
		}
		else
			printf("Unknown error %d", err);

		puts("");

		if(err>=DUERR_FATAL)
			exit(16);
	}


	void message(int err, unsigned line, const char *s, int i)
	{
		error_common( err, line);

		ERRMCI mci = err_map.find(err);

		if(mci!=err_map.end())
		{
			const errs *e = mci->second;
			if ( e->errt == DUERRT_SI )
				printf(e->msg, s, i);
			else
				printf("Missing error parameter %d: %s", err, e->msg);
		}
		else
			printf("Unknown error %d", err);

		puts("");

		if(err>=DUERR_FATAL)
			exit(16);
	}

	void message(int err, unsigned line, int i, int j)
	{
		error_common( err, line);

		ERRMCI mci = err_map.find(err);

		if(mci!=err_map.end())
		{
			const errs *e = mci->second;
			if ( e->errt == DUERRT_II )
				printf(e->msg, i, j);
			else
				printf("Missing error parameter %d: %s", err, e->msg);
		}
		else
			printf("Unknown error %d", err);

		puts("");

		if(err>=DUERR_FATAL)
			exit(16);
	}

	void message(int err, unsigned line, int i, const char *s)
	{
		error_common( err, line);

		ERRMCI mci = err_map.find(err);

		if(mci!=err_map.end())
		{
			const errs *e = mci->second;
			if ( e->errt == DUERRT_IS )
				printf(e->msg, i, s);
			else
				printf("Missing error parameter %d: %s", err, e->msg);
		}
		else
			printf("Unknown error %d", err);

		puts("");

		if(err>=DUERR_FATAL)
			exit(16);
	}

	config read_args12(int argc, char * * argv)
	{
		config c;

		if (argc < 2)
		{
			std::cout << "Usage: du12 <input_file>\n";
			throw std::domain_error("invalid arguments");
		}

		c.in_file = argv[1];

		return std::move(c);
	}


	config read_args3(int argc, char * * argv)
	{
		config c;

		if (argc < 2)
		{
			std::cout << "Usage: du3 <input_file>\n";
			throw std::domain_error("invalid arguments");
		}

		c.in_file = argv[1];

		return std::move(c);
	}


	config read_args4(int argc, char * * argv)
	{
		config c;

		if (argc < 2)
		{
		usage:
			std::cout << "Usage: du4 <input_file> [options]\n";
			std::cout << "Options:\n";
			std::cout << "\t-B\t\tdebug symbol tables\n";
			std::cout << "\t-D<xml_file>\t\tdump symbol tables canonically\n";
			throw std::domain_error("invalid arguments");
		}

		for (int i = 2; i < argc; ++i)
			if (argv[i][0] == '/' || argv[i][0] == '-')
				switch (argv[i][1])
				{
				case 'D':
					c.dump_fname = argv[i] + 2;
					break;
				case 'B':
					c.debug_symtab = true;
					break;
				}
			else
			{
				std::cout << "Unknown parameter \"" << argv[i] << "\"\n";
				goto usage;
			}

		c.in_file = argv[1];

		return std::move(c);
	}

	config read_args56(int argc, char * * argv)
	{
		config c;

		if (argc < 2)
		{
		usage:
			std::cout << "Usage: du56 <input_file> [options]\n";
			std::cout << "Options:\n";
			std::cout << "\t-S<asm_file>\tassembler listing\n";
			std::cout << "\t-M<asm_file>\tbytecode output\n";
			std::cout << "\t-B\t\tdebug symbol tables\n";
			std::cout << "\t-D<xml_file>\t\tdump symbol tables canonically\n";
			throw std::domain_error("invalid arguments");
		}

		for (int i = 2; i < argc; ++i)
			if (argv[i][0] == '/' || argv[i][0] == '-')
				switch (argv[i][1])
				{
				case 'D':
					c.dump_fname = argv[i] + 2;
					break;
				case 'S':
					c.asm_file = argv[i] + 2;
					break;
				case 'M':
					c.obj_file = argv[i] + 2;
					break;
				case 'B':
					c.debug_symtab = true;
					break;
				}
			else
			{
				std::cout << "Unknown parameter \"" << argv[i] << "\"\n";
				goto usage;
			}

		c.in_file = argv[1];

		return std::move(c);
	}


#if defined( _MSC_VER)
void myInvalidParameterHandler(const wchar_t* expression,
	const wchar_t* function,
	const wchar_t* file,
	unsigned int line,
	uintptr_t)
{
	wprintf(L"Invalid parameter detected in function %s."
		L" File: %s Line: %d\n", function, file, line);
	wprintf(L"Expression: %s\n", expression);
	assert(0);
}
#endif

#pragma warning (disable:4189 4100)

std::unique_ptr< protection_data> protection_start()
{
#if defined(_MSC_VER)
	{
		int rv1 = _set_error_mode(_REPORT_ERRMODE);
		int rv2 = _set_error_mode(_OUT_TO_STDERR);
		int rv3 = _set_error_mode(_REPORT_ERRMODE);
		//std::cerr << "Error mode switched: " << rv1 << "," << rv2 << "," << rv3 << std::endl;
	}
	{
		int rv1 = _CrtSetReportMode(_CRT_WARN, _CRTDBG_REPORT_MODE);
		int rv2 = _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
		int rv3 = _CrtSetReportMode(_CRT_WARN, _CRTDBG_REPORT_MODE);
		//std::cerr << "_CRT_WARN mode switched: " << rv1 << "," << rv2 << "," << rv3 << std::endl;
	}
	{
		_HFILE rv1 = _CrtSetReportFile(_CRT_WARN, _CRTDBG_REPORT_FILE);
		_HFILE rv2 = _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
		_HFILE rv3 = _CrtSetReportFile(_CRT_WARN, _CRTDBG_REPORT_FILE);
		//std::cerr << "_CRT_WARN file switched: " << rv1 << "," << rv2 << "," << rv3 << std::endl;
	}
	{
		int rv1 = _CrtSetReportMode(_CRT_ERROR, _CRTDBG_REPORT_MODE);
		int rv2 = _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
		int rv3 = _CrtSetReportMode(_CRT_ERROR, _CRTDBG_REPORT_MODE);
		//std::cerr << "_CRT_ERROR mode switched: " << rv1 << "," << rv2 << "," << rv3 << std::endl;
	}
	{
		_HFILE rv1 = _CrtSetReportFile(_CRT_ERROR, _CRTDBG_REPORT_FILE);
		_HFILE rv2 = _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
		_HFILE rv3 = _CrtSetReportFile(_CRT_ERROR, _CRTDBG_REPORT_FILE);
		//std::cerr << "_CRT_ERROR file switched: " << rv1 << "," << rv2 << "," << rv3 << std::endl;
	}
	{
		int rv1 = _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_REPORT_MODE);
		int rv2 = _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
		int rv3 = _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_REPORT_MODE);
		//std::cerr << "_CRT_ASSERT mode switched: " << rv1 << "," << rv2 << "," << rv3 << std::endl;
	}
	{
		_HFILE rv1 = _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_REPORT_FILE);
		_HFILE rv2 = _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
		_HFILE rv3 = _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_REPORT_FILE);
		//std::cerr << "_CRT_ASSERT file switched: " << rv1 << "," << rv2 << "," << rv3 << std::endl;
	}
	{
		_invalid_parameter_handler oldHandler, newHandler;
		newHandler = myInvalidParameterHandler;
		oldHandler = _set_invalid_parameter_handler(newHandler);
		//std::cerr << "invalid_parameter_handler switched: " << oldHandler << "," << newHandler << std::endl;
	}
#endif

	auto p = std::make_unique< protection_data>();

#if defined( DEBUG_MEMORY_LEAKS) && defined( _MSC_VER) && defined( _DEBUG)
	p->msOld.Checkpoint();
#endif

	return p;
};

protection_data::~protection_data()
{
#if defined( DEBUG_MEMORY_LEAKS) && defined( _MSC_VER) && defined( _DEBUG)
	msOld.DumpAllObjectsSince();
#endif
}

}
