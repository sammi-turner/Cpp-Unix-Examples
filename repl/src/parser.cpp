#include "utils.h"
#include "parser.h"

bool parser::isParen(string s)
{
    return (s == "(" || s == ")");
}

bool parser::isOperator(string s)
{
    return
    (
        s == "+" ||
        s == "-" ||
        s == "*" ||
        s == "/"
    );
}

string parser::padParens(string s)
{
    string r = "";
    for (char c : s)
    {
        if (c == '(')
        {
            r += "( ";
        }
        else if (c == ')')
        {
            r += " )";
        }
        else
        {
            r += c;
        }
    }
    return r;
}

array<string, 2> parser::checkToken(string s)
{
    if (isOperator(s))
    {
        return {"operator", s};
    }
    else if (isParen(s))
    {
        return {"paren", s};
    }
    else if (isInt(s))
    {
        return {"integer", s};
    }
    else
    {
        return {"invalid", s};
    }
}

string parser::runLexer(string s)
{
    string str = padParens(s);
    vector<string> vec = splitBySpace(str);
    int vs = vec.size();
    array<string, 2> a;
    int n = 0;
    while (n < vs)
    {
        a = checkToken(vec[n]);
        if (a[0] == "invalid")
        {
            return "invalid token: " + a[1];
        } 
        n++;
    }
    return "all tokens valid";
}

// vector<string> parser::tokenStream(string s)
// {

// }