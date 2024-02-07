#include "utils.h"

using namespace utils;

int main()
{
    cout << "What's your full name? ";
    string name = userInput();
    cout << "Hello " << name << "\n";
}
