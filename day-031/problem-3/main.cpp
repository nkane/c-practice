/*
 * Write a C program that converts feet to meters. The program should display feet from
 * 3 to 30 in 3-foot increments and the corresponding meter equivalents. Use the relationship
 * that 1 meter is eqivalent to 3.28 feet.
 */

#include <stdio.h>

#define global_variable static

global_variable float Start_Point = 3.0f;
global_variable float End_Point = 30.0f;
global_variable float Increment_Value = 3.0f;
global_variable float Feet_Per_Meter = 3.28f;

struct Metric
{
	float Feet;
	float Meters;
};

inline Metric
CreateMetric(float feet);

inline float
ComputeMetersMetric(Metric *);

inline void
PrettyPrint(Metric *);

int
main()
{
	Metric M;

	for (float i = Start_Point; i < End_Point; i += Increment_Value)
	{
		M = CreateMetric(i);
		PrettyPrint(&M);
	}

	return 0;
}


inline Metric
CreateMetric(float feet)
{
	Metric M = 
	{
		feet,
		0.0f,
	};

	M.Meters = ComputeMetersMetric(&M);

	return M;
}

inline float
ComputeMetersMetric(Metric *m)
{
	float result = 0.0f;
	result = m->Feet / Feet_Per_Meter;
	return result;
}

inline void
PrettyPrint(Metric *m)
{
	printf("Feet: %.2f\tMeters: %.2f\n", m->Feet, m->Meters);
}
