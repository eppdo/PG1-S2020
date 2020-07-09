#include <stdlib.h>

void Movement(_Bool Direction[], int* nextRow, int* nextCol)
{
	// Reihenfolge: oben -> unten -> links -> rechts
	// Ist eine Richtung frei wird diese zurueckgegeben
	int dir = 0;

	// Zufallszahl
	int RandIdx = rand();

	// Index fuer Direction Array
	int idx;

	for (int i = 1; i < 5; i++)
	{
		idx = ((RandIdx + i) % 4) + 1;
		if (Direction[idx] == 1)
		{
			dir = idx;
			break;
		}

	}

	switch (dir)
	{
	case 1:		// oben
		*nextRow = -1;
		*nextCol = 0;
		break;

	case 2:		// unten
		*nextRow = 1;
		*nextCol = 0;
		break;

	case 3:		// links
		*nextRow = 0;
		*nextCol = -1;
		break;

	case 4:		// rechts
		*nextRow = 0;
		*nextCol = 1;
		break;

	default:
		break;

	}

}