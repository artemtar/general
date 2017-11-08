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
    int final_score;
    int num_failed[];
    string name_player;
    bool ended;
    //Give the class ScoreSheet a print function that accepts an std::ostream and
    // inserts the score sheet formatted as in the above example into the stream.
protected:
    virtual bool validate() = 0;  
public:
    enum Colour
    {
        RED,
        YELLOW,
        BLUE,
        GREEN,
        WHITE
    };
    ScoreSheet(string name = "", string lastName = "");
    void print(const ostream &os) const;
    virtual bool score(vector<Dice> d, Colour c, int pos = -1);
    virtual int calcTotal() = 0;
    void setTotal();
    bool operator !();

};

//istream &operator>>(istream &, Person &);
//ostream &operator<<(ostream &, const Person &);

class QwintoScoreSheet:public ScoreSheet{
    bool score(vector<Dice> d, Colour c, int pos = -1) override;
    int calcTotal() override;
public:
};

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