#include "utils.h"

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

        if ((ch == KEY_BACKSPACE || ch == 127 || ch == '\b') && pos > 0)
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

int utils::toInt(string arg)
{
    return std::stoi(arg);
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

string utils::firstSlice(string arg, char delim)
{
    string result = arg;
    while (result[0] == delim)
        result = result.substr(1, result.length());

    int index = result.find(delim);
    result = result.substr(0, index);
    return result;
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

string utils::removeNthLine(string arg, int num)
{
    return removeNthSlice(arg, '\n', num);
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

string utils::insertLineAt(string arg, string ins, int num)
{
    return insertSliceAt(arg, ins, '\n', num);
}