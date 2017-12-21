#include <iostream>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <fstream>
#include <algorithm>
using namespace std;
template<typename T>
class A
{
    T* d_a;
    T d_sz;

  public:
    A(T sz ) : d_sz(sz)
    {
        d_a = new T[d_sz];
    }
    A &operator=(const A &a){
        if (this != &a)
        {
            if (d_a != nullptr)
                delete d_a;
            d_sz = a.d_sz;
            d_a = new T[d_sz];
            for (int i = 0; i < d_sz; ++i)
            {
                *(d_a + i) = *(a.d_a + i);
            }
        }
        return *this;
    }
    friend ostream& operator<<(ostream& os, A<T> a){
        for(int i; i < a.d_sz; ++i) cout << a.d_a[i] << " ";
        os << endl;
        return os;
    }
};

class Integer
{
    int i;

  public:
    Integer operator++(int){     
        Integer temp(*this);   
        i++;        
        return temp;
    }
    Integer(int integer = 8) : i{integer}{} 
    friend ostream& operator << (ostream& os, const Integer& inter){
        os << inter.i << " result" << endl;
        return os;
    }
};

class Couple
{
    int a, b;

  public:
    Couple(int a, int b) : a(a), b(b) {}
    friend ostream& operator<< (ostream& os, Couple& c){
         os << "(" << c.a << "," << c.b << ")" << endl;
         return os;
     }
};

int main()
{
    // A<int> a1(3);
    // A<int> a2(2);
    // cout << a1 << a2;
    // a2 = a1;
    // a1 = a1;
    // cout << a2 << " " << a1;
    // cout << a2 << " " << a1 << endl;
    Couple c(3, 2);
    // // Desired output: c=(3,2)
    std::cout << "c =" << c;
//     Integer myInt;
//    Integer inter = myInt++;
//     cout << myInt;
//     cout << inter << "previous" << endl;
    return 0;
}