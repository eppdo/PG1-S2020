#include <stdio.h>

int power(int a, int exp)
{
	int out = 1;

	if (exp != 0)
	{
		for (int i = 1; i <= exp; i++)
		{
			out = out * a;
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
	int out = 0;
	int strlen = 0;

	for (int i = 0; i < 11; i++)
	{
		strlen = i;

		if (*(str + i) == '\0')
			break;
	}

	int exponent = 0;

	for (int i = strlen -1; i >= 2; i--)
	{
		out = out + HexToDec(*(str + i))* power(16, exponent++);
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