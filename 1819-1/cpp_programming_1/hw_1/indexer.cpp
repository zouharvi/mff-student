#include "indexer.h"

Indexer::Indexer(std::istream &articles, std::istream &queries, std::ostream &out) : articles_stream(articles), queries_stream(queries), out(out)
{
    load_articles();
    process_queries();
}

void Indexer::load_articles()
{
    std::string id, title, body;
    // id is the var which will read empty line (we're promised this format)
    while (std::getline(articles_stream, id) && id != "" && std::getline(articles_stream, title) && std::getline(articles_stream, body))
    {
        std::string word;
        std::shared_ptr<Article> article = std::make_shared<Article>(id, title, body);
        for (size_t i = 0; i < body.length(); i++)
        {
            if (Utils::is_letter(body[i]))
            {
                // this could be microoptimized, but it's nothing compared to other operations
                word += body[i];
            }
            else
            {
                // check buffer on nonword char
                if (word.length() != 0)
                {
                    std::string lowered = Utils::to_lower(word);
                    index[lowered].insert(ArticleLoc(i - word.length(), article));
                    word.clear();
                }
            }
        }
        // check buffer on end of line
        if (word.length() != 0)
        {
            std::string lowered = Utils::to_lower(word);
            index[lowered].insert(ArticleLoc(body.length() - word.length(), article));
        }
    }
}

void Indexer::process_queries()
{
    std::string line;
    std::getline(queries_stream, line);

    std::vector<std::vector<std::string>> queries;
    while (line != "")
    {
        std::vector<std::string> query_buff;
        std::string word_buff;
        for (auto c : line)
        {
            if (Utils::is_letter(c))
            {
                word_buff += c;
            }
            else
            {
                // check buffer on nonword char
                if (word_buff.length() != 0)
                {
                    query_buff.push_back(Utils::to_lower(word_buff));
                    word_buff.clear();
                }
            }
        }
        // check buffer on end of lien
        if (word_buff.length() != 0) {
            query_buff.push_back(Utils::to_lower(word_buff));
        }

        queries.push_back(query_buff);
        std::getline(queries_stream, line);
    }

    // no need to make queries unique, since intersection will not affect the result
    // and time complexity will not drop
    for (auto query : queries)
    {
        // some legit keywords exist
        if (query.size() != 0)
        {
            bool no_results = false;
            std::vector<std::set<ArticleLoc>> query_occurences;
            for (auto keyword : query)
            {
                if (index.find(keyword) != index.end())
                {
                    query_occurences.push_back(index.at(keyword));
                }
                else
                {
                    no_results = true;
                    break;
                }
            }

            // output is sorted, because we use the set object
            auto query_intersection = Utils::intersect(query_occurences);
            if (no_results || query_intersection.size() == 0)
            {
                out << "No results\n"
                    << std::endl;
            }
            else
            {
                for (ArticleLoc loc : query_intersection)
                {
                    out << "[" << loc.obj->id << "] " << loc.obj->title << std::endl;
                    out << loc.obj->body.substr(loc.position, 75) << "..." << std::endl;
                }
                out << std::endl;
            }
        }
        else
        {
            // empty query
            out << "No results\n"
                << std::endl;
        }
    }
}