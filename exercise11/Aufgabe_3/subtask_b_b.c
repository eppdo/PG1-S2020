#include <time.h>

int compare_3Ddouble(const void* a, const void* b);

void PrintMagVector(void* a, int t_size, int a_size);

double subtask_b_b(void* array, int t_size, int a_size)
{
	// Array mit zufaelligen Werten zwischen 0 und 100 fuellen
	for (int i = 0; i < a_size; i++)
	{
		*(double*)((char*)array + (i * t_size)) = (double)(rand() % 100);
	}

	// Ausgabe: unsortierte Liste (3D Vectoren)
	printf("unsortierte Liste (3D-Vectoren - bsort):\n\n");
	Print3DArray(array, t_size, a_size);
	PrintMagVector(array, t_size, a_size);

	// Zeitmarke: tb_b	(Start)
	clock_t tb_b;
	tb_b = clock();

	// Bubblesort Sortierung
	bsort(array, 3 * t_size, a_size  / 3, compare_3Ddouble);

	// Zeitmarke: tb_b	(Stop)
	tb_b = clock() - tb_b;
	return ((double)tb_b) / CLOCKS_PER_SEC; // in seconds 

}