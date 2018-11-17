#include <lcthw/list_algos.h>
#include <lcthw/dbg.h>

inline void
ListNode_Swap(ListNode *n1, ListNode *n2)
{
	void *temp = n1->value;
	n1->value = n2->value;
	n2->value = temp;
}

int
List_Bubble_Sort(List *list, List_compare list_compare_function)
{
	int sorted = 1;
	if (List_Count(list) <= 1)
	{
		return 0;
	}
	else
	{
		do {
			sorted = 1;
			LIST_FOREACH(list, first, next, current)
			{
				if (current->next)
				{
					if (list_compare_function(current->value, current->next->value) > 0)
					{
						ListNode_Swap(current, current->next);
						sorted = 0;
					}
				}
			}
		} while (!sorted);
	}
	return 0;
}

List *
List_Merge_Sort(List *list, List_compare list_compare_function)
{
	if (list && list_compare_function)
	{
		return list;
	}
	return NULL;
}
