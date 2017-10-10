#ifndef SCREEN
#define SCREEN

static const int g_height = 20;
static const int g_width = 40;

    void screen(int w, int h);
    void clearScreen(char (&a)[g_height][g_width]);
    void printScreen(char (&a)[g_height][g_width]);
    void gridScreen(char (&a)[g_height][g_width], int x, int y = -1);
    

    #endif // SCREEN