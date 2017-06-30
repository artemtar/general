#define key(A) (A.key)
#define info(A) (A.info)
typedef int Key;
typedef struct {Key key; char info[10]; } STitem;//main informarion holder  
#define less(A, B) (A < B)
#define eq(A, B) (A == B)

void STinit(int);
int STcount(void);
void STshow(void);
void STinsert(STitem);
STitem STsearch(Key);
Key ITEMrand(void);
int ITEMscan(Key *);
void ITEMshow(STitem);