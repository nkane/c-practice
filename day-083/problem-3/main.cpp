/*
 * Write a C program that reads a list of double-precision grades
 * from the keyboard into an array named grades. The grades are
 * to be counted as they are read, and entry is to be terminated
 * when a negative value has been entered. Once all of the grades
 * have been input, your program should find and display the sum
 * and average of the grades. The grades should then be listed
 * with an asterisk (*) in front of each grade that is below
 * average.
 *
 * Extend the program written above, to display each grade
 * and its letter equivalent. Assume the following scale:
 * 	- A: greater or equal to 90
 * 	- B: greater or equal to 80 and less than 90
 * 	- C: greater or equal to 70 and less than 80
 * 	- D: greater or equal to 60 and less than 70
 * 	- F: anything below or equal to 59
 *
 */

#include <stdio.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

#define global_variable static

global_variable const int Size = 256;

void
OutputGrades(double array[], int size);

int
main()
{
	int gradeCount = 0;
	double gradeInput[Size];
	double gradeAverage = 0.0l;

	do {
		printf("Enter in a grade: ");
		scanf("%lf", &gradeInput[gradeCount]);
		if (gradeInput[gradeCount] >= 0.0l)
		{
			gradeAverage += gradeInput[gradeCount];
			++gradeCount;
		}
	} while (gradeInput[gradeCount] >= 0.0l);

	printf("Grade(s) sum: %.2lf\n", gradeAverage);
	printf("Grade(s) average: %.2lf\n", (gradeAverage / gradeCount));

	OutputGrades(gradeInput, gradeCount);

	return 0;
}

void
OutputGrades(double array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (array[i] >= 90.0l)
		{
			printf("Grade: A");
		}
		else if(array[i] >= 80.0l)
		{

			printf("Grade: B");
		}
		else if(array[i] >= 70.0l)
		{
			printf("Grade: C");
		}
		else if (array[i] >= 60.0l)
		{
			printf("* Grade: D");
		}
		else 
		{
			printf("* Grade: F");
		}
		printf("\n");
	}
}

