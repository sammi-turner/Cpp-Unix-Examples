#include "utils.h"
#include "parser.h"

using namespace parser;

int main()
{
    string str = padParens("Mary**had**a**little**lamb");
    vector<string> vec = splitByDelimiter(str, '*');
    for (string word : vec)
    {
        cout << checkToken(word) << '\n';
    }
}