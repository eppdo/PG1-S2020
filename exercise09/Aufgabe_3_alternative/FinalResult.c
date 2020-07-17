#include <stdio.h>

void FinalResult(int Winner, int PGRow, int PGCol, _Bool Draw)
{
	printf("\n\n");

	// Abgrenzung mit #
	for (int i = 0; i <= PGCol * 6; i++)
	{
		printf("#");
	}

	printf("\n");


	// Ergebnisanzeige
	if (Draw == 0)
	{
		printf("\n\tSpieler %i gewinnt!\n", Winner);
	}
	else
	{
		printf("\n\tUnentschieden\n");
	}


	// // Abgrenzung mit #
	printf("\n");

	for (int i = 0; i <= PGCol * 6; i++)
	{
		printf("#");
	}

	printf("\n");

}