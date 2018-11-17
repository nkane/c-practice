/*
 *  Write a function named remove() that deletes all occurences of a character from a string.
 *  The function should take two arguments: the string name and the character to be remove.
 *  For example, if message contains the string "HappyHolidays", the function call
 *  remove(message, 'H') should plce the string "apppolidays" into message.
 *
 */

#include <stdio.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

void
Remove(char *stringBuffer, char removeChar);

void
CopyBuffer(char *src, char *dest);

int
main()
{
    char message[] = "HappyHolidays";

    printf("original: %s\n", message);
    Remove(message, 'H');
    printf("remove: %s\n", message);

    return 0;
}

void
Remove(char *stringBuffer, char removeChar)
{
    char tempBuffer[256] = { 0 };
    int i;
    int j;
    for (i = 0, j = 0; *(stringBuffer + i) != '\0'; ++i)
    {
        if (*(stringBuffer + i) != removeChar)
        {
            *(tempBuffer + j) = *(stringBuffer + i);
            ++j;
        }
    }
    CopyBuffer(tempBuffer, stringBuffer);
}

void
CopyBuffer(char *src, char *dest)
{
    for (src; *src != '\0'; ++src, ++dest)
    {
        *dest = *src;
    }
    *dest = '\0';
}
