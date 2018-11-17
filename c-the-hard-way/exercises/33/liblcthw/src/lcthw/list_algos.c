#include <lcthw/list_algos.h>
#include <lcthw/dbg.h>
#include <string.h>

void
ListNode_Swap(ListNode *n1, ListNode *n2)
{
	void *temp = n1->value;
	n1->value = n2->value;
	n2->value = temp;
}

int
List_bubble_sort(List *list, List_compare list_compare_function)
{
	int result = -1;
	if (list && list_compare_function)
	{
		ListNode *node_one = list->first;
		ListNode *node_two = node_one->next; 
		int i;
		int j;
		for (i = 0; i < list->count; i++)
		{
			node_one = list->first;
			node_two = node_one->next;
			for (j = 0; j < list->count - i - 1; j++)
			{
				// check if node_one value is greater than node_two value
				if (list_compare_function(node_one, node_two) == 1)
				{
					ListNode_Swap(node_one, node_two);
				}
				node_one = node_two;
				node_two = node_one->next;
			}
		}
		result = 0;
	}
	return result;
}

List *
List_merge_sort(List *list, List_compare list_compare_function)
{
	if (list && list_compare_function)
	{
		return list;
	}
	return NULL;
}
