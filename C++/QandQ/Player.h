#include "ScoreSheet.h"
#ifndef PLAYER
#define PLAYER

class Person
{
    string name;
    bool status;

  public:
    Person(const string &_name = "");
    ~Person()
    {
        cout << "~Person: " << d_lastName << endl;
    }
    inline bool getStatus();
    void setScore(ScoreSheet s);
    virtual void inputBeforeRoll(RollOfDice&) = 0;
    virtual void inputAfterRoll(RollOfDice&) = 0;
    friend istream &operator>>(istream &, Person &);
    friend ostream &operator<<(ostream &, const Person &);
};


#endif //PLAYER

#ifndef QWINTOPLAYER
#define QWINTOPLAYER

class QwintoPlayer:public Player{
    QwintoScoreSheet sheet;
public:
    QwintoPlayer(QwintoScoreSheet&);
    void inputBeforeRoll(RollOfDice&);
    void inputAfterRoll(RollOfDice&);
};

#endif //QWINTOPLAYER


#ifndef QWIXXPLAYER
#define QWIXXPLAYER

class QwixxPlayer:public Player{
    QwintoScoreSheet sheet;
public:
    QwixxPlayer(QwintoScoreSheet&);
    void inputBeforeRoll(RollOfDice&);
    void inputAfterRoll(RollOfDice&);
};

#endif //QWIXXPLAYER