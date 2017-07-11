#include <stdlib.h>
#include <string.h>
#include "BST_ST.h"
extern int cnt1;
extern int cnt2;
static link head, pointNULL; //header of the graph
struct STnode { Item item; link l, r; int N; int red; };
//creates new node to compose all info
link makeNEW(STitem c, link left, link right, int num)
{
    link x = malloc(sizeof *x);
    x->item = c;
    x->l = left;
    x->r = right;
    x->N = num;
    return x;
}
//adds sorted leaf to the graph
link insertBST(link h, STitem x)
{
    if (h == pointNULL)
        return makeNEW(x, pointNULL, pointNULL, 1);
    Key v = key(x), t = key(h->item);
    if (++cnt1 && less(v, t))
        h->l = insertBST(h->l, x);
    else
        h->r = insertBST(h->r, x);
    (h->N)++;
    return h;
}
//all next function declarations are compability function
//serves as extention of privious version which utilize array implementation
void STinsert(STitem x) { head = insertBST(head, x); }
//print graph
void showBST(link h)
{
    if (h == pointNULL)
        return;
    showBST(h->l);
    ITEMshows(h->item);
    showBST(h->r);
}
///compability function
void STshow(void)
{
    showBST(head);
}
///serch for item in graph(key based implementation)
STitem searchBST(link h, Key v)
{
    //Key t = key(h->item);
    if (h == pointNULL)
    {
        //defult empty element, assuming that none empty element have key reference greater than -1
        STitem h = {-1, "NULL"};
        return h;
    }
    Key t = key(h->item);
    if (++cnt2 && eq(v, t))
        return h->item;
    if (++cnt2 && less(v, t))
        return searchBST(h->l, v);
    else
        return searchBST(h->r, v);
}
///compatability function
STitem STsearch(Key v) { return searchBST(head, v); }
int STcount(void) { return head->N; }
///print item
void ITEMshows(STitem item)
{
    printf("key = %d, info = ", key(item));
    puts(info(item));
}