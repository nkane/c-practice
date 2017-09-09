/*
 * Write a C program that displays the following prompts:
 * "Enter the length of the room:"
 * "Enter the width of the room:"
 * 
 * After each prompt is displayed, your program should use a scanf()
 * function call to accept data from the keyboard for the displayed
 * prompt. After the width of the room is entered, your program should
 * calculate and display the area of the room. The area displayed
 * should be included in an appropriate message and calculated
 * using the expression: area = length * width
 */

#include <stdio.h>

struct Room
{
	float Length;
	float Width;
	float Area;
};

inline Room
CreateRoom();

inline void
ComputeRoomArea(Room *);

inline void
PrettyPrint(Room *);

int
main(void)
{
	Room R = CreateRoom();
	ComputeRoomArea(&R);
	PrettyPrint(&R);

	return 0;
}

inline Room
CreateRoom()
{
	float l, w;
	printf("Enter the length of the room:\n");
	scanf("%f", &l);
	printf("Enter the width of the room:\n");
	scanf("%f", &w);
	return Room
	{
		l,
		w,
		0.0f,
	};
}

inline void
ComputeRoomArea(Room *r)
{
	r->Area = (r->Length * r->Width);
}

inline void
PrettyPrint(Room *r)
{
	printf("Room Length: %.2f\n", r->Length);
	printf("Room Width: %.2f\n", r->Width);
	printf("Room Area: %.2f", r->Area);
}
