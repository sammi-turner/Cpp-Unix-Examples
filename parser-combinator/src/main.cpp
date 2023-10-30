#include "utils.h"
#include "lexer.h"

using namespace lexer;

int main()
{
    string str = padDelims("div mod pow mul min max");
    vector<string> vec = splitBySpace(str);
    for (string word : vec)
    {
        cout << checkToken(word) << '\n';
    }
}