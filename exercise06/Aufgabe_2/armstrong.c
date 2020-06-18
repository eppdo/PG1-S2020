#include <math.h>

// function: Ermittlung der Ziffern
unsigned int Digits(unsigned int Number);

// function: Potenzberechnung Abhängig der Stellen
unsigned int ArmstrongPotenz(unsigned int x, unsigned int n);


_Bool armstrong(unsigned int n)
{
	unsigned int ArmstrongTestValue = 0;
	unsigned int StoreDiv;						// Entspricht der aktuell ausgewaehlten Ziffer
	unsigned int actNumber = n;

	// Ermittlung Ziffernanzahl
	unsigned int NumDigits = Digits(n);

	for (int lv = NumDigits; lv >= 1; lv--)
	{
		// Aktuelle hoechste Zehnerpotenz
		unsigned int power = lv - 1;

		// Ermitteln der aktuellen Ziffer (angefangen an der linken Position)
		StoreDiv = n / pow(10, power);

		ArmstrongTestValue = ArmstrongTestValue + ArmstrongPotenz(StoreDiv, NumDigits);

		// Eliminieren der linken Positon
		n = n - StoreDiv * pow(10, power);
	}

	// Ueberpruefung ob aktuelle Zahl eine Armstrong-Zahl ist
	if (ArmstrongTestValue == actNumber)
	{
		return 1;
	}
	else {
		return 0;
	}

	
}