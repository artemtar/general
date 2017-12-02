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
    s.print(out);
    for (auto i : s.num_failed)
    {
        out << i << " ";
    }
    return out << endl;
}
//-----End of Scoresheet

//-----Initialization of QwintoScoresheet
QwintoScoreSheet::QwintoScoreSheet(string n, QwintoRow<RED> r, QwintoRow<YELLOW> y, QwintoRow<BLUE> b) : ScoreSheet(n), red(r), yellow(y), blue(b) {}
bool QwintoScoreSheet::validate(int index)
{
}
bool QwintoScoreSheet::score(RollOfDice& rd, Color c, int pos)
{
    //more code is requered
    switch (c)
    {
    case ScoreSheet::Color::RED:
        red[pos] = rd; //do something, have to finish validation
        break;
    case ScoreSheet::Color::YELLOW:
        yellow[pos] = rd; //do something
        break;
    case ScoreSheet::Color::BLUE:
        blue[pos] = rd; //do something
        break;
    }
}
int QwintoScoreSheet::calcTotal()
{
    //calculating rows
    int rowsTotal = 0;
    if (red.isFull())
        rowsTotal += red[9];
    else
        rowsTotal = red.amountNums();
    if (yellow.isFull())
        rowsTotal += yellow[9];
    else
        rowsTotal = yellow.amountNums();
    if (red.isFull())
        rowsTotal += blue[9];
    else
        rowsTotal = blue.amountNums();
    //calculating columns
    int colTotal = 0;
    if (red[0] != -1 && yellow[1] != -1 && blue[3] != -1)
        colTotal += blue[3];
    if (red[1] != -1 && yellow[2] != -1 && blue[4] != -1)
        colTotal += red[1];
    if (red[5] != -1 && yellow[6] != -1 && blue[7] != -1)
        colTotal += red[5];
    if (red[6] != -1 && yellow[7] != -1 && blue[8] != -1)
        colTotal += yellow[7];
    if (red[7] != -1 && yellow[8] != -1 && blue[9] != -1)
        colTotal += blue[9];

    int fails = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (num_failed[i] != -1)
            fails += 1;
    }

    return rowsTotal + colTotal - 5 * fails;
}
bool QwintoScoreSheet::operator!()
{
    ScoreSheet &parent = *this;
    if (!parent)
        return false;
    //checking if two rows are full
    int check = red.isFull() + yellow.isFull() + blue.isFull();
    if (check < 2)
        return false;
    else
        return true;
}

ostream &operator<<(ostream &os, const QwintoScoreSheet &qss)
{
    return qss.print(os);
}
ostream &QwintoScoreSheet::print(ostream &out) const
{

    //ScoreSheet::print(out);
    // out << *parent << endl;
    out << "    -------------------------" << endl;
    out << "    " << red << endl;
    out << "  -------------------------" << endl;
    out << "  " << yellow << endl;
    out << "-------------------------" << endl;
    out << "" << blue << endl
        << endl;
    out << "Failed: ";
    //for (int i = 0; i < 4; ++i)
    // {
    //     if (*(parent->getFails() + i) != 100) //for debuging change 100 to -1 when finished
    //         cout << *(parent->getFails() + i) << " ";
    // }
    cout << endl;
    return out;
}
//-----End of QwixScoreSheet

//-----Initialization of QwixScoreSheet
QwixScoreSheet::QwixScoreSheet(string n, QwintoRow<RED> r, QwintoRow<YELLOW> y, QwintoRow<BLUE> b, QwintoRow<GREEN> g): ScoreSheet(n) {}
bool QwixScoreSheet::score(RollOfDice& rd, ScoreSheet::Color c, int pos) {}
bool QwixScoreSheet::validate(int i) {}
int QwixScoreSheet::calcTotal() {}
bool QwixScoreSheet::operator!() {}
ostream &operator<<(ostream &os, const QwixScoreSheet &qss)
{
    return qss.print(os);
}
ostream &QwixScoreSheet::print(ostream &out) const
{
}
//-----End of QwintoScoreSheet
// int main()
// {
//     //testing
//     QwintoRow<ScoreSheet::Color::RED> qr;
//     QwintoRow<ScoreSheet::Color::YELLOW> qy;
//     QwintoRow<ScoreSheet::Color::BLUE> qb;
//     RollOfDice r;
//     cout << r << "roled" << endl;
//     qr[2] = r;
//     QwintoScoreSheet qs("Artem", qr, qy, qb);
//     ScoreSheet& parent = qs;
//     cout << parent;
//     r.roll();
//     parent.score(r, ScoreSheet::Color::RED, 5);
//     cout << parent;

// }