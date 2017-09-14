/*
 * The Fog Index is an index that can be used to determine the approximate reading gread
 * level of an article. It is determined by measuring both sentence length and the faction
 * of words with three or more syllables, without taking into account either the article's
 * conceptual difficulty or its clarity. The index is determined using the following steps:
 *
 * 	Step 1: Select a sample of at least 100 words
 * 	Step 2: Count the number of sentences. Any caluse that is separated by a semicolon
 * 		or colon should be counted as a separated sentence.
 * 	Step 3: Count the number of words containing three or more syllables; but do not
 * 		include words that reach three or more syllables because of either "es" or
 * 		"ed" endings, or because they are compounds of simple words, such as everything
 * 		or seventeen.
 * 	step 4: Calculate the Fog Index using this formula
 *
 * 	FogIndex = 0.4 ((number of words / number of sentences) + 100 * (number of big words / number of words))
 *
 * For this exercise obtain sample of at least 10 sentences from a variety of sources, such as
 * children's books, high school textbooks, college textbooks, or a number of different newspaper.
 * For each of these samples, manually determine the number of words and big words contained in
 * the sample. Then write a C function that: accepts the number of words, accepts the number of
 * sentences, accept the number of big words, calculates a Fog Index, and returns the calculated
 * value. Verify the value returned by your function against your hand calculations
 *
 */

#include <stdio.h>

int
main()
{
	return 0;
}
