/*
 * Rewrite Program 6.6 in Seciton 6.3 so that lines 14 through 20 are replaced
 * by a function named getData(). This function should request a child's age,
 * in years and months, as integer values, and the child's height, as a floating-point
 * value. It should return both the child's age in years and the child's height as
 * floating-point values through its parameter list.
 *
 */

#include <stdio.h>
#include <math.h>

float
norms(float);

float 
percentDiff(float, float);

void getData(float *, float *);

void
showit(float, float);

int
main()
{
	float height, normht;
	float age, perdiff;

	getData(&age, &height);

	printf("Age: %f\n", age);
	printf("Height: %f\n", height);
	normht = norms(age);
	perdiff = percentDiff(height, normht);

	showit(normht, perdiff);

	return (0);
}

void getData(float *age, float *height)
{
	int years, months;
	printf("\nHow old (in years) is this child? ");
	scanf("%d", &years);

	printf("\nHow many months since the child's birthday? ");
	scanf("%d", &months);

	*age = years + months / 12.0f;

	printf("\nEnter the child's height (in inches): ");
	scanf("%f", height);
}

float
norms(float age)
{
	float agediff, avght;
	agediff = age - 6.0f;
	avght = -0.25f * pow(agediff, 2) + 3.5 * agediff + 45.0f;
	return (avght);
}

float 
percentDiff(float actual, float base)
{
	return ((actual - base) / base * 100.0f);
}

void
showit(float normht, float percentDiff)
{
	printf("Normal Height: %f\n", normht);
	printf("Percentage Difference: %f\n", percentDiff);
}

