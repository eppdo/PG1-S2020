#include <stdio.h>

// Anzeige Spielfeld:
//	|     |     |...			
//	|  X  |     |...			
//	|_____|_____|...

void PrintPlayGround(int PGRow, int PGCol, char GameArray[][7])
{
	// Header
	const char HeaderStr[] = "|_[0]_|_[1]_|_[2]_|_[3]_|_[4]_|_[5]_|_[6]_|";
	printf("\n%s\n\n", HeaderStr);


	for (int row = 0; row < PGRow * 3; row++)							// Zeilen
	{
		for (int col = 0; col <= PGCol * 6; col++)					// Spalten
		{
			if (col % 6 == 0)
			{
				printf("|");

				if (col == PGCol * 6)
				{
					printf("\n");
				}
			}
			else if (row % 3 == 2)
			{
				printf("_");
			}
			else if (col % 6 == 3 && row % 3 == 1)
			{
				printf("%c", GameArray[(int)(row / 3)][(int)(col / 6)]);

			}
			else
			{
				printf(" ");
			}

		}	// for(int col = 0; col <= PGCol*6; col++)

	}	// for (int row = 0; row < PGRow*3; row++)





}