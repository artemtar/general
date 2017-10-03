#include "screen.h"
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>

void screen(int w, int h){

}
void clearScreen(char **a){
    int r = sizeof a / sizeof a[0];
    int c = sizeof a[0] / sizeof(char);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            a[i][j] = ' ';
}
void printScreen(int **a){

}
void gridScreen(int **a, int x, int y){

}