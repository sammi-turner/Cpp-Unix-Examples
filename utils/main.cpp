#include "utils.h"

using namespace utils;

int main()
{
    openVirtualTerminal();
    string s = fileRead("test.txt");
    vPuts(s);
    closeVirtualTerminal("\n\nPRESS ANY KEY TO CLOSE");
}
