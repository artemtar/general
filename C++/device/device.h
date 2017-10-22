#include <string>
#include <iostream>
#include <vector>

#ifndef DEVICE
#define DEVICE

using std::vector;
using std::string;
using std::cout;
using std::ostream;

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
    string toStr(Type t);
    string  to_String();
    ~Device();
    Device( Device& d);
    Device() = default;

  private:
    string  name;
    Type  type;
    DateOfManufacture date;
};

class ChargeStack
{
    vector<Device> charger;

  public:
    void push(Device d);
    Device pop();
    void print(ostream& out);
};

#endif //DEVICE