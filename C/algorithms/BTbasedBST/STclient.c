#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST_ST.h"

STitem newItem = {300, "New Item"};
int cnt1 = 0, cnt2 = 0;
//creates information holder
Key ITEMrand(void)
{
    return rand() % 1000;
}
//random key for reference
int ITEMscan(Key *x) { return scanf("%d", x); }
void ITEMshow(STitem item)
{
    printf("key = %d, info = ", key(item));
    puts(info(item));
}

void main(int argc, char *argv[])
{
    int i, sKey, M = atoi(argv[1]), sw = atoi(argv[2]), maxN = M + 1;
    Key v;
    STitem item;
    //STinit(maxN);
    srand(2);
    //creates table based on select.
    //0:Random, 1:Sorted, 2:Manual input
    for (i = 0; i < M; i++)
    {
        switch (sw)
        {
        case 0:
            v = ITEMrand();
            break;
        case 1:
            v = i + 1;
            break;
        default:
            if (ITEMscan(&v) == EOF)
                break;
        } //creating table, dependeng on chosen options
        key(item) = v;
        strcpy(info(item), "Hello");
        STinsert(item);
    }
    printf("Original Symbol Table\n");
    STshow();
    printf("Length = %d, Keys = %d\n\n", M, STcount());
    STinsert(newItem);
    printf("After insertion\n");
    STshow();
    printf("Input sKey: ");
    scanf("%d", &sKey);
    ITEMshow(STsearch(sKey));
}