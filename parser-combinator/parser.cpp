#include "utils.h"
#include "parser.h"

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