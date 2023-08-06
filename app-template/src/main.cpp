#include "utils.h"

using namespace utils;

int main()
{
    openVirtualTerminal();
    string your_name = editPrompt("What is your name? ", "", 15);
    string result = "\n\nNice to meet you " + your_name + "\n\n";
    vPuts(result);
    closeVirtualTerminal("PRESS ANY KEY TO CLOSE");
}
