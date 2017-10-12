#include "chargeStack.h"
#include "device.h"

void ChargeStack::push(Device d)
{
    charger.push_back(d);
}

Device ChargeStack::pop()
{
  //Device d = charger.pop_back();
}

void ChargeStack::print(ostream &out){
    for (Device d : charger)
    out << "hello" << endl;
    //return out;
}