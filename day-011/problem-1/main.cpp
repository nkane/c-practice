/*
 * One of the longest suspension bridges in the world is New York City's
 * Verrazano-Narrows Bridge, which links Brooklyn to Staten Island.
 * In building this bridge, which is made of steel, allowance had to be
 * made for the expansion of the steel due to changes in temperature. The
 * change in the length of the bridge, delta L, in meters is given by
 * the formula delta L = L * 12 * 10^-6 * dela T, where L is the length,
 * in meters, that he bridge must span, 12 * 10^-6 is the thermal expansion
 * coefficient for steel, and delta T is the range of temperature, in degrees
 * Celsius, that the bridge will experience. Using this equation, write a C
 * program to determine thet expansion that the bridge will undergo if it spans
 * a length of 13,000 meters and can undergo temperature changes of 100 degrees
 * Celsius. (Note: The expansion is provided for by expansion joints placed
 * in the surface of the bridge, which automatically expand and contract as the
 * temperature changes.)
 */

#include <stdio.h>
#include <math.h>

struct Bridge 
{
	float Length;
	float ThermalExpansion;
	float DeltaTemperature;
	float DeltaLength;
};

inline float
ComputeBridgeCurrentLengthF(Bridge *);

inline void
PrettyPrint(Bridge *);

int
main(void)
{
	Bridge B = 
	{
		13000.f,
		(float)pow(10.0f, -6.0f),
		100.0f,
		0.0f,
	};

	B.DeltaLength = ComputeBridgeCurrentLengthF(&B);
	PrettyPrint(&B);

	return 0;
}

inline float
ComputeBridgeCurrentLengthF(Bridge *b)
{
	float result = ((b->Length * 12.0f * b->ThermalExpansion) * b->DeltaTemperature);
	return result;
}


inline void
PrettyPrint(Bridge *b)
{
	printf("Bridge Length: %.2f\n", b->Length);
	printf("Bridge Thermal Expansion: %.7f\n", b->ThermalExpansion);
	printf("Bridge Delta Temperature: %.2f\n", b->DeltaTemperature);
	printf("Bridge Detal Length: %.2f\n", b->DeltaLength);
}
