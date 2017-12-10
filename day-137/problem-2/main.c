/*
 * Write a function that uses pointers to add a single character at the end of
 * and existing string. The function should replace the existing '\0' character
 * with the new character and append a new '\0' at the end of the string.
 *
 */

#include <stdio.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

int
StringLength(char *stringBuffer, int size);

void
ReplaceEndChar(char *stringBuffer, int endPosition, char replaceChar);

int
main()
{
    char stringBuffer[256] = "This is a test string inputs";

    printf("prior to replace: %s\n", stringBuffer);
    ReplaceEndChar(stringBuffer, StringLength(stringBuffer, len(stringBuffer)) - 1, 'z');
    printf("after replace: %s\n", stringBuffer);

    return 0;
}

int
StringLength(char *stringBuffer, int size)
{
    int i = 0;
    while (i < size && *(stringBuffer + i) != '\0')
    {
        ++i;
    }
    return i;
}

void
ReplaceEndChar(char *stringBuffer, int endPosition, char replaceChar)
{
    *(stringBuffer + endPosition++) = replaceChar;
    *(stringBuffer + endPosition) = '\0';
}
