#include <time.h>

int compare_char(const void* a, const void* b);

double subtask_a_q(void* array, int t_size, int a_size)
{
	int offset = 'a' - 'A';

	// Array mit zufaelliger Folge aus Gross- und Kleinbuchstaben fuellen
	for (int i = 0; i < a_size; i++)
	{
		//	(rand() % 25) + 65)	-> Kleinbuchstaben
		//	(((rand() % 2) == 0) * offset	->	Wenn ((rand() % 2) == 0) -> True	-> Grossbuchstabe 
		*(char*)((char*)array + (i * t_size)) = ((rand() % 25) + 65) + (((rand() % 2) == 0) * offset);
	}

	// Ausgabe: unsortierte Liste (Buchstaben)
	printf("\nunsortierte Liste (Character - qsort):\n");
	Print1DArray(array, t_size, a_size);

	// Quicksort
		// Zeitmarke: ta_q	(Start)
		clock_t ta_q;
		ta_q = clock();

	// Quicksort Sortierung
	qsort(array, a_size, t_size, compare_char);

		// Zeitmarke: ta_q	(Stop)
		ta_q = clock() - ta_q;

		return ((double)ta_q) / CLOCKS_PER_SEC; // in seconds 
}