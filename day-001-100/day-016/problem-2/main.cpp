/*
 * Write a C program that displays the following prompts:
 * "Enter the length of the swimming pool:"
 * "Enter the width of the swimming pool:"
 * "Enter the average depth of the swimming pool:"
 * 
 * After each prompt is displayed, your program should use a scanf()
 * function call to accept data from the keyboard for the displayed
 * prompt. After the depth of the swimming pool is entered, your
 * program should calculate and display the volume of the pool. The
 * volumne should be included in an appropriate message and calcualated
 * using the equation volume = length * width * average depth
 */

#include <stdio.h>

struct Pool
{
	float Length;
	float Width;
	float AverageDepth;
	float Volume;
};

inline Pool
CreatePool();

inline void
ComputePoolVolume(Pool *);

inline void
PrettyPrint(Pool *);

int
main(void)
{
	Pool P = CreatePool();
	ComputePoolVolume(&P);
	PrettyPrint(&P);

	return 0;
}


inline Pool
CreatePool()
{
	float l = 0.0f, w = 0.0f, ad = 0.0f;

	printf("Enter the length of the swimming pool:\n");
	scanf("%f", &l);
	printf("Enter the width of the swimming pool:\n");
	scanf("%f", &w);
	printf("Enter the average depth of the swimming pool:\n");
	scanf("%f", &ad);

	return Pool 
	{
		l,
		w,
		ad,
		0.0f,
	};
}

inline void
ComputePoolVolume(Pool *p)
{
	p->Volume = (p->Length * p->Width * p->AverageDepth);
}

inline void
PrettyPrint(Pool *p)
{
	int x = 0;
	printf("Pool Length: %.2f\n", p->Length);
	printf("Pool Width: %.2f\n", p->Width);
	printf("Pool Average Depth: %.2f\n", p->AverageDepth);
	printf("Pool Volume: %.2f\n", p->Volume);
	scanf("%d", &x);
}
