#include "ST.h"
#include "STitem.h"
typedef struct STnode *link;
struct STnode
{
    STitem item;
    link l, r;
    int N;
    int red; // 0 is black and 1 is red
};
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
  //check correctness of red-black implementation
  //all conditions have to be satisfied
  if (h == pointNULL)
    return makeNEW(item, pointNULL, pointNULL, 1, 1);
  //general case condition
  if ((hl->red) && (hr->red))
  {
    h->red = 1;
    hl->red = 0;
    hr->red = 0;
  }
  if (less(v, key(h->item)))
  {
    hl = RBinsert(hl, item, 0);
    //red cant have red child, if so make rotation right
    if (h->red && hl->red && sw)
      h = rotR(h);
    //red cant have red uncle, if so make rotation right
    if (hl->red && hll->red)
    {
      h = rotR(h);
      h->red = 0;
      hr->red = 1;
    }
  }
  else
  {
    hr = RBinsert(hr, item, 1);
    //chack if previous cases hold after insertion
    if (h->red && hr->red && !sw)
      h = rotL(h);
    if (hr->red && hrr->red)
    {
      h = rotL(h);
      h->red = 0;
      hl->red = 1;
    }
  }
  fixN(h);
  return h;
}
//insert funcion
void STinsert(STitem item)
{
  head = RBinsert(head, item, 0);
  head->red = 0;
}