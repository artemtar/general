#include "screen.h"
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;
void screen(int w, int h)
{
}
void clearScreen(char (&a)[g_height][g_width])
{
    for (int i = 0; i < g_height; i++)
        for (int j = 0; j < g_width; j++)
            a[i][j] = ' ';
}
void printScreen(char (&a)[g_height][g_width])
{
    for (int i = 0; i < g_height; i++)
    {
        for (int j = 0; j < g_width; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
}
void gridScreen(char (&a)[g_height][g_width], int hor, int ver)
{
    int space_h = g_width / hor + 1;
    int space_v = g_height / ver + 1;
    //a[0][0] = '2';
   // a[1][0] = '3';
    char *r = a[0];
    //cout << "hi" << *r;
    for (int i = 0; i < hor; ++i)
    {
        for (int j = 0; j < g_height; ++j)
            if (j == i * space_h)
                *(r + j - 1) = '*';
               // cout << "hi" << *r;
    }
}