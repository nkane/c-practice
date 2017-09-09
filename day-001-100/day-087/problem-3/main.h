/*
 * main.h
 *
 */

#define len(array)(sizeof(array)/sizeof(array[0]))

#define global_variable static

global_variable const int Size = 5;

void
GenerateNumbers(int array[], int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; ++i)
	{
		array[i] = (1 + (rand() % 100));
	}
}

void
PrintArray(int array[], int size, char *text)
{
	printf("%s : { ", text);
	for (int i = 0; i < size; ++i)
	{
		printf("%d, ", array[i]);
	}
	printf("}\n");
}

