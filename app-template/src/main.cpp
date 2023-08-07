#include "utils.h"

using namespace utils;

int main()
{
    openVirtualTerminal();
    string yourName = editPrompt("What is your name? ", "", 15);
    string result = "\n\nNice to meet you " + yourName + "\n\n";
    vPuts(result);
    closeVirtualTerminal("PRESS ANY KEY TO CLOSE");
}
