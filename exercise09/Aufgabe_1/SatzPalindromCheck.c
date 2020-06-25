#include <stdio.h>
#include <ctype.h>

_Bool SatzPalindromCheck(char* InpStr, char* OutpStr, int strLength)
{
	// Eingabe ist Palindrom? 0 -> false | 1 -> true
	_Bool flagPalindrom = 0;

	// Bei Satz- oder Leerzeichen wird der Index um +1 erhoeht
	int InpIdx = 0;
	int OutIdx = 0;

	for (int i = 0; (i + OutIdx) < strLength; i++)
	{
		// Satz- und Leerzeichen erkennen: InpStr
		if (isalpha(InpStr[i + InpIdx]) == 0)
		{
			InpIdx++;
		}

		// Satz- und Leerzeichen erkennen: OutStr
		if (isalpha(OutpStr[i + OutIdx]) == 0)
		{
			OutIdx++;
		}

		// Satzpalindromueberpruefung
		if (tolower(InpStr[i + InpIdx]) != tolower(OutpStr[i + OutIdx]))
		{
			flagPalindrom = 0;
			return flagPalindrom;
			break;
		}

		flagPalindrom = 1;

	}	// for (int i = 0; (i + OutIdx) < strLength; i++)

	return flagPalindrom;
}