#ifndef UTILS_H
#define UTILS_H

/* System headers */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

/* Standard namespace */

using std::ostringstream;
using std::to_string;
using std::getline;
using std::ios_base;
using std::ofstream;
using std::ifstream;
using std::string;
using std::cout;
using std::cin;

namespace utils
{   
    string userInput();

    bool isCharDigit(char arg);
    bool isPosInt(string arg);
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