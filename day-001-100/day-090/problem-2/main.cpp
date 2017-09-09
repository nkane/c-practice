/*
 * A professor has constructed a two-dimensional array of double-percision
 * numbers having 35 rows and 4 columns. This array currently contains the
 * numerical grades of the students in the professor's four classes. Write
 * a C program that determines the total number of grades in the range less
 * than 60, greater than or equal to 60, and less than 70, greater than or
 * equal to 70 and less than 80, greater than or equal to 80 and less than
 * 90, and greater than or equal to 90.
 *
 * Include the possiblity that no grade could be present; additionally, 
 * use a indicator grade as a invalid grade flag.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define global_variable static

global_variable const int Rows = 35;
global_variable const int Columns = 4;
global_variable const int Invalid_Grade = -1;


void
GenerateNumbers2D(int array[Rows][Columns]);

void
PrintArray2D(int array[Rows][Columns]);

void
PrintArray(int array[5]);

void
CalculateGrades(int grades[Rows][Columns], int array[5], int invalidCode);

/* 
 * Index Info for Grade[5]:
 * 0 - A
 * 1 - B
 * 2 - C
 * 3 - D
 * 4 - F
 */
int
main()
{
	int TestCase[Rows][Columns] = { 0 };
	int Grades[5] = { 0 };

	GenerateNumbers2D(TestCase);
	PrintArray2D(TestCase);
	
	CalculateGrades(TestCase, Grades, Invalid_Grade);

	PrintArray(Grades);

	return 0;
}

void
GenerateNumbers2D(int array[Rows][Columns])
{
	for (int r = 0; r < Rows; r++)
	{
		for (int c = 0; c < Columns; ++c)
		{
			array[r][c] = (rand() % 100);
		}
	}
}

void
PrintArray2D(int array[Rows][Columns])
{
	printf("{\n");
	for (int r = 0; r < Rows; r++)
	{
		printf("\t{ ");
		for (int c = 0; c < Columns; ++c)
		{
			printf("%d, ", array[r][c]);
		}
		printf("},\n");
	}
	printf("}\n");
}

void
PrintArray(int array[5])
{
	printf("Grades: \n");
	for (int i = 0; i < 5; ++i)
	{
		switch (i)
		{
			case 0:
			{
				printf("A: ");
			} break;

			case 1:
			{
				printf("B: ");
			} break;

			case 2:
			{
				printf("C: ");
			} break;

			case 3:
			{
				printf("D: ");
			} break;

			case 4:
			{
				printf("F: ");
			} break;

			default: 
			{
			} break;
		}
		printf("%d\n", array[i]);
	}
}

void
CalculateGrades(int grades[Rows][Columns], int array[5], int invalidCode)
{
	int grade = 0;
	for (int r = 0; r < Rows; r++)
	{
		for (int c = 0; c < Columns; ++c)
		{
			grade = grades[r][c];
			if (grade > invalidCode)
			{
				if (grade >= 90)
				{
					++array[0];
				}
				else if (grade >= 80)
				{
					++array[1];
				}
				else if (grade >= 70)
				{
					++array[2];
				}
				else if(grade >= 60)
				{
					++array[3];
				}
				else 
				{
					++array[4];
				}
			}
		}
	}
}

