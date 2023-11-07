#ifndef UTILS_H
#define UTILS_H

/* System headers */

#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <array>
#include <cmath>

/* Standard namespace */

using std::istringstream;
using std::ostringstream;
using std::to_string;
using std::ios_base;
using std::ofstream;
using std::ifstream;
using std::vector;
using std::string;
using std::array;
using std::cout;
using std::pow;

namespace utils
{
    void seed();
    void virtualCursorOn();
    void virtualCursorOff();
    void virtualKeypressOff();
    void virtualKeypressOn();
    void openVirtualTerminal();
    void shell(string arg);
    void vPuts(string arg);
    void closeVirtualTerminal(string arg);
    void renderMenu(string menu[], int size, int count);
    void renderPrompt(string prompt, string buffer, int pos);
    void fileAppend(string name, string text);
    
    int pseudo(int arg);
    int selectOption(string menu[], int size);
    int fileWrite(string name, string text);
    
    bool isCharLowerCase(char arg);
    bool isCharDigit(char arg);
    bool fileExists(string name);

    string vInput(int arg);
    string fileRead(string name);
    string editPrompt(string prompt, string buffer, int max);
}

#endif