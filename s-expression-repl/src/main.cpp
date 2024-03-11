#include "utils.h"
#include "repl.h"

using namespace repl;

int main()
{
    string s{}, p{}, r{};
    vector<token> stream{};
    cout << "\nWelcome to the S-Expression REPL!\n";
    while (true)
    {
        s = utils::userInput("\n> ");
        if (s == "")
        {
            cout << "\n";
            break;
        }
        stream = tokenise(s);
        p = parse(stream);
        if (p == "valid")
        {
            r = evaluate(stream);
            cout << r << "\n";
        }
        else
        {
            cout << p << "\n";
        }
    }
}
