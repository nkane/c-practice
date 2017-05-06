/*
 * A well-regarded manufacturer of widgets has been losing 4 percent of its sales each year.
 * The annual profit for the firm is 10 percent of sales. This year the firm has had $10 million
 * in sales and a profit of $1 million. Determine the expected sales and profit for the next 10 years.
 * Your program should complete and produce a table with this information.
 *
 */

#include <stdio.h>

#define global_variable static

global_variable const float Decline_Rate = 0.04f;
global_variable const float Profit_Rate = 0.10f;
global_variable const float Initial_Value = 10000000.0f;

global_variable const int Projection_Years = 10;

struct Manufacturer
{
	float Sales;
	float Profit;
	float ProfitRate;
	float DeclineRate;
};

inline float
ComputeProjectedSalesM(Manufacturer *);

inline float
ComputeProjectedProfitM(Manufacturer *);

inline void
PrettyPrintM(Manufacturer *, int);

int
main()
{
	Manufacturer M = 
	{
		Initial_Value,
		0.0f,
		Profit_Rate,
		Decline_Rate,
	};

	M.Profit = ComputeProjectedProfitM(&M);


	for (int i = 0; i < Projection_Years; ++i)
	{
		PrettyPrintM(&M, (i + 1));
		M.Sales = ComputeProjectedSalesM(&M);
		M.Profit = ComputeProjectedProfitM(&M);
	}

	return 0;
}

inline float
ComputeProjectedSalesM(Manufacturer *m)
{
	float result = ((m->Sales) - (m->Sales * m->DeclineRate));
	return result;
}

inline float
ComputeProjectedProfitM(Manufacturer *m)
{
	float result = (m->Sales * m->ProfitRate);
	return result;
}

inline void
PrettyPrintM(Manufacturer *m, int year)
{
	printf("Year: %d - Projected Sales: %.2f - Projected Profits: %.2f\n", year, m->Sales, m->Profit);
}

