#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


// Anzahl der Elemente die sortiert werden sollen
#define ArraySize 20

// function: Allgemein
void Print1DArray(void* array, int t_size, int a_size);
void Print3DArray(void* array, int t_size, int a_size);
void PrintComplex(void* array, int t_size, int a_size);

void bsort(void* a, int t_size, int a_size, int (*compare) (const void*, const void*));

// Zusatz
double subtask_0_b(void* array, int t_size, int a_size);
double subtask_0_q(void* array, int t_size, int a_size);


// function: Teilaufgabe a)
double subtask_a_b(void* array, int t_size, int a_size);
double subtask_a_q(void* array, int t_size, int a_size);


// function: Teilaufgabe b)
double subtask_b_b(void* array, int t_size, int a_size);
double subtask_b_q(void* array, int t_size, int a_size);

void PrintMagVector(void* a, int t_size, int a_size);			// Betrag von Vector

// function: Teilaufgabe c)
double subtask_c_b(void* array, int t_size, int a_size);
double subtask_c_q(void* array, int t_size, int a_size);

typedef struct {
	float Re;
	float Im;
} ComplexNum;


int main(void)
{
	// Init Zufallszahl
	srand(time(NULL));

	printf("PG1 Uebungsblatt 11 - Aufgabe 3: void-Pointer und function-Pointer\n");
	// Zusatz (Integer Array)
	// Array initialisieren
	int array_b[ArraySize] = { 0 };		// Bubblesort
	int array_q[ArraySize] = { 0 };		// Quicksort


	// Bubblesort und Zeitmessung
	double time_taken_0_b = subtask_0_b(array_b, sizeof(int), sizeof(array_b)/sizeof(int));

	// Ausgabe des Array (sortiert)	-	Bubblesort
	printf("\nsortierte Liste (Integer - bsort):\n");
	Print1DArray(array_b, sizeof(int), sizeof(array_b) / sizeof(int));


	// Quicksort und Zeitmessung
	double time_taken_0_q = subtask_0_q(array_q, sizeof(int), sizeof(array_q) / sizeof(int));

	// Ausgabe des Array (sortiert)	-	Quicksort
	printf("\nsortierte Liste (Integer - qsort):\n");
	Print1DArray(array_q, sizeof(int), sizeof(array_q) / sizeof(int));

	/*
	----------------------------------------------------------------------------------------------------------
	*/

	// Teilaufgabe a)
	// Buchstaben sortieren (Kleinschreibung == Grossschreibung)

	// char-Array mit zufaelligen Werten befuellen
	char A_Letters_b[ArraySize] = { 0 };
	char A_Letters_q[ArraySize] = { 0 };


	// Bubblesort und Zeitmessung
	double time_taken_a_b = subtask_a_b(A_Letters_b, sizeof(char), sizeof(A_Letters_b) / sizeof(char));

	// Ausgabe des Array (sortiert)	-	Bubblesort
	printf("\nsortierte Liste (Character - bsort):\n");
	Print1DArray(A_Letters_b, sizeof(char), sizeof(A_Letters_b) / sizeof(char));


	// Quicksort und Zeitmessung
	double time_taken_a_q = subtask_a_q(A_Letters_q, sizeof(char), sizeof(A_Letters_q) / sizeof(char));

	// Ausgabe des Array (sortiert)	-	Quicksort
	printf("\nsortierte Liste (Character - qsort):\n");
	Print1DArray(A_Letters_q, sizeof(char), sizeof(A_Letters_q) / sizeof(char));


	/*
	----------------------------------------------------------------------------------------------------------
	*/

	// Teilaufgabe b)
	// 3D-Vectoren (double[3]) (am Betrag)
	
	double B_3DVectoren_b[ArraySize][3] = { 0 };
	double B_3DVectoren_q[ArraySize][3] = { 0 };

	// Bubblesort und Zeitmessung
	double time_taken_b_b = subtask_b_b(B_3DVectoren_b, sizeof(double), sizeof(B_3DVectoren_b) / sizeof(double));

	// Ausgabe des Array (sortiert)	-	Bubblesort
	printf("\nsortierte Liste (3D-Vectoren - bsort):\n");
	Print3DArray(B_3DVectoren_b, sizeof(double), sizeof(B_3DVectoren_b) / sizeof(double));
	// Betrag der Vectoren
	PrintMagVector(B_3DVectoren_b, sizeof(double), sizeof(B_3DVectoren_b)/sizeof(double));


	// Quicksort und Zeitmessung
	double time_taken_b_q = subtask_b_q(B_3DVectoren_q, sizeof(double), sizeof(B_3DVectoren_q) / sizeof(double));

	// Ausgabe des Array (sortiert)	-	Quicksort
	printf("\nsortierte Liste (3d-Vectoren - qsort):\n");
	Print3DArray(B_3DVectoren_q, sizeof(double), sizeof(B_3DVectoren_q) / sizeof(double));
	// Betrag der Vectoren
	PrintMagVector(B_3DVectoren_q, sizeof(double), sizeof(B_3DVectoren_q) / sizeof(double));



	/*
	----------------------------------------------------------------------------------------------------------
	*/

	// Teilaufgabe c)
	// Komplexe Zahlen (struct) (am Betrag)

	// Struct fuer bubblesort
	ComplexNum bubble[ArraySize];

	// Struct fuer quicksort
	ComplexNum quick[ArraySize];


	// Bubblesort und Zeitmessung
	double time_taken_c_b = subtask_c_b(bubble, sizeof(float), sizeof(bubble) / sizeof(float));

	// Ausgabe sortierte Komplexe Zahlen (bsort)
	printf("sortierte Komplexe Zahlen (bsort):\n\n");
	PrintComplex(&bubble, sizeof(float), sizeof(bubble) / sizeof(float));


	// Quicksort und Zeitmessung
	double time_taken_c_q = subtask_c_q(quick, sizeof(float), sizeof(quick) / sizeof(float));

	// Ausgabe sortierte Komplexe Zahlen (qsort)
	printf("sortierte Komplexe Zahlen (qsort):\n\n");
	PrintComplex(&quick, sizeof(float), sizeof(quick) / sizeof(float));


	/*
	----------------------------------------------------------------------------------------------------------
	*/

	printf("\n\n");
	printf("\tVergleich Laufzeit von bsort und qsort\n");
	printf("Anzahl der zu sortierenden Elemente: %d\n\n", ArraySize);
	printf("\t\t\tbsort\t\tqsort\n");
	printf("Zusatz (int)\t\t%.f ms\t\t%.f ms\n", time_taken_0_b * 1000, time_taken_0_q * 1000);
	printf("a) (char)\t\t%.f ms\t\t%.f ms\n", time_taken_a_b * 1000, time_taken_a_q * 1000);
	printf("b) (doouble[3])\t\t%.f ms\t\t%.f ms\n", time_taken_b_b * 1000, time_taken_b_q * 1000);
	printf("c) (struct)\t\t%.f ms\t\t%.f ms\n", time_taken_c_b * 1000, time_taken_c_q * 1000);

}