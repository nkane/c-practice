/*
 * The quadrant in which a line drawn from the origin resides is determined by the
 * angle that the line makes with the positive X axis as follows:
 *
 * | Angle from the Positive X | Quadrant |
 * |---------------------------|----------|
 * | Between 0 - 90 degrees    | I	  |
 * | Between 90 - 180 degrees  | II	  | 
 * | Between 180 - 270 degrees | III	  |
 * | Between 270 - 360 degrees | IV	  |
 * 
 * Using this information, write a C program that accepts the angle of the line as user
 * input and determines and displays the quadrant appropriate to the input data. (Note:
 * If the angle is exactly 0, 90, 180, or 270 degrees, the corresponding lines does not
 * reside in any quadrant but lies on any axis.
 * 
 * Create a message that identifies an angle of 0 degrees as the positive X-axis, and 
 * angle of 90 degrees as the positive Y-Axis, an angle of 180 degrees as the negative
 * X-axis, and an angle of 270 degrees as the negative Y-axis.
 */

#include <stdio.h>

struct Quadrant
{
	int X_Angle;
	int QuadrantNumber;
	bool OnAxis;
};

inline Quadrant
CreateQuadrant();

inline int
DetermineQuadrant(Quadrant *);

inline void
PrettyPrint(Quadrant *);

int
main()
{
	Quadrant Q = CreateQuadrant();

	PrettyPrint(&Q);

	return 0;
}

inline Quadrant
CreateQuadrant()
{
	Quadrant Q = {};
	Q.OnAxis = false;

	printf("Enter in the X angle of the line:\n");
	scanf("%d", &Q.X_Angle);

	Q.QuadrantNumber = DetermineQuadrant(&Q);
	
	return Q;
}

inline int
DetermineQuadrant(Quadrant *q)
{
	int result = 0;
	// first, check to see if is on axis
	if (q->X_Angle == 0 || 
	    q->X_Angle == 90 || 
	    q->X_Angle == 180 || 
	    q->X_Angle == 270)
	{
		q->OnAxis = true;
	}

	// second, if not on axis
	if (!q->OnAxis) 
	{
		if (q->X_Angle < 90)
		{
			result = 1;
		}
		else if (q->X_Angle < 180)
		{
			result = 2;
		}
		else if (q->X_Angle < 270)
		{
			result = 3;
		}
		else
		{
			result = 4;
		}
	}
	else 
	{
		if (q->X_Angle == 0)
		{
			printf("On Positive X-Axis!\n");
		}
		else if (q->X_Angle == 90)
		{
			printf("On Positive Y-Axis!\n");
		}
		else if (q->X_Angle == 180)
		{
			printf("On Negtive X-Axis!\n");
		}
		else 
		{
			printf("On Negative Y-Axis!\n");
		}
	}

	return result;
}

inline void
PrettyPrint(Quadrant *q)
{
	printf("X Angle: %d\n", q->X_Angle);
	if (!q->OnAxis)
	{
		printf("Quadrant: %d\n", q->QuadrantNumber);
	}
}

