#include <stdio.h>

void printMaze(char maze[][20])
{

	for (int i = 0; i < 20; i++)				// Zeile
	{
		for (int j = 0; j < 20; j++)			// Spalte
		{
			printf("%c", maze[i][j]);
		}

		printf("\n");
	}


}