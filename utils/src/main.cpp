#include "utils.h"

using namespace utils;

int main()
{
    int n;
    string s;
    while(true)
    {
        cout << "\n> ";
        s = userInput();
        if (isPosInt(s))
        {
            cout << "Positive.\n";
        }
        else if (isNegInt(s))
        {
            cout << "Negative.\n";
        }
        else if (isInt(s))
        {
            cout << "Zero.\n";
        }
        else 
        {
            break;
        }
    }
}
