#include <stdio.h>

long MinMaxAlternative(short* Array, int ArraySize)
{
	short Min = 32767;				// Vorbelegt mit Grenzen des Wertebereichs
	short Max = -32768;				// Vorbelegt mit Grenzen des Wertebereichs

	if (ArraySize == 2)
	{
		// (Array[0] <= Array[1]) == false	-> 0 * Array[0] = 0
		Min = (Array[0] <= Array[1]) * Array[0] + (Array[1] < Array[0]) * Array[1];

		Max = (Array[0] >= Array[1]) * Array[0] + (Array[1] > Array[0]) * Array[1];

	}
	else if (ArraySize == 1)
	{
		Min = Array[0];
		Max = Min;
	}
	else
	{
		short tempMin;
		short tempMax;

		for (int i = 0; i < ArraySize; i = (i + 2))			// Vergleiche 2 aufeinanderfolgende Elemente
		{
			if (i + 1 != ArraySize)
			{
				tempMin = (Array[i] <= Array[i + 1]) * Array[i] + (Array[i + 1] < Array[i]) * Array[i + 1];
				Min = (tempMin <= Min) * tempMin + (tempMin > Min) * Min;

				tempMax = (Array[i] >= Array[i + 1]) * Array[i] + (Array[i + 1] > Array[i]) * Array[i + 1];
				Max = (tempMax >= Max) * tempMax + (Max > tempMax) * Max;
			}
			else
			{
				Min = (Array[i] <= Min) * Array[i] + (Array[i] > Min) * Min;

				Max = (Array[i] >= Max) * Array[i] + (Max > Array[i]) * Max;
			}

		}
	}

	return ((long)Max << 16) + (long)Min;

}