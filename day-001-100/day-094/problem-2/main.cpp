/*
 * Rewrite the binary search algorithm to use recursion rather than
 * iteration.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

#define global_variable static

global_variable const int Size = 5;

int
BinarySearch(int list[], int high, int low, int searchKey);

int
main()
{
	srand(time(NULL));
	int TestCase[Size] = { 1, 2, 3, 4, 5, };
	int SearchKey = (1 + (rand() % 25));

	printf("Searching for %d ....\n", SearchKey);

	if (BinarySearch(TestCase, (len(TestCase) - 1), 0, SearchKey) > 0)
	{
		printf("Found: %d", SearchKey);
	}
	else
	{
		printf("Not Found: %d", SearchKey);
	}

	return 0;
}

int
BinarySearch(int list[], int high, int low, int searchKey)
{
	// base case
	if (low <= high)
	{
		int mid = ((high + low) / 2);
		
		if (list[mid] == searchKey)
		{
			return mid;
		}
		// drop the lower half of the list
		if (searchKey > list[mid])
		{
			return BinarySearch(list, high, mid + 1, searchKey);
		}
		// drop the higher half of the list
		else if (searchKey < list[mid])
		{
			return BinarySearch(list, mid - 1, low, searchKey);
		}
	}
	return -1;
}

