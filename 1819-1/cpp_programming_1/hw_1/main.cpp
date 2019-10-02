#include <fstream>
#include "indexer.h"

int main(int argc, char **argv)
{
    // only filename specified, exiting
    if (argc <= 1 || argc >= 4)
        exit(0);
    else
    {
        // first argument is the article file
        std::ifstream article_file;
        article_file.open(argv[1]);
        if (article_file.fail())
            exit(0);

        // use stdin
        if (argc == 2)
            Indexer(article_file, std::cin, std::cout);
        else
        {
            // input file specified
            std::ifstream query_file;
            query_file.open(argv[2]);
            if (!query_file.fail())
            {
                Indexer(article_file, query_file, std::cout);
                query_file.close();
            }
        }

        article_file.close();
    }
}