#include "scoresheet.h"
#ifndef PLAYER
#define PLAYER

class Person
{
    string d_lastName;
    string d_firstName;
    ScoreSheet score;
    int d_sin;

  public:
    Person(const string &_firstName = "",
           const string &_lastName = "");
    ~Person()
    {
        cout << "~Person: " << d_lastName << endl;
    }
    void setScore(ScoreSheet s);
    friend istream &operator>>(istream &, Person &);
    friend ostream &operator<<(ostream &, const Person &);
};


#endif //PLAYER