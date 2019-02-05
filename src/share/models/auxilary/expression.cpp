#include "models/auxilary/expression.h"

Expression::Expression(const std::vector<std::string> &tokens, bool &ok)
{
    size_t length = tokens.size();
    size_t start_index = 0;
    size_t end_index = length - start_index - 1;

    for (const std::string& s : tokens)
    {
        raw_name += s;
    }

    while (tokens[start_index] == "(" && tokens[end_index] == ")")
    {
        start_index++;
        end_index--;
    }
    length = end_index - start_index + 1;

    if (length == 0)
    { // virtual operand for, eg + -5
        value = "";
        value_only = true;
        return;
    }
    if (length == 1)
    { // probably a variable or a constant
        value = tokens[0];
        value_only = true;
        // @TODO: check if value is at least size 2
        if ((value.front() == '"' && value.back() == '"') ||
            (value.front() == '"' && value.back() == '"'))
        {
            // string constant
            value = value.substr(1, value.length() - 2);
        }
        else if (CompUtils::is_number(value))
        {
            // is number
        }
        else
        {
            is_variable = true;
            required_vars.insert(value);
        }
        return;
    }
    int open = 0;
    unsigned int lowest_priority = 0;
    unsigned int lowest_priority_index = 0;
    // this could be all done in one pass, but this just seemed more robus
    for (size_t i = start_index; i <= end_index; i++)
    {
        if (tokens[i] == "(")
        {
            open++;
            continue;
        }
        if (tokens[i] == ")")
        {
            open--;
            if (open < 0)
            {
                err(ok, "Expression not properly parenthesized", tokens);
                return;
            }
            continue;
        }
        unsigned int priority = get_priority(tokens[i]);
        if (priority != 0)
        { // tokens[i] is an operator
            if (open * 100 + priority < lowest_priority || lowest_priority == 0)
            {
                lowest_priority_index = i;
                lowest_priority = open * 100 + priority;
            }
        }
    }
    if (open != 0)
    {
        err(ok, "Expression not properly parenthesized", tokens);
        return;
    }

    std::string ops = this->ops = tokens[lowest_priority_index];
    if (ops == "+")
        op = ADD;
    else if (ops == "-")
        op = SUB;
    else if (ops == "/")
        op = DIV;
    else if (ops == "*")
        op = MUL;
    else if (ops == "AND")
        op = AND;
    else if (ops == "OR")
        op = OR;
    else if (ops == "||")
        op = CAT;
    else if (ops == "=")
        op = EQ;
    else if (ops == "!=")
        op = NEQ;
    else
    {
        err(ok, "Error: Invalid operator `" + ops + "`");
    }

    left_expr = std::make_unique<Expression>(CompUtils::slice(tokens, start_index, lowest_priority_index - 1), ok);
    right_expr = std::make_unique<Expression>(CompUtils::slice(tokens, lowest_priority_index + 1, end_index), ok);

    required_vars.merge(left_expr->required_vars);
    required_vars.merge(right_expr->required_vars);
}

std::string Expression::eval(std::map<std::string, std::string> &vars, bool &ok)
{
    if (value_only)
    {
        if (is_variable)
        {
            if (vars.count(value) == 0)
            { // didn't find the required value
                err(ok, "Error: Variable `" + value + "` not propagated");
                return "";
            }
            else
            {
                return vars[value];
            }
        }
        else
        {
            return value;
        }
    }

    double ld, rd;
    bool lb, rb;
    std::string ls, rs;
    switch (op)
    {
    case ADD:
        // left side can be virtual
        ld = left_expr == nullptr ? 0 : left_expr->eval_cast<double>(vars, ok);
        if (right_expr == nullptr)
        {
            missing_right_op(ok, ops);
            return "";
        }
        rd = right_expr->eval_cast<double>(vars, ok);
        return std::to_string(ok ? (ld + rd) : 0);
        break;
    case SUB:
        // left side can be virtual
        ld = left_expr == nullptr ? 0 : left_expr->eval_cast<double>(vars, ok);
        if (right_expr == nullptr)
        {
            missing_right_op(ok, ops);
            return "";
        }
        rd = right_expr->eval_cast<double>(vars, ok);
        return std::to_string(ok ? (ld - rd) : 0);
        break;
    case MUL:
        if (left_expr == nullptr)
        {
            missing_left_op(ok, ops);
            return "";
        }
        if (right_expr == nullptr)
        {
            missing_right_op(ok, ops);
            return "";
        }
        ld = left_expr->eval_cast<double>(vars, ok);
        rd = right_expr->eval_cast<double>(vars, ok);
        return std::to_string(ok ? (ld * rd) : 0);
        break;
    case DIV:
        if (left_expr == nullptr)
        {
            missing_left_op(ok, ops);
            return "";
        }
        if (right_expr == nullptr)
        {
            missing_right_op(ok, ops);
            return "";
        }
        ld = left_expr->eval_cast<double>(vars, ok);
        rd = right_expr->eval_cast<double>(vars, ok);
        if (rd == 0)
        {
            err(ok, "Error: Division by zero");
            return "";
        }
        return std::to_string(ok ? (ld / rd) : 0);
        break;
    case AND:
        if (left_expr == nullptr)
        {
            missing_left_op(ok, ops);
            return "";
        }
        if (right_expr == nullptr)
        {
            missing_right_op(ok, ops);
            return "";
        }
        lb = left_expr->eval_cast<bool>(vars, ok);
        rb = right_expr->eval_cast<bool>(vars, ok);
        return std::to_string(ok ? (lb && rb) : 0);
        break;
    case OR:
        if (left_expr == nullptr)
        {
            missing_left_op(ok, ops);
            return "";
        }
        if (right_expr == nullptr)
        {
            missing_right_op(ok, ops);
            return "";
        }
        lb = left_expr->eval_cast<bool>(vars, ok);
        rb = right_expr->eval_cast<bool>(vars, ok);
        return std::to_string(ok ? (lb || rb) : 0);
        break;
    case CAT:
        if (left_expr == nullptr)
        {
            missing_left_op(ok, ops);
            return "";
        }
        if (right_expr == nullptr)
        {
            missing_right_op(ok, ops);
            return "";
        }
        ls = left_expr->eval_cast<std::string>(vars, ok);
        rs = right_expr->eval_cast<std::string>(vars, ok);
        return ok ? ls + rs : std::to_string(0);
        break;
    case EQ:
        if (left_expr == nullptr)
        {
            missing_left_op(ok, ops);
            return "";
        }
        if (right_expr == nullptr)
        {
            missing_right_op(ok, ops);
            return "";
        }
        ls = left_expr->eval_cast<std::string>(vars, ok);
        rs = right_expr->eval_cast<std::string>(vars, ok);
        return (ok && ls == rs) ? std::to_string(1) : std::to_string(0);
        break;
    case NEQ:
        if (left_expr == nullptr)
        {
            missing_left_op(ok, ops);
            return "";
        }
        if (right_expr == nullptr)
        {
            missing_right_op(ok, ops);
            return "";
        }
        ls = left_expr->eval_cast<std::string>(vars, ok);
        rs = right_expr->eval_cast<std::string>(vars, ok);
        return (ok && ls != rs) ? std::to_string(1) : std::to_string(0);
        break;
    default:
        err(ok, "Error: No operator found");
        return "";
    }
}

template <>
bool Expression::cast<bool>(std::string value, bool &)
{
    return value != "0" && value != "";
}

template <>
double Expression::cast<double>(std::string value, bool &ok)
{
    try
    {
        return stod(value);
    }
    catch (...)
    {
        ok = false;
        err(ok, "Error: `" + value + "` cannot be parsed");
        return 0;
    }
}

template <>
std::string Expression::cast<std::string>(std::string value, bool &)
{
    return value;
}

unsigned int Expression::get_priority(std::string op)
{

    // level 2
    if (op == "*")
        return 5;
    if (op == "/")
        return 5;
    if (op == "%")
        return 5;

    // level 3
    if (op == "+")
        return 4;
    if (op == "-")
        return 4;
    if (op == "||")
        return 4;

    // level 5
    if (op == "NOT")
        return 3;

    // level 6, 7
    if (op == "AND")
        return 3;
    if (op == "OR")
        return 3;

    // level 8
    if (op == "=")
        return 2;
    if (op == "!=")
        return 2;

    return 0;
}

bool Expression::is_operator(std::string op)
{
    // level 2
    if (op == "*" || op == "/" || op == "%")
        return true;

    // level 3
    if (op == "+" || op == "-" || op == "||")
        return true;

    // level 5
    if (op == "NOT")
        return true;

    // level 6, 7
    if (op == "AND" || op == "OR")
        return true;

    return false;
}

void Expression::err(bool &ok, std::string info, std::vector<std::string> tokens)
{
    ok = false;
    if (!tokens.empty())
    {
        std::cout << "Error `" << CompUtils::implode(tokens, " ") << "`" << std::endl;
        std::cout << "      ";
    }
    std::cout << info << std::endl;
}

void Expression::missing_left_op(bool &ok, const std::string &ops)
{
    err(ok, "Error: Missing left operand for `" + ops + "`");
}

void Expression::missing_right_op(bool &ok, const std::string &ops)
{
    err(ok, "Error: Missing right operand for `" + ops + "`");
}