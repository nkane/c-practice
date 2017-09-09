/*
 * A directly connected telephone network is one in which all
 * telephones in the network are directly connected and do not
 * require a central switching station to establish calls between
 * two telephones. For example, financial institutions on Wall
 * Street use such a network to maintain direct and continuously
 * open phone lines between firms.
 *
 * The number of direct lines needed to maintain a directly
 * connected network for n telephones, is given in the formula:
 *
 * lines = n * (n - 1) / 2
 * 
 * For example, a directly connecting four telephones requires six
 * individual lines. Adding a fifth telephone to this network would
 * require an additional four lines for a total of 10 lines.
 * 
 * Using the given formula, write a C program that determines the
 * number of direct lines required for 100 telephones, and the
 * additional lines required if 10 new telephones were added to the
 * network.
 * 
 * Next make a program that calculates and dispalys the number of
 * connections of direct lines required for 1000 telephones.
 */

#include <stdio.h>

struct telephone_lines
{
	int line_numbers;
	int total_connections;
};

inline void Init_Telephones(telephone_lines *);

inline void PrettyPrint(telephone_lines *);

int main(void)
{
	telephone_lines T0 = { 4, 0 };
	Init_Telephones(&T0);
	PrettyPrint(&T0);

	T0.line_numbers = 5;
	Init_Telephones(&T0);
	PrettyPrint(&T0);
	
	telephone_lines T1 = { 100, 0 };
	Init_Telephones(&T1);
	PrettyPrint(&T1);

	telephone_lines T2 = { 1000, 0 };
	Init_Telephones(&T2);
	PrettyPrint(&T2);

	return 0;
}

inline void Init_Telephones(telephone_lines * lines)
{
	lines->total_connections =  ((lines->line_numbers * (lines->line_numbers - 1)) / 2);
}

inline void PrettyPrint(telephone_lines * lines)
{
	printf("Total Phones: %d\n", lines->line_numbers);
	printf("Total Connections: %d\n", lines->total_connections);
}
