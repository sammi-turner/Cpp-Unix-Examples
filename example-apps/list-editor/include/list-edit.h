#ifndef LE_H
#define LE_H

#include "boilerplate.h"

using namespace bp;

class ListEdit
{
    int listIndex = 1;

    string list = "";
    string copiedItem = "";

    void updateItem(int i);
    void updateText(int i);
    void printList();

    string createItem(string arg);
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