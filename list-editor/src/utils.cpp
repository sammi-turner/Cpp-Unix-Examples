#include "utils.h"

int utils::compareInts(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

void utils::sortIntArray(int* arr, int size)
{
    qsort(arr, size, sizeof(int), compareInts);
}

void utils::shell(string arg)
{
    int num = arg.length() + 1;
    char* arr = new char[num];
    strcpy(arr, arg.c_str());
    system(arr);
    delete[] arr;
}

void utils::seed() 
{
    srand((int)time(0));
}

int utils::pseudo(int arg) 
{
    int result = 0;
    if (arg > 1) 
        result = (rand() % arg) + 1;
    return result;
}

void utils::openVirtualTerminal() 
{
    initscr();
    signal(SIGWINCH, NULL);
    scrollok(stdscr, TRUE);
    keypad(stdscr, TRUE);
}

void utils::closeVirtualTerminal(string arg) 
{
    vPuts(arg);
    getch();
    endwin();
}

void utils::virtualCursorOff() 
{
    curs_set(0);
}

void utils::virtualCursorOn() 
{
    curs_set(1);
}

void utils::virtualKeypressOff() 
{
    noecho();
}

void utils::virtualKeypressOn() 
{
    echo();
}

int utils::virtualRows() 
{
    int row;
    int col;
    getmaxyx(stdscr, row, col);
    return row;
}

int utils::virtualColumns() 
{
    int row;
    int col;
    getmaxyx(stdscr, row, col);
    return col;
}

string utils::vInput(int arg) 
{
    char cstring[arg + 1];
    getnstr(cstring, arg);
    return string(cstring);
}

void utils::vPuts(string arg) 
{
    int num = arg.length();
    char arr[num + 1];
    strcpy(arr, arg.c_str());
    printw(arr);
    refresh();
}

void utils::renderMenu(string menu[], int size, int count) 
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

int utils::selectOption(string menu[], int size) 
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

void utils::renderPrompt(string prompt, string buffer, int pos)
{
    clear();
    string s = prompt;
    for (int i = 0; i < pos; i++)
        s += buffer[i];
    vPuts(s);
}

string utils::editPrompt(string prompt, string buffer, int max)
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

bool utils::isCharDigit(char arg)
{
    return (isdigit(arg) > 0);
}

bool utils::isCharHexDigit(char arg)
{
    return (isxdigit(arg) > 0);
}

bool utils::isCharAlphaNumeric(char arg)
{
    return (isalnum(arg) > 0);
}

bool utils::isCharLetter(char arg)
{
    return (isalpha(arg) > 0);
}

bool utils::isCharLowerCase(char arg)
{
    return (islower(arg) > 0);
}

bool utils::isCharUpperCase(char arg)
{
    return (isupper(arg) > 0);
}

bool utils::isCharPunct(char arg)
{
    return (ispunct(arg) > 0);
}

bool utils::isCharWhiteSpace(char arg)
{
    return (isspace(arg) > 0);
}

bool utils::isCharGraphical(char arg)
{
    return (isgraph(arg) > 0);
}

bool utils::isLowerCase(string arg)
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

bool utils::isUpperCase(string arg)
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

bool utils::isAlphabetic(string arg)
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

bool utils::isPosInt(string arg)
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

bool utils::isNegInt(string arg)
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

bool utils::isInt(string arg)
{
    return (arg == "0" || isPosInt(arg) || isNegInt(arg));
}

bool utils::isFloat(string arg)
{
    float f;
    istringstream iss(arg);
    iss >> noskipws >> f;
    return iss.eof() && !iss.fail();
}

int utils::toInt(string arg)
{
    return std::stoi(arg);
}

float utils::toFloat(string arg)
{
    return std::stof(arg);
}

bool utils::fileExists(string name)
{
    bool value = false;
    ifstream f(name);
    if (f)
        value = true;
    return value;
}

int utils::fileWrite(string name, string text)
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

void utils::fileAppend(string name, string text)
{
    ofstream outfile;
    outfile.open(name, ios_base::app);
    outfile << text;
}

string utils::fileRead(string name)
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


void utils::fileDelete(string arg)
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

int utils::charCount(string arg, char ch)
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

string utils::replaceChar(string arg, char oldChar, char newChar)
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

bool utils::isMember(string arg, string* arr, int arrSize)
{
    bool value = false;
    for (int i = 0; i < arrSize; i++)
    {
        if (arg == arr[i])
            value = true;
    }
    return value;
}

bool utils::isSubString(string arg1, string arg2)
{
    bool value;
    if (arg2.find(arg1) != string::npos)
        value = true;
    else
        value = false;
    return value;
}

string utils::firstSlice(string arg, char delim)
{
    string result = arg;
    while (result[0] == delim)
        result = result.substr(1, result.length());

    int index = result.find(delim);
    result = result.substr(0, index);
    return result;
}

string utils::firstWord(string arg)
{
    return firstSlice(arg, ' ');
}

string utils::firstLine(string arg)
{
    return firstSlice(arg, '\n');
}

string utils::otherSlices(string arg, char delim)
{
    string result = arg;
    while (result[0] == delim)
        result = result.substr(1, result.length());

    int index = result.find(delim);
    result = result.substr((index + 1), result.length());

    return result;
}

string utils::otherWords(string arg)
{
    return otherSlices(arg, ' ');
}

string utils::otherLines(string arg)
{
    return otherSlices(arg, '\n');
}

int utils::sliceCount(string arg, char delim)
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

int utils::wordCount(string arg)
{
    return sliceCount(arg, ' ');
}

int utils::lineCount(string arg)
{
    return sliceCount(arg, '\n');
}

string utils::trimWhiteSpace(string arg)
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

string utils::substitute(string arg, string x, string y)
{
    size_t pos;
    int len = x.length();
    while ((pos = arg.find(x)) != string::npos)
        arg.replace(pos, len, y);
    return arg;
}

string utils::nthSlice(string arg, char delim, int num)
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

string utils::nthWord(string arg, int num)
{
    return nthSlice(arg, ' ', num);
}

string utils::nthLine(string arg, int num)
{
    return nthSlice(arg, '\n', num);
}

string utils::removeNthSlice(string arg, char delim, int num)
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

string utils::removeNthWord(string arg, int num)
{
    return removeNthSlice(arg, ' ', num);
}

string utils::removeNthLine(string arg, int num)
{
    return removeNthSlice(arg, '\n', num);
}

string utils::removeLastWord(string arg)
{
    int num = sliceCount(arg, ' ');
    return removeNthSlice(arg, ' ', num);
}

string utils::removeLastLine(string arg)
{
    int num = sliceCount(arg, '\n');
    return removeNthSlice(arg, '\n', num);
}

string utils::removeLastSlice(string arg, char delim)
{
    int num = sliceCount(arg, delim);
    return removeNthSlice(arg, delim, num);
}

string utils::insertSliceAt(string arg, string ins, char delim, int num)
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

string utils::insertWordAt(string arg, string ins, int num)
{
    return insertSliceAt(arg, ins, ' ', num);
}

string utils::insertLineAt(string arg, string ins, int num)
{
    return insertSliceAt(arg, ins, '\n', num);
}

string utils::replaceSliceAt(string arg, string ins, char delim, int num)
{
    string start = insertSliceAt(arg, ins, delim, num);
    string value = removeNthSlice(start, delim, (num + 1));
    return value;
}

string utils::replaceWordAt(string arg, string ins, int num)
{
    string start = insertSliceAt(arg, ins, ' ', num);
    string value = removeNthSlice(start, ' ', (num + 1));
    return value;
}

string utils::replaceLineAt(string arg, string ins, int num)
{
    string start = insertSliceAt(arg, ins, '\n', num);
    string value = removeNthSlice(start, '\n', (num + 1));
    return value;
}

bool utils::readFileIntoVector(string fileName, vector<string> & vec)
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

void utils::appendVectorToFile(string fileName, vector<string> vec)
{
    string current = "";
    int len = vec.size();
    for (int i = 0; i < len; i++)
    {
        current = vec[i] + "\n";
        fileAppend(fileName, current);
    }
}

int utils::stringPosition(string arg, vector<string> vec)
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
