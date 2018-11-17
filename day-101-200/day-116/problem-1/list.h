/*
 * 	NOTE(nick): was going to use a list, but decided not to :D
 *	list.h
 */

typedef struct _node
{
	struct _node *Next;
	struct _node *Previous;
	void *Value;
} Node;

typedef struct _linklist
{
	Node *Head;
	Node *Tail;
	int Size;
	int ElementSize;
	void (*FreeFunction)(void *);
} LinkList;

void
NewList(LinkList *l, int elementSize, void (*freeFunction)(void *));

void
Insert(LinkList *l, void *element);

void
FreeList(LinkList *l);
