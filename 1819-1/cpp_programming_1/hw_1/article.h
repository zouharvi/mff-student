#ifndef ARTICLE_H
#define ARTICLE_H

#include <string>
#include <memory>
#include "utils.h"

class Article
{
  public:
    Article(std::string id, std::string title, std::string body) : id(id), title(title), body(body){};
    std::string id, title, body;
};

class ArticleLoc
{
  public:
    ArticleLoc(size_t position, std::shared_ptr<Article> obj) : position(position), obj(obj){};

    // makes std containers sort this locator by article title
    bool operator<(const ArticleLoc &a) const
    {
        return a.obj->id > obj->id;
    };
    bool operator>(const ArticleLoc &a) const
    {
        return a.obj->id < obj->id;
    };

    // used int Utils intersection
    bool operator==(const ArticleLoc &a) const
    {
        return a.obj->id == obj->id;
    };
    bool operator!=(const ArticleLoc &a) const
    {
        return a.obj->id != obj->id;
    };

    // pointer to the real Article data + word beginning position
    std::shared_ptr<Article> obj;
    size_t position;
};

#endif