# Ncurses Template

An ncurses project template for MacOS and Linux.

<br>

## To build

From the root directory, enter

```
make
```

<br>

## Useful shell aliases

To run the binary.

```
alias run='./bin/main'
```

To build and run the binary.

```
alias mar='make && ./bin/main'
```
<br>

## Source files

.cpp files go in the src directory.

<br>

## Header files

.h files go in the include directory.

Don't forget to use [include guards](https://en.wikipedia.org/wiki/Include_guard) on all headers.

<br>

## List editor

This app implements basic [CRUD operations](https://en.wikipedia.org/wiki/Create,_read,_update_and_delete) on lists, in addition to 'swap', 'copy', 'cut', 'paste', 'insert', 'load', 'save', and 'exit'.

To return to the main menu, simply enter a blank input.

<br>

## Yahtzee

A solitaire, command line version of the [famous dice game](https://en.wikipedia.org/wiki/Yahtzee).

<br>

## Sorting functions

```
int compareInts(const void* a, const void* b)
```

This function is used as a parameter for another function in this library (sortIntArray).

```
void sortIntArray(int* arr, int size)
```

Sorts an array of integers (arr) of a given size (size).

<br>

## Shell commands

```
void shell(string arg)
```

Executes the shell command specified by a string (arg).

<br>

## Pseudo random numbers

```
void seed()
```

Seeds the pseudo random number generator.

```
int pseudo(int arg)
```

Returns either 0, or a pseudo random number from 1 to an integer value (arg).

<br>

## Virtual terminal session

```
void openVirtualTerminal()
```

Opens a virtual terminal session.

```
void closeVirtualTerminal(string arg)
```

Displays a string (arg) within the virtual terminal session, then closes the session after the next keypress.

<br>

## Virtual cursor

```
void virtualCursorOff()
```

Turns the cursor off within a virtual terminal session.

```
void virtualCursorOn()
```

Turns the cursor on within a virtual terminal session.

<br>

## Virtual keypress

```
void virtualKeypressOff()
```

Sets keypresses to not display, within a virtual terminal session.

```
void virtualKeypressOn()
```

Sets keypresses to display, within a virtual terminal session.

<br>

## Virtual rows and columns

```
int virtualRows()
```

Returns the number of rows in a virtual terminal session.

```
int virtualColumns()
```

Returns the number of columns in a virtual terminal session.

<br>

## Virtual strings

```
string vInput(int arg)
```

Returns user input up to a maximum number of characters (arg).

```
void vPuts(string arg)
```

Prints a string (arg), within a virtual terminal session.

<br>

## Virtual menus

```
void renderMenu(string menu[], int size, int count)
```

This is a helper function, used by another function in this namespace (selectOption).

```
int selectOption(string menu[], int size)
```

Within a virtual terminal session, this function returns an integer based on the user selecting an option from an on-screen menu specified by an array of strings (menu), of a specified size (size).

<br>

## Virtual prompt

```
void renderPrompt(string prompt, string buffer, int pos)
```

This is a helper function, used by another function in this namespace (editPrompt).

```
string editPrompt(string prompt, string buffer, int max)
```

Within a virtual terminal session, this function displays a specified prompt (prompt), and an initial buffer (buffer) which may be edited by the user.

When the buffer reaches a maximum size (max) or the return key is pressed, the new buffer is written to a string (result).

<br>

## Identifying chars

```
bool isCharDigit(char arg)
```

Returns true if a char (arg) is a digit, or false, if it is not.

```
bool isCharHexDigit(char arg)
```

Returns true if a char (arg) is a hex digit, or false, if it is not.

```
bool isCharAlphaNumeric(char arg)
```

Returns true if a char (arg) is alphanumeric, or false, if it is not.

```
bool isCharLetter(char arg)
```

Returns true if a char (arg) is a letter, or false, if it is not.

```
bool isCharLowerCase(char arg)
```

Returns true if a char (arg) is a lower case letter, or false, if it is not.

```
bool isCharUpperCase(char arg)
```

Returns true if a char (arg) is an upper case letter, or false, if it is not.

```
bool isCharPunct(char arg)
```

Returns true if a char (arg) is a punctuation mark, or false, if it is not.

```
bool isCharWhiteSpace(char arg)
```

Returns true if a char (arg) is a non-graphical character, or false, if it is not.

```
bool isCharGraphical(char arg)
```

Returns true if a char (arg) is a graphical character, or false, if it is not.

<br>

## Identifying strings

```
bool isLowerCase(string arg)
```

Returns true if a string (arg) is all lower case letters, or false, if it is not.

```
bool isUpperCase(string arg)
```

Returns true if a string (arg) is all upper case letters, or false, if it is not.

```
bool isAlphabetic(string arg)
```

Returns true if a string (arg) is all alphabetic characters, or false, if it is not.

```
bool isPosInt(string arg)
```

Returns true if a string (arg) denotes a positive integer, or false, if it does not.

```
bool isNegInt(string arg)
```

Returns true if a string (arg) denotes a negative integer, or false, if it does not.

```
bool isInt(string arg)
```

Returns true if a string (arg) denotes an integer, or false, if it does not.

```
bool isFloat(string arg)
```

Returns true if a string (arg) denotes a floating point number, or false, if it does not.

<br>

## Conversion to string

```
int toInt(string arg)
```

Returns either zero, or the integer obtained by converting a string (arg).

```
float toFloat(string arg)
```

Returns either a float, or the integer obtained by converting a string (arg).

<br>

## File IO

```
bool fileExists(string name)
```

Returns either false, or true if a string (name) matches the name of a file in the working directory.

```
int fileWrite(string name, string text)
```

Writes a string (text), to a file named by another string (name). Returns 1 if the file write fails, or 0 if it suceeds.

```
void fileAppend(string name, string text)
```

Appends a string (text), to a file named by another string (name).

```
string fileRead(string name)
```

Returns either the empty string, or the contents of the file in the working directory named by a string (name).

```
void fileDelete(string arg)
```

Deletes a file in the working directory named by a string (arg).

<br>

## String manipulation

```
int charCount(string arg, char ch)
```

Returns the number of chars in a string (arg) that are equal to a char (ch).

```
string replaceChar(string arg, char oldChar, char newChar);
```

Returns the string obtained by replacing every instance of a character (oldChar), with another character (newChar) in a string (arg).

```
string trimWhiteSpace(string arg)
```

Returns the string obtained by removing redundant whitespace in another string (arg).

```
string substitute(string arg, string x, string y)
```

Returns the string obtained by replacing every occurence of one string (x), with another string (y), in a third string (arg).

<br>

## String comparison

```
bool isMember(string arg, string* arr, int arrSize)
```

Returns either false, or true if a string (arg), occurs in an array of strings (arr), of a given size (arrSize).

```
bool isSubString(string arg1, string arg2)
```

Returns either false, or true if a string (arg1), is contained in another string (arg2).

<br>

## Nth slices

```
string nthSlice(string arg, char delim, int num)
```

Returns the nth slice (num) in a string (arg) that is sliced by a given delimiter (delim).

```
string nthWord(string arg, int num)
```

Returns the nth slice (num) in a string (arg) where the space character is the delimiter.

```
string nthLine(string arg, int num)
```

Returns the nth slice (num) in a string (arg) where the newline character is the delimiter.

<br>

## First slices

```
string firstSlice(string arg, char delim)
```

Returns the first slice in a string (arg) that is sliced by a given delimiter (delim).

```
string firstWord(string arg)
```

Returns the first slice in a string (arg) where the space character is the delimiter.

```
string firstLine(string arg)
```

Returns the first slice in a string (arg) where the newline character is the delimiter.

<br>

## Other slices

```
string otherSlices(string arg, char delim)
```

Returns all slices after the first in a string (arg) that is sliced by a given delimiter (delim).

```
string otherWords(string arg)
```

Returns all slices after the first in a string (arg) where the space character is the delimiter.

```
string otherLines(string arg)
```

Returns all slices after the first in a string (arg) where the newline character is the delimiter.

<br>

## Slice counts

```
int sliceCount(string arg, char delim)
```

Returns the number of slices in a string (arg) that is sliced by a given delimiter (delim).

```
int wordCount(string arg)
```

Returns the number of slices in a string (arg) where the space character is the delimiter.

```
int lineCount(string arg)
```

Returns the number of slices in a string (arg) where the newline character is the delimiter.

<br>

## Removing slices

```
string removeNthSlice(string arg, char delim, int num)
```

Returns the result of removing the nth slice (num), from a string (arg), that is delimited by a specific char (delim).

```
string removeNthWord(string arg, int num)
```

Returns the result of removing the nth slice (num), from a string (arg), where the space character is the delimiter.

```
string removeNthLine(string arg, int num)
```

Returns the result of removing the nth slice (num), from a string (arg), where the newline character is the delimiter.

```
string removeLastSlice(string arg, char delim)
```

Returns the result of removing the last slice, from a string (arg), that is delimited by a specific char (delim).

```
string removeLastWord(string arg)
```

Returns the result of removing the last slice from a string (arg), where the space character is the delimiter.

```
string removeLastLine(string arg)
```

Returns the result of removing the last slice from a string (arg), where the newline character is the delimiter.

<br>

## Inserting slices

```
string insertSliceAt(string arg, string ins, char delim, int num)
```

Returns the result of inserting a string (ins) into another string (arg), as the nth slice (num), where the delimiter is a given
char (delim).

```
string insertWordAt(string arg, string ins, int num)
```

Returns the result of inserting a string (ins) into another string (arg), as the nth slice (num), where the space character is the delimiter.

```
string insertLineAt(string arg, string ins, int num)
```

Returns the result of inserting a string (ins) into another string (arg), as the nth slice (num), where the newline character is the delimiter.

<br>

## Replacing slices

```
string replaceSliceAt(string arg, string ins, char delim, int num)
```

Returns the result of inserting a string (ins) into another string (arg), as the nth slice (num), where the delimiter is a given char (delim).

```
string replaceWordAt(string arg, string ins, int num)
```

Returns the result of inserting a string (ins) into another string (arg), as the nth slice (num), where the space character is the delimiter.

```
string replaceLineAt(string arg, string ins, int num)
```

Returns the result of inserting a string (ins) into another string (arg), as the nth slice (num), where the newline character is the delimiter.

<br>

## Vectors

```
bool readFileIntoVector(string fileName, vector<string> & vec)
```

Reads a file in the working directory named by a string (fileName), into a vector of strings (vec). Returns true if the operation was successful, or false if it was not.

```
void appendVectorToFile(string fileName, vector<string> vec)
```

Appends a vector of strings (vec), to a file in the working directory named by a string (fileName).

```
int stringPosition(string arg, vector<string> vec)
```

Returns the position of a string (arg) in a vector of strings (vec), or 0 if it was not found.
