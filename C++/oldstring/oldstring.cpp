#include "oldstring.h"
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>

using namespace std;

Oldstring::Oldstring(string s) : data(s)

{
    //const char *pS = s.c_str();
    p_str = new char[s.size() + 1];
    strcpy(p_str, s.c_str());
    pos = 0;
    //copy(s.begin, s.end, p_str);
    //p_str[s.size()] = '\0';
}

double Oldstring::mean(char *c)
{
    int sum = 0;
    while ((*c != ' ') || (*c != '\0'))
        sum += static_cast<int>(*(c++));

    return sum / data.size();
}

double Oldstring::stdDev(char *c, double d)
{
    double m = mean(c);
    double dev = pow(m, 2);
    return sqrt(dev / (data.size() - 1));
}

string Oldstring::getWord(char *c)
{
    cout << "run2" << *(c+2) << endl;
    string word = "";
    if (*c == '\0')
    {
        pos = -1;
        return word;
    }
    while ((c[pos] == ' ') && (pos > 0))
    {
        pos++;
        if (c[pos] == '\0')
        {
            pos = -1;
            return word;
        }
    }

    while (*(c + pos) != ' ')
    {
        word += *(c + pos);
        pos++;
        if (c[pos] == '\0')
        {
            pos = -1;
            return word;
        }
    }

    return word;
}

void Oldstring::getstat()
{
        cout << "run" << endl;
        string w = getWord(p_str);
        cout << w << endl;
    
}
char* Oldstring::getPtr(){return p_str;}