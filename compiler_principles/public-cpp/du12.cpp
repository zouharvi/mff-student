/*

	DU12.CPP

	JY

	Main for DU1-2

*/

#include <iostream>
#include <stdexcept>

#include "dummyg.hpp"
#include "duerr.hpp"
#include "el_shr_ptr.hpp"

using namespace std;
using namespace mlc;
using namespace mlaskal;

int main(int argc, char **argv)
{
	try {
		auto c = mlc::read_args12(argc, argv);

		auto d = mlc::open_file(c);

		auto state = mlc::protection_start();

		auto e = mlc::create_ic();
		{
			auto f = mlc::create_tab(c, e);

			try {
				mlc::parse< yy::mlaskal_parser>(d, f);
			}
			catch (...) {}

			mlc::final_message( f);
		}
	}
	catch (...) {}

	return 0;
}
