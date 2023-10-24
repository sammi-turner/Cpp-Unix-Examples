#include "utils.h"
#include "parser.h"

using namespace parser;

int main()
{
    string word0 = "abcde";
    string word1 = "01234";
    string word2 = "-13";
    cout << isTerm(word0) << " " << isTerm(word1) << " " << isTerm(word2) << "\n";
}