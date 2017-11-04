#include <stdlib.h>
#include <stdio.h>
#include "heap.h"
//#include <math.h>

///make new node
heapNode makeNew(Item item)
{
  heapNode x;
  x = malloc(sizeof(*x));
  x->item = item;
  x->r = NULL;
  x->l = NULL;
  x->size = 1;
  return x;
}

///Incert node in right position
heapNode HEAPinsertRight(heapNode x, Item n)
{
  heapNode t = makeNew(n);
  //x->size++;
  x->r = t;
  return x;
}

///Incert node in left position
heapNode HEAPinsertLeft(heapNode x, Item n)
{
  heapNode t = makeNew(n);
  //x->size++;
  x->l = t;
  return x;
}

/// Check if node is empty
int isEmpty(heapNode x)
{
  return x == NULL;
}

///Check if graph is complete
int isComplete(heapNode x)
{
  int h = height(x);
  int comp = 2;
  while (h > 0)
  {
    comp = comp * 2;
    h--;
  }
  return x->size == comp - 1;
}

///insert new element
heapNode insertHeap(heapNode self, Item n)
{
  if (isEmpty(self))
  {
    heapNode temp = makeNew(n);
    return temp;
  }
  else
  {
    insertLeaf(self, n);
    self->size++;
    return self;
  }
}

///put leafs according to complete graph rules
void insertLeaf(heapNode n, Item x)
{
  if (!isEmpty(n->l) && isEmpty(n->r))
  {
    heapNode left = n->l;
    if (isEmpty(left->r) && isEmpty(left->l))
    {
      Item z = simpleCheck(n, x);
      n = HEAPinsertRight(n, z);
      heapNode r = n->r;
      heapNode l = n->l;
      return;
    }
  }
  if (isEmpty(n->l) && isEmpty(n->r))
  {
    Item z = simpleCheck(n, x);
    n = HEAPinsertLeft(n, z);
    return;
  }
  heapNode rpath = n->r;
  heapNode lpath = n->l;
  if (height(n) != 0 && isComplete(n)) //check if subgraph is complerte
  {                                    //if complete insertion is in the left most position
    lpath->size++;
    insertLeaf(lpath, x);
    n = checkAndChange(n, lpath, rpath);
    return;
  }
  int lpathLen = height(lpath);
  int rpathLen = height(rpath);

  if (rpathLen <= lpathLen && isComplete(lpath))
  {
    rpath->size++;
    insertLeaf(rpath, x);
  }
  else
  {
    lpath->size++;
    insertLeaf(lpath, x);
  }
  n = checkAndChange(n, lpath, rpath);
}

///Check if value which is about to be added is smaller than head node, if so, swap it
Item simpleCheck(heapNode n, Item x)
{
  Item z = x;
  if (x < n->item)
  {
    z = n->item;
    n->item = x;
  }
  return z;
}

//compare values of right and left nodes and if it is bigger replace it with value of head
heapNode checkAndChange(heapNode n, heapNode lpath, heapNode rpath)
{
  heapNode change;
  if (rpath->item < lpath->item)
    change = rpath;
  else
    change = lpath;
  if (change->item < n->item)
  {
    Item temp = n->item;
    n->item = change->item;
    change->item = temp;
  }
  return n;
}

///heihght of given subgraph
int height(heapNode n)
{
  if (((n->l == NULL) && (n->r == NULL)) || n == NULL)
    return 0;
  int self = 1;
  int left, right;
  left = 0;
  right = 0;
  if (n->l != NULL)
  {
    left = height(n->l);
  }
  if (n->r != NULL)
  {
    right = height(n->r);
  }
  if (left >= right)
  {
    return self + left;
  }
  if (left < right)
  {
    return self + right;
  }
}

///print graph of the heap
void printHeapGraph(heapNode x)
{
  if (x == NULL)
  {
    printf("Null");
    return;
  }
  printf("Node%C(sizeof%d, ", x->item, x->size);
  printHeapGraph(x->l);
  printf(", ");
  printHeapGraph(x->r);
  printf(")");
  return;
}

///print
void printHeap(heapNode x)
{
  if (x == NULL)
  {
    return;
  }
  printf("%C ", x->item, x->size);
  printHeap(x->l);
  printHeap(x->r);
  return;
}

///making ordered array out of heap
Item *deheapify(heapNode x)
{
  Item *heapArray;
  heapArray = malloc((x->size) * sizeof(*heapArray));
  int pos;
  int heapSize = x->size;
  for (pos = 0; pos < heapSize; pos++)
  {
   heapArray[pos] = rearrange(x);//remove top of the heap and replace with bottom leaf
  }
  return heapArray;
}

///rearange heap
Item rearrange(heapNode x)
{
  Item toReturn = x->item;
  Item last = findLastLeaf(x);//removing happens there
  if (x->size != 0)
  {
    x->item = last;
    x->item = checkOrder(x);//after removal order might change, therefore have to recheck it
  }
  else
    free(x);
  return toReturn;
}

///find last leaf of tree cut it off, return value of head node and replace it with value of cutted leaf, so it 
///looks like replacement of head with bottom leaf
Item findLastLeaf(heapNode n)
{
  heapNode rpath = n->r;
  heapNode lpath = n->l;
  if (isEmpty(n->l) && isEmpty(n->r))
  {
    Item last = n->item;
    free(n);
    return last;
  }
  if (!isEmpty(n->l) && isEmpty(n->r))
  {
    heapNode left = n->l;
    Item last = left->item;
    n->l = NULL;
    free(left);
    return last;
  }
  if (!isEmpty(n->l) && !isEmpty(n->r))
  {
    heapNode left = n->l;
    heapNode right = n->r;
    if (isEmpty(left->l) && isEmpty(left->r) && isEmpty(right->l) && isEmpty(right->r))
    {
      Item last = right->item;
      n->r = NULL;
      free(right);
      return last;
    }
  }

  int lpathLen = height(lpath);
  int rpathLen = height(rpath);

  if (rpathLen == lpathLen)
  {
    rpath->size--;
    return findLastLeaf(n->r);
  }
  else
  {
    lpath->size--;
    return findLastLeaf(n->l);
  }
}

///check if value to incert is not disruprint heap strucrure
Item checkOrder(heapNode n)
{
  if (isEmpty(n->l) && isEmpty(n->r))
  {
    return n->item;
  }

  if (!isEmpty(n->l) && isEmpty(n->r))
  {
    heapNode left = n->l;
    Item change = n->item;
    if (n->item > left->item)
    {
      change = left->item;
      left->item = n->item;
      n->item = change;
    }
    return change;
  }

  if (!isEmpty(n->l) && !isEmpty(n->r))
  {
    heapNode left = n->l;
    heapNode right = n->r;
    if (isEmpty(left->l) && isEmpty(left->r) && isEmpty(right->l) && isEmpty(right->r))
    {
      Item toChange = n->item;
      if (left->item < n->item)
      {
        toChange = left->item;
        left->item = n->item;
        n->item = toChange;
      }
      if (right->item < n->item)
      {
        toChange = right->item;
        right->item = n->item;
        n->item = toChange;
      }
      return toChange;
    }
  }

  heapNode rpath = n->r;
  heapNode lpath = n->l;
  int lpathLen = height(lpath);
  int rpathLen = height(rpath);
  Item nodeCheckL, nodeCheckR, temp, result;
  nodeCheckL = NULL;
  nodeCheckR = NULL;
  ///recurcive part with rearrangement of values
  if (rpathLen == lpathLen && isComplete(lpath))//since complete, only possible situation out of standard
  {
    nodeCheckL = checkOrder(rpath);
  }
  else
  {
    nodeCheckR = checkOrder(lpath);
  }
  result = n->item;
  if (rpath->item < n->item)
  {
    result = rpath->item;
    rpath->item = n->item;
    n->item = result;
  }
  if (lpath->item < n->item)
  {
    result = lpath->item;
    lpath->item = n->item;
    n->item = result;
  }
  return result;
  //start checkingh result and see if any of nodes are bigger
  /*if (nodeCheckL != NULL && nodeCheckR != NULL)
  {
    if (nodeCheckR >= nodeCheckL)
    {
      temp = nodeCheckR;
      rpath->item = n->item;
      n->item = temp;
      result = temp;
    }
    else
    {
      temp = nodeCheckL;
      lpath->item = n->item;
      n->item = temp;
      result = temp;
    }
  }
  if (nodeCheckL != NULL && nodeCheckR == NULL)
  {
    temp = nodeCheckL;
    if (temp > n->item)
    {
      lpath->item = n->item;
      n->item = temp;
      result = temp;
    }
  }
  if (nodeCheckL == NULL && nodeCheckR != NULL)
  {
    temp = nodeCheckR;
    if (temp > n->item)
    {
      rpath->item = n->item;
      n->item = temp;
      result = temp;
    }
  }
  if (nodeCheckL == NULL && nodeCheckR == NULL)
  {
    result = n->item;
  }
  return result;*/
}