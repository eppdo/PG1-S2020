#include <stdio.h>

#define MaxShort -32768				// -32768 = min. Wert bei short (Grenzen des Wertebereichs: jedes zulässiges Element muss groesser sein als MaxShort)
#define MinShort 32767				// 32767 = max. Wert bei short (Grenzen des Wertebereichs: jedes zulässiges Element muss kleiner sein als MinShort)

// function: Min-Max-Suche
void MinMax(short* Array, int ArraySize, long* Result);

// function: Min-Max-Suche-Alternative
long MinMaxAlternative(short* Array, int ArraySize);


int main(void)
{
	// Gegebens Feld aus Werten (Datentyp short)
	// short -> 16 Bit:	-32.768 … +32.767	| unsigned short: 0 ... 65535
	short Array[] = { 7, 2, 5, 6, 3, 2, 1 };
	
	// Header
	printf("PG1 Uebungsblatt 10 - Aufgabe 2: Rekursion, Teile und Herrsche - MinMax-Suche\n\n");

	printf("Elemente in Array:\n");
	for (int i = 0; i < sizeof(Array)/sizeof(short); i++)
	{
		printf("\t%d", Array[i]);
	}

	int ArraySize = sizeof(Array)/sizeof(short);

	// Initialisierung von Min. und Max.
	short MinRec = MinShort;					
	short MaxRec = MaxShort;					

	// Initialisierung von Ergebnis (rekursive Suche)
	long ResRec = (long)((MaxRec << 16) + MinRec);
	
	// Suche von Min und Max in Array
	MinMax(&Array, ArraySize - 1, &ResRec);

	// Ausgabe Ergebnis (rekursiv)
	printf("\n\nErgebnis (rekursiv):\n");
	printf("\n\tMin:\t%d\tMax:\t%d\n\n", (short)((ResRec << 16) >> 16), (short)(ResRec >> 16));



	//	--------------------------------------------------------------------------------
	//	Alternative (Zusatz):	Iterative Suche nach Min und Max
	//	--------------------------------------------------------------------------------


	// Deklaration von Ergebnis (iterative Suche)
	long ResIt;

	// Iterative Suche nach Min und Max
	ResIt = MinMaxAlternative(&Array, ArraySize);

	short Min = (short)((ResIt << 16) >> 16);				// Setzt die ersten 16 Bit auf 0
	short Max = (short)(ResIt >> 16);						// Verschiebt die ersten 16 Bit nach rechts -> ueberschreibt die vorherigen 16 bit
															// Die ersten 16 Bit werden zu 0

	// Ausgabe Ergebnis (iterativ)
	printf("Ergebnis (iterativ):\n");
	printf("\n\tMin:\t%d\tMax:\t%d\n", Min, Max);

	

	return 0;
}