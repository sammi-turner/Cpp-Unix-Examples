#include "utils.h"

using namespace utils;

int main()
{
    string sentence = "Mary had a little lamb";
    vector<string> v = splitStringBySpace(sentence);
    for (string s : v)
    {
        cout << s << "\n";
    }
    cout << "\nThe word 'lamb' is at index " << stringPosition("lamb", v) << "\n";
}
