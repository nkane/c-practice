/*
 * Based on an automobile's model year and weight, the state of New Jersey determines
 * the car's weight class and registration fee using the following schedule:
 * 
 * | Model Year      | Weight              | Weight Class | Fee    |
 * |-----------------|---------------------|--------------|--------|
 * | 1970 or earlier | less than 2,700 lbs | 1		  | $16.50 |
 * |		     | 2,700 to 3,800 lbs  | 2		  | $25.50 |
 * |		     | more than 3,800 lbs | 3		  | $46.50 |
 * | 1971 to 1979    | less than 2,700 lbs | 4		  | $27.00 |
 * |		     | 2,700 to 3,800 lbs  | 5		  | $30.50 |
 * |		     | more than 3,800 lbs | 6		  | $52.50 |
 * | 1980 or later   | less than 3,500 lbs | 7		  | $35.50 |
 * |		     | more than 3,500 lbs | 8		  | $65.50 |
 * 
 * Using the information, write a C program that accepts the yearh and weight of an automobile
 * and determines and displays the weight clas and registration fee for the car.
 */


#include <stdio.h>

struct Key
{
	int WeightClass;
	float Fee;
};

const Key LookupTable[8]
{
	Key { 1, 16.50f },
	Key { 2, 25.50f },
	Key { 3, 46.50f },
	Key { 4, 27.00f },
	Key { 5, 30.50f },
	Key { 6, 52.50f },
	Key { 7, 35.50f },
	Key { 8, 65.50f },
};

struct Car 
{
	int Year;
	float Weight;
	int WeightClassIndex;
};

inline Car
CreateCar();

inline int
DetermineWeightClass(Car *);

inline void
PrettyPrint(Car *);

int
main()
{
	Car C = CreateCar();
	PrettyPrint(&C);

	return 0;
}

inline Car
CreateCar()
{
	Car C = {};

	printf("Enter in the year:\n");
	scanf("%d", &C.Year);

	printf("Enter in the weight:\n");
	scanf("%f", &C.Weight);

	C.WeightClassIndex = DetermineWeightClass(&C);

	return C;
}

inline int
DetermineWeightClass(Car *c)
{
	int index;
	if (c->Year <= 1970)
	{
		if (c->Weight < 2700.0f)
		{
			index = 0;
		}
		else if (c->Weight < 3800.0f)
		{
			index = 1;
		}
		else
		{
			index = 2;
		}
	}
	else if (c->Year <= 1979)
	{
		if (c->Weight < 2700.0f)
		{
			index = 3;
		}
		else if (c->Weight < 3800.0f)
		{
			index = 4;
		}
		else
		{
			index = 5;
		}
	}
	else 
	{
		if (c->Weight < 3500.0f)
		{
			index = 6;
		}
		else 
		{
			index = 7;
		}
	}

	return index;
}

inline void
PrettyPrint(Car *c)
{
	printf("Car Year: %d\n", c->Year);
	printf("Car Weight: %.2f\n", c->Weight);
	printf("Car Weight Class: %d\n", LookupTable[c->WeightClassIndex].WeightClass);
	printf("Car Fee: %.2f\n", LookupTable[c->WeightClassIndex].Fee);
}
