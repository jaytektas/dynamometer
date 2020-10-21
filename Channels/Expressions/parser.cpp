/**
 * @file parser.h
 *
 * @brief
 * C++ Expression parser. See the header file for more detailed explanation
 *
 * @license
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy
 * of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 *
 * Copyright (C) 2007-2011 Jos de Jong, http://www.speqmath.com
 *
 * The parser is based on the example "A mini C++ Interpreter" from the
 * book "The art of C++" by Herbert Schildt.
 *
 * @author 	Jos de Jong, <wjosdejong@gmail.com>
 * @date	2007-12-22, updated 2012-02-06
 */

// declarations
#include "parser.h"
#include <QDebug>

namespace Dynamometer
{
Parser::~Parser()
{

}

/*
 * constructor.
 * Initializes all data with zeros and empty strings
 */
Parser::Parser(QObject *parent) : QObject (parent)
{
    expr = "";
    e = 0;

    token = "";
    token_type = NOTHING;
}

/**
 * parses and evaluates the given expression
 * On error, an error of type Error is thrown
 */
qreal Parser::parse(QByteArray new_expr, bool evaluation)
{
    p_evaluation = evaluation;

    try
    {
        // check the length of expr
        if (new_expr.length() > EXPR_LEN_MAX)
        {
            throw Error(row(), col(), 200);
        }

        // initialize all variables
        expr = new_expr;  // copy the given expression to expr
        e = 0;                                  // let e point to the start of the expression
        ans = 0;

        getToken();
        if (token_type == DELIMETER && token == "")
        {
            throw Error(row(), col(), 4);
        }

        ans = parse_level1();

        // check for garbage at the end of the expression
        // an expression ends with a character '\0' and token_type = delimeter
        if (token_type != DELIMETER || token != "")
        {
            if (token_type == DELIMETER)
            {
                // user entered a not existing operator like "//"
                throw Error(row(), col(), 101, &token);
            }
            else
            {
                throw Error(row(), col(), 5, &token);
            }
        }

        // add the answer to memory as variable "Ans"
//        user_var.add("Ans", ans);

//        snprintf(ans_str, sizeof(ans_str), "Ans = %g", ans);
    }
    catch (Error err)
    {
        if (err.get_row() == -1)
        {
            qDebug() << ans_str << QString("Error: %1 (col %2)").arg(err.get_msg()).arg(err.get_col());
        }
        else
        {
            qDebug() << ans_str << QString("Row %1 Error: %2 (col %3)").arg(err.get_row()).arg(err.get_msg()).arg(err.get_col());
        }
    }

 //   return ans_str;
    return ans;
}


/*
 * checks if the given char c is a minus
 */
bool Parser::isMinus(const char c)
{
    if (c == 0) return 0;
    return c == '-';
}

/*
 * checks if the given char c is whitespace
 * whitespace when space chr(32) or tab chr(9)
 */
bool Parser::isWhiteSpace(const char c)
{
    if (c == 0) return 0;
    return c == 32 || c == 9;  // space or tab
}

/*
 * checks if the given char c is a delimeter
 * minus is checked apart, can be unary minus
 */
bool Parser::isDelimeter(const char c)
{
    if (c == 0) return 0;
    return strchr("&|<>=+/*%^!", c) != 0;
}

/*
 * checks if the given char c is NO delimeter
 */
bool Parser::isNotDelimeter(const char c)
{
    if (c == 0) return 0;
    return strchr("&|<>=+-/*%^!()", c) != 0;
}

/*
 * checks if the given char c is a letter or undersquare
 */
bool Parser::isAlpha(const char c)
{
    if (c == 0) return 0;
    return strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZ_", toupper(c)) != 0;
}

/*
 * checks if the given char c is a digit or dot
 */
bool Parser::isDigitDot(const char c)
{
    if (c == 0) return 0;
    return strchr("0123456789.", c) != 0;
}

/*
 * checks if the given char c is a digit
 */
bool Parser::isDigit(const char c)
{
    if (c == 0) return 0;
    return strchr("0123456789", c) != 0;
}


/**
 * Get next token in the current string expr.
 * Uses the Parser data expr, e, token, t, token_type and err
 */
void Parser::getToken()
{
int t = 0;

    token_type = NOTHING;
    token = "";         // set token empty

    //printf("\tgetToken e:{%c}, ascii=%i, col=%i\n", *e, *e, e-expr);

    // skip over whitespaces
    while (expr[e] == ' ' || expr[e] == '\t')     // space or tab
    {
        e++;
    }

    // check for end of expression
    if (e >= expr.length())
    {
        // token is still empty
        token_type = DELIMETER;
        return;
    }

    // check for minus
    if (expr[e] == '-')
    {
        token_type = DELIMETER;
        token += expr[e];
        e++;
        t++;
        return;
    }

    // check for parentheses
    if (expr[e] == '(' || expr[e] == ')')
    {
        token_type = DELIMETER;
        token[t] = expr[e];
        e++;
        t++;
        return;
    }

    // check for operators (delimeters)
    if (isDelimeter(expr[e]))
    {
        token_type = DELIMETER;
        while (isDelimeter(expr[e]))
        {
            token[t] = expr[e];
            e++;
            t++;
        }
        return;
    }

    // check for a value
    if (isDigitDot(expr[e]))
    {
        token_type = NUMBER;
        while (isDigitDot(expr[e]))
        {
            token[t] = expr[e];
            e++;
            t++;
        }

        // check for scientific notation like "2.3e-4" or "1.23e50"
        if (toupper(expr[e]) == 'E')
        {
            token[t] = expr[e];
            e++;
            t++;

            if (expr[e] == '+' || expr[e] == '-')
            {
                token[t] = expr[e];
                e++;
                t++;
            }

            while (isDigit(expr[e]))
            {
                token[t] = expr[e];
                e++;
                t++;
            }
        }

        return;
    }

    // check for variables or functions
    if (isAlpha(expr[e]))
    {
        while (isAlpha(expr[e]) || isDigit(expr[e]))
        //while (isNotDelimeter(*e))
        {
            token[t] = expr[e];
            e++;
            t++;
        }

        // check if this is a variable or a function.
        // a function has a parentesis '(' open after the name
        int e2 = 0;
        e2 = e;

        // skip whitespaces
        while (expr[e2] == ' ' || expr[e2] == '\t')     // space or tab
        {
            e2++;
        }

        if (expr[e2] == '(')
        {
            token_type = FUNCTION;
        }
        else
        {
            token_type = VARIABLE;
        }
        return;
    }

    // something unknown is found, wrong characters -> a syntax error
    token_type = UNKNOWN;
    while (e < expr.length())
    {
        token[t] = expr[e];
        e++;
        t++;
    }
    throw Error(row(), col(), 1, &token);

}


/*
 * assignment of variable or function
 */
qreal Parser::parse_level1()
{
    if (token_type == VARIABLE)
    {
        // copy current token
        int e_now = e;
        TOKENTYPE token_type_now = token_type;
        QByteArray token_now;
        token_now = token;

        getToken();
        if (token == "=")
        {
            // assignment
            qreal ans;
            getToken();
            ans = parse_level2();
            if (!Channels->addChannel(token_now, ans, true))
                throw Error(row(), col(), 300);

            return ans;
        }
        else
        {
            // go back to previous token
            e = e_now;
            token_type = token_type_now;
            token = token_now;
        }
    }

    return parse_level2();
}


/*
 * conditional operators and bitshift
 */
qreal Parser::parse_level2()
{
    int op_id;
    qreal ans;
    ans = parse_level3();

    op_id = get_operator_id(token);
    while (op_id == AND || op_id == OR || op_id == BITSHIFTLEFT || op_id == BITSHIFTRIGHT)
    {
        getToken();
        ans = eval_operator(op_id, ans, parse_level3());
        op_id = get_operator_id(token);
    }

    return ans;
}

/*
 * conditional operators
 */
qreal Parser::parse_level3()
{
    int op_id;
    qreal ans;
    ans = parse_level4();

    op_id = get_operator_id(token);
    while (op_id == EQUAL || op_id == UNEQUAL || op_id == SMALLER || op_id == LARGER || op_id == SMALLEREQ || op_id == LARGEREQ)
    {
        getToken();
        ans = eval_operator(op_id, ans, parse_level4());
        op_id = get_operator_id(token);
    }

    return ans;
}

/*
 * add or subtract
 */
qreal Parser::parse_level4()
{
    int op_id;
    qreal ans;
    ans = parse_level5();

    op_id = get_operator_id(token);
    while (op_id == PLUS || op_id == MINUS)
    {
        getToken();
        ans = eval_operator(op_id, ans, parse_level5());
        op_id = get_operator_id(token);
    }

    return ans;
}


/*
 * multiply, divide, modulus, xor
 */
qreal Parser::parse_level5()
{
    int op_id;
    qreal ans;
    ans = parse_level6();

    op_id = get_operator_id(token);
    while (op_id == MULTIPLY || op_id == DIVIDE || op_id == MODULUS || op_id == XOR)
    {
        getToken();
        ans = eval_operator(op_id, ans, parse_level6());
        op_id = get_operator_id(token);
    }

    return ans;
}


/*
 * power
 */
qreal Parser::parse_level6()
{
    int op_id;
    qreal ans;
    ans = parse_level7();

    op_id = get_operator_id(token);
    while (op_id == POW)
    {
        getToken();
        ans = eval_operator(op_id, ans, parse_level7());
        op_id = get_operator_id(token);
    }

    return ans;
}

/*
 * Factorial
 */
qreal Parser::parse_level7()
{
    int op_id;
    qreal ans;
    ans = parse_level8();

    op_id = get_operator_id(token);
    while (op_id == FACTORIAL)
    {
        getToken();
        // factorial does not need a value right from the
        // operator, so zero is filled in.
        ans = eval_operator(op_id, ans, 0.0);
        op_id = get_operator_id(token);
    }

    return ans;
}

/*
 * Unary minus
 */
qreal Parser::parse_level8()
{
    qreal ans;

    int op_id = get_operator_id(token);
    if (op_id == MINUS)
    {
        getToken();
        ans = parse_level9();
        ans = -ans;
    }
    else
    {
        ans = parse_level9();
    }

    return ans;
}


/*
 * functions
 */
qreal Parser::parse_level9()
{
    char fn_name[NAME_LEN_MAX+1];
    qreal ans;

    if (token_type == FUNCTION)
    {
        strcpy(fn_name, token);
        getToken();
        ans = eval_function(fn_name, parse_level10());
    }
    else
    {
        ans = parse_level10();
    }

    return ans;
}


/*
 * parenthesized expression or value
 */
qreal Parser::parse_level10()
{
    // check if it is a parenthesized expression
    if (token_type == DELIMETER)
    {
        if (token == "(")
        {
            getToken();
            qreal ans = parse_level2();
            if (token_type != DELIMETER || token[0] != ')' || token.length() > 1)
            {
                throw Error(row(), col(), 3);
            }
            getToken();
            return ans;
        }
    }

    // if not parenthesized then the expression is a value
    return parse_number();
}


qreal Parser::parse_number()
{
qreal ans = 0;

    switch (token_type)
    {
        case NUMBER:
            // this is a number
            ans = token.toDouble();
            getToken();
            break;

        case VARIABLE:
            // this is a variable
            ans = eval_variable(token);
            getToken();
            break;

        default:
            // syntax error or unexpected end of expression
            if (token == "")
            {
                throw Error(row(), col(), 6);
            }
            else
            {
                throw Error(row(), col(), 7);
            }
            break;
    }

    return ans;
}


/*
 * returns the id of the given operator
 * treturns -1 if the operator is not recognized
 */
int Parser::get_operator_id(QByteArray op_name)
{
    // level 2
    if (op_name == "&") {return AND;}
    if (op_name == "|") {return OR;}
    if (op_name == "<<") {return BITSHIFTLEFT;}
    if (op_name == ">>") {return BITSHIFTRIGHT;}

    // level 3
    if (op_name == "=") { return EQUAL; }
    if (op_name == "<>") { return UNEQUAL; }
    if (op_name == "<") { return SMALLER; }
    if (op_name == ">") { return LARGER; }
    if (op_name == "<=") { return SMALLEREQ; }
    if (op_name == ">=") { return LARGEREQ; }

    // level 4
    if (op_name == "+") { return PLUS; }
    if (op_name == "-") { return MINUS; }

    // level 5
    if (op_name == "*") { return MULTIPLY; }
    if (op_name == "/") { return DIVIDE; }
    if (op_name == "%") { return MODULUS; }
    if (op_name == "||") { return XOR; }

    // level 6
    if (op_name == "^") {return POW; }

    // level 7
    if (op_name == "!") {return FACTORIAL; }

    return -1;
}


/*
 * evaluate an operator for given valuess
 */
qreal Parser::eval_operator(int op_id, const qreal &lhs, const qreal &rhs)
{
    switch (op_id)
    {
        // level 2
        case AND:           return static_cast<int>(lhs) & static_cast<int>(rhs);
        case OR:            return static_cast<int>(lhs) | static_cast<int>(rhs);
        case BITSHIFTLEFT:  return static_cast<int>(lhs) << static_cast<int>(rhs);
        case BITSHIFTRIGHT: return static_cast<int>(lhs) >> static_cast<int>(rhs);

        // level 3
        case EQUAL:     return lhs == rhs;
        case UNEQUAL:   return lhs != rhs;
        case SMALLER:   return lhs < rhs;
        case LARGER:    return lhs > rhs;
        case SMALLEREQ: return lhs <= rhs;
        case LARGEREQ:  return lhs >= rhs;

        // level 4
        case PLUS:      return lhs + rhs;
        case MINUS:     return lhs - rhs;

        // level 5
        case MULTIPLY:  return lhs * rhs;
        case DIVIDE:    return lhs / rhs;
        case MODULUS:   return static_cast<int>(lhs) % static_cast<int>(rhs); // todo: give a warning if the values are not integer?
        case XOR:       return static_cast<int>(lhs) ^ static_cast<int>(rhs);

        // level 6
        case POW:       return pow(lhs, rhs);

        // level 7
        case FACTORIAL: return factorial(lhs);
    }

    throw Error(row(), col(), 104, op_id);
    return 0;
}


/*
 * evaluate a function
 */
qreal Parser::eval_function(QByteArray fn_name, const qreal &value)
{
    try
    {
        // first make the function name upper case
        QByteArray fnU;
        fnU = fn_name.toUpper();

        // arithmetic
        if (fnU == "ABS") { return abs(value); }
        if (fnU == "EXP") { return exp(value); }
        if (fnU == "SIGN") { return sign(value); }
        if (fnU == "SQRT") { return sqrt(value); }
        if (fnU == "LOG") { return log(value); }
        if (fnU =="LOG10") { return log10(value); }

        // trigonometric
        if (fnU == "SIN") { return sin(value); }
        if (fnU == "COS") { return cos(value); }
        if (fnU == "TAN") { return tan(value); }
        if (fnU == "ASIN") { return asin(value); }
        if (fnU == "ACOS") { return acos(value); }
        if (fnU == "ATAN") { return atan(value); }

        // probability
        if (fnU == "FACTORIAL") { return factorial(value); }

        // interpolate
        if (fnU == "INTERPOLATE")
            return -1;
    }
    catch (Error err)
    {
        // retrow error, add information about column and row of occurance
        // TODO: doesnt work yet
        throw Error(col(), row(), err.get_id(), err.get_msg());
    }

    // unknown function
    throw Error(row(), col(), 102, &fn_name);
    return 0;
}


/*
 * evaluate a variable
 */
qreal Parser::eval_variable(QByteArray var_name)
{
    // first make the variable name uppercase
    QByteArray varU;
    varU = var_name.toUpper();

    // check for built-in variables
    if (varU == "E") { return 2.7182818284590452353602874713527; }
    if (varU == "PI") { return 3.1415926535897932384626433832795; }

    // check for user defined variables
    return Channels->getChannel(var_name)->getValue(p_evaluation);
}


/*
 * Shortcut for getting the current row value (one based)
 * Returns the line of the currently handled expression
 */
int Parser::row()
{
    return -1;
}

/*
 * Shortcut for getting the current col value (one based)
 * Returns the column (position) where the last token starts
 */
int Parser::col()
{
    return expr.length() - e - token.length() + 1;
}
}
