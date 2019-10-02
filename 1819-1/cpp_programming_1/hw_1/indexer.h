#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include "article.h"

class Indexer
{
  public:
    Indexer(std::istream &articles, std::istream &queries, std::ostream &out);

  private:
    // load from articles_stream
    void load_articles();
    // load from queries_stream and outputs to out
    void process_queries();

    std::ostream &out;
    std::istream &articles_stream, &queries_stream;
    std::map<std::string, std::set<ArticleLoc>> index;
};