/*
 * Write a program that uses a structure for storing the name of a stock, it's estimated
 * earnings per sharing, and its estimated price-to-earning ratio. Have the program prompt
 * the user to enter these items for five different stocks, each time using the same structure
 * to store the entered data. When the data has been entered for a particular stock, have the
 * program conmpute and display the anticipated stock price based on the entered earnings
 * and price-per-earnings values. For example, if a user entered the data XYZ 1.56 12, the
 * anticipated price for a share of XYZ stock is (1.56) * (12) = $18.72.
 *
 */

#include <stdio.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

typedef struct _stock
{
    char name[4];
    float earningsPerShare;
    float priceToEarnRatio;
    float price;
} Stock;

void
GetStock(Stock *s);

void
PrintStock(Stock *s);

int
main()
{
    Stock stockList[5] = { 0 };

    int i;
    for (i = 0; i < len(stockList); ++i)
    {
        GetStock((stockList + i));
        PrintStock((stockList + i));
    }

    return 0;
}


void
GetStock(Stock *s)
{
    printf("Enter in name (3 chars only): ");
    scanf("%s", s->name);

    printf("Enter in the earings per share: ");
    scanf("%f", &s->earningsPerShare);

    printf("Enter in the price to earn ratio: ");
    scanf("%f", &s->priceToEarnRatio);

    s->price = (s->earningsPerShare * s->priceToEarnRatio);
}

void
PrintStock(Stock *s)
{
    printf("Name: %s\nPrice Per Earnings: %6.2f\nPrice to Earn Ration: %6.2f\nPrice: %6.2f\n",
            s->name, s->earningsPerShare, s->priceToEarnRatio, s->price);
}
