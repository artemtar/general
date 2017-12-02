#include "ScoreSheet.h"
#ifndef PLAYER
#define PLAYER

class Player
{
  protected:
    string name;
    bool status = false;
    //ScoreSheet board;

  public:
    Player(const string &_name = "");
    inline void setStatusActive();
    inline void setStatusInactuve();
    virtual inline bool getStatus();
    //void setScore(ScoreSheet& s);
    virtual void inputBeforeRoll(RollOfDice &) = 0;
    virtual void inputAfterRoll(RollOfDice &) = 0;
    friend istream &operator>>(istream &, Player &);
    friend ostream &operator<<(ostream &, const Player &);
};

#endif //PLAYER

#ifndef QWINTOPLAYER
#define QWINTOPLAYER

class QwintoPlayer : public Player
{
    QwintoScoreSheet sheet;

  public:
    QwintoPlayer(QwintoScoreSheet &, string _name);
    virtual void inputBeforeRoll(RollOfDice &) override;
    virtual void inputAfterRoll(RollOfDice &) override;
};

#endif //QWINTOPLAYER

#ifndef QWIXPLAYER
#define QWIXPLAYER

class QwixPlayer : public Player
{
    QwixScoreSheet sheet;

  public:
    QwixPlayer(QwixScoreSheet &, string _name);
    virtual void inputBeforeRoll(RollOfDice &) override;
    virtual void inputAfterRoll(RollOfDice &) override;
};

#endif //QWIXPLAYER