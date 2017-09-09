/*
 * Using a do-while statement, write a C program to accept a grade. The program
 * should request a grade continuously as long as an invalid grade is entered. An invalid
 * grade is any grade less than 0 or greater than 100. After a valid grade has been entered,
 * your program should display its value.
 *
 * - Alert the user that an invalid grade as been entered
 * - Allow the user to exit the program by entering number 999
 * - Automatically terminate after five invalid grades have been entered
 *
 */

#include <stdio.h>

#define global_variable static

global_variable const int EXIT_CODE = 999;
global_variable const int MIN_GRADE = 0;
global_variable const int MAX_GRADE = 100;
global_variable const int INVALID_MAX = 5;
global_variable bool Running = true;

int
main()
{
	int Grade = 0; 
	int invalidCount = 0;

	do {
		printf("Enter in a grade value:\n");
		scanf("%d", &Grade);

		if (Grade == EXIT_CODE) 
		{
			printf("Exit code entered!\n");
			Running = false;
		}
		else if (Grade > MAX_GRADE || Grade < MIN_GRADE) 
		{
			printf("Invalid number entered!\n");
			if (invalidCount >= INVALID_MAX) 
			{
				printf("Max invalid numbers entered!\n");
				Running = false;
			}
			else
			{
				invalidCount++;
			}
		}
		else 
		{
			printf("Grade Entered: %d\n", Grade);
		}
	} while(Running);

	return 0;
}
