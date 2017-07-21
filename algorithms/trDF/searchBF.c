#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "QUEUE.h"
#define M 7
int graph[M][M];
int visited[M];
int goal;

int searchBF(int start)
{
    QUEUEinit();
}
void main(int argc, char *argv[])
{
    int i, j;
    goal = atoi(argv[1]);

    for (i = 0; i < M; i++)
        for (j = 0; j < M; j++)
            graph[i][j] = 0;
    while (scanf("%d %d", &i, &j) == 2)
        graph[i][j] = 1;
    if (searchBF(0))
        printf("\nThe goal %d is found\n", goal);
    else
        printf("\nNot Found\n");
}