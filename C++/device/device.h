#include <string>
#include <iostream>

#ifndef DEVICE
#define DEVICE
using namespace std;

struct DateOfManufacture
{
    int day;
    int month;
    int year;
    void print(ostream &print);
};


class Device
{

  public:
    enum Type
    {
        phone,
        tablet,
        watch,
        laptop
    };
    Device(string n, Type t, DateOfManufacture d);   
    string toStr (Type& t);

  private:
    string name;
    Type type;
    DateOfManufacture date;
};

#endif //DEVICE