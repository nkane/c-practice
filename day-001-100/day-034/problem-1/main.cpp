/*
 * Write a C program to display the prompt:
 *
 * Please type in the total number of data values to be averaged:
 *
 * In response to this prompt, the program should accept a user-entered number and then 
 * use this number to control the number of times the while loop is executed. Thus, if the
 * user enters 6 in response to the prompt, the program should request the input of six numbers
 * and display the average of the next six numbers entered.
 */

#include <stdio.h>

struct UserInput
{
	int Iterations;
	float Total;
	float Average;
};

inline UserInput
CreateUserInput();

inline float
ComputeAverageUI(UserInput *);

inline void
PrettyPrint(UserInput *);

int
main()
{
	UserInput UI = CreateUserInput();
	float tempValue = 0.0f;

	int i = 0;
	while (i < UI.Iterations)
	{
		printf("Enter in value[%d]:\n", (i + 1));
		scanf("%f", &tempValue);
		UI.Total += tempValue;
		++i;
	}

	UI.Average = ComputeAverageUI(&UI);

	PrettyPrint(&UI);
	
	return 0;
}

inline UserInput
CreateUserInput()
{
	UserInput UI = {};

	printf("Please type in the total number of data values to be averaged:\n");
	scanf("%d", &UI.Iterations);

	return UI;
}

inline float
ComputeAverageUI(UserInput *ui)
{
	float result = 0.0f;
	result = (ui->Total / ui->Iterations);
	return result;
}

inline void
PrettyPrint(UserInput *ui)
{
	printf("The average is: %.2f\n", ui->Average);
}
