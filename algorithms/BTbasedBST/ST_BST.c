#include <stdlib.h>
#include <string.h>
#include "BST_ST.h"
extern int cnt1;
extern int cnt2;
static link head, pointNULL;

link makeNEW(STitem c, link left, link right, int num)
{
    link x = malloc(sizeof *x);
    x->item = c;
    x->l = left;
    x->r = right;
    x->N = num;
    return x;
}

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
void STinsert(STitem x) { head = insertBST(head, x); }

void showBST(link h)
{
    if (h == pointNULL)
        return;
    showBST(h->l);
    ITEMshows(h->item);
    showBST(h->r);
}
void STshow(void)
{
    showBST(head);
}

STitem searchBST(link h, Key v){
//Key t = key(h->item);
if(h == pointNULL)
{
    //defult empty element, assuming that none empty element have key reference greater than -1
    STitem h = {-1, "NULL"};
    return h;
} 
Key t = key(h->item);
if(++cnt2 && eq(v,t)) return h->item;
if(++cnt2 && less(v,t))
return searchBST(h->l, v);
else return searchBST(h->r, v);
}
STitem STsearch(Key v){ return searchBST(head, v); }
int STcount(void) { return head->N; }
void ITEMshows(STitem item)
{
    printf("key = %d, info = ", key(item));
    puts(info(item)); 
}