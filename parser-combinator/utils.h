#ifndef UTILS_H
#define UTILS_H

/* System headers */

#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

/* Standard namespace */

using std::istringstream;
using std::ostringstream;
using std::to_string;
using std::ios_base;
using std::ofstream;
using std::ifstream;
using std::vector;
using std::string;
using std::cout;

namespace utils
{
    void seed();
    int pseudo(int arg);
    
    void openVirtualTerminal();
    void closeVirtualTerminal(string arg);

    void virtualCursorOn();
    void virtualCursorOff();
    
    void virtualKeypressOff();
    void virtualKeypressOn();
    
    void vPuts(string arg);
    void renderMenu(string menu[], int size, int count);
    void renderPrompt(string prompt, string buffer, int pos);
    
    string vInput(int arg);
    string editPrompt(string prompt, string buffer, int max);
    int selectOption(string menu[], int size);
    
    bool isCharLowerCase(char arg);
    bool isCharDigit(char arg);

    bool isPosInt(string arg);
    bool isNegInt(string arg);
    bool isInt(string arg);
    int toInt(string arg);

    bool fileExists(string name);
    int fileWrite(string name, string text);
    void fileAppend(string name, string text);

    string fileRead(string name);
    string firstSlice(string arg, char delim);
    string otherSlices(string arg, char delim);

    int sliceCount(string arg, char delim);
    int lineCount(string arg);

    string trimWhiteSpace(string arg);
    string nthSlice(string arg, char delim, int num);
    string nthLine(string arg, int num);

    string removeNthSlice(string arg, char delim, int num);
    string removeNthLine(string arg, int num);

    string insertSliceAt(string arg, string ins, char delim, int num);
    string insertLineAt(string arg, string ins, int num);
}

#endif