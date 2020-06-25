#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// function: Seed fuer Zufallszahl
void initRand()
{
	srand((unsigned)time(NULL));
}

// function: Zufallszahl
int randDice(int n)
{
	if (n != 0)
	{
		return ((rand() % n) + 1);
	}
	else
	{
		return 0;
	}

}

// function: char to int
int CharToInt(char inp);

// function: Ueberpruefung der Eingabe
_Bool InputCheck(char* InpString);

int main(void)
{
	// Seed fuer Zufallszahl
	initRand();

	char InpString[6];					// Eingabestring
	int ResultA2 = 0;

	// Header
	printf("PG 1  Uebungsblatt 9: Aufgabe 3 - Zeichenkettenverarbeitung\n");
	printf("\nEingabe in Form von 'kDn+C'\n");
	printf("\tk\t->\tWuerfelwuerfe\n");
	printf("\tn\t->\tSeitenanzahl des Wuerfels\n");
	printf("\t+\t->\tVorzeichen\n");
	printf("\tC\t->\tKonstanter Wert\n");
	printf("\nk, n und C sind als einziffrige Dezimalzahlen einzugeben\n");

	printf("\nEingabe:\t");
	if (scanf_s("%s", InpString, sizeof(InpString)) == 0)
	{
		printf("Fehlerhafte Eingabe\n");
		return 1;
	}

	// Ueberpruefung der Eingabe:
	_Bool flagInpCheck = InputCheck(&InpString);
	if (InputCheck(&InpString) == 1)
	{
		printf("Fehlerhafte Eingabe!\n");
		return 1;

	}

	// Ausgabe Eingabe:
	printf("\nAnzahl Wuerfelwuerfe:\t%c\n", InpString[0]);
	printf("Anzahl Seiten Anzahl:\t%c\n", InpString[2]);
	printf("Konstanter Wert:\t%c%c\n\n", InpString[3], InpString[4]);
	
	// Wuerfeln
	for (int i = 1; i <= CharToInt(InpString[0]); i++)
	{
		ResultA2 = ResultA2 + randDice(CharToInt(InpString[2]));
		printf("\tWurf #%d:\tWert: %d\n", i, ResultA2);

	}

	ResultA2 = ResultA2 + CharToInt(InpString[3]) * CharToInt(InpString[4]);

	// Ausgabe Ergebnis
	printf("\nErgebnis:\t%d\n", ResultA2);




	return 0;
}