#include "ScoreSheet.h"

// int raw[16];
// Colour c;

int& QwintoRow::operator[](int index){
    assert(index >=0 && index < 16);
    return row[index];

}
bool checkAdd(int place); 


int main (){
    //testing

}