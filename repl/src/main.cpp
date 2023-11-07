#include "utils.h"
#include "parser.h"

using namespace parser;

int main()
{
    cout << "\n";
    vector<string> t0 = tokenStream("(^ (+ 2 (* 5 3)))");
    string j = joinStrings(t0, " ");
    cout << j << "\n\n";
}