/*
 * Enter and execute program 13.4
 *
 */

#include <stdlib.h>
#include <stdio.h>

int
main()
{
    int numgrades = 0;
    int *grades = NULL;
    int i = 0;

    printf("\nEnter the number of grades to be processed: ");
    scanf("%d", &numgrades);

    grades = (int *) malloc(numgrades * sizeof(int));

    if (grades == (int *) NULL)
    {
        printf("\nFailed to allocate grades array\n");
    }

    for (i = 0; i < numgrades; ++i)
    {
        printf("  Enter a grade: ");
        scanf("%d", &grades[i]);
    }

    printf("\nAn array was created for %d integers", numgrades);
    printf("\nThe values stored in the array are:\n");

    for (i = 0; i < numgrades; ++i)
    {
        printf(" %d\n", grades[i]);
    }

    free(grades);

    return 0;
}
