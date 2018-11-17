/*
 * Write, compile, and execute a C program that creates a binary file named
 * points and writes the following numbers to the file:
 *
 * 	6.3    8.2    18.25    24.32
 *	4.0    4.0    10.0     -5.0
 *     -2.0    5.0     4.0      5.0
 *
 * Using the data in the points file created - write, compile, and run a C
 * program that reads four numbers using a for loop and interprets the first
 * and second numbers in each record as the coordinates of one point and the
 * third and fourth numbers as the coordinates of a second point. Have the
 * program compute and display the slope and midpoint of each pair of entered
 * points.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 12

typedef struct _vector2
{
	float X;
	float Y;
} Vector2;

FILE *
CreateDataFile(const char *fileName);

void
WriteDataToFile(FILE *file);

float
SlopeV2(Vector2 p1, Vector2 p2);

void
MidpointV2(Vector2 p1, Vector2 p2, Vector2 *outMidpoint);

int
main()
{
	FILE *file = CreateDataFile("points.bin");
	if (file)
	{
		Vector2 v2_pos1;
		Vector2 v2_pos2;
		Vector2 midpoint;
		int i;
		for (i = 0; i < 4; ++i)
		{
			fread(&v2_pos1.X, sizeof(float), 1, file);
			fread(&v2_pos1.Y, sizeof(float), 1, file);
			fread(&v2_pos2.X, sizeof(float), 1, file);
			fread(&v2_pos2.Y, sizeof(float), 1, file);
			printf("Slope: %6.2f\n", SlopeV2(v2_pos1, v2_pos2));
			MidpointV2(v2_pos1, v2_pos2, &midpoint);
			printf("Midpoint: ( %6.2f, %6.2f )\n", midpoint.X, midpoint.Y);
		}
		fclose(file);
	}
	system("pauses");

	return 0;
}

FILE *
CreateDataFile(const char *fileName)
{
	FILE *file = fopen(fileName, "rb");
	char c = ' ';
	if (file)
	{
		printf("Overwrite file? (y / n): ");
		scanf("%c", &c);
		if (tolower(c) == 'y')
		{
			fclose(file);
		}
	}
	if (file == NULL || tolower(c) == 'y')
	{
		file = fopen(fileName, "wb");
		WriteDataToFile(file);
		fclose(file);
		file = fopen(fileName, "rb");
	}
	return file;
}

void
WriteDataToFile(FILE *file)
{
	float rawData[SIZE] = {
				    6.3f, 8.2f, 18.25f, 24.32f,
				    4.0f, 4.0f, 10.0f,  -5.0f,
				   -2.0,  5.0,   4.0,    5.0f,
		              };
	fwrite(rawData, sizeof(float), 12, file);
}

float
SlopeV2(Vector2 p1, Vector2 p2)
{
	float slope = (p2.Y - p1.Y) / (p2.X - p1.X);
	return slope;
}

void
MidpointV2(Vector2 p1, Vector2 p2, Vector2 *outMidpoint)
{
	outMidpoint->X = (p1.X + p2.X) / 2.0f;
	outMidpoint->Y = (p1.Y + p2.Y) / 2.0f;
}
