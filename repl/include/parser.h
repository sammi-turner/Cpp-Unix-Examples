#ifndef PARSER_H
#define PARSER_H

using namespace utils;

namespace parser
{
    int toInt(string arg);

    bool isPosInt(string arg);
    bool isNegInt(string arg);
    bool isInt(string arg);
    bool isRightParen(string arg);
    bool isOperator(string arg);

    string padRightParens(string arg);
    string joinStrings(vector<string> v, string d);

    vector<string> removeEmptyStrings(vector<string> v);
    vector<string> splitBySpace(string arg);
    vector<string> tokenStream(string arg);
}

#endif