/*
 * 	list.c
 */

#define DEFAULT_SIZE 4

#include <assert.h>

#include "list.h"

void
NewList(LinkList *l, int elementSize, void (*freeFunction)(void *))
{
	assert(elementSize > 0);
	l->Size = 0;
	l->ElementSize = elementSize;
	l->FreeFunction = freeFunction;
	l->Head = NULL;
	l->Tail = NULL;
}

void
Insert(LinkList *l, void *element)
{
	Node *tempNode = NULL;
	tempNode = (Node *)malloc(sizeof(Node));
	tempNode->Value = (void *)malloc(sizeof(l->ElementSize));
	memcpy(tempNode->Value, element, l->ElementSize);
	if (l->Head && l->Tail)
	{
		Node *previousTail = l->Tail;
		previousTail->Next = tempNode;
		tempNode->Previous = previousTail;
		tempNode->Next = NULL;
		l->Tail = tempNode;
	}
	else
	{
		tempNode->Previous = NULL;
		tempNode->Next = tempNode;
		l->Head = tempNode;
		l->Tail = tempNode;
	}
}

void
FreeList(LinkList *l)
{
	Node *current = l->Head;
	Node *freeable = current;
	if (l->FreeFunction)
	{
		while (current != NULL)
		{
			freeable = current;
			current = freeable->Next;
			l->FreeFunction(freeable->Value);
			free(freeable);
		}
	}
	else
	{
		while (current != NULL)
		{

			freeable = current;
			current = freeable->Next;
			free(freeable->Value);
			free(freeable);
		}
	}
	l->Head = NULL;
	l->Tail = NULL;
}
