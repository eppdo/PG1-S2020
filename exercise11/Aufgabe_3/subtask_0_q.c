#include <time.h>

int compare_int(const void* a, const void* b);

double subtask_0_q(void* array, int t_size, int a_size)
{
	// Zusatz (Integer Array)
	// Array mit zufaelligen Werten zwischen 0 und 100 fuellen
	for (int i = 0; i < a_size; i++)
	{
		*(int*)((char*)array + (i * t_size)) = rand() % 100;
	}

	// Ausgabe des Arrays (unsortiert - qsort)
	printf("\nunsortierte Liste (Integer - qsort):\n");
	Print1DArray(array, t_size, a_size);


	// Quicksort
		// Zeitmarke: t0_q	(Start)
		clock_t t0_q;
		t0_q = clock();

		// Quicksort Sortierung
		qsort(array, a_size, t_size, compare_int);

		// Zeitmarke: t0_q	(Stop)
		t0_q = clock() - t0_q;


	return ((double)t0_q) / CLOCKS_PER_SEC; // in seconds

}