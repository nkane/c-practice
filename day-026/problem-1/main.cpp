/*
 * A student's letter grade is calculated according to the following schedule. Write a C program
 * that accepts a student's numerical grade, converts the numerical grade to an equivalent letter
 * grade, and displays the letter grade.
 *
 * Numerical Grade  | Letter Grade
 * >= 90		A
 * < 90 && >= 80	B
 * < 80 && >= 70      	C
 * < 70 && >= 60	D
 * < 60			F
 */

#include <stdio.h>
#include <math.h>

#define len(array) (sizeof(array) / sizeof(array[0]))
#define LOWEST_TERM 50.0f

char Grades[] = { 'F', 'D', 'C', 'B', 'A' };

struct Grade
{
	float numerical;
	char letter;
};

inline Grade
CreateGrade();

inline char
DetermineLetterGrade(Grade *);

inline void
PrettyPrint(Grade *);

int
main()
{
	Grade G = CreateGrade();
	PrettyPrint(&G);
	return 0;
}

inline Grade
CreateGrade()
{
	Grade G = {};
	printf("Enter in the numerical grade:\n");
	scanf("%f", &G.numerical);
	
	G.letter = DetermineLetterGrade(&G);

	if (G.letter == NULL)
	{
		printf("Error occured determining letter grade!\n");
	}

	return G;
}

// if the letter grade = 90 
// 90 - 50 
// 40 
// 40 / 10 -> index of letter grade
inline char DetermineLetterGrade(Grade *g) 
{
	char result;
	int numerical = g->numerical;

	if (g->numerical > 100)
	{
		numerical = 100;
	}
	else if (g->numerical < 50)
	{
		numerical = 50;
	}

	unsigned int index = (int)((floor(numerical) - LOWEST_TERM) / 10);
	
	if (index > len(Grades))
	{
		return NULL;
	}

	result = Grades[index];
	return result;
}

inline void
PrettyPrint(Grade *g)
{
	printf("The numerical grade is: %.2f\n", g->numerical);
	printf("The letter grade is: %c\n", g->letter);
}
