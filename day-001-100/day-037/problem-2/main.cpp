/*
 * Write and run a C program that accepts 10 individual values of gallons, one at a time,
 * and converts each value entered to its liter equivalent before the next value is requested.
 * Use a for loop in your program. There are 3.785 liters in 1 gallon.
 *
 */

#include <stdio.h>

#define global_variable static

global_variable int Loop_Amount = 10;
global_variable float Liters_To_Gallons = 3.785f;

struct LiquidMeasurement
{
	float Gallons;
	float Liters;
};

inline LiquidMeasurement
CreateLiquidMeasurement();

inline float
ComputeLitersLM(LiquidMeasurement *);

inline void
PrettyPrint(LiquidMeasurement *);

int
main()
{
	LiquidMeasurement LM = CreateLiquidMeasurement();
	
	for (int i = 0; i < Loop_Amount; ++i)
	{
		printf("Enter in gallon amount:\n");
		scanf("%f", &LM.Gallons);
		LM.Liters = ComputeLitersLM(&LM);
		PrettyPrint(&LM);
	}

	return 0;
}

inline LiquidMeasurement
CreateLiquidMeasurement()
{
	LiquidMeasurement LM = {};
	return LM;
}

inline float
ComputeLitersLM(LiquidMeasurement *lm)
{
	float result = (lm->Gallons * Liters_To_Gallons);
	return result;
}

inline void
PrettyPrint(LiquidMeasurement *lm)
{
	printf("Gallons\tLiters\n");
	printf("%.2f\t%.5f\n", lm->Gallons, lm->Liters);
}

