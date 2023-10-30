#ifndef LEXER_H
#define LEXER_H

using namespace utils;

namespace lexer
{
    bool isDelim(string s);
    bool isBuiltin(string s);
    string padDelims(string s);
    string checkToken(string s);
}

#endif