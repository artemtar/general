#ifndef SCREEN
#define SCREEN

static const int g_height = 40;
static const int g_width = 40;

    void screen(int w, int h);
    void clearScreen(char (&a)[g_height][g_width]);
    void printScreen(char (&a)[g_height][g_width]);
    void gridScreen(char (&a)[g_height][g_width], int x, int y);
    void gridScreen(char (&a)[g_height][g_width], int x);

    #endif // SCREEN