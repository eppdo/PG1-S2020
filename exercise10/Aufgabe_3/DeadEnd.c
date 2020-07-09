void DeadEnd(char maze[][20], int* row, int* col, int Way[][3], int* StaticIdx)
{
	// Finde letzten Eintrag in Way-Array
	int ArrayIdx = 0;
	for (int idx1 = 0; idx1 < 500; idx1++)
	{
		if (Way[idx1][0] == 0 && Way[idx1][1] == 0)
		{
			ArrayIdx = idx1 - 1;
			break;
		}
	}

	// Letzte Kreuzung in Way-Array finden
	for (int idx2 = ArrayIdx; idx2 > 0; idx2--)
	{

		if (Way[idx2][2] == 1)
		{
			Way[idx2][2] = 0;
			*row = Way[idx2][0];
			*col = Way[idx2][1];

			*StaticIdx = idx2 + 1;
			break;

		}

		// Irrweg mit 'x' markieren
		maze[Way[idx2][0]][Way[idx2][1]] = 'x';

		// Eintrag aus Way-Array entfernen
		Way[idx2][0] = 0;
		Way[idx2][1] = 0;


	}
}