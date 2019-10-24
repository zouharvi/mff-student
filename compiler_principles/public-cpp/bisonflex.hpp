/*

bisonflex.hpp

Warning: Contains macros
Include only in bfexpl.lex and bfexpg.y

*/

#ifndef BISONFLEX_HPP__
#define BISONFLEX_HPP__

// define YY_DECL which is used in lex.cpp and grammar.y
#define YY_DECL yy::mlaskal_parser::symbol_type yylex(mlc::yyscan_t2 yyscanner, mlc::MlaskalCtx *ctx)

#endif

