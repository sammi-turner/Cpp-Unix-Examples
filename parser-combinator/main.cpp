#include "utils.h"
#include "parser.h"

using namespace parser;

int main()
{
    string word0 = "abcde";
    string word1 = "abc13";
    cout << isLowerCaseWord(word0) << " " << isLowerCaseWord(word1) << "\n";
}