/*
 * Write a C program to calculate the volume of a pool. The quation for
 * determining the volume is volume = length * width * depth. Assume that
 * the pool has a length of 25 feet, a width of 10 feet, and a depth of 6
 * feet.
 */

#include <stdio.h>


struct Pool
{
	float length;
	float width;
	float depth;
};


inline float 
Calculate_Volume_Pool(Pool);

int main(void)
{
	Pool p = 
	{
		25.0f,
		10.0f,
		6.0f,
	};

	float volume = Calculate_Volume_Pool(p);

	printf("Pool Volume: %.3f", volume);

	return 0;
}


inline float 
Calculate_Volume_Pool(Pool p)
{
	float result = (p.length * p.width * p.depth);
	return result;
}
