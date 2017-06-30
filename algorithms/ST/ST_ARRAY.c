#include <stdlib.h>
#include "STitem.h"
static STitem *st;
static int N;
extern int cnt1;
extern int cnt2;
extern STitem NULLitem;

//allocate place to hold refferece(key) to each element
void STinit(int maxN)
{
    st = malloc((maxN) * sizeof(STitem));
    N = 0;
}
//check size
int STcount(void) { return N; }
//display elements
void STshow(void)
{
    int i;
    for (i = 0; i < N; i++)
        ITEMshow(st[i]);
}
//insert element in existing list, selected search-like methode is used
void STinsert(STitem x)
{
    int j = N++;
    Key v = key(x);
    while (++cnt1 && j > 0 && less(v, key(st[j - 1])))
    {
        st[j] = st[j - 1];
        j--;
    }
    st[j] = x;
}
//returns element with desired key number, else defult elementr is retured,
//which means there is no such element
STitem STsearch(Key v)
{
    int j;
    for (j = 0; j < N; j++)
    {
        if (++cnt2 && eq(v, key(st[j])))
            return st[j];
        if (++cnt2 && less(v, key(st[j])))
            break;
    }
    return NULLitem;
}