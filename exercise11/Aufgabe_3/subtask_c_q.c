#include <math.h>
#include <time.h>

float compare_complex(const void* a, const void* b);
void PrintComplex(void* array, int t_size, int a_size);

double subtask_c_q(void* array, int t_size, int a_size)
{
	// struct mit zufaelligen Werten fuellen
	for (int i = 0; i < a_size; i++)
	{
		*(float*)((char*)array + (i * t_size)) = ((float)(rand() % 1000)) / 1000;
	}

	// Ausgabe unsortierte Komplexe Zahlen
	printf("unsortierte Komplexe Zahlen (qsort):\n\n");
	PrintComplex(array, t_size, a_size);

	// Zeitmarke: tc_q	(Start)
	clock_t tc_q;
	tc_q = clock();

	// Bubblesort Sortierung
	// void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
	qsort(array, a_size / 2, t_size * 2, compare_complex);

	// Zeitmarke: t3_q	(Stop)
	tc_q = clock() - tc_q;


	return ((double)tc_q) / CLOCKS_PER_SEC; // in seconds 

}