#include "utils.h"

using namespace utils;

int main()
{
    string sentence = "Mary had a little lamb";
    vector<string> v = splitStringBySpace(sentence);
    int words = wordCount(sentence);
    for (int i = 0; i < words; i++)
    {
        cout << v[i] << "\n";
    }
    cout << "\nThe word 'lamb' is at index " << stringPosition("lamb", v) << "\n";
}
