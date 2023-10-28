#include "utils.h"
#include "list-edit.h"

using namespace utils;

int main()
{
    openVirtualTerminal();
    curs_set(0);
    ListEdit instance;
    instance.mainLoop();
    closeVirtualTerminal("\n    PRESS ANY KEY TO CLOSE");
}
