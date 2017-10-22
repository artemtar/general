#include <string>
#include <iostream>
#include "device.h"

using namespace std;

Device::Device(string n, Type t, DateOfManufacture d) : name(n), type(t), date(d) 
{}

string  Device::toStr(Type enumval)
{
    return ( char *[]){
        "phone",
        "tablet",
        "watch",
        "laptop",
    }[enumval];
}

string DateOfManufacture::to_String()
{
   return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}

string Device::to_String() 
{
   return name + " " + toStr(type) + " date: " + date.to_String();
}
Device::~Device()
{
    cerr << "destructing device: " << to_String() << endl;
}
Device::Device( Device& d) : name(d.name), 
                                  type(d.type),
                                  date(d.date)
{
  cerr << "copied device: " << d.to_String() << " copy " << endl;
}

void ChargeStack::push(Device d)
{
charger.push_back(d);
//cout << "ahoq" << (charger.back()).to_string << "inside" << endl;
}

Device ChargeStack::pop()
{
   // cout << charger.size() << " ";
    Device dev = charger.back();
    charger.pop_back();
    //cout << charger.size() << endl;
    return dev;
}

void ChargeStack::print(ostream &out)
{
    for (auto d : charger)
        out << d.to_String() << endl;
}

