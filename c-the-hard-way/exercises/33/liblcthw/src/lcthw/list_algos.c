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
	if (list && list_compare_function)
	{
		ListNode *node_one = list->first;
		ListNode *node_two = node_one->next; 

		int i;
		int j;
		for (i = 0; i < list->count; i++)
		{
			for (j = 0; j < list->count - i - 1; j++)
			{
				if (list_compare_function(node_one, node_two))
				{
					//swap(node_one, node_two);
				}
			}
		}
	}
	return -1;
}

List *
List_merge_sort(List *list, List_compare list_compare_function)
{
	return NULL;
}
