/*
 * Using pointers, repeat Programming Exercise 2 from Section 9.1
 *
 * Modify the vowels function given in 9.1 exercise 1 to count and display
 * individual number of each vowels contained in the string.
 *
 */

#include <stdio.h>
#include <ctype.h>

typedef unsigned char byte;

void
Vowels(char *string, byte *set);

int
GetKey(char c);

void
PrintVowels(byte *set);

int
main()
{
    char stringBuffer[256] = { 0 };
    byte set[5] = { 0 };

    printf("Enter in a string: ");
    gets(stringBuffer);

    Vowels(stringBuffer, set);
    PrintVowels(set);

	return 0;
}

void
Vowels(char *string, byte *set)
{
	int i = 0;
	char c;
	while ((c = *(string + i)) != '\0')
	{
        c = tolower(c);
		switch (c)
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
                set[GetKey(c)]++;
		}
        ++i;
	}
}

void
PrintVowels(byte *set)
{
    printf("Value A : %d\nValue B : %d\nValue I : %d\nValue O : %d\nValue U : %d\n",
           set[GetKey('a')],
           set[GetKey('e')],
           set[GetKey('i')],
           set[GetKey('o')],
           set[GetKey('u')]);
}

int
GetKey(char c)
{
    int key;
    switch (c)
    {
        case 'a':
        {
            key = 0;
        } break;

        case 'e':
        {
            key = 1;
        } break;

        case 'i':
        {
            key = 2;
        } break;

        case 'o':
        {
            key = 3;
        } break;

        case 'u':
        {
            key = 4;
        } break;
    }
    return key;
}
