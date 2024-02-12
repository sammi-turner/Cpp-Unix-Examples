#include "utils.h"

using namespace utils;

int main()
{
    string sentence = "Mary had a little lamb.";
    int words = wordCount(sentence);
    vector<string> v = splitStringBySpace(sentence);
    for (int i = 0; i < words; i++)
    {
        cout << v[i] << "\n";
    }
}
