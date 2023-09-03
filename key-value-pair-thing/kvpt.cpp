#include "kvpt.h"

string kvpt::shell(string arg) 
{
    const char* cstr = arg.c_str();
    string tempFile = "temp.txt";

    string command = string(cstr) + " > " + tempFile;
    system(command.c_str());

    string output;
    ifstream file(tempFile, std::ios::in);
    if (file.is_open()) 
    {
        string line;
        while (std::getline(file, line)) 
        {
            output += line + "\n";
        }
        file.close();
    }

    remove(tempFile.c_str());
    return output;
}

bool kvpt::isSqliteInstalled()
{
    string s = shell("sqlite3 --version");
    return (s[0] == '3');
}

bool kvpt::dbExists(string t)
{
    bool value = false;
    string name = t + ".db";
    ifstream f(name);
    if (f)
        value = true;
    return value;
}

bool kvpt::tableContainsKey(string t, string k)
{
    int size = sliceCount(k, '\n');
    for (int i = 0; i < size; i++)
    {
        if (nthSlice(t, '\n', i) == k)
            return true;
    }
    return false;
}

int kvpt::sliceCount(string arg, char delim)
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

string kvpt::nthSlice(string arg, char delim, int num)
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

string kvpt::firstSlice(string arg, char delim)
{
    string result = arg;
    while (result[0] == delim)
        result = result.substr(1, result.length());

    int index = result.find(delim);
    result = result.substr(0, index);
    return result;
}

string kvpt::otherSlices(string arg, char delim)
{
    string result = arg;
    while (result[0] == delim)
        result = result.substr(1, result.length());

    int index = result.find(delim);
    result = result.substr((index + 1), result.length());

    return result;
}

string kvpt::trimWhiteSpace(string arg)
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

string kvpt::createKeyValueTable(string t)
{
    string s0 = "echo " + dq + "CREATE TABLE " + t + " (key VARCHAR(50) PRIMARY KEY, value TEXT);" + dq + " | sqlite3 " + t + ".db";
    string s1 = shell(s0);
    return s1;
}

string kvpt::insertKeyValuePair(string t, string k, string v)
{
    string s0 = "echo " + dq + "INSERT INTO " + t + " (key, value) VALUES ('" + k + "', '" + v + "');" + dq + " | sqlite3 " + t + ".db";
    string s1 = shell(s0);
    return s1;
}

string kvpt::selectAllKeys(string t)
{
    string s0 = "echo " + dq + "SELECT key FROM " + t + ";" + dq + " | sqlite3 " + t + ".db";
    string s1 = shell(s0);
    return s1;
}

string kvpt::selectAllValues(string t)
{
    string s0 = "echo " + dq + "SELECT value FROM " + t + ";" + dq + " | sqlite3 " + t + ".db";
    string s1 = shell(s0);
    return s1;
}

string kvpt::deleteKeyValuePair(string t, string k)
{
    string s0 = "echo " + dq + "DELETE FROM " + t + " WHERE key = '" + k + "';" + dq + " | sqlite3 " + t + ".db";
    string s1 = shell(s0);
    return s1;
}

string kvpt::selectAllPairs(string t)
{
    string s0 = "echo " + dq + "SELECT * FROM " + t + ";" + dq + " | sqlite3 " + t + ".db";
    string s1 = shell(s0);
    return s1;
}

string kvpt::selectRowFromKey(string t, string k)
{
    string s0 = "echo " + dq + "SELECT * FROM " + t + " WHERE key = '" + k + "';" + dq + " | sqlite3 " + t + ".db";
    string s1 = shell(s0);
    return s1;
}

string kvpt::selectValueFromKey(string t, string k)
{
    string s0 = "echo " + dq + "SELECT value FROM " + t + " WHERE key = '" + k + "';" + dq + " | sqlite3 " + t + ".db";
    string s1 = shell(s0);
    return s1;
}