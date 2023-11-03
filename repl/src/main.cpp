#include "utils.h"
#include "parser.h"

using namespace parser;

int main()
{
    cout << "\n";
    vector<string> t0 = tokenStream("(/ (* 3 -2) (- 4 1))");
    for (string s : t0)
    {
        cout << s << "\n";
    }
    vector<string> t1 = tokenTypeStream(t0);
    cout << "\n";
    for (string s : t1)
    {
        cout << s << "\n";
    }
    cout << "\n";
}