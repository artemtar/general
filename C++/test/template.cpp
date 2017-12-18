#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <fstream>
#include "example.h"
using namespace std;

// template<> 
// void foo(){
//     cout << "no template" << endl;
// }
int main(){
Temp<int, 1> ca{1};
Temp<int, 1> c2{2};
Temp<char, 1> c3{'e'};
c3.foo();

foof<int>();
foof<double>();

}
