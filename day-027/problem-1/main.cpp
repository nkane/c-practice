/*
 * Each disk drive in a shipment of devices is stamped with a code
 * from 1 through 4, which indicates a drive manufacturer as follows:
 * 
 * Code		|	Disk Drive Manufacturer
 * 1			3M Corporation
 * 2			Maxell Corporation
 * 3			Sony Corporation
 * 4			Verbatim Corporation
 * 
 * Write a C program that accepts the code number as an input and,
 * based on the value entered, displays the correct disk drive manufacturer.
 */

#include <stdio.h>

struct DiskDrive
{
	int code;
	char *manufacturer;
};

inline DiskDrive
CreateDiskDrive();

inline char*
DetermineManufacturer(DiskDrive *);

inline void
PrettyPrint(DiskDrive *);

int
main()
{
	DiskDrive D = CreateDiskDrive();
	PrettyPrint(&D);

	return 0;
}

inline DiskDrive
CreateDiskDrive()
{
	DiskDrive D = {};
	printf("Enter in the manufacturer code:\n");
	scanf("%d", &D.code);
	D.manufacturer = DetermineManufacturer(&D);

	return D;
}

inline char*
DetermineManufacturer(DiskDrive *d)
{
	char *result;

	switch (d->code)
	{
		case 1:
		{
			result = "3M Corporation\0";
		} break;

		case 2:
		{
			result = "Maxell Corporation\0";
		} break;

		case 3:
		{
			result = "Sony Corporation\0";
		} break;

		case 4:
		{
			result = "Verbatim Corporation\0";
		} break;

		default:
		{
			result = "BAD VALUE!\0";
		} break;
	}

	return result;
}

inline void
PrettyPrint(DiskDrive *d)
{
	printf("The entered code is: %d\n", d->code);
	printf("The manufacturer is: %s\n", d->manufacturer);
}
