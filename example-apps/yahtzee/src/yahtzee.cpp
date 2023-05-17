#include "boilerplate.h"
#include "yahtzee.h"

/* This method sets the dice held at the beginning of each round.
The zero index represents the number of re-rolls. */

void Yahtzee::defaultDice()
{
    dice[0] = 5;
    for (int i = 1; i < 7; i++)
        dice[i] = 0;
}

/* This method sets the value of each score box at the begining of each game.
A value of '-1' means that the score box has not been filled. */

void Yahtzee::defaultScores()
{
    for (int i = 0; i < 13; i++)
        scores[i] = -1;
}

/* Rolling the dice and recording the results */

void Yahtzee::diceCount()
{
    while (dice[0] > 0)
    {
        int roll = pseudo(6);
        dice[0]--;
        switch (roll)
        {
            case 1:
                dice[1]++;
                break;
            case 2:
                dice[2]++;
                break;
            case 3:
                dice[3]++;
                break;
            case 4:
                dice[4]++;
                break;
            case 5:
                dice[5]++;
                break;
            case 6:
                dice[6]++;
                break;
        };
    };
}

/* Player re-rolls dice by type */

void Yahtzee::playerReRolls()
{
    string s;
    int ch, num;
    for (int i = 1; i < 7; i++)
    {
        if (dice[i] > 0)
        {
            scoreCard();
            s = "     How many " + to_string(i) + "s do you wish to re-roll?";
            vPuts(s);
            ch = getch();
            num = ch - '0';
            if (num > 0 && num <= dice[i])
            {
                dice[i] -= num;
                dice[0] += num;
            }
        }
    }
}

/* Prints out the score card so far. */

void Yahtzee::scoreCard() 
{
    clear();
    virtualCursorOff();
    string s = "\n     SCORE CARD\n";

    s += "\n     Ones                     ";
    if (scores[0] == -1) 
        s += "a";
    else 
        s += to_string(scores[0]);
    s += "\n     Twos                     ";

    if (scores[1] == -1) 
        s += "b";
    else 
        s += to_string(scores[1]);
    s += "\n     Threes                   ";

    if (scores[2] == -1) 
        s += "c";
    else 
        s += to_string(scores[2]);
    s += "\n     Fours                    ";

    if (scores[3] == -1) 
        s += "d";
    else 
        s += to_string(scores[3]);
    s += "\n     Fives                    ";

    if (scores[4] == -1) 

        s += "e";
    else 
        s += to_string(scores[4]);
    s += "\n     Sixes                    ";

    if (scores[5] == -1) 
        s += "f";
    else 
        s += to_string(scores[5]);
    s += "\n     Three of a Kind          ";

    if (scores[6] == -1) 
        s += "g";
    else 
        s += to_string(scores[6]);
    s += "\n     Four of a Kind           ";

    if (scores[7] == -1) 
        s += "h";
    else 
        s += to_string(scores[7]);
    s += "\n     Full House               ";

    if (scores[8] == -1) 
        s += "i";
    else 
        s += to_string(scores[8]);
    s += "\n     Small Straight           ";

    if (scores[9] == -1) 
        s += "j";
    else 
        s += to_string(scores[9]);
    s += "\n     Large Straight           ";

    if (scores[10] == -1) 
        s += "k";
    else 
        s += to_string(scores[10]);
    s += "\n     Chance                   ";

    if (scores[11] == -1) 
        s += "l";
    else 
        s += to_string(scores[11]);
    s += "\n     Yahtzee                  ";

    if (scores[12] == -1) 

        s += "m";
    else 
        s += to_string(scores[12]);

    s += "\n\n     DICE HELD\n\n     ";
    s += to_string(dice[1]) + " 1s, ";
    s += to_string(dice[2]) + " 2s, ";
    s += to_string(dice[3]) + " 3s, ";
    s += to_string(dice[4]) + " 4s, ";
    s += to_string(dice[5]) + " 5s, ";
    s += "and " + to_string(dice[6]) + " 6s.";
    s += "\n\n     You have " + to_string(dice[0]) + " re-rolls.\n\n";

    vPuts(s);
}

/* Loop to insure that a valid input has been entered */

void Yahtzee::scoringSelection() 
{
    char ch;
    bool exitLoop = false;

    while (!exitLoop) 
    {
        scoreCard();
        vPuts("     Which scorebox? ");
        ch = getch();

        if ((ch == 'a') && (scores[0] == -1))
        {
            scores[0] = dice[1];
            exitLoop = true;
        };

        if ((ch == 'b') && (scores[1] == -1))
        {
            scores[1] = (dice[2] * 2);
            exitLoop = true;
        };

        if ((ch == 'c') && (scores[2] == -1))
        {
            scores[2] = (dice[3] * 3);
            exitLoop = true;
        };

        if ((ch == 'd') && (scores[3] == -1))
        {
            scores[3] = (dice[4] * 4);
            exitLoop = true;
        };

        if ((ch == 'e') && (scores[4] == -1))
        {
            scores[4] = (dice[5] * 5);
            exitLoop = true;
        };

        if ((ch == 'f') && (scores[5] == -1))
        {
            scores[5] = (dice[6] * 6);
            exitLoop = true;
        };

        if ((ch == 'g') && (scores[6] == -1))
        {
            scores[6] = threeOfAKind();
            exitLoop = true;
        };

        if ((ch == 'h') && (scores[7] == -1))
        {
            scores[7] = fourOfAKind();
            exitLoop = true;
        };

        if ((ch == 'i') && (scores[8] == -1))
        {
            scores[8] = fullHouse();
            exitLoop = true;
        };

        if ((ch == 'j') && (scores[9] == -1))
        {
            scores[9] = smallStraight();
            exitLoop = true;
        };

        if ((ch == 'k') && (scores[10] == -1))
        {
            scores[10] = largeStraight();
            exitLoop = true;
        };

        if ((ch == 'l') && (scores[11] == -1))
        {
            scores[11] = chance();
            exitLoop = true;
        };

        if ((ch == 'm') && (scores[12] == -1))
        {
            scores[12] = yahtzee();
            exitLoop = true;
        };
    }
}

/* Three of a kind score function */

int Yahtzee::threeOfAKind()
{
    int value = 0;
    if (dice[1] > 2 || dice[2] > 2 || dice[3] > 2 || dice[4] > 2 || dice[5] > 2 || dice[6] > 2)
        value = dice[1] + (dice[2] * 2) + (dice[3] * 3) + (dice[4] * 4) + (dice[5] * 5) + (dice[6] * 6);
    return value;
}

/* Four of a kind score function */

int Yahtzee::fourOfAKind() {
    int value = 0;
    if (dice[1] > 3 || dice[2] > 3 || dice[3] > 3 || dice[4] > 3 || dice[5] > 3 || dice[6] > 3)
        value = dice[1] + (dice[2] * 2) + (dice[3] * 3) + (dice[4] * 4) + (dice[5] * 5) + (dice[6] * 6);
    return value;
}

/* Full house score function */

int Yahtzee::fullHouse()
{
    int value = 0;
    bool tripleTest = false;
    bool pairTest = false;

    if (dice[1] == 3 || dice[2] == 3 || dice[3] == 3 || dice[4] == 3 || dice[5] == 3 || dice[6] == 3)
        tripleTest = true;

    if (dice[1] == 2 || dice[2] == 2 || dice[3] == 2 || dice[4] == 2 || dice[5] == 2 || dice[6] == 2) 
        pairTest = true;

    if (tripleTest && pairTest) 
        value = 25;

    if (dice[1] == 5 || dice[2] == 5 || dice[3] == 5 || dice[4] == 5 || dice[5] == 5 || dice[6] == 5) 
        value = 25;

    return value;
}

/* Small straight score function */

int Yahtzee::smallStraight() {
    int value = 0;

    if (dice[1] > 0 && dice[2] > 0 && dice[3] > 0 && dice[4] > 0) 
        value = 30;

    if (dice[2] > 0 && dice[3] > 0 && dice[4] > 0 && dice[5] > 0) 
        value = 30;

    if (dice[3] > 0 && dice[4] > 0 && dice[5] > 0 && dice[6] > 0) 
        value = 30;

    return value;
}

/* Large straight score function */

int Yahtzee::largeStraight() {
    int value = 0;

    if (dice[1] > 0 && dice[2] > 0 && dice[3] > 0 && dice[4] > 0 && dice[5] > 0)
        value = 40;

    if (dice[2] > 0 && dice[3] > 0 && dice[4] > 0 && dice[5] > 0 && dice[6] > 0)
        value = 40;

    return value;
}

/* The total of all dice. Regardless of arrangement */

int Yahtzee::chance() 
{
    return (dice[1] + (dice[2] * 2) + (dice[3] * 3) + (dice[4] * 4) + (dice[5] * 5) + (dice[6] * 6));
}

/* Yahtzee score function */

int Yahtzee::yahtzee() 
{
    int value = 0;
    if (dice[1] == 5 || dice[2] == 5 || dice[3] == 5 || dice[4] == 5 || dice[5] == 5 || dice[6] == 5)
        value = 50;
    return value;
}

/* Total of the upper section */

int Yahtzee::upperTotal()
{
    return (scores[0] + scores[1] + scores[2] + scores[3] + scores[4] + scores[5]);
}

/* If the upper section total is greater than 62, then a bonus of 35 is awarded */

int Yahtzee::upperBonus()
{
    int value = 0;
    if (upperTotal() > 62)
        value = 35;
    return value;
}

/* Total of all scores */

int Yahtzee::grandTotal() 
{
    return (upperTotal() + upperBonus() + scores[6] + scores[7] + scores[8] + scores[9] + scores[10] + scores[11] + scores[12]);
}

/* Scores written to both the file "scores.txt", and the screen */

void Yahtzee::outputScores() 
{
    clear();
    string output = "\n\n     FINAL SCORE CARD\n";

    output += "\n     Ones                     " + to_string(scores[0]);
    output += "\n     Twos                     " + to_string(scores[1]);
    output += "\n     Threes                   " + to_string(scores[2]);
    output += "\n     Fours                    " + to_string(scores[3]);
    output += "\n     Fives                    " + to_string(scores[4]);
    output += "\n     Sixes                    " + to_string(scores[5]);
    output += "\n";
    output += "\n     Upper Total              " + to_string(upperTotal());
    output += "\n     Upper Bonus              " + to_string(upperBonus());
    output += "\n";
    output += "\n     Three of a kind          " + to_string(scores[6]);
    output += "\n     Four of a kind           " + to_string(scores[7]);
    output += "\n     Full House               " + to_string(scores[8]);
    output += "\n     Small Straight           " + to_string(scores[9]);
    output += "\n     Large Straight           " + to_string(scores[10]);
    output += "\n     Chance                   " + to_string(scores[11]);
    output += "\n     Yahtzee                  " + to_string(scores[12]);
    output += "\n";
    output += "\n     GRAND TOTAL              " + to_string(grandTotal());
    output += "\n";

    fileAppend("scores.txt", output);
    vPuts(output);
}

void Yahtzee::mainLoop()
{
    defaultScores();
    for (int i = 0; i < 13; i++) 
    {
        defaultDice();
        diceCount();
        playerReRolls();
        if (dice[0] > 0) 
        {
            diceCount();
            playerReRolls();
        };
        diceCount();
        scoringSelection();
    };
    outputScores();
}