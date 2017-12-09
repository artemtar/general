#include "ScoreSheet.h"

//**ScoreSheet**

//constructor
ScoreSheet::ScoreSheet(string name) : name_player(name), num_failed(0)
{
 
}
//same as always, not sure if you need it, you just defining default constructor
ScoreSheet::ScoreSheet(const ScoreSheet &from) : name_player(from.name_player), overallScore(from.overallScore), num_failed(from.num_failed)
{
   
}
ScoreSheet::~ScoreSheet() {}

//to add fail into num_fail
void ScoreSheet::addFail()
{
    this->num_failed++;

}
int ScoreSheet::setTotal()
{
    overallScore = calcTotal();
    return overallScore;
}
//if fails is 4, stop the game
bool ScoreSheet::operator!()
{
    cout << "this line should not appeatr";
}

//to print out ScoreSheet
ostream &operator<<(ostream &out, const ScoreSheet &s)
{
    out << endl;
    out << "\tPlayer's Name: " << s.name_player << endl;
    s.print(out);
    cout << endl;
    cout << "\tFails: ";
    int count = 1;

    cout << s.num_failed;
    
    return out << endl;
}
//-----End of Scoresheet


//-----Initialization of QwintoScoresheet
//constructor
QwintoScoreSheet::QwintoScoreSheet(string name)
    : ScoreSheet(name), red(QwintoRow<RED>{}), yellow(QwintoRow<YELLOW>{}), blue(QwintoRow<BLUE>{}) {}                                                  // Aleks moved row to be created inside initializetion list
QwintoScoreSheet::QwintoScoreSheet(const QwintoScoreSheet &from) : ScoreSheet(from.name_player), red(from.red), yellow(from.yellow), blue(from.blue) {} //need to give a name

//template<class T>
bool QwintoScoreSheet::validate(int index, ScoreSheet *sheet, RollOfDice *rollOfDices)
{
    bool out = false;

    QwintoScoreSheet *qwintoSheet = dynamic_cast<QwintoScoreSheet *>(sheet);

    if ((*qwintoSheet).red.chosen)
    {
        out = (*qwintoSheet).red.validate(index, *rollOfDices);
        return out;
    } //convering RollOfDices to int
    else if ((*qwintoSheet).yellow.chosen)
    {
        out = (*qwintoSheet).yellow.validate(index, *rollOfDices);
        return out;
    }
    else if ((*qwintoSheet).blue.chosen)
    {
        out = (*qwintoSheet).blue.validate(index, *rollOfDices);
        return out;
    }

    //clean up //make the rows unchosen again
    (*qwintoSheet).red.chosen = false;
    (*qwintoSheet).yellow.chosen = false;
    (*qwintoSheet).blue.chosen = false;

}

bool QwintoScoreSheet::checkForFail(RollOfDice *rollOfDice, ScoreSheet *scoreSheet)
{
   

    QwintoScoreSheet *qwintoSheet = dynamic_cast<QwintoScoreSheet *>(scoreSheet);
    bool outR = true;
    bool outY = true;
    bool outB = true;


    for (int i = 1; i < 10; i++)
    {

        //if found a place
        qwintoSheet->red.chosen = true;
        if (QwintoScoreSheet::validate(i, scoreSheet, rollOfDice))
        {
            outR=false;
        }
        qwintoSheet->yellow.chosen = true;
        if (QwintoScoreSheet::validate(i, scoreSheet, rollOfDice))
        {
            outY=false;
        }
        qwintoSheet->blue.chosen = true;
        if (QwintoScoreSheet::validate(i, scoreSheet, rollOfDice))
        {
            outB=false;
        }
    }
    if ((outR+outY+outB)>=3){return true;}
    else{return false;}
}

//to check if can put in the position
bool QwintoScoreSheet::score(RollOfDice *rd, ScoreSheet::Color c, int pos)
{
    bool colourCondition = false;
    bool positionCondition = false;

    for (Dice &d : *rd)
    {
        if ((c == d.c) && (d.isEnabled))
        {
            colourCondition = true;
        }
    }
    //mark the chosen colour
    switch (c)
    {
    case RED:
    {
        (*this).red.chosen = true;
        break;
    }
    case YELLOW:
    {
        (*this).yellow.chosen = true;
        break;
    }
    case BLUE:
    {
        (*this).blue.chosen = true;
        break;
    }
    }

    //check if position is ok
    positionCondition = validate(pos, this, rd);
    
    
    //cout<<(colourCondition==true)<<"hi"<<(positionCondition==true)<<endl;

    if (colourCondition && positionCondition)
    {
        switch (c)
        {
        case RED:
        {
            (*this).red[pos-1] = *rd;
            break;
        }
        case YELLOW:
        {
            (*this).yellow[pos-1] = *rd;
            break;
        }
        case BLUE:
        {
            (*this).blue[pos-1] = *rd;
            break;
        }
        }

        return true;
    }
    else
    {
        return false;
    }
}
int QwintoScoreSheet::calcLine(int a, int b, int c, int val)
{
    if (a > 0 && b > 0 && c > 0)
        return val;
    else
        return 0;
}
//get the toral
int QwintoScoreSheet::calcTotal()
{
    //calculating rows
    int rowsTotal = 0;
    if (red.isFull())
        rowsTotal += red[9];
    else
        rowsTotal += red.amountNums();
    if (yellow.isFull())
        rowsTotal += yellow[9];
    else
        rowsTotal += yellow.amountNums();
    if (blue.isFull())
        rowsTotal += blue[9];
    else
        rowsTotal += blue.amountNums();
    //calculating columns
    //cout << endl <<"rows " <<rowsTotal << endl;
    int colTotal = 0;
    colTotal += calcLine(red[0], yellow[1], blue[2], blue[2]);
    colTotal += calcLine(red[1], yellow[2], blue[3], red[1]);
    colTotal += calcLine(red[5], yellow[6], blue[7], red[5]);
    colTotal += calcLine(red[6], yellow[7], blue[8], yellow[7]);
    colTotal += calcLine(red[7], yellow[8], blue[9], blue[9]);

    return rowsTotal + colTotal - 5 * this->num_failed;
}
//have to be polimorphic
bool QwintoScoreSheet::operator!()
{
    if (num_failed == 4)
    {
        return true;
    }
    //checking if two rows are full
    int check = red.isFull() + yellow.isFull() + blue.isFull();
    if (check < 2)
        return false;
    else
        return true;
}
//to put on the stream
ostream &operator<<(ostream &os, const QwintoScoreSheet &qss)
{
    return qss.print(os);
    os << endl;
}
ostream &QwintoScoreSheet::print(ostream &out) const
{   
    cout << endl;
    out << "\t\t\t-------------------------------" << endl;
    out << "\tRed";
    out << "\t\t" << red << endl;
    out << "\t\t     -------------------------------" << endl;
    out << "\tYellow";
    out << "       " << yellow << endl;
    out << "\t\t    -------------------------------" << endl;
    out << "\tBlue";
    out << "      " << blue << endl;
    out << "\t\t  -------------------------------" << endl;
    return out;
}

//-----End of QwintoScoreSheet

//-----Initialization of QwixScoreSheet

QwixScoreSheet::QwixScoreSheet(string name, int* locks): ScoreSheet(name), player_locks{locks}{}

bool QwixScoreSheet::validate(int index,ScoreSheet* sheet,RollOfDice* rollOfDices){}
//recursion that calculates score
int QwixScoreSheet::calcHelper(int i){
    if (i == 1){
    return 1;

    }
    else
    {
        int result = 0;
        result += calcHelper(i - 1) + i;
        return result;
    }
}
 bool QwixScoreSheet::checkForFail(RollOfDice* rd,ScoreSheet* sheet){
     if(*rd == sheet->num_failed - 4 ) return true;
      return false;
 }
bool QwixScoreSheet::score(RollOfDice* rd, Color c, int pos){}
int QwixScoreSheet::calcTotal()
{

    int total = 0;
    int redrow = red.calcRow();
    int bluerow = blue.calcRow();
    int greenrow = green.calcRow();
    int yellowrow = yellow.calcRow();
    total = calcHelper(redrow) + calcHelper(bluerow) + calcHelper(yellowrow) + calcHelper(greenrow);
    return total - 5 * num_failed;
}
bool QwixScoreSheet::operator!()
{
    if (num_failed != 4)
         return true;
    int locks = 0;
    for (int i = 0; i < 4; --i){
        locks += *(player_locks + i);
    }
    if(locks < 2) return true;

    //checking if two rows are full
    else
        return false;
}
//to put on the stream
ostream &operator<<(ostream &os, const QwixScoreSheet &qss)
{
    return qss.print(os);
    os << endl;
}

//
ostream &QwixScoreSheet::print(ostream &out) const
{



cout << endl;
    out << "\t\t----------------------------------" << endl;
    out << "\tRed";
    out << "\t" << red;
    if(*player_locks == 0) out << " U" << endl;
    else out << " L"<< endl;
    out << "\t\t----------------------------------" << endl;
    out << "\tYellow";
    out << "\t" << yellow;
    if(*player_locks == 0) out << " U" << endl;
    else out << " L"<< endl;
    out << "\t\t----------------------------------" << endl;
    out << "\tGreen";
    out << "\t" << green;
    if(*player_locks == 0) out << " U" << endl;
    else out << " L"<< endl;
    out << "\t\t----------------------------------" << endl;
    out << "\tBlue";
    out << "\t" << blue;
    if(*player_locks == 0) out << " U" << endl;
    else out << " L"<< endl;
    out << "\t\t----------------------------------" << endl;  

    return out;
}


