#include <stdlib.h>
#include "Item.h"
#include "QUEUE.h"
typedef struct QUEUEnode *link;
struct QUEUEnode
{
    Item item;
    link next;
};
static link head, tail;

void QUEUEinit(int maxN)
{
    head = NULL;
}
Item QUEUEempty(void)
{
    return head == NULL;
}
Item QUEUEget(void)
{
    Item x = head->item;
    link t = head->next;
    free(head);
    head = t;
    return x;
}
Item QUEUEget(void)
{
    Item x = head->item;
    link t = head->next;
    free(head);
    head = t;
    return x;
}