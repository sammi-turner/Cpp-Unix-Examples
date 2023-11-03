#include "utils.h"
#include "parser.h"

using namespace parser;

int main()
{
    string s0 = padParens("(/ (* 3 -2) (- 4 1))");
    string s1 = runLexer(s0);
    cout << "\n" << s0 << "\n" << s1 << "\n"; 
}