#include "utils.h"

using namespace utils;

int main()
{
    openVirtualTerminal();
    string s = fileRead("test.txt");
    vPuts(s);
    string v = shell("sqlite3 --version");
    vPuts(v);
    closeVirtualTerminal("\n\nPRESS ANY KEY TO CLOSE");
}
