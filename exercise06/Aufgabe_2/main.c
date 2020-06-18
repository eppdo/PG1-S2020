#include <stdio.h>

// function: Kubik
unsigned int kubik(unsigned int x);

// function: Prüfung ob Armstrong-Zahl vorliegt
_Bool armstrong(unsigned int n);



int main(void)
{

	// b
	unsigned int ArmstrongTestValue;
	unsigned int actNumber;
	unsigned int Laufvar1 = 0;
	//c
	_Bool ArmstrongOutput;
	unsigned int Laufvar2 = 0;


	printf("Ue1 - Aufgabe 2: Armstrong-Zahlen-Finder\n");
	printf("Teilaufgabe b): Armstrong-Zahlen bis < 999\n\n");

	for (int Hunderter = 0; Hunderter <= 9; Hunderter++)
	{
		for (int Zehner = 0; Zehner <= 9; Zehner++)
		{
			for (int Einer = 0; Einer <= 9; Einer++)
			{
				ArmstrongTestValue = kubik(Hunderter) + kubik(Zehner) + kubik(Einer);

				actNumber = Hunderter * 100 + Zehner * 10 + Einer * 1;

					// Armstrong-Zahlen-Test
					if (actNumber == ArmstrongTestValue && actNumber >= 100)
					{
						Laufvar1++;
						printf("\t%d. Armstrong-Zahl ist: %d\n", Laufvar1, ArmstrongTestValue);
					}
			}
		}
	}

	// -------------------------------------------------------------------------------------------

	printf("\nTeilaufgabe b): Armstrong-Zahlen zwischen 1 und 10.000\n\n");

	for (int lv = 1; lv <= 10000; lv++)
	{
		ArmstrongOutput = armstrong(lv);

			if (ArmstrongOutput == 1)
			{
				Laufvar2++;
				printf("\t%d. Armstrong-Zahl ist: %d\n", Laufvar2, lv);
			}
	}


	return 0;

}