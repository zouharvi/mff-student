#ifndef DU3456SEM_HPP_
#define DU3456SEM_HPP_

#include <string>
#include <sstream>
#include <utility>
#include <memory>
#include <vector>
#include <tuple>

#include "literal_storage.hpp"
#include "flat_icblock.hpp"
#include "dutables.hpp"
#include "abstract_instr.hpp"
#include "gen_ainstr.hpp"

namespace mlc
{
std::string &upper_case(std::string &);
std::string &un_apostrophe(std::string &);

enum class SPECIAL_CASE
{
    SC_NORMAL,
    SC_UINT_DOTDOT
};

ls_real_type::value_type convert_real(const std::string &);
ls_int_type::value_type convert_int(
    const char *from,
    decltype(MlaskalCtx::curline) line);

icblock_pointer create_destr(type_category);

bool count_field_recur(
    symbol_pointer symbol,
    const std::vector<ls_id_index> &ids,
    type_pointer &type,
    stack_address &address);

class type_specifier
{
public:
    typedef std::shared_ptr<type_specifier> pointer;
    enum class type
    {
        ID_TYPE,
        RECORD_TYPE,
        ARRAY_TYPE // NOT SUPPORTED
    };

    type_specifier() = default;
    virtual ~type_specifier() noexcept = default;
    virtual type get_type() const = 0;
};

class id_specifier : public type_specifier
{
public:
    id_specifier(
        ls_id_index val) : _val{val}
    {
    }

    ~id_specifier() noexcept override = default;
    type get_type() const override
    {
        return type::ID_TYPE;
    }

    ls_id_index _val;
};

class record_specifier : public type_specifier
{
public:
    record_specifier(
        type_pointer val) : _val{val}
    {
    }

    ~record_specifier() noexcept override = default;
    type get_type() const override
    {
        return type::RECORD_TYPE;
    }

    type_pointer _val;
};

class constant_value
{
public:
    typedef std::shared_ptr<constant_value> pointer;
    enum class type
    {
        SIGNED_UINT_CONSTANT,
        SIGNED_REAL_CONSTANT,
        UINT_CONSTANT,
        STR_CONSTANT,
        REAL_CONSTANT,
        ID_CONSTANT
    };

    constant_value() = default;
    virtual ~constant_value() noexcept = default;
    virtual type get_type() const = 0;
};

class id_constant : public constant_value
{
public:
    id_constant(
        ls_id_index val) : _val{val}
    {
    }

    ~id_constant() noexcept override = default;
    type get_type() const override
    {
        return type::ID_CONSTANT;
    }

    ls_id_index _val;
};

class str_constant : public constant_value
{
public:
    str_constant(
        ls_str_index val) : _val{val}
    {
    }

    ~str_constant() noexcept override = default;
    type get_type() const override
    {
        return type::STR_CONSTANT;
    }

    ls_str_index _val;
};

class real_constant : public constant_value
{
public:
    real_constant(
        ls_real_index val) : _val{val}
    {
    }

    ~real_constant() noexcept override = default;
    type get_type() const override
    {
        return type::REAL_CONSTANT;
    }

    ls_real_index _val;
};

class uint_constant : public constant_value
{
public:
    uint_constant(
        ls_int_index val) : _val{val}
    {
    }

    ~uint_constant() noexcept override = default;
    type get_type() const override
    {
        return type::UINT_CONSTANT;
    }

    ls_int_index _val;
};

class signed_uint_constant : public constant_value
{
public:
    signed_uint_constant(
        DUTOKGE_OPER_SIGNADD oper,
        ls_int_index val) : _oper{oper}, _val{val}
    {
    }

    ~signed_uint_constant() noexcept override = default;
    type get_type() const override
    {
        return type::SIGNED_UINT_CONSTANT;
    }

    DUTOKGE_OPER_SIGNADD _oper;
    ls_int_index _val;
};

class signed_real_constant : public constant_value
{
public:
    signed_real_constant(
        DUTOKGE_OPER_SIGNADD oper,
        ls_real_index val) : _oper{oper}, _val{val}
    {
    }

    ~signed_real_constant() noexcept override = default;
    type get_type() const override
    {
        return type::SIGNED_REAL_CONSTANT;
    }

    DUTOKGE_OPER_SIGNADD _oper;
    ls_real_index _val;
};

struct id_list
{
    typedef std::shared_ptr<id_list> pointer;

    id_list() = default;
    id_list(ls_id_index val) : _ids{}
    {
        _ids.push_back(val);
    }

    ~id_list() noexcept = default;

    void append(ls_id_index val)
    {
        _ids.push_back(val);
    }

    std::vector<ls_id_index> _ids;
};

struct var_def
{
    typedef std::shared_ptr<var_def> pointer;
    var_def(
        id_list::pointer list,
        type_pointer type) : _list{std::move(list)},
                             _type{type}
    {
    }

    var_def() noexcept = default;

    id_list::pointer _list;
    type_pointer _type;
};

class r_expression;
class l_expression;

class expression
{
public:
    typedef std::shared_ptr<expression> pointer;
    typedef std::shared_ptr<r_expression> r_pointer;
    typedef std::shared_ptr<l_expression> l_pointer;
    enum class type
    {
        REXPRESSION,
        LEXPRESSION
    };

    expression(type_pointer type) : _type{type}
    {
    }

    virtual ~expression() noexcept = default;
    virtual type get_type() const = 0;

    static r_pointer rexpressionize(MlaskalCtx *ctx, pointer);

    type_pointer _type;
};

class r_expression : public expression
{
public:
    typedef r_pointer pointer;
    r_expression(
        type_pointer type,
        icblock_pointer constr) : expression(type),
                                  _constr{std::move(constr)}
    {
    }

    ~r_expression() noexcept override = default;

    type get_type() const override
    {
        return type::REXPRESSION;
    }

    icblock_pointer _constr;
};

class l_expression : public expression
{
public:
    typedef l_pointer pointer;
    l_expression(
        type_pointer type,
        id_list::pointer ids) : expression(type),
                                _ids{std::move(ids)}
    {
    }

    ~l_expression() noexcept override = default;

    type get_type() const override
    {
        return type::LEXPRESSION;
    }

    id_list::pointer _ids;
};

class real_par_list
{
public:
    typedef std::shared_ptr<real_par_list> pointer;
    real_par_list() : _pars{}
    {
    }

    real_par_list(
        expression::pointer par) : _pars{}
    {
        _pars.push_back(par);
    }

    ~real_par_list() noexcept = default;

    void append(expression::pointer par)
    {
        _pars.push_back(par);
    }

    std::vector<expression::pointer> _pars;
};

}

#endif // DU3456SEM_HPP_
