#include <stdio.h>
#include <stdlib.h>

char EingabeOperatorF(void)
{
	char Eingabe;			

	printf("Eingabe Operator:\t");
	if (scanf_s(" %c", &Eingabe) == 1)
	{
		if (Eingabe == '+' || Eingabe == '-' || Eingabe == '*' || Eingabe == '/' || Eingabe == '%' || Eingabe == 'q')
		{
			return Eingabe;
		}
		else
		{
			printf("\nFalsche Eingabe! - Eingabewert muss darf nur aus folgenden Zeichen bestehen:\n");
			printf("\t'+', '-', '*', '/', '%', 'q'\n");
			exit(0);							// Game Over
		}


	}
	else
	{
		printf("\nFalsche Eingabe! - Eingabewert muss darf nur aus folgenden Zeichen bestehen:\n");
		printf("\t'+', '-', '*', '/', '%', 'q'\n");
		exit(0);									// Game Over

	}

}