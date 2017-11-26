#include "Dices.h"

int RandomDice::getRandomFace()
{
    std::uniform_int_distribution<> dis(1, 6);
    static std::random_device rd;
    std::mt19937 gen(rd());
    dis(gen);
}
Dice::Dice(ScoreSheet::Color col) : c(col) { roll(); }
void Dice::roll()
{
    face = RandomDice::getRandomFace();
}
RollOfDice::RollOfDice()
{
    dices.reserve(6);
    Dice red(ScoreSheet::Color::RED);
    Dice yellow(ScoreSheet::Color::YELLOW);
    Dice blue(ScoreSheet::Color::BLUE);
    dices.push_back(red);
    dices.push_back(yellow);
    dices.push_back(blue);
}
RollOfDice::operator int()
{
    int sum = 0;
    for (const Dice &d : dices)
        sum += d.face;
    return sum;
}
void RollOfDice::roll()
{
    for (Dice &d : dices)
        d.roll();
}

RollOfDice RollOfDice::pair(int d1, int d2) {}

ostream &operator<<(ostream &_os, const Dice &d)
{
    _os << colToStr(d.c) << " dice rolled :" << d.face << endl;
    return _os;
}
ostream &operator<<(ostream &_os, const RollOfDice &set)
{
    for (const Dice &d : set.dices)
    {
        _os << d;
    }
    return _os;
}
string colToStr(ScoreSheet::Color c)
{
    return (const char *[]){
        "Red",
        "Yellow",
        "Blue",
        "Green",
        "White",
    }[c];
}

// int main()
// {
//     //run test
//     cout << "ROLL:" << endl;
//     RollOfDice r;
//     int i = r;
//     cout << r;
//     cout << "total is:";
//     cout << i << endl;
//     cout << "REROLL:" << endl;
//     r.roll();
//     i = r;
//     cout << r;
//     cout << "total is:";
//     cout << i << endl;
// }