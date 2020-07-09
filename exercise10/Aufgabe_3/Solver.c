#include <stdio.h>   

// function: Bewegungsrichtung finden
void Movement(_Bool Direction[], int* nextRow, int* nextCol);

// Benachbarte Elemente untersuchen
void Pathfinder(_Bool Direction[], char maze[][20], int row, int col, int* Crossing);

// Sackgasse
void DeadEnd(char maze[][20], int* row, int* col, int Way[][3], int* StaticIdx);



void Solver(char maze[][20], const int* StartRow, const int* StartCol, int row, int col, int Way[][3])
{
	// Array zum speichern der freien Richtungen: _Bool 0 -> belegt	| _Bool 1 -> frei
	// Direction[0] -> Boolscher Wert: 1 = Freies Nachbarelement
	// Direction[1]	->	oben	|	Direction[2] ->	unten
	// Direction[3]	->	links	|	Direction[4] ->	rechts
	_Bool Direction[5] = { 0 };

	// Index fuer bereits begangenen Weg
	static int idx = 0;

	// Aktuelle Position speichern
	Way[idx][0] = row;
	Way[idx][1] = col;
	idx++;


	// Wieder an Start angekommen -> Kein Futter gefunden
	if (row == StartRow && col == StartCol && maze[row][col] == '.')
	{
		// Wieder am Start angekommen -> Kein Futter gefunden
		printf("\nEs wurde kein Futter gefunden und die Maus muss verhungern\n\n");
	}

	// Futter gefunden :)
	else if (maze[row][col] == 'F')
	{
		// Ausgabe: "Futter gefunden"	->	Ziel erreicht
		printf("\n\tFutter gefunden!\n\n");

	}

	// Wegsuche
	else
	{
		// Umgebung nach freien Feldern untersuchen: Ergebnis in Direction gespeichert
		Pathfinder(Direction, maze, row, col, &Way[idx - 1][2]);


		// Pruefung ob Sackgasse
		if (Direction[0] == 0)			// Direction[0] == 0 -> Sackgasse
		{
			DeadEnd(maze, &row, &col, Way, &idx);
		}
		else
		{
			// Weg markieren
			maze[row][col] = '.';
		}



		// Bestimmung naechste Bewegunsrichtung
		int nextRow = 0;
		int nextCol = 0;

		Movement(Direction, &nextRow, &nextCol);


		// rek. Aufruf Funktion
		Solver(maze, StartRow, StartCol, row + nextRow, col + nextCol, Way);

	}

}