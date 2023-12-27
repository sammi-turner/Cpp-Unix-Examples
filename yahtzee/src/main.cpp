#include "utils.h"
#include "yahtzee.h"

using namespace utils;

int main() 
{
    seed();
    openVirtualTerminal();
    int ch;
    Yahtzee instance;
    bool quitLoop = false;
    while (!quitLoop)
    {
        instance.mainLoop();
        vPuts("\n     Would you like to play again? (y/n) ");
        ch = getch();
        if (ch != 'Y' && ch != 'y')
        {
            quitLoop = true;
        }
    }
    closeVirtualTerminal("\n\n     PRESS ANY KEY TO CLOSE");
}
