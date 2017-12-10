/*
 * Write a C function that uses pointers to delete a single character from the end
 * of a string. This is effectively achieved by moving th \0 character one position
 * closer to the start of the string.
 *
 */

#include <stdio.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

void
DeleteEndCharFromString(char *s, int size);

int
StringSize(char *s, int size);

int
main()
{
    char stringBuffer[256] = "This is a test string case.";

    int i;
    for (i = 0; i < 10; ++i)
    {
        printf("prior to delete: %s\n", stringBuffer);
        DeleteEndCharFromString(stringBuffer, StringSize(stringBuffer, len(stringBuffer)) - 1);
        printf("after delete: %s\n\n", stringBuffer);
    }
   
    return 0;
}

void
DeleteEndCharFromString(char *s, int size)
{
    *(s + size) = '\0';
}

int
StringSize(char *s, int size)
{
    int i = 0;
    while (i < size && *(s + i) != '\0')
    {
        ++i;
    }
    return i;
}
