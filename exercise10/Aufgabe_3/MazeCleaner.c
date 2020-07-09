void MazeCleaner(char maze[][20])
{
	// Wege die in eine Sackgasse gefuehrt haben sind mit 'x' markiert und werden entfernt
	for (int i = 0; i < 20; i++)				// Zeile
	{
		for (int j = 0; j < 20; j++)			// Spalte
		{
			if (maze[i][j] == 'x')
				maze[i][j] = ' ';
		}

	}

}
