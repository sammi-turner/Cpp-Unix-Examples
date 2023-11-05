#ifndef PARSER_H
#define PARSER_H

using namespace utils;

namespace parser
{
    bool isPosInt(string arg);
    bool isNegInt(string arg);
    bool isInt(string arg);
    int toInt(string arg);

    bool isParen(string s);
    bool isOperator(string s);
    string padParens(string s);

    vector<string> removeEmptyStrings(vector<string> v);
    vector<string> splitByDelimiter(string s, char d);
    vector<string> splitByNewLine(string s);
    vector<string> splitBySpace(string s);
    vector<string> tokenStream(string s);

    bool hasOuterParens(vector<string> v);
    bool isAtomicList(vector<string> v);
    vector<string> removeOuterTokens(vector<string> v);
}

#endif