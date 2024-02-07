#include "utils.h"

using namespace utils;

int main()
{
    cout << "What's your full name? ";
    string name = trimmedUserInput();
    cout << "Hello " << name << ", its nice to meet you!\n";
}
