#include <stdio.h>

// Funktion: Umrechnung con Hex. auf Dezimalzahlen
int HexToDec(char x)
{
	int out = 0;

	if (x >= 0x30 && x <= 0x39)				//	ANSI: 0x30 == '0'		0x39 == '9'
		out = x - 0x30;
	else if (x >= 0x41 && x <= 0x5A)		//	ANSI: 0x41 == 'A'		0x5A == 'Z'
		out = x - 0x41 + 10;

	// Wird nicht benoetigt: Angabe gibt vor, dass keine Kleinbuchstaben verwendet werden
	else									// ANSI: 0x61 == 'a'		0x7A =='z'
		out = x - 0x61 + 10;


	return out;
}


int func(char* str)
{
	unsigned int out = 0;			//	Rueckgabewert
	int strlen = 0;					//	Laenge des Strings

	// Laenge des Eingabestrings ermitteln
	for (int i = 0; i < 11; i++)
	{
		if (*(str + i) == '\0')			// '\0' ist immer letztes Zeichen in string
			break;

		strlen = i;
	}

	int exponent = 0;


	for (int i = 2; i <= strlen; i++)
	{
		//	out == Rueckgabewert	
		//	+=	Addition mit vorherigen Wert: x += 10	==	x = x + 10;
		//	HexToDec == Funktion fuer die Umrechnung von Hex.Zahlen zu Dezimalzahlen
		//	<< ((strlen - i) * 4)	== Bitshift um 4*x	
		//	Bitshit << 4	==	* 16^x		x == Potenz
		//	Bsp.:	0xF23	->	15*16^2 + 2*16^1 + 2*16^0
		out += HexToDec(*(str + i)) << ((strlen - i) * 4);
	}

	return out;
}


int main(void)
{
	printf("Probeklausur PG1 - Sommersememster 2020: Aufgabe 3\n");
	printf("Felder und Strings:\n");

	// Eingabe 
	char inp[11] = { 0 };

	printf("Eingabe: ");
	scanf_s("%s", &inp, sizeof(inp));

	unsigned int Dec = func(inp);

	printf("Hex:\t%s\tDec:\t%u\n", inp, Dec);


	return 0;
}