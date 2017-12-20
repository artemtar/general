#include <memory>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <typeinfo>
#include <algorithm>
using namespace std;

void printVec(vector<string>::reverse_iterator iter, vector<string>::iterator iterend){
    while(iter != iterend){
        cout << *iter << endl;
        iter++;
    }

}

int main(){
    vector<string> s = {"new", "vector", "and whatever"};
    printVec(s.rend(), s.begin());
}