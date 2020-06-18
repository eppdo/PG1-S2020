#include <stdio.h>

// function: Celsius -> Fahrenheit
float CtoF(float FahrenheitValue);

// function: Fahrenheit -> Celsius
float FtoC(float CelsiusValue);


int main(void)
{
	float ValueFahrenheit;
	float ValueCelsius;
	char charEingabe ='\0';

	// Eingabe:
	printf("Temperaturumrechnung\n");
	printf("\tFuer die Umrechnung von C -> F: Eingabe von F\n");
	printf("\tFuer die Umrechnung von F -> C: Eingabe von C\n");
	printf("\tFuer die Beendigung des Programms: Sonstige Eingabe\n");


	while (charEingabe == '\0' || charEingabe == 'F' || charEingabe == 'f' || charEingabe == 'C' || charEingabe == 'c')
	{
		printf("\nIn welche Skala soll umgerechnet werden [C/F] ?: ");
		scanf_s(" %c", &charEingabe);

		// Umrechnung Celsius -> Fahrenheit
		if (charEingabe == 'F' || charEingabe == 'f')	
		{
			printf("Eingabe Wert in Celsius:\t");
			scanf_s("%f", &ValueCelsius);

			ValueFahrenheit = CtoF(ValueCelsius);
			printf("\n%.2f Celsius\t=\t%.2f Fahrenheit\n", ValueCelsius, ValueFahrenheit);

		}
		// Umrechnung Fahrenheit -> Celsius
		else if (charEingabe == 'C' || charEingabe == 'c')
		{
			printf("Eingabe Wert in Fahrenheit:\t");
			scanf_s("%f", &ValueFahrenheit);

			ValueCelsius = FtoC(ValueFahrenheit);
			printf("\n%.2f Fahrenheit\t=\t%.2f Celsius\n", ValueFahrenheit, ValueCelsius);

		}
		else
		{
			printf("\n\tProgramm wurde beendet!\n");
			return 0;
		}
	}	


	return 0;
}