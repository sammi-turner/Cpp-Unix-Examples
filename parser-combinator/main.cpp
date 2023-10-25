#include "utils.h"
#include "parser.h"

using namespace parser;

int main()
{
    string s0 = padParens("2(r7) - 5(8)");
    vector<string> sentence = splitBySpace(s0);
    for (string word : sentence) 
    {
        cout << word << '\n';
    }
}