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
        return "valid token: " + s;
    }
    else
    {
        return "invalid token: " + s;
    }
}

string lexer::runLexer(string s)
{
    string str = padDelims(s);
    vector<string> vec = splitBySpace(str);
    int vs = vec.size();
    string ct;
    int n = 0;
    while (n < vs)
    {
        ct = checkToken(vec[n]);
        if (ct[0] == 'i')
        {
            return ct;
        } 
        n++;
    }
    return "all tokens valid";
}