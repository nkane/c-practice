/*
 * The followng function, convert(), "marches along" the string passed to it and
 * sends each character in the string one at a time to the toUpper() function until
 * the NULL character is encountered.
 *
 * The toUpper() function takes each character passed to it and first examines it to
 * determine if the character is lowercase letter (a lowercase letter is any character
 * between a and z, inclusive). Assuming that characters are stored using the standard
 * ASCII character codes, the expression letter - 'a' + 'A'  converts a lowercase letter
 * to its uppercase equivalent. Rewrite the convert() function using pointers.
 *
 * Include the convert() and toUpper() functions in a working program. The program
 * should prompt thet user for a string and echo the string back to the user in uppercase
 * letters. Use gets() and puts() for string input and display.
 *
 */

#include <stdio.h>

char
ToUpper(char c);

void
Convert(char *string);

int
main()
{
    char stringBuffer[256] = { 0 };

    printf("Enter in a string: ");
    gets(stringBuffer);

    Convert(stringBuffer);

    printf("Output: %s", stringBuffer);

	return 0;
}

void
Convert(char string[])
{
	int i = 0;
	while (string[i] != '\0')
	{
        char *c = (string + i);
        *c = ToUpper(*c);
		string[i] = ToUpper(string[i]);
		++i;
	}
}

char
ToUpper(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 'a' + 'A');
	}
	else
	{
		return (c);
	}
}
