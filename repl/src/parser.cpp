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

bool parser::isRightParen(string arg)
{
    return (arg == ")");
}

bool parser::isOperator(string arg)
{
    return
    (
        arg == "(^" ||
        arg == "(*" ||
        arg == "(/" ||
        arg == "(+" ||
        arg == "(-"
    );
}

string parser::padRightParens(string arg)
{
    string r = "";
    for (char c : arg)
    {
        if (c == ')')
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

string parser::joinStrings(vector<string> v, string d)
{
    int max = v.size();
    if (max == 0)
    {
        return "";
    }
    if (max == 1)
    {
        return v[0];
    }
    string result = v[0];
    for (int i = 1; i < max; i++)
    {
        result += d;
        result += v[i]; 
    }
    return result;
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

vector<string> parser::splitBySpace(string arg) 
{
    vector<string> v;
    istringstream iss(arg);
    string line;
    while (getline(iss, line, ' ')) 
    {
        v.push_back(line);
    }
    return removeEmptyStrings(v);
}

vector<string> parser::tokenStream(string arg)
{
    string p = padRightParens(arg);
    return splitBySpace(p);
}