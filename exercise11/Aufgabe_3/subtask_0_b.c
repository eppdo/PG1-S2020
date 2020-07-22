#include <time.h>
int compare_int(const void* a, const void* b);
void Print1DArray(void* array, int t_size, int a_size);

double subtask_0_b(void* array, int t_size, int a_size)
{
	// Zusatz (Integer Array)
		// Array mit zufaelligen Werten zwischen 0 und 100 fuellen
		for (int i = 0; i < a_size; i++)
		{
			*(int*)((char*)array + (i * t_size)) = rand() % 100;
		}

	// Ausgabe des Arrays (unsortiert)
	printf("\nunsortierte Liste (Integer bsort):\n");
	Print1DArray(array, t_size, a_size);


// Bubblesort
	// Zeitmarke: t0_b	(Start)
	clock_t t0_b;
	t0_b = clock();


	// Bubblesort Sortierung
	bsort(array, t_size, a_size, compare_int);

	// Zeitmarke: t0_b	(Stop)
	t0_b = clock() - t0_b;


	return ((double)t0_b) / CLOCKS_PER_SEC; // in seconds 

}