#include "ScoreSheet.h"

ostream &operator<<(ostream & _os, const QwintoRow<C> &qr){
    for (auto i : row){
        _os << i;
    }
    return _os;
}




int main (){
    //testing
    //QwintoRow<ScoreSheet::Color::RED> qr;

}