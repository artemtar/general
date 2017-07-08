typedef int Key;
typedef struct { Key key; char info[10]; } Item;
#define key(A) (A.key)
#define info(A) (A.info)

#define less(A, B) (A < B)
#define eq(A, B) (A == B)

Item NULLitem;

Key  ITEMrand(void);
int  ITEMscan(Key *);
void ITEMshow(Item);
