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
    const ScoreSheet::Colour c;
    int face;
    void roll();
    Dice(ScoreSheet::Colour col);
};
struct RollOfDice
{
    vector<Dice> dices;
    RollOfDice(); //might use two diffrent construct if needed to work with both games
    void roll();
    RollOfDice pair(int d, int d2);
    operator int();
};
string colToStr(ScoreSheet::Colour c);
ostream &operator<<(ostream &, const RollOfDice &);
ostream &operator<<(ostream &, const Dice &);

#endif //DICE