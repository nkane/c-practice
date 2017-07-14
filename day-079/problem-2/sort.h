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

// simple bubble sort
void
BubbleSort(int array[], int size)
{
	bool swapped = false;
	for (int i = 0; i < size - 1; ++i)
	{
		swapped = false;
		for (int j = 0; j  < size - (i + 1); ++j)
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

// insertion sort
void
InsertionSort(int array[], int size)
{
	int i = 0;
	int j = 0;
	int key = 0;

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

// selection sort
void
SelectionSort(int array[], int size)
{
	int i = 0;
	int j = 0;
	int min_index = 0;

	for (i = 0; i < size - 1; ++i)
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

// merge
void
Merge(int array[], int leftIndex, int middleIndex, int rightIndex)
{
	int i = 0;
	int j = 0;
	int k = 0;
	// NOTE(nick): MSVC hates variables signed arrays 
	// dont use them!
	int n1 = middleIndex - leftIndex + 1;
	int n2 = rightIndex - middleIndex;
	
	int tempLeft[5] = { 0 };
	for (i = 0; i < n1; ++i)
	{
		tempLeft[i] = array[leftIndex + i];
	}

	int tempRight[5] = { 0 };
	for (j = 0; j < n2; ++j)
	{
		tempRight[j] = array[middleIndex + 1 + j];
	}

	i = 0;
	j = 0;
	k = leftIndex;

	while (i < n1 && j < n2)
	{
		if (tempLeft[i] <= tempRight[j])
		{
			array[k] = tempLeft[i];
			++i;
		}
		else
		{
			array[k] = tempRight[j];
			++j;
		}
		++k;
	}

	while (i < n1)
	{
		array[k] = tempLeft[i];
		++i;
		++k;
	}

	while (j < n2)
	{
		array[k] = tempRight[j];
		++j;
		++k;
	}
}

// merge sort
void
MergeSort(int array[], int leftIndex, int rightIndex)
{
	if (leftIndex < rightIndex)
	{
		int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
		MergeSort(array, leftIndex, middleIndex);
		MergeSort(array, middleIndex + 1, rightIndex);
		Merge(array, leftIndex, middleIndex, rightIndex);
	}
}

