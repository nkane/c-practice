#include <stdio.h>
#include <windows.h>

#define global_variable static
#define Assert(Expression) if(!(Expression)) {*(int *)0=0;}

global_variable const int Min_Args = 2;
global_variable const int Buffer_Size = 256;
global_variable char *BufferString;

void
ConcatString(char *, char *, char*);

void
ClearToEmptyString(char *);

int 
main(int argc, char *argv[])
{
	if (argc >= Min_Args)
	{
		// alloc buffer for strings
		BufferString = (char *)VirtualAlloc(0, Buffer_Size, (MEM_COMMIT | MEM_RESERVE), PAGE_READWRITE);
		// file name needs to be day-###
		ConcatString(BufferString, ".\\day-0\0", argv[1]);
		if (!CreateDirectory(BufferString, NULL))
		{
			// FAILED
			Assert(1 == 0);
		}
	}
	else
	{
		// TODO(nick):
		// not enough args passed in 
	}

	// free buffer for string
	VirtualFree(BufferString, 0, MEM_RELEASE);

	return 0;
}

void
ConcatString(char *bufferString, char *firstString, char *secondString)
{
	// for each character in firstString
	// add to buffer string
	char c = *firstString;
	while (c != '\0')
	{
		*bufferString = c;
		++bufferString;
		++firstString;
		c = *firstString;
	}

	c = *secondString;
	while (c != '\0')
	{
		*bufferString = c;
		++bufferString;
		++secondString;
		c = *secondString;
	}

	*bufferString = '\0'; 
}

void
ClearToEmptyString(char *string)
{
	char c = *string;
	while (c != '\0')
	{
		c = ' ';
		++string;
		c = *string;
	}
}

