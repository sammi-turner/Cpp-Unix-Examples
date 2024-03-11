#include "kvpt.h"

string kvpt::shell(const string arg) 
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

bool kvpt::dbExists(const string t)
{
    bool value = false;
    string name = t + ".db";
    ifstream f(name);
    if (f)
    {
        value = true;
    }
    return value;
}

bool kvpt::tableContainsKey(const string t, const string k)
{
    int size = sliceCount(k, '\n');
    for (int i = 0; i < size; i++)
    {
        if (nthSlice(t, '\n', i) == k)
        {
            return true;
        }
    }
    return false;
}

int kvpt::sliceCount(const string arg, const char delim)
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

string kvpt::nthSlice(const string arg, const char delim, const int num)
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

string kvpt::firstSlice(const string arg, const char delim)
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

string kvpt::otherSlices(const string arg, const char delim)
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

string kvpt::trimWhiteSpace(const string arg)
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

string kvpt::createKeyValueTable(const string t)
{
    string s0 = format("echo {}CREATE TABLE {} (key VARCHAR(50) PRIMARY KEY, value TEXT);{} | sqlite3 {}.db", dq, t, dq, t);
    string s1 = shell(s0);
    return s1;
}

string kvpt::insertKeyValuePair(const string t, const string k, const string v)
{
    string s0 = format("echo {}INSERT INTO {} (key, value) VALUES ('{}', '{}');{} | sqlite3 {}.db", dq, t, k, v, dq, t);
    string s1 = shell(s0);
    return s1;
}

string kvpt::selectAllKeys(const string t)
{
    string s0 = format("echo {}SELECT key FROM {};{} | sqlite3 {}.db", dq, t, dq, t);
    string s1 = shell(s0);
    return s1;
}

string kvpt::selectAllValues(const string t)
{
    string s0 = format("echo {}SELECT value FROM {};{} | sqlite3 {}.db", dq, t, dq, t);
    string s1 = shell(s0);
    return s1;
}

string kvpt::deleteKeyValuePair(const string t, const string k)
{
    string s0 = format("echo {}DELETE FROM {} WHERE key = '{}';{} | sqlite3 {}.db", dq, t, k, dq, t);
    string s1 = shell(s0);
    return s1;
}

string kvpt::selectAllPairs(const string t)
{
    string s0 = format("echo {}SELECT * FROM {};{} | sqlite3 {}.db", dq, t, dq, t);
    string s1 = shell(s0);
    return s1;
}

string kvpt::selectRowFromKey(const string t, const string k)
{
    string s0 = format("echo {}SELECT * FROM {} WHERE key = '{}';{} | sqlite3 {}.db", dq, t, k, dq, t);
    string s1 = shell(s0);
    return s1;
}

string kvpt::selectValueFromKey(const string t, const string k)
{
    string s0 = format("echo {}SELECT value FROM {} WHERE key = '{}';{} | sqlite3 {}.db", dq, t, k, dq, t);
    string s1 = shell(s0);
    return s1;
}