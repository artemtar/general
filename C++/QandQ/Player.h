#include "ScoreSheet.h"
#ifndef PLAYER
#define PLAYER

class Player
{
protected:
  bool status = false;
public:
  //data
  string name;
  ScoreSheet* sheet;
  //constructor

  Player(ScoreSheet*, const string &_name = "");
  Player(const Player&);
  virtual ~Player();

  virtual ScoreSheet::Color choseColor()=0;
  //set players status

  inline void setStatusActive(){status = true;}
  inline void setStatusInactuve(){status = false;}
  inline ScoreSheet* getScoreSheet(){return sheet;}
  virtual int inputChecker(int, int);
  virtual inline bool getStatus(){return status;}
  virtual  std::vector<ScoreSheet::Color> inputBeforeRoll(RollOfDice &,int) = 0;
  virtual void inputAfterRoll(RollOfDice*) = 0;
  bool operator >(const Player&);
  //bool findWinner(Player*, Player*); looking a place to implement
  friend ostream &operator<<(ostream &, const Player &);
  
};

#endif //PLAYER

#ifndef QWINTOPLAYER
#define QWINTOPLAYER

class QwintoPlayer : public Player
{
public:
  //constructors
    QwintoPlayer(QwintoScoreSheet*, string _name);
    QwintoPlayer(const QwintoPlayer &from);
    ~QwintoPlayer();//for debuging
    //virtual
    std::vector<ScoreSheet::Color> inputBeforeRoll(RollOfDice &,int) override;
    virtual void inputAfterRoll(RollOfDice*) override;

     ScoreSheet::Color choseColor() override;
};

#endif //QWINTOPLAYER

#ifndef QWIXPLAYER
#define QWIXPLAYER

class QwixPlayer : public Player
{
public:
  QwixPlayer(QwixScoreSheet*, string _name); // compile complain
  std::vector<ScoreSheet::Color> inputBeforeRoll(RollOfDice &,int) override;
  virtual void inputAfterRoll(RollOfDice*) override;

  ScoreSheet::Color choseColor() override;
};

#endif //QWIXPLAYER