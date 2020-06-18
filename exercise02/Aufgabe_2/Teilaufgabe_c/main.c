// PG1 Uebungsblatt 2 - Aufgabe 2 c)

#include <stdio.h>

int main()
{
	// Minuend:
	int z3_1, z2_1, z1_1, z0_1;
	// Subtrahent:
	int z3_2, z2_2, z1_2, z0_2;
	// Ergebnis:
	int erg_z3, erg_z2, erg_z1, erg_z0;
	// Hilfsvariable für Uebergang
	int erg_z3h, erg_z2h, erg_z1h, erg_z0h;

	printf("Aufgabe 2 b) - Addition von Zahlen mit der Basis 6\n\t");


	// Initialisierung: Basis 6
	z3_1 = 4;
	z2_1 = 3;
	z1_1 = 2;
	z0_1 = 1;
	printf("Minuend: \t%i%i%i%i\n\t", z3_1, z2_1, z1_1, z0_1);

	z3_2 = 1;
	z2_2 = 2;
	z1_2 = 3;
	z0_2 = 4;
	printf("Subtrahent: \t%i%i%i%i\n\t", z3_2, z2_2, z1_2, z0_2);

	// Addition

		// Ziffer 0 mit Uebergang
		//  erg = Differenz * boolscher Ausdruck -> boolscher Ausdruck fuer Ueberschlag (< 0) true
	erg_z0 = (z0_1 - z0_2) * ((z0_1 - z0_2) >= 0) + (6 + z0_1 - z0_2) * ((z0_1 - z0_2) < 0);
	erg_z0h = ((z0_1 - z0_2) < 0);

	// Ziffer 1 mit Uebergang
	erg_z1 = (z1_1 - (z1_2 + erg_z0h)) * ((z1_1 - (z1_2 + erg_z0h)) >= 0) + (6 + z1_1 - (z1_2 + erg_z0h)) * ((z1_1 - (z1_2 + erg_z0h)) < 0);
	erg_z1h = ((z1_1 - z1_2) < 0);

	// Ziffer 2 mit Uebergang
	erg_z2 = (z2_1 - (z2_2 + erg_z1h)) * ((z2_1 - (z2_2 + erg_z1h)) >= 0) + (6 + z2_1 - (z2_2 + erg_z1h)) * ((z2_1 - (z2_2 + erg_z1h)) < 0);
	erg_z2h = ((z2_1 - z2_2) < 0);

	// Ziffer 3 mit Uebergang
	erg_z3 = (z3_1 - (z3_2 + erg_z2h)) * ((z3_1 - (z3_2 + erg_z2h)) >= 0) + (6 + z3_1 - (z3_2 + erg_z2h)) * ((z3_1 - (z3_2 + erg_z2h)) < 0);

	printf("Ergebnis: \t%i%i%i%i\n", erg_z3, erg_z2, erg_z1, erg_z0);

	return(0);

}


