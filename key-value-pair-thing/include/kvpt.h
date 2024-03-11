#ifndef KVPT_H
#define KVPT_H

#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <format>
#include <string>

using std::ifstream;
using std::system;
using std::remove;
using std::format;
using std::string;
using std::cout;

namespace kvpt
{
    bool isSqliteInstalled();
    bool dbExists(const string t);
    bool tableContainsKey(const string t, const string k);

    int sliceCount(const string arg, const char delim);
    string nthSlice(const string arg, const char delim, const int num);
    string firstSlice(const string arg, const char delim);
    string otherSlices(const string arg, const char delim);
    string trimWhiteSpace(const string arg);

    const string dq = "\"";
    string shell(const string arg);

    string createKeyValueTable(const string t);
    string insertKeyValuePair(const string t, const string k, const string v);
    string deleteKeyValuePair(const string t, const string k);

    string selectAllPairs(const string t);
    string selectAllKeys(const string t);
    string selectAllValues(const string t);

    string selectRowFromKey(const string t, const string k);
    string selectValueFromKey(const string t, const string k);
};

#endif