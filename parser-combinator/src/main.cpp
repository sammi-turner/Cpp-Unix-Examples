#include "utils.h"
#include "lexer.h"

using namespace lexer;

int main()
{
    string s0 = padParens("(/ (* 3 -2) (- 4 1))");
    string s1 = runLexer(s0);
    cout << s0 << "\n" << s1 << "\n"; 
}