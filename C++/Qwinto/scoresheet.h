#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>

class Person;
// rand() requires

using namespace std;
using std::string;
using std::ostream;
using std::vector;
using std::cout;
using std::istream;
using std::endl;
using std::fstream;
using std::cin;
using std::ios;

static const int g_height = 3;
static const int g_width = 14;
class ScoreSheet
{
    enum Colour
    {
        RED,
        YELLOW,
        BLUE
    };
    //The class ScoreSheet should hold the scores for the 3 colours, the name of
    // the player, the number of failed attempts and the overall score.
    int score_red[16] , score_yellow[16], score_blue[16] = {};
    int score_3colours[g_height][g_width];
    int score_overall;
    int num_failed[];
    string name_player;
    //Give the class ScoreSheet a print function that accepts an std::ostream and
    // inserts the score sheet formatted as in the above example into the stream.
  public:
    ScoreSheet(string name = "", string lastName = "");
    void print(const ostream &os) const;
    //void score(vector<Dice> d);
};


istream &operator>>(istream &, Person &);
ostream &operator<<(ostream &, const Person &);

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