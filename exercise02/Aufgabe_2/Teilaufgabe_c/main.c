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


	printf("Aufgabe 2 c) - Subtraktion von Zahlen mit der Basis 6\n\t");


	// Initialisierung: Basis 6
	z3_1 = 1;
	z2_1 = 5;
	z1_1 = 2;
	z0_1 = 5;
	printf("Minuend: \t%i%i%i%i\n\t", z3_1, z2_1, z1_1, z0_1);

	z3_2 = 1;
	z2_2 = 1;
	z1_2 = 2;
	z0_2 = 0;
	printf("Subtrahent: \t%i%i%i%i\n\t", z3_2, z2_2, z1_2, z0_2);

	// Addition

		// Ziffer 0
		//  Erklaerung: (Basis 6 + Differenz der Ziffern) modulo Basis 6
	erg_z0 = (base6 + (z0_1 - z0_2)) % base6;


	// Ziffer 1 mit Uebertrag:
		// Hilfsvar. fuer Uebertrag: 
		// h_var1_i > 6 fuer (z1 - z2) < 0 (also z2 > z1)
	h_var1_i = base6 - (z0_1 - z0_2);
	// h_var1_i > 6 -> Modulo Berechnung  = 6	-> Division mit Basis 6 = 1 (z1 < z2 -> Uebertrag) | = 0.xx (z1 > z2)
	h_var1 = (base6 % (base6 - h_var1_i)) / base6;

	// int(h_var1) -> Typumwandlung von float -> int: 0.xx wird 0	-> kein Uebergang
	erg_z1 = (base6 + (z1_1 - (z1_2 + (int)h_var1))) % base6;


	// Ziffer 2 mit Uebertrag:
	h_var2_i = base6 - (z1_1 - z1_2);
	h_var2 = (base6 % (base6 - h_var2_i)) / base6;

	erg_z2 = (base6 + (z2_1 - (z2_2 + (int)h_var2))) % base6;


	// Ziffer 3 mit Uebertrag:
	h_var3_i = base6 - (z2_1 - z2_2);
	h_var3 = (base6 % (base6 - h_var3_i)) / base6;

	erg_z3 = (base6 + (z3_1 - (z3_2 + (int)h_var3))) % base6;



	printf("Ergebnis: \t%i%i%i%i\n", erg_z3, erg_z2, erg_z1, erg_z0);


	return(0);

}


