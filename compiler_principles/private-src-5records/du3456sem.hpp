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
std::string &upper(std::string &);
std::string &dropApostrophe(std::string &);

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

class typeSpecifier
{
public:
    typedef std::shared_ptr<typeSpecifier> pointer;
    enum class type
    {
        ID_TYPE,
        RECORD_TYPE,
        ARRAY_TYPE
    };

    typeSpecifier() = default;
    virtual ~typeSpecifier() noexcept = default;
    virtual type getType() const = 0;
};

class idSpecifier : public typeSpecifier
{
public:
    idSpecifier(
        ls_id_index val) : _val{val}
    {
    }

    ~idSpecifier() noexcept override = default;
    type getType() const override
    {
        return type::ID_TYPE;
    }

    ls_id_index _val;
};

class recordSpecifier : public typeSpecifier
{
public:
    recordSpecifier(
        type_pointer val) : _val{val}
    {
    }

    ~recordSpecifier() noexcept override = default;
    type getType() const override
    {
        return type::RECORD_TYPE;
    }

    type_pointer _val;
};

class valueConstant
{
public:
    typedef std::shared_ptr<valueConstant> pointer;
    enum class type
    {
        SIGNED_UINT_CONSTANT,
        SIGNED_REAL_CONSTANT,
        UINT_CONSTANT,
        STR_CONSTANT,
        REAL_CONSTANT,
        ID_CONSTANT
    };

    valueConstant() = default;
    virtual ~valueConstant() noexcept = default;
    virtual type getType() const = 0;
};

class idConstant : public valueConstant
{
public:
    idConstant(
        ls_id_index val) : _val{val}
    {
    }

    ~idConstant() noexcept override = default;
    type getType() const override
    {
        return type::ID_CONSTANT;
    }

    ls_id_index _val;
};

class strConstant : public valueConstant
{
public:
    strConstant(
        ls_str_index val) : _val{val}
    {
    }

    ~strConstant() noexcept override = default;
    type getType() const override
    {
        return type::STR_CONSTANT;
    }

    ls_str_index _val;
};

class realConstant : public valueConstant
{
public:
    realConstant(
        ls_real_index val) : _val{val}
    {
    }

    ~realConstant() noexcept override = default;
    type getType() const override
    {
        return type::REAL_CONSTANT;
    }

    ls_real_index _val;
};

class uintConstant : public valueConstant
{
public:
    uintConstant(
        ls_int_index val) : _val{val}
    {
    }

    ~uintConstant() noexcept override = default;
    type getType() const override
    {
        return type::UINT_CONSTANT;
    }

    ls_int_index _val;
};

class signedUintConstant : public valueConstant
{
public:
    signedUintConstant(
        DUTOKGE_OPER_SIGNADD oper,
        ls_int_index val) : _oper{oper}, _val{val}
    {
    }

    ~signedUintConstant() noexcept override = default;
    type getType() const override
    {
        return type::SIGNED_UINT_CONSTANT;
    }

    DUTOKGE_OPER_SIGNADD _oper;
    ls_int_index _val;
};

class signedRealConstant : public valueConstant
{
public:
    signedRealConstant(
        DUTOKGE_OPER_SIGNADD oper,
        ls_real_index val) : _oper{oper}, _val{val}
    {
    }

    ~signedRealConstant() noexcept override = default;
    type getType() const override
    {
        return type::SIGNED_REAL_CONSTANT;
    }

    DUTOKGE_OPER_SIGNADD _oper;
    ls_real_index _val;
};

struct idList
{
    typedef std::shared_ptr<idList> pointer;

    idList() = default;
    idList(ls_id_index val) : _ids{}
    {
        _ids.push_back(val);
    }

    ~idList() noexcept = default;

    void append(ls_id_index val)
    {
        _ids.push_back(val);
    }

    std::vector<ls_id_index> _ids;
};

struct varDef
{
    typedef std::shared_ptr<varDef> pointer;
    varDef(
        idList::pointer list,
        type_pointer type) : _list{std::move(list)},
                             _type{type}
    {
    }

    varDef() noexcept = default;

    idList::pointer _list;
    type_pointer _type;
};

class rExpression;
class lExpression;

class expression
{
public:
    typedef std::shared_ptr<expression> pointer;
    typedef std::shared_ptr<rExpression> r_pointer;
    typedef std::shared_ptr<lExpression> l_pointer;
    enum class type
    {
        REXPRESSION,
        LEXPRESSION
    };

    expression(type_pointer type) : _type{type}
    {
    }

    virtual ~expression() noexcept = default;
    virtual type getType() const = 0;

    static r_pointer rexpressionize(MlaskalCtx *ctx, pointer);

    type_pointer _type;
};

class rExpression : public expression
{
public:
    typedef r_pointer pointer;
    rExpression(
        type_pointer type,
        icblock_pointer constr) : expression(type),
                                  _constr{std::move(constr)}
    {
    }

    ~rExpression() noexcept override = default;

    type getType() const override
    {
        return type::REXPRESSION;
    }

    icblock_pointer _constr;
};

class lExpression : public expression
{
public:
    typedef l_pointer pointer;
    lExpression(
        type_pointer type,
        idList::pointer ids) : expression(type),
                                _ids{std::move(ids)}
    {
    }

    ~lExpression() noexcept override = default;

    type getType() const override
    {
        return type::LEXPRESSION;
    }

    idList::pointer _ids;
};

class realParList
{
public:
    typedef std::shared_ptr<realParList> pointer;
    realParList() : _pars{}
    {
    }

    realParList(
        expression::pointer par) : _pars{}
    {
        _pars.push_back(par);
    }

    ~realParList() noexcept = default;

    void append(expression::pointer par)
    {
        _pars.push_back(par);
    }

    std::vector<expression::pointer> _pars;
};

}

#endif // DU3456SEM_HPP_
