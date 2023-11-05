#include "utils.h"
#include "parser.h"

using namespace parser;

int main()
{
    cout << "\n";
    vector<string> t0 = tokenStream("(* 3 -2)");
    vector<string> t1 = removeOuterTokens(t0);
    cout << isAtomicList(t1) << "\n\n";
}