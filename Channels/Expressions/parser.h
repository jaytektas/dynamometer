/**
 * @file parser.h
 *
 * @brief
 * C++ Expression parser
 *
 * Features:
 *     Operators:
 *         & | << >>
 *         = <> < > <= >=
 *         + -
 *         * / % ||
 *         ^
 *         !
 *
 *     Functions:
 *         Abs, Exp, Sign, Sqrt, Log, Log10
 *         Sin, Cos, Tan, ASin, ACos, ATan
 *         Factorial
 *
 *     Variables:
 *         Pi, e
 *         you can define your own variables
 *
 *     Other:
 *        Scientific notation supported
 *         Error handling supported
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



#ifndef PARSER_H
#define PARSER_H

// declarations
#include "constants.h"
#include "error.h"
#include "functions.h"
#include "channellist.h"

using namespace std;

namespace Dynamometer
{
class Parser : public QObject
{
    Q_OBJECT

    enum TOKENTYPE { NOTHING = -1, DELIMETER, NUMBER, VARIABLE, FUNCTION, UNKNOWN };

    enum OPERATOR_ID { AND, OR, BITSHIFTLEFT, BITSHIFTRIGHT,            // level 2
               EQUAL, UNEQUAL, SMALLER, LARGER, SMALLEREQ, LARGEREQ,    // level 3
               PLUS, MINUS,                     // level 4
               MULTIPLY, DIVIDE, MODULUS, XOR,  // level 5
               POW,                             // level 6
               FACTORIAL };                     // level 7
public:
    Parser(QObject *parent = nullptr);
    ~Parser();

    qreal parse(QByteArray expr, bool evaluation = false);

private:
    bool isMinus(const char c);
    bool isWhiteSpace(const char c);
    bool isDelimeter(const char c);
    bool isNotDelimeter(const char c);
    bool isAlpha(const char c);
    bool isDigitDot(const char c);
    bool isDigit(const char c);

    void getToken();

    qreal parse_level1();
    qreal parse_level2();
    qreal parse_level3();
    qreal parse_level4();
    qreal parse_level5();
    qreal parse_level6();
    qreal parse_level7();
    qreal parse_level8();
    qreal parse_level9();
    qreal parse_level10();
    qreal parse_number();

    int get_operator_id(QByteArray op_name);
    qreal eval_operator(int op_id, const qreal &lhs, const qreal &rhs);
    qreal eval_function(QByteArray fn_name, const qreal &value);
    qreal eval_variable(QByteArray var_name);

    int row();
    int col();

    QByteArray expr;              // holds the expression
    int e;                      // points to a character in expr

    QByteArray token;   // holds the token
    TOKENTYPE token_type;         // type of the token

    qreal ans;                   // holds the result of the expression
    QByteArray ans_str;            // holds a string containing the result

    bool p_evaluation = false;
};
}

#endif
