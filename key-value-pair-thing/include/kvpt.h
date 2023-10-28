#ifndef KVPT_H
#define KVPT_H

#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using std::ifstream;
using std::system;
using std::remove;
using std::string;
using std::cout;

namespace kvpt
{
    bool isSqliteInstalled();
    bool dbExists(string t);
    bool tableContainsKey(string t, string k);

    int sliceCount(string arg, char delim);
    string nthSlice(string arg, char delim, int num);
    string firstSlice(string arg, char delim);
    string otherSlices(string arg, char delim);
    string trimWhiteSpace(string arg);

    const string dq = "\"";
    string shell(string arg);

    string createKeyValueTable(string t);
    string insertKeyValuePair(string t, string k, string v);
    string deleteKeyValuePair(string t, string k);

    string selectAllPairs(string t);
    string selectAllKeys(string t);
    string selectAllValues(string t);

    string selectRowFromKey(string t, string k);
    string selectValueFromKey(string t, string k);
};

#endif