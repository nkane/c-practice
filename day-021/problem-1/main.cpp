/*
 * Enter enad execute Program 3.19
 * Execute Program 3.19 to determine the amount of each color paint
 * needed for an 8-foot display.
 */

#include <stdio.h>
#include <math.h>

#define PI 3.1416f
#define SQUARE_FEET_PER_QUART 200.0f

#define compute_outer_radius(width) (width / 2.0f)
#define compute_inner_radius(outerRadius) (0.25f * outerRadius)

#define compute_total_area(outerRadius) (PI * (pow(outerRadius, 2)))
#define compute_inner_area(innerRadius) compute_total_area(innerRadius)
#define compute_outer_rim_area(totalArea, innerArea) (totalArea - innerArea)

#define compute_red_paint_amount(innerArea) (innerArea / SQUARE_FEET_PER_QUART)
#define compute_blue_paint_amount(outerRimArea) (outerRimArea / SQUARE_FEET_PER_QUART)

struct Color
{
	float Blue;
	float Red;
};

struct Sign 
{
	float Width;
	float OuterRadius;
	float InnerRadius;
	float TotalArea;
	float InnerArea;
	float OuterRimArea;
	Color PaintColorAmount;
};

inline Sign CreateSign();
inline void ComputeSignInfo(Sign *);
inline void PrettyPrint(Sign *);

int
main(void)
{
	Sign S = CreateSign();
	PrettyPrint(&S);

	return 0;
}

inline Sign CreateSign()
{
	Sign S = {};
	printf("Enter the with of the display (in feet):\n");
	scanf("%f", &S.Width);
	ComputeSignInfo(&S);

	return S;
}

inline void ComputeSignInfo(Sign *s)
{
	s->OuterRadius = compute_outer_radius(s->Width);
	s->InnerRadius = compute_inner_radius(s->OuterRadius);
	s->TotalArea = compute_total_area(s->OuterRadius);
	s->InnerArea = compute_inner_area(s->InnerRadius);
	s->OuterRimArea = compute_outer_rim_area(s->TotalArea, s->InnerArea);
	s->PaintColorAmount.Red = compute_red_paint_amount(s->InnerArea);
	s->PaintColorAmount.Blue = compute_blue_paint_amount(s->OuterRimArea);
}

inline void PrettyPrint(Sign *s)
{
	int x = 0;
	printf("Sign Width: %.2f\n", s->Width);
	printf("Sign Outer Radius: %.2f\n", s->OuterRadius);
	printf("Sign Inner Radius: %.2f\n", s->InnerRadius); 
	printf("Sign Total Area: %.2f\n", s->TotalArea); 
	printf("Sign Inner Area: %.2f\n", s->InnerArea);
	printf("Sign Outer Rim Area: %.2f\n", s->OuterRimArea);
	printf("Sign Red Paint Amount: %.2f\n", s->PaintColorAmount.Red);
	printf("Sign Blue Paint Amount: %.2f\n", s->PaintColorAmount.Blue);
	printf("Enter any number to continue ...\n");
	scanf("%d", &x);
}
