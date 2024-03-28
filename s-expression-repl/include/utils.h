#ifndef UTILS_H
#define UTILS_H

/* System headers */

#include <iostream>
#include <fstream>
#include <sstream>
#include <format>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>

/* Shorthands */

using std::format;
using std::string;
using std::vector;
using std::cout;

namespace utils
{   
    string userInput(const string arg);
    string trimmedUserInput(const string arg);
    string trimWhiteSpace(const string arg);

    void shell(const string arg);

    bool isCharDigit(const char arg);
    bool isCharLetter(const char arg);
    bool isCharLowerCase(const char arg);
    bool isInt(const string arg);
    bool isFloat(const string arg);

    bool isMantissaZero(const string arg);
    string truncateExcessZeros(const string arg);

    int toInt(const string arg);
    float toFloat(const string arg);

    string fileRead(const string name);
    string firstSlice(const string arg, const char delim);
    string firstWord(const string arg);
    string firstLine(const string arg);

    string otherSlices(const string arg, const char delim);
    string otherWords(const string arg);
    string otherLines(const string arg);

    int sliceCount(const string arg, const char delim);
    int wordCount(const string arg);
    int lineCount(const string arg);

    string nthSlice(const string arg, const char delim, const int num);
    string nthWord(const string arg, const int num);
    string nthLine(const string arg, const int num);

    string removeNthSlice(const string arg, const char delim, const int num);
    string removeNthWord(const string arg, const int num);
    string removeNthLine(const string arg, const int num);

    string removeLastSlice(const string arg, const char delim);
    string removeLastWord(const string arg);
    string removeLastLine(const string arg);

    string insertSliceAt(const string arg, const string ins, const char delim, const int num);
    string replaceSliceAt(const string arg, const string ins, const char delim, const int num);
    
    int stringPosition(const string arg, const vector<string> v);
    vector<string> splitStringBySpace(const string arg);
    vector<string> removeEmptyStrings(const vector<string> arg);
}

#endif