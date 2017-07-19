/*
 * main.h
 */

#define len(array)(sizeof(array)/sizeof(array[0]))

#define global_variable static

global_variable const int Size = 5;

void
GenerateNumbers(int array[], int size);

void
PrintArray(int array[], int size, char *text);

