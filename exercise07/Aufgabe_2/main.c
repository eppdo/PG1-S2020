#include <stdio.h>
#include <math.h>

// Dimensionen des Arrays
#define ArrayRow 21		// Anzahl der Zeilen im Array
#define ArrayCol 41			// Anzahl der Spalten im Array
#define maxAngle 360		// 360 Grad Winkel

// workaround fuer nicht erkanntes M_PI
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void plot(char* Array, int ArrayRow1, int ArrayCol1);

int main(void)
{
	// Array
	char Array[ArrayRow][ArrayCol] = { 0, 0 };

	printf("Aufgabe 2:\n");

	// y = sin(x)
	float x_Deg;			// x in Deg
	float x_Rad;			// x in Rad
	float y_sin;			// y = sin(x)
	float y_sinS;			// Skalierung von sin(x) für Werte zwischen [-1, ...,  1]
	int y;					// Wert y-Achse

	// Umrechnung von 360 Grad -> Anzahl Spalten im Array
	float xConv = (float)maxAngle / (float)(ArrayCol - 1);

	// Eintragen der Werte in Array
	for (int x = 0; x < (ArrayCol); x++)
	{
		// x Umrechnen in Spaltenwert
		x_Deg = x * xConv;

		// Umrechnen x in Bogenmass
		x_Rad = x_Deg * M_PI / 180;

		// Sinus berechnen
		y_sin = sin(x_Rad);

		// Skalieren von Sinus 
		y_sinS = y_sin * ((ArrayRow - 1) / 2);

		// Zeilenwert berechnen
		y = (int)((ArrayRow - 1) / 2) - (int)round(y_sinS);

		Array[y][x] = 'X';
		//printf("\tX: %d\tY: %d\t\tx:Deg:\t%.4f  \ty_sinS\t%.4f\n", x, y, x_Deg, y_sinS);
	}


	// Anzeige des Arrays
	plot(Array, ArrayRow, ArrayCol);


	return 0;

}