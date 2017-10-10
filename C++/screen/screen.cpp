#include "screen.h"
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
    if(hor == 0 && (ver == -1 || ver == 0)){cout << "0 lines have been chosen, empty array will be printed" << endl; return;}
    if(hor >= g_height && ver >= g_width){cout << "ammount of lines is incopatable with screen size:" << g_width << "x" << g_height << ". Empty array will be printed"<<endl; return;}
    int space_h = g_height / (hor + 1);
    int space_v;
    //same ammount of lines
if (ver == -1) space_v = g_width / ( hor + 1);
else space_v = g_width / (ver + 1);
if(hor >= g_height/2 || ver >= g_width/2){cout << "Visual representation, which can have an equal ammount of space between lines, for the amount of line greater than the half of the screen size is unavaliable, aka it is all messed up" << endl; return;}

        for (int i = 1; i < hor + 1; ++i)
        {
            for (int k = 0; k < g_height; ++k)
            {
                for (int j = 0; j < g_width; ++j)
                {
                    if (k == i * space_h){
                        a[i * space_h][j] = '*';
                    }
                }                  
            }          
        }

        for (int i = 1; i < ver + 1; ++i)
        {
            for (int k = 0; k < g_height; ++k)
            {
                for (int j = 0; j < g_width; ++j)
                {
                    if (j == i * space_v){
                        
                        a[k][i * space_v] = '*';
                    }
                }                  
            }            
        }

        
   // a[0][0] = '1';
   // a[0][g_width - 1] = '2';
   // a[g_height-1][0] = '3';
  //  a[g_height-1][g_width-1] = '4';
}