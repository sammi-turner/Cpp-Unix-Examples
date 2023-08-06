#ifndef BACKSPACE 
#define BACKSPACE 128
#endif

#ifndef UTILS_H
#define UTILS_H

/* System headers */

#include <ncurses.h>
#include <csignal>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <climits>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

/* Standard namespace */

using std::ostringstream;
using std::istringstream;
using std::noskipws;
using std::to_string;
using std::ios_base;
using std::ofstream;
using std::ifstream;
using std::string;
using std::system;
using std::cout;
using std::cerr;
using std::vector;
using std::unordered_map;
using std::make_pair;

namespace utils
{
    int compareInts(const void* a, const void* b);
    void sortIntArray(int* arr, int size);
    
    void shell(string arg);
    void seed();
    int pseudo(int arg);

    void openVirtualTerminal();
    void closeVirtualTerminal(string arg);

    void virtualCursorOff();
    void virtualCursorOn();

    void virtualKeypressOff();
    void virtualKeypressOn();

    int virtualRows();
    int virtualColumns();

    string vInput(int arg);
    void vPuts(string arg);

    void renderMenu(string menu[], int size, int count);
    int selectOption(string menu[], int size);

    void renderPrompt(string prompt, string buffer, int pos);
    string editPrompt(string prompt, string buffer, int max);

    bool isCharDigit(char arg);
    bool isCharHexDigit(char arg);

    bool isCharAlphaNumeric(char arg);
    bool isCharLetter(char arg);
    bool isCharLowerCase(char arg);

    bool isCharUpperCase(char arg);
    bool isCharPunct(char arg);
    bool isCharWhiteSpace(char arg);
    
    bool isCharGraphical(char arg);
    bool isLowerCase(string arg);

    bool isUpperCase(string arg);
    bool isAlphabetic(string arg);

    bool isPosInt(string arg);
    bool isNegInt(string arg);

    bool isInt(string arg);
    bool isFloat(string arg);

    int toInt(string arg);
    float toFloat(string arg);

    bool fileExists(string name);
    int fileWrite(string name, string text);
    void fileAppend(string name, string text);

    string fileRead(string name);
    void fileDelete(string arg);

    int charCount(string arg, char ch);
    string replaceChar(string arg, char oldChar, char newChar);

    bool isMember(string arg, string* arr, int arrSize);
    bool isSubString(string arg1, string arg2);

    string firstSlice(string arg, char delim);
    string firstWord(string arg);
    string firstLine(string arg);

    string otherSlices(string arg, char delim);
    string otherWords(string arg);
    string otherLines(string arg);

    int sliceCount(string arg, char delim);
    int wordCount(string arg);
    int lineCount(string arg);

    string trimWhiteSpace(string arg);
    string substitute(string arg, string x, string y);

    string nthSlice(string arg, char delim, int num);
    string nthWord(string arg, int num);
    string nthLine(string arg, int num);

    string removeNthSlice(string arg, char delim, int num);
    string removeNthWord(string arg, int num);
    string removeNthLine(string arg, int num);
    
    string removeLastWord(string arg);
    string removeLastLine(string arg);
    string removeLastSlice(string arg, char delim);

    string insertSliceAt(string arg, string ins, char delim, int num);
    string insertWordAt(string arg, string ins, int num);
    string insertLineAt(string arg, string ins, int num);

    string replaceSliceAt(string arg, string ins, char delim, int num);
    string replaceWordAt(string arg, string ins, int num);
    string replaceLineAt(string arg, string ins, int num);

    bool readFileIntoVector(string fileName, vector<string> & vec);
    void appendVectorToFile(string fileName, vector<string> vec);
    int stringPosition(string arg, vector<string> vec);
}

#endif
