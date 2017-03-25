/*
 * Newton's law of cooling states that when a object with an initial
 * temperature, itemp, is placed in a surrounding substance of temperature
 * a, it will reach a temperature tfin in t minutes according to the formula
 * tfin = a + (itemp + a) * e^(-kt). In this formula k is a thermal coefficient,
 * which depends on the material being cooled. Using this formula, write,
 * compile, and execute a C program that determines the temperature reached by
 * an object after 20 minutes when it is placed in a glass of water whose
 * temperature is 60 degrees. Assume that the object initially has a temperature
 * of 150 degrees and has a thermal constant of 0.0367 and e is a constant of
 * 2.72
 *
 * Next, determine the temperature of the same object, with an initial temperature
 * of 150 degrees, after 10 minutes when it is placed in a glass of water whose
 * temperature is 50 degrees.
 */

#include <stdio.h>
#include <math.h>

#define E_CONST 2.72f

struct Object 
{
	float Temperature;
	float ThermalConst;
	float CoolingTime;
};

inline Object
MakeObject(float, float, float);

inline float
ComputeCooledTemperature(Object *, float);

inline void
PrettyPrint(Object *, float);

int
main(void)
{
	// NOTE(nick): first portion of problem
	Object O1 = MakeObject(150.0f, 0.0367f, 20.0f);
	float resultTemp = ComputeCooledTemperature(&O1, 60.0f);
	PrettyPrint(&O1, resultTemp);

	// NOTE(nick): seocnd portion of problem
	O1.CoolingTime = 10.0f;
	resultTemp = ComputeCooledTemperature(&O1, 50.0f);
	PrettyPrint(&O1, resultTemp);

	return 0;
}

inline Object
MakeObject(float temp, float thermConst, float coolTime)
{
	return Object 
	{
		temp,
		thermConst,
		coolTime,
	};
}

inline float
ComputeCooledTemperature(Object * object, float surroundingTemp)
{
	// tfin = a + (itemp + a) * e^(-kt)
	float result = (object->Temperature + surroundingTemp);
	result = (result * pow(E_CONST, (-1 * (object->ThermalConst * object->CoolingTime))));
	return result;
}

inline void
PrettyPrint(Object * object, float resultTemp)
{
	printf("Object Initial Temp: %.2f\n", object->Temperature);
	printf("Object Thermal Const: %.2f\n", object->ThermalConst);
	printf("Object Cool Time: %.2f\n", object->CoolingTime);
	printf("Resulting Temp: %.2f\n", resultTemp);
}
