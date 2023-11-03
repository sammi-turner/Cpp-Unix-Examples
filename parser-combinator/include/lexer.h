#ifndef LEXER_H
#define LEXER_H

using namespace utils;

namespace lexer
{
    bool isParen(string s);
    bool isOperator(string s);
    string padParens(string s);
    string runLexer(string s);
    array<string, 2> checkToken(string s);
}

#endif