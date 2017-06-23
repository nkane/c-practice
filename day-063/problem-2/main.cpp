/*
 *
 * Here is a version of a problem called "the random walk." It can be extended to two or
 * three dimensions, and used to simulate molecular motion, to determine the effectiveness
 * of reactor shielding, or to calculate a variety of other probabilities.
 *
 * Assume that your very tired and sleepy dog leaves his favorite lamppost on warm 
 * summer evenings and staggers randomly either two steps in the direction toward home
 * or one step in the opposite direction. After taking these steps, the dog again staggers, 
 * randomly two steps toward home or one step backward, and does this again, and again. If
 * the pet reaches a total distance of 10 steps from the lamppost in the direction toward
 * home, you find him and take him home. If the dog arrives back at the lamppost before
 * reaching 10 steps in the direction towards home, he lies down and spend the night at the
 * foot of the lamppost.
 *
 * Write a C program that simulates 500 summer evenings, and calculates and print the percentage
 * of the time your pet sleeps at home for these evenings. (Hint: In a loop determine forward
 * or backward based on the value of a random number.) Accumulate the distance the dog has reached
 * toward your home. If the distance reaches 10, stop the loop and increment the home count. If the
 * distance reaches 0 before it reaches 10, stop the loop but do not increment the home count. Repeat
 * this loop 500 times and find the ratio of (home count)/500.0.
 *
 */

#include <stdio.h>

int
main()
{
	return 0;
}
