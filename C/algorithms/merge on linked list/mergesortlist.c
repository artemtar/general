#include <stdio.h>
#include <stdlib.h>
#include "list.h"
int c = 0;

void main(void)
{
link lst = LISTcons(6,NULL);
lst = LISTcons(4,lst); lst = LISTcons(2,lst); lst = LISTcons(5,lst);
lst = LISTcons(7,lst); lst = LISTcons(3,lst); lst = LISTcons(1,lst);
LISTprint(lst);
lst = merge(lst);
printf("sorted: ");
LISTprint(lst);
}
