/*
 * 	logfind.c
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "logfind.h"
#include "dbg.h"

global_variable const char *DefaultLogFilePath = "/home/pi/.logfind";
global_variable const int MaxLineBuffer = 128;
global_variable const int MaxListSize = 10;

internal uint8_t
Write_Default_Log_File()
{
	uint8_t success = 0;
	FILE *outFile = fopen(DefaultLogFilePath, "w");
	if (outFile)
	{
		fclose(outFile);
		success = 1;
	}
	return success;
}

char **
Read_Log_File_List()
{
	FILE *defaultLogFile = fopen(DefaultLogFilePath, "r");
	if (defaultLogFile == NULL)
	{
		check(Write_Default_Log_File() == 1, "Failed to create default log file");
	}
	char **fileList = NULL;
	uint32_t lineNumber = 0;
	uint8_t currentBufferNumber = 0;
	int16_t currentCharacter = 0;
	// allocate memory for array of pointers
	fileList = (char **)calloc(MaxListSize, sizeof(char *));
	check_mem(fileList);
	// allocate memory for first string
	fileList[lineNumber] = (char *)malloc(MaxLineBuffer * sizeof(char));;
	while ((currentCharacter = fgetc(defaultLogFile)) != EOF)
	{
		if (currentCharacter == '\n' || currentCharacter == '\0')
		{
			lineNumber++;
			currentBufferNumber = 0;
			fileList[lineNumber] = (char *)malloc(MaxLineBuffer * sizeof(char));;
			check_mem(fileList[lineNumber]);
		}
		else
		{
			check(currentBufferNumber < MaxLineBuffer, "Path to log file is too large.");
			fileList[lineNumber][currentBufferNumber] = currentCharacter;
			currentBufferNumber++;
		}
	}
	fclose(defaultLogFile);
	return fileList;
error:
	// TODO(nick): finish clean up
	if (defaultLogFile)
	{
		fclose(defaultLogFile);
	}
	return NULL;
}

void
Check_Log_For_Match(char *logFilePath, int compareType, ...)
{
	va_list argPointer;
	char **compareStringList = NULL;
	uint32_t listPosition = 0;
	uint32_t listSize = 0;
	FILE *logFile = NULL;

	check(compareType > 0, "Invalid Compare Type Passed in.");
	debug("Opening Log File: %s", logFilePath);
	logFile = fopen(logFilePath, "r");
	check_mem(logFile);
	debug("Beginning to Read Log File: %s", logFilePath);
	va_start(argPointer, compareType);

	// first argument should be list position
	listPosition = va_arg(argPointer, uint32_t);
	debug("List Starting Position: %d", listPosition);

	// second argument should be list size
	listSize = va_arg(argPointer, uint32_t);
	debug("List Size: %d", listSize);

	// third argument should be compare list
	compareStringList = va_arg(argPointer, char **);
	check_mem(compareStringList);

	va_end(argPointer);

	char wordBuffer[MaxLineBuffer] = { 0 };
	int32_t c = 0;
	int32_t i = 0;
	int32_t fileLineNumber = 1;
	int32_t uniqueMatch = 0x00;
	int32_t matchCount = 0;
	while ((c = fgetc(logFile)) != EOF)
	{
		if (c == '\n' || c == ' ')
		{
			// check compareStringList against current wordBuffer
			uint8_t match = 0;
			uint32_t j = listPosition;
			int32_t wordBufferLength = strlen(wordBuffer);
			debug("Word: %s - Word Buffer Length: %d", wordBuffer, wordBufferLength);
			for (j = listPosition; j <= listSize; j++)
			{
				debug("compare: %s == %s", wordBuffer, compareStringList[j]);
				if (wordBufferLength == strlen(compareStringList[j]))
				{
					// length of strings match, do a strcmp
					if (strcmp(wordBuffer, compareStringList[j]) == 0)
					{
						match = 1;
					}
				}
				if (match == 1)
				{
					switch (compareType)
					{
						case COMPARE_AND:
						{
							log_info("list size: %d", listSize);
							if ((uniqueMatch | j) != uniqueMatch)
							{
								if (listSize > 1)
								{
									printf("[Semi-Match Found '%s']: %s : %d\n", compareStringList[j], logFilePath, fileLineNumber);
								}
								uniqueMatch |= j;
								matchCount++;
							}
							if (matchCount == listSize)
							{
								printf("[Match Found]: %s\n", logFilePath);
							}
						} break;

						case COMPARE_OR:
						{
							printf("[Match Found '%s']: %s : %d\n", compareStringList[j], logFilePath, fileLineNumber); }
						} break;
				}
				else
				{
					debug("No Match -> Log Word: %s - Check Word: %s", wordBuffer, compareStringList[j]);
				}
				match = 0;
			}
			// reset i counter and zero out wordBuffer
			i = 0;
			memset(wordBuffer, 0, MaxLineBuffer);
			if 	(c == '\n')
			{
				fileLineNumber++;
			}
		}
		else
		{
			wordBuffer[i] = c;
			i++;
		}
	}

error:
	if (logFile) 
	{
		fclose(logFile);
	}
	return;
}
