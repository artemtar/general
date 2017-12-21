#include <memory>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <typeinfo>
#include <algorithm>
using namespace std;

void printVec(vector<string>::reverse_iterator iter, vector<string>::reverse_iterator iterend ){
    while(iter != iterend){
        cout << *iter << endl;
        iter++;
    }

}
class A{virtual void foo(){}};
class B : public A{};
int f(int x){
    if (x < 0) throw 'N';
    return x * 2;
}
int main(){

    vector<string> s = {"new", "vector", "and whatever"};
    printVec(s.rbegin(), s.rend());
    vector<int>v = {1,0,2,0,3,4,5};
    replace_if(v.begin(), v.end(), [](int e){return e==0;}, 1);
    cout << "replace if" << endl;
    for(auto a : v)  cout << a << endl;

      B b;
      A& obja = b;
    try{
        B& objb = dynamic_cast<B&>(obja);
    } catch (bad_cast){
        cout << "cast failed" << endl;
    }

    int tab[5] = {1,2,3,4,5};
    vector<int> v1 (tab, tab + 5);
    cout << "v1 ";
    for (auto e : v1) cout << e << " ";
    cout << endl;
    vector<int> v2(5);
    copy(tab, tab + 5, v2.begin());
    for(auto e : v2) cout << e + 100 << " ";
    cout << endl;
    try{
    int i = f(-2);
    cout << i << endl;}
    catch(char c){cout << "is negative" << c << endl;}
    int **tabb = new int* [3];
    int* temp = new int[5 * 3];
    for(int i = 0; i < 3; ++i){
        tabb[i] = &temp[i*5];
    }
}