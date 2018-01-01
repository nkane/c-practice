/*
 * Determine the display produced by the following section of code:
 *
 *  union
 *  {
 *      char ch;
 *      double btype;
 *  } alt;
 *
 *  alt.ch = 'y';
 *  printf("%f", alt.btype);
 *
 *  Use the above code in a working program to verify your answer.
 *
 */

#include <stdio.h>

typedef union _alt
{
    char ch;
    double btype;
} Alt;

typedef struct _v3i
{
    union
    {
        struct
        {
            int x;
            int y;
            int z;
        };
        struct 
        {
            int r;
            int g;
            int b;
        };
    };
} Vector3i;

int
main()
{
    Alt alt = { 0 };

    alt.ch = 'y';

    printf("%f\n", alt.btype);

    int x = 121;

    printf("%f\n", *((double *)&x));

    Vector3i v3i =  (Vector3i)
    {
        .x = 1,
        .y = 2,
        .z = 3
    };

    printf("R: %d - G: %d - B: %d\n", v3i.r, v3i.b, v3i.g);

    return 0;
}
