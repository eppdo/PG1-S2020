#include <stdio.h>

#define Row 6		// Reihen Spielfeld
#define Col 7		// Spalten Spielfeld


// function: Spielfeld auffuellen
void PrintPlayGround(int PGRow, int PGCol, char GameArray[][7]);

// function: Eingabe des Spielers
void PlayerInput(int PGRow, int PGCol, char GameArray[][7], int Player, int LastInp[2]);

// function: Ueberpruefung ob Spielzug zum Sieg gefuehrt hat
_Bool Checker(char GameArray[][7], int PGRow, int PGCol, int Player, int LastInp[2]);

// function: "Siegerehrung" - Anzeige Spielende mit Gewinner
void FinalResult(int Winner, int PGRow, int PGCol, _Bool Draw);



int main(void)
{
	char RepeatGame = '1';					// Wenn Spiel beendet wurde kann es erneut gestartet werden

	char GameArray[Row][Col];				// Spielstandspeicher

	int Player;								// Spieler 1 und 2	-> gerader Spielzug		==	Spieler 1
											//					->	ungerader Spielzug	==	Spieler 2
											
							

	while (RepeatGame == '1')
	{

		_Bool GameEnd = 0;						// flag Spielende

		_Bool Draw = 0;							// flag Unentschieden

		int Turn = 0;							// Rundenzaehler

		int LastInput[2] = { 0 };				// [0]	->	Row	|	[1]	->	Col


		// Header
		printf("PG1 Uebungsblatt 9: Aufgabe 3 - Mehrdimensionale Felder - Vier - Gewinnt Spiel\n\n");
		printf("Spieler 1:\tX\n");
		printf("Spieler 2:\tO\n\n\n");

		// GameArray fuellen
		for (int i = 0; i < Row; i++)				// Zeile GameArray
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
			// Zuweisung aktueller Spieler
			Player = (Turn % 2) + 1;

			// Eingabe Spieler	
			PlayerInput(Row, Col, GameArray, Player, LastInput);

			// Spielfeld anzeigen
			PrintPlayGround(Row, Col, GameArray);

			// Ueberpruefung ob die Gewinnbedung erreicht wird
			GameEnd = Checker(GameArray, Row, Col, Player, LastInput);										

			// Zaehler fuer Spielrunde um +1 erhoehen
			Turn++;

			// Pruefung ob alle Felder beleget sind:
			//	-> unentschieden
			if (Turn >= (Row * Col))
			{
				GameEnd = 1;
				Draw = 1;
			}


		}	// while (GameEnd == 0)



		// Ende - Spielstand
		FinalResult(Player, Row, Col, Draw);

		// Erneut spielen
		printf("\n\nErneut spielen?:\nJa -> 1\t\t|\tNein -> Sonstige Eingabe\n");
		printf("Eingabe:\t");
		if (scanf_s(" %c", &RepeatGame, sizeof(RepeatGame)) == 0)		// scanf_s == 0 bei ungueltiger Eingabe (z.B. mehr als 1 Zeichen)
		{
			break;
		}


	}	// while (RepeatGame == '1')




	return 0;
}