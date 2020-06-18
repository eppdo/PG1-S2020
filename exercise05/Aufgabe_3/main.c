// PG1 Uebungsblatt 5 - Aufgabe 3: Alternative Ausführungen und Schleifen
#include <stdio.h>

// function: Eingabe - Ganzzahl
float EingabeGanzzahl(int Eingabewert);

// function: Eingabe - Operator
char EingabeOperatorF(void);

// function: Addition		+
float Addition(float E1,float E2);

// function: Subtraktion	-
float Subtraktion(float E1, float E2);

// function: Multiplikation	*
float Multiplikation(float E1, float E2);

// function: Division		/
float Division(float E1, float E2);

// function: Modulo			%
float Modulo(int E1, int E2);

int main(void)
{
	float EingabeZahl1;
	int EingabeZahl2;
	char EingabeOperator = 'f';
	float Ergebnis = 0;


	printf("PG1 Uebung 5 - Aufgabe 3: Alternative Ausführungen und Schleifen\n");
	printf("\tTaschenrechner:\n\n");

	// Eingabe
		// Eingabe 1: Ganzzahl
		EingabeZahl1 = EingabeGanzzahl(1);

		while (EingabeOperator != 'q')
		{

			// Eingabe 2: Operator
			EingabeOperator = EingabeOperatorF();


			switch (EingabeOperator) {
			case '+':
				// Eingabe 3: Ganzzahl
				EingabeZahl2 = EingabeGanzzahl(2);
				Ergebnis = Addition(EingabeZahl1, EingabeZahl2);

				break;

			case '-':
				// Eingabe 3: Ganzzahl
				EingabeZahl2 = EingabeGanzzahl(2);
				Ergebnis = Subtraktion((float)EingabeZahl1, (float)EingabeZahl2);

				break;

			case '*':
				// Eingabe 3: Ganzzahl
				EingabeZahl2 = EingabeGanzzahl(2);
				Ergebnis = Multiplikation((float)EingabeZahl1, (float)EingabeZahl2);

				break;

			case '/':
				// Eingabe 3: Ganzzahl
				EingabeZahl2 = EingabeGanzzahl(2);
				Ergebnis = Division((float)EingabeZahl1, (float)EingabeZahl2);

				break;

			case '%':	// Modulo Berechnung ist nur fuer Ganzzahlen definiert
				// Eingabe 3: Ganzzahl
				EingabeZahl2 = EingabeGanzzahl(2);
				Ergebnis = Modulo((int)EingabeZahl1, (int)EingabeZahl2);

				break;

			case 'q':
				printf("\n\t Ergebnis: %.3f\n", Ergebnis);

				return 1;

			default:
				printf("Fehlerhafte Eingabe des Operators!\n");

				return 1;
			}


			// Ergebnis wird als EingabeZahl1 zwischengespeichert
			EingabeZahl1 = Ergebnis;
			printf("\nErgebnis: \t\t%.3f\n", Ergebnis);


		}


		return 0;
}
