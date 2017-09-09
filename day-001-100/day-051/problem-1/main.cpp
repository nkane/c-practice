/*
 * Write a function named conversions() that displays a table of miles converted to
 * kilometers. The function should accept the initial mile value to be converted, the
 * number of conversion to be made, and the increment between each mile value. For each
 * conversion the function should call a function named milesToKm() that accepts a
 * mle balue and returns its equivalent kilometer value. In computing the conversion,
 * use the relationship that there are 1.6093 kilometers per mile.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define global_variable static

global_variable const float Kilometers_Per_Mile = 1.6093f;

struct Distance
{
	float Miles;
	float Kilometers;
};

inline Distance *
CreateDistance();

inline float 
ComputeKilometersFromMiles(float);

inline void
DestoryDistance(Distance *);

int
main()
{
	int increments = 0;
	float incrementStep = 0;

	Distance * D = CreateDistance();

	printf("Enter initial mile value:\n");
	scanf("%f", &D->Miles);

	printf("Enter number of conversion:\n");
	scanf("%d", &increments);

	printf("Enter value of increments:\n");
	scanf("%f", &incrementStep);

	for (int i = 0; i < increments; ++i)
	{

		D->Kilometers = ComputeKilometersFromMiles(D->Miles);

		printf("Miles: %.2f\t", D->Miles);
		printf("Kilometers: %.2f\n", D->Kilometers);

		D->Miles += incrementStep;
	}

	DestoryDistance(D);
	return 0;
}

inline Distance *
CreateDistance()
{
	Distance * D = (Distance *)malloc(sizeof(Distance));
	return D;
}

inline float 
ComputeKilometersFromMiles(float m)
{
	return (m * Kilometers_Per_Mile);
}

inline void
DestoryDistance(Distance *d)
{
	if (d)
	{
		free(d);
	}
}


