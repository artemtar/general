#include "rectangle.h"
#include <iostream>
#include <vector>
using namespace std;
int main(){
    Rectangle r1, r2;
    r1.setVal(3,4,12,8);
    r2.setVal(8,8,10,11);
    Rectangle r3 = r1.intersection(r2);
    r1.setVal(3,4,12,8);
    r2.setVal(4,1,13,2);
    r3 = r1.intersection(r2);
    r1.setVal(14,2,16,6);
    r2.setVal(3,4,12,8);
    r3 = r1.intersection(r2);
    r1.setVal(3,4,12,8);
    r2.setVal(1,2,15,10);
    r3 = r1.intersection(r2);
    vector <Rectangle> v;
    v = r1.split();
    for(int i = 0; i < 4; i++){
       ((Rectangle) v[i]).print();
       cout << endl;
    }
}