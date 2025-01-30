#include <string>
#include <iostream>
#include <memory>
#include "zimadb.h"
#include "meta_system.h"
#include "../compiler/compiler.h"
#include "../utils/tokenizer.h"

#ifdef __linux__
	// external libraries
	#include <readline/readline.h>
	#include <readline/history.h>
#endif

class Front
{
public:
  // constructor with filename string parameter
  // pass empty string if no file specified
  Front(std::string);

  // input entry point
  void start_loop();

private:
  // buffer for multiline inputs
  std::string buffer = "";

  // two main processing systems
  std::unique_ptr<MetaSystem> meta_system;
  std::unique_ptr<Compiler> compiler;

  // main db interface
  std::shared_ptr<DbConnector> db;

  // main program input loading loop
  void loop(std::string);

  // prompt and load next line
  char *next_line();

  // program vars
  const std::string PROMPT_WORD = "zimadb> ";
  const std::string PROMPT_WORD_CONTINUE = "   ...> ";

  // user welcome
  const std::string HELLO_USER = "ZimaDB version " + std::string(ZIMADB_VERSION) + "\nEnter `.help` for usage hints.";
  const std::string NO_PERNAMENT_DB = "No .zima file specified. Using `default.zima` instead.";
};