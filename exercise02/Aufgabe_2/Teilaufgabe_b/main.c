#include <stdio.h>

int main()
{
	// Summand 1:
	unsigned int z3_1, z2_1, z1_1, z0_1;
	//Summand 2:
	unsigned int z3_2, z2_2, z1_2, z0_2;
	// Ergebnis:
	int erg_z3, erg_z2, erg_z1, erg_z0;
	// Hilfsvariable fuer Ueberschlag:
	float h_var1, h_var2, h_var3;
	unsigned int h_var1_i, h_var2_i, h_var3_i;
	// Basis: 6
	const unsigned int base6 = 6;


	printf("Aufgabe 2 b) - Addition von Zahlen mit der Basis 6\n\t");


	// Initialisierung: Basis 6
	z3_1 = 1;
	z2_1 = 5;
	z1_1 = 2;
	z0_1 = 5;
	printf("Summand 1: \t%i%i%i%i\n\t", z3_1, z2_1, z1_1, z0_1);

	z3_2 = 1;
	z2_2 = 1;
	z1_2 = 2;
	z0_2 = 0;
	printf("Summand 2: \t%i%i%i%i\n\t", z3_2, z2_2, z1_2, z0_2);

	// Addition

		// Ziffer 0 mit Uebergang
		//  Erklaerung: 
	erg_z0 = (base6 + z0_1 + z0_2) % base6;


	// Ziffer 1 mit Uebergang
		// Hilfsvar. fuer Uebertrag: 
		// h_var1_i: Summe aus z0_1 und z0_2
	h_var1_i = z0_1 + z0_2;
	// h_var1_i >= 6 -> Division mit Basis 6 = 1.xx (z1 + z2 >= 6 -> Uebertrag) | = 0.xx (z1 + z2 < 6)
	h_var1 = h_var1_i / base6;

	erg_z1 = (base6 + z1_1 + z1_2 + (int)h_var1) % base6;


	// Ziffer 2 mit Uebertrag:
	h_var2_i = z1_1 + z1_2;
	h_var2 = h_var2_i / base6;

	erg_z2 = (base6 + z2_1 + z2_2 + (int)h_var2) % base6;


	// Ziffer 3 mit Uebertrag:
	h_var3_i = z2_1 + z2_2;
	h_var3 = h_var3_i / base6;

	erg_z3 = (base6 + z3_1 + z3_2 + (int)h_var3) % base6;



	printf("Ergebnis: \t%i%i%i%i\n", erg_z3, erg_z2, erg_z1, erg_z0);


	return(0);

}


