/*
 * 	logfind.h
 */

#ifndef _logfind_h
#define _logfind_h

#define global_variable		static
#define local_persist		static
#define internal			static

typedef enum _compareType
{
	COMPARE_NONE 	= 0x00,
	COMPARE_AND  	= 0x01,
	COMPARE_OR   	= 0x02,
} CompareType; 

char **
Read_Log_File_List();

void
Check_Log_For_Match(char *logFilePath, int argc, ...);

#endif
