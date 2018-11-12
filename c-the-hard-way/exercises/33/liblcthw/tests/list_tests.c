#include "minunit.h"
#include <lcthw/list.h>
#include <assert.h>

static List * list = NULL;
char * test1 = "test1 data";
char * test2 = "test2 data";
char * test3 = "test3 data";

char *
test_create()
{
	list = List_Create();

	mu_assert(list != NULL, "Failed to create list.");

	return NULL;
}

char *
test_destroy()
{
	List_Clear_Destroy(list);

	return NULL;
}

char *
test_push_pop()
{
	List_Push(list, test1);
	mu_assert(List_Last(list) == test1, "Wrong last value.");

	List_Push(list, test2);
	mu_assert(List_Last(list) == test2, "Wrong last value.");

	List_Push(list, test3);
	mu_assert(List_Last(list) == test3, "Wrong last value.");

	mu_assert(List_Count(list) == 3, "Wrong count on push.");

	char * value = List_Pop(list);
	mu_assert(value == test3, "Wrong value on pop.");

	value = List_Pop(list);
	mu_assert(value == test2, "Wrong value on pop.");

	value = List_Pop(list);
	mu_assert(value == test1, "Wrong value on pop.");

	mu_assert(List_Count(list) == 0, "Wrong count after pop.");

	return NULL;
}

char *
test_unshift()
{
	List_Unshift(list, test1);
	mu_assert(List_First(list) == test1, "Wrong first value.");

	List_Unshift(list, test2);
	mu_assert(List_First(list) == test2, "Wrong first value.");

	List_Unshift(list, test3);
	mu_assert(List_First(list) == test3, "Wrong last value.");

	mu_assert(List_Count(list) == 3, "Wrong count on unshift.");

	return NULL;
}

char *
test_remove()
{
	// we only need to test the middle remove case since push/sift already tests the other cases
	char * value = List_Remove(list, list->first->next);

	mu_assert(value == test2, "Wrong removed element.");
	mu_assert(List_Count(list) == 2, "Wrong count after remove.");
	mu_assert(List_First(list) == test3, "Wrong first after remove.");
	mu_assert(List_Last(list) == test1, "Wrong laster after remove.");

	return NULL;
}

char *
test_shift()
{
	mu_assert(List_Count(list) != 0, "Wrong count before shift.");

	char * value = List_Shift(list);
	mu_assert(value == test3, "Wrong value on shift.");

	value = List_Shift(list);
	mu_assert(value == test1, "Wrong value on shift.");
	mu_assert(List_Count(list) == 0, "Wrong count after shift.");

	return NULL;
}

char *
all_tests()
{
	mu_suite_start();

	mu_run_test(test_create);
	mu_run_test(test_push_pop);
	mu_run_test(test_unshift);
	mu_run_test(test_remove);
	mu_run_test(test_shift);
  	mu_run_test(test_destroy);

	return NULL;
}

RUN_TESTS(all_tests);
