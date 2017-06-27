
typedef char Item;
typedef struct node* heapNode;
struct node { Item item; heapNode r; heapNode l; heapNode last; int size;};
heapNode insertHeap(heapNode,Item);
heapNode HEAPconsL(heapNode, Item);
heapNode makeNew(Item);
heapNode HEAPconsR(heapNode, Item );
heapNode checkAndChange(heapNode, heapNode, heapNode);
Item simpleCheck(heapNode, Item);
Item rearrange(heapNode);
Item checkOrder(heapNode);
Item findLastLeaf(heapNode);
Item* deheapify(heapNode );
void print(heapNode);
