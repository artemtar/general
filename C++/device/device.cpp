#include "device.h"

using std::endl;
using std::cerr;
using std::to_string;

Device::Device(string n, Type t, DateOfManufacture d) : name(n), type(t), date(d)
{
}

string Device::toStr(Type &enumVal)
{
    return (const char *[]){
        "Phone",
        "Tablet",
        "Watch",
        "Laptop",
    }[enumVal];
}

string DateOfManufacture::to_String()
{
    return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}

string Device::to_String()
{
    return name + " " + toStr(type) + " Date: " + date.to_String();
}
Device::~Device()
{
    cerr << "Destructing device: " << to_String() << endl;
}
Device::Device(const Device &d) : name(d.name),
                                  type(d.type),
                                  date(d.date)
{
    cerr << "Copied device: " << to_String() << endl;
}

void ChargeStack::push(Device &d)
{
    charger.push_back(d);
}

Device &ChargeStack::pop()
{
    Device &dev = charger.back();
    charger.pop_back();
    return dev;
}

void ChargeStack::print(ostream &out)
{
    for (auto &d : charger)
        out << d.to_String() << endl;
}

ChargeStack::ChargeStack() { charger.reserve(10); }