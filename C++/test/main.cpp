//thisngs to check:
//creating custom destructor, binding12, capture list12 for lambda, when dynamicly castubg what we get after assignemnt
//cout operator, open files, thourough declaration

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <fstream>


using namespace std;
class Addition {
    int point;
    public:
    Addition(int i): point{i}{}
    Addition() = default;
        Addition operator+ (const Addition& _toadd)const{
            Addition a;
            a.point = point + _toadd.point;
            return a;
        }
        Addition& operator+=(const Addition& rhs){
            point += rhs.point;
            return *this;
        }
        Addition& operator++ (){
            point++;
            return *this;
        }
        Addition (string s):point{10}{}
        operator string () {
            return "i am new string";
        }        
        friend ostream& operator<< (ostream& out, const Addition n){
            out << n.point;
            return out; 
        }
};

int main(){

Addition ass(5);
Addition asss(3);
Addition q = ass+asss;
string s = q;
q = s;
cout << q << s << endl;
}