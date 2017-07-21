#include <stdlib.h>
#include "Item.h"
#include "QUEUE.h"
static Item *q;
static int maxN, head, tail;
void QUEUEinit(int n)
{
    q = malloc((n + 1) * sizeof(Item));
    maxN = n;
    head = 0;
    tail = 0;
}
int QUEUEempty(void)
{
    return head == tail;
}
void QUEUEput(Item x)
{
    q[tail++] = x;
    tail = tail % (maxN + 1);
}
Item QUEUEget(void)
{
    int res = q[head];
    head = (head + 1) % (maxN + 1);
    return res;
}