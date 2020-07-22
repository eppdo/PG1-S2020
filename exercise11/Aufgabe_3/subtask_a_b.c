#include <time.h>

int compare_char(const void* a, const void* b);

double subtask_a_b(void* array, int t_size, int a_size)
{
	int offset = 'a' - 'A';

	// Array mit zufaelliger Folge aus Gross- und Kleinbuchsten fuellen
	for (int i = 0; i < a_size; i++)
	{
		//	(rand() % 25) + 65)	-> Kleinbuchstaben
		//	(((rand() % 2) == 0) * offset	->	Wenn ((rand() % 2) == 0) -> True	-> Grossbuchstabe 
		*(char*)((char*)array + (i * t_size)) = ((rand() % 25) + 65) + (((rand() % 2) == 0) * offset);
	}

	// Ausgabe: unsortierte Liste (Character - bsort)
	printf("\nunsortierte Liste (Buchstaben):\n");
	Print1DArray(array, t_size, a_size);

		// Zeitmarke: ta_b	(Start)
		clock_t ta_b;
		ta_b = clock();

	// Bubblesort Sortierung
	bsort(array, t_size, a_size, compare_char);

		// Zeitmarke: ta_b	(Stop)
		ta_b = clock() - ta_b;


		return ((double)ta_b) / CLOCKS_PER_SEC; // in seconds 
}