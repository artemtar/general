#include <iostream>
#include <string>
#include "oldstring.h"
using namespace std;

int main()
{
    string i;
    string input;
    while (true)
    {
        cout << "Input: ";
        cin >> input;
        if (input == "stop")
        break;
        i = i + " " + input;
    }
    Oldstring olds (i);
    char* n = olds.getPtr();
    cout << "pointer" << n[1] << endl;
    

    cout << "The value you entered is " << i << endl;
    olds.getstat();
    return 0;
} 