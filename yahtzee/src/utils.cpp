#include "utils.h"

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

void utils::virtualKeypressOff() 
{
    noecho();
}

void utils::virtualKeypressOn() 
{
    echo();
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

void utils::fileAppend(string name, string text)
{
    ofstream outfile;
    outfile.open(name, ios_base::app);
    outfile << text;
}