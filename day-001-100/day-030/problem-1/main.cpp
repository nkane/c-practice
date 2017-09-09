/*
 * A quadratic equation is an equation that either has the form ax^2 + bx + c = 0
 * or an equation that can be algebraically manipulated into this form. In this
 * equation, x is the unknown variable, and a, b, and c are known constants. Although
 * the constants b and c can be any numbers, including 0, the value of the constants
 * a cannot be 0 (if a is 0, the equation would become a linear equation in x). Examples
 * of quadratic equations are:
 *
 * 5x^2 + 6x + 2 = 0
 * x^2 + 7x + 20 = 0
 * 34^2 + 16 = 0
 * 
 * In the first equation a = 5, b = 6, and c = 2; in the second equation a = 1, b = -7,
 * and c = 20; and in the third equation a = 34, b = 0, and c = 16.
 * 
 * The real roots of a quadratic equation can be calculated using the quadratic forulma
 * as follows:
 * 
 * rootOne = -b + sqrt(b^2 - 4ac) / 2a
 * rootTwo = -b - sqrt(b^2 - 4ac) / 2a
 * 
 * Using these equations, write a C program to solve for the roots of a quadratic equation.
 */

#include <stdio.h>
#include <math.h>

struct QuadEquation
{
	float A;
	float B;
	float C;
	float RootOne;
	float IRootOne;
	float RootTwo;
	float IRootTwo;
};

inline QuadEquation
CreateQuadEquation(float, float, float);

inline float
ComputeFirstRootQuadEquation(QuadEquation *);

inline float
ComputeSecondRootQuadEquation(QuadEquation *);

inline void
PrettyPrint(QuadEquation *);

int
main()
{
	QuadEquation E1 = CreateQuadEquation(5.0f, 6.0f, 2.0f);
	QuadEquation E2 = CreateQuadEquation(1.0f, -7.0f, 20.0f);
	QuadEquation E3 = CreateQuadEquation(34.0f, 0.0f, 16.0f);

	PrettyPrint(&E1);
	PrettyPrint(&E2);
	PrettyPrint(&E3);

	return 0;
}

inline QuadEquation
CreateQuadEquation(float a, float b, float c)
{
	QuadEquation Q =
	{
		a,
		b,
		c,
		0.0f,
		0.0f,
		0.0f,
		0.0f,
	};

	Q.RootOne = ComputeFirstRootQuadEquation(&Q);
	Q.RootTwo = ComputeSecondRootQuadEquation(&Q);

	return Q;
}

inline float
ComputeFirstRootQuadEquation(QuadEquation *q)
{
	float result = 0.0f;

	result = pow(q->B, 2);
	result = (result - (4.0f * q->A * q->C));
	if (result > 0.0f)
	{
		result = sqrt(result);
	}
	else
	{
		// can't take a negative numbers square root!
		q->IRootOne = sqrt((result * -1.0f));
		q->IRootOne = (q->IRootOne / (2.0f * q->A));
		result = 0.0f;
	}

	result = ((-1.0f * q->B) + result);
	result = (result / (2.0f * q->A));
	
	return result;
}

inline float
ComputeSecondRootQuadEquation(QuadEquation *q)
{
	float result = 0.0f;

	result = pow(q->B, 2);
	result = (result - (4.0f * q->A * q->C));

	if (result > 0.0f)
	{
		result = sqrt(result);
	}
	else
	{
		// can't take a negative numbers square root!
		q->IRootTwo = sqrt((result * -1.0f));
		q->IRootTwo = (q->IRootTwo / (2.0f * q->A));
		result = 0.0f;
	}

	result = ((-1.0f * q->B) - result);
	result = (result / (2.0f * q->A));

	return result;
}


inline void
PrettyPrint(QuadEquation *q)
{
	if (q->IRootOne > 0.0f) 
	{
		printf("Root One: %.2f + %.2fi\n", q->RootOne, q->IRootOne);
	}
	else
	{
		printf("Root One: %.2f\n", q->RootOne);
	}

	if (q->IRootTwo > 0.0f)
	{
		printf("Root Two: %.2f - %.2fi\n", q->RootTwo, q->IRootTwo);
	}
	else
	{
		printf("Root One: %.2f\n", q->RootTwo);
	}
}
