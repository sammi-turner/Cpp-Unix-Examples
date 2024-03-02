#include "utils.h"

using namespace utils;

struct functionCall
{
    str name;
    vector<string> arguments;
};

struct infix
{
    string name;
    string lhs;
    string rhs;
};



int main() 
{
    Tree t;
    t.insert("0", 1); // Insert 1 as a leaf of the root
    t.insert("0", 2); // Insert 2 as another leaf of the root
    t.insert("1", 3); // Insert 3 as a leaf of node 1
    t.printTree();
}
