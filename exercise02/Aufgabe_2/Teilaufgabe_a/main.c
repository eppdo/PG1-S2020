#include <stdio.h>
#include <math.h>

int main(void)
{
	// Aufgabe 2
	// a)
	unsigned int z0, z1, z2, z3, erg_a_10, erg_a_10_add, erg_a_6;
	float z3_6f, z2_6f, z1_6f, z0_6f;
	unsigned int z3_6i, z2_6i, z1_6i, z0_6i;

	// Initialisierung: (Groesster Wert: 5555 (Basis 6) -> 1295 (Basis 10))
	z0 = 4;
	z1 = 3;
	z2 = 2;
	z3 = 1;

	// Berechnung von Basis 6 zu Basis 10:
	erg_a_10 = z3 * pow(6, 3) + z2 * pow(6, 2) + z1 * pow(6, 1) + z0 * pow(6, 0);
	printf("Aufgabe 2 a)\n\tZahl Basis 6: \t\t\t%i%i%i%i\n\t", z3, z2, z1, z0);
	printf("Umgewandelt in Zahl Basis 10: \t%i\n\t", erg_a_10);

	// Schlaue Berechnung: Addition + 1
	erg_a_10_add = erg_a_10 + 1;
	printf("Addition + 1: \t\t\t%i\n\n\t", erg_a_10_add);

	// Berechnung von Basis 10 zu Basis 6:
		// Erste Ziffer:
	z3_6f = erg_a_10_add / pow(6, 3);
	z3_6i = (int)z3_6f;

	// Zweite Ziffer:
	z2_6f = (erg_a_10 - z3_6i * pow(6, 3)) / pow(6, 2);
	z2_6i = (int)z2_6f;

	// Dritte Ziffer:
	z1_6f = (erg_a_10_add - z3_6i * pow(6, 3) - z2_6i * pow(6, 2)) / pow(6, 1);
	z1_6i = (int)z1_6f;

	// Vierte Ziffer
	z0_6f = (erg_a_10_add - z3_6i * pow(6, 3) - z2_6i * pow(6, 2) - z1_6i * pow(6, 1)) / pow(6, 0);
	z0_6i = (int)z0_6f;
	printf("Umgewandelt in Zahl Basis 6: \t%i%i%i%i", z3_6i, z2_6i, z1_6i, z0_6i);




	return(0);
}

/*
i.		Groesster Wert: 5555 (Basis 6) -> 1295 (Basis 10)

ii.		overvlow: 5555 (Basis 6) + 1 (Basis 6) = 0000 (Basis 6)

*/
