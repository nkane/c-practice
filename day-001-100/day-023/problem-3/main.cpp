/*
 * In a pass / fail course, a student passes if the grade is greater
 * than or equal to 70 and fails if they grade is lower. Write a C
 * program that accepts a grade and prints the message A passing grade
 * or a failing grade as appropriate.
 */

#include <stdio.h>

#define PASSING_GRADE 70.0f

int
main(void)
{
	float grade = 0.0f;

	printf("Enter in a grade value (e.g., 76.7):\n");
	scanf("%f", &grade);

	if (grade >= PASSING_GRADE)
	{
		printf("A passing grade!\n");
	}
	else
	{
		printf("A failing grade!\n");
	}

	return 0;
}
