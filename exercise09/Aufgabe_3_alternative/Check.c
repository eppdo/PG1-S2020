_Bool Checker(char GameArray[][7], int PGRow, int PGCol, int Player, int LastInp[2])
{
	char PlayerChar;
	_Bool WinCondition = 0;				// 0	->	False		1	-> True
	int curRow = LastInp[0];			// Zeilen-Koordinaten des letzten Spielzuges
	int curCol = LastInp[1];			//Spalten-Koordinaten des letzten Spielzuges


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


	// Zaehler fuer aufeinanderfolgende gleiche Spielsteine
	int HCounter = 0;
	int VCounter = 0;
	int DCounter1 = 0;
	int DCounter2 = 0;

	for (int i = 0; i <= 6; i++)
	{
		// Check: Horizontal
		//	(curCol - 3) + i >= 0		->	Linke Grenze innerhalb von GameArray?
		//	((curCol + 3) - i) <= PGCol	->	Rechte Grenze innerhalb von GameArray?
		if ((curCol - 3) + i >= 0 && ((curCol + 3) - i) <= PGCol)
		{
			if (GameArray[curRow][(curCol - 3) + i] == PlayerChar)
			{
				HCounter++;
			}
			else
			{
				HCounter = 0;
			}
		}


		// Check: Vertical
		//	(curRow - 3) + i >= 0		->	Obere Grenze innerhalb von GameArray?
		//	((curRow + 3) - i) <= PGCol	->	untere Grenze innerhalb von GameArray?
		if ((curRow - 3) + i >= 0 && ((curRow + 3) - i) <= PGCol)
		{
			if (GameArray[i][curCol] == PlayerChar)
			{
				VCounter++;

			}
			else
			{
				VCounter = 0;
			}
		}


		// Check: Diagonal (links oben	-> rechts unten)
		// Pruefung ob Diagonale innerhalb des Spielfeldes liegt
		if (((curRow - 3) + i) >= 0 && ((curRow + 3) - i) <= PGRow && ((curCol - 3) + i) >= 0 && ((curCol + 3) - i) <= PGCol)
		{
			if (GameArray[((curRow - 3) + i)][(curCol - 3) + i] == PlayerChar)
			{
				DCounter1++;
			}
			else
			{
				DCounter1 = 0;
			}
		}


		// Check: Diagonal (rechts oben	-> links unten)
		// Pruefung ob Diagonale innerhalb des Spielfeldes liegt
		if (((curRow - 3) + i) >= 0 && ((curRow + 3) - i) <= PGRow && ((curCol - 3) + i) >= 0 && ((curCol + 3) - i) <= PGCol)
		{
			if (GameArray[((curRow - 3) + i)][(curCol + 3) - i] == PlayerChar)
			{
				DCounter2++;
			}
			else
			{
				DCounter2 = 0;
			}
		}


		// Pruefung: Ob 4 aufeinanderfolgende Spielsteine auf dem Feld sind
		if (HCounter == 4 || VCounter == 4 || DCounter1 == 4|| DCounter2 == 4)
		{
			WinCondition = 1;
			break;			// Schleife wird beendet	-> es muss nicht weiter gesucht werden
		}

	}		// for (int i = 0; i <= 6; i++)


	// Rueckgabe
	return WinCondition;

}