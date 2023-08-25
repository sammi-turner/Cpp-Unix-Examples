#include "utils.h"
#include "list-edit.h"

using namespace utils;

void ListEdit::createLoop()
{
    clear();
    string newItem = "";
    bool exit = false;

    while (!exit)
    {
        printList();
        vPuts("\n\n    Item to add?\n    > ");
        newItem = vInput(80);

        if (newItem != "")
        {
            list += createItem(newItem);
            printList();
            listIndex++;
        }
        else
            exit = true;
    }
}

string ListEdit::createItem(string arg)
{
    string value = trimWhiteSpace(arg);
    int len = value.length();
    while (len < 80)
    {
        value += " ";
        len++;
    }
    value += "\n";

    if (listIndex > 99)
    {
        value = "";
        listIndex--;
    }
    return value;
}

void ListEdit::printList()
{
    clear();
    if (listIndex > 1)
    {
        vPuts("\n    LIST\n\n");

        int count = 1;
        string showLine;
        while (count < listIndex)
        {
            showLine += "    " + to_string(count) + ". " + nthLine(list, count) + "\n";
            count++;
        }
        vPuts(showLine);
    }
}

void ListEdit::readList()
{
    if (listIndex > 1)
    {
        printList();
        vPuts("\n    PRESS ANY KEY TO CONTINUE");
        getch();
    }
}

void ListEdit::updateLoop()
{
    bool exit = false;
    while (!exit)
    {
        printList();
        vPuts("\n    Item to update?\n    > ");
        string newItem = vInput(2);

        if (isPosInt(newItem))
            updateItem(toInt(newItem));
        else
            exit = true;
    }
}

void ListEdit::updateItem(int i)
{
    if (i <= listIndex)
        updateText(i);
}

void ListEdit::updateText(int i)
{
    string newItem = "";
    string oldLine = "";
    string lineToInsert = "";

    oldLine = nthLine(list, i);

    newItem = editPrompt("\n    Updating item\n    > ", oldLine, 80);
    if (newItem != "")
    {
        string finishedItem = createItem(newItem);
        list = removeNthLine(list, i);
        list = insertLineAt(list, finishedItem, i);
    }
}

void ListEdit::deleteLoop()
{
    bool doDelete = true;
    string newItem = "";
    int num;

    while (doDelete)
    {
        printList();
        vPuts("\n    Item to delete?\n    > ");
        newItem = vInput(2);

        if (!isPosInt(newItem))
            doDelete = false;
        else
            num = toInt(newItem);

        if (doDelete)
        {
            list = removeNthLine(list, num);
            listIndex--;
            printList();
        }
    }
}

void ListEdit::swapRoutine()
{
    bool bothValid = true;
    int firstNum, secondNum, low, high;

    printList();
    vPuts("\n    First item?\n    > ");
    string firstItem = vInput(2);

    vPuts("\n    Second item?\n    > ");
    string secondItem = vInput(2);

    if (!isPosInt(firstItem) || !isPosInt(secondItem))
        bothValid = false;

    if (bothValid)
    {
        firstNum = toInt(firstItem);
        secondNum = toInt(secondItem);
    }

    if (firstNum > listIndex || secondNum > listIndex)
        bothValid = false;

    if (firstNum == secondNum)
        bothValid = false;

    if (bothValid)
    {
        if (firstNum < secondNum)
        {
            low = firstNum;
            high = secondNum;
        }
        else
        {
            low = secondNum;
            high = firstNum;
        }

        swapItems(low, high);
    }
}

void ListEdit::swapItems(int i, int j)
{
    string lowerItem = nthLine(list, i);
    string upperItem = nthLine(list, j);

    list = removeNthLine(list, i);
    list = insertLineAt(list, upperItem, i);

    list = removeNthLine(list, j);
    list = insertLineAt(list, lowerItem, j);

    readList();
}

void ListEdit::loadList()
{
    printList();
    vPuts("\n    Name of file to load?\n    > ");
    string newItem = vInput(30);
    if (newItem != "" && fileExists(newItem))
    {
        list = fileRead(newItem);
        listIndex = lineCount(list) + 1;
        readList();
    }
    else
    {
        vPuts("\n    That file is not in the current directory.\n\n    PRESS ANY KEY TO CONTINUE");
        getch();
    }
}

void ListEdit::saveList()
{
    printList();
    vPuts("\n    Name of file to save?\n    > ");
    string newItem = vInput(80);
    if (newItem != "")
        fileWrite(newItem, list);
    readList();
}

void ListEdit::copyRoutine()
{
    printList();
    bool doCopy = true;
    string newItem = "";
    int num;

    if (listIndex == 1)
        doCopy = false;

    vPuts("\n    Item to copy?\n    > ");
    newItem = vInput(2);

    if (!isPosInt(newItem))
        doCopy = false;

    if (doCopy)
        num = toInt(newItem);

    if (num < listIndex)
        copiedItem = nthLine(list, num);
}

void ListEdit::cutRoutine()
{
    printList();
    bool doCut = true;
    int num;

    if (listIndex == 1)
        doCut = false;

    vPuts("\n    Item to cut?\n    > ");
    string newItem = vInput(2);

    if (!isPosInt(newItem))
        doCut = false;

    if (doCut)
        num = toInt(newItem);

    if (num >= listIndex)
        doCut = false;

    if (doCut)
    {
        copiedItem = nthLine(list, num);
        list = removeNthLine(list, num);
        listIndex--;
        readList();
    }
}

void ListEdit::pasteRoutine()
{
    printList();
    bool doPaste = true;
    int num = listIndex;
    string newItem = "";

    if (copiedItem == "")
        doPaste = false;

    else
    {
        vPuts("\n    Location to paste?\n    > ");
        newItem = vInput(2);
    }

    if (!isPosInt(newItem))
        doPaste = false;

    if (doPaste)
        num = toInt(newItem);

    if (num > listIndex)
        doPaste = false;

    if (doPaste)
    {
        list = insertLineAt(list, copiedItem, num);
        listIndex++;
        readList();
    }
}

void ListEdit::insertRoutine()
{
    printList();
    bool doInsert = true;
    string itemLocation = "";
    string text = "";
    int num = listIndex;

    if (listIndex == 1)
        doInsert = false;

    if (doInsert)
    {
        vPuts("\n    Item to insert?\n    > ");
        text = vInput(80);
    }

    if (text == "")
        doInsert = false;

    if (doInsert)
    {
        vPuts("\n    Location to insert?\n    > ");
        itemLocation = vInput(2);
    }

    if (!isPosInt(itemLocation))
        doInsert = false;

    if (doInsert)
        num = toInt(itemLocation);

    if (num <= listIndex)
    {
        list = insertLineAt(list, text, num);
        listIndex++;
        readList();
    }
}

void ListEdit::mainLoop()
{
    int choice;
    bool exitLoop = false;
    
    string mainMenu[] =
    {
        "MAIN MENU",
        "Create",
        "Read",
        "Update",
        "Delete",
        "Swap",
        "Copy",
        "Cut",
        "Paste",
        "Insert",
        "Load",
        "Save",
        "Exit"
    };

    while (!exitLoop)
    {
        choice = selectOption(mainMenu, 13);
        switch (choice)
        {
            case 1:
            createLoop();
            break;

            case 2:
            readList();
            break;

            case 3:
            updateLoop();
            break;

            case 4:
            deleteLoop();
            break;

            case 5:
            swapRoutine();
            break;

            case 6:
            copyRoutine();
            break;

            case 7:
            cutRoutine();
            break;

            case 8:
            pasteRoutine();
            break;

            case 9:
            insertRoutine();
            break;

            case 10:
            loadList();
            break;

            case 11:
            saveList();
            break;

            case 12:
            exitLoop = true;
            break;
        }
    }
}
