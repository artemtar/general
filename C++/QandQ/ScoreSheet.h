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
    int overallScore;
    int num_failed[4];
    string name_player;
    bool ended;
    //Give the class ScoreSheet a print function that accepts an std::ostream and
    // inserts the score sheet formatted as in the above example into the stream.
  protected:
    virtual bool validate(int) = 0;
  public:
    enum Color
    {
        RED,
        YELLOW,
        BLUE,
        GREEN,
        WHITE
    };
    ScoreSheet(string s = "");    
    //void print(const ostream &os) const;
    virtual bool score(RollOfDice, Color, int pos = -1) = 0;
    virtual int calcTotal() = 0;
    //void setTotal();
    virtual bool operator!();
    const int* getFails()const;
    friend ostream& operator<<(ostream& , const ScoreSheet&);
};
#endif //SCORESHEET

#ifndef QWINTOROW
#define QWINTOROW
template <const ScoreSheet::Color C>
class QwintoRow
{
    int row[10];
    bool validate(int);
  public:
    QwintoRow();
    int &operator[](int);
    friend ostream& operator<<(ostream& out, const QwintoRow<C>& qr){
    for (auto i : qr.row){
        out << i;
    }
    return out;
}
};
//separate file to hold declaration of template
#include "Qwinto.hxx"
#endif //QWINTOROW


#ifndef QWIXROW
#define QWIXROW
template <class T, const ScoreSheet::Color C>
class QwixRow
{
    int row[11];
    bool validate(int) override;
  public:
    int &operator[](int);
    int &operator+=(RollOfDice&);
    bool checkAdd(int);
    friend ostream& operator<<(ostream& out, const QwixRow<T,C>& qr){
    for (auto i : qr.row){
        out << i;
    }
    return out;
}
};
#include "Qwix.hxx"
#endif //QWIXROW

#ifndef QWINTOSCORESHEET
#define QWINTOSCORESHEET
class QwintoScoreSheet : public ScoreSheet
{
    QwintoRow<RED> red;
    QwintoRow<YELLOW> yellow;
    QwintoRow<BLUE> blue;        
    
  public:
  QwintoScoreSheet(string, QwintoRow<RED>, QwintoRow<YELLOW>, QwintoRow<BLUE>);
    bool score(RollOfDice, ScoreSheet::Color, int pos = -1) override;
    bool validate(int);
    int calcTotal() override;
    bool operator!() override;
    friend ostream& operator<<(ostream& , const QwintoScoreSheet&);
};
#endif //QWINTOSCORESHEET

// #ifndef QWIXSCORESHEET
// #define QWIXSCORESHEET
// class QwixScoreSheet : public ScoreSheet
// {
//   vector red_yellow;
//  // list blue_green;

//   public:
//   QwixScoreSheet(string, QwintoRow<RED>, QwintoRow<YELLOW>, QwintoRow<BLUE>, QwintoRow<GREEN>);
//     bool score(RollOfDice, ScoreSheet::Color, int pos = -1) override;
//     int calcTotal() override;
//     bool operator!() override;
//     friend ostream& operator<<(ostream& , const QwintoScoreSheet)&;
// };
// #endif //QWIXSCORESHEET