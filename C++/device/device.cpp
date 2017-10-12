#include <string>
#include <iostream>
#include "device.h"

using namespace std;

Device::Device(string n, Type t, DateOfManufacture d) : name(n), type(t), date(d) {}

void print(ostream &out)
{
    out << "hello " << endl;
}
string Device::toStr(Type &enumVal)
{
    return (const char *[]){
        "phone",
        "tablet",
        "watch",
        "laptop",
    }[enumVal];
}

void DateOfManufacture::print(ostream &out)
{
    out << "day: " << day << ","
        << "month: " << month << ","
        << "year: " << year << endl;
}
