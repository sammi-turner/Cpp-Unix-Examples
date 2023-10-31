#include "utils.h"
#include "lexer.h"

using namespace lexer;

int main()
{
    string str = runLexer("div(mul(3, 2), sub(4, 1))");
    cout << str << "\n";
}