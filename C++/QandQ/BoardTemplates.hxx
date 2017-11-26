class ScoreSheet;
//implementing Qwinto board

#ifndef QWINTOROW
#define QWINTOROW
template <const ScoreSheet::Color C>
bool QwintoRow<C>::validate(int index)
{
    //out of range
    if (index > 16 || index < 0)
        return false;
    //has input already
    else if (row[index] != -1)
        return false;
    else
        return true;
}

template <const ScoreSheet::Color C>
int &QwintoRow<C>::operator[](int index)
{
    if (bool (*check)(int))
        return row[index];
    //if cannot insert return -1 for error check
    else
        return -1;
}
#endif //QWINTOROW

#ifndef QWIXROW
#define QWIXROW
// template <class T, const ScoreSheet::Color C>
// int& QwixRow<T, C>::operator[](int index){
//    return row[index];
// }
#endif //QWIXROW