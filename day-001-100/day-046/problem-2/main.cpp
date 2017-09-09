/*
 * Write a C program that continuously request a grade to be entered. If the grade is
 * less than 0 or greater than 100, your program should print an appropriate message
 * informing the user that an invalid grade has been entered, else the grade should be
 * added to a total. When a grade of 999 is entered, the program should exit the repetition
 * loop and compute and display the average of the valid grades entered.
 *
 */

#include <stdio.h>

#define global_variable static

global_variable const int GRADE_MAX = 100;
global_variable const int GRADE_MIN = 0;
global_variable const int EXIT_CODE = 999;
global_variable const int INVALID_MAX = 5;


global_variable bool Running = true;

int
main()
{
	int input = 0;
	int average = 0;
	int validCount = 0;
	int invalidCount = 0;

	do {
		printf("Enter in a grade: \n");
		scanf("%d", &input);
	
		if (input == EXIT_CODE)
		{
			printf("Exit code entered!\n");
			Running = false;
		}
		else if (input > GRADE_MAX || input < GRADE_MIN)
		{
			printf("Invalid grade entered!\n");
			if (invalidCount >= 5)
			{
				printf("Max invalid grades entered!");
				Running = false;
			}
			else 
			{
				++invalidCount;
			}
		}
		else
		{
			printf("Grade: %d\n", input);
			average += input;
			++validCount;
		}
	} while(Running);

	if (validCount > 0)
	{
		printf("Grade Sum: %d\n", average);
		printf("Total Grades: %d\n", validCount);
		printf("Grade Average: %d\n", (average / validCount));
	}

	return 0;
}
