// #ifndef QWIXROW
// #define QWIXROW
template <class T, const ScoreSheet::Color C>
bool QwixRow<T, C>::validate(int index)
{
    //out of range
    if (index > 11 || index < 0)
        return false;
    //has input already
    else if (row[index] != -1)
        return false;
    else
        return true;
}
template <class T, const ScoreSheet::Color C>
int &QwixRow<T, C>::operator[](int index)
{
    return row[index];
}
template <class T, const ScoreSheet::Color C>
int &QwixRow<T, C>::operator+=(RollOfDice &) {

}
template <class T, const ScoreSheet::Color C>
bool QwixRow<T, C>::checkAdd(int) {

}
// template <class T, const ScoreSheet::Color C>
// ostream &operator<< <>(ostream & out, const QwixRow<>& qr){
//     for (auto i : qr.row){
//         out << i;
//     }
//     return out;
// }
//#endif //QWIXROW