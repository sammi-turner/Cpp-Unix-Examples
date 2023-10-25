#ifndef PARSER_H
#define PARSER_H

using namespace utils;

namespace parser
{
    bool isInfixOperator(string s);
    bool isBuiltin(string s);
    vector<string> splitByDelimiter(string s, char d);
    vector<string> removeEmptyStrings(vector<string> v);
    vector<string> splitBySpace(string s);
    vector<string> splitByNewLine(string s);
    string padParens(string s);
    string checkToken(string s);
}

#endif