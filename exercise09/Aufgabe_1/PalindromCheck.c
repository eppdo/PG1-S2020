#include <stdio.h>
#include <ctype.h>

_Bool PalindromCheck(char* InpStr, char* OutpStr, int strLength)
{
	// Eingabe ist Palindrom? 0 -> false | 1 -> true
	_Bool flagPalindrom = 0;

	for (int i = 0; i < strLength; i++)
	{
		if (tolower(InpStr[i]) != tolower(OutpStr[i]))
		{
			flagPalindrom = 0;
			return flagPalindrom;
			break;
		}

		flagPalindrom = 1;

	}

	return flagPalindrom;
}