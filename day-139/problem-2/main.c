/*
 * Modify the problem written previously, so that the function returns the address
 * of the character string containing the propery day to be displayed
 *
 */

#include <stdio.h>

int
GetDay(char **days, int x);

int
main()
{
    int input = 0;
    char *days[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", };

    printf("Enter in day number: ");
    scanf("%d", &input);

    int address = GetDay(days, input);

    printf("%s", (char *)address);

    return 0;
}

int
GetDay(char **days, int x)
{
    int result = (int)&(**(days + (x - 1)));
    return result;
}
