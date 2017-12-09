/*
 * Write a program that stores the following letters in the array named message:
 * "This is a test". Have your program copy the data stored in message to another
 * array named mess2 and then display the letter in the mess2 array.
 *
 */

#include <stdio.h>

#define SIZE 14
#define len(array)(sizeof(array)/sizeof(array[0]))

typedef unsigned char byte;

void 
CopyArray(void *src, void *dest, int elementSize, int arraySize);

void
PrintCharArray(char *string, int size);

int
main()
{
    char message[SIZE] = "This is a test";
    char messageCopy[SIZE] = { 0 };

    CopyArray(message, messageCopy, sizeof(message[0]), len(message));
    PrintCharArray(messageCopy, len(messageCopy));

    return 0;
}

void 
CopyArray(void *src, void *dest, int elementSize, int arraySize)
{
    int i;
    for (i = 0; i < arraySize; ++i)
    {
        *((byte *)dest + (elementSize * i)) = *((byte *)src + (elementSize * i));
    }
    *((byte *)dest + (elementSize * i)) = '\0';
}

void
PrintCharArray(char *string, int size)
{
    int i;
    printf("%s\n", string);
}
