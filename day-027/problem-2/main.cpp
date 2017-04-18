/*
 * Rewrite the following program using a switch statement:
 *
 * #include <stdio.h>
 * int main()
 * {
 *	char marcode;
 *	
 *	printf("Enter a martial code: ");
 *	scanf("%c", &marcode);
 *	
 *	if (marcode == 'M')
 *		printf("\nIndividual is married.\n");
 *	else if (marcode == 'S')
 *		printf("\nIndividual is single.\n");
 *	else if (marcode == 'D')
 *		printf("\nIndividual is divorced.\n");
 *	else if (marcode == 'W')
 *		printf("\nIndividual is widowed.\n");
 *	else
 *		printf("\nAn invalid code was entered.\n");
 *
 *	return 0;
 * }
 */

#include <stdio.h>
#include <ctype.h>

inline void
PrintMartialStatus(char);

int
main()
{
	char marcode;

	printf("Enter a martial code:\n");
	scanf("%c", &marcode);

	PrintMartialStatus(toupper(marcode));

	return 0;
}

inline void
PrintMartialStatus(char c)
{
	switch (c)
	{
		case 'M':
		{
			printf("Individual is married.\n");
		} break;

		case 'S':
		{
			printf("Individual is single.\n");
		} break;

		case 'D':
		{
			printf("Individual is divorced.\n");
		} break;

		case 'W':
		{
			printf("Individual is widowed\n");
		} break;

		default:
		{
			printf("An invalid code was entered.\n");
		} break;
	}
}
