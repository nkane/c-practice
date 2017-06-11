/*
 * An extremely useful programming algorithm for rounding a real number to n decimal
 * places in:
 *
 * - step 1: multiply the number byt 10^n
 * - step 2: Add 0.5
 * - step 3: Delete the fractional part of the result
 * - step 4: Divide by 10^n
 *
 * - For example, using this algorithm to round the number 78.374625 to three decimal places
 *   yields:
 *   -> step 1: 78.374625 * 10^3 = 78374.625
 *   -> step 2: 78374.625 + 0.5 = 78375.125
 *   -> step 3: retaining the integer part = 78375
 *   -> step 4: 78375 / 10^3 = 78.375
 *
 * Use this information to write a C program named round() that rounds the value of it's first
 * paramter to the number of decimal palces specified by it's second parameter.
 *
 */

#include <stdio.h>
#include <math.h>

float Round(float, int);

int
main()
{
	float value = 0.0f;
	int percision = 0;

	printf("Enter in the value:\n"); 
	scanf("%f", &value);

	printf("Enter in the percision:\n");
	scanf("%d", &percision);

	printf("Value: %.6f\n", Round(value, percision));

	return 0;
}

float Round(float value, int percision)
{
	float result = 0.0f;
	result = (value * pow(10, percision));
	result = (result + 0.5f);
	result = ((int)(result));
	result = (result / pow(10, percision));
	return result;
}
