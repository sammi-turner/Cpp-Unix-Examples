#include "boilerplate.h"
#include "list-edit.h"

using namespace bp;

int main()
{
    openVirtualTerminal();
    virtualCursorOff();

    ListEdit instance;
    instance.mainLoop();

    closeVirtualTerminal("\n    PRESS ANY KEY TO CLOSE");
}
