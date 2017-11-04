#include <stdlib.h>
#include "STitem.h"
#define used(A) (key(st[A]) != key(NULLitem))
//M is size of Hash reference array
extern int M, cnt1, cnt2;
static int N;//size of hash table
static STitem *st;
typedef struct STnode *link;
///Data holder
struct STnode
{
    STitem item;
    link next;
};
///First hash key
int hash(Key v) { return v % M; }
///Second hash key
int hashtwo(Key v){return 9 - (v % 9);}
///makes new hash data node
static link insertNew(STitem item, link next)
{
    link x = malloc(sizeof *x);
    x->item = item;
    x->next = next;
    return x;
}
static link *heads, pointNULL;
///initializer
void STinit(int max)
{
    int i;
    N = 0;
    st = malloc(max * sizeof(STitem));
    for (i = 0; i < max; i++)
        st[i] = NULLitem;
}
///insert value into table
void STinsert(STitem item)
{
    Key v = key(item);
    int i = hash(v);
    int k = hashtwo(v);
    //collision evasion
    while (used(i))
    {
        i = (i + k) % M;
        cnt1++;
    }
    st[i] = item;
    N++;
}
///look up value
STitem STsearch(Key v)
{
    int i = hash(v);
    int k = hashtwo(v);
    //retrive original value
    while (used(i))
        if
            eq(v, key(st[i])) return st[i];
        else
        {
            i = (i + k) % M;
            cnt2++;
        }
    return NULLitem;
///display list
}
void STshow(void)
{
    int i;
    for (i = 0; i < M; i++)
    {
        ITEMshow(st[i]);
    }
}
///return size
int STcount() { return N; }
