/*
 * 	lists.c
 * 	Created By: Nick Kane
 *
 */

#include <stdio.h>
#include <stdlib.h>

struct _node;

typedef struct _node
{
	struct _node *next;
	struct _node *previous;
	void *value;
} Node;

typedef struct _list
{
	int count;
	Node *first;
	Node *last;
} List;

List *
List_Create()
{
	List *list = malloc(sizeof(List));
	list->first = NULL;
	list->last = NULL;
	list->count = 0;
	return list;
}

void
List_Destroy(List *list)
{
	if (list)
	{
		free(list);
	}
}

void
List_Add(List *list, void *value)
{
	if (list)
	{
		Node *new_node = malloc(sizeof(Node));
		if (new_node)
		{
			new_node->next = NULL;
			new_node->previous = NULL;
			new_node->value = value;
			if (list->first && list->last)
			{
				new_node->previous = list->last;
				list->last->next = new_node;
				list->last = new_node;
			}
			else
			{
				list->first = new_node;
				list->last = new_node;
			}
			list->count++;
		}
	}
}

void
List_Remove(List *list, int element)
{
	if (element < list->count && element >= 0)
	{
		Node *current_node = list->first;
		int i;
		for (i = 0; i < element && current_node; i++)
		{
			current_node = current_node->next;
		}
		Node *previous_node = current_node->previous;
		Node *next_node = current_node->next;
		if (previous_node == NULL)
		{
			// checks if it is beginning of list
			list->first = next_node;
			list->first->previous = NULL;
		}
		else if (next_node == NULL)
		{
			// checks if it is end of list
			list->last = previous_node;
			list->last->next = NULL;
		}
		else
		{
			previous_node->next = next_node;
			next_node->previous = previous_node;
		}
		free(current_node);
		list->count--;
	}
}

void
List_Print(List *l)
{
	Node *current_node = l->first;
	printf(" ---- Beginning of List ---- \n");
	printf(" ---- List Count: %3d   ---- \n", l->count);
	while (current_node != NULL)
	{
		printf("Node [Address: %p] - Int Value: %d\n", current_node, *(int *)current_node->value); 
		current_node = current_node->next;
	}
	printf(" ---- End of List ---- \n\n");
}
