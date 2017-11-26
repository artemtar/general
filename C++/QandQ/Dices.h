#include <random>

#ifndef DICE
#define DICE

#include "ScoreSheet.h"

struct RandomDice
{
    static int getRandomFace();
};
struct Dice
{
    const ScoreSheet::Color c;
    int face;
    void roll();
    Dice(ScoreSheet::Color);
};
struct RollOfDice
{
    vector<Dice> dices;
    RollOfDice(); //might use two diffrent construct if needed to work with both games
    void roll();
    RollOfDice pair(int, int);
    operator int();
};
string colToStr(ScoreSheet::Color);
ostream &operator<<(ostream &, const RollOfDice &);
ostream &operator<<(ostream &, const Dice &);

#endif //DICE