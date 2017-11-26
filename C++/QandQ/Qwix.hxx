// #ifndef QWIXROW
// #define QWIXROW
template <class T, const ScoreSheet::Color C>
int& QwixRow<T, C>::operator[](int index){
   return row[index];
}
// template <class T, const ScoreSheet::Color C>
// ostream &operator<< <>(ostream & out, const QwixRow<>& qr){
//     for (auto i : qr.row){
//         out << i;
//     }
//     return out;
// }
//#endif //QWIXROW