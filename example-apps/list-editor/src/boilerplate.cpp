#include "boilerplate.h"

int bp::compareInts(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

void bp::sortIntArray(int* arr, int size)
{
    qsort(arr, size, sizeof(int), compareInts);
}

void bp::shell(string arg)
{
    int num = arg.length() + 1;
    char* arr = new char[num];
    strcpy(arr, arg.c_str());
    system(arr);
    delete[] arr;
}

void bp::seed() 
{
    srand((int)time(0));
}

int bp::pseudo(int arg) 
{
    int result = 0;
    if (arg > 1) 
        result = (rand() % arg) + 1;
    return result;
}

void bp::openVirtualTerminal() 
{
    initscr();
    signal(SIGWINCH, NULL);
    scrollok(stdscr, TRUE);
    keypad(stdscr, TRUE);
}

void bp::closeVirtualTerminal(string arg) 
{
    vPuts(arg);
    getch();
    endwin();
}

void bp::virtualCursorOff() 
{
    curs_set(0);
}

void bp::virtualCursorOn() 
{
    curs_set(1);
}

void bp::virtualKeypressOff() 
{
    noecho();
}

void bp::virtualKeypressOn() 
{
    echo();
}

int bp::virtualRows() 
{
    int row;
    int col;
    getmaxyx(stdscr, row, col);
    return row;
}

int bp::virtualColumns() 
{
    int row;
    int col;
    getmaxyx(stdscr, row, col);
    return col;
}

string bp::vInput(int arg) 
{
    char cstring[arg + 1];
    getnstr(cstring, arg);
    return string(cstring);
}

void bp::vPuts(string arg) 
{
    int num = arg.length();
    char arr[num + 1];
    strcpy(arr, arg.c_str());
    printw(arr);
    refresh();
}

void bp::renderMenu(string menu[], int size, int count) 
{
    clear();
    string s = "\n    " + menu[0] + "\n\n";
    for (int i = 1; i < size; i++) 
    {
        if (i == count) 
            s += "  > " + menu[i] + "\n";
        else 
            s += "    " + menu[i] + "\n";
    };
    vPuts(s);
}

int bp::selectOption(string menu[], int size) 
{
    virtualCursorOff();
    
    int value = 1;
    int keyPress;
    
    do 
    {
        renderMenu(menu, size, value);
        keyPress = getch();
        switch(keyPress) 
        {
            case KEY_DOWN:
                value++;
                if (value == size) 
                    value = 1;
                renderMenu(menu, size, value);
                break;

            case KEY_UP:
                value--;
                if (value == 0) 
                    value = (size - 1);
                renderMenu(menu, size, value);
            default:
                break;
        }
    }
    while (keyPress != '\n');

    return value;
}

void bp::renderPrompt(string prompt, string buffer, int pos)
{
    clear();
    string s = prompt;
    for (int i = 0; i < pos; i++)
        s += buffer[i];
    vPuts(s);
}

string bp::editPrompt(string prompt, string buffer, int max)
{
    int ch;
    int exit = 0;
    
    string result = buffer;

    int pos = buffer.length();
    int res = pos;

    renderPrompt(prompt, result, pos);

    while (!exit && pos < max)
    {
        ch = getch();

        if (ch == KEY_LEFT && pos > 0)
            pos--;

        if (ch == KEY_RIGHT && res > pos)
            pos++;

        if (ch == KEY_BACKSPACE && pos > 0)
        {
            pos--;
            res--;
            result.erase(pos, 1);
        }

        else if (ch > 31 && ch < 127)
        {
            if (pos < res)
            {
                result[pos] = ch;
                pos++;
            }
            else
            {
                result += ch;
                pos++;
                res++;
            }
        }

        else if (ch == 10)
            exit = 1;

        renderPrompt(prompt, result, pos);
    }

    return result;
}

bool bp::isCharDigit(char arg)
{
    return (isdigit(arg) > 0);
}

bool bp::isCharHexDigit(char arg)
{
    return (isxdigit(arg) > 0);
}

bool bp::isCharAlphaNumeric(char arg)
{
    return (isalnum(arg) > 0);
}

bool bp::isCharLetter(char arg)
{
    return (isalpha(arg) > 0);
}

bool bp::isCharLowerCase(char arg)
{
    return (islower(arg) > 0);
}

bool bp::isCharUpperCase(char arg)
{
    return (isupper(arg) > 0);
}

bool bp::isCharPunct(char arg)
{
    return (ispunct(arg) > 0);
}

bool bp::isCharWhiteSpace(char arg)
{
    return (isspace(arg) > 0);
}

bool bp::isCharGraphical(char arg)
{
    return (isgraph(arg) > 0);
}

bool bp::isLowerCase(string arg)
{
    bool result = true;
    int size = arg.length();
    for (int i = 0; i < size; i++)
    {
        if (!isCharLowerCase(arg[i]))
            result = false;
    }
    return result;
}

bool bp::isUpperCase(string arg)
{
    bool result = true;
    int size = arg.length();
    for (int i = 0; i < size; i++)
    {
        if (!isCharUpperCase(arg[i]))
            result = false;
    }
    return result;
}

bool bp::isAlphabetic(string arg)
{
    bool result = true;
    int size = arg.length();
    for (int i = 0; i < size; i++)
    {
        if (!isCharLowerCase(arg[i]) && !isCharUpperCase(arg[i]))
            result = false;
    }
    return result;
}

bool bp::isPosInt(string arg)
{
    bool result = true;
    int size = arg.length();
    if (!isCharDigit(arg[0]) || arg[0] == '0')
        result = false;

    for (int i = 1; i < size; i++)
    {
        if (!isCharDigit(arg[i]))
            result = false;
    }
    return result;
}

bool bp::isNegInt(string arg)
{
    bool result = true;
    int size = arg.length();
    if (arg[0] != '-')
        result = false;

    if (!isCharDigit(arg[1]) || arg[1] == '0')
        result = false;

    for (int i = 2; i < size; i++)
    {
        if (!isCharDigit(arg[i]))
            result = false;
    }
    return result;
}

bool bp::isInt(string arg)
{
    return (arg == "0" || isPosInt(arg) || isNegInt(arg));
}

bool bp::isFloat(string arg)
{
    float f;
    istringstream iss(arg);
    iss >> noskipws >> f;
    return iss.eof() && !iss.fail();
}

int bp::toInt(string arg)
{
    return std::stoi(arg);
}

float bp::toFloat(string arg)
{
    return std::stof(arg);
}

bool bp::fileExists(string name)
{
    bool value = false;
    ifstream f(name);
    if (f)
        value = true;
    return value;
}

int bp::fileWrite(string name, string text)
{
    ofstream myfile;
    myfile.open(name);
    if (myfile.is_open())
    {
        myfile << text;
        myfile.close();
        return 0;
    }
    else
        return 1;
}

void bp::fileAppend(string name, string text)
{
    ofstream outfile;
    outfile.open(name, ios_base::app);
    outfile << text;
}

string bp::fileRead(string name)
{
    ifstream f(name);
    string value;
    if(f) 
    {
        ostringstream ss;
        ss << f.rdbuf();
        value = ss.str();
    }
    return value;
}


void bp::fileDelete(string arg)
{
    int len = arg.length() + 1;
    char* arr = new char[len];
    char* fileName = new char[len];
    for (int i = 0; i < len; i++)
        fileName[i] = arg[i];

    remove(fileName);
    delete[] arr;
    delete[] fileName;
}

int bp::charCount(string arg, char ch)
{
    int count = 0;
    int len = arg.length();

    for (int i = 0; i < len; i++)
    {
        if (arg[i] == ch)
            count++;
    }
    return count;
}

string bp::replaceChar(string arg, char oldChar, char newChar)
{
    int len = arg.length();
    string result = arg;

    for (int i = 0; i < len; i++)
    {
        if (arg[i] == oldChar)
            result[i] = newChar;
    }
    return result;
}

bool bp::isMember(string arg, string* arr, int arrSize)
{
    bool value = false;
    for (int i = 0; i < arrSize; i++)
    {
        if (arg == arr[i])
            value = true;
    }
    return value;
}

bool bp::isSubString(string arg1, string arg2)
{
    bool value;
    if (arg2.find(arg1) != string::npos)
        value = true;
    else
        value = false;
    return value;
}

string bp::firstSlice(string arg, char delim)
{
    string result = arg;
    while (result[0] == delim)
        result = result.substr(1, result.length());

    int index = result.find(delim);
    result = result.substr(0, index);
    return result;
}

string bp::firstWord(string arg)
{
    return firstSlice(arg, ' ');
}

string bp::firstLine(string arg)
{
    return firstSlice(arg, '\n');
}

string bp::otherSlices(string arg, char delim)
{
    string result = arg;
    while (result[0] == delim)
        result = result.substr(1, result.length());

    int index = result.find(delim);
    result = result.substr((index + 1), result.length());

    return result;
}

string bp::otherWords(string arg)
{
    return otherSlices(arg, ' ');
}

string bp::otherLines(string arg)
{
    return otherSlices(arg, '\n');
}

int bp::sliceCount(string arg, char delim)
{
    string first = firstSlice(arg, delim);
    string final = otherSlices(arg, delim);
    int count = 0;

    while (first != final)
    {
        count++;
        first = firstSlice(final, delim);
        final = otherSlices(final, delim);
    }

    count += (final != "");
    return count;
}

int bp::wordCount(string arg)
{
    return sliceCount(arg, ' ');
}

int bp::lineCount(string arg)
{
    return sliceCount(arg, '\n');
}

string bp::trimWhiteSpace(string arg)
{
    string dest = "";
    string src = arg;
    int words = sliceCount(arg, ' ');

    int count = 1;
    while (count < words)
    {
        dest += firstSlice(src, ' ');
        dest += " ";
        src = otherSlices(src, ' ');
        count++;
    }

    dest += firstSlice(src, ' ');
    return dest;
}

string bp::substitute(string arg, string x, string y)
{
    size_t pos;
    int len = x.length();
    while ((pos = arg.find(x)) != string::npos)
        arg.replace(pos, len, y);
    return arg;
}

string bp::nthSlice(string arg, char delim, int num)
{
    string trim = trimWhiteSpace(arg);
    int count = 1;

    while (count < num)
    {
        count++;
        trim = otherSlices(trim, delim);
    }

    return firstSlice(trim, delim);
}

string bp::nthWord(string arg, int num)
{
    return nthSlice(arg, ' ', num);
}

string bp::nthLine(string arg, int num)
{
    return nthSlice(arg, '\n', num);
}

string bp::removeNthSlice(string arg, char delim, int num)
{
    string trim = trimWhiteSpace(arg);
    string result = "";
    int max = sliceCount(arg, delim);

    for (int i = 1; i <= num; i++)
    {
        if (i < num)
        {
            result += firstSlice(trim, delim) + delim;
            trim = otherSlices(trim, delim);
        }
        else
            trim = otherSlices(trim, delim);
    }

    if (num < max)
        result += trim;

    return result;
}

string bp::removeNthWord(string arg, int num)
{
    return removeNthSlice(arg, ' ', num);
}

string bp::removeNthLine(string arg, int num)
{
    return removeNthSlice(arg, '\n', num);
}

string bp::removeLastWord(string arg)
{
    int num = sliceCount(arg, ' ');
    return removeNthSlice(arg, ' ', num);
}

string bp::removeLastLine(string arg)
{
    int num = sliceCount(arg, '\n');
    return removeNthSlice(arg, '\n', num);
}

string bp::removeLastSlice(string arg, char delim)
{
    int num = sliceCount(arg, delim);
    return removeNthSlice(arg, delim, num);
}

string bp::insertSliceAt(string arg, string ins, char delim, int num)
{
    string trim = trimWhiteSpace(arg);
    string result;
    int count = 1;

    while (count < num)
    {
        count++;
        result += firstSlice(trim, delim);
        result += delim;
        trim = otherSlices(trim, delim);
    }

    return (result + ins + delim + trim);
}

string bp::insertWordAt(string arg, string ins, int num)
{
    return insertSliceAt(arg, ins, ' ', num);
}

string bp::insertLineAt(string arg, string ins, int num)
{
    return insertSliceAt(arg, ins, '\n', num);
}

string bp::replaceSliceAt(string arg, string ins, char delim, int num)
{
    string start = insertSliceAt(arg, ins, delim, num);
    string value = removeNthSlice(start, delim, (num + 1));
    return value;
}

string bp::replaceWordAt(string arg, string ins, int num)
{
    string start = insertSliceAt(arg, ins, ' ', num);
    string value = removeNthSlice(start, ' ', (num + 1));
    return value;
}

string bp::replaceLineAt(string arg, string ins, int num)
{
    string start = insertSliceAt(arg, ins, '\n', num);
    string value = removeNthSlice(start, '\n', (num + 1));
    return value;
}

bool bp::readFileIntoVector(string fileName, vector<string> & vec)
{
    ifstream in(fileName.c_str());
    if (!in)
    {
        cerr << "Cannot open " << fileName << " in the working directory.\n";
        return false;
    }

    string s;
    while (getline(in, s))
    {
        if (s.size() > 0)
            vec.push_back(s);
    }
    in.close();
    return true;
}

void bp::appendVectorToFile(string fileName, vector<string> vec)
{
    string current = "";
    int len = vec.size();
    for (int i = 0; i < len; i++)
    {
        current = vec[i] + "\n";
        fileAppend(fileName, current);
    }
}

int bp::stringPosition(string arg, vector<string> vec)
{
    int value = -1;
    int len = vec.size();
    for (int i = 0; i < len; i++)
    {
        if (arg == vec[i])
            value = i; 
    }
    return value;
}
