#include <stdio.h>
#include <stdlib.h>

float EingabeGanzzahl(int Eingabewert)
{
	int Eingabe;
	float out;

	printf("Eingabe Zahl %d:\t\t", Eingabewert);
	if (scanf_s("%d", &Eingabe) == 1)
	{
		out = (float)Eingabe;
		return out;
	}
	else
	{
		printf("\nFalsche Eingabe! - Eingabewert muss eine Ganzzahl sein!\n");
		exit(0);						// Game Over

	}

}