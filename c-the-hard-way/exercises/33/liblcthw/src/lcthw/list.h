#ifndef lcthw_List_h
#define lcthw_List_h

#include <stdlib.h>

struct ListNode;

typedef struct ListNode
{
	struct ListNode * next;
	struct ListNode * prev;
	void * value;
} ListNode;

typedef struct List
{
	int count;
	ListNode * first;
	ListNode * last;
} List;

List *
List_Create();

void
List_Destroy(List * list);

void
List_Clear(List * list);

void
List_Clear_Destroy(List * list);

#define List_Count(A) ((A)->count)
#define List_First(A) ((A)-> first != NULL ? (A)->first->value : NULL)
#define List_Last(A)  ((A)->last != NULL ? (A)->last->value : NULL)

void
List_Push(List * list, void * value);

void *
List_Pop(List * list);

void
List_Unshift(List * list, void * value);

void *
List_Shift(List * list);

void *
List_Remove(List * list, ListNode * node);

void
List_Print(List * list, const char *);

#define LIST_FOREACH(L, S, M, V) ListNode *_node = NULL;\
												   ListNode *V = NULL;\
for (V = _node = L->S; _node != NULL; V = _node = _node->M)

#endif
