#include "utils.h"

string utils::userInput()
{
    string s;
    getline(cin, s);
    return s;
}

string utils::trimmedUserInput()
{
    string s;
    getline(cin >> ws, s);
    return s;
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
    {
        result = false;
    }
    for (int i = 1; i < size; i++)
    {
        if (!isCharDigit(arg[i]))
        {
            result = false;
        }
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

string utils::firstSlice(string arg, char delim)
{
    string result = arg;
    while (result[0] == delim)
    {
        result = result.substr(1, result.length());
    }
    int index = result.find(delim);
    result = result.substr(0, index);
    return result;
}

string utils::otherSlices(string arg, char delim)
{
    string result = arg;
    while (result[0] == delim)
    {
        result = result.substr(1, result.length());
    }
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
        {
            trim = otherSlices(trim, delim);
        }
    }
    if (num < max)
    {
        result += trim;
    }
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