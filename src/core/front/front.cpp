#include "front/front.h"

char *Front::next_line()
{
    return readline(buffer.length() == 0 ? PROMPT_WORD.c_str() : PROMPT_WORD_CONTINUE.c_str());
}

void Front::start_loop()
{
    std::cout << HELLO_USER << std::endl;

    // we use char* as a tradeoff for being able to use the readline library
    char *buf;
    while ((buf = next_line()) != nullptr)
    {
        if (strlen(buf) > 0)
        {
            add_history(buf);
            loop(std::string(buf));
        }
    }
    std::cout << std::endl;
}

void Front::loop(std::string line)
{
    // if buffer is empty and this is probably a meta command
    if (buffer.length() == 0 && Tokenizer::is_meta(line))
    {
        meta_system->process(Tokenizer::split(line.substr(1)));
    }
    else
    {
        // we accept multiline string, hence this cumbersome process
        buffer += "\n" + line;

        // even a batch of commands has to end with a semicolon
        if (Tokenizer::is_end_query(line))
        {
            auto queries_raw = Tokenizer::extract_queries(
                Tokenizer::split(
                    buffer));
            buffer.clear();

            for (auto query_raw : queries_raw)
            {
                compiler->process(query_raw);
            }
        }
    }
}

Front::Front(std::string file)
{
    db = std::make_shared<DbConnector>();

    meta_system = std::make_unique<MetaSystem>(file, db);
    compiler = std::make_unique<Compiler>(db);
}