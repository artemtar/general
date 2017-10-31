#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
using namespace std;
#ifndef SCORESHEET
#define SCORESHEET

struct Dice;
struct RollOfDice;

//ostream &operator<<(ostream &, const QwintoRow<Colour>&);
//ostream &operator<<(ostream &, const QwixxRow<Colour>&);

class ScoreSheet
{
    //The class ScoreSheet should hold the scores for the 3 colours, the name of
    // the player, the number of failed attempts and the overall score.
    int score_red[], score_yellow[], score_blue[];
   // int score_3colours[][];
    int score_overall;
    int num_failed[];
    string name_player;
    //Give the class ScoreSheet a print function that accepts an std::ostream and
    // inserts the score sheet formatted as in the above example into the stream.
  public:
    ScoreSheet(string name = "", string lastName = "");
    void print(const ostream &os) const;
    void score(vector<Dice> d);
    enum Colour
    {
        RED,
        YELLOW,
        BLUE,
        GREEN,
        WHITE
    };
};

//istream &operator>>(istream &, Person &);
//ostream &operator<<(ostream &, const Person &);


template <class Colour>
class QwintoRow{
    int row[16];
    ScoreSheet::Colour c;
public:
    int& operator[](int index);
    bool checkAdd(int place); 
};

template <class Colour>
class QwixxRow{
    int raw[14];
    ScoreSheet::Colour c;
public:
    int& operator[](int index);
    int& operator+=(RollOfDice r);
    bool checkAdd(int place); 
};

#endif //SCORESHEET

#include "Dices.h"