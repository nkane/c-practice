/*
 * Write a C program that selects and displays the maximum value of five numbers that
 * are to be entered when the program is executed. (Hint: Use a for loop with both a 
 * scanf() and if statement internal to the loop.)
 *
 * Display maximum value and the position in the input set of numbers where the maximum
 * occurs.
 *
 */

#include <stdio.h>

#define global_variable static

global_variable const int Numbers = 5;

struct Input
{
	int Position;
	float Value;
};

inline void
PrettyPrintI(Input *);

int
main() 
{
	float value = 0.0f;
	Input I =
	{
		0,
		0.0f,
	};

	for (int i = 0; i < Numbers; ++i)
	{
		printf("Enter in a value:\n");
		scanf("%f", &value);

		if (I.Value < value)
		{
			I.Value = value;
			I.Position = (i + 1);
		}
	}

	PrettyPrintI(&I);

	return 0;
}

inline void
PrettyPrintI(Input *i)
{
	printf("Value: %.2f - Position: %d\n", i->Value, i->Position);
}

