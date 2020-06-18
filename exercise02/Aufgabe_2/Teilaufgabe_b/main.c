// PG1 Uebungsblatt 2 - Aufgabe 2 b)

#include <stdio.h>

int main(void)
{
// Summand 1:
	unsigned int z3_1, z2_1, z1_1, z0_1;
//Summand 2:
	unsigned int z3_2, z2_2, z1_2, z0_2;
// Ergebnis:
	unsigned int erg_z3, erg_z2, erg_z1, erg_z0;
// Hilfsvariable für Uebergang
	unsigned int erg_z3h, erg_z2h, erg_z1h, erg_z0h;

	printf("Aufgabe 2 b) - Addition von Zahlen mit der Basis 6\n\t");


	// Initialisierung: Basis 6
	z3_1 = 0;
	z2_1 = 1;
	z1_1 = 2;
	z0_1 = 3;
	printf("Summand 1: \t%i%i%i%i\n\t", z3_1, z2_1, z1_1, z0_1);

	z3_2 = 3;
	z2_2 = 5;
	z1_2 = 5;
	z0_2 = 5;
	printf("Summand 2: \t%i%i%i%i\n\t", z3_2, z2_2, z1_2, z0_2);

	// Addition

		// Ziffer 0 mit Uebergang
		//  erg = Summe * boolscher Ausdruck -> boolscher Ausdruck fuer Ueberschlag (>= 6) true
		erg_z0 = (z0_1 + z0_2) * ((z0_1 + z0_2) <= 5) + ((z0_1 + z0_2)-6)* ((z0_1 + z0_2) >= 6);
		erg_z0h = ((z0_1 + z0_2) >= 6);

		// Ziffer 1 mit Uebergang
		erg_z1 = (z1_1 + z1_2 + erg_z0h) * ((z1_1 + z1_2 + erg_z0h) <= 5) + ((z1_1 + z1_2 + erg_z0h) - 6) * ((z1_1 + z1_2 + erg_z0h) >= 6);
		erg_z1h = ((z1_1 + z1_2) >= 6);


		// Ziffer 2 mit Uebergang
		erg_z2 = (z2_1 + z2_2 + erg_z1h) * ((z2_1 + z2_2 + erg_z1h) <= 5) + ((z2_1 + z2_2 + erg_z1h) - 6) * ((z2_1 + z2_2 + erg_z1h) >= 6);
		erg_z2h = ((z2_1 + z2_2) >= 6);

		// Ziffer 3 mit Uebergang
		erg_z3 = (z3_1 + z3_2 + erg_z2h) * ((z3_1 + z3_2 + erg_z2h) <= 5) + ((z3_1 + z3_2 + erg_z2h) - 6) * ((z3_1 + z3_2 + erg_z2h) >= 6);


		printf("Ergebnis: \t%i%i%i%i\n", erg_z3, erg_z2, erg_z1, erg_z0);
}


