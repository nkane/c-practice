#include "dbg.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void
die(const char *message)
{
	if (errno)
	{
		perror(message);
	}
	else
	{
		printf("ERROR: %s\n", message);
	}
}

// a typedef creates a fake type, in this
// case for a function pointer
typedef int (*compare_cb) (int a, int b);


// a classic bubble sort function that uses the
// compare_cb to do the sorting
int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
	int temp = 0;
	int i = 0;
	int j = 0;
	int *target = malloc(count * sizeof(int));
	if (!target)
	{
		die("Memory error.");
	}
	memcpy(target, numbers, count * sizeof(int));
	for (i = 0; i < count; i++)
	{
		for (j = 0; j < count - 1; j++)
		{
			if (cmp(target[j], target[j+1]) > 0)
			{
				temp = target[j + 1];
				target[j + 1] = target[j];
				target[j] = temp;
			}
		}
	}
	return target;
}

int sorted_order(int a, int b)
{
	return a - b;
}

int reverse_order(int a, int b)
{
	return b - a;
}

int strange_order(int a, int b)
{
	if (a == 0 || b == 0)
	{
		return 0;
	}
	else
	{
		return a % b;
	}
}

// used to test that we are sorting things correctly
// by doing the sort and printing it out.
void test_sorting(int *numbers, int count, compare_cb cmp)
{
	int i = 0;
	int *sorted = bubble_sort(numbers, count, cmp);
	if (!sorted)
	{
		die("Failed to sort as requested.");
	}
	for (i = 0; i < count; i++)
	{
		printf("%d ", sorted[i]);
	}
	printf("\n");
	free(sorted);
}

void dump(compare_cb cmp)
{
	int i = 0;

	unsigned char *data = (unsigned char *)cmp;

	for (i = 0; i < 25; i++)
	{
		printf("%02x:", data[i]);
	}

	printf("\n");
}

void destroy(compare_cb cmp)
{
	int i = 0;

	unsigned char *data = (unsigned char *)cmp;
	debug("data is %p:%s", data, data);

	for (i = 0; i < 1; i++)
	{
		debug("assign %d to data at %d", i, i);
		data[i] = i;
	}
	debug("exited loop, data now: %s\n", data);

	printf("\n");

}

int
main(int argc, char *argv[]) 
{
	if (argc < 2)
	{
		die("USAGE: ex18 4 3 1 5 6");
	}

	int count = argc - 1;
	int i = 0;
	char **inputs = argv + 1;
	int *numbers= malloc(count * sizeof(int));

	if (!numbers)
	{
		die("Memory Error");
	}

	for (i = 0; i < count; i++)
	{
		numbers[i] = atoi(inputs[i]);
	}

	test_sorting(numbers, count, sorted_order);
	test_sorting(numbers, count, reverse_order);
	test_sorting(numbers, count, strange_order);

	free(numbers);

	printf("SORTED:");
	dump(sorted_order);

	debug("calling destroy with %p", sorted_order);
	//destroy(sorted_order);

	printf("REVERSE:");
	dump(reverse_order);
	//destroy(reverse_order);

	printf("STRANGE:");
	dump(strange_order);
	destroy(strange_order);

	return 0;
}
