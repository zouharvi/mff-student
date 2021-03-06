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
    #define YYLLOC_DEFAULT(res,rhs,N)    (res = (N)?YYRHSLOC(rhs, 1):YYRHSLOC(rhs, 0))
    #define YY_NULL    0
    #define YY_NULLPTR 0
}

%param{ mlc::yyscan_t2 yyscanner }
%param{ mlc::MlaskalCtx* ctx }

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

/* statements */
%type<mlc::icblock_pointer> simple_statement
%type<mlc::icblock_pointer> if_statement
%type<mlc::icblock_pointer> safe_statement
%type<mlc::icblock_pointer> headered_safe_statement
%type<mlc::icblock_pointer> headered_if_statement
%type<mlc::icblock_pointer> block
%type<mlc::icblock_pointer> block_body
%type<mlc::icblock_pointer> program_block
%type<mlc::icblock_pointer> whilefor_header
%type<mlc::icblock_pointer> statement
%type<mlc::icblock_pointer> statement_list

/* expressions */
%type<mlc::expression::pointer> factor
%type<mlc::expression::pointer> mulExpression
%type<mlc::expression::pointer> addExpression
%type<mlc::expression::pointer> simpleExpression
%type<mlc::expression::pointer> expression

%type<mlc::realParList::pointer> realParList

/* variables */
%type<mlc::idList::pointer> variable_noidentifier
%type<mlc::idList::pointer> variable

/* profun-definition */
%type<std::tuple<mlc::ls_id_index, mlc::parameter_list_ptr>> profun_header
%type<std::tuple<mlc::ls_id_index, mlc::parameter_list_ptr>> procedure_header
%type<std::tuple<mlc::ls_id_index, mlc::parameter_list_ptr>> function_header
%type<mlc::parameter_list_ptr> formalParList
%type<mlc::parameter_list_ptr> formal_par

/* types */
%type<mlc::typeSpecifier::pointer> type
%type<mlc::type_pointer> structured_type
%type<mlc::field_list_ptr> record_body
%type<mlc::field_list_ptr> field_list
%type<mlc::varDef::pointer> varDef
%type<mlc::idList::pointer> identifier_list

/* constants */
%type<mlc::valueConstant::pointer> constant
%type<mlc::valueConstant::pointer> unsigned_constant
%type<mlc::valueConstant::pointer> unsigned_constant_noidentifier

%start program

%%

program:
    PROGRAM IDENTIFIER SEMICOLON program_block DOT {
        ctx->tab->set_main_code($IDENTIFIER, $program_block);
    }
    ;

program_block:
    block_header
    profun_def_list
    block_body { $$ = std::move($block_body); }
    ;

block_header:
    block_header_label
    block_header_const
    block_header_type
    block_header_var
    ;

block_header_label:
    /* Can be empty; don't remove */
    | LABEL label_list SEMICOLON
    ;

block_header_const:
    /* Can be empty; don't remove */
    | CONST const_def_list
    ;

block_header_type:
    /* Can be empty; don't remove */
    | TYPE type_def_list
    ;

block_header_var:
    /* Can be empty; don't remove */
    | VAR varDef_list
    ;

block:
    block_header block_body { $$ = std::move($block_body); }
    ;

block_body:
    BEGIN statement_list END { $$ = std::move($statement_list); }
    ;

statement_list:
    statement { $$ = std::move($statement); }
    | statement_list[lft_list] SEMICOLON statement { $$ = icblock_merge_and_kill($lft_list, $statement); }
    ;

label_list:
    UINT {
        ctx->tab->add_label_entry(@UINT, $UINT, ctx->tab->new_label());
    }
    | label_list[list] COMMA UINT {
        ctx->tab->add_label_entry(@UINT, $UINT, ctx->tab->new_label());
    }
    ;

const_def_list:
    const_def SEMICOLON
    | const_def_list const_def SEMICOLON
    ;

const_def:
    IDENTIFIER EQ constant {
        switch ($constant->getType()) {
            case valueConstant::type::ID_CONSTANT: {
                auto value = ((idConstant*)&*$constant)->_val;
                mlc::symbol_pointer sp = ctx->tab->find_symbol(value);
                if (sp->kind() != SKIND_CONST)
                    message(DUERR_NOTCONST, @constant, *value);

                switch (sp->access_const()->type()->cat()) {
                    case TCAT_REAL:
                        ctx->tab->add_const_real(@IDENTIFIER, $IDENTIFIER, sp->access_const()->access_real_const()->real_value());
                    break;

                    case TCAT_INT:
                        ctx->tab->add_const_int(@IDENTIFIER, $IDENTIFIER, sp->access_const()->access_int_const()->int_value());
                    break;

                    case TCAT_STR:
                        ctx->tab->add_const_str(@IDENTIFIER, $IDENTIFIER, sp->access_const()->access_str_const()->str_value());
                    break;

                    case TCAT_BOOL:
                        ctx->tab->add_const_bool(@IDENTIFIER, $IDENTIFIER, sp->access_const()->access_bool_const()->bool_value());
                    break;

                    case TCAT_UNDEF:
                    case TCAT_RECORD:
                    case TCAT_RANGE:
                    default:
                    break;
                }
            } break;

            case valueConstant::type::UINT_CONSTANT:
                ctx->tab->add_const_int(@IDENTIFIER, $IDENTIFIER, ((uintConstant*)&*$constant)->_val);
            break;

            case valueConstant::type::STR_CONSTANT:
                ctx->tab->add_const_str(@IDENTIFIER, $IDENTIFIER, ((strConstant*)&*$constant)->_val);
            break;

            case valueConstant::type::REAL_CONSTANT:
                ctx->tab->add_const_real(@IDENTIFIER, $IDENTIFIER, ((realConstant*)&*$constant)->_val);
            break;

            case valueConstant::type::SIGNED_UINT_CONSTANT:
                if (((signedUintConstant*)&*$constant)->_oper == DUTOKGE_OPER_SIGNADD::DUTOKGE_PLUS) {
                    ctx->tab->add_const_int(@IDENTIFIER, $IDENTIFIER,
                        ((signedUintConstant*)&*$constant)->_val);
                } else {
                    ctx->tab->add_const_int(@IDENTIFIER, $IDENTIFIER,
                        ctx->tab->ls_int().add(-*((signedUintConstant*)&*$constant)->_val));
                }
            break;

            case valueConstant::type::SIGNED_REAL_CONSTANT:
                if (((signedRealConstant*)&*$constant)->_oper == DUTOKGE_OPER_SIGNADD::DUTOKGE_PLUS) {
                    ctx->tab->add_const_real(@IDENTIFIER, $IDENTIFIER,
                        ((signedRealConstant*)&*$constant)->_val);
                } else {
                    ctx->tab->add_const_real(@IDENTIFIER, $IDENTIFIER,
                        ctx->tab->ls_real().add(-*((signedRealConstant*)&*$constant)->_val));
                }
            break;
        }
    }
    ;

type_def_list:
    type_def SEMICOLON
    | type_def_list type_def SEMICOLON
    ;

type_def:
    IDENTIFIER EQ type {
        switch ($type->getType()) {
            case typeSpecifier::type::ID_TYPE: {
                auto value = ((idSpecifier*)&*$type)->_val;
                mlc::symbol_pointer sp =
                    ctx->tab->find_symbol(value);

                if (!sp || (sp->kind() != SKIND_TYPE)) {
                    message(DUERR_NOTTYPE, @type, *value);
                } else {
                    ctx->tab->add_type(@IDENTIFIER, $IDENTIFIER, sp->access_type()->type());
                }
            } break;

            case typeSpecifier::type::RECORD_TYPE:
                ctx->tab->add_type(@IDENTIFIER, $IDENTIFIER, ((recordSpecifier*)&*$type)->_val);
            break;
            default:
            break;
        }
    }
    ;

varDef_list:
    varDef_do SEMICOLON
    | varDef_list varDef_do SEMICOLON
    ;

varDef_do:
    varDef {
        for (auto&& id : $varDef->_list->_ids)
            ctx->tab->add_var(@varDef, id, $varDef->_type);
    }
    ;

varDef:
    identifier_list COLON type {
        type_pointer type;

        switch ($type->getType()) {
            case typeSpecifier::type::ID_TYPE: {
                auto value = ((idSpecifier*)&*$type)->_val;
                mlc::symbol_pointer sp =
                    ctx->tab->find_symbol(value);

                if (!sp || (sp->kind() != SKIND_TYPE))
                    message(DUERR_NOTTYPE, @type, *value);
                else
                    type = sp->access_type()->type();
            }
            break;

            case typeSpecifier::type::RECORD_TYPE:
                type = ((recordSpecifier*)&*$type)->_val;
            break;

            default:
            break;
        }

        $$ = std::make_shared<varDef>(std::move($identifier_list), type);
    }
    ;

identifier_list:
    IDENTIFIER { $$ = std::make_shared<idList>($IDENTIFIER); }
    | identifier_list[list] COMMA IDENTIFIER {
        $list->append($IDENTIFIER);
        $$ = std::move($list);
    }
    ;

profun_def_list:
    /* Can be empty; don't remove */
    | profun_def_list procedure_header SEMICOLON block SEMICOLON[end] {
        ctx->tab->leave(@end);
        ctx->tab->set_subprogram_code(std::get<0>($procedure_header), $block);
    }
    | profun_def_list function_header SEMICOLON block SEMICOLON[end] {
        ctx->tab->leave(@end);
        ctx->tab->set_subprogram_code(std::get<0>($function_header), $block);
    }
    ;

procedure_header: PROCEDURE profun_header {
        ctx->tab->add_proc(
            @profun_header,
            std::get<0>($profun_header),
            std::get<1>($profun_header));
        ctx->tab->enter(
            @profun_header,
            std::get<0>($profun_header));
        $$ = std::move($profun_header);
    }
    ;

function_header: FUNCTION profun_header COLON IDENTIFIER {
        mlc::symbol_pointer sp = ctx->tab->find_symbol($IDENTIFIER);
        if (!sp || (sp->kind() != SKIND_TYPE))
            message(DUERR_NOTTYPE, @IDENTIFIER, *$IDENTIFIER);

        ctx->tab->add_fnc(
            @profun_header,
            std::get<0>($profun_header),
            sp->access_type()->type(),
            std::get<1>($profun_header));
        ctx->tab->enter(
            @profun_header,
            std::get<0>($profun_header));

        $$ = std::move($profun_header);
    }
    ;

profun_header:
    IDENTIFIER {
        $$ = std::make_tuple($IDENTIFIER, std::make_shared<parameter_list_body>());
    }
    | IDENTIFIER LPAR formalParList RPAR {
        ctx->tab->enter(@IDENTIFIER, $IDENTIFIER);
        $$ = std::make_tuple($IDENTIFIER, $formalParList);
    }
    ;

formalParList:
    formal_par { $$ = $formal_par; }
    | formalParList[list] SEMICOLON formal_par {
        $list->append_and_kill($formal_par);
        $$ = $list;
    }
    ;

formal_par:
    identifier_list COLON IDENTIFIER {
        $$ = std::make_shared<parameter_list_body>();

        mlc::symbol_pointer sp = ctx->tab->find_symbol($IDENTIFIER);

        if (!sp || (sp->kind() != SKIND_TYPE))
            message(DUERR_NOTTYPE, @IDENTIFIER, *$IDENTIFIER);
        for (auto&& id : $identifier_list->_ids)
            $$->append_parameter_by_value(id, sp->access_type()->type());
    }
    | VAR identifier_list COLON IDENTIFIER  {
        $$ = std::make_shared<parameter_list_body>();
        mlc::symbol_pointer sp = ctx->tab->find_symbol($IDENTIFIER);

        if (!sp || (sp->kind() != SKIND_TYPE))
            message(DUERR_NOTTYPE, @IDENTIFIER, *$IDENTIFIER);
        for (auto&& id : $identifier_list->_ids)
            $$->append_parameter_by_reference(id, sp->access_type()->type());
    }
    ;

type:
    IDENTIFIER  { $$ = std::make_shared<idSpecifier>($IDENTIFIER); }
    | structured_type { $$ = std::make_shared<recordSpecifier>($structured_type); }
    ;

structured_type:
    RECORD END {
        $$ = ctx->tab->create_record_type(std::make_shared<field_list_body>(), @RECORD);
    }
    | RECORD record_body END {
        $$ = ctx->tab->create_record_type($record_body, @RECORD);
    }
    ;

record_body:
    field_list { $$ = $field_list; }
    | field_list SEMICOLON { $$ = $field_list; }
    ;

field_list:
    varDef {
        auto fields = std::make_shared<field_list_body>();

        for (auto&& id : $varDef->_list->_ids)
            fields->append_field(id, $varDef->_type);

        $$ = fields;
    }
    | field_list[fields] SEMICOLON varDef {
        for (auto&& id : $varDef->_list->_ids)
            $fields->append_field(id, $varDef->_type);

        $$ = $fields;
    }
    ;

statement:
    headered_safe_statement { $$ = std::move($headered_safe_statement); }
    | headered_if_statement { $$ = std::move($headered_if_statement); }
    ;

whilefor_header:
    WHILE expression DO  { $$ = icblock_create(); }
    | FOR IDENTIFIER ASSIGN
    expression FOR_DIRECTION expression
    DO { $$ = icblock_create(); }
    ;

headered_safe_statement:
    label_header safe_statement { $$ = std::move($safe_statement); }
    ;

safe_statement:
    /* Can be empty; don't remove */  { $$ = icblock_create(); }
    | IF expression THEN headered_safe_statement ELSE headered_safe_statement { $$ = icblock_create(); }
    | REPEAT statement_list UNTIL expression { $$ = icblock_create(); }
    | whilefor_header headered_safe_statement { $$ = icblock_create(); }
    | simple_statement { $$ = std::move($simple_statement); }
    ;

headered_if_statement:
    label_header if_statement { $$ = icblock_create(); }
    ;

if_statement:
    IF expression THEN statement { $$ = icblock_create(); }
    | IF expression THEN headered_safe_statement ELSE headered_if_statement { $$ = icblock_create(); }
    | whilefor_header headered_if_statement { $$ = icblock_create(); }
    ;

label_header:
    /* Can be empty; don't remove */
    | UINT COLON
    ;

simple_statement:
    IDENTIFIER ASSIGN expression {
        auto r_expr = expression::rexpressionize(ctx, $expression);
        auto symbol = ctx->tab->find_symbol($IDENTIFIER);
        auto kind = symbol->kind();
        type_pointer type;

        switch (kind) {
            case SKIND_GLOBAL_VARIABLE:
                type = symbol->access_global_variable()->type();
                switch (type->cat()) {
                    case TCAT_BOOL:
                        r_expr->_constr->append<ai::GSTB>(symbol->access_global_variable()->address());
                    break;

                    case TCAT_INT:
                        r_expr->_constr->append<ai::GSTI>(symbol->access_global_variable()->address());
                    break;

                    case TCAT_REAL:
                        if (r_expr->_type->cat() == TCAT_INT)
                            r_expr->_constr->append<ai::CVRTIR>();
                        else if (r_expr->_type->cat() != TCAT_REAL) {
                            // TODO: cannot be converted to real
                        }

                        r_expr->_constr->append<ai::GSTR>(symbol->access_global_variable()->address());
                    break;

                    case TCAT_STR:
                        r_expr->_constr->append<ai::GSTS>(symbol->access_global_variable()->address());
                    break;

                    case TCAT_RECORD:
                    break;
                }
            break;

            case SKIND_LOCAL_VARIABLE:
                type = symbol->access_local_variable()->type();
                switch (type->cat()) {
                    case TCAT_BOOL:
                        r_expr->_constr->append<ai::LSTB>(symbol->access_local_variable()->address());
                    break;

                    case TCAT_INT:
                        r_expr->_constr->append<ai::LSTI>(symbol->access_local_variable()->address());
                    break;

                    case TCAT_REAL:
                        if (r_expr->_type->cat() == TCAT_INT)
                            r_expr->_constr->append<ai::CVRTIR>();
                        else if (r_expr->_type->cat() != TCAT_REAL) {
                            // TODO: cannot be converted to real
                        }

                        r_expr->_constr->append<ai::LSTR>(symbol->access_local_variable()->address());
                    break;

                    case TCAT_STR:
                        r_expr->_constr->append<ai::LSTS>(symbol->access_local_variable()->address());
                    break;

                    case TCAT_RECORD:
                    break;
                }
            break;

            case SKIND_FUNCTION:
                if (ctx->tab->nested() && ctx->tab->my_function_name() == $IDENTIFIER) {
                    type = symbol->access_function()->type();

                    switch (type->cat()) {
                        case TCAT_BOOL:
                            r_expr->_constr->append<ai::LSTB>(ctx->tab->my_return_address());
                        break;

                        case TCAT_INT:
                            r_expr->_constr->append<ai::LSTI>(ctx->tab->my_return_address());
                        break;

                        case TCAT_REAL:
                            if (r_expr->_type->cat() == TCAT_INT)
                                r_expr->_constr->append<ai::CVRTIR>();
                            else if (r_expr->_type->cat() != TCAT_REAL) {
                                // TODO: cannot be converted to real
                            }

                            r_expr->_constr->append<ai::LSTR>(ctx->tab->my_return_address());
                        break;

                        case TCAT_STR:
                            r_expr->_constr->append<ai::LSTS>(ctx->tab->my_return_address());
                        break;

                        case TCAT_RECORD:
                        break;
                    }
                }
            break;
        }

        $$ = std::move(r_expr->_constr);
    }
    | variable_noidentifier ASSIGN expression {
        auto r_expr = expression::rexpressionize(ctx, $expression);
        auto symbol = ctx->tab->find_symbol($variable_noidentifier->_ids[
            0
            ]);
        auto kind = symbol->kind();
        type_pointer type;

        switch (kind) {
            case SKIND_GLOBAL_VARIABLE:
                type = symbol->access_global_variable()->type();
                switch (type->cat()) {
                    case TCAT_RECORD:{
                        auto address = symbol->access_global_variable()->address();
                        type = symbol->access_global_variable()->type();

                        if (count_field_recur(symbol, $variable_noidentifier->_ids, type, address)) {
                            switch (type->cat()) {
                                case TCAT_BOOL:
                                    r_expr->_constr->append<ai::GSTB>(address);
                                break;

                                case TCAT_INT:
                                    r_expr->_constr->append<ai::GSTI>(address);
                                break;

                                case TCAT_REAL:
                                    if (r_expr->_type->cat() == TCAT_INT)
                                        r_expr->_constr->append<ai::CVRTIR>();
                                    else if (r_expr->_type->cat() != TCAT_REAL) {
                                        // TODO: cannot be converted to real
                                    }

                                    r_expr->_constr->append<ai::GSTR>(address);
                                break;

                                case TCAT_STR:
                                    r_expr->_constr->append<ai::GSTS>(address);
                                break;

                                default:
                                    // TODO: ERROR
                                break;
                            }
                        }
                    } break;

                    default:
                        // TODO: ERROR
                    break;
                }
            break;

            case SKIND_LOCAL_VARIABLE:
                type = symbol->access_local_variable()->type();
                switch (type->cat()) {
                    case TCAT_RECORD: {
                        auto address = symbol->access_local_variable()->address();
                        type = symbol->access_local_variable()->type();

                        if (count_field_recur(symbol, $variable_noidentifier->_ids, type, address)) {
                            switch (type->cat()) {
                                case TCAT_BOOL:
                                    r_expr->_constr->append<ai::LSTB>(address);
                                break;

                                case TCAT_INT:
                                    r_expr->_constr->append<ai::LSTI>(address);
                                break;

                                case TCAT_REAL:
                                    if (r_expr->_type->cat() == TCAT_INT) {
                                        r_expr->_constr->append<ai::CVRTIR>();
                                    } else if (r_expr->_type->cat() != TCAT_REAL) {
                                        // TODO: cannot be converted to real
                                    }

                                    r_expr->_constr->append<ai::LSTR>(address);
                                break;

                                case TCAT_STR:
                                    r_expr->_constr->append<ai::LSTS>(address);
                                break;

                                default:
                                break;
                            }
                        }
                    } break;

                    default:
                    break;
                }

            default:
            break;
        }
        $$ = std::move(r_expr->_constr);
    }
    | IDENTIFIER {
        auto symbol = ctx->tab->find_symbol($IDENTIFIER);
        auto kind = symbol->kind();
        icblock_pointer constr = icblock_create();

        if (kind == SKIND_PROCEDURE) {
            constr->append<ai::CALL>(symbol->access_procedure()->code());
            $$ = std::move(constr);
        }
    }
    | IDENTIFIER LPAR realParList RPAR {
        auto symbol = ctx->tab->find_symbol($IDENTIFIER);
        auto kind = symbol->kind();
        icblock_pointer constr = icblock_create();
        icblock_pointer destr = icblock_create();

        if (kind == SKIND_PROCEDURE) {
            for (
                auto [par, real_par] = std::tuple{
                    symbol->access_procedure()->parameters()->begin(),
                    $realParList->_pars.begin()
                };

                (par != symbol->access_procedure()->parameters()->end()) &&
                (real_par != $realParList->_pars.end());

                ++par,
                ++real_par
            ) {
                if (par->partype == PMODE_BY_VALUE) {
                    auto expr = expression::rexpressionize(ctx, *real_par);

                    auto tcat1 = par->ltype->cat();
                    auto tcat2 = expr->_type->cat();

                    if (tcat1 != tcat2) {
                        if (tcat1 == TCAT_REAL) {
                            if (tcat2 == TCAT_INT) {
                                expr->_constr->append<ai::CVRTIR>();
                            }
                        } else if (tcat1 == TCAT_INT) {
                            if (tcat2 == TCAT_REAL) {
                                expr->_constr->append<ai::CVRTRI>();
                            }
                        }
                    }

                    constr = icblock_merge_and_kill(constr, expr->_constr);
                    destr = icblock_merge_and_kill(create_destr(par->ltype->cat()), destr);
                }
            }

            constr->append<ai::CALL>(symbol->access_procedure()->code());

            $$ = icblock_merge_and_kill(constr, destr);
        }
    }
    | GOTO UINT {
        $$ = icblock_create();
    }
    | block_body { $$ = std::move($block_body); }
    ;

variable:
    IDENTIFIER {
        $$ = std::make_shared<idList>($IDENTIFIER);
    }
    | variable_noidentifier { $$ = std::move($variable_noidentifier); }
    ;

variable_noidentifier:
    variable DOT IDENTIFIER {
        $variable->append($IDENTIFIER);
        $$ = std::move($variable);
    }
    ;

realParList:
    expression { $$ = std::make_shared<realParList>($expression); }
    | realParList[lft_list] COMMA expression {
        $lft_list->append($expression);
        $$ = std::move($lft_list);
    }
    ;

expression:
    simpleExpression { $$ = std::move($simpleExpression); }
    | simpleExpression[lftExpression] OPER_REL simpleExpression[rgtExpression] {
        rExpression::pointer r_expr1 = expression::rexpressionize(ctx, $lftExpression);
        rExpression::pointer r_expr2 = expression::rexpressionize(ctx, $rgtExpression);

        type_category tcat1 = r_expr1->_type->cat();
        type_category tcat2 = r_expr2->_type->cat();
        if (tcat1 == TCAT_REAL) {
            if (tcat2 == TCAT_REAL) {
                r_expr1->_constr = icblock_merge_and_kill(r_expr1->_constr, r_expr2->_constr);
            } else if (tcat2 == TCAT_INT) {
                r_expr2->_constr->append<ai::CVRTIR>();
                r_expr1->_constr = icblock_merge_and_kill(r_expr1->_constr, r_expr2->_constr);
            }

            switch ($OPER_REL) {
                case DUTOKGE_OPER_REL::DUTOKGE_LT:
                    r_expr1->_constr->append<ai::LTR>();
                break;

                case DUTOKGE_OPER_REL::DUTOKGE_LE:
                    r_expr1->_constr->append<ai::LER>();
                break;

                case DUTOKGE_OPER_REL::DUTOKGE_NE:
                    r_expr1->_constr->append<ai::NER>();
                break;

                case DUTOKGE_OPER_REL::DUTOKGE_GE:
                    r_expr1->_constr->append<ai::GER>();
                break;

                case DUTOKGE_OPER_REL::DUTOKGE_GT:
                    r_expr1->_constr->append<ai::GTR>();
                break;
            }
        } else if (tcat1 == TCAT_INT) {
            if (tcat2 == TCAT_REAL) {
                r_expr1->_constr->append<ai::CVRTIR>();
                r_expr1->_constr = icblock_merge_and_kill(r_expr1->_constr, r_expr2->_constr);

                switch ($OPER_REL) {
                    case DUTOKGE_OPER_REL::DUTOKGE_LT:
                        r_expr1->_constr->append<ai::LTR>();
                    break;

                    case DUTOKGE_OPER_REL::DUTOKGE_LE:
                        r_expr1->_constr->append<ai::LER>();
                    break;

                    case DUTOKGE_OPER_REL::DUTOKGE_NE:
                        r_expr1->_constr->append<ai::NER>();
                    break;

                    case DUTOKGE_OPER_REL::DUTOKGE_GE:
                        r_expr1->_constr->append<ai::GER>();
                    break;

                    case DUTOKGE_OPER_REL::DUTOKGE_GT:
                        r_expr1->_constr->append<ai::GTR>();
                    break;
                }
            } else if (tcat2 == TCAT_INT) {
                r_expr1->_constr = icblock_merge_and_kill(r_expr1->_constr, r_expr2->_constr);

                switch ($OPER_REL) {
                    case DUTOKGE_OPER_REL::DUTOKGE_LT:
                        r_expr1->_constr->append<ai::LTI>();
                    break;

                    case DUTOKGE_OPER_REL::DUTOKGE_LE:
                        r_expr1->_constr->append<ai::LEI>();
                    break;

                    case DUTOKGE_OPER_REL::DUTOKGE_NE:
                        r_expr1->_constr->append<ai::NEI>();
                    break;

                    case DUTOKGE_OPER_REL::DUTOKGE_GE:
                        r_expr1->_constr->append<ai::GEI>();
                    break;

                    case DUTOKGE_OPER_REL::DUTOKGE_GT:
                        r_expr1->_constr->append<ai::GTI>();
                    break;
                }
            }
        }

        $$ = std::move(r_expr1);
    }
    ;

simpleExpression:
    addExpression { $$ = std::move($addExpression); }
    | OPER_SIGNADD addExpression {
        rExpression::pointer r_expr = expression::rexpressionize(ctx, $addExpression);

        if ($OPER_SIGNADD == DUTOKGE_OPER_SIGNADD::DUTOKGE_MINUS) {
            switch (r_expr->_type->cat()) {
                case TCAT_INT:
                    r_expr->_constr->append<ai::MINUSI>();
                break;

                case TCAT_REAL:
                    r_expr->_constr->append<ai::MINUSR>();
                break;

                default:
                break;
            }
        }

        $$ = std::move(r_expr);
    }
    ;

addExpression:
    mulExpression { $$ = std::move($mulExpression); }
    | addExpression[lftExpression] OPER_SIGNADD mulExpression {
        rExpression::pointer r_expr1 = expression::rexpressionize(ctx, $lftExpression);
        rExpression::pointer r_expr2 = expression::rexpressionize(ctx, $mulExpression);

        type_category tcat1 = r_expr1->_type->cat();
        type_category tcat2 = r_expr2->_type->cat();

        if (tcat1 == TCAT_REAL) {
            if (tcat2 == TCAT_REAL) {
                r_expr1->_constr = icblock_merge_and_kill(r_expr1->_constr, r_expr2->_constr);
            } else if (tcat2 == TCAT_INT) {
                r_expr2->_constr->append<ai::CVRTIR>();
                r_expr1->_constr = icblock_merge_and_kill(r_expr1->_constr, r_expr2->_constr);
            }

            if ($OPER_SIGNADD == DUTOKGE_OPER_SIGNADD::DUTOKGE_PLUS) {
                r_expr1->_constr->append<ai::ADDR>();
            } else {
                r_expr1->_constr->append<ai::SUBR>();
            }
        } else if (tcat1 == TCAT_INT) {
            if (tcat2 == TCAT_REAL) {
                r_expr1->_constr->append<ai::CVRTIR>();
                r_expr1->_constr = icblock_merge_and_kill(r_expr1->_constr, r_expr2->_constr);

                if ($OPER_SIGNADD == DUTOKGE_OPER_SIGNADD::DUTOKGE_PLUS) {
                    r_expr1->_constr->append<ai::ADDR>();
                } else {
                    r_expr1->_constr->append<ai::SUBR>();
                }
            } else if (tcat2 == TCAT_INT) {
                r_expr1->_constr = icblock_merge_and_kill(r_expr1->_constr, r_expr2->_constr);

                if ($OPER_SIGNADD == DUTOKGE_OPER_SIGNADD::DUTOKGE_PLUS) {
                    r_expr1->_constr->append<ai::ADDI>();
                } else {
                    r_expr1->_constr->append<ai::SUBI>();
                }
            }
        } else if (tcat1 == TCAT_STR && tcat2 == TCAT_STR) {
                r_expr1->_constr = icblock_merge_and_kill(r_expr1->_constr, r_expr2->_constr);

                if ($OPER_SIGNADD == DUTOKGE_OPER_SIGNADD::DUTOKGE_PLUS) {
                    r_expr1->_constr->append<ai::ADDS>();
                }
        }
        $$ = std::move(r_expr1);
    }
    | addExpression[lftExpression] OR mulExpression {
        rExpression::pointer r_expr1 = expression::rexpressionize(ctx, $lftExpression);
        rExpression::pointer r_expr2 = expression::rexpressionize(ctx, $mulExpression);

        type_category tcat1 = r_expr1->_type->cat();
        type_category tcat2 = r_expr2->_type->cat();

        if (tcat1 == TCAT_BOOL) {
            if (tcat2 == TCAT_BOOL) {
                r_expr1->_constr = icblock_merge_and_kill(r_expr1->_constr, r_expr2->_constr);
                r_expr1->_constr->append<ai::OR>();
            }
        }
        $$ = std::move(r_expr1);
    }
    ;

mulExpression:
    factor { $$ = std::move($factor); }
    | mulExpression[lft_expr] OPER_MUL factor {
        rExpression::pointer r_expr1 = expression::rexpressionize(ctx, $lft_expr);
        rExpression::pointer r_expr2 = expression::rexpressionize(ctx, $factor);

        type_category tcat1 = r_expr1->_type->cat();
        type_category tcat2 = r_expr2->_type->cat();

        switch ($OPER_MUL) {
            case DUTOKGE_OPER_MUL::DUTOKGE_AND:
                if (tcat1 == TCAT_BOOL) {
                    if (tcat2 == TCAT_BOOL) {
                        r_expr1->_constr = icblock_merge_and_kill(r_expr1->_constr, r_expr2->_constr);
                        r_expr1->_constr->append<ai::OR>();
                    }
                }
            break;

            case DUTOKGE_OPER_MUL::DUTOKGE_ASTERISK:
                if (tcat1 == TCAT_REAL) {
                    if (tcat2 == TCAT_REAL) {
                        r_expr1->_constr = icblock_merge_and_kill(r_expr1->_constr, r_expr2->_constr);
                    } else if (tcat2 == TCAT_INT) {
                        r_expr2->_constr->append<ai::CVRTIR>();
                        r_expr1->_constr = icblock_merge_and_kill(r_expr1->_constr, r_expr2->_constr);
                    }

                    r_expr1->_constr->append<ai::MULR>();
                } else if (tcat1 == TCAT_INT) {
                    if (tcat2 == TCAT_REAL) {
                        r_expr1->_constr->append<ai::CVRTIR>();
                        r_expr1->_constr = icblock_merge_and_kill(r_expr1->_constr, r_expr2->_constr);
                        r_expr1->_constr->append<ai::MULR>();
                    } else if (tcat2 == TCAT_INT) {
                        r_expr1->_constr = icblock_merge_and_kill(r_expr1->_constr, r_expr2->_constr);
                        r_expr1->_constr->append<ai::MULI>();
                    }
                }
            break;

            case DUTOKGE_OPER_MUL::DUTOKGE_SOLIDUS:
                if (tcat1 == TCAT_REAL) {
                    if (tcat2 == TCAT_REAL) {
                        r_expr1->_constr = icblock_merge_and_kill(r_expr1->_constr, r_expr2->_constr);
                    } else if (tcat2 == TCAT_INT) {
                        r_expr2->_constr->append<ai::CVRTIR>();
                        r_expr1->_constr = icblock_merge_and_kill(r_expr1->_constr, r_expr2->_constr);
                    }

                } else if (tcat1 == TCAT_INT) {
                    r_expr1->_constr->append<ai::CVRTIR>();

                    if (tcat2 == TCAT_REAL) {
                        r_expr1->_constr = icblock_merge_and_kill(r_expr1->_constr, r_expr2->_constr);
                    } else if (tcat2 == TCAT_INT) {
                        r_expr2->_constr->append<ai::CVRTIR>();
                        r_expr1->_constr = icblock_merge_and_kill(r_expr1->_constr, r_expr2->_constr);
                    }
                }

                r_expr1->_type = ctx->tab->logical_real();
                r_expr1->_constr->append<ai::DIVR>();
            break;

            case DUTOKGE_OPER_MUL::DUTOKGE_DIV:
                if (tcat1 == TCAT_REAL) {
                    r_expr1->_constr->append<ai::CVRTRI>();
                    if (tcat2 == TCAT_REAL) {
                        r_expr2->_constr->append<ai::CVRTRI>();
                        r_expr1->_constr = icblock_merge_and_kill(r_expr1->_constr, r_expr2->_constr);
                    } else if (tcat2 == TCAT_INT) {
                        r_expr1->_constr = icblock_merge_and_kill(r_expr1->_constr, r_expr2->_constr);
                    }

                    r_expr1->_constr->append<ai::DIVI>();
                } else if (tcat1 == TCAT_INT) {
                    if (tcat2 == TCAT_REAL) {
                        r_expr2->_constr->append<ai::CVRTRI>();
                        r_expr1->_constr = icblock_merge_and_kill(r_expr1->_constr, r_expr2->_constr);
                    } else if (tcat2 == TCAT_INT) {
                        r_expr1->_constr = icblock_merge_and_kill(r_expr1->_constr, r_expr2->_constr);
                    }

                    r_expr1->_constr->append<ai::DIVI>();
                }
            break;

            case DUTOKGE_OPER_MUL::DUTOKGE_MOD:
                if (tcat1 == TCAT_REAL) {
                    r_expr1->_constr->append<ai::CVRTRI>();
                    if (tcat2 == TCAT_REAL) {
                        r_expr2->_constr->append<ai::CVRTRI>();
                        r_expr1->_constr = icblock_merge_and_kill(r_expr1->_constr, r_expr2->_constr);
                    } else if (tcat2 == TCAT_INT) {
                        r_expr1->_constr = icblock_merge_and_kill(r_expr1->_constr, r_expr2->_constr);
                    }

                    r_expr1->_constr->append<ai::MODI>();
                } else if (tcat1 == TCAT_INT) {
                    if (tcat2 == TCAT_REAL) {
                        r_expr2->_constr->append<ai::CVRTRI>();
                        r_expr1->_constr = icblock_merge_and_kill(r_expr1->_constr, r_expr2->_constr);
                    } else if (tcat2 == TCAT_INT) {
                        r_expr1->_constr = icblock_merge_and_kill(r_expr1->_constr, r_expr2->_constr);
                    }

                    r_expr1->_constr->append<ai::MODI>();
                }
            break;
        }
        $$ = std::move(r_expr1);
    }
    ;

factor:
    unsigned_constant_noidentifier[constant] {
        type_pointer type;
        icblock_pointer constr = icblock_create();

        switch($constant->getType()) {
            case valueConstant::type::UINT_CONSTANT:
                type = ctx->tab->logical_integer();
                constr->append<ai::LDLITI>(((uintConstant*)&*$constant)->_val);
            break;

            case valueConstant::type::STR_CONSTANT:
                type = ctx->tab->logical_string();
                constr->append<ai::LDLITS>(((strConstant*)&*$constant)->_val);
            break;

            case valueConstant::type::REAL_CONSTANT:
                type = ctx->tab->logical_real();
                constr->append<ai::LDLITR>(((realConstant*)&*$constant)->_val);
            break;

            default:
            break;
        }

        $$ = std::make_shared<rExpression>(
            type,
            constr);
    }
    | variable_noidentifier {
        $$ = std::make_shared<lExpression>(
            ctx->tab->find_symbol($variable_noidentifier->_ids[
                0
                ])->access_typed()->type(),
            $variable_noidentifier);
    }
    | IDENTIFIER {
        $$ = std::make_shared<lExpression>(
            ctx->tab->find_symbol($IDENTIFIER)->access_typed()->type(),
            std::make_shared<idList>($IDENTIFIER));
    }
    | IDENTIFIER LPAR realParList RPAR {
        auto symbol = ctx->tab->find_symbol($IDENTIFIER);
        auto kind = symbol->kind();
        icblock_pointer constr = icblock_create();
        icblock_pointer destr = icblock_create();

        if (kind == SKIND_FUNCTION) {
            type_pointer type = symbol->access_function()->type();
            switch (type->cat()) {
                case TCAT_BOOL:
                    constr->append<ai::INITB>();
                break;

                case TCAT_INT:
                    constr->append<ai::INITI>();
                break;

                case TCAT_REAL:
                    constr->append<ai::INITR>();
                break;

                case TCAT_STR:
                    constr->append<ai::INITS>();
                break;

                case TCAT_RECORD:
                    // TODO: function returning a record
                break;
            }

            for (
                auto [par, real_par] = std::tuple{
                    symbol->access_function()->parameters()->begin(),
                    $realParList->_pars.begin()
                };

                (par != symbol->access_function()->parameters()->end()) &&
                (real_par != $realParList->_pars.end());

                ++par,
                ++real_par
            ) {
                if (par->partype == PMODE_BY_VALUE) {
                    auto expr = expression::rexpressionize(ctx, *real_par);

                    auto tcat1 = par->ltype->cat();
                    auto tcat2 = expr->_type->cat();

                    if (tcat1 != tcat2) {
                        if (tcat1 == TCAT_REAL) {
                            if (tcat2 == TCAT_INT) {
                                expr->_constr->append<ai::CVRTIR>();
                            }
                        } else if (tcat1 == TCAT_INT) {
                            if (tcat2 == TCAT_REAL) {
                                expr->_constr->append<ai::CVRTRI>();
                            }
                        }
                    }

                    constr = icblock_merge_and_kill(constr, expr->_constr);
                    destr = icblock_merge_and_kill(create_destr(par->ltype->cat()), destr);
                }
            }

            constr->append<ai::CALL>(symbol->access_function()->code());

            $$ = std::make_shared<rExpression>(type, icblock_merge_and_kill(constr, destr));
        }
    }
    | LPAR expression RPAR { $$ = std::move($expression); }
    | NOT factor[inner_factor] {
        rExpression::pointer r_expr = expression::rexpressionize(ctx, $inner_factor);

        switch (r_expr->_type->cat()) {
            case TCAT_BOOL:
                r_expr->_constr->append<ai::NOT>();
            break;

            default:
            break;
        }

        $$ = std::move(r_expr);
    }
    ;

constant:
    unsigned_constant { $$ = std::move($unsigned_constant); }
    | OPER_SIGNADD UINT { $$ = std::make_shared<signedUintConstant>($OPER_SIGNADD, $UINT); }
    | OPER_SIGNADD REAL { $$ = std::make_shared<signedRealConstant>($OPER_SIGNADD, $REAL); }
    ;

unsigned_constant:
    IDENTIFIER  { $$ = std::make_shared<idConstant>($IDENTIFIER); }
    | unsigned_constant_noidentifier { $$ = std::move($unsigned_constant_noidentifier); }
    ;

unsigned_constant_noidentifier:
    UINT { $$ = std::make_shared<uintConstant>($UINT); }
    | REAL { $$ = std::make_shared<realConstant>($REAL); }
    | STRING { $$ = std::make_shared<strConstant>($STRING); }
    ;

%%

namespace yy {
    void mlaskal_parser::error(const location_type& l, const std::string& m)
    {
        message(DUERR_SYNTAX, l, m);
    }
}