#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <array>
#include "funk.h"
using namespace std;
template <typename T>
void print(T i)
{
    cout << "this is whatever function " << i << endl;
}
void foo(string s)
{
    cout << s << endl;
}
struct Distance_x
{
    int x;
    Distance_x(int i) : x{i} {}
    void operator()(int &i)
    {
        cout << "distance " << x + i << endl;
    }
};
template<typename T>
class Test
{
    vector<T> d;
    public:
    Test(){d.push_back(5); d.push_back(6);}
    public: void printAll(void (*f)(T t)){
        for_each(d.begin(), d.end(), f);
    }
};
int main (){
vector<int> i;
i.push_back(1);
i.push_back(3);
print<int>(1);
print<string>("3");
for_each(i.begin(), i.end(), print<int>);
Test<int> gg;
Test<string> tt();
gg.printAll(print<int>);
gg.printAll([](int i){cout << "lambda" << i << endl;});
void (*ptr) (string t);
ptr = foo;
}