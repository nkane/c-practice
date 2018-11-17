/*
 * Write a C program that accepts a string and two integer numbers from a user. Each of these
 * inputs should be preceeded by a prompt and stored using individual variable names. Have your
 * program call a function that assembles the input data into a single string. Display the
 * assembled string using a puts() call.
 *
 */

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>

#define Size 256

int
GetLine(char *stringBuffer, int max);

char *
Combined(char *format, ...);

void
Concatenate(char *sourceString, char *string);

int
main()
{
	char StringBuffer[Size] = { 0 };
	char *Result = NULL;
	int x = 0, y = 0;

	printf("Enter in a string: \n");
	GetLine(StringBuffer, Size);

	printf("Enter in two integers: ");
	scanf("%d %d", &x, &y);

	Result = Combined("s d d", StringBuffer, x, y);
	if (Result)
	{
		printf("%s\n", Result);
		free(Result);
	}

	system("pause");

	return 0;
}

int
GetLine(char *stringBuffer, int max)
{
	int i = 0;
	while (i < max && (*(stringBuffer + i) = getchar()) != '\n')
	{
		++i;
	}
	*(stringBuffer + i) = '\0';
	return (i - 1);
}

char *
Combined(char *format, ...)
{
	char *result = NULL;
	va_list args;
	va_start(args, format);
	char *stringFormat = NULL;
	int intFormat;
	char c;

	int size = (sizeof(char) * (Size * 2));
	result = (char *)malloc(size);
	memset(result, '\0', size);
	for (int i = 0; *(format + i) != '\0'; ++i)
	{
		c = *(format + i);
		if (c == 's')
		{
			stringFormat = va_arg(args, char *);
			if (i > 0)
			{
				Concatenate(result, " ");
			}
			Concatenate(result, stringFormat);
		}
		else if (c == 'd')
		{
			intFormat = va_arg(args, int);
			if (i > 0)
			{
				Concatenate(result, " ");
			}
			itoa(intFormat, stringFormat, 10);
			Concatenate(result, stringFormat);
		}
	}
	va_end(args);
	return result;
}

void
Concatenate(char *sourceString, char *string)
{
	int i = 0;
	while (*(sourceString + i) != '\0')
	{
		++i;
	}
	int j = 0;
	while (*(string + j) != '\0')
	{
		*(sourceString + i) = *(string + j);
		++j;
		++i;
	}
}

