#include "minunit.h"
#include <lcthw/list_algos.h>
#include <assert.h>
#include <string.h>

char *values[] = { "XXXX", "1234", "abcd", "xjvef", "NDSS" };

#define NUM_VALUES 5

List *
create_words()
{
	int i = 0;
	List *words = List_Create();
	for (i = 0; i < NUM_VALUES; i++)
	{
		List_Push(words, values[i]);
	}
	return words;
}

int
is_sorted(List *words)
{
	LIST_FOREACH(words, first, next, current)
	{
		if (current->next && strcmp(current->value, current->next->value) > 0)
		{
			debug("%s %s", (char *)current->value, (char *)current->next->value);
			return 0;
		}
	}
	return 1;
}

char *
test_bubble_sort()
{
	List *words = create_words();

	List_Print(words, "Before Bubble Sort");

	// should work on a list that needs sorting
	int rc = List_Bubble_Sort(words, (List_compare) strcmp);

	List_Print(words, "After Bubble Sort");

	mu_assert(rc == 0, "Bubble sort failed.");
	mu_assert(is_sorted(words), "Words are not sorted after bubble sort.");

	// should work on an already sorted list
	rc = List_Bubble_Sort(words, (List_compare) strcmp);
	mu_assert(rc == 0, "Bubble sort of already sorted failed.");
	mu_assert(is_sorted(words), "Words should be sorted if already bubble sorted.");

	List_Destroy(words);

	// should work on an empty list
	words = List_Create(words);
	rc = List_Bubble_Sort(words, (List_compare) strcmp);
	mu_assert(rc == 0, "Bubble sort failed on empty list.");
	mu_assert(is_sorted(words), "Words sould be sorted if empty.");

	List_Destroy(words);

	return NULL;
}

char *
test_merge_sort()
{
	List *words = create_words();

	// should work on a list that needs sorting
	List *res = List_Merge_Sort(res, (List_compare) strcmp);
	mu_assert(is_sorted(res), "Words are not sorted after merge sort.");

	List *res2 = List_Merge_Sort(res, (List_compare) strcmp);
	mu_assert(is_sorted(res), "Should still be sorted after merge sort.");
	List_Destroy(res2);
	List_Destroy(res);

	List_Destroy(words);
	return NULL;
}

char *
all_tests()
{
	mu_suite_start();
	mu_run_test(test_bubble_sort);
	mu_run_test(test_merge_sort);
	return NULL;
}

RUN_TESTS(all_tests);
