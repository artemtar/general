#include <vector>
#include "device.h"
#ifndef CHARGESTACK
#define CHARGESTACK
using std::vector;

class ChargeStack
{
    vector<Device> charger;

  public:
    void push(Device d);
    Device pop();
    void print(ostream &out);
};

#endif //CHARGESTACK