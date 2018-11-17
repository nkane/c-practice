/*
 * Create a function that counts both characters and words. (Hint: Refer to Section
 * 7.3 on how to return multiple values.)
 * 
 */

#include <stdio.h>

#define Size 512

typedef struct _count
{
	int WordCount;
	int CharacterCount;
} Count;

Count *
CreateStruct();

void
ReleaseStruct(Count *count);

void
CountCharactersAndWords(char *stringBuffer, Count *outResult);

void
GetLine(char *stringBuffer);

int
main()
{
	char StringBuffer[Size] = { 0 };

	printf("Enter in a string: ");
	GetLine(StringBuffer);
	
	Count *CountResult = CreateStruct();
	CountResult->WordCount = 0;
	CountResult->CharacterCount = 0;

	CountCharactersAndWords(StringBuffer, CountResult);

	printf("Word Count: %d\n", CountResult->WordCount);
	printf("Character Count: %d\n", CountResult->CharacterCount);

	ReleaseStruct(CountResult);
	
	return 0;
}

Count *
CreateStruct()
{
	Count *Result = (Count *)malloc(sizeof(Count));
	return Result;
}

void
ReleaseStruct(Count *count)
{
	if (count)
	{
		free(count);
	}
}

// NOTE(nick): expecting somewhat reasonable input ... 
// probably not the best idea, but just practice ;)
void
CountCharactersAndWords(char *stringBuffer, Count *outResult)
{
	for (int i = 0; *(stringBuffer + i) != '\0'; ++i)
	{
		if (*(stringBuffer + i) != ' ' && *(stringBuffer + i) != '\n')
		{
			++outResult->CharacterCount;
		}
		if (*(stringBuffer + i) == ' ' || *(stringBuffer + i) == '\n')
		{
			++outResult->WordCount;
		}
	}
}

void
GetLine(char *stringBuffer)
{
	int i = 0;
	while ((*(stringBuffer + i++) = getchar()) != '\n');
}

