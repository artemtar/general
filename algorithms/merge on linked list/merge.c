#include <stdio.h>
#include <stdlib.h>
#include "list.h"

link merge(link a)
{
    link sorted= NULL;
    int N = LISTlength(a);
    if(N <= 1) return a;
    else
    {
        link right = listCut(a, N/2);
        link left = a;
        left = merge(left);
        right = merge(right);
        sorted = mergeHalves(left, right);

    }
    return sorted;
}

link mergeHalves(link left, link right)
{
    link sort = NULL;

    while (!isEmpty(left) && !isEmpty(right))
    {

        if (left->item <= right->item)
        {
            sort = LISTconsLast(left->item, sort);//reverse incertion, check defenition in list_ADT
            left = left->next;
        }
        else
        {
            sort = LISTconsLast(right->item, sort);
            right = right->next;
        }
    }

   while (!isEmpty(left))
    {
        sort =  LISTconsLast(left->item, sort);
        left = left->next;
    }

    while  (!isEmpty(right))
    {
        sort =  LISTconsLast(right->item, sort);
        right = right->next;

    }return sort;
}
