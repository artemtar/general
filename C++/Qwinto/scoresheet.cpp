#include "scoresheet.h"
#include <ctime>
#include <time.h>
ScoreSheet::ScoreSheet(string name, string lastName) : name_player(name + " " + lastName)
{
}
void ScoreSheet::print(const ostream &os) const
{
    //os << name_player << "scored " << score_overall << "points: ";
}
void ScoreSheet::score(vector<Dice> d)
{
    //int score
}

//Dice
void Dice::roll()
{
    srand(time(NULL));
    dice = (rand() % 6) + 1;
}
void Dice::print()
{

    cout << "The first Dice rolled a "
         << "." << endl;

    cout << "The second Dice rolled a "
         << "." << endl;

    cout << "Adding both dices up you rolled a total of: " << endl;
}

//Person
Person::Person(const string &_firstName, const string &_lastName)
    : d_firstName(_firstName), d_lastName(_lastName), d_sin(0)
{
    d_sin = rand();
    cout << "new Person" << endl;
}
istream &operator>>(istream &_is, Person &_p)
{
    _is >> _p.d_firstName >> _p.d_lastName >> _p.d_sin;
    // check for failure
    if (!_is)
        _p = Person();
    return _is;
}
ostream &operator<<(ostream &_os, const Person &_p)
{
    _os << _p.d_firstName << "\t" << _p.d_lastName << "\t";
    _os << _p.d_sin;
    return _os;
}
void Person::setScore(ScoreSheet s){score = s;}
int main()
{
    
    fstream ioFile;
    Person personA, personB;
    // read personA from console
    cin >> personA;
    ScoreSheet s(<<personA);
    //cout << personA;
    cout << "-------------------" << endl;
    // output personA to file
    ioFile.open("people.txt", ios::out);
    ioFile << personA;
    ioFile.close();
    // read personB from file
    ioFile.open("people.txt", ios::in);
    ioFile >> personB;
    ioFile.close();
    // output personB to console
    cout << "Person: " << personB << endl;

    string board[12][34] = {};

    for (int i = 0; i < 12; i +=3)
    {
        // cout << endl;
        
        // string s(3*(4-i), ' ');
        // cout << s;
        for (int j = 0; j < 34; ++j)
        {
            board[i][j] = '_';
        }
    }
    cout << endl;
    for (int k = 0; k < 14; ++k)
    {
        cout << endl;
        if (k == 2) cout << "Red";
        if (k == 5) cout << "Yellow";
        if (k == 8) cout << "Blue";
        for (int l = 0; l < 32; ++l)
        {
            cout << board[k][l];
        }
    }

    return 0;
}