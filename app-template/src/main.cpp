#include "utils.h"

using namespace utils;

int main()
{
    openVirtualTerminal();
    vPuts("Hello, world!\n\n");
    closeVirtualTerminal("PRESS ANY KEY TO CLOSE");
}
