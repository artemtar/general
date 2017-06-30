#define key(A) (A.key)
#define info(A) (A.info)
typedef int Key;
typedef struct {Key key; char info[10]; } STitem;//main informarion holder     
//defult empty element, assuming that none empty element have key reference greater than -1
STitem NULLitem = {-1, "NULL"};  
#define less(A, B) (A < B)
#define eq(A, B) (A == B)
//creates information holder
            Key ITEMrand(void)
{
    return rand() % 1000;
}
//random key for reference
int ITEMscan(Key *x) { return scanf("%d", x); }
void ITEMshow(STitem item)
{
    printf("key = %d, info = ", key(item));
    puts(info(item));    
}
