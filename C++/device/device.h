#include <string>
#include <iostream>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::ostream;

#ifndef DEVICE
#define DEVICE

struct DateOfManufacture
{
    int day;
    int month;
    int year;
    string to_String();
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
    string toStr(Type &t);
    string to_String();
    ~Device();
    Device(const Device &d);

  private:
    string name;
    Type type;
    DateOfManufacture date;
};

class ChargeStack
{
    vector<Device> charger;

  public:
    ChargeStack();
    void push(Device &d);
    Device &pop();
    void print(ostream &out);
};

#endif //DEVICE