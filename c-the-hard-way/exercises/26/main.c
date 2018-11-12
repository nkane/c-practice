#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "dbg.h"
#include "logfind.h"

#define global_variable		static
#define local_persist		static
#define internal			static

int8_t
Check_Parameters(int parameterAmount, char *parameterList[])
{
	int8_t result = COMPARE_AND;

	if (parameterAmount < 2)
	{
		printf("[USAGE]: ./logfind test one");
		result = COMPARE_NONE;
	}
	else if (parameterList[1][0] == '-' && parameterList[1][1] == 'o')
	{
		log_info("Or flag processed - changing comparison to or logic.");
		result = COMPARE_OR;
	}

	return result;
}

inline void
Clean_Up_File_List(char **fileList)
{
	// TODO
}

int
main(int argc, char *argv[])
{
	char ** logFileList = Read_Log_File_List();
	check_mem(logFileList);
	log_info("Successfully loaded log file list.");

	uint8_t compareLogic = Check_Parameters(argc, argv);
	check(compareLogic > 0, "Invalid Parameters passed in.");
	log_info("Compare Logic Set to: 0x%x", compareLogic);

	// TODO(nick): check each log file 
	int i = 0;
	while (logFileList[i] && (strlen(logFileList[i]) > 0))
	{
		debug("Checking file: %s", logFileList[i]);
		Check_Log_For_Match(logFileList[i], compareLogic, 1, (argc - 1), argv);
		i++;
	}

	return 0;
error:
	// TODO(nick): finish clean up
	return 1;
}
