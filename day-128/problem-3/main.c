/*
 * Write, compile, and run a C program that write the numbers 92.65,
 * 88.72, 77.46, and 82.93 as double-percision values to a binary file
 * named results.bin. After writing the data to the file, the program
 * should read the data file, detemine the average of the four numbers
 * read, and display the average. Verifty the output produced by the 
 * program by manually calculating the average of the four input numbers.
 *
 */

#include <stdio.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

int
main()
{
	FILE *file;
	double values[4] = { 92.65, 88.72, 77.46, 82.93, };
	char fileName[9] = "temp.dat";

	file = fopen(fileName, "wb");
	if (file)
	{
		fwrite(&values, sizeof(values[0]), 4, file);
		fclose(file);
		file = fopen(fileName, "rb");
		double average = 0.0;
		if (file) 
		{
			double currentValue = 0.0;
			int i;
			for (i = 0; i < len(values); ++i)
			{
				fread(&currentValue, sizeof(double), 1, file);
				printf("Index %d - value: %lf\n", i, currentValue);
				average += currentValue;
				currentValue = 0.0;
			}
			fclose(file);
		}
		printf("Average: %lf\n", average / len(values));
	}

	return 0;
}
