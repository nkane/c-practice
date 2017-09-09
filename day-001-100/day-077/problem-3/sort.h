/*
 * sort.h
 *
 */

// simple swap
void
Swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

// simple bubble sort algorithm
// best  case: O(n^2)
// worst case: O(n^2)
void
BubbleSort(int array[], int size)
{
	bool swapped = false;
	for (int i = 0; i < size; ++i)
	{
		swapped = false;
		for (int j = 0; j < (size - (i + 1)) ; ++j)
		{
			if (array[j] > array[j + 1])
			{
				Swap(&array[j], &array[j + 1]);
				swapped = true;
			}
		}
		if (!swapped)
		{
			break;
		}
	}
}

// simple insertion sort algorithm
// best  case: O(n)
// worst case: O(n^2)
void
InsertionSort(int array[], int size)
{
	int i, key, j;
	for (i = 1; i < size; ++i)
	{
		key = array[i];
		j = i - 1;

		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			--j;
		}
		array[j + 1] = key;
	}
}

