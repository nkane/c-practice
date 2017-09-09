/*
 * header file for sorting algorithms
 *
 */

// simple swap
void
Swap(int *x, int *y)
{
	int temp = 0;
	temp = *x;
	*x = *y;
	*y = temp;
}

// simple bubble sort algorithm
// best  time complexity: O(n^2)
// worst time complexity: O(n^2)
void
BubbleSort(int array[], int size)
{
	bool swapped = false;
	for (int i = 0; i < size; ++i)
	{
		swapped = false;
		// last i element is in correct place
		for (int j = 0; j < (size - i - 1); ++j)
		{
			// compare adjacent (contiguous) array elements
			if (array[j] > array[j + 1])
			{
				Swap(&array[j], &array[j + 1]);
				swapped = true;
			}
		}
		// list should be in order - okay to break
		if (swapped == false)
		{
			break;
		}
	}
}

// simple insertion sort algoritm
// best  time complexity: O(n)
// worst time complexity: O(n^2)
void
InsertionSort(int array[], int size)
{
	int i, j, key;
	for (i = 1; i < size; ++i)
	{
		// key is current element
		key = array[i];
		// j is always the previous element
		j = (i - 1);

		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j = (j - 1);
		}
		array[j + 1] = key;
	}
}

