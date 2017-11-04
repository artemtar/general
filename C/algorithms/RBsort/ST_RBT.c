#include <stdio.h>
#include <stdlib.h>
#include "STitem.h"
#include "ST.h"
extern int cnt1;
extern int cnt2;

typedef struct STnode *link;
struct STnode
{
  STitem item;
  link l, r;
  int N;
  int red; // 0 is black and 1 is red
};
static link head, pointNULL; //header of the graph
link makeNEW();
void ITEMshows();
void showBST();
//rotates three nodes of the graph when needed (right side rotation)
link rotR(link h)
{
  link x = h->l;
  h->l = x->r;
  x->r = h;
  return x;
}
//rotates three nodes of the graph when needed (left side rotation)
link rotL(link h)
{
  link x = h->r;
  h->r = x->l;
  x->l = h;
  return x;
}
//recurcive recout of nodes
void fixN(link h)
{
  if (h == pointNULL)
  {
    return;
  }
  fixN(h->l);
  fixN(h->r);
  h->N = (h->l->N) + (h->r->N) + 1;
  return;
}
//inserts new element into graph
link RBinsert(link h, STitem item, int sw)
{
  Key v = key(item);
 link hl = h->r;
 link hr = h->l;

  //check correctness of red-black implementation
  //all conditions have to be satisfied
  if (h == pointNULL)
    return makeNEW(item, pointNULL, pointNULL, 1, 1);

  //general case condition
  if ((h->l->red) && (h->r->red))
  {
    h->red = 1;
    h->l->red = 0;
    h->r->red = 0;
  }

  if (less(v, key(h->item)))
  {        

    h->l = RBinsert(h->l, item, 0);
    //red cant have red child, if so make rotation right    
    if (h->red && h->l->red && sw)
      h = rotR(h);
    //red cant have red uncle, if so make rotation right
   if (h->l->l!=NULL&&h->l->red && h->l->l->red)
    {
      h = rotR(h);
      h->red = 0;
      h->r->red = 1;
    }
  }
  else
  {
    h->r = RBinsert(h->r, item, 1);
    //check if previous cases hold after insertion        
    //printf("%dr\n", hrr);
    if (h->red && h->r->red && !sw)
      h = rotL(h);    
    if (h->r->r!=NULL&&h->r->red && h->r->r->red)
    {
      h = rotL(h);
      h->red = 0;
      h->l->red = 1;
    }
  }
  fixN(h);
  return h;
}
//make new node
link makeNEW(STitem c, link left, link right, int num, int color)
{
    link x = malloc(sizeof *x);
    x->item = c;
    x->l = left;
    x->r = right;
    x->N = num;
    x->red = color;
    return x;
}
//creates default graph
void STinit(){
 head = (pointNULL = makeNEW(NULLitem,NULL,NULL,0,0)); 
}
//shows graph size
int STcount(void) { return head->N; }
///print item
void ITEMshows(STitem item)
{
    printf("key = %d, info = ", key(item));
    puts(info(item));
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
///print graph
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
//insert funcion
void STinsert(STitem item)
{
  head = RBinsert(head, item, 0);
  head->red = 0;
}