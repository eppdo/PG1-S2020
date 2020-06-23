#include <stdio.h>

// function: Aufgabe 1a) - Vector Addition
void VecAdd3D(int* aa, int* ba, int* erg_A);

// function: Aufgabe 1b) - 3x3 Matritzen Addition
void MatAdd3x3(int* ab, int* bb, int idx, int* erg_B);

// function: Aufgabe 1c) - Vector Addition
void VecAdd(int* a, int* b, int idx, int* erg_C);

int main(void)
{
	printf("PG1 - Aufgabe 1: Felder als Parameter\n\n");
	// Aufgabe 1 a) 3D Vektor-Addition

		// Beispielwerte
	int aa[3] = { 10, 20, 30 };
	int ba[3] = { 1, 2 , 3 };
	int erg_A[3] = { 0 };

	// Vektoraddition
	VecAdd3D(&aa, &ba, &erg_A);


	// Ausgabe
	printf("Ergebnis a):\n");
	for (int i = 0; i < 3; i++)
	{
		printf("erg_A[%d]\t=\t%d\n", i, erg_A[i]);
	}


	// Aufgabe 1b) 3x3 Mitritzen Addition

		//Beispielwerte
	int ab[3][3] = { {10, 20 , 30}, {11, 21, 31}, {12, 22, 32} };
	int bb[3][3] = { {40, 50 , 60}, {41, 51, 61}, {42, 52, 62} };
	int erg_B[3][3];


	// 3x3 Matritzen-Addition
	MatAdd3x3(&ab, &bb, sizeof(ab) / sizeof(int), &erg_B);


	// Ausgabe
	printf("\n\nErgebnis b):\n");
	int idx = 0;
	for (int Zeile = 0; Zeile < 3; Zeile++)
	{
		for (int Spalte = 0; Spalte < 3; Spalte++)
		{
			if ((idx) % 3 == 0 && idx != 0)
			{
				printf("\n");
			}

			printf("%d\t", erg_B[Zeile][Spalte]);

			idx++;
		}
	}


	// Aufgabe 1 c) Vektor-Addition

	// Beispielwerte
	int ac[5] = { 10, 20, 30, 40, 50 };
	int bc[5] = { 1, 2 , 3, 4, 5 };
	int erg_C[5] = { 0 };

	// Vektoraddition
	VecAdd(&ac, &bc, sizeof(ac) / sizeof(int), &erg_C);


	// Ausgabe
	printf("\n\nErgebnis c):\n");
	for (int i = 0; i < sizeof(ac) / sizeof(int); i++)
	{
		printf("erg_C[%d]\t=\t%d\n", i, erg_C[i]);
	}







}