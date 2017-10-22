#include "oldstring.h"
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>

using namespace std;

Oldstring::Oldstring(string s) : data(s)

{
    p_str = new char[s.size() + 1];
    strcpy(p_str, s.c_str());
    pos = 1; //starts counting
}

double Oldstring::mean(char *c)
{
    double sum = 0;
    while ((*c != '\0'))
        sum += static_cast<int>(*(c++));
    return sum / pointedSize;
}

double Oldstring::stdDev(char *c, double d)
{
    double var = 0;
    double s;
    while ((*c != '\0'))
    {
        
        var += pow(*c - d, 2);
        c++;
       
    }
    //s = sqrt(var / (pointedSize - 1));
   // return s;
    return sqrt(var / (pointedSize - 1));
}

string Oldstring::getWord(char *c)
{

    string word = "";
    if (*(p_str) == '\0')
    {
        pos = -1;
        cout << "string is empty" << endl;
        return word;
    }
    if (pos < 0)
        return word;

    while ((*c == ' ') && (pos > 0))
    {
        c++; //haha
        pos++;
        if (*c == '\0')
        {
            pos = -1;
            return word;
        }
    }
    while (*c != ' ')
    {
        word += *c;
        c++;
        pos++;
        if (*c == '\0')
        {
            pos = -1;
            return word;
        }
    }
    return word;
}

void Oldstring::getstat()
{
    char *pass;
    while (pos < data.size()) //main loop for getting all calculation
    {
        string w = getWord(p_str + pos); //get next word
        pointedSize = w.size();
        pass = new char[w.size() + 1]; //temprely holder
        strcpy(pass, w.c_str());
        double m = mean(pass);
        double dev = stdDev(pass, m);
        cout << "Mean of " + w + ": " << m << endl;
        cout << "Standard deviation of " + w + ": " << dev << endl;
    }
    delete[] pass;
    delete_array(); // optional, not needed if you still need the array
}
char *Oldstring::getPtr() { return p_str + pos; }

void Oldstring::delete_array() { delete[] p_str; }