// function: Diagonale links/rechts ueberpruefen (abhaengig don "int direction")
int DiagChecker(char GameArray[][7], int row, int col, int PGCol, char PlayerChar, int Counter, int WinElements, int direction);

_Bool CheckDiag(char GameArray[][7], int PGRow, int PGCol, int Player)
{
	char PlayerChar;
	int CounterR = 0;			// Zaehlt die diagonalen gleichen Spielsteine (rechts)
	int CounterL = 0;			// Zaehlt die diagonalen gleichen  Spielsteine (links)
	const int WinElements = 4;		// Anzahl der notwendigen Elemente zum gewinnen

	int direction = 1;			// direction = 1 -> Diagonale nach rechts | direction = -1 -> Diagonale nach links
	

	// Zuweisung Spieler Symbol
	switch (Player)
	{
	case 1:
		PlayerChar = 'X';
		break;

	case 2:
		PlayerChar = 'O';
		break;

	default:
		PlayerChar = '?';		// Unbekannte Eingabe
		break;
	}

	// Check: Diagonal links -> rechts
	for (int row = (PGRow - 1); row >= 0; row--)					// Zeile (von "unten" beginnend)	
	{

		for (int col = 0; col <= (PGCol - 1); col++)		// Spalte  (von links beginnend)
		{
			// Zaehler in neuer Zeile initialisieren
			CounterR = 0;
			CounterL = 0;

			// Ueberpruefung ob Element = Spieler 
			if (GameArray[row][col] == PlayerChar)
			{

				// Pruefung Diagonale nach rechts
				direction = 1;

					// Ueberpruefung: Diagonale innerhalb von Spielfeld
					if ((row - (WinElements - 1)) >= 0 && (col + (direction) * (WinElements - 1)) >= 0)		
					{
						CounterR = DiagChecker(GameArray, row, col, PGCol, PlayerChar, CounterR, WinElements, direction);
					}
				

				// Pruefung Diagonale nach links
				direction = -1;

				// Ueberpruefung: Diagonale innerhalb von Spielfeld
				if ((row - (WinElements - 1)) >= 0 && (col + (direction) * (WinElements - 1)) < PGCol)
				{
					CounterL = DiagChecker(GameArray, row, col, PGCol, PlayerChar, CounterL, WinElements, direction);
				}
								

			}	// (GameArray[row][col] == PlayerChar)
			else
			{
				CounterR = 0;
				CounterL = 0;

			}	// if (GameArray[row][col] == PlayerChar)



			if (CounterR >= WinElements || CounterL >= WinElements)
			{
				return 1;
			}


		}	// for (int col = 0; col < (PGCol - 1); col++)		// Spalte  (von links beginnend)

	}	// for (int row = (PGRow - 1); row > 0; row--)					// Zeile (von "unten" beginnend)	

	return 0;

}