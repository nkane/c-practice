/*
 * Using pointers, repeat Program Exercise 1 from section 9.1
 *
 * 9.1 - Exercise 1
 * Description:
 * The following vowels() function can be used to select and display all
 * vowels within a user-input string.
 *
 * Notice that the switch statement in vowels uses the fact that selected
 * cases "drop through" in the absense of break statements. Thus, all selected
 * cases result in a putchar() function call. Include vowels() in a working
 * program that accepts a user-input string and then displays all vowels in
 * the string. In response to the input How much is the litter worth worth?,
 * your program should display ouieieoo
 *
 * Modify the vowels() function to count and display the total number of vowels
 * contained in the string passed to it
 *
 */

#include <stdio.h>

void
Vowels(char *string);

int
main()
{
    char stringBuffer[256] = { 0 };
    printf("Enter in a string: ");
    gets(stringBuffer);
    printf("Vowels print out:\n");
    Vowels(stringBuffer);

	return 0;
}

void
Vowels(char string[])
{
	int i = 0;
	char c;
	while ((c = *(string + i)) != '\0')
	{
		switch (c)
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				putchar(c);
        		putchar('\n');
		}
        ++i;
	}
}
