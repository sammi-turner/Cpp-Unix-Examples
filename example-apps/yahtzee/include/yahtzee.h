#ifndef YA_H
#define YA_H

using namespace bp;

class Yahtzee
{
    int dice[7];
    int scores[13];

    int threeOfAKind();
    int fourOfAKind();
    int fullHouse();

    int smallStraight();
    int largeStraight();

    int chance();
    int yahtzee();

    void scoreCard();

    int upperTotal();
    int upperBonus();
    int grandTotal();

    void defaultDice();
    void defaultScores();

    void diceCount();
    void playerReRolls();

    void scoringSelection();
    void outputScores();

public:
    void mainLoop();
};

#endif