#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Seed fuer Zufallszahl (Auffuellen der Matrizen mit zufaelligen Werten)
void initSeed()
{
	srand((unsigned)time(NULL));
}

int randInt(void)
{
	return (rand() % 10);
}


// function: Matrix mit zufaelligen Werten zwischen 0 und 9 fuellen
void fillMatrix(int Matrix[][4], int MRow, int MCol);

// function: Ausgabe der Matrix
void printMatrix(int Matrix[][4], char string[8]);

// function: Matrixmultiplikation
void MatrixMultiplikation4x4(int* M1ptr, int* M2ptr, int* ErgMatPtr);


#define Mrow 4			// Dimension der Matrizen (Zeilen)
#define Mcol 4			// Dimension der Matrizen (Spalten)

int main(void)
{
	// Initialisierung Seed fuer Zufallszahl
	initSeed();

	printf("PG1 Uebungsblatt 11 - Aufgabe 1: Pointer to Pointer (4x4 Matrix-Multiplikation)\n");

	//M1 = Matrix 1		|		M2 = Matrix 2
	int M1[Mrow][Mcol] = { 0 };
	int* M1ptr = &M1;				// Pointer auf Matrix M1
	int M2[Mrow][Mcol] = { 0 };
	int* M2ptr = &M2;				// Pointer auf Matrix M2

	// Ergebnismatrix
	int ErgMatrix[Mrow][Mcol] = { 0 };
	int* ErgMatPtr = &ErgMatrix;

	// Matrix 1 und Matrix 2 mit zufaelligen Werten befuellen
	fillMatrix(M1, Mrow, Mcol);	
	fillMatrix(M2, Mrow, Mcol);
	

	// Anzeige von Matrix 1 und Matrix 2
	printMatrix(M1, "1");
	printMatrix(M2, "2");



	//// Matrixmultiplikation -> "Zeile * Spalte"
	MatrixMultiplikation4x4(M1ptr, M2ptr, ErgMatPtr);

	
	// Ausgabe Ergebnis
	printMatrix(ErgMatrix, "Ergebnis");


	return 0;
}