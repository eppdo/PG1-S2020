#include <stdio.h>

#define Row 6		// Reihen Spielfeld
#define Col 7		// Spalten Spielfeld


// function: Spielfeld auffuellen
void PrintPlayGround(int PGRow, int PGCol, char GameArray[][7]);

// function: Eingabe des Spielers
void PlayerInput(int PGRow, int PGCol, char GameArray[][7], int Player);

// function: Ueberpruefung Horizontal
_Bool CheckHor(char GameArray[][7], int PGRow, int PGCol, int Player);

// function: Ueberpruefung Vertikal
_Bool CheckVer(char GameArray[][7], int PGRow, int PGCol, int Player);

// function: Ueberpruefung Diagonale
_Bool CheckDiag(char GameArray[][7], int PGRow, int PGCol, int Player);

// function: "Siegerehrung" - Anzeige Spielende mit Gewinner
void FinalResult(short Winner, int PGRow, int PGCol);


int main(void)
{
	char GameArray[Row][Col];				// Spielstandspeicher

	_Bool GameEnd = 0;						// flag Spielende

	const int Player1 = 1;					// Spieler 1 
	const int Player2 = 2;					// Spieler 2

	int RoundInt = 0;						// Rundenzaehler

	short Winner = 0;							// Gewinner



	// Header
	printf("PG1 Uebungsblatt 9: Aufgabe 3 - Mehrdimensionale Felder - Vier - Gewinnt Spiel\n\n");
	printf("Spieler 1:\tX\n");
	printf("Spieler 2:\tO\n\n\n");

	// GameArray fuellen
	for (int i = 0; i < Row; i++)			// Zeile GameArray
	{
		for (int j = 0; j < Col; j++)			// Spalte GameArray
		{
			GameArray[i][j] = ' ';				// Fuellen mit Leerzeichen Charakter
		}
	}

	// Spielfeld anzeigen
	PrintPlayGround(Row, Col, GameArray);


	while (GameEnd == 0)
	{
		// Zaehler fuer Spielrunde um +1 erhoehen
		RoundInt++;

		// Eingabe Spieler 1
		PlayerInput(Row, Col, GameArray, Player1);

		// Spielfeld anzeigen
		PrintPlayGround(Row, Col, GameArray);

		// Ueberpruefung 
		if (RoundInt >= 4)
		{
			// Horizontal
			if (CheckHor(GameArray, Row, Col, Player1) == 1)
			{
				GameEnd = 1;
				Winner = 1;
				break;
			}

			// Vertikal
			if (CheckVer(GameArray, Row, Col, Player1) == 1)
			{
				GameEnd = 1;
				Winner = 1;
				break;
			}

			// Diagonal
			if (CheckDiag(GameArray, Row, Col, Player1) == 1)
			{
				GameEnd = 1;
				Winner = 1;
				break;
			}

		}

		// Eingabe Spieler 2
		PlayerInput(Row, Col, GameArray, Player2);

		// Spielfeld anzeigen
		PrintPlayGround(Row, Col, GameArray);

		// Ueberpruefung 
		if (RoundInt >= 4)
		{
			// Horizontal
			if (CheckHor(GameArray, Row, Col, Player2) == 1)
			{
				GameEnd = 1;
				Winner = 2;
				break;
			}

			// Vertikal
			if (CheckVer(GameArray, Row, Col, Player2) == 1)
			{
				GameEnd = 1;
				Winner = 2;
				break;
			}

			// Diagonal
			if (CheckDiag(GameArray, Row, Col, Player2) == 1)
			{
				GameEnd = 1;
				Winner = 2;
				break;
			}
			
		}

		
		// Spielfeld voll (2 * RoundInt -> 1 Spielrunde -> 2 Spieler -> 2 Steine)


		if ((2 * RoundInt) >= (Row * Col))
		{
			GameEnd = 1;
		}


	}	// while (GameEnd == 0)



	// Ende - Spielstand
	FinalResult(Winner, Row, Col);


	return 0;
}