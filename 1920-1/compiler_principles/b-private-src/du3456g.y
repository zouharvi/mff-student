%language "c++"
%require "3.0.4"
%defines
%define parser_class_name { mlaskal_parser }
%define api.token.constructor
%define api.token.prefix{DUTOK_}
%define api.value.type variant
%define parse.assert
%define parse.error verbose

%locations
%define api.location.type{ unsigned }

%code requires
{
#include "dutables.hpp"
#include "du3456sem.hpp"
#pragma warning (disable:4065)
#define YYLLOC_DEFAULT(res,rhs,N)	 (res = (N)?YYRHSLOC(rhs, 1):YYRHSLOC(rhs, 0))
#define YY_NULL    0
#define YY_NULLPTR 0
}

%param{ mlc::yyscan_t2 yyscanner }
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

}

%token EOF    0    "end of file"

%token PROGRAM                                   /* program */
%token LABEL                                     /* label */
%token CONST                                     /* const */
%token TYPE                                      /* type */
%token VAR                                       /* var */
%token BEGIN                                     /* begin */
%token END                                       /* end */
%token PROCEDURE                                 /* procedure */
%token FUNCTION                                  /* function */
%token ARRAY                                     /* array */
%token OF                                        /* of */
%token GOTO                                      /* goto */
%token IF                                        /* if */
%token THEN                                      /* then */
%token ELSE                                      /* else */
%token WHILE                                     /* while */
%token DO                                        /* do */
%token REPEAT                                    /* repeat */
%token UNTIL                                     /* until */
%token FOR                                       /* for */
%token OR                                        /* or */
%token NOT                                       /* not */
%token RECORD                                    /* record */

/* literals */
%token<mlc::ls_id_index> IDENTIFIER              /* identifier */
%token<mlc::ls_int_index> UINT                   /* unsigned integer */
%token<mlc::ls_real_index> REAL                  /* real number */
%token<mlc::ls_str_index> STRING                 /* string */

/* delimiters */
%token SEMICOLON                                 /* ; */
%token DOT                                       /* . */
%token COMMA                                     /* , */
%token EQ                                        /* = */
%token COLON                                     /* : */
%token LPAR                                      /* ( */
%token RPAR                                      /* ) */
%token DOTDOT                                    /* .. */
%token LSBRA                                     /* [ */
%token RSBRA                                     /* ] */
%token ASSIGN                                    /* := */

/* grouped operators and keywords */
%token<mlc::DUTOKGE_OPER_REL> OPER_REL           /* <, <=, <>, >=, > */
%token<mlc::DUTOKGE_OPER_SIGNADD> OPER_SIGNADD   /* +, - */
%token<mlc::DUTOKGE_OPER_MUL> OPER_MUL           /* *, /, div, mod, and */
%token<mlc::DUTOKGE_FOR_DIRECTION> FOR_DIRECTION /* to, downto */

/* variables */
%type<mlc::ls_id_index> pfHeader
%type<bool> varMaybe
%type<mlc::parameter_list_ptr> params
%type<mlc::parameter_list_ptr> paramsMaybe
%type<std::vector<mlc::ls_id_index>> identifierList

/* types */
%type<mlc::type_pointer> identifierType
%type<mlc::type_pointer> type
%type<mlc::type_pointer> ordType
%type<mlc::ls_int_index> ordConst
%type<mlc::ls_int_index> constantInt
%type<mlc::ls_real_index> constantReal
%type<mlc::ls_str_index> constantString
%type<mlc::ls_id_index> constantIdentifier

/* statements */
%type<mlc::icblock_pointer> mlaskal
%type<mlc::icblock_pointer> block
%type<mlc::icblock_pointer> basicBlock
%type<mlc::icblock_pointer> statement
%type<mlc::icblock_pointer> statementList
%type<mlc::icblock_pointer> stmtA
%type<mlc::icblock_pointer> stmtB

/* expressions */
%type<mlc::exprConst> factor
%type<mlc::exprConst> termMany
%type<mlc::exprConst> term
%type<mlc::exprConst> simpleExpr
%type<mlc::exprConst> expr
%type<mlc::exprConst> constantLiteral
%type<mlc::argsCode> args
%type<mlc::argsCode> argsMaybe
%%

mlaskal: PROGRAM IDENTIFIER SEMICOLON block DOT { ctx->tab->set_main_code($2, $4); };

block: labelBlock constBlock typeBlock varBlock pfBlock BEGIN statementList END { $$ = $7; };
basicBlock: labelBlock constBlock typeBlock varBlock BEGIN statementList END { $$ = $6; };

labelBlock: %empty
          | LABEL labelName SEMICOLON
          ;

labelName: UINT                 { ctx->tab->add_label_entry(@1, $1, ctx->tab->new_label()); }
         | labelName COMMA UINT { ctx->tab->add_label_entry(@3, $3, ctx->tab->new_label()); }
         ;

constBlock: %empty
          | CONST constBlockInner
          ;


constBlockInner:
    IDENTIFIER EQ constantInt SEMICOLON { ctx->tab->add_const_int(@2, $1, $3); }
    | IDENTIFIER EQ constantReal SEMICOLON {  ctx->tab->add_const_real(@2, $1, $3); }
    | IDENTIFIER EQ constantString SEMICOLON { ctx->tab->add_const_str(@2, $1, $3); }
    | IDENTIFIER EQ constantIdentifier SEMICOLON { 
        auto sp = ctx->tab->find_symbol($3);
        if (!sp  || (sp->kind() != SKIND_CONST)) {
            message(DUERR_NOTCONST, @3, * $3);
        }
        if (sp->access_const()->type()->cat() == TCAT_INT) {
            auto val = sp->access_const()->access_int_const()->int_value();
            ctx->tab->add_const_int(@2, $1, val);
        }
        else if (sp->access_const()->type()->cat() == TCAT_REAL) {
            auto val = sp->access_const()->access_real_const()->real_value();
            ctx->tab->add_const_real(@2, $1, val);
        }
        else if (sp->access_const()->type()->cat() == TCAT_STR) {
            auto val = sp->access_const()->access_str_const()->str_value();
            ctx->tab->add_const_str(@2, $1, val);
        }
        else if (sp->access_const()->type()->cat() == TCAT_BOOL) {
            auto val = sp->access_const()->access_bool_const()->bool_value();
            ctx->tab->add_const_bool(@2, $1, val);
        } else {
            message(DUERR_NOTCONST, @3, * $3);
        }
    }
    | constBlockInner IDENTIFIER EQ constantInt SEMICOLON { ctx->tab->add_const_int(@3, $2, $4); }
    | constBlockInner IDENTIFIER EQ constantReal SEMICOLON { ctx->tab->add_const_real(@3, $2, $4); }
    | constBlockInner IDENTIFIER EQ constantString SEMICOLON { ctx->tab->add_const_str(@3, $2, $4); }
    | constBlockInner IDENTIFIER EQ constantIdentifier SEMICOLON {
        auto sp = ctx->tab->find_symbol($4);
        if (!sp  || (sp->kind() != SKIND_CONST)) {
            message(DUERR_NOTCONST, @4, * $4);
        }
        if (sp->access_const()->type()->cat() == TCAT_INT) {
            auto val = sp->access_const()->access_int_const()->int_value();
            ctx->tab->add_const_int(@3, $2, val);
        }
        else if (sp->access_const()->type()->cat() == TCAT_REAL) {
            auto val = sp->access_const()->access_real_const()->real_value();
            ctx->tab->add_const_real(@3, $2, val);
        }
        else if (sp->access_const()->type()->cat() == TCAT_STR) {
            auto val = sp->access_const()->access_str_const()->str_value();
            ctx->tab->add_const_str(@3, $2, val);
        }
        else if (sp->access_const()->type()->cat() == TCAT_BOOL) {
            auto val = sp->access_const()->access_bool_const()->bool_value();
            ctx->tab->add_const_bool(@3, $2, val);
        } else {
            message(DUERR_NOTCONST, @4, * $4);
        }
    }
    ;

constantInt:
    UINT { $$ = $1; }
    | OPER_SIGNADD UINT {
        auto val = $2;
        if ($1 == mlc::DUTOKGE_OPER_SIGNADD::DUTOKGE_MINUS) {
            val = ctx->tab->ls_int().add(- *val);
        }
        $$ = val;
    }
    ;

constantReal:
    REAL { $$ = $1; }
    | OPER_SIGNADD REAL {
        auto val = $2;
        if ($1 == mlc::DUTOKGE_OPER_SIGNADD::DUTOKGE_MINUS) {
            val = ctx->tab->ls_real().add(- *val);
        }
        $$ = val;
    }
    ;

constantString: STRING { $$ = $1; };
constantIdentifier: IDENTIFIER { $$ = $1; }

constantLiteral:
    UINT	{
        auto icblock = mlc::icblock_create();
        icblock->append<ai::LDLITI>($1);
        mlc::exprConst ec;
        ec.code = icblock;
        ec.lastType = TCAT_INT;
        $$ = ec;
    }
    | REAL 	{
        auto icblock = mlc::icblock_create();
        icblock->append<ai::LDLITR>($1);
        mlc::exprConst ec;
        ec.code = icblock;
        ec.lastType = TCAT_REAL;
        $$ = ec;
    }
    | STRING {
        auto icblock = mlc::icblock_create();
        icblock->append<ai::LDLITS>($1);
        mlc::exprConst ec;
        ec.code = icblock;
        ec.lastType = TCAT_STR;
        $$ = ec;
    }
    ;

typeBlock: %empty
	| TYPE typeBlockInner
    ;

typeBlockInner:
    IDENTIFIER EQ type SEMICOLON { ctx->tab->add_type(@2, $1, $3); }
    | typeBlockInner IDENTIFIER EQ type SEMICOLON { ctx->tab->add_type(@2, $2, $4); }
    ;

varBlock: %empty
    | VAR varBlockInner
    ;

varBlockInner:
    identifierList COLON type SEMICOLON {
        for (auto i = 0; i < $1.size(); ++i) {
            ctx->tab->add_var(@2, $1[i], $3);
        }
    }
    | varBlockInner identifierList COLON type SEMICOLON {
        for (auto i = 0; i < $2.size(); ++i) {
			ctx->tab->add_var(@3, $2[i], $4);
		}
    }
    ;

identifierList:
    IDENTIFIER {
        std::vector<mlc::ls_id_index> vec;
        vec.push_back($1);
        $$ = vec;
                }
                    | identifierList COMMA IDENTIFIER {
                $1.push_back($3);
            $$ = $1;
    }
    ;

pfBlock: %empty
    | 	pfHeader SEMICOLON { ctx->tab->enter(@2, $1); }
		basicBlock 	{ ctx->tab->leave(@3); }
		SEMICOLON 	{ ctx->tab->set_subprogram_code($1, $4); }
		pfBlock		
    ;

pfHeader:
    PROCEDURE IDENTIFIER paramsMaybe {
		ctx->tab->add_proc(@1, $2, $3);
		$$ = $2;
	}
    | FUNCTION IDENTIFIER paramsMaybe COLON identifierType {
		ctx->tab->add_fnc(@1, $2, $5, $3);
		$$ = $2;
	}
    ;

paramsMaybe: %empty		{ $$ = mlc::create_parameter_list(); }
    | LPAR params RPAR	{ $$ = $2; }
    ;

params:
    varMaybe identifierList COLON identifierType {
        auto params = mlc::create_parameter_list();
        for (size_t i = 0; i < $2.size(); ++i) {
            if ($1) {
                params->append_parameter_by_reference($2[i], $4);
            } else {
                params->append_parameter_by_value($2[i], $4);
            }
        }
        $$ = params;
        }
    | params SEMICOLON varMaybe identifierList COLON identifierType {
      	auto params = mlc::create_parameter_list();
        for (size_t i = 0; i < $4.size(); ++i) {
            if ($3) {
                params->append_parameter_by_reference($4[i], $6);
            } else {
                params->append_parameter_by_value($4[i], $6);
            }
        }
        $1->append_and_kill(params);
        $$ = $1;
    }
    ;

varMaybe: %empty 	{ $$ = false; }
    | VAR 	 	{ $$ = true; }
    ;

identifierType:
    IDENTIFIER {
        auto symbolptr = ctx->tab->find_symbol($1);

        if (!symbolptr || (symbolptr->kind() != SKIND_TYPE)) {
            message(DUERR_NOTTYPE, @1, * $1);
        } else {
            auto t = symbolptr->access_type();
            $$ = t->type();
        }
    }
    ;

type: identifierType	{ $$ = $1; }
    | ordType           { $$ = $1; }
    ;

ordType: ordConst DOTDOT ordConst   { $$ = ctx->tab->create_range_type($1, $3); };

statement:
    stmtA { $$ = $1; } 
    | stmtB { $$ = $1; };

statementList:
    statement 			 { $$ = $1; }
    | statementList SEMICOLON statement { $$ = mlc::icblock_merge_and_kill($1, $3); }
    ;

stmtA:
    GOTO UINT    {
        auto icblock = mlc::icblock_create();

        auto label = ctx->tab->find_label($2);
        if (!!label) {
            icblock->append_with_target<ai::JMP>(label->label());
            label->goto_found(@1);
        } else {
            message(DUERR_NOTLABEL, @2, * $2);
        }

        $$ = icblock;
    }
    | IF expr THEN stmtA ELSE stmtA    {
        auto label_then = ctx->tab->new_label();
        auto label_else = ctx->tab->new_label();

        auto icblock = $2.code;

        icblock->append_with_target<ai::JF>(label_then);
        icblock = mlc::icblock_merge_and_kill(icblock, $4);

        icblock->append_with_target<ai::JMP>(label_else);
        icblock->add_label(label_then);

        icblock = mlc::icblock_merge_and_kill(icblock, $6);
        icblock->add_label(label_else);

        $$ = icblock;
    }
    | WHILE expr DO stmtA      { 
        auto icblock = mlc::icblock_create();

        auto label_loop = ctx->tab->new_label();
        auto label_cond = ctx->tab->new_label();
        
        // JMP [label_cond] 
        icblock->append_with_target<ai::JMP>(label_cond);
        // [label_loop]:
        icblock->add_label(label_loop);
        // <stmt>
        icblock = mlc::icblock_merge_and_kill(icblock, $4);

        // [label_cond]:
        icblock->add_label(label_cond);
        // <expr>
        icblock = mlc::icblock_merge_and_kill(icblock, $2.code);
        // JT [label_loop]
        icblock->append_with_target<ai::JT>(label_loop);
        
        $$ = icblock;
    }
    | REPEAT statementList UNTIL expr  { 
        auto icblock = mlc::icblock_create();

        auto label_loop = ctx->tab->new_label();
        
        // [label_loop]:
        icblock->add_label(label_loop);
        // <stmtList>
        icblock = mlc::icblock_merge_and_kill(icblock, $2);

        // <expr>
        icblock = mlc::icblock_merge_and_kill(icblock, $4.code);
        // JF [label_loop]
        icblock->append_with_target<ai::JF>(label_loop);
        
        $$ = icblock;
    }
    | FOR IDENTIFIER ASSIGN expr FOR_DIRECTION expr DO stmtA   { 
        auto sp = ctx->tab->find_symbol($2);

        if (!sp || (sp->kind() != SKIND_GLOBAL_VARIABLE 
                    && sp->kind() != SKIND_LOCAL_VARIABLE
                    && sp->kind() != SKIND_PARAMETER_BY_REFERENCE)) {
            message(DUERR_FORNOTLOCAL, @2, * $2);
        } else if (sp->access_typed()->type()->cat() != TCAT_INT) {
            message(DUERR_FORNOTINTEGER, @2, * $2);
        } else {
            auto tsp = sp->access_typed();
            auto icblock = mlc::icblock_create();

            auto label_loop = ctx->tab->new_label();
            auto label_cond = ctx->tab->new_label();

            bool increasing;
            if ($5 == mlc::DUTOKGE_FOR_DIRECTION::DUTOKGE_TO) {
                increasing = true;
            } else if ($5 == mlc::DUTOKGE_FOR_DIRECTION::DUTOKGE_DOWNTO) {
                increasing = false;
            }

            // assign <id> <initialExpr>
            icblock = mlc::icblock_merge_and_kill(icblock, $4.code);
            // store <id>
            mlc::store_variable(icblock, tsp);
                            
            // JMP [label_cond]
            icblock->append_with_target<ai::JMP>(label_cond);

            // [label_loop]:
            icblock->add_label(label_loop);

            // <stmt>
            icblock = mlc::icblock_merge_and_kill(icblock, $8);

            // load <id>
            mlc::load_variable(icblock, tsp);

            // load_const 1
            icblock->append<ai::LDLITI>(ctx->tab->one());

            // inc/dec
            if (increasing) {
                icblock->append<ai::ADDI>(); 
            } else {
                icblock->append<ai::SUBI>();
            }

            // store <id>
            mlc::store_variable(icblock, tsp);

            // [label_cond]:
            icblock->add_label(label_cond);

            // <endExpr>
            icblock = mlc::icblock_merge_and_kill(icblock, $6.code);

            // load <id>
            mlc::load_variable(icblock, tsp);

            // GEI / LEI 
            if (increasing) {
                icblock->append<ai::GEI>();
            } else {
                icblock->append<ai::LEI>();
            }

            // JF [label_loop]
            icblock->append_with_target<ai::JT>(label_loop);
            
            $$ = icblock;
        }
    }
    | IDENTIFIER argsMaybe	{ // fn call
        auto icblock = mlc::icblock_create();
        auto sp = ctx->tab->find_symbol($1);
        if (!sp || (sp->kind() != SKIND_PROCEDURE)) {
            message(DUERR_NOTPROC, @1, * $1);
        } else {
            auto subprog = sp->access_subprogram();
            auto params = subprog->parameters();
            for (int i = 0; i < $2.argTypes.size(); i++) {
                auto argType = $2.argTypes[i];
                auto argCode = $2.argCodes[i];
                auto par = params->begin() + i;
                if (par->partype == parameter_mode::PMODE_BY_VALUE) {
                    icblock = mlc::icblock_merge_and_kill(icblock, argCode);
                } else if (par->partype == parameter_mode::PMODE_BY_REFERENCE) {
                    auto psp = ctx->tab->find_symbol(par->idx);
                    auto tsp = psp->access_typed();

                    if (psp->kind() == SKIND_PARAMETER_BY_REFERENCE) {
                        if (argCode->size() != 2) {
                            message(DUERR_NOTPARAMVAR, @1);

                            icblock = mlc::icblock_merge_and_kill(icblock, argCode);
                        } else {
                            icblock->append<ai::LLDP>(tsp->access_parameter_by_reference()->address());
                        }
                    } else {
                        if (argCode->size() != 1) {
                            message(DUERR_NOTPARAMVAR, @1);

                            icblock = mlc::icblock_merge_and_kill(icblock, argCode);
                        } else {
                            ref_variable(icblock, tsp);
                        }
                    }
                    
                } else {
                    assert(false);
                }
            }
            icblock->append<ai::CALL>(subprog->code());
            if ($2.argTypes.size() != params->size()) {
                message(DUERR_PARNUM, @1, * $1);
            } else {
                for (int i = $2.argTypes.size() - 1; i >= 0; i--) {
                    auto argType = $2.argTypes[i];
                    auto par = params->begin() + i;
                    if (par->partype == parameter_mode::PMODE_BY_VALUE) {
                        switch (argType) {
                            case TCAT_BOOL:
                                    icblock->append<ai::DTORB>();
                                    break;
                            case TCAT_INT:
                                    icblock->append<ai::DTORI>();
                                    break;
                            case TCAT_REAL:
                                    icblock->append<ai::DTORR>();
                                    break;
                            case TCAT_STR:
                                    icblock->append<ai::DTORS>();
                                    break;
                        }
                    } else if (par->partype == parameter_mode::PMODE_BY_REFERENCE) {
                        icblock->append<ai::DTORP>();
                    }
                }
            }
        }
        $$ = icblock;
    }
    | UINT COLON stmtA     {  // GOTO
        auto icblock = mlc::icblock_create();
        auto label = ctx->tab->find_label($1);
        if (!!label) {
            icblock->add_label(label->label());
            label->label_found(@1);
        } else {
            message(DUERR_NOTLABEL, @1, * $1);
        }

        $$ = mlc::icblock_merge_and_kill(icblock, $3); 
    }
    | IDENTIFIER ASSIGN expr     {
        auto icblock = mlc::icblock_create();
        auto sp = ctx->tab->find_symbol($1);
        if (!sp || sp->kind() == SKIND_UNDEF
                || sp->kind() == SKIND_PROCEDURE
                || sp->kind() == SKIND_TYPE
                || sp->kind() == SKIND_CONST) {
                    message(DUERR_NOTVAR, @1, * $1);
        }
        if (sp->kind() == SKIND_FUNCTION) {
            auto fnName = ctx->tab->my_function_name();
            if (!ctx->tab->nested() || $1 != fnName) {
                message(DUERR_NOTVAR, @1, * $1);
            } else {
                icblock = mlc::icblock_merge_and_kill(icblock, $3.code);
                auto fnType = ctx->tab->find_symbol(fnName)->access_typed()->type()->cat();
                auto retAddress = ctx->tab->my_return_address();
                switch (fnType) {
                    case TCAT_BOOL:
                        icblock->append<ai::LSTB>(retAddress);
                        break;
                    case TCAT_INT:
                        icblock->append<ai::LSTI>(retAddress);
                        break;
                    case TCAT_REAL:
                        icblock->append<ai::LSTR>(retAddress);
                        break;
                    case TCAT_STR:
                        icblock->append<ai::LSTS>(retAddress);
                        break;

                }
            }
        } else if (sp->kind() == SKIND_GLOBAL_VARIABLE 
                    || sp->kind() == SKIND_LOCAL_VARIABLE
                    || sp->kind() == SKIND_PARAMETER_BY_REFERENCE) { // GLOBAL, LOCAL, PARAM
            assert($3.code != nullptr);
            auto type = sp->access_typed()->type()->cat();
            icblock = mlc::icblock_merge_and_kill(icblock, $3.code);

            switch (type) {
                case TCAT_INT:
                    if ($3.lastType == TCAT_REAL) {
                        icblock->append<ai::CVRTRI>();
                        message(DUERR_CONVERSION, @3);
                    }
                    break;
                case TCAT_REAL:
                    if ($3.lastType == TCAT_INT) {
                        icblock->append<ai::CVRTIR>();
                    }
                    break;
            }

            if (sp->kind() == SKIND_PARAMETER_BY_REFERENCE) {
                icblock->append<ai::LLDP>(sp->access_typed()->access_parameter_by_reference()->address());
                switch (sp->access_typed()->type()->cat()) {
                        case TCAT_BOOL:
                            icblock->append<ai::XSTB>();
                            break;
                        case TCAT_INT:
                            icblock->append<ai::XSTI>();
                            break;
                        case TCAT_REAL:
                            icblock->append<ai::XSTR>();
                            break;
                        case TCAT_STR:
                            icblock->append<ai::XSTS>();
                            break;
                }
            } else {
                mlc::store_variable(icblock, sp->access_variable());
            }
        }
        
        $$ = icblock;
    }
    | BEGIN statementList END  { $$ = $2; }
    | %empty { $$ = mlc::icblock_create(); }
    ;

stmtB:
    IF expr THEN statement   { 
        auto label_then = ctx->tab->new_label();

        auto icblock = $2.code;

        icblock->append_with_target<ai::JF>(label_then);
        icblock = mlc::icblock_merge_and_kill(icblock, $4);
        icblock->add_label(label_then);

        $$ = icblock;
    }
    | WHILE expr DO stmtB      {
        auto icblock = mlc::icblock_create();
        auto label_loop = ctx->tab->new_label();
        auto label_cond = ctx->tab->new_label();
        
        // JMP [label_cond] 
        icblock->append_with_target<ai::JMP>(label_cond);
        // [label_loop]:
        icblock->add_label(label_loop);
        // <stmt>
        icblock = mlc::icblock_merge_and_kill(icblock, $4);

        // [label_cond]:
        icblock->add_label(label_cond);
        // <expr>
        icblock = mlc::icblock_merge_and_kill(icblock, $2.code);
        // JT [label_loop]
        icblock->append_with_target<ai::JT>(label_loop);
        
        $$ = icblock;
    }
    | IF expr THEN stmtA ELSE stmtB    {
        auto label_then = ctx->tab->new_label();
        auto label_else = ctx->tab->new_label();
        auto icblock = $2.code;

        icblock->append_with_target<ai::JF>(label_then);
        icblock = mlc::icblock_merge_and_kill(icblock, $4);

        icblock->append_with_target<ai::JMP>(label_else);
        icblock->add_label(label_then);

        icblock = mlc::icblock_merge_and_kill(icblock, $6);
        icblock->add_label(label_else);

        $$ = icblock;
    }
    | FOR IDENTIFIER ASSIGN expr FOR_DIRECTION expr DO stmtB { $$ = mlc::icblock_create(); }
    | UINT COLON stmtB     { // GOTO
        auto icblock = mlc::icblock_create();
        auto label = ctx->tab->find_label($1);
        if (!!label) {
            icblock->add_label(label->label());
            label->label_found(@1);
        } else {
            message(DUERR_NOTLABEL, @1, * $1);
        }

        $$ = mlc::icblock_merge_and_kill(icblock, $3); 
    }
    ;

argsMaybe: %empty		{
        mlc::argsCode ac;
        ac.code = mlc::icblock_create();
                            ac.argCodes = std::vector<mlc::icblock_pointer>();
        ac.argTypes = std::vector<mlc::type_category>();
        $$ = ac;
    }
    | LPAR args RPAR	{ $$ = $2; }
    ;

args:
    expr {
        mlc::argsCode ac;
        ac.code = $1.code;
                            ac.argCodes = std::vector<mlc::icblock_pointer>{ $1.code };
        ac.argTypes = std::vector<mlc::type_category>{ $1.lastType };
        $$ = ac;
    }
    | args COMMA expr		{
        mlc::argsCode ac;
        ac.code = mlc::icblock_merge_and_kill($1.code, $3.code);

        $1.argCodes.push_back($3.code);
        ac.argCodes = $1.argCodes;

        $1.argTypes.push_back($3.lastType);
        ac.argTypes = $1.argTypes;

        $$ = ac;
    }
    ;

expr: simpleExpr			{ $$ = $1; }
    | simpleExpr OPER_REL simpleExpr    {
		mlc::exprConst ec;
        if ($1.lastType == TCAT_BOOL && $3.lastType == TCAT_BOOL) {
            ec.code = mlc::icblock_merge_and_kill($1.code, $3.code);
            if ($2 == mlc::DUTOKGE_OPER_REL::DUTOKGE_LT) {
                ec.code->append<ai::LTB>();
            } else if ($2 == mlc::DUTOKGE_OPER_REL::DUTOKGE_LE) {
                ec.code->append<ai::LEB>();
            } else if ($2 == mlc::DUTOKGE_OPER_REL::DUTOKGE_NE) {
                ec.code->append<ai::NEB>();
            } else if ($2 == mlc::DUTOKGE_OPER_REL::DUTOKGE_GE) {
                ec.code->append<ai::GEB>();
            } else if ($2 == mlc::DUTOKGE_OPER_REL::DUTOKGE_GT) {
                ec.code->append<ai::GTB>();
            }
            ec.lastType = TCAT_BOOL;
        } else if ($1.lastType == TCAT_STR && $3.lastType == TCAT_STR) {
            ec.code = mlc::icblock_merge_and_kill($1.code, $3.code);
            if ($2 == mlc::DUTOKGE_OPER_REL::DUTOKGE_LT) {
                ec.code->append<ai::LTS>();
            } else if ($2 == mlc::DUTOKGE_OPER_REL::DUTOKGE_LE) {
                ec.code->append<ai::LES>();
            } else if ($2 == mlc::DUTOKGE_OPER_REL::DUTOKGE_NE) {
                ec.code->append<ai::NES>();
            } else if ($2 == mlc::DUTOKGE_OPER_REL::DUTOKGE_GE) {
                ec.code->append<ai::GES>();
            } else if ($2 == mlc::DUTOKGE_OPER_REL::DUTOKGE_GT) {
                ec.code->append<ai::GTS>();
            }
            ec.lastType = TCAT_BOOL;
        } else if ($1.lastType == TCAT_INT && $3.lastType == TCAT_INT) {
            ec.code = mlc::icblock_merge_and_kill($1.code, $3.code);
            if ($2 == mlc::DUTOKGE_OPER_REL::DUTOKGE_LT) {
                ec.code->append<ai::LTI>();
            } else if ($2 == mlc::DUTOKGE_OPER_REL::DUTOKGE_LE) {
                ec.code->append<ai::LEI>();
            } else if ($2 == mlc::DUTOKGE_OPER_REL::DUTOKGE_NE) {
                ec.code->append<ai::NEI>();
            } else if ($2 == mlc::DUTOKGE_OPER_REL::DUTOKGE_GE) {
                ec.code->append<ai::GEI>();
            } else if ($2 == mlc::DUTOKGE_OPER_REL::DUTOKGE_GT) {
                ec.code->append<ai::GTI>();
            }
            ec.lastType = TCAT_BOOL;
        } else if (($1.lastType == TCAT_INT || $1.lastType == TCAT_REAL) &&
                    ($3.lastType == TCAT_INT || $3.lastType == TCAT_REAL)) {
            if ($1.lastType == TCAT_INT) {
                $1.code->append<ai::CVRTIR>();
            }
            if ($3.lastType == TCAT_INT) {
                $3.code->append<ai::CVRTIR>();
            }

            ec.code = mlc::icblock_merge_and_kill($1.code, $3.code);        
            if ($2 == mlc::DUTOKGE_OPER_REL::DUTOKGE_LT) {
                ec.code->append<ai::LTR>();
            } else if ($2 == mlc::DUTOKGE_OPER_REL::DUTOKGE_LE) {
                ec.code->append<ai::LER>();
            } else if ($2 == mlc::DUTOKGE_OPER_REL::DUTOKGE_NE) {
                ec.code->append<ai::NER>();
            } else if ($2 == mlc::DUTOKGE_OPER_REL::DUTOKGE_GE) {
                ec.code->append<ai::GER>();
            } else if ($2 == mlc::DUTOKGE_OPER_REL::DUTOKGE_GT) {
                ec.code->append<ai::GTR>();
            }
            ec.lastType = TCAT_BOOL;
        }
        
        $$ = ec;
    }
    | simpleExpr EQ simpleExpr          {
		mlc::exprConst ec;
        if ($1.lastType == TCAT_BOOL && $3.lastType == TCAT_BOOL) {
            ec.code = mlc::icblock_merge_and_kill($1.code, $3.code);
            ec.code->append<ai::EQB>();
            ec.lastType = TCAT_BOOL;
        } else if ($1.lastType == TCAT_STR && $3.lastType == TCAT_STR) {
            ec.code = mlc::icblock_merge_and_kill($1.code, $3.code);
            ec.code->append<ai::EQS>();
            ec.lastType = TCAT_BOOL;
        } else if ($1.lastType == TCAT_INT && $3.lastType == TCAT_INT) {
            ec.code = mlc::icblock_merge_and_kill($1.code, $3.code);
            ec.code->append<ai::EQI>();
            ec.lastType = TCAT_BOOL;
        } else if (($1.lastType == TCAT_INT || $1.lastType == TCAT_REAL) &&
                    ($3.lastType == TCAT_INT || $3.lastType == TCAT_REAL)) {
            if ($1.lastType == TCAT_INT) {
                $1.code->append<ai::CVRTIR>();
            }
            if ($3.lastType == TCAT_INT) {
                $3.code->append<ai::CVRTIR>();
            }

            ec.code = mlc::icblock_merge_and_kill($1.code, $3.code);        
            ec.code->append<ai::EQR>();
            ec.lastType = TCAT_BOOL;
        }
        
        $$ = ec;
    } 
    ;

simpleExpr:
    termMany			{ $$ = $1; }
    | OPER_SIGNADD termMany	{
		if ($1 == mlc::DUTOKGE_OPER_SIGNADD::DUTOKGE_MINUS) {
			switch ($2.lastType) {
				case TCAT_INT:
					$2.code->append<ai::MINUSI>();
					break;
				case TCAT_REAL:
					$2.code->append<ai::MINUSR>();
					break;
			}
		}
		$$ = $2;
    }
    ;

termMany:
    termMany OPER_SIGNADD term	{
		mlc::exprConst ec;
                assert($1.code != nullptr && $3.code != nullptr);
		if ($1.lastType == TCAT_STR && $3.lastType == TCAT_STR) {
			ec.code = mlc::icblock_merge_and_kill($1.code, $3.code);
			ec.code->append<ai::ADDS>();
			ec.lastType = TCAT_STR;
		} else if ($1.lastType == TCAT_INT && $3.lastType == TCAT_INT) {
			if ($2 == mlc::DUTOKGE_OPER_SIGNADD::DUTOKGE_PLUS) {
				ec.code = mlc::icblock_merge_and_kill($1.code, $3.code);
				ec.code->append<ai::ADDI>();
				ec.lastType = TCAT_INT;
			} else /* minus */ {
				ec.code = mlc::icblock_merge_and_kill($1.code, $3.code);
				ec.code->append<ai::SUBI>();
				ec.lastType = TCAT_INT;
			}
		} else if ($1.lastType == TCAT_INT && $3.lastType == TCAT_REAL) {
			if ($2 == mlc::DUTOKGE_OPER_SIGNADD::DUTOKGE_PLUS) {
				$1.code->append<ai::CVRTIR>();
				ec.code = mlc::icblock_merge_and_kill($1.code, $3.code);
				ec.code->append<ai::ADDR>();
				ec.lastType = TCAT_REAL;
			} else /* minus */ {
				$1.code->append<ai::CVRTIR>();
				ec.code = mlc::icblock_merge_and_kill($1.code, $3.code);
				ec.code->append<ai::SUBR>();
				ec.lastType = TCAT_REAL;
			}
		} else if ($1.lastType == TCAT_REAL && $3.lastType == TCAT_INT) {
			if ($2 == mlc::DUTOKGE_OPER_SIGNADD::DUTOKGE_PLUS) {
				ec.code = mlc::icblock_merge_and_kill($1.code, $3.code);
				ec.code->append<ai::CVRTIR>();
				ec.code->append<ai::ADDR>();
				ec.lastType = TCAT_REAL;
			} else /* minus */ {
				ec.code = mlc::icblock_merge_and_kill($1.code, $3.code);
				ec.code->append<ai::CVRTIR>();
				ec.code->append<ai::SUBR>();
				ec.lastType = TCAT_REAL;
			}
		} else if ($1.lastType == TCAT_REAL && $3.lastType == TCAT_REAL) {
			if ($2 == mlc::DUTOKGE_OPER_SIGNADD::DUTOKGE_PLUS) {
				ec.code = mlc::icblock_merge_and_kill($1.code, $3.code);
				ec.code->append<ai::ADDR>();
				ec.lastType = TCAT_REAL;
			} else /* minus */ {
				ec.code = mlc::icblock_merge_and_kill($1.code, $3.code);
				ec.code->append<ai::SUBR>();
				ec.lastType = TCAT_REAL;
			}
		}
                if (ec.code == nullptr) {
                    std::cerr << $1.lastType << ", " << $3.lastType << std::endl;
                }
                assert(ec.code != nullptr);
		$$ = ec;
    }
    | termMany OR term		{
        mlc::exprConst ec;
        if ($1.lastType == TCAT_BOOL && $3.lastType == TCAT_BOOL) {
            ec.code = mlc::icblock_merge_and_kill($1.code, $3.code);
            ec.code->append<ai::OR>();
            ec.lastType = TCAT_BOOL;
        }
        $$ = ec;
    }
    | term				{ $$ = $1; }
    ;

term: factor			{ $$ = $1; }
    | factor OPER_MUL term	{
        mlc::exprConst ec;
            if ($1.lastType == TCAT_BOOL && $3.lastType == TCAT_BOOL) {
                ec.code = mlc::icblock_merge_and_kill($1.code, $3.code);
                if ($2 == mlc::DUTOKGE_OPER_MUL::DUTOKGE_AND) {
                    ec.code->append<ai::AND>();
                }
                ec.lastType = TCAT_BOOL;
            } else if ($1.lastType == TCAT_INT && $3.lastType == TCAT_INT) {
        if ($2 == mlc::DUTOKGE_OPER_MUL::DUTOKGE_ASTERISK) {
            ec.code = mlc::icblock_merge_and_kill($1.code, $3.code);
            ec.code->append<ai::MULI>();
            ec.lastType = TCAT_INT;
        } else if ($2 == mlc::DUTOKGE_OPER_MUL::DUTOKGE_SOLIDUS) {
            $1.code->append<ai::CVRTIR>();
            ec.code = mlc::icblock_merge_and_kill($1.code, $3.code);
            ec.code->append<ai::CVRTIR>();
            ec.code->append<ai::DIVR>();
            ec.lastType = TCAT_REAL;
        } else if ($2 == mlc::DUTOKGE_OPER_MUL::DUTOKGE_DIV) {
            ec.code = mlc::icblock_merge_and_kill($1.code, $3.code);
            ec.code->append<ai::DIVI>();
            ec.lastType = TCAT_INT;
        } else if ($2 == mlc::DUTOKGE_OPER_MUL::DUTOKGE_MOD) {
            ec.code = mlc::icblock_merge_and_kill($1.code, $3.code);
            ec.code->append<ai::MODI>();
            ec.lastType = TCAT_INT;
        }
        } else if ($1.lastType == TCAT_INT && $3.lastType == TCAT_REAL) {
            if ($2 == mlc::DUTOKGE_OPER_MUL::DUTOKGE_ASTERISK) {
                $1.code->append<ai::CVRTIR>();
                ec.code = mlc::icblock_merge_and_kill($1.code, $3.code);
                ec.code->append<ai::MULR>();
                ec.lastType = TCAT_REAL;
            } else if ($2 == mlc::DUTOKGE_OPER_MUL::DUTOKGE_SOLIDUS) {
                $1.code->append<ai::CVRTIR>();
                ec.code = mlc::icblock_merge_and_kill($1.code, $3.code);
                ec.code->append<ai::DIVR>();
                ec.lastType = TCAT_REAL;
                }
        } else if ($1.lastType == TCAT_REAL && $3.lastType == TCAT_INT) {
            if ($2 == mlc::DUTOKGE_OPER_MUL::DUTOKGE_ASTERISK) {
                ec.code = mlc::icblock_merge_and_kill($1.code, $3.code);
                $1.code->append<ai::CVRTIR>();
                ec.code->append<ai::MULR>();
                ec.lastType = TCAT_REAL;
            } else if ($2 == mlc::DUTOKGE_OPER_MUL::DUTOKGE_SOLIDUS) {
                ec.code = mlc::icblock_merge_and_kill($1.code, $3.code);
                $1.code->append<ai::CVRTIR>();
                ec.code->append<ai::DIVR>();
                ec.lastType = TCAT_REAL;
                }
        } else if ($1.lastType == TCAT_REAL && $3.lastType == TCAT_REAL) {
            if ($2 == mlc::DUTOKGE_OPER_MUL::DUTOKGE_ASTERISK) {
                ec.code = mlc::icblock_merge_and_kill($1.code, $3.code);
                ec.code->append<ai::MULR>();
                ec.lastType = TCAT_REAL;
            } else if ($2 == mlc::DUTOKGE_OPER_MUL::DUTOKGE_SOLIDUS) {
                ec.code = mlc::icblock_merge_and_kill($1.code, $3.code);
                ec.code->append<ai::DIVR>();
                ec.lastType = TCAT_REAL;
            }
        }
        $$ = ec;
    }
    ;

factor: constantLiteral		{ $$ = $1; }
    | IDENTIFIER argsMaybe /* identifier OR identifier(args) */
    {
        mlc::exprConst ec;
        auto icblock = mlc::icblock_create();
        if ($2.argTypes.empty()) { // no arguments given 
            auto sp = ctx->tab->find_symbol($1);
            if (!sp || sp->kind() == SKIND_UNDEF
                    || sp->kind() == SKIND_PROCEDURE
                    || sp->kind() == SKIND_TYPE) {
                        message(DUERR_NOTVAR, @1, * $1);
            } else if (sp->kind() == SKIND_PARAMETER_BY_REFERENCE) {
                icblock->append<ai::LLDP>(sp->access_typed()->access_parameter_by_reference()->address());
                auto type = sp->access_typed()->type()->cat();
                switch (type) {
                    case TCAT_BOOL:
                        icblock->append<ai::XLDB>();
                        break;
                    case TCAT_INT:
                        icblock->append<ai::XLDI>();
                        break;
                    case TCAT_REAL:
                        icblock->append<ai::XLDR>();
                        break;
                    case TCAT_STR:
                        icblock->append<ai::XLDS>();
                        break;
                }
                ec.lastType = type;
            } else if (sp->kind() == SKIND_CONST) {
                auto type = sp->access_const()->type()->cat();
                switch (type) {
                    case TCAT_BOOL: {
                        auto val = sp->access_const()->access_bool_const()->bool_value();
                        icblock->append<ai::LDLITB>(val);
                        break;
                    }
                    case TCAT_INT: {
                        auto val = sp->access_const()->access_int_const()->int_value();
                        icblock->append<ai::LDLITI>(val);
                        break;
                    }
                    case TCAT_REAL: {
                        auto val = sp->access_const()->access_real_const()->real_value();
                        icblock->append<ai::LDLITR>(val);
                        break;
                    }
                    case TCAT_STR: {
                        auto val = sp->access_const()->access_str_const()->str_value();
                        icblock->append<ai::LDLITS>(val);
                        break;
                    }
                }
                ec.lastType = type;
            } else if (sp->kind() == SKIND_FUNCTION) {
                auto subprog = sp->access_subprogram();
                auto type = sp->access_function()->type()->cat();
                switch (type) {
                    case TCAT_BOOL:
                        icblock->append<ai::INITB>();
                        break;
                    case TCAT_INT:
                        icblock->append<ai::INITI>();
                        break;
                    case TCAT_REAL:
                        icblock->append<ai::INITR>();
                        break;
                    case TCAT_STR:
                        icblock->append<ai::INITS>();
                        break;
                }
                icblock->append<ai::CALL>(subprog->code());
                ec.lastType = type;
            } else {
                auto tsp = sp->access_typed();
                mlc::load_variable(icblock, tsp);

                auto type = tsp->type()->cat();
                ec.lastType = type;
            }
        } else {
            auto sp = ctx->tab->find_symbol($1);
            if (!sp || (sp->kind() != SKIND_FUNCTION)) {
                    message(DUERR_NOTFNC, @1, * $1);
            } else {
                auto subprog = sp->access_subprogram();
                auto fnType = sp->access_function()->type()->cat();
                switch (fnType) {
                    case TCAT_BOOL:
                            icblock->append<ai::INITB>();
                            break;
                    case TCAT_INT:
                            icblock->append<ai::INITI>();
                            break;
                    case TCAT_REAL:
                            icblock->append<ai::INITR>();
                            break;
                    case TCAT_STR:
                            icblock->append<ai::INITS>();
                            break;
                }
                auto params = subprog->parameters();
                for (int i = 0; i < $2.argTypes.size(); i++) {
                    auto argType = $2.argTypes[i];
                    auto argCode = $2.argCodes[i];
                    auto par = params->begin() + i;
                    if (par->partype == parameter_mode::PMODE_BY_VALUE) {
                        icblock = mlc::icblock_merge_and_kill(icblock, argCode);
                    } else if (par->partype == parameter_mode::PMODE_BY_REFERENCE) {
                        auto psp = ctx->tab->find_symbol(par->idx);
                        auto tsp = psp->access_typed();

                            if (psp->kind() == SKIND_PARAMETER_BY_REFERENCE) {
                                if (argCode->size() != 2) {
                                    message(DUERR_NOTPARAMVAR, @1);

                                    icblock = mlc::icblock_merge_and_kill(icblock, argCode);
                                } else {
                                    icblock->append<ai::LLDP>(tsp->access_parameter_by_reference()->address());
                                }
                            } else {
                                if (argCode->size() != 1) {
                                    message(DUERR_NOTPARAMVAR, @1);

                                    icblock = mlc::icblock_merge_and_kill(icblock, argCode);
                                } else {
                                    ref_variable(icblock, tsp);
                                }
                            }
                    } else {
                        assert(false);
                    }
                }
                //icblock = mlc::icblock_merge_and_kill(icblock, $2.code);
                icblock->append<ai::CALL>(subprog->code());

                if ($2.argTypes.size() != params->size()) {
                    message(DUERR_PARNUM, @1, * $1);
                } else {
                    for (int i = $2.argTypes.size() - 1; i >= 0; i--) {
                        auto argType = $2.argTypes[i];
                        auto par = params->begin() + i;
                        if (par->partype == parameter_mode::PMODE_BY_VALUE) {
                                switch (argType) {
                                    case TCAT_BOOL:
                                            icblock->append<ai::DTORB>();
                                            break;
                                    case TCAT_INT:
                                            icblock->append<ai::DTORI>();
                                            break;
                                    case TCAT_REAL:
                                            icblock->append<ai::DTORR>();
                                            break;
                                    case TCAT_STR:
                                            icblock->append<ai::DTORS>();
                                            break;
                                }
                        } else if (par->partype == parameter_mode::PMODE_BY_REFERENCE) {
                            icblock->append<ai::DTORP>();
                        }
                    }
                }
                ec.lastType = fnType;
            }
        }	
        ec.code = icblock;
        $$ = ec;
    }
    | LPAR expr RPAR		{ $$ = $2; }
    | NOT factor            {
        mlc::exprConst ec;
            if ($2.lastType == TCAT_BOOL) {
                ec.code = $2.code;
                ec.code->append<ai::OR>();
                ec.lastType = TCAT_BOOL;
            }
            $$ = ec;
    }
    ;

ordConst:
    OPER_SIGNADD IDENTIFIER {
        auto sp = ctx->tab->find_symbol($2);
        if (!sp || (sp->kind() != SKIND_CONST)) {
            message(DUERR_NOTCONST, @2, * $2);
        }
        if ( sp->access_const()->type()->cat() == TCAT_INT ) {
            auto val = sp->access_const()->access_int_const()->int_value();
            if ($1 == mlc::DUTOKGE_OPER_SIGNADD::DUTOKGE_MINUS) {
                $$ = ctx->tab->ls_int().add(- *val);
            } else {
                $$ = val;
            }
        } else {
            message(DUERR_NOTINTEGRAL, @2, * $2);
        }
    }
	| constantInt { $$ = $1; }
    | IDENTIFIER {
        auto sp = ctx->tab->find_symbol($1);
        if (!sp || (sp->kind() != SKIND_CONST)) {
            message(DUERR_NOTCONST, @1, * $1);
        }
        if ( sp->access_const()->type()->cat() == TCAT_INT ) {
            auto val = sp->access_const()->access_int_const()->int_value();
            $$ = val;
        } else {
            message(DUERR_NOTINTEGRAL, @1, * $1);
        }
    }
    ;
%%

namespace yy {
	void mlaskal_parser::error(const location_type& l, const std::string& m)
	{
		message(DUERR_SYNTAX, l, m);
	}
}