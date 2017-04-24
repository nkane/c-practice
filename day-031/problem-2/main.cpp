/*
 * Write a C program that converts gallons to liters. The program should display 
 * gallons from 10 to 20 in 1-gallon increments and the corresponding liter equivalents.
 * Use the relationship that 1 gallon contains 3.785 liters.
 */

#include <stdio.h>

#define global_varaible static

global_varaible float Start_Point = 10.0f;
global_varaible float End_Point = 20.0f;
global_varaible float Increment_Value = 1.0f;
global_varaible float Liters_Per_Gallon = 3.785f;

struct LiquidMeasurement
{
	float Gallons;
	float Liters;
};

inline LiquidMeasurement
CreateLiquidMeasurement(float gallons);

inline float
ComputeLitersLM(LiquidMeasurement *);

inline void
PrettyPrint(LiquidMeasurement *);

int
main()
{
	LiquidMeasurement LM;

	float currentGallons = Start_Point;

	while (currentGallons < End_Point)
	{
		LM = CreateLiquidMeasurement(currentGallons);
		PrettyPrint(&LM);
		currentGallons += Increment_Value;
	}

	return 0;
}

inline LiquidMeasurement
CreateLiquidMeasurement(float gallons)
{
	LiquidMeasurement LM = 
	{
		gallons,
		0.0f,
	};

	LM.Liters = ComputeLitersLM(&LM);

	return LM;
}

inline float
ComputeLitersLM(LiquidMeasurement *lm)
{
	float result = 0.0f;
	result = (lm->Gallons * Liters_Per_Gallon);
	return result;
}

inline void
PrettyPrint(LiquidMeasurement *lm)
{
	printf("Gallons: %.2f\tLiters: %.2f\n", lm->Gallons, lm->Liters);
}

