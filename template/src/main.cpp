#include "utils.h"

using namespace utils;

int main() 
{
    string name = userInput("Hello, what is your name? ");
    cout << format("Welcome to C++20 {}!\n", name);
}
