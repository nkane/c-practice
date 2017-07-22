/*
 * Define an array named PeopleTypes that can store a maximum of 50
 * integers values that will be entered at the keyboard. Enter a series
 * of 1s, 2s, 3s, and 4s into the array, where a 1 represents an infant,
 * a 2 presents a child, and a 3 represents a teenager, and a 4 represents
 * an adult who was present at a local school function. Any other integer
 * value should not be accepted as valid input and data entry should stop
 * when a negative value has been entered.
 *
 * This program should count the number of each 1, 2, 3, and 4 in the array
 * and output a list of how many infants, children, teenagers, and adults
 * were at the school function.
 *
 */

#include <stdio.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

#define global_variable static

global_variable const int Size = 50;

int
GetCount(int array[], int size, int lookup);

int
main()
{
	int InputData[Size] = { 0 };
	int temp = 0;
	int i = 0;

	while (i < len(InputData))
	{
		printf("Enter in a value [%d]: ", i);
		scanf("%d", &temp);
		if (temp > 0 && temp <= 4)
		{
			InputData[i] = temp;
			++i;
		}
		else if (temp < 0)
		{
			break;
		}
	}

	printf("Infant Count: %d\n", GetCount(InputData, len(InputData), 1));
	printf("Children Count: %d\n", GetCount(InputData, len(InputData), 2));
	printf("Teenagers Count: %d\n", GetCount(InputData, len(InputData), 3));
	printf("Adults Count: %d\n", GetCount(InputData, len(InputData), 4));

	return 0;
}

int
GetCount(int array[], int size, int lookup)
{
	int result = 0;
	for (int i = 0; i < size; ++i)
	{
		if (array[i] == lookup)
		{
			++result;
		}
	}

	return (result);
}

