#include <stdio.h>

// function: Spielereingabe in GameArray eintragen
int SetInput(char GameArray[][7], int PGRow, int Input, char PlayerChar);

void PlayerInput(int PGRow, int PGCol, char GameArray[][7], int Player, int LastInp[2])
{
	int InpPlayer;					// Eingabe Spieler
	_Bool flagInp = 1;				// Ueberpruefung ob Eingabe gueltig ist: 1 -> gueltig | 0 -> ungueltig
	char PlayerChar = 'X';
	int Row = 0;					// Koordinate Reihe

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
		break;
	}


	// Eingabe des Spielers
	while (flagInp == 1)
	{
		printf("\nEingabe Spieler %d:\t", Player);
		scanf_s("%d", &InpPlayer);

		// Ueberpruefung der Eingabe
		if (InpPlayer >= 0 && InpPlayer < PGCol && GameArray[0][InpPlayer] == ' ')
		{
			// Eingabe in GameArray Eintragen
			Row = SetInput(GameArray, PGRow, InpPlayer, PlayerChar);
			flagInp = 0;

		}
		else
		{
			printf("\n\tUngueltige Eingabe!\n");
		}


	}	// while (flagInp == 1)

	LastInp[0] = Row;			// Eingabe Spieler:Reihe
	LastInp[1] = InpPlayer;		// Eingabe Spieler:	Spalte
}