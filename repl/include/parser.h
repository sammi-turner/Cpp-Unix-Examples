#ifndef PARSER_H
#define PARSER_H

using namespace utils;

namespace parser
{
    bool isParen(string s);
    bool isOperator(string s);
    string padParens(string s);
    string runLexer(string s);
    array<string, 2> checkToken(string s);
    vector<string> tokenStream(string s);
}

#endif