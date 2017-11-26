#include "ScoreSheet.h"

//-----initialization of parent Scoresheet
ScoreSheet::ScoreSheet(string name) : name_player(name) {}

bool ScoreSheet::operator!()
{
    if (num_failed == 4)
        return true;
    else
        return false;
}
ostream& operator<<(ostream& out, const ScoreSheet& s){
    out << s.name_player;
    return out;
}
//-----End of Scoresheet

//-----Initialization of QwintoScoresheet
QwintoScoreSheet::QwintoScoreSheet(string n, QwintoRow<RED> r, QwintoRow<YELLOW> y,QwintoRow<BLUE> b) : ScoreSheet(n), red(r), yellow(y), blue(b) {}
bool QwintoScoreSheet::score(RollOfDice rd, Color c, int pos) {

}
int QwintoScoreSheet::calcTotal(){

}
bool QwintoScoreSheet::operator!() {

}
ostream& operator<<(ostream& out, const QwintoScoreSheet& qss){
//ScoreSheet parent = qss;
//out << parent;
out << "------------------------------" << endl;
out << qss.red;
out << "  ------------------------------" << endl;
out << qss.yellow;
out << "    ------------------------------" << endl;
out << qss.blue;

return  out;
}
//-----End of QwintoScoreSheet
int main()
{
    //testing
    QwintoRow<ScoreSheet::Color::RED> qr;
    QwintoRow<ScoreSheet::Color::YELLOW> qy;
    QwintoRow<ScoreSheet::Color::BLUE> qb;
    RollOfDice r;
    int i = r;
    cout << r;
    cout << "total is:";
    cout << i << endl;
    qr[2] = 666666666;
    cout << qr;
    //QwintoScoreSheet qs("name", qr, qy, qb);
}