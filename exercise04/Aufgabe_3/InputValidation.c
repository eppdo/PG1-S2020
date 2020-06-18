#include <stdio.h>

int InputValidation(unsigned char* in)
{
	// Laufvariable
	unsigned int i;
	unsigned int flagValidation = 0;

	for (i = 0; i <= 7; i++)
	{
		if (in[i] != '0' && in[i] != '1' && in[i] != '\0')
		{
			printf("Fehlerhafte Eingabe!");
			flagValidation = 1;
			return flagValidation;
		}
		else if (in[i] == '\0')
		{
			break;

		}
	}

return 0;
}