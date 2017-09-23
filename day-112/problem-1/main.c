/*
 * Write individual declaration and open statements to link the following external data
 * filenames to their corresponding internal names. Note that all files are binary, not 
 * text.
 *
 * External name		Internal Name		Mode
 * -------------		-------------		----
 * coba.mem			memo			binary and output
 * coupons.bnd			coups			binary and append
 * prices.dat			priFile			binary and input
 *
 */

#include <stdio.h>

void
OpenFile(char *file, char *options, FILE *outFile);

int
main()
{
	FILE *memoFile = NULL;
	FILE *couponsFile = NULL;
	FILE *pricesFile = NULL;

	OpenFile("./data/coba.mem", "rb", memoFile);
	OpenFile("./data/coupons.bnd", "ab", couponsFile);
	OpenFile("./data/prices.dat", "wb", pricesFile);

	if (memoFile)
	{
		fclose(memoFile);
	}

	if (couponsFile)
	{
		fclose(couponsFile);
	}

	if (pricesFile)
	{
		fclose(pricesFile);
	}

	return 0;
}

void
OpenFile(char *file, char *options, FILE *outFile)
{
	if (outFile = fopen(file, options))
	{
		printf("SUCCESS - Properly opened %s\n", file);
	}
	else
	{
		printf("ERROR - Failed to open file %s\n", file);
	}
}

