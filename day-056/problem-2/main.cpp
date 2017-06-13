/*
 *
 * The owner of a strawberry farm has made the following arrangment with a group of 
 * students: They may pick all the strawberries they want. When they are through picking,
 * the strawberries will be weighed. The farm will retain 50 percent of the strawberries and
 * the students will divide the remainder evenly amoung them. Using this information, write 
 * a C program that has a function that accepts the number of students and the total pounds
 * picked as input arguments, and returns the approximate number of strawberries each receives.
 * Assume that a strawberry weights approximately 1 ounce. There are 16 ounces to a pound.
 *
 * 2 students
 * 512 strawberries
 * 256 strawberries
 * 256 / 16 = 16
 * 16 / 2 = 8 lbs for each student
 *
 */

#include <stdio.h>

#define global_variable static

global_variable const float Pounds_In_Ounces = 16.0f;

global_variable const float Retain_Amount = 2.0f;

inline float
ComputeTakeHomeAmount(int, int);


int
main()
{
	int studentCount = 0, totalPicked = 0;

	printf("Enter in the student amount:\n");
	scanf("%d", &studentCount);

	printf("Enter in the total strawberries picked:\n");
	scanf("%d", &totalPicked);

	printf("Each student should receive: %.2flbs", ComputeTakeHomeAmount(studentCount, totalPicked));

	return 0;
}

inline float
ComputeTakeHomeAmount(int studentCount, int totalPicked)
{
	float Result = 0.0f;
	Result = ((float)totalPicked / Retain_Amount);
	Result = (Result / Pounds_In_Ounces);
	Result = (Result / studentCount);
	return Result;
}

