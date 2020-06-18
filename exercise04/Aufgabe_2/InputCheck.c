#include<stdio.h>

int InputCheck(unsigned int tag, unsigned int m, unsigned int j)
{
	unsigned int maxDays;		// maximale Anzahl an Tage je Monat


	// Check Jahreszahl
	if (j < 1582)
	{
		printf("Fehler!\n - Wochentag kann nur im gregorianischen Kalender bis 1582 berechnet werden - \n");
		return 1;
	}

	// Check Monatsangabe
	if (m > 12 || m <= 0)
	{
		printf("Fehler!\n - Falsche Monatsangabe -\n");
		return 1;
	}

	// Berechnungen fuer Tagesangabe:
		// Monate mit 30 Tage   
		if ((m <= 7 && m % 2 == 0 && m!= 2) || (m < 7 && m % 2 != 0))
		{
			maxDays = 30;
		}
		// Sonderfall Februar -> Schaltjahr = false
		else if ((m == 2 && j % 4 != 0) || (m == 2 && j % 4 == 0 && j % 100 == 0 && j % 400 != 0))
		{
			maxDays = 28;
		}
		// Schaltjahr = true
		else if ((m == 2 && j % 4 == 0) || (m == 2 && j % 4 == 0 && j % 100 == 0 && j % 400 == 0))
		{
			maxDays = 29;
		}
		// Sonstiges
		else
		{
			maxDays = 31;
		}
		

	// Check Tagesangabe
	if (tag > maxDays)
	{
		printf("Fehler!\n - Falsche Tagangabe -\n");
		return 1;
	}


	return 0;
}
