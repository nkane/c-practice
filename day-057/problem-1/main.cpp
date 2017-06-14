/*
 * The determinant of the 2-by-2 matrix:
 *
 * | a[1][1]	a[1][2] |
 * | a[2][1] 	a[2][2] |
 *
 * a[1][1] * a[2][2] - a[2][1] * a[1][2]
 *
 * Similarly, the determinant of a 3-by-3 matrix is:
 *
 * | a[1][1] 	a[1][2]	  a[1][3] |
 * | a[2][1]	a[2][2]	  a[2][3] |
 * | a[3][1]	a[3][2]	  a[3][3] |
 *
 * { a[1][1] * ((a[2][2] * a[3][3]) - (a[3][2] * a[2][3])) } - { a[2][1] * ((a[1][2] * a[3][3]) - (a[3][2] * a[1][3])) } + { a[3][1] ((a[1][2] * a[2][3]) - (a[2][2] * a[1][3])) }
 *
 * Using this information write and test two functions named determinant2() and determinant3(). The determinant2 function should accept the four coeffiects of a 2-by-2 matrix
 * and return its determinant. The determinant3 function should accept the nine coefficients of a 3-by-3 matrix and return its determinant by calling determinant2 to calculate
 * the required 2-by-2 determinants.
 *
 */

#include <stdio.h>

#define global_variable static

global_variable float Matrix2f[2][2] = 
{
	{ 3.0f , 8.0f },
	{ 4.0f , 6.0f },
};

global_variable float Matrix3f[3][3] = 
{
	{ 6.0f, 1.0f, 1.0f },
	{ 4.0f, -2.0f, 5.0f },
	{ 2.0f, 8.0f, 7.0f },
};

inline float
DeterminantMatrix2f(float[2][2]);

inline float
DeterminantMatrix3f(float[3][3]);

int
main()
{
	printf("Determinant of 2x2 Matrix: %.2f\n", DeterminantMatrix2f(Matrix2f));
	printf("Determinant of 3x3 Matrix: %.2f\n", DeterminantMatrix3f(Matrix3f));
	return 0;
}

inline float
DeterminantMatrix2f(float matrix2f[2][2])
{
	float result = 0.0f;
	result = ((matrix2f[0][0] * matrix2f[1][1]) - (matrix2f[1][0] * matrix2f[0][1]));
	return result;
}

inline float
DeterminantMatrix3f(float matrix3f[3][3])
{
	float result = 0.0f;

	float matrix2f_1[2][2] =
	{
		{ matrix3f[1][1], matrix3f[1][2] },
		{ matrix3f[2][1], matrix3f[2][2] },
	};

	float matrix2f_2[2][2] =
	{
		{ matrix3f[0][1], matrix3f[0][2] },
		{ matrix3f[2][1], matrix3f[2][2] },
	};

	float matrix2f_3[2][2] = 
	{
		{ matrix3f[0][1], matrix3f[0][2] },
		{ matrix3f[1][1], matrix3f[1][2] },
	};

	result =  (matrix3f[0][0] * DeterminantMatrix2f(matrix2f_1));
	result -= (matrix3f[1][0] * DeterminantMatrix2f(matrix2f_2));
	result += (matrix3f[2][0] * DeterminantMatrix2f(matrix2f_3));

	return result;
}
