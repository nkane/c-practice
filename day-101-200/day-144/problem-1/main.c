/*
 * Declare a single structure type suitable for a car record consisting of an integer car
 * indentification number, an integer value for the miles driven by the car, and an integer
 * value for the number of gallons used by each car.
 *
 * Using the structure type declared for the program, write a C program that interactively
 * accepts the following data into an array of five structures:
 *
 * Car Number           Miles Driven            Gallons Used
 * ---------            ------------            ------------
 *  25                      1,450                   62
 *  36                      3,240                   136
 *  44                      1,792                   76
 *  52                      2,360                   105
 *  68                      2,114                   67
 *
 * Once the data has been entered, the program should create a report listing each car
 * number and the miles per gallon achieved by the car. At the end of the report, include
 * the average miles per gallon achieved by the complete fleet of cars.
 *
 */

#include <stdio.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

typedef struct _carInfo
{
    int id;
    int miles;
    int gallons;
    float mpg;
} CarInfo;

CarInfo
GetCarInfo();

void
PrintCarInfo(CarInfo *carInfo);

int
main()
{
    CarInfo list[5] = { 0 };
    int i;
    float fleetMiles = 0.0f;
    float fleetGallons = 0.0f;

    for (i = 0; i < len(list); ++i)
    {
        *(list + i) = GetCarInfo();
        fleetMiles += (list + i)->miles;
        fleetGallons += (list + i)->gallons;
    }

    for (i = 0; i < len(list); ++i)
    {
        PrintCarInfo((list + i));
    }

    printf("=====================\nFleet average MPG: %6.2f\n", (fleetMiles / fleetGallons));

    return 0;
}

CarInfo
GetCarInfo()
{
    CarInfo result = { 0 };

    do {
        printf("id number: ");
        scanf("%d", &result.id);
    } while (result.id < 0);
    
    do {
        printf("miles driven: ");
        scanf("%d", &result.miles);
    } while (result.miles < 0);

    do {
        printf("gallons used: ");
        scanf("%d", &result.gallons);
    } while (result.gallons < 0);

    result.mpg = ((float)result.miles / (float)result.gallons);
    printf("\n");

    return result;
}

void
PrintCarInfo(CarInfo *carInfo)
{
    printf("=======================================\nid: %d\nmiles: %d\ngallons:%d\nmpg:%6.2f\n",
            carInfo->id, carInfo->miles, carInfo->gallons, carInfo->mpg);
}
