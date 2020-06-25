#include <stdio.h>
#include <ctype.h>

#define maxLength 100

// function: Teilaufgabe b) - Ueberpruefung ob Eingabe Palindrom
_Bool PalindromCheck(char* InpStr, char* OutpStr, int strLength);

// function: Teilaufgabe c) - Ueberpruefung auf Satzpalindrome
_Bool SatzPalindromCheck(char* InpStr, char* OutpStr, int strLength);

int main(void)
{
	// Header
	printf("PG1 Uebungsblatt 9 - Aufgabe 1: Zeichenkettenverarbeitung\n");
	char InpStr[maxLength];					// Eingabe char string
	char OutpStr[maxLength];				// Ausgabe char string
	int strLength = 0;						// Laenge des Eingabestrings
	_Bool flagPalindrom;					// Eingabe (Teilaufgabe b)) ist Palindrom 
	_Bool flagSatzPalindrom;				// Eingabe (Teilaufgabe c)) ist Satzpalindrom 

	_Bool flagSentence = 0;					// Ueberpruefung ob Eingabe aus mehreren Woertern besteht: 0 -> Wort | 1 -> Satz

	// ---------------------------------------------------------
	//	Teilaufgabe a)
	// ---------------------------------------------------------
	printf("\n\nTeilaufgabe a)\n");
	printf("\tMaximale Anzahl an Zeichen:\t%d\n", maxLength);
	printf("\tEingabe:\t");
	fgets(InpStr, maxLength, stdin);				// scanf funntkioniert nur bei einzelnen Woertern, Leerzeichen -> '\0' -> Stringende

	// Laenge der Zeichenkette ermitteln			// Beenden der Eingabe mit 'Enter' = '\n' = letztes Zeichen in Inputstream
	for (int i = 0; i < sizeof(InpStr); i++)
	{
		// Leerzeichen finden -> Eingabe ist ein Satz und kein einzelner Wort
		if (InpStr[i] == ' ')
		{
			flagSentence = 1;
		}

		// Ende der Eingabe finden
		if (InpStr[i] == '\n')
		{
			strLength = i;
			InpStr[i] = '\0';						// Zeilenumbruch aus String durch Stringende '\0' ersetzen
			break;
		}
	}

	// Zeichenkette umdrehen
	for (int j = 0; j < strLength; j++)
	{
		OutpStr[j] = InpStr[(strLength - 1) - j];
	}
	OutpStr[strLength] = '\0';

	printf("\tAusgabe\t\t%s\n", OutpStr);


	// ---------------------------------------------------------
	//	Teilaufgabe b)
	// ---------------------------------------------------------

	printf("\nTeilaufgabe b)\n");
	if (flagSentence == 0)			// Eingabe ist EIN Wort
	{
		flagPalindrom = PalindromCheck(&InpStr, &OutpStr, strLength);

		if (flagPalindrom == 1)
		{
			printf("\n\t'%s' ist ein Palindrom\n", InpStr);
		}
		else
		{
			printf("\n\t'%s' ist KEIN Palindrom\n", InpStr);
		}

		printf("\t%s\t-\t%s\n", InpStr, OutpStr);
	}
	else
	{
		printf("Eingabe besteht aus mehr als einem Wort - Keine Ueberpruefung auf Palindrom\n");
	}

	
	// ---------------------------------------------------------
	//	Teilaufgabe c)
	// ---------------------------------------------------------

	printf("\nTeilaufgabe c)\n");
	if (flagSentence == 1)			// Eingabe besteht aus mehreren Woertern
	{
		flagSatzPalindrom = SatzPalindromCheck(&InpStr, &OutpStr, strLength);

		if (flagSatzPalindrom == 1)
		{
			printf("\n\t'%s' ist ein Satzpalindrom\n", InpStr);
		}
		else
		{
			printf("\n\t'%s' ist KEIN Satzpalindrom\n", InpStr);
		}

		printf("\t%s\n", InpStr);
		printf("\t%s\n", OutpStr);
	}
	else
	{
		printf("Eingabe besteht nur aus EINEM Wort - Keine Ueberpruefung aus Satzpalindrom\n");
	}


	return 0;
}