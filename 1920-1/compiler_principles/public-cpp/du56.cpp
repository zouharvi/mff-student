/*

	DU6.CPP

	DB

	Main for DU6

*/

#include "duerr.hpp"
#include "dutables.hpp"
#include "el_shr_ptr.hpp"

#include "du3456g.hpp"

#include "icm_flat_icblock.hpp"
#include "icm_machine.hpp"
#include "icexcept.hpp"


void exec_ic(const mlc::config & c, const std::unique_ptr< mlaskal::abstract_ic> & e)
{
	mlaskal::icm_machine_trace_options to;
	to.trace_state = false;
	to.instruction_limit_ = 1000000000;
	to.stack_limit_ = 1000000;

	std::string machname = "stack";
	auto m = std::find_if(
		mlaskal::icm_machines_::machines.begin(), 
		mlaskal::icm_machines_::machines.end(), 
		[& machname](const mlaskal::icm_machines_::machine &m) { return m.name_ == machname; });
	if (m == mlaskal::icm_machines_::machines.end())   // not found
	{
		std::cout << "Internal error: Unknown machine name \"" << machname << "\"\n";
		return;
	}

	try
	{
		mlaskal::icm_flat_icblock inic(* e);

		// construct the machine
		mlaskal::icm_machine *the_machine = mlaskal::machine_factory::create_machine(*m, &inic, nullptr, to);

		// do simulation
		the_machine->simulate();
	}
	catch (const mlaskal::ic_except &iex)
	{
		std::cout << "ERROR: " << iex.get_msg();
		if (iex.has_ip())
			std::cout << " on IP=" << iex.get_ip();
		std::cout << '\n';
	}
}

int main(int argc, char **argv)
{
	try {
		auto c = mlc::read_args56(argc, argv);

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

			mlc::dump_tab(c, f);
		}
		mlc::dump_ic(c, e);

		if (!mlc::n_errors)
		{
			std::cout << "****** PROGRAM OUTPUT ******" << std::endl;
			exec_ic(c, e);
			std::cout << "****************************" << std::endl;
		}
	}
	catch (...) {}

	return 0;
}
