%language "c++"
%require "3.0.4"
%defines
%define parser_class_name{ mlaskal_parser }
%define api.token.constructor
%define api.token.prefix{DUTOK_}
%define api.value.type variant
%define parse.assert
%define parse.error verbose

%locations
%define api.location.type{ unsigned }

%code requires
{
	// this code is emitted to du3456g.hpp

	// allow references to semantic types in %type
#include "dutables.hpp"

	// avoid no-case warnings when compiling du3g.hpp
#pragma warning (disable:4065)

// adjust YYLLOC_DEFAULT macro for our api.location.type
#define YYLLOC_DEFAULT(res,rhs,N)	(res = (N)?YYRHSLOC(rhs, 1):YYRHSLOC(rhs, 0))
// supply missing YY_NULL in bfexpg.hpp
#define YY_NULL	0
#define YY_NULLPTR	0
}

%param{ mlc::yyscan_t2 yyscanner }	// formal name "yyscanner" is enforced by flex
%param{ mlc::MlaskalCtx* ctx }

%start mlaskal

%code
{
	// this code is emitted to du3456g.cpp

	// declare yylex here 
	#include "bisonflex.hpp"
	YY_DECL;

	// allow access to context 
	#include "dutables.hpp"

	// other user-required contents
	#include <assert.h>
	#include <stdlib.h>

    /* local stuff */
    using namespace mlc;


// MY ADDED C++ CODE START ===========================================================

// parses a type identifier and returns a type_pointer
mlc::type_pointer type_identifier(mlc::MlaskalCtx* ctx, int line_number, mlc::ls_id_index id)
{
	auto ts = ctx->tab->find_symbol(id)->access_type();
	
	if (!ts)
		message(DUERR_NOTTYPE, line_number, *id);
	
	return ts->type();
}

// checks that a given type is a scalar type
void type_check_scalar(mlc::MlaskalCtx* ctx, int line_number, mlc::ls_id_index id, mlc::type_pointer tp)
{
	if (!tp) // tp is not a type, skip checks
		return;

	if (tp->cat() == TCAT_BOOL) return;
	if (tp->cat() == TCAT_INT) return;
	if (tp->cat() == TCAT_REAL) return;
	if (tp->cat() == TCAT_STR) return;
	
	message(DUERR_NOTSCALAR, line_number, *id);
}

// gets value of an integral constant identifier
mlc::ls_int_index resolve_integral_const(mlc::MlaskalCtx* ctx, int line_number, mlc::ls_id_index id)
{
	mlc::symbol_pointer sp = ctx->tab->find_symbol(id);
	if (sp->kind() != SKIND_CONST) { message(DUERR_NOTCONST, line_number, *id); }
	if (sp->access_const()->type()->cat() != TCAT_INT)
		message(DUERR_NOTINTEGRAL, line_number, *id);
	return sp->access_const()->access_int_const()->int_value();
}

// MY ADDED C++ CODE END =============================================================

}

%token EOF	0	"end of file"

%token PROGRAM			/* program */
%token LABEL			/* label */
%token CONST			/* const */
%token TYPE			    /* type */
%token VAR			    /* var */
%token BEGIN			/* begin */
%token END			    /* end */
%token PROCEDURE		/* procedure */
%token FUNCTION			/* function */
%token ARRAY			/* array */
%token OF				/* of */
%token GOTO			    /* goto */
%token IF				/* if */
%token THEN			    /* then */
%token ELSE			    /* else */
%token WHILE			/* while */
%token DO				/* do */
%token REPEAT			/* repeat */
%token UNTIL			/* until */
%token FOR			    /* for */
%token OR				/* or */
%token NOT			    /* not */
%token RECORD			/* record */

/* literals */
%token<mlc::ls_id_index> IDENTIFIER			/* identifier */
%token<mlc::ls_int_index> UINT			    /* unsigned integer */
%token<mlc::ls_real_index> REAL			    /* real number */
%token<mlc::ls_str_index> STRING			/* string */

/* delimiters */
%token SEMICOLON	    /* ; */
%token DOT			    /* . */
%token COMMA			/* , */
%token EQ				/* = */
%token COLON			/* : */
%token LPAR			    /* ( */
%token RPAR			    /* ) */
%token DOTDOT			/* .. */
%token LSBRA			/* [ */
%token RSBRA			/* ] */
%token ASSIGN			/* := */

/* grouped operators and keywords */
%token<mlc::DUTOKGE_OPER_REL> OPER_REL			    /* <, <=, <>, >=, > */
%token<mlc::DUTOKGE_OPER_SIGNADD> OPER_SIGNADD		/* +, - */
%token<mlc::DUTOKGE_OPER_MUL> OPER_MUL			    /* *, /, div, mod, and */
%token<mlc::DUTOKGE_FOR_DIRECTION> FOR_DIRECTION	/* to, downto */

// Custom

%type<mlc::type_pointer> type;
%type<mlc::type_pointer> ordinal_type;
%type<mlc::type_pointer> structured_type;
%type<std::list<mlc::type_pointer>> ordinal_type_list;
%type<mlc::type_pointer> ordinal_type_list_item;
%type<mlc::field_list_ptr> optional_field_list;
%type<mlc::field_list_ptr> field_list;
%type<mlc::field_list_ptr> field_list_item;

%type<mlc::ls_int_index> ordinal_constant;

%type<mlc::parameter_list_ptr> parenthesised_param_list
%type<mlc::parameter_list_ptr> formal_parameters
%type<mlc::parameter_list_ptr> formal_parameters_item
%type<bool> optional_var

%type<mlc::DUTOKGE_OPER_SIGNADD> optional_sign

%type<std::list<mlc::ls_id_index>> identifier_list

// custom end
%%

/*
	NOTES:
	======
	Procedure = special kind of function
*/

mlaskal:	PROGRAM IDENTIFIER SEMICOLON block_p DOT;

/* CODE BLOCKS */

block_p:	label_declaration
		const_declaration
		type_declaration
		var_declaration
		func_declaration /* proc & func */
		statement_block;

block:	label_declaration
	const_declaration
	type_declaration
	var_declaration
	statement_block;

/* LABEL DECLARATION */

label_declaration:	LABEL label_uint_list SEMICOLON;
label_declaration:	/* SKIP */;

label_uint_list:	label_uint_list_item COMMA label_uint_list;
label_uint_list:	label_uint_list_item;

label_uint_list_item:	UINT {
	mlc::ic_label lbl = ctx->tab->new_label();
	ctx->tab->add_label_entry(@1, $1, lbl);
};

/* CONST DECLARATION */

const_declaration:	CONST const_declaration_list;
const_declaration:	/* SKIP */;

const_declaration_list:	const_declaration_item const_declaration_list;
const_declaration_list:	const_declaration_item;

const_declaration_item:	identifier_list EQ STRING SEMICOLON {
	for (mlc::ls_id_index id : $1)
		ctx->tab->add_const_str(@1, id, $3);
};
const_declaration_item:	identifier_list EQ optional_sign UINT SEMICOLON {
	mlc::ls_int_index val = $4;
	if ($3 == mlc::DUTOKGE_OPER_SIGNADD::DUTOKGE_MINUS) // handle minus
	{
		val = ctx->tab->ls_int().add(- *val);
	}
	for (mlc::ls_id_index id : $1)
		ctx->tab->add_const_int(@1, id, val);
};
const_declaration_item:	identifier_list EQ optional_sign REAL SEMICOLON {
	mlc::ls_real_index val = $4;
	if ($3 == mlc::DUTOKGE_OPER_SIGNADD::DUTOKGE_MINUS) // handle minus
	{
		val = ctx->tab->ls_real().add(- *val);
	}
	for (mlc::ls_id_index id : $1)
		ctx->tab->add_const_real(@1, id, val);
};

const_declaration_item:	identifier_list EQ IDENTIFIER SEMICOLON {
	mlc::symbol_pointer sp = ctx->tab->find_symbol($3);
	if (sp->kind() != SKIND_CONST)
		message(DUERR_NOTCONST, @3, * $3);
	
	// INT
	if (sp->access_const()->type()->cat() == TCAT_INT)
	{
		mlc::ls_int_index val = sp->access_const()->access_int_const()->int_value();
		for (mlc::ls_id_index id : $1)
			ctx->tab->add_const_int(@1, id, val);
	}
	
	// REAL
	if (sp->access_const()->type()->cat() == TCAT_REAL)
	{
		mlc::ls_real_index val = sp->access_const()->access_real_const()->real_value();
		for (mlc::ls_id_index id : $1)
			ctx->tab->add_const_real(@1, id, val);
	}
	
	// STR
	if (sp->access_const()->type()->cat() == TCAT_STR)
	{
		mlc::ls_str_index val = sp->access_const()->access_str_const()->str_value();
		for (mlc::ls_id_index id : $1)
			ctx->tab->add_const_str(@1, id, val);
	}
	
	// BOOL
	if (sp->access_const()->type()->cat() == TCAT_BOOL)
	{
		bool val = sp->access_const()->access_bool_const()->bool_value();
		for (mlc::ls_id_index id : $1)
			ctx->tab->add_const_bool(@1, id, val);
	}
};


/* TYPE DECLARATION */
type_declaration:	TYPE type_declaration_list;
type_declaration:	/* SKIP  */;

type_declaration_list:	type_declaration_item type_declaration_list;
type_declaration_list:	type_declaration_item;

type_declaration_item:	IDENTIFIER EQ type SEMICOLON {
	ctx->tab->add_type(@1, $1, $3);
};

/* VAR DECLARATION */
var_declaration:	VAR var_declaration_list;
var_declaration:	/* SKIP */;

var_declaration_list:	var_declaration_item var_declaration_list;
var_declaration_list:	var_declaration_item;

var_declaration_item:	identifier_list COLON type SEMICOLON {
	for (mlc::ls_id_index id : $1)
		ctx->tab->add_var(@1, id, $3);
};

/* FUNCTION DECLARATION (list of functions) */
func_declaration:	func_declaration_item func_declaration;
func_declaration:	/* SKIP  */;

func_declaration_item: proc_header SEMICOLON block SEMICOLON { ctx->tab->leave(@4); };
func_declaration_item: func_header SEMICOLON block SEMICOLON { ctx->tab->leave(@4); };

proc_header:	PROCEDURE IDENTIFIER parenthesised_param_list {	
	ctx->tab->add_proc(@2, $2, $3);
	ctx->tab->enter(@2, $2);
};
func_header:	FUNCTION IDENTIFIER parenthesised_param_list COLON IDENTIFIER /* scalar type id */ {
	auto tp = type_identifier(ctx, @5, $5);
	type_check_scalar(ctx, @5, $5, tp);
	ctx->tab->add_fnc(@2, $2, tp, $3);
	ctx->tab->enter(@2, $2);
};

parenthesised_param_list:	LPAR formal_parameters RPAR { $$ = $2; };
parenthesised_param_list:	/* empty parameter list */ { $$ = mlc::create_parameter_list(); };

optional_var:	VAR { $$ = true; };
optional_var:	/* skipped */ { $$ = false; };
formal_parameters:	formal_parameters_item SEMICOLON formal_parameters {
	mlc::parameter_list_ptr p = $1;
	p->append_and_kill($3);
	$$ = p;
};
formal_parameters:	formal_parameters_item { $$ = $1; };

formal_parameters_item:	optional_var identifier_list COLON IDENTIFIER /* type_identifier */ {
	mlc::parameter_list_ptr p = mlc::create_parameter_list();
	for (mlc::ls_id_index id : $2)
	{
		auto tp = type_identifier(ctx, @4, $4);
		if ($1)
			p->append_parameter_by_reference(id, tp);
		else
			p->append_parameter_by_value(id, tp);
	}
	$$ = p;
};


/* TYPES */
type:	IDENTIFIER {
	$$ = type_identifier(ctx, @1, $1);
};
type:	ordinal_type { $$ = $1; };
type:	structured_type { $$ = $1; };

ordinal_type:	ordinal_constant DOTDOT ordinal_constant {
	$$ = ctx->tab->create_range_type($1, $3);
};

// IDENTIFIER (no conflict)
ordinal_type:	IDENTIFIER DOTDOT ordinal_constant {
	$$ = ctx->tab->create_range_type(resolve_integral_const(ctx, @1, $1), $3);
};
ordinal_type:	ordinal_constant DOTDOT IDENTIFIER {
	$$ = ctx->tab->create_range_type($1, resolve_integral_const(ctx, @3, $3));
};
ordinal_type:	IDENTIFIER DOTDOT IDENTIFIER {
	$$ = ctx->tab->create_range_type(
		resolve_integral_const(ctx, @1, $1),
		resolve_integral_const(ctx, @3, $3)
	);
};

structured_type:	ARRAY LSBRA ordinal_type_list RSBRA OF type {
	std::list<mlc::type_pointer> tps = $3;
	mlc::type_pointer array_tp = $6; // "0 dimensional array"
	while (tps.size() > 0) {
		array_tp = ctx->tab->create_array_type(tps.back(), array_tp);
		tps.pop_back();
	}
	$$ = array_tp;
};
structured_type:	RECORD optional_field_list END {
	$$ = ctx->tab->create_record_type($2, @1);
};

ordinal_type_list:	ordinal_type_list_item COMMA ordinal_type_list {
	std::list<mlc::type_pointer> tps = $3;
	tps.push_front($1);
	$$ = tps;
};
ordinal_type_list:	ordinal_type_list_item {
	std::list<mlc::type_pointer> tps = { $1 };
	$$ = tps;
};

ordinal_type_list_item: ordinal_type { $$ = $1; };
ordinal_type_list_item: IDENTIFIER { // pulled out IDENTIFIER
	auto tp = type_identifier(ctx, @1, $1);
	if (tp->cat() != TCAT_RANGE)
		message(DUERR_NOTORDINAL, @1, *$1);
	$$ = tp;
};

optional_field_list:	field_list optional_semicolon { $$ = $1; };
optional_field_list:	/* empty field list */ { $$ = mlc::create_field_list(); };

// left recursion
field_list:	field_list SEMICOLON field_list_item {
	mlc::field_list_ptr fl = $1;
	fl->append_and_kill($3);
	$$ = fl;
};
field_list:	field_list_item { $$ = $1; };

field_list_item:	identifier_list COLON type {
	mlc::field_list_ptr fl = mlc::create_field_list();
	for (mlc::ls_id_index id : $1)
		fl->append_field(id, $3);
	$$ = fl;
};

/* CONSTANTS */
unsigned_constant:	UINT;
unsigned_constant:	REAL;
unsigned_constant:	STRING;

/* ORDINAL CONSTANTS */
ordinal_constant:	OPER_SIGNADD IDENTIFIER {
	mlc::ls_int_index val = resolve_integral_const(ctx, @2, $2);
	if ($1 == mlc::DUTOKGE_OPER_SIGNADD::DUTOKGE_MINUS) // handle minus
		val = ctx->tab->ls_int().add(- *val);
	$$ = val;
};
ordinal_constant:	optional_sign UINT {
	mlc::ls_int_index val = $2;
	if ($1 == mlc::DUTOKGE_OPER_SIGNADD::DUTOKGE_MINUS) // handle minus
		val = ctx->tab->ls_int().add(- *val);
	$$ = val;
};

/* STATEMENT BLOCK */
statement_block:	BEGIN statement_list END;

/* STATEMENT LIST */
statement_list:	statement SEMICOLON statement_list;
statement_list:	statement;

/* STATEMENT */
statement:	label_usage raw_statement;
statement:	raw_statement;
statement:	/* empty statement */;

raw_statement:	closed_statement;
raw_statement:	open_statement;

/* IF THEN ELSE */
open_statement:	IF expression THEN closed_statement;
open_statement:	IF expression THEN open_statement;
open_statement:	IF expression THEN closed_statement ELSE open_statement;

closed_statement:	simple_statement;
closed_statement:	IF expression THEN closed_statement ELSE closed_statement;

/* WHILE CYCLE */
open_statement:		WHILE expression DO open_statement;
closed_statement:	WHILE expression DO closed_statement;

/* FOR CYCLE */
open_statement:		FOR IDENTIFIER /* ordinal type */
			ASSIGN expression /* ordinal type */
			FOR_DIRECTION expression /* ordinal type */
			DO open_statement;

closed_statement:	FOR IDENTIFIER /* ordinal type */
			ASSIGN expression /* ordinal type */
			FOR_DIRECTION expression /* ordinal type */
			DO closed_statement;

/* LABEL USAGE */
label_usage:	UINT COLON;

/* GOTO */
goto_statement:	GOTO UINT;

/* VARIABLE ASSIGNMENT */
var_assignment:	variable ASSIGN expression;
var_assignment:	IDENTIFIER /* var id | function id */ ASSIGN expression;

/* PROCEDURE & FUNCTION INVOCATION*/
func_invoke:	IDENTIFIER p_real_parameters;

p_real_parameters:	LPAR real_parameters RPAR;

real_parameters:	real_param_item COMMA real_parameters;
real_parameters:	real_param_item;
real_param_item: expression;

/* REPEAT CYCLE */
repeat_statement:	REPEAT statement_list UNTIL expression; /* bool */

expression:	simple_expression expr_oper simple_expression; // bool expr
expression:	simple_expression;

expr_oper:	OPER_REL;
expr_oper:	EQ;

/* SIMPLE STATEMENTS */
simple_statement:	IDENTIFIER; // func_invoke (without params)
simple_statement:	label_usage;
simple_statement:	var_assignment;
simple_statement:	func_invoke; // has to be a procedure, not function ???
simple_statement:	goto_statement;
simple_statement:	statement_block;
simple_statement:	repeat_statement;

/* SIMPLE EXPRESSION */

simple_expression:	optional_sign term_list;
term_list: term term_list_separator term_list;
term_list: term;
term_list_separator:	OPER_SIGNADD;
term_list_separator:	OR;

/* FACTOR */
factor:	IDENTIFIER; // unsigned_constant | variable
factor:	unsigned_constant; // IDENTIFIER not defined inside
factor:	variable; // IDENTIFIER not defined inside
factor:	func_invoke; // has to be a function, not procedure
factor:	LPAR expression RPAR;
factor:	NOT factor;

/* TERM */
term:	factor OPER_MUL term;
term:	factor;

/* VARIABLE */
variable:	array_variable;
variable:	IDENTIFIER DOT IDENTIFIER;

array_variable:	array_variable LSBRA ord_expression_list RSBRA;
array_variable:	IDENTIFIER LSBRA ord_expression_list RSBRA;

ord_expression_list:	expression COMMA ord_expression_list;
ord_expression_list:	expression;

/* OPTIONAL SEMICOLON */
optional_semicolon:	SEMICOLON;
optional_semicolon:	/* omitted */;

/* OPTIONAL SIGN (+, -) */
optional_sign:	OPER_SIGNADD { $$ = $1; };
optional_sign:	/* omitted */ { $$ = mlc::DUTOKGE_OPER_SIGNADD::DUTOKGE_PLUS; };


/* IDENTIFIER LIST */
identifier_list:	IDENTIFIER COMMA identifier_list {
	std::list<mlc::ls_id_index> ids = $3;
	ids.push_front($1);
	$$ = ids;
};
identifier_list:	IDENTIFIER {
	std::list<mlc::ls_id_index> ids = { $1 };
	$$ = ids;
};

%%

namespace yy {

	void mlaskal_parser::error(const location_type& l, const std::string& m)
	{
		message(DUERR_SYNTAX, l, m);
	}

}