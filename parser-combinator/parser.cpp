#include "utils.h"
#include "parser.h"

using namespace utils;

bool parser::isLowerCaseWord(string s) 
{
    for (char c : s) 
    {
        if (c < 'a' || c > 'z') 
        {
            return false;
        }
    }
    return !s.empty();
}

bool parser::isTerm(string s)
{
    return isLowerCaseWord(s) || isInt(s);
}