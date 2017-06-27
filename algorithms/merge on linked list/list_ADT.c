#include <stdio.h>
#include <stdlib.h>
#include "list.h"

link LISTempty(void){
 return NULL;
}

int isEmpty(link a){
  return  a == NULL;
}

Item LISThead(link x){
  if (x == NULL) return 0;
  return x->item;
}

link LISTtail(link x){
   if (x == NULL) return NULL;
  return x->next;
}

link makeNew(Item item){
 link x;
 x = malloc(sizeof(*x));
 x->item = item;
 x->next = NULL;
 return x;
}

link LISTcons(Item n, link x){
  link t = makeNew(n);
  t->next = x;
  return t;
}

link LISTconsLast(Item n, link x){
  link t = makeNew(n);
  if(x == NULL) return t;
  link rotate = x;
  while(rotate->next != NULL) rotate = rotate->next;
  rotate->next = t;
  return x;
}

int LISTlength(link x){
  int c = 0;
  link t = x;
  while(t != NULL){
    c++;
    t = t->next;
  }
   return c;
}

void LISTprint(link x){
  link t = x;
  printf("[");
  while(t != NULL){
    printf("%d ", t->item);
     t = t->next;
   }
  printf("]\n");
}

link listCut(link x, int cut)
///returns cutted pease
{
  link temp = x;
    while(cut > 0)
    {
      if(temp->next == NULL){printf("wrong cut position"); break;}
      link cutHere = temp;
      temp = temp->next;
      cut--;
      if(cut == 0) cutHere->next = NULL;
    }return temp;
}
