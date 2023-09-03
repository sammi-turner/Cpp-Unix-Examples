#include "kvpt.h"

using namespace kvpt;

int main()
{
    if (isSqliteInstalled())
    {
        if (dbExists("kv")) 
        {
            cout << "\nTable already exists.\n";
        }
        else
        {
            createKeyValueTable("kv");
            insertKeyValuePair("kv", "John", "Plumber");
            insertKeyValuePair("kv", "Bill", "Firefighter");
            insertKeyValuePair("kv", "Susan", "Engineer");
        }

        string v0 = "\n" + selectAllPairs("kv");
        string v1 = "\n" + selectAllKeys("kv");
        string v2 = "\n" + selectAllValues("kv") + "\n";

        deleteKeyValuePair("kv", "Bill");
        bool v3 = tableContainsKey("kv", "Bill");

        string v4 = "\n" + selectAllKeys("kv");
        string v5 = "\n" + selectAllValues("kv");

        string v6 = selectRowFromKey("kv", "John");
        string v7 = "\n" + selectValueFromKey("kv", "Susan");

        cout << v0 << v1 << v2 << v3 << v4 << v5 << v6 << v7 << "\n";
    }
    else
    {
        cout << "Sqlite3 is not installed.\n";
    }
}
