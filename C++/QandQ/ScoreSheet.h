#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <fstream>
#include "Dices.h"
using namespace std;
#ifndef SCORESHEET
#define SCORESHEET

struct Dice;
struct RollOfDice;
class ScoreSheet
{
private:
  //data

  int overallScore = -1;
  //Give the class ScoreSheet a print function that accepts an std::ostream and
protected:
  //data
  string name_player;
  virtual bool validate(int,ScoreSheet*,RollOfDice*) = 0; 

public:
  //data
  int num_failed;//change to next line to get to the array
  enum Color
  {
    RED,
    YELLOW,
    BLUE,
    GREEN,
    WHITE
  };
  //constructor//
  ScoreSheet(string s = "");
  ScoreSheet(const ScoreSheet &from);
  virtual ~ScoreSheet();
  //functions
  inline int getf(){return num_failed;}
  void addFail();
  virtual bool operator!();
  friend ostream &operator<<(ostream &, const ScoreSheet &);
  virtual bool score(RollOfDice*, ScoreSheet::Color, int pos = -1) = 0;
  virtual bool checkForFail(RollOfDice*,ScoreSheet*)=0;
  virtual ostream &print(ostream &) const = 0;
  int setTotal();
  virtual int calcTotal() = 0;
  inline int getScore() { return overallScore; }

};
#endif //SCORESHEET

#ifndef QWINTOROW
#define QWINTOROW
string lazyLine(int i);
template <const ScoreSheet::Color C>
class QwintoRow
{
private:
  int row[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};//changed for testing
  //testing
 
public:  
  bool validate(int, int);
  bool chosen = false;
  QwintoRow();
  void test(){for (int a : row) cout << a;}
  int &operator[](int);
  bool isFull();
  int amountNums();
  //should i make it inline? :D
  friend ostream &operator<<(ostream &out, const QwintoRow<C> &qr)
  {
    //please do not read this, I was drunk
    if (C == ScoreSheet::Color::RED)
    {
      int i = 0;
      cout << "|";
      for (auto j : qr.row)
      {

        string num = "";
        if (i == 3)
          num = "XX";
        else
        {
          if (j <= 0)
            num = "  ";
          else
          {
            if (i >= 0 && i < 10)
              num = " " + to_string(j);
            else
              num = to_string(j);
          }
        }

        out << num;

        if (i == 0 || i == 1 || i == 4 || i == 5)
          cout << "%";
        else
          out << "|";
        i += 1;
      }
      return out;
    }

    if (C == ScoreSheet::Color::YELLOW)
    {
      int i = 0;
      cout << "|";
      for (auto j : qr.row)
      {

        string num = "";
        if (i == 5)
          num = "XX";
        else
        {
          if (j <= 0)
            num = "  ";
          else
          {
            if (i >= 0 && i < 10)
              num = " " + to_string(j);
            else
              num = to_string(j);
          }
        }

        out << num;

        if  (i == 6 || i == 7)
          cout << "%";
        else
          out << "|";
        i += 1;
      }
      return out;
    }

    if (C == ScoreSheet::Color::BLUE)
    {
      int i = 0;
      cout << "|";
      for (auto j : qr.row)
      {

        string num = "";
        if (i == 4)
          num = "XX";
        else
        {
          if (j <= 0)
            num = "  ";
          else
          {
            if (i >= 0 && i < 10)
              num = " " + to_string(j);
            else
              num = to_string(j);
          }
        }

        out << num;

        if (i == 1 || i == 2 || i == 8 || i == 9)
          cout << "%";
        else
          out << "|";
        i += 1;
      }
      return out;
    }
  }
};
//separate file to hold declaration of template
#include "Qwinto.hxx"
#endif //QWINTOROW

#ifndef QWIXROW
#define QWIXROW
template<ScoreSheet::Color C, 
template<class, class = allocator<int>> class Container>
class QwixRow
{
private:
  //data
  Container<int> row;
  //functions
  bool validate(int);  

public:
  //functions
  QwixRow();
  int &operator[](int);
  int &operator+=(RollOfDice &);
  bool checkAdd(int);
  int calcRow();
  friend ostream &operator<<(ostream &out, const QwixRow<C, Container> &qr){
       

    if (C == ScoreSheet::Color::RED || C == ScoreSheet::Color::YELLOW)
    {
      cout << "|";
      for (auto j : qr.row)
      {
        string num = "";
        if (j == -1)
          num = "XX";       
          if (j <= 0)
            num = "  ";
          else
          {
            if (j > 0 && j < 10)
              num = " " + to_string(j);
            else
              num = to_string(j);
          } 
        out << num;
          out << "|";
      }

      return out;
    }

    if (C == ScoreSheet::Color::GREEN || C == ScoreSheet::Color::BLUE)
        {
    auto b = qr.row.begin();
    auto e = qr.row.end();
    --b;
    --e;
      cout << "|";
      while (e != b)
      {
        int j = *e;
        string num = "";
        if (j == -1)
          num = "XX";       
          if (j <= 0)
            num = "  ";
          else
          {
            if (j > 0 && j < 10)
              num = " " + to_string(j);
            else
              num = to_string(j);
          } 
        out << num;
          out << "|";
          --e;
      }
      return out;
    }
  }
 };
#include "Qwix.hxx"
#endif //QWIXROW

#ifndef QWINTOSCORESHEET
#define QWINTOSCORESHEET
class QwintoScoreSheet : public ScoreSheet
{
private:
  //data
  QwintoRow<RED> red;
  QwintoRow<YELLOW> yellow;
  QwintoRow<BLUE> blue;
  int calcLine(int, int, int, int);

public:
  QwintoScoreSheet(string name);                 
  QwintoScoreSheet(const QwintoScoreSheet &from); 
   bool score(RollOfDice*, ScoreSheet::Color, int pos = -1) override;
   bool validate(int,ScoreSheet*,RollOfDice*) override;
   bool checkForFail(RollOfDice* rollOfDice,ScoreSheet* scoreSheet);
  int calcTotal() override;
  bool operator!() override;
  ostream &print(ostream &) const override;
  friend ostream &operator<<(ostream &, const QwintoScoreSheet &);
};
#endif //QWINTOSCORESHEET

//have to revise this class before implementing
#ifndef QWIXSCORESHEET
#define QWIXSCORESHEET
class QwixScoreSheet : public ScoreSheet
{


  int* player_locks;

public:
QwixRow<ScoreSheet::Color::BLUE, vector> blue;
QwixRow<ScoreSheet::Color::GREEN, vector> green;
QwixRow<ScoreSheet::Color::RED, list> red;
QwixRow<ScoreSheet::Color::YELLOW, list> yellow;
  //constructors  
  QwixScoreSheet(string, int*);
  //functions

  bool score(RollOfDice*, ScoreSheet::Color, int pos = -1) override;
  bool checkForFail(RollOfDice*,ScoreSheet*) override;
  virtual bool validate(int, ScoreSheet *, RollOfDice*);
  int calcHelper(int);
  int calcTotal() override;
  bool operator!() override;
  ostream &print(ostream &) const override;
  //friends
  friend ostream &operator<<(ostream &, const QwixScoreSheet &);

};
#endif //QWIXSCORESHEE