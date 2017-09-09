/*
 * A recipe for making enough acorn squash for four people requires for the following
 * ingredients:
 * 	- 2 acorn squashes
 * 	- 2 teaspoons of lemon juice
 * 	- 1/4 cup of raisins
 * 	- 1 1/2 cups of applesauce
 * 	- 1/4 cup of brown sugar
 * 	- 3 tablespoons of chopped walnuts
 *
 * Using this information, write and test six functions that each accept the number of people
 * that musts be served and return the amount of each ingredient, respectively, that is required.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define global_variable static

global_variable const int Base_Amount = 4;

struct AcornSquash
{
	float Squashes;
	float LemonJuice;
	float Raisins;
	float AppleSauce;
	float BrownSugar;
	float ChoppedWalnuts;
};

inline AcornSquash*
CreateAS(int, int);

inline void
ReleaseAS(AcornSquash *);

inline float
ComputeAcornSquashAmount(int, int);

inline float
ComputeLemonJuiceAmount(int , int);

inline float
ComputeRaisinAmount(int, int);

inline float
ComputeAppleSauce(int, int);

inline float
ComputeBrownSugar(int, int);

inline float
ComputeChoppedWalnuts(int, int);

inline void
PrettyPrintAS(AcornSquash *);

int
main()
{
	int peopleCount = 0;
	printf("Enter in the amount of people eating acorn squash:\n");
	scanf("%d", &peopleCount);
	AcornSquash *AS = CreateAS(Base_Amount, peopleCount);
	PrettyPrintAS(AS);
	ReleaseAS(AS);

	return 0;
}

inline AcornSquash*
CreateAS(int baseAmount, int personCount)
{
	AcornSquash *Result     = (AcornSquash*)malloc(sizeof(AcornSquash));
	Result->Squashes       = ComputeAcornSquashAmount(baseAmount, personCount); 
	Result->LemonJuice     = ComputeLemonJuiceAmount(baseAmount, personCount);
	Result->Raisins        = ComputeRaisinAmount(baseAmount, personCount);
	Result->AppleSauce     = ComputeAppleSauce(baseAmount, personCount);
	Result->BrownSugar     = ComputeBrownSugar(baseAmount, personCount);
	Result->ChoppedWalnuts = ComputeChoppedWalnuts(baseAmount, personCount);
	return Result;
}

inline void
ReleaseAS(AcornSquash *AS)
{
	if (AS)
	{
		free(AS);
	}
}

inline float
ComputeAcornSquashAmount(int base, int personCount)
{
	// 5 -> 5 / (4 / 2) = 5 / 2 = 2 1/2
	// 4 -> 4 / (4 / 2) = 4 / 2 = 2
	// 2 -> 2 / (4 / 2) = 2 / 2 = 1
	return ((float)personCount / ((float)base / 2.0f));
}

inline float
ComputeLemonJuiceAmount(int base, int personCount)
{
	return ComputeAcornSquashAmount(base, personCount);
}

inline float
ComputeRaisinAmount(int base, int personCount)
{
	// NOTE(nick): this seems correct?
	// 4/1 * 1/16 = 4 / 16 = 1 / 4
	// 2/1 * 1/16 = 2 / 16 = 2 / 8
	// 5/1 * 1/16 = 5 / 16 = 5 / 16
	float result = 0.0f;
	result = ((float)personCount * (1.0f / (float)(base * base)));
	return result;
}

inline float
ComputeAppleSauce(int base, int personCount)
{
	float result = 0.0f;
	result = ((float)personCount * (1.5f / (float)(base)));
	return result;
}

inline float
ComputeBrownSugar(int base, int personCount)
{
	float result = 0.0f;
	result = ComputeRaisinAmount(base, personCount);
	return result;
}

inline float
ComputeChoppedWalnuts(int base, int personCount)
{
	float result = 0.0f;
	result = ((float)personCount * 0.75f);
	return result;
}

inline void
PrettyPrintAS(AcornSquash *AS)
{
	printf("Squahes: %.2f whole\n", AS->Squashes);
	printf("Lemon Juice: %.2f teaspoons\n", AS->LemonJuice);
	printf("Raisins: %.2f cups\n", AS->Raisins);
	printf("Apple Sauce: %.2f cups\n", AS->AppleSauce);
	printf("Brown Sugar: %.2f cups\n", AS->BrownSugar);
	printf("Chopped Walnuts: %.2f tablespoons\n", AS->ChoppedWalnuts);
}

