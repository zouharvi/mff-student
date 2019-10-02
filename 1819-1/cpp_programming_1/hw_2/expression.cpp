#include "expression.h"

void Expression::swap_children(std::unique_ptr<Expression> &tl, std::unique_ptr<Expression> &tr)
{
    if ((t.type == Token::OP_1) || (t.type == Token::OP_2))
    {
        tl = std::move(left);
        tr = std::move(right);
    }
}

void Expression::traverse_infix()
{
    if (!is_simple())
    {
        std::cout << "(";
        left->traverse_infix();
        t.print();
        right->traverse_infix();
        std::cout << ")";
    }
    else
    {
        t.print();
    }
}

std::unique_ptr<Expression> Expression::clone()
{
    std::unique_ptr<Expression> x = std::make_unique<Expression>(t);
    if (t.type == Token::OP_1 || t.type == Token::OP_2)
    {
        // We assume that tokens always have both children
        x->left = left->clone();
        x->right = right->clone();
    }
    return x;
};

std::unique_ptr<Expression> Expression::build(std::vector<Token> &tokens, bool &ok)
{
    std::stack<std::unique_ptr<Expression>> table;
    for (Token t : tokens)
    {
        table.push(std::make_unique<Expression>(t));

        if (t.type == Token::OP_1 || t.type == Token::OP_2)
        {
            std::unique_ptr<Expression> current = std::move(table.top());
            table.pop();

            if (t.v.c == '-')
            {
                if (table.size() == 2)
                {
                    current->right = std::move(table.top());
                    table.pop();
                    current->left = std::move(table.top());
                    table.pop();
                }
                else if (table.size() == 1)
                {
                    // Implicit zero on the right side
                    current->right = std::make_unique<Expression>(Token());
                    current->left = std::move(table.top());
                    table.pop();
                }
                else
                {
                    ok = false;
                    return (current);
                }
            }
            else
            {
                if (table.size() < 2)
                {
                    ok = false;
                    return (current);
                }
                current->right = std::move(table.top());
                table.pop();
                current->left = std::move(table.top());
                table.pop();
            }
            table.push(std::move(current));
        }
    }
    if (table.size() != 1)
        ok = false;
    return std::move(table.top());
};

void Expression::derive()
{
    if (t.type == Token::NUM)
    {
        t.v.d = 0;
    }
    else if (t.type == Token::VAR)
    {
        t.type = Token::NUM;
        t.v.d = 1;
    }
    else if (t.type == Token::OP_2) // +-
    {
        left->derive();
        right->derive();
    }
    else
    {
        std::unique_ptr<Expression> lp = left->clone(), rp = right->clone();
        lp->derive();
        rp->derive();
        std::unique_ptr<Expression> l = std::move(left), r = std::move(right);

        if (t.v.c == '*')
        {
            t.v.c = '+';
            t.type = Token::OP_2;
            left = std::make_unique<Expression>(Token{'*', Token::OP_1});
            right = std::make_unique<Expression>(Token{'*', Token::OP_1});
            left->left = std::move(lp);
            left->right = std::move(r);
            right->left = std::move(rp);
            right->right = std::move(l);
        }
        else if (t.v.c == '/')
        {
            right = std::make_unique<Expression>(Token{'*', Token::OP_1});
            right->left = r->clone();
            right->right = r->clone();

            left = std::make_unique<Expression>(Token{'-', Token::OP_2});
            left->left = std::make_unique<Expression>(Token{'*', Token::OP_1});
            left->right = std::make_unique<Expression>(Token{'*', Token::OP_1});
            left->left->left = std::move(lp);
            left->left->right = std::move(r);
            left->right->left = std::move(l);
            left->right->right = std::move(rp);
        }
    }
}

void Expression::simplify()
{
    if (is_simple())
        return;

    left->simplify();
    right->simplify();

    if (left->is_num(0))
    {
        switch (t.v.c)
        {
        case '-':
            break;
        case '+':
            t = right->t;
            right->swap_children(left, right);
            break;
        case '/':
        case '*':
            t.type = Token::NUM;
            t.v.d = 0;
            break;
        }
    }

    // Simplification with 0
    if (right->is_num(0))
    {
        switch (t.v.c)
        {
        case '-':
            t = left->t;
            right = std::move(left->right);
            left = std::move(left->left);
            break;
        case '+':
            t = left->t;
            right = std::move(left->right);
            left = std::move(left->left);
            break;
        case '/':
            t.type = Token::NUM;
            t.v.d = std::numeric_limits<double>::quiet_NaN();
        case '*':
            // What should the result of NaN*x be?
            t.type = Token::NUM;
            t.v.d = 0;
            break;
        }
    }

    // Simplification with 1
    if (!is_simple())
    {
        if (left->is_num(1) && t.v.c == '*')
        {
            t = right->t;
            right->swap_children(left, right);
        }
        else if (right->is_num(1) && (t.v.c == '*' || t.v.c == '/'))
        {
            t = left->t;
            left->swap_children(left, right);
        }
    }
    else
        return;

    if ((left->t.type != Token::NUM) || (right->t.type != Token::NUM))
        return;

    switch (t.v.c)
    {
    case '+':
        t.v.d = left->t.v.d + right->t.v.d;
        break;
    case '-':
        t.v.d = left->t.v.d - right->t.v.d;
        break;
    case '*':
        t.v.d = left->t.v.d * right->t.v.d;
        break;
    case '/':
        t.v.d = left->t.v.d / right->t.v.d;
        break;
    }
    t.type = Token::NUM;
}