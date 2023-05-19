#include "boilerplate.h"
#include "list-edit.h"

using namespace utils;

int main()
{
    openVirtualTerminal();
    virtualCursorOff();

    ListEdit instance;
    instance.mainLoop();

    closeVirtualTerminal("\n    PRESS ANY KEY TO CLOSE");
}
