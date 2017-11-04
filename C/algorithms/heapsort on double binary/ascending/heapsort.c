#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

void main(void)
{
int i, j;
Item input[100];
    printf("\nInput to sort: ");
    scanf("%s", input);
    int inputLen = strlen(input);
heapNode heap = NULL;
    for(i=0; i < inputLen; i++)
    {
        printf("Insert %c : ", input[i]); 
        heap = insertHeap(heap, input[i]);          
    }
   // printHeap(heap);
    Item* sort;
    int heapSize = heap->size;
    sort = deheapify(heap);
    int k;
    for(k = 0; k < heapSize; k++)
    {
        printf("\n");
        printf("%c ", *(sort + k));
    }
 }