#include "utils.h"
#include "lexer.h"

bool lexer::isDelim(string s)
{
    return
    (
        s == "(" ||
        s == ")" ||
        s == ","
    );
}

bool lexer::isBuiltin(string s)
{
    return
    (
        s == "add" ||
        s == "sub" ||
        s == "mul" ||
        s == "pow" ||
        s == "div" ||
        s == "mod" ||
        s == "min" ||
        s == "max"
    );
}

string lexer::padDelims(string s)
{
    string r = "";
    for (char c : s)
    {
        if (c == '(')
        {
            r += " ( ";
        }
        else if (c == ')')
        {
            r += " ) ";
        }
        else if (c == ',')
        {
            r += " , ";
        }
        else
        {
            r += c;
        }
    }
    return r;
}

string lexer::checkToken(string s)
{
    if (isBuiltin(s) || isDelim(s) || isInt(s))
    {
        return "Valid";
    }
    else
    {
        return "Invalid token: " + s;
    }
}