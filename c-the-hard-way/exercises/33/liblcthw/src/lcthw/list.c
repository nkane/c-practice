#include <lcthw/list.h>
#include <lcthw/dbg.h>

List *
List_Create()
{
	return calloc(1, sizeof(List));
}

void
List_Destroy(List * list)
{
	LIST_FOREACH(list, first, next, current) 
	{
		if (current->prev) 
		{
			free(current->prev);
		}
	}
	free(list->last);
	free(list);
}

void
List_Clear(List * list)
{
	LIST_FOREACH(list, first, next, current)
	{
		free(current->value);
	}
}

void
List_Clear_Destroy(List * list)
{
	List_Clear(list);
	List_Destroy(list);
}

void
List_Push(List * list, void * value)
{
	ListNode * node = calloc(1, sizeof(ListNode));
	check_mem(node);
	node->value = value;
	if (list->last == NULL)
	{
		list->first = node;
		list->last = node;
	}
	else
	{
		list->last->next = node;
		node->prev = list->last;
		list->last = node;
	}
	list->count++;

error:
	return;
}

void *
List_Pop(List * list)
{
	ListNode * node = list->last;
	return node != NULL ? List_Remove(list, node) : NULL;
}

void
List_Unshift(List * list, void * value)
{
	ListNode * node = calloc(1, sizeof(ListNode));
	check_mem(node);
	node->value = value;
	if (list->first == NULL)
	{
		list->first = node;
		list->last = node;
	}
	else
	{
		node->next = list->first;
		list->first->prev = node;
		list->first = node;
	}
	list->count++;
error:
	return;
}

void *
List_Shift(List * list)
{
	ListNode *node = list->first;
	return node != NULL ? List_Remove(list, node) : NULL;
}

void *
List_Remove(List * list, ListNode * node)
{
	void *result = NULL;
	check(list->first && list->last, "List is empty.");
	check(node, "nod can't be NULL");
	if (node == list->first && node == list->last)
	{
		list->first = NULL;
		list->last = NULL;
	}
	else if (node == list->first)
	{
		list->first = node->next;
		check(list->first != NULL, "Invalid list, somehow got a first that is NULL.");
		list->first->prev = NULL;
	}
	else if (node == list->last)
	{
		list->last = node->prev;
		check(list->last != NULL, "Invalid list, somehow got a next that is NULL.");
		list->last->next = NULL;
	}
	else
	{
		ListNode *after = node->next;
		ListNode *before = node->prev;
		after->prev = before;
		before->next = after;
	}
	list->count--;
	result = node->value;
	free(node);
error:
	return result;
}

void
List_Print(List * list, const char *message)
{
	check(list, "List is NULL");
	log_info("%s", message);
	LIST_FOREACH(list, first, next, current)
	{
		log_info("Node [%p] - value: %s -- prev [%p] <- * -> next [%p]", current, (char *)current->value, current->prev, current->next);
	} 
error:
	return;
}
