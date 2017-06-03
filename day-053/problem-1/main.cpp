/*
 * Write a program to calculate a child's normal weight and a percent weight difference
 * in addition to the calculated height values. Assume the fomrula for predicting normal 
 * weight, in pounds, is given by the formula:
 *
 * 	- normal weight = 0.5 (age - 6) + 5.0 (age - 6) + 48
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define global_variable static

struct Person
{
	float Age;
	float Height;
	float Weight;
};

inline float
HeightNormal(float);

inline float
WeightNormal(float);

inline float
PercentDifference(float, float);

inline void
PrettyPrint(float, float, char *); 

inline Person *
CreatePerson();

inline void
DestroyPerson(Person *);

global_variable float NormalHeight;
global_variable float NormalWeight;
global_variable float HeightDiff;
global_variable float WeightDiff;

int
main()
{
	Person * P = CreatePerson();

	NormalHeight = HeightNormal(P->Age);
	HeightDiff = PercentDifference(P->Height, NormalHeight);

	PrettyPrint(NormalHeight, HeightDiff, "height");

	NormalWeight = WeightNormal(P->Age);
	WeightDiff = PercentDifference(P->Weight, NormalWeight);

	PrettyPrint(NormalWeight, WeightDiff, "weight");

	DestroyPerson(P);

	return 0;
}

inline float
HeightNormal(float age)
{
	const float Min_Age = 6.0f;
	float result = 0.0f, ageDiff = 0.0f;

	ageDiff = (age - Min_Age);
	result = (-0.25f * pow(ageDiff, 2) + 3.5f * ageDiff + 45.0f);

	return 	result;
}

inline float
WeightNormal(float age)
{
	float result = 0.0f;

	result = (0.5f * (age - 6.0f) + 5.0f * (age - 6.0f) + 48);
	
	return result;
}

inline float
PercentDifference(float actual, float base)
{
	float result = 0.0f;
	
	result = ((actual - base) / base * 100.0f);

	return result;
}


inline Person *
CreatePerson()
{
	Person *P = (Person *)malloc(sizeof(Person));
	int years = 0 , months = 0;

	printf("How old in years is the person:\n");
	scanf("%d", &years);

	printf("How old in months is the person:\n");
	scanf("%d", &months);

	printf("Enter in the height:\n");
	scanf("%f", &P->Height);

	printf("Enter in the weight:\n");
	scanf("%f", &P->Weight);

	P->Age = (years + (months / 12.0f));

	return P;
}

inline void
DestroyPerson(Person *p)
{
	if (p)
	{
		free(p);
	}
}

inline void
PrettyPrint(float normalHeight,  float percentDiff, char * type)
{
	printf("The average %s in inches is: %5.2f\n", type, normalHeight);
	printf("The actual %s deviates from the normal by: %5.2f%c\n", type, percentDiff, '%');
}

