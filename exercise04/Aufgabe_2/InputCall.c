#include <stdio.h>

int InputCall(char* dateInput)
{
	unsigned int dateOutput;

	printf("Eingabe %s: \t", dateInput);
	scanf_s("%d", &dateOutput);

	return dateOutput;

}



