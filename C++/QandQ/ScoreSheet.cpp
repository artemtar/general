#include "ScoreSheet.h"

//-----initialization of parent Scoresheet
ScoreSheet::ScoreSheet(string name) : name_player(name)
{
    for (int i = 0; i < 4; ++i)
    {
        num_failed[i] = -1;
    }
}

bool ScoreSheet::operator!()
{
            if (num_failed[3] == 4)
        return true;
    else
        return false;
}
ostream &operator<<(ostream &out, const ScoreSheet &s)
{
    out << s.name_player;
    return out;
}
//-----End of Scoresheet

//-----Initialization of QwintoScoresheet
QwintoScoreSheet::QwintoScoreSheet(string n, QwintoRow<RED> r, QwintoRow<YELLOW> y, QwintoRow<BLUE> b) : ScoreSheet(n), red(r), yellow(y), blue(b) {}
bool QwintoScoreSheet::validate(int index)
{
}
bool QwintoScoreSheet::score(RollOfDice rd, Color c, int pos)
{
}
int QwintoScoreSheet::calcTotal()
{
}
bool QwintoScoreSheet::operator!()
{
    ScoreSheet& parent = *this;
    if(!parent) return false;
    //more code is comming
    
}
const int* ScoreSheet::getFails()const{
    return num_failed;
}
ostream &operator<<(ostream &out, const QwintoScoreSheet &qss)
{
    const ScoreSheet *parent = &qss;
    out << *parent << endl;
    out << "    -------------------------" << endl;
    out << "    " << qss.red << endl;
    out << "  -------------------------" << endl;
    out << "  " << qss.yellow << endl;
    out << "-------------------------" << endl;
    out << "" << qss.blue << endl << endl;
    out << "Failed: ";
    for(int i = 0; i < 4; ++ i){
        if(*(parent->getFails() + i) != 100)//for debuging change 100 to -1 when finished
            cout <<  *(parent->getFails() + i) << " ";
    }
    cout << endl;
    return out;
}
//-----End of QwixScoreSheet

//insert code for qwix

//-----Initialization of QwixScoreSheet


//-----End of QwintoScoreSheet
int main()
{
    //testing
    QwintoRow<ScoreSheet::Color::RED> qr;
    QwintoRow<ScoreSheet::Color::YELLOW> qy;
    QwintoRow<ScoreSheet::Color::BLUE> qb;
    RollOfDice r;
    cout << r << "roled" << endl;
    qr[2] = r;
    QwintoScoreSheet qs("Artem", qr, qy, qb);
    cout << qs;
}