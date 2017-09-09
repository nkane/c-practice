/*
 * The following data was collected on a recent automobile trip:
 *
 * Mileage		| Gallons
 * 22495, start	  	  full tank
 * 22841		  12.2
 * 23185		  11.3
 * 23400		  10.5
 * 23772		  11.0
 * 24055		  12.2
 * 24434		  14.7
 * 24804		  14.3
 * 25276		  15.2
 *
 * Write a C program that accept a mileage and gallons value to calculate the mile-per-gallon (mpg)
 * achieved for that segment of the trip. The mpg is obtained as the difference in mileage between
 * fill-ups divided by the number of gallons of gasoline received in the fill-up. 
 *
 * (mileages2 - mileage1) / gallons
 *
 * Next, compute and display the cummulative mpg achieved after each fill-up. The cummulative mpg
 * is calculated as the difference between each fill-up mileage and the mileage at the start of the
 * trip divided by the sum of the gallons used to that point in the trip.
 * 
 * (totalMileage - startMileage) / (sum of all gallons used)
 */

#include <stdio.h>
#include <stdlib.h>

#define len(array) (sizeof(array) / sizeof(array[0]))
#define len2d(array) (sizeof(array[0]) / sizeof(array[0][0]))

#define global_variable static

global_variable float Data[9][2] =
{
	{ 22495.0f ,  0.0f },
	{ 22841.0f , 12.2f },
 	{ 23185.0f , 11.3f },
	{ 23400.0f , 10.5f },
	{ 23772.0f , 11.0f },
  	{ 24055.0f , 12.2f },
   	{ 24434.0f , 14.7f },
  	{ 24804.0f , 14.3f },
	{ 25276.0f , 15.2f },
};

struct Segment
{
	float Mileage;
	float Gas;
	Segment *NextNode;
	Segment *PreviousNode;
};

struct Trip
{
	Segment *Head;
	Segment *Tail;
	float TripMPG;
	float TotalMileage;
	float TotalGallonsGas;
};

inline Trip
CreateTrip(float*, int, int);

inline float
ComputeMPGPerSegmentT(Trip *);

inline void
CleanupTrip(Trip *);

int 
main()
{
	Trip T = CreateTrip(*Data, len2d(Data), len(Data));
	CleanupTrip(&T);

	return 0;
}

inline Trip
CreateTrip(float *data, int columns, int rows)
{
	Trip T = {};
	Segment *tempSeg = NULL;

	for (int r = 0; r < rows; ++r)
	{
		if (r == 0)
		{
			T.Head = (Segment *)malloc(sizeof(Segment));
			T.Tail = T.Head;
			tempSeg = T.Tail;
			T.Tail->NextNode = NULL;
			T.Tail->PreviousNode = NULL;
		}
		else 
		{
			tempSeg = (Segment *)malloc(sizeof(Segment));
			T.Tail->NextNode = tempSeg;
			T.Tail->NextNode->PreviousNode = T.Tail;
		}

		for (int c = 0; c < columns; ++c)
		{
			if (c == 0)
			{
				tempSeg->Mileage = *data;
			}
			else if (c == 1)
			{
				tempSeg->Gas = *data;
			}
			++data;
		}

		if (T.Tail->NextNode)
		{
			T.TotalMileage += (tempSeg->Mileage - tempSeg->PreviousNode->Mileage);
		}

		T.TotalGallonsGas += tempSeg->Gas;

		if (r > 0)
		{
			float segmentMpg = (T.Tail->NextNode->Mileage - T.Tail->Mileage) / T.Tail->NextNode->Gas;
			printf("Segment MPG: %.2f\n", segmentMpg);
			T.Tail = T.Tail->NextNode;
			T.Tail->NextNode = NULL;
		}
	}

	printf("Trip Total Mileage: %.2f\n", (T.TotalMileage / T.TotalGallonsGas));

	return T;
}

inline void
CleanupTrip(Trip *t)
{
	Segment *s = t->Head;

	while (s)
	{
		if (s->NextNode)
		{
			s = s->NextNode;
			free(s->PreviousNode);
		}
		else
		{
			free(s);
			s = NULL;
		}
	}
}

