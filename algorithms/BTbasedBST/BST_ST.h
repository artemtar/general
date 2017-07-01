#define key(A) (A.key)
#define info(A) (A.info)
typedef int Key;
typedef struct {Key key; char info[10]; } STitem;//main informarion holder
typedef struct STnode *link;
struct STnode
{
    STitem item;
    link l, r;
    int N;
};
#define less(A, B) (A < B)
#define eq(A, B) (A == B)
Key ITEMrand(void);
int ITEMscan(Key *);
void STshow(void);
STitem STsearch(Key );
void STinsert(STitem x);