#include "boilerplate.h"

using namespace bp;

int main()
{
    openVirtualTerminal();
    vPuts("Hello, world!\n\n");
    closeVirtualTerminal("PRESS ANY KEY TO CLOSE");
}
