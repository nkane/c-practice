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
	for (int i = 0; i < size - 1; ++i)
	{
		swapped = false;
		for (int j = 0; j < size - (i + 1); ++j)
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
	int i;
	int j;
	for (i = 1; i < size; ++i)
	{
		j = i - 1;
		key = array[i];

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
	int temp;
	for (i = 0; i < size; ++i)
	{
		min_index = i;
		for (j = i + 1; j < size; ++j)
		{
			if (array[min_index] > array[j])
			{
				min_index = j;
				temp = array[i];
			}
		}
		Swap(&array[min_index], &array[i]);
	}
}

void
Merge(int array[], int l, int m, int r)
{
	int i;
	int j;
	int k;
	int n1 = m - l + 1;
	int n2 = r - m;
	// NOTE(nick): typically want to have an array
	// with the ACTUALL needed size - instead of being
	// wasteful
	int L[Size] = { 0 };
	int R[Size] = { 0 };
	
	for (i = 0; i < n1; ++i)
	{
		L[i] = array[l + i];
	}

	for (j = 0; j < n2; ++j)
	{
		R[j] = array[m + 1 + j];
	}

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			array[k] = L[i];
			++i;
		}
		else
		{
			array[k] = R[j];
			++j;
		}
		++k;
	}

	while (i < n1)
	{
		array[k] = L[i];
		++i;
		++k;
	}

	while (j < n2)
	{
		array[k] = R[j];
		++j;
		++k;
	}
}

void
MergeSort(int array[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		MergeSort(array, l, m);
		MergeSort(array, m + 1, r);
		
		Merge(array, l, m, r);
	}
}

