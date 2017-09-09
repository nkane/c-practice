/*
 * (Central Limit Theorem Simulation) Modify Program 6.9 so that it automatically generates
 * 20 simulations, with each simulation having 1000 tosses. Print out the percentage for each
 * run and the percentages for the 20 runs combined. Determine if the averages for the 20 runs
 * combined are closer to the 50 percent heads and tails than the majority of the individual
 * simulation results.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define global_variable static

global_variable const int Simulations = 20;
global_variable const int Test_Count  = 1000;
global_variable const int Total_Simulations_Tests = (Test_Count * Simulations);

int
flip(int);

float 
ComputePercentage(int, int);

void 
Print(int, int, int, float, float);

float
Diff(float, float);

struct ResultSet
{
	float IndividualHeadsAvg[Simulations];
	float IndividualTailsAvg[Simulations];
	float SimulationHeadsAvg;
	float SimulationTailsAvg;
};

int
main()
{
	int totalHeads = 0;
	int heads = 0;
	int tails = 0;

	ResultSet Results = 
	{
		0.0f,
		0.0f, 
		0.0f,
		0.0f,
	};
	
	for (int i = 0; i < Simulations; ++i)
	{
		heads = flip(Test_Count);
		tails = (Test_Count - heads);
		totalHeads += heads;

		Results.IndividualHeadsAvg[i] = ComputePercentage(Test_Count, heads);
		Results.IndividualTailsAvg[i] = ComputePercentage(Test_Count, tails);

		Print(Test_Count, heads, tails, Results.IndividualHeadsAvg[i], Results.IndividualTailsAvg[i]);
	}

	printf("=========================\n");
	printf("Total for Simulation:\n");
	Results.SimulationHeadsAvg = ComputePercentage((Total_Simulations_Tests), totalHeads);
	Results.SimulationTailsAvg = ComputePercentage((Total_Simulations_Tests), ((Total_Simulations_Tests) - totalHeads));
	Print(Total_Simulations_Tests, totalHeads, (Total_Simulations_Tests - totalHeads), Results.SimulationHeadsAvg, Results.SimulationTailsAvg);
	printf("=========================\n");

	int totalAvg = 0;
	int individualAvg = 0;
	for (int i = 0; i < Simulations; ++i)
	{
		if (Diff(50.0f, Results.SimulationHeadsAvg) < Diff(50.0f, Results.IndividualHeadsAvg[i]))
		{
			++totalAvg;
		}
		else
		{
			++individualAvg;
		}

		if (Diff(50.0f, Results.SimulationTailsAvg) < Diff(50.0f, Results.IndividualTailsAvg[i]))
		{
			++totalAvg;
		}
		else
		{
			++individualAvg;
		}
	}

	if (totalAvg > individualAvg)
	{
		printf("Average for combined is better!\n");
	}
	else
	{
		printf("Individual average(s) are better!\n");
	}

	return (0);
}

int flip(int numTimes)
{
	int randValue;
	int heads = 0;

	srand(time(NULL));

	for (int i = 1; i <= numTimes; ++i)
	{
		randValue = 1 + (int)rand() % 100;
		Sleep(1);
		if (randValue > 50) 
		{
			++heads;
		}
	}

	return (heads);
}

float 
ComputePercentage(int testCases, int resultAmount)
{
	float Result = 0.0f;
	Result = ((float)resultAmount / testCases) * 100.0f;
	return (Result);
}

float
Diff(float base, float testAmount)
{
	float Result = 0.0f;

	if (testAmount > base)
	{
		Result = (testAmount - base);
	}
	else
	{
		Result = (base - testAmount);
	}

	return (Result);
}


void 
Print(int numTosses, int heads, int tails, float headsavg, float tailsavg)
{
	if (numTosses <= 0)
	{
		printf("There were no tosses, so no percetnages can be calculated.\n");
	}
	else
	{
		printf("Number of coin tosses: %d\n", numTosses);
		printf("\tHeads: %d\tTails:%d\n", heads, tails);
		printf("Heads came up %6.2f percent of the time.\n", headsavg);
		printf("Tails came up %6.2f percent of the time.\n\n", tailsavg);
	}
}

