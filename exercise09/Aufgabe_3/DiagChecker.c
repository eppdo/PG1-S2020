int DiagChecker(char GameArray[][7], int row, int col, int PGCol, char PlayerChar, int Counter, int WinElements, int direction)
{
//(direction = +1->Diagonale nach rechts | direction = -1->Diagonale nach links)
	
	
	// Elemente der Diagonale untersuchen 
	for (int idx = 0; idx < WinElements; idx++)
	{
		if ((GameArray[row - idx][col + (direction)*idx] == PlayerChar))
		{
			// Zaehler um +1 erhoehen
			Counter++;
		}
		else
		{
			break;
		}

	}


	return Counter;
}