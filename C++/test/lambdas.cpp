#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <fstream>
#include <algorithm>

using namespace std;

int main(){
    int b= 2, c = 5;
    string a = "inside lambda";
    string g = " here";
    auto vala = [=]() mutable {return b++;};
   // ++b;
    cout << vala() << endl;
    cout << b << endl;

// const vector<string>::size_type sz = 10;
// vector<string> sVec( sz, "abc" );
// for(auto e : sVec) cout << e << " ";
// cout << endl;
// std::fill_n( sVec.begin() + 3, 4, string("xyz"));
// for(auto e : sVec) cout << e << " ";
// cout << endl;
// auto lastU = unique( sVec.begin(), sVec.end());
// for(auto e : sVec) cout << e << " ";
// cout << endl;
}