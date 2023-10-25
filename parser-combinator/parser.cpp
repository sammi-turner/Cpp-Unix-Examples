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

vector<string> parser::removeEmptyStrings(vector<string> v)
{
    vector<string> r;
    for (string s : v)
    {
        if (s != "")
        {
            r.push_back(s);
        }
    }
    return r;
}

vector<string> parser::splitByDelimiter(string s, char d)
{
    vector<string> v;
    istringstream iss(s);
    string line;
    while (getline(iss, line, d))
    {
        v.push_back(line);
    }
    return removeEmptyStrings(v);
}

vector<string> parser::splitBySpace(string s) 
{
    vector<string> v;
    istringstream iss(s);
    string line;
    while (getline(iss, line, ' ')) 
    {
        v.push_back(line);
    }
    return removeEmptyStrings(v);
}

vector<string> parser::splitByNewLine(string s) 
{
    vector<string> v;
    istringstream iss(s);
    string line;
    while (getline(iss, line, '\n')) 
    {
        v.push_back(line);
    }
    return removeEmptyStrings(v);
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