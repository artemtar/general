#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include "Dices.h"
using namespace std;
#ifndef SCORESHEET
#define SCORESHEET

struct Dice;
struct RollOfDice;

//ostream &operator<<(ostream &, const QwintoRow<Color>&);
//ostream &operator<<(ostream &, const QwixxRow<Color>&);

class ScoreSheet
{
    //The class ScoreSheet should hold the scores for the 3 colors, the name of
    // the player, the number of failed attempts and the overall score.
    int score_red[], score_yellow[], score_blue[];
    // int score_3colors[][];
    int final_score;
    int num_failed[];
    string name_player;
    bool ended;
    //Give the class ScoreSheet a print function that accepts an std::ostream and
    // inserts the score sheet formatted as in the above example into the stream.
  protected:
    virtual bool validate() = 0;

  public:
    enum Color
    {
        RED,
        YELLOW,
        BLUE,
        GREEN,
        WHITE
    };
    ScoreSheet(string name = "", string lastName = "");
    void print(const ostream &os) const;
    virtual bool score(vector<Dice> d, Color c, int pos = -1);
    virtual int calcTotal() = 0;
    void setTotal();
    bool operator!();
};
#endif //SCORESHEET

//istream &operator>>(istream &, Person &);
//ostream &operator<<(ostream &, const Person &);
#ifndef QWINTOSCORESHEET
#define QWINTOSCORESHEET
class QwintoScoreSheet : public ScoreSheet
{
    bool score(vector<Dice> d, Color c, int pos = -1) override;
    int calcTotal() override;

  public:
};
#endif //QWINTOSCORESHEET

#ifndef QWINTOROW
#define QWINTOROW
template <const ScoreSheet::Color C>
class QwintoRow
{
    int row[16];

  public:
    bool validate(int);
    int &operator[](int);
    int[] getRow();    
};
#include "BoardTemplates.hxx"
ostream &operator<<(ostream &, const QwintoRow<C> &)
#endif //QWINTOROW


#ifndef QWIXROW
#define QWIXROW
template <class T, const ScoreSheet::Color>
class QwixRow
{
    int row[14];

  public:
    int &operator[](int);
    int &operator+=(RollOfDice r);
    bool checkAdd(int place);
};
#include "BoardTemplates.hxx"
#endif //QWIXROW
