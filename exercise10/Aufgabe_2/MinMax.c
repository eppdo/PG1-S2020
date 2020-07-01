#include <stdio.h>

void MinMax(short* Array, int ArraySize, long* Result)
{
	short Min = (short)((*Result << 16) >> 16);
	short Max = (short)(*Result >> 16);


	if (ArraySize < 1)		// Betrachteter Arraybereich besteht nur aus 1 Element
	{
		if (Array[0] <= Min)					// Minimum
		{
			Min = Array[0];
		}
		else if (Array[0] > Max)				// Maximum
		{
			Max = Array[0];
		}

		*Result = (long)(Max << 16) + (long)Min;

	}
	else		// Betrachteter Arraybereich besteht nur min. 2 Elementen
	{
		
		if (Array[ArraySize] <= Array[ArraySize - 1])
		{
			// (Array[ArraySize - 1] <= Array[ArraySize - 2]) == false	-> 0 * Array[0] = 0
			Min = (Array[ArraySize] < Min) * Array[ArraySize] + (Min <= Array[ArraySize]) * Min;

			Max = (Array[ArraySize - 1] > Max) * Array[ArraySize - 1] + (Max >= Array[ArraySize - 1]) * Max;
			
		}
		else
		{
			// Vergleiche ob Min/Max kleiner/groesser  dem aktuellen Wert in Result ist 
			Min = (Array[ArraySize - 1] < Min) * Array[ArraySize - 1] + (Min <= Array[ArraySize - 1]) * Min;

			Max = (Array[ArraySize] > Max) * Array[ArraySize] + (Max >= Array[ArraySize]) * Max;
		}


		*Result = (long)(Max << 16) + (long)Min;

		MinMax(Array, ArraySize - 2, Result);
	}


	



}