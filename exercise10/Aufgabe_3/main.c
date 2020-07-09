#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "maze.h"

#define StartCoordRow 1
#define StartCoordCol 1

// function: Labyrinth anzeigen
void printMaze(char maze[][20]);

// function: MazeSolver
void Solver(char maze[][20], const int* StartRow, const int* StartCol, int row, int col, int Way[][3]);

// function: MazeCleaner	
void MazeCleaner(char maze[][20]);

// Seed fuer Zufallszahl (An Kreuzungen soll zufaellig entschieden werden, wo zuerst abgebogen werden soll)
void initSeed()
{
	srand((unsigned)time(NULL));
}



int main(void)
{
	printf("PG1 Uebungsblatt 10 - Aufgabe 10: Backtracking - Die hungernde Maus im Labyrinth\n\n");

	initSeed();

	// Start Position im Labyrinth
	const int StartRow = StartCoordRow;
	const int StartCol = StartCoordCol;

	// Labyrinth anzeigen
	printMaze(maze);


	// MazeSolver
		// Initialisierung Anfangswerte:
		int Way[500][3] = { 0 };		// Koordinaten bereits gegangener Weg:
											// [x][y][z]		->	[x] = row
											//					->	[y] = col


	Solver(&maze, StartRow, StartCol, StartCoordRow, StartCoordCol, &Way);

	// Labyrinth anzeigen (mit Sackgassen)
	printMaze(maze);

	// Labyrinth von Irrwegen befreien
	MazeCleaner(maze);


	// Labyrinth anzeigen
	printMaze(maze);


	return 0;

}