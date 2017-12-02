//class ScoreSheet;
//implementing Qwinto board

// #ifndef QWINTOROW
// #define QWINTOROW
static int DEFAULT_ELEMENT = -1;
template <const ScoreSheet::Color C>
QwintoRow<C>::QwintoRow()
{
    for (int i = 0; i < 10; ++i)
    {
        row[i] = -1;
    }
}

template <const ScoreSheet::Color C>
bool QwintoRow<C>::validate(int index)
{
    //out of range
    if (index > 10 || index < 0)
        return false;
    //has input already
    else if (row[index] != -1)
        return false;
    else
        return true;
}
//have to decide how to return nothing if not passing validate
template <const ScoreSheet::Color C>
int &QwintoRow<C>::operator[](int index)
{
    //
    if (validate(index))
        return row[index];
    //if cannot insert return -1 for error check
    else
        throw;//not sure if correct, check latter

}
//returns true if row is full
template <const ScoreSheet::Color C>
bool QwintoRow<C>::isFull()
{
    int count = 0;
    for (int i = 0; i < 10; ++i)
    {
        if (row[i] != -1)
            ++count;
    }
    if (count == 9)
        return true;
    else
        return false;
}
//counts how many numbers in row
template <const ScoreSheet::Color C>
int QwintoRow<C>::amountNums()
{
    int count = 0;
    for (int i = 0; i < 10; ++i)
    {
        if (row[i] != -1)
            ++count;
    }
    return count;
}
// template <const ScoreSheet::Color C>
// ostream &operator<<(ostream& out, const QwintoRow<C>& qr){
//     for (auto i : qr.row){
//         out << i;
//     }
//     return out;
// }
//#endif //QWINTOROW
