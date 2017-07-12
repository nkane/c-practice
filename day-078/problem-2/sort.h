/*
 * sort.h
 *
 */

void
Swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void
BubbleSort(int array[], int size)
{
	bool swapped = false;
	for (int i = 0; i < (size - 1); ++i)
	{
		swapped = false;
		for (int j = 0; j < (size - (1 + i)); ++j)
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

void
InsertionSort(int array[], int size)
{
	int key;
	int j = 0;
	for (int i = 1; i < size; ++i)
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

void
SelectionSort(int array[], int size)
{
	int i;
	int j;
	int min_index;

	for (i = 0; i < (size - 1); ++i)
	{
		min_index = i;
		for (j = i + 1; j < size; ++j)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}
		Swap(&array[min_index], &array[i]);
	}
}

