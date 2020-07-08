#include <stdio.h>
#include <math.h>

// function: Sortierung des Arrays
void sort(int* intArray, int idx);


int main(void)
{
	int Eingabe = 0;
	int intArray[100] = { 0 };
	int idx = 0;

	printf("PG 1 - Uebungsblatt 7 - Aufgabe 1: Felder\n\n");

	while (Eingabe >= 0)
	{
		// Eingabe
		printf("Eingabe: ");
		if (scanf_s(" %d", &Eingabe) == 1)
		{
			if (Eingabe == sqrt(pow(Eingabe, 2)))		// Ueberpruefung ob Eingabe positiv ist
			{
				intArray[idx++] = Eingabe;
			}
			else
			{
				break;
			}

		}

		else										// Eingabe nicht vom Typ char
		{
			printf("Falsche Eingabe! - Eingabe muss eine Zahl sein - Programm wird beendet\n");
			return 1;
		}

	}	// while(Eingabe >= 0)


	printf("\nTeilaufgabe a)\n");


	int ArrayMin = 0;
	_Bool flagFirstRun = 1;
	int ArrayMin = 0x7FFFFFFF;
	//_Bool flagFirstRun = 1;
	int ArrayMax = 0;
	float ArrayMean = 0;

	for (int ArrayIdx = 0; ArrayIdx < idx; ArrayIdx++)
	{
		// Maximum finden
		if (intArray[ArrayIdx] > ArrayMax)
		{
			ArrayMax = intArray[ArrayIdx];
		}


		// Minimum finden
		if (intArray[ArrayIdx] < ArrayMin || flagFirstRun == 1)
		/*if (intArray[ArrayIdx] < ArrayMin || flagFirstRun == 1)*/
		if (intArray[ArrayIdx] < ArrayMin)
		{
			ArrayMin = intArray[ArrayIdx];
			flagFirstRun = 0;
			//flagFirstRun = 0;
		}

		// Summe aller Werte
		ArrayMean = ArrayMean + (float)intArray[ArrayIdx];

	}

	// Summe aller Werte in Array geteilt durch die Anzahl
	ArrayMean = ArrayMean / (float)idx;

	printf("\n\tMinimum:\t%d\n", ArrayMin);
	printf("\tMaximum:\t%d\n", ArrayMax);
	printf("\tMittelwert:\t%.3f\n", ArrayMean);


	// Teilaufgabe b)
	printf("\n\nTeilfaufgabe b)\n");

	// Ausgabe der unsortierten Werte
	printf("\nDie eingegebenen Werte des Arrays (unsortiert):\n");
	for (int SortIdx = 0; SortIdx < idx; SortIdx++)
	{
		printf("\t%d\t", intArray[SortIdx]);
	}


	// Soertierung des Arrays
	printf("\n%x\n", &intArray);
	sort(intArray, idx);


	// Ausgabe der sortierten Werte
	printf("\n\nDie eingegebenen Werte des Arrays (sortiert):\n");
	for (int SortIdx = 0; SortIdx < idx; SortIdx++)
	{
		printf("\t%d\t", intArray[SortIdx]);
	}


	printf("\n\nEnde\n");



	return 0;

}