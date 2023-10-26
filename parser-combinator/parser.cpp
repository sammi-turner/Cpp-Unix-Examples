#include "utils.h"
#include "parser.h"

bool parser::isInfixOperator(string s) 
{
    return (s == "+" || s == "-");
}

bool parser::isBuiltin(string s)
{
    return
    (
        s == "mul" ||
        s == "pow" ||
        s == "div" ||
        s == "mod" ||
        s == "min" ||
        s == "max"
    );
}

string parser::padParens(string s)
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
        else
        {
            r += c;
        }
    }
    return r;
}

string parser::checkToken(string s)
{
    if (isInfixOperator(s) || isBuiltin(s) || isInt(s))
    {
        return "Valid";
    }
    else
    {
        return "Invalid token: " + s;
    }
}