#ifndef PARSER_H
#define PARSER_H

using namespace utils;

namespace parser
{
    bool isInfixOperator(string s);
    bool isBuiltin(string s);
    vector<string> splitBySpace(string s);
    string padParens(string s);
}

#endif