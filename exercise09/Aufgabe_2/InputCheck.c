#include <stdio.h>

// function: char to int
int CharToInt(char inp);

_Bool InputCheck(char* InpString)
{
	// Ueberpruefung erste Ziffer (Wuerfelwuerfe k)
	int kDigit = CharToInt(InpString[0]);

	if (kDigit < 0 || kDigit > 9)
	{
		return 1;
	}


	// Ueberpruefung zweite Ziffer (D)
	if (InpString[1] != 'D')
	{
		return 1;
	}


	// Ueberpruefung dritte Ziffer (Seitenanzahl Wuerfel n)
	int nDigit = CharToInt(InpString[2]);

	if (nDigit < 0 || nDigit > 9)
	{
		return 1;
	}


	// Ueberpruefung vierte Ziffer Vorzeichen (+/-)
	if (InpString[3] != '+' && InpString[3] != '-')
	{
		return 1;
	}


	// Ueberpruefung fünfte Ziffer (Konstante C)
	int cDigit = CharToInt(InpString[4]);

	if (cDigit < 0 || cDigit > 9)
	{
		return 1;
	}


	// Eingabe ist regelkonform
	return 0;
}