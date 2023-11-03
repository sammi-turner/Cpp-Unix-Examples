#include "utils.h"

void utils::seed() 
{
    srand((int)time(0));
}

int utils::pseudo(int arg) 
{
    int result = 0;
    if (arg > 1)
    {
        result = (rand() % arg) + 1;
    }
    return result;
}

void utils::shell(string s)
{
    system(s.c_str());
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

string utils::vInput(int arg) 
{
    char cstring[arg + 1];
    getnstr(cstring, arg);
    return string(cstring);
}

void utils::vPuts(string arg) 
{
    printw(arg.c_str());
    refresh();
}

void utils::renderMenu(string menu[], int size, int count) 
{
    clear();
    string s = "\n    " + menu[0] + "\n\n";
    for (int i = 1; i < size; i++) 
    {
        if (i == count) 
        {
            s += "  > " + menu[i] + "\n";
        }
        else 
        {
            s += "    " + menu[i] + "\n";
        }
    };
    vPuts(s);
}

int utils::selectOption(string menu[], int size) 
{
    curs_set(0);
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
                {
                    value = 1;
                }
                renderMenu(menu, size, value);
                break;
            case KEY_UP:
                value--;
                if (value == 0)
                {
                    value = (size - 1);
                }
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
    {
        s += buffer[i];
    }
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
        {
            pos--;
        }
        if (ch == KEY_RIGHT && res > pos)
        {
            pos++;
        }
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
        {
            exit = 1;
        }
        renderPrompt(prompt, result, pos);
    }
    return result;
}

bool utils::isCharLowerCase(char arg)
{
    return (arg >= 'a' || arg <= 'z');
}

bool utils::isCharDigit(char arg)
{
    return (isdigit(arg) > 0);
}

bool utils::fileExists(string name)
{
    bool value = false;
    ifstream f(name);
    if (f)
    {
        value = true;
    }
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
    {
        return 1;
    }
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