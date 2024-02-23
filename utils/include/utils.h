#ifndef UTILS_H
#define UTILS_H

/* System headers */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>

/* Shorthands */

using std::string;
using std::vector;
using std::cout;

namespace utils
{   
    string userInput(const string arg);
    string trimmedUserInput(const string arg);
    string trimWhiteSpace(const string arg);

    void shell(const string arg);
    int pseudo(const int arg);
    void seed();

    bool isCharDigit(const char arg);
    bool isCharHexDigit(const char arg);
    bool isCharAlphaNumeric(const char arg);

    bool isCharLetter(const char arg);
    bool isCharLowerCase(const char arg);
    bool isCharUpperCase(const char arg);

    bool isCharPunct(const char arg);
    bool isCharWhiteSpace(const char arg);
    bool isCharGraphical(const char arg);

    bool isLowerCase(const string arg);
    bool isUpperCase(const string arg);
    bool isAlphabetic(const string arg);

    bool isPosInt(const string arg);
    bool isNegInt(const string arg);

    bool isInt(const string arg);
    bool isFloat(const string arg);

    bool isMantissaZero(const string arg);
    string truncateExcessZeros(const string arg);

    int toInt(const string arg);
    float toFloat(const string arg);

    bool fileExists(const string name);
    int fileWrite(const string name, const string text);
    void fileAppend(const string name, const string text);

    string fileRead(const string name);
    void fileDelete(const string arg);

    int charCount(const string arg, const char ch);
    string replaceChar(const string arg, const char oldChar, const char newChar);
    bool isSubString(const string arg1, const string arg2);

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
    string insertWordAt(const string arg, const string ins, const int num);
    string insertLineAt(const string arg, const string ins, const int num);

    string replaceSliceAt(const string arg, const string ins, const char delim, const int num);
    string replaceWordAt(const string arg, const string ins, const int num);
    string replaceLineAt(const string arg, const string ins, const int num);

    void appendVectorToFile(const string fileName, const vector<string> v);
    int stringPosition(const string arg, const vector<string> v);

    vector<string> splitStringByChar(const string arg, const char delim);
    vector<string> splitStringBySpace(const string arg);
    vector<string> splitStringByNewline(const string arg);

    vector<string> removeEmptyStrings(const vector<string> arg);
    vector<string> concatStringVectors(const vector<string> arg1, const vector<string> arg2);
    vector<string> reverseStringVector(const vector<string> arg);
}

#endif
