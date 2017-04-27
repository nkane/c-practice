/*
 * Create a program that continously request for grades to be entered and compute the average. 
 *
 */

#include <stdio.h>
#include <ctype.h>

struct Grade
{
	float Current;
	float Total;
	float Average;
	int TotalGrades;
};

inline Grade
CreateGrade();

inline float
ComputeAverageG(Grade *);

inline void
PrettyPrint(Grade *);

int
main()
{
	char end = 'N';
	Grade G = CreateGrade();

	do {
		printf("Enter in the current grade:\n");
		scanf("%f", &G.Current);
		G.Total += G.Current;
		++G.TotalGrades;

		printf("Do you want to enter another grade? (y/n)\n");
		scanf("\n%c", &end);
	} while (toupper(end) != 'N'); 

	G.Average = ComputeAverageG(&G);
	PrettyPrint(&G);

	return 0;
}

inline Grade
CreateGrade()
{
	Grade G = {};
	return G;
}

inline float
ComputeAverageG(Grade *g)
{
	float result = 0.0f;
	result = (g->Total / g->TotalGrades);
	return result;
}

inline void
PrettyPrint(Grade *g)
{
	printf("The grade average is: %.2f\n", g->Average);
}
