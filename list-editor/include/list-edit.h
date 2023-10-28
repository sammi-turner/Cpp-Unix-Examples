#ifndef LE_H
#define LE_H

#include "utils.h"

using namespace utils;

class ListEdit
{
    int listIndex = 1;

    string list = "";
    string copiedItem = "";
    string createItem(string arg);
    
    void updateItem(int i);
    void updateText(int i);
    void printList();
    void swapItems(int i, int j);
    void createLoop();
    void updateLoop();
    void deleteLoop();
    void swapRoutine();
    void copyRoutine();
    void cutRoutine();
    void pasteRoutine();
    void insertRoutine();
    void readList();
    void loadList();
    void saveList();

public:
    void mainLoop();
};

#endif