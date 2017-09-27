#include <string>
using namespace std;
#ifndef OLDSTRING
#define OLDSTRING

class Oldstring{
    string data;
    char *p_str;
    int pos;

public:
    Oldstring(string s = "");
    double mean(char* c);
    double stdDev(char* c, double d);
    string getWord(char* c);
    void getstat();
    char* getPtr();
};


#endif // OLDSTRING