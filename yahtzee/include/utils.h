#ifndef UTILS_H
#define UTILS_H

/* System headers */

#include <ncurses.h>
#include <fstream>
#include <string>

/* Standard namespace */

using std::to_string;
using std::ios_base;
using std::ofstream;
using std::string;

namespace utils
{
    void seed();
    int pseudo(int arg);

    void openVirtualTerminal();
    void closeVirtualTerminal(string arg);

    void virtualCursorOff();
    void virtualKeypressOff();
    void virtualKeypressOn();

    string vInput(int arg);
    void vPuts(string arg);

    bool isCharDigit(char arg);
    bool isPosInt(string arg);

    int toInt(string arg);
    void fileAppend(string name, string text);
}

#endif
