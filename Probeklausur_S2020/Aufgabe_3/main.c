#include <stdio.h>

int power(int a, int exp)		// Funktionsweise entspricht "pow"-Funktion aus math.h
{
	int out = 1;		// Vorbelegung mit Wert 1, falls der Exponent == 0

	if (exp != 0)
	{
		for (int i = 1; i <= exp; i++)
		{
			out *= a;		// out *= a		==		out = out * a
		}
	}

	return out;
}

int HexToDec(char x)
{
	int out = 0;

	if (x >= 0x30 && x <= 0x39)				//	ANSI: 0x30 == '0'		0x39 == '9'
		out = x - 0x30;
	else if (x >= 0x41 && x <= 0x5A)		//	ANSI: 0x41 == 'A'		0x5A == 'Z'
		out = x - 0x41 + 10;
	else									// ANSI: 0x61 == 'a'		0x7A =='z'
		out = x - 0x61 + 10;


	return out;
}



int func(char* str)
{
	int out = 0;			//	Rueckgabewert
	int strlen = 0;			//	Laenge des Strings

	// Laenge des Eingabestrings ermitteln
	for (int i = 0; i < 11; i++)
	{
		if (*(str + i) == '\0')			// '\0' ist immer letztes Zeichen in string
			break;

		strlen = i;
	}

	int exponent = 0;

	for (int i = strlen; i >= 2; i--)
	{
		//	out == Rueckgabewert	
		//	+=	Addition mit vorherigen Wert: x += 10	==	x = x + 10;
		//	HexToDec == Funktion fuer die Umrechnung von Hex.Zahlen zu Dezimalzahlen
		//	power == Nachimplementierung von "pow"-funktion aus math.h
		out += HexToDec(*(str + i))* power(16, exponent++);
	}

	return out;
}


int main(void)
{
	printf("Probeklausur PG1 - Sommersememster 2020: Aufgabe 3\n");
	printf("Felder und Strings:\n");

	// Eingabe 
	char inp[11] = {0};

	printf("Eingabe: ");
	scanf_s("%s", &inp, sizeof(inp));

	int Dec = func(inp);

	printf("Hex:\t%s\tDec:\t%d\n", inp, Dec);


	return 0;
}