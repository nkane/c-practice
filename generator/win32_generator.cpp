#include <stdio.h>
#include <windows.h>

#define global_variable static
#define Assert(Expression) if(!(Expression)) {*(int *)0=0;}

global_variable const int Min_Args = 2;
global_variable const int Buffer_Size = 256;
global_variable char *BufferString;

void
ConcatString(char *, char *);

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
		ConcatString(BufferString, ".\\day-0\0");
		ConcatString(BufferString, argv[1]);
		if (!CreateDirectory(BufferString, NULL))
		{
			// FAILED
			Assert(1 == 0);
		}

		
		// SUCCESS
		// TODO(nick):
		// 1) create 3 sub-direction in inside of newly created directory
		// 2) create build.bat and main.cpp files inside all problem directories
		//

		// TODO(nick):
		// 1) repalce last char instead of clearing string
		ConcatString(BufferString, "\\problem-1");
		if (!CreateDirectory(BufferString, NULL))
		{
			// FAILED
			Assert(1 == 0);
		}
	
		ConcatString(BufferString, "\\build.bat");
		if (CreateFile(BufferString, (GENERIC_READ | GENERIC_WRITE), 0, NULL, (CREATE_NEW), (FILE_ATTRIBUTE_NORMAL), NULL) == INVALID_HANDLE_VALUE)
		{
			// FAILED
			Assert(1 == 0);
		}

		ClearToEmptyString(BufferString);
		ConcatString(BufferString, ".\\day-0\0");
		ConcatString(BufferString, argv[1]);
		ConcatString(BufferString, "\\problem-1");
		ConcatString(BufferString, "\\main.cpp");
		if (CreateFile(BufferString, (GENERIC_READ | GENERIC_WRITE), 0, NULL, (CREATE_NEW), (FILE_ATTRIBUTE_NORMAL), NULL) == INVALID_HANDLE_VALUE)
		{
			// FAILED
			Assert(1 == 0);
		}


		ClearToEmptyString(BufferString);
		ConcatString(BufferString, ".\\day-0\0");
		ConcatString(BufferString, argv[1]);
		ConcatString(BufferString, "\\problem-2");
		if (!CreateDirectory(BufferString, NULL))
		{
			// FAILED
			Assert(1 == 0);
		}

		ConcatString(BufferString, "\\build.bat");
		if (CreateFile(BufferString, (GENERIC_READ | GENERIC_WRITE), 0, NULL, (CREATE_NEW), (FILE_ATTRIBUTE_NORMAL), NULL) == INVALID_HANDLE_VALUE)
		{
			// FAILED
			Assert(1 == 0);
		}

		ClearToEmptyString(BufferString);
		ConcatString(BufferString, ".\\day-0\0");
		ConcatString(BufferString, argv[1]);
		ConcatString(BufferString, "\\problem-2");
		ConcatString(BufferString, "\\main.cpp");
		if (CreateFile(BufferString, (GENERIC_READ | GENERIC_WRITE), 0, NULL, (CREATE_NEW), (FILE_ATTRIBUTE_NORMAL), NULL) == INVALID_HANDLE_VALUE)
		{
			// FAILED
			Assert(1 == 0);
		}

		ClearToEmptyString(BufferString);
		ConcatString(BufferString, ".\\day-0\0");
		ConcatString(BufferString, argv[1]);
		ConcatString(BufferString, "\\problem-3");
		if (!CreateDirectory(BufferString, NULL))
		{
			// FAILED
			Assert(1 == 0);
		}
		ConcatString(BufferString, "\\build.bat");
		if (CreateFile(BufferString, (GENERIC_READ | GENERIC_WRITE), 0, NULL, (CREATE_NEW), (FILE_ATTRIBUTE_NORMAL), NULL) == INVALID_HANDLE_VALUE)
		{
			// FAILED
			Assert(1 == 0);
		}

		ClearToEmptyString(BufferString);
		ConcatString(BufferString, ".\\day-0\0");
		ConcatString(BufferString, argv[1]);
		ConcatString(BufferString, "\\problem-3");
		ConcatString(BufferString, "\\main.cpp");
		if (CreateFile(BufferString, (GENERIC_READ | GENERIC_WRITE), 0, NULL, (CREATE_NEW), (FILE_ATTRIBUTE_NORMAL), NULL) == INVALID_HANDLE_VALUE)
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

	// free memory for buffer string
	VirtualFree(BufferString, 0, MEM_RELEASE);

	return 0;
}

void
ConcatString(char *bufferString, char *string)
{
	// for each character in string
	// add to buffer string
	char c;
	
	if (string)
	{
		// is the bufferstring populated
		if (*bufferString && *bufferString != ' ')
		{
			// keep iterating over the bufferString
			// util null position is found
			c = *bufferString;
			while (c != '\0')
			{
				++bufferString;
				c = *bufferString;
			}
		}

		c = *string;
		while (c != '\0')
		{
			*bufferString = c;
			++bufferString;
			++string;
			c = *string;
		
		}
	}

	*bufferString = '\0'; 
}

void
ClearToEmptyString(char *string)
{
	char c = *string;
	while (c != '\0')
	{
		*string = ' ';
		++string;
		c = *string;
	}
}

