#include <math.h>
#include <time.h>

float compare_complex(const void* a, const void* b);
void PrintComplex(void* array, int t_size, int a_size);

double subtask_c_b(void* array, int t_size, int a_size)
{
	// struct mit zufaelligen Werten fuellen
	for (int i = 0; i < a_size; i++)
	{
		*(float*)((char*)array + (i * t_size)) = ((float)(rand() % 1000)) / 1000;
	}

	// Ausgabe unsortierte Komplexe Zahlen
	printf("unsortierte Komplexe Zahlen (bsort):\n\n");
	PrintComplex(array, t_size, a_size);

	// Zeitmarke: tc_b	(Start)
	clock_t tc_b;
	tc_b = clock();

	// Bubblesort Sortierung
	bsort(array, t_size * 2, a_size, compare_complex);

	// Zeitmarke: t3_b	(Stop)
	tc_b = clock() - tc_b;

	return ((double)tc_b) / CLOCKS_PER_SEC; // in seconds 
}