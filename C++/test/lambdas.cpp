#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <fstream>


using namespace std;

int main(){
    int b= 2, c = 5;
    string a = "inside lambda";
    string g = " here";
    auto vala = [=, &a] () mutable {return g + a;};
    ++b;
    cout << vala() << endl;
    cout << a << endl;
}