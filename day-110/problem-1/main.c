/*
 * The Fog Index is an index that can be used to determine the approximate reading grade
 * level of an article. It is determined by measuring both sentence length and the fraction
 * of words with three or more syllables, without taking into account either the article's
 * conceptual difficulty or its clarity. The index is determined using the following steps:
 *
 * 	Step 1: Select a sample of at least 100 words
 * 	Step 2: Count the number of sentences. Any clause that is separated by a semicolon
 * 		or colon should be counted as a separated sentence.
 * 	Step 3: Count the number of words containing three or more syllables; but do not
 * 		include words that reach three or more syllables because of either "es" or
 * 		"ed" endings, or because they are compounds of simple words, such as everything
 * 		or seventeen.
 * 	step 4: Calculate the Fog Index using this formula
 *
 * 	FogIndex = 0.4 ((number of words / number of sentences) + 100 * (number of big words / number of words))
 *
 * For this exercise obtain sample of at least 10 sentences from a variety of sources, such as
 * children's books, high school textbooks, college textbooks, or a number of different newspaper.
 * For each of these samples, manually determine the number of words and big words contained in
 * the sample. Then write a C function that: accepts the number of words, accepts the number of
 * sentences, accept the number of big words, calculates a Fog Index, and returns the calculated
 * value. Verify the value returned by your function against your hand calculations
 *
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define Byte(value)(sizeof(uint8_t) * value)
#define Kilobyte(value)(Byte(1000) * value)
#define Megabyte(value)(Kilobyte(1000) * value)
#define Gigabyte(value)(Megabyte(1000) * value)

#define len(array)(sizeof(array)/sizeof(array[0]))

struct FogIndex
{
	float Result;
	int WordCount;
	int LargeWordCount;
	int SentenceCount;
};

void
ResetFogIndex(struct FogIndex *fogIndex);

void
ComputeFogIndex(char *stringBuffer, struct FogIndex *outResult);

bool
IsValidLargeWord(char *stringBuffer, int length);

bool
isCharVowel(char c);

void
PrintFogIndex(struct FogIndex *fogIndex, char *fileName);

int
main()
{
	char *fileNames[3] = 
	{
		"./data/data-0.txt",
		"./data/data-1.txt",
		"./data/data-2.txt",
	};

	char *stringBuffer = (char *)malloc(Kilobyte(25));
	memset(stringBuffer, 0, Kilobyte(25));

	struct FogIndex Result;
	ResetFogIndex(&Result);

	int i = 0;
	while (len(fileNames) > i)
	{
		FILE *currentFile = NULL;
		if (currentFile = fopen(*(fileNames + i), "r"))
		{
			fgets(stringBuffer, Kilobyte(25), currentFile);
			ComputeFogIndex(stringBuffer, &Result);
			PrintFogIndex(&Result, *(fileNames + i));
			fclose(currentFile);
			ResetFogIndex(&Result);
			memset(stringBuffer, 0, Kilobyte(25));
		}
		else
		{
			printf("Error: unable to read file - %s\n", *(fileNames + i));
		}
		++i;
	}

	if (stringBuffer)
	{
		free(stringBuffer);
	}

	system("pause");

	return 0;
}

void
ResetFogIndex(struct FogIndex *fogIndex)
{
	fogIndex->Result = 0.0f;
	fogIndex->WordCount = 0;
	fogIndex->SentenceCount = 0;
}

void
ComputeFogIndex(char *stringBuffer, struct FogIndex *outResult)
{
	int i = 0;
	bool inWord = false;
	char c = *(stringBuffer + i);
	char tempBuffer[256] = { 0 };
	int tempBufferCount = 0;
	while (c != '\0')
	{
		switch (c)
		{
			case ' ': 
			{
				inWord = false;
				*(tempBuffer + tempBufferCount) = '\0';
				if (IsValidLargeWord(tempBuffer, tempBufferCount))
				{
					++outResult->LargeWordCount;
				}
				tempBufferCount = 0;
				memset(tempBuffer, 0, 256);
			} break;

			case '.':
			case '?':
			case ';':
			case ':':
			case '!':
			{
				++outResult->SentenceCount;
			} break;

			default: 
			{
				if (inWord == false)
				{
					inWord = true;
					++outResult->WordCount;
				}
				if (isalpha((int)c) > 0)
				{
					*(tempBuffer + tempBufferCount++) = c;
				}
			} break;
		}
		c = *(stringBuffer + ++i);
	}
	outResult->Result = (0.4f * ((outResult->WordCount / outResult->SentenceCount) + 100.0f * (outResult->LargeWordCount / outResult->WordCount)));
}

// NOTE(nick):
// - 4 letters is the shortest 3 syllable word in the english language
// - very basic syllable checker, not completely accurate
bool
IsValidLargeWord(char *stringBuffer, int length)
{
	bool result = false;
	int i = 0;
	if (length >= 4)
	{
		int j = 0;
		while (*(stringBuffer + j) != '\0')
		{
			if (isCharVowel(*(stringBuffer + j)))
			{
				++i;
				if (i >= 3)
				{
					result = true;
					break;
				}
			}
			++j;
		}
	}
	return result;
}

bool
isCharVowel(char c)
{
	bool result = false;
	switch (tolower(c))
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		{
			result = true;
		} break;
		default:
		{
			// NOTE(nick): do nothing
		} break;
	}
	return result;
}

void
PrintFogIndex(struct FogIndex *fogIndex, char *fileName)
{
	printf("File Name: %s\n", fileName);
	printf("Word Count: %d\n", fogIndex->WordCount);
	printf("Large Word Count: %d\n", fogIndex->LargeWordCount);
	printf("Sentence Count: %d\n", fogIndex->SentenceCount);
	printf("Fog Index: %6.2f\n\n", fogIndex->Result);
}

