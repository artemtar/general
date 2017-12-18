#include <ostream>
#include <iostream>
using namespace std;
template <typename T, const int I>
class Temp {
    T i;
    public:
    Temp(T n) : i{n}{cout << "created " << n;}
    Temp operator+(const Temp& rhs){
        Temp res;
        res.i = i + rhs.i;
        return res;
    }
    Temp() = default;
    void foo();
    friend ostream& operator<<(ostream& os, const Temp<T, I>& t){
        os << t.i;
        return os;
    }
};
template<typename T, const int I>
void Temp<T, I>::foo(){cout << "whatever" << endl;} 

template <const int I>
class Temp<char, I> {
    char i;
    public:
    Temp(char n) : i{n}{cout << "created char" << endl;}
    public: void foo();
};
template <>
class Temp<char, 10> {
    char i;
    public:
    Temp(char n) : i{n}{cout << "created special char" << endl;}
};
template<const int I>
void Temp<char, I>::foo(){cout << "this is foo form char" << endl;} 

template <typename T> 
void foof(){
    T i;
    cout << "TEMPLATE" << endl;
}
template <> 
void foof<double>(){
    double i;
    cout << "this is double" << endl;
}