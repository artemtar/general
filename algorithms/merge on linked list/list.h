typedef int Item;
typedef struct node *link;
struct node { Item item; link next; };

link merge(link);
link mergeHalves(link, link);

link LISTempty(void);
Item LISThead(link);
link LISTtail(link);
link LISTcons(Item,link);
int LISTlength(link);
void LISTprint(link);
