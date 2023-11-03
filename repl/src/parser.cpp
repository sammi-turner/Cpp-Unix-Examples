#include "utils.h"
#include "parser.h"

bool parser::isPosInt(string arg)
{
    int size = arg.length();
    if (size == 0 || arg[0] == '0')
    {
        return false;
    }
    for (int i = 0; i < size; i++)
    {
        if (!isCharDigit(arg[i]))
        {
            return false;
        }
    }
    return true;
}

bool parser::isNegInt(string arg)
{
    int size = arg.length();
    if (size < 2 || arg[0] != '-')
    {
        return false;
    }
    string s = arg.erase(0, 1);
    return isPosInt(s);
}

bool parser::isInt(string arg)
{
    return isPosInt(arg) || arg == "0" || isNegInt(arg);
}

int parser::toInt(string arg)
{
    return std::stoi(arg);
}

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

vector<string> parser::tokenStream(string s)
{
    string p = padParens(s);
    return splitBySpace(p);
}

vector<string> parser::tokenTypeStream(vector<string> v)
{
    vector<string> types;
    for (string s : v)
    {
        if (isInt(s))
        {
            types.push_back("integer");
        }
        else if (isParen(s))
        {
            types.push_back("paren");
        }
        else if (isOperator(s))
        {
            types.push_back("operator");
        }
        else
        {
            types.push_back("invalid");
        }
    }
    return types;
}