#include <lib/algorithms.c>

#define SIZE_1 100
#define SIZE_2 1000
#define SIZE_3 10000
#define SIZE_4 100000

int
main()
{
	int *array = malloc(SIZE_1 * sizeof(int));
	Generate_Array_Random_Data_Int(array, SIZE_1, 0, SIZE_1);
	printf("Sorting array size: %d\n", SIZE_1);
	Selection_Sort(array, SIZE_1);

	array = realloc(array, SIZE_2 * sizeof(int));
	Generate_Array_Random_Data_Int(array, SIZE_2, 0, SIZE_2);
	printf("Sorting array size: %d\n", SIZE_2);
	Selection_Sort(array, SIZE_2);

	array = realloc(array, SIZE_3 * sizeof(int));
	Generate_Array_Random_Data_Int(array, SIZE_3, 0, SIZE_3);
	printf("Sorting array size: %d\n", SIZE_3);
	Selection_Sort(array, SIZE_3);

	array = realloc(array, SIZE_4 * sizeof(int));
	Generate_Array_Random_Data_Int(array, SIZE_4, 0, SIZE_4);
	printf("Sorting array size: %d\n", SIZE_4);
	Selection_Sort(array, SIZE_4);

	free(array);
	return 0;
}
