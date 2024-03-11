#include "utils.h"
#include "repl.h"

using namespace utils;
using repl::token;

string repl::padParens(const string arg)
{
    string result{};
    for (char c : arg)
    {
        if (c == '(')
        {
            result += " ( ";
        }
        else if (c == ')')
        {
            result += " ) ";
        }
        else
        {
            result += c;
        }
    }
    return result;
}

bool repl::isFunction(const string arg)
{
    vector<string> v = {"add", "sub", "mul", "div", "mod", "pow"};
    return stringPosition(arg, v) > -1;
}

vector<token> repl::tokenise(const string arg)
{
    token t{};
    vector<token> result{};
    string p = padParens(arg);
    vector<string> v0 = splitStringBySpace(p);
    vector<string> v1 = removeEmptyStrings(v0);
    for (string s : v1)
    {
        t.value = s;
        if (s == "(")
        {
            t.type = "OPEN"; 
        }
        else if (s == ")")
        {
            t.type = "CLOSE"; 
        }
        else if (isFunction(s))
        {
            t.type = "FUNC";
        }
        else if (isInt(s) || isFloat(s))
        {
            t.type = "NUMBER";
        }
        else
        {
            t.type = "ILLEGAL";
        }
        result.push_back(t);
    }
    return result;
}

string repl::parse(const vector<token> arg)
{
    int openParen = 0;
    int size = arg.size();
    vector<string> expected = {"OPEN"};
    for (int i = 0; i < size; i++)
    {
        if (stringPosition(arg[i].type, expected) == -1)
        {
            return ("Unexpected token '" + arg[i].value + "' at position " + std::to_string(i) + ".");
        }
        else if (arg[i].type == "OPEN")
        {
            openParen++;
            expected = {"FUNC"};
        }
        else if (arg[i].type == "CLOSE")
        {
            openParen--;
            expected = {"OPEN", "NUMBER"};
            if (openParen > 0)
            {
                expected.push_back("CLOSE");
            }
        }
        else if (arg[i].type == "NUMBER")
        {
            expected = {"NUMBER", "OPEN"};
            if (openParen > 0)
            {
                expected.push_back("CLOSE");
            }
        }
        else 
        {
            expected = {"OPEN", "NUMBER"};
        }
    }
    return "valid";
}

string repl::evaluate(const vector<token> arg)
{
    vector<string> funcs{};
    vector<string> operands{};
    for (token t : arg)
    {
        if (t.type == "FUNC")
        {
            funcs.push_back(t.value);
        }
        if (t.type == "NUMBER")
        {
            operands.push_back(t.value);
        }
        if (t.type == "CLOSE")
        {
            float n0{}, n1{}, n2{};
            if (funcs.empty())
            {
                return "Parse error : too many operands.";
            }
            if (operands.size() < 2)
            {
                return "Parse error : too few operands.";
            }
            string f = funcs.back();
            funcs.pop_back();
            n0 = toFloat(operands.back());
            operands.pop_back();
            n1 = toFloat(operands.back());
            operands.pop_back();
            if (f == "add")
            {
                n2 = n0 + n1;
            }
            if (f == "sub")
            {
                n2 = n1 - n0;
            }
            if (f == "mul")
            {
                n2 = n0 * n1;
            }
            if (f == "div")
            {
                n2 = n1 / n0;
            }
            if (f == "mod")
            {
                n2 = (int)n1 % (int)n0;
            }
            if (f == "pow")
            {
                n2 = pow(n1, n0);
            }
            operands.push_back(std::to_string(n2));
        }
    }
    if (!funcs.empty())
    {
        return "Parse error : too few operands.";
    }
    if (operands.size() > 1)
    {
        return "Parse error : too many operands.";
    }
    if (isMantissaZero(operands[0]))
    {
        int r = toInt(operands[0]);
        return std::to_string(r);
    }
    return truncateExcessZeros(operands[0]);
}