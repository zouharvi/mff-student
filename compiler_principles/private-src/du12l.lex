%{
	// this code is emitted into du12l.cpp 
	// avoid macro redefinition warnings when compiling du1l.cpp
	#pragma warning (disable:4005)
	// avoid unreferenced parameter warnings when compiling du1l.cpp
	#pragma warning (disable:4100)
	// avoid unreferenced function warnings when compiling du1l.cpp
	#pragma warning (disable:4505)

	// allow access to YY_DECL macro
	#include "bisonflex.hpp"

	// allow access to context 
	// CHANGE THIS LINE TO #include "du3456g.hpp" WHEN THIS FILE IS COPIED TO du3456l.lex
	#include "dummyg.hpp"
%}

/* DO NOT TOUCH THIS OPTIONS! */
%option noyywrap nounput batch noinput stack reentrant
%option never-interactive

WHITESPACE[ \r\t\f]

%x STRING
%x ML_COMMENT

%%

%{
	typedef yy::mlaskal_parser parser;
	int ml_comment_depth = 0;
	std::string ml_string_buff;
%}


\{	{
	ml_comment_depth = 1;
	BEGIN(ML_COMMENT);
}
<ML_COMMENT>\n			{ ctx->curline++; }
<ML_COMMENT>[^\{\}\n]+	{ }
<ML_COMMENT>\{			{ ml_comment_depth++; }
<ML_COMMENT>\} { 
	ml_comment_depth--;
	if (ml_comment_depth == 0)
		BEGIN(INITIAL);
}
\} message(mlc::DUERR_UNEXPENDCMT, ctx->curline);
<ML_COMMENT><<EOF>>  {
	message(mlc::DUERR_EOFINCMT, ctx->curline);
	BEGIN(INITIAL);
}

\'	{
	BEGIN(STRING);
	ml_string_buff = "";
}
<STRING>\'\' {
	ml_string_buff.append("'");
}
<STRING>\' {
	BEGIN(INITIAL);
	return parser::make_STRING(ctx->tab->ls_str().add(ml_string_buff), ctx->curline);
}
<STRING>\n {
	message(mlc::DUERR_EOLINSTRCHR, ctx->curline);
	BEGIN(INITIAL);
	return parser::make_STRING(ctx->tab->ls_str().add(ml_string_buff), ctx->curline++);
}
<STRING>. {
	ml_string_buff.append(yytext);
}

(;)		return parser::make_SEMICOLON(ctx->curline);
(\.)	return parser::make_DOT(ctx->curline);
(\.\.)	return parser::make_DOTDOT(ctx->curline);
(\:)	return parser::make_COLON(ctx->curline);

(?i:PROGRAM)	return parser::make_PROGRAM(ctx->curline);
(?i:BEGIN)	return parser::make_BEGIN(ctx->curline);
(?i:END)	return parser::make_END(ctx->curline);
(?i:IF)		return parser::make_IF(ctx->curline);
(?i:THEN)	return parser::make_THEN(ctx->curline);
(?i:ELSE)	return parser::make_ELSE(ctx->curline);
(?i:LABEL)	return parser::make_LABEL(ctx->curline);
(?i:TYPE)	return parser::make_TYPE(ctx->curline);
(?i:VAR)	return parser::make_VAR(ctx->curline);
(?i:CONST)	return parser::make_CONST(ctx->curline);

(?i:FUNCTION)	return parser::make_FUNCTION(ctx->curline);
(?i:PROCEDURE)	return parser::make_PROCEDURE(ctx->curline);
(?i:RECORD)		return parser::make_RECORD(ctx->curline);
(?i:ARRAY)		return parser::make_ARRAY(ctx->curline);

(?i:DO)		return parser::make_DO(ctx->curline);
(?i:FOR)	return parser::make_FOR(ctx->curline);
(?i:DOWNTO)	return parser::make_FOR_DIRECTION(mlc::DUTOKGE_FOR_DIRECTION::DUTOKGE_DOWNTO, ctx->curline);
(?i:TO)		return parser::make_FOR_DIRECTION(mlc::DUTOKGE_FOR_DIRECTION::DUTOKGE_TO, ctx->curline);
(?i:WHILE)	return parser::make_WHILE(ctx->curline);
(?i:GOTO)	return parser::make_GOTO(ctx->curline);
(?i:REPEAT) return parser::make_REPEAT(ctx->curline);
(?i:UNTIL) 	return parser::make_UNTIL(ctx->curline);

(?i:NOT)	return parser::make_NOT(ctx->curline);
(?i:OR)		return parser::make_OR(ctx->curline);
(?i:OF)		return parser::make_OF(ctx->curline);

(\,)	return parser::make_COMMA(ctx->curline);
(\+)	return parser::make_OPER_SIGNADD(mlc::DUTOKGE_OPER_SIGNADD::DUTOKGE_PLUS, ctx->curline);
(\-)	return parser::make_OPER_SIGNADD(mlc::DUTOKGE_OPER_SIGNADD::DUTOKGE_MINUS, ctx->curline);
(\*)	return parser::make_OPER_MUL(mlc::DUTOKGE_OPER_MUL::DUTOKGE_ASTERISK, ctx->curline);
(\/)	return parser::make_OPER_MUL(mlc::DUTOKGE_OPER_MUL::DUTOKGE_SOLIDUS, ctx->curline);
(=)		return parser::make_EQ(ctx->curline);
(\))	return parser::make_RPAR(ctx->curline);
(\()	return parser::make_LPAR(ctx->curline);
(\[)	return parser::make_LSBRA(ctx->curline);
(\])	return parser::make_RSBRA(ctx->curline);
(\:=)	return parser::make_ASSIGN(ctx->curline);

(?i:DIV)	return parser::make_OPER_MUL(mlc::DUTOKGE_OPER_MUL::DUTOKGE_DIV, ctx->curline);
(?i:MOD)	return parser::make_OPER_MUL(mlc::DUTOKGE_OPER_MUL::DUTOKGE_MOD, ctx->curline);
(?i:AND)	return parser::make_OPER_MUL(mlc::DUTOKGE_OPER_MUL::DUTOKGE_AND, ctx->curline);

(\<)	return parser::make_OPER_REL(mlc::DUTOKGE_OPER_REL::DUTOKGE_LT, ctx->curline);
(\<=)	return parser::make_OPER_REL(mlc::DUTOKGE_OPER_REL::DUTOKGE_LE, ctx->curline);
(\<\>)	return parser::make_OPER_REL(mlc::DUTOKGE_OPER_REL::DUTOKGE_NE, ctx->curline);
(\>=)	return parser::make_OPER_REL(mlc::DUTOKGE_OPER_REL::DUTOKGE_GE, ctx->curline);
(\>)	return parser::make_OPER_REL(mlc::DUTOKGE_OPER_REL::DUTOKGE_GT, ctx->curline);

[0-9]+[a-zA-Z][a-zA-Z0-9]*  {
	std::string buff = "";
	for(char & c: std::string(yytext)) {
		if(c >= '0' && c <= '9') {
			buff += c;
		}
	}
	message(mlc::DUERR_BADINT, ctx->curline, yytext);
	return parser::make_UINT(ctx->tab->ls_int().add(std::stoi(buff)), ctx->curline);
}
(([0-9]+\.)?[0-9]+(e|E)(\+|\-)?[0-9]+|[0-9]+\.[0-9]+)[a-zA-Z][a-zA-Z0-9]*	{
	std::string buff = "";
	for(char & c: std::string(yytext)) {
		if((c >= '0' && c <= '9') || c == 'e' || c == '.') {
			buff += c;
		}
	}
	message(mlc::DUERR_BADREAL, ctx->curline, yytext);
	return parser::make_REAL(ctx->tab->ls_real().add(std::stod(buff)), ctx->curline);
}

[0-9]+	{
	// conversion hack
	std::string tmp_buff(yytext);
	const ulong C31 = 2147483648;
	ulong sum = 0;
	bool ok = true;
	for(char & c: tmp_buff) {
		sum *= 10; 
		if(sum >= C31) 	ok = false;
		sum = sum % C31;
		sum += (c - '0');
		if(sum >= C31) 	ok = false;
	}
	if(!ok) message(mlc::DUERR_INTOUTRANGE, ctx->curline, yytext);
	return parser::make_UINT(ctx->tab->ls_int().add(sum), ctx->curline);
}
([0-9]+\.)?[0-9]+(e|E)(\+|\-)?[0-9]+	{
	double tmp = std::stod(yytext);
	return parser::make_REAL(ctx->tab->ls_real().add(tmp), ctx->curline);
}
[0-9]+\.[0-9]+	{
	double tmp = std::stod(yytext);
	return parser::make_REAL(ctx->tab->ls_real().add(tmp), ctx->curline);
}
[a-zA-Z][a-zA-Z0-9]*	{
	std::string tmp_buff(yytext);
	for (auto & c: tmp_buff) c = toupper(c);
	return parser::make_IDENTIFIER(ctx->tab->ls_id().add(tmp_buff), ctx->curline);
}

\n	{ ctx->curline++; }
{WHITESPACE}+	/* go out with whitespaces */

.	message(mlc::DUERR_UNKCHAR, ctx->curline, *yytext, *yytext);

<<EOF>>	return parser::make_EOF(ctx->curline);

%%

namespace mlc {

	yyscan_t2 lexer_init(FILE * iff)
	{
		yyscan_t2 scanner;
		yylex_init(&scanner);
		yyset_in(iff, scanner);
		return scanner;
	}

	void lexer_shutdown(yyscan_t2 scanner)
	{
		yyset_in(nullptr, scanner);
		yylex_destroy(scanner);
	}

}
