#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define Mrow 5			// Dimension der Matrizen (Zeilen)
//#define Mcol 5			// Dimension der Matrizen (Spalten)

// Definition der Dimension von Matrix 1
#define M1row 7		// Anzahl der Zeilen von Matrix 1
#define M1col 2			// Anzahl der Spalten von Matrix 1

// Definition der Dimension von Matrix 1
#define M2row M1col		// Anzahl der Zeilen von Matrix 2 (MUSS gleich der Spaltenanzahl von Matrix 1 sein)
#define M2col 9			// Anzahl der Spalten von Matrix 2



// Seed fuer Zufallszahl (Auffuellen der Matrizen mit zufaelligen Werten)
void initSeed()
{
	srand((unsigned)time(NULL));
}

// function: Zufallszahl zwischen 0 - 9
int randInt(void)
{
	return (rand() % 10);
}

// function: Matrix mit zufaelligen Werten zwischen 0 und 9 fuellen
void fillMatrix(int* MPtr, int MRow, int MCol)
{
	for (int i = 0; i < (MRow * MCol); i++)
	{
		*(MPtr + i) = randInt();
	}
}

// function: Ausgabe der Matrix
void printMatrix(int* MPtr, int MRow, int MCol, char string[8])
{
	printf("\nMatrix %s:\n\n", string);

	for (int i = 0; i < (MRow * MCol); i++)
	{
		printf("%d\t", *(MPtr + i));

		// Neue Zeile
		if ((i + 1) % MCol == 0)
		{
			printf("\n");
		}

	}
}

// function: Matrixmultiplikation
void MatrixMultiplikation(int* M1ptr, int* M2ptr, int* ErgMatPtr, int MRow, int MCol, int M1Col);




int main(void)
{
	// Initialisierung Seed fuer Zufallszahl
	initSeed();

	printf("PG1 Uebungsblatt 11 - Aufgabe 1: Pointer to Pointer (4x4 Matrix-Multiplikation)\n");

	//M1 = Matrix 1		|		M2 = Matrix 2
	int M1[M1row][M1col] = { 0 };
	int* M1ptr = &M1;				// Pointer auf Matrix M1
	int M2[M2row][M2col] = { 0 };
	int* M2ptr = &M2;				// Pointer auf Matrix M2

	// Ergebnismatrix
	int ErgMatrix[M1row][M2col] = { 0 };
	int* ErgMatPtr = &ErgMatrix;

	// Matrix 1 und Matrix 2 mit zufaelligen Werten befuellen
	fillMatrix(M1, M1row, M1col);
	fillMatrix(M2, M2row, M2col);


	// Anzeige von Matrix 1 und Matrix 2
	printMatrix(M1, M1row, M1col, "1");
	printMatrix(M2, M2row, M2col, "2");



	//// Matrixmultiplikation -> "Zeile * Spalte"
	MatrixMultiplikation(M1ptr, M2ptr, ErgMatPtr, M1row, M2col, M1col);


	// Ausgabe Ergebnis
	printMatrix(ErgMatrix, M1row, M2col, "Ergebnis");


	return 0;
}