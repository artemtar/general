#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>

using std::string;
using std::ostream;
using std::vector;
using std::cout;
using std::istream;
using std::endl;
using std::fstream;
using std::cin;
using std::ios;
#ifndef SCORESHEET
#define SCORESHEET

static const int g_height = 3;
static const int g_width = 14;

class ScoreSheet
{
    //The class ScoreSheet should hold the scores for the 3 colours, the name of
    // the player, the number of failed attempts and the overall score.
    int score_red[], score_yellow[], score_blue[];
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

#endif //SCORESHEET