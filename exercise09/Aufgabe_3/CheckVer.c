_Bool CheckVer(char GameArray[][7], int PGRow, int PGCol, int Player)
{
	char PlayerChar;
	int Counter = 0;			// Zaehlt die nebeneinanderliegenden Spielsteine
	const int WinElements = 4;		// Anzahl der notwendigen Elemente zum gewinnen

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

	// Check	
	for (int col = 0; col < PGCol; col++)		// Spalte  (von links beginnend)
	{
		// Zaehler in neuer Spalte initialisieren
		Counter = 0;

		for (int row = (PGRow - 1); row >= 0; row--)					// Zeile (von "unten" beginnend)
		{
			// Ueberpruefung ob Element = 
			if (GameArray[row][col] == PlayerChar)
			{
				// Zaehler um +1 erhoehen
				Counter++;
			}
			else
			{
				Counter = 0;
			}

			if (Counter >= WinElements)
			{
				return 1;
			}


		}	// for (int row = (PGRow - 1); row >= 0; row--)					// Zeile (von "unten" beginnend)

	}	// for (int col = 0; col < PGCol; col++)		// Spalte  (von links beginnend)

	return 0;

}