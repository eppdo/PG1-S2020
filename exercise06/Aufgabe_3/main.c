#include <stdlib.h>
#include <time.h>
#include <stdio.h>

// function: Seed fuer Zufallszahl
void initD6()
{
	srand((unsigned)time(NULL));
}
// function: Zufallszahl
int D6()
{
	return ((rand() % 6) + 1);
}

// function: Spielzug
void RollDice(unsigned int* GameArray[9][7], int* Dice, char* NewRoll, int curPlayer, unsigned int maxDice);


int main(void)
{
	initD6();

	unsigned int in_NumPlayers;
	const unsigned int maxDice = 5;				// maximale Anzahl Wuerfel	

	printf("PG1 Uebungsblatt 6 - Aufgabe 3: 'Funktionen und vordefinierte Funktionen - 'Kniffel fuer Arme'\n");
	printf("\n\tK N I F F E L\n\n");

	//  Eingabe: Anzahl der Spieler
	printf("Anzahl der Spieler [2 - 9]: ");
	if (scanf_s(" %d", &in_NumPlayers) != 1)				// Ueberpruefung ob integer eingebenen wurde
	{
		printf("Ungueltige Eingabe! - Eingabe muss eine Zahl sein\n");
		return 1;
	}

	// Ueberpruefung: Anzahl der Spieler
	if (in_NumPlayers <= 1 || in_NumPlayers > 9)			// Ueberpruefung ob die max. Anzahl an Spieler eingegeben wurde
	{
		printf("Ungueltige Eingabe! - Maximale Anzahl der Spieler ist 9\n");
		return 1;
	}

	// Initialisierung GameArray = Spielstand
	unsigned int GameArray[9][7] = { 			//[9] -> Maximale Anzahl der Spieler 9 | [7] Anzahl der Würfel = 5 und Gesamtpunktzahl
		//{# Spieler, Wuerfel 1, Wuerfel 2, Wuerfel 3, Wuerfel 4, Wuerfel 5, Punkte}
		{1, 0, 0, 0, 0, 0, 0},							// Spieler 1					
		{2, 0, 0, 0, 0, 0, 0},							// Spieler 2
		{3, 0, 0, 0, 0, 0, 0},							// Spieler 3
		{4, 0, 0, 0, 0, 0, 0}, 							// Spieler 4
		{5, 0, 0, 0, 0, 0, 0}, 							// Spieler 5
		{6, 0, 0, 0, 0, 0, 0}, 							// Spieler 6
		{7, 0, 0, 0, 0, 0, 0}, 							// Spieler 7
		{8, 0, 0, 0, 0, 0, 0}, 							// Spieler 8
		{9, 0, 0, 0, 0, 0, 0}							// Spieler 9
	};

	// Initialisierung: Alle Werte der Wuerfel auf 0
	int Dice[5] = { 0 };

	// Initialisierung: Array fuer Abfrage ob Wuerfel neu gewuerfelt werden soll
	char NewRoll[5] = { '1', '1', '1', '1', '1' };



	// Starte Spiel
	for (int curPlayer = 0; curPlayer < in_NumPlayers; curPlayer++)
	{
		// Erster Spielzug
		RollDice(GameArray, Dice, NewRoll, curPlayer, maxDice);

		// Erneuter Spielzug
		for (int Turn = 1; Turn <= 2; Turn++)
		{
			printf("\nWaehle nacheinander aus welche Wuerfel neu gewuerfelt werden: (%d/3)\n", Turn + 1);
			printf("\tMit dem Wert '1' wird der ausgewaehlte Wuerfel nochmal gewuerfelt\n\tSonstige Eingaben erhalten das Ergebnis\n\n");

			// Auswah l mit welchen Wuerfel neu gewuerfelt werden soll
			for (int idxRoll = 0; idxRoll < 5; idxRoll++)
			{
				printf("Wuerfel %d (%d P.): ", idxRoll + 1, GameArray[curPlayer][idxRoll + 1]);
				scanf_s(" %c", &NewRoll[idxRoll], 2);
			}

			// Erneut würfeln:
			RollDice(GameArray, Dice, NewRoll, curPlayer, maxDice);
		}


		// Anzeige Endergebnis
		printf("\n---------------------------------------------------------------\n");
		printf("\tEndergebnis Spieler %d: %d Punkte", GameArray[curPlayer][0], GameArray[curPlayer][6]);
		printf("\n---------------------------------------------------------------\n");


		int x = sizeof(NewRoll);
		// Ruecksetzen: Array fuer Abfrage ob Wuerfel neu gewuerfelt werden soll
		for (int idx = 0; idx < sizeof(NewRoll); idx++)
		{
			NewRoll[idx] = '1';
		}

	}

	//Ermittlung Sieger
	unsigned int WinnerArray[9][3] = {
		//{Platzierung, Spieler, Punkte}
		{1, 0, 0},							// 1. Paltz
		{2, 0, 0},							// 2. Paltz
		{3, 0, 0},							// 3. Paltz
		{4, 0, 0},							// 4. Paltz
		{5, 0, 0},							// 5. Paltz
		{6, 0, 0},							// 6. Paltz
		{7, 0, 0},							// 7. Paltz
		{8, 0, 0},							// 8. Paltz
		{9, 0, 0},							// 9. Paltz
	};


	unsigned int curMinPoints = 0;		// Maximal hoechste Wuerfelsumme		
	unsigned int curSortPlayer;						// Aktuell zu sortierender Spieler

	for (int indexSort = 0; indexSort < in_NumPlayers; indexSort++)				// Schleife zum Befuellen von WinnerArray		
	{

		for (int curPlayer = 0; curPlayer < in_NumPlayers; curPlayer++)			// Schleife zum Finden der Werte im GameArray
		{
			if (GameArray[curPlayer][6] >= curMinPoints)
			{
				// Speichern Platzierung des Spielers
				WinnerArray[indexSort][1] = GameArray[curPlayer][0];
				// Speichern Punkte des Spielers
				WinnerArray[indexSort][2] = GameArray[curPlayer][6];

				curMinPoints = GameArray[curPlayer][6];
				curSortPlayer = GameArray[curPlayer][0];
			}
		}

		// Ueberschreiben der hoechsten Werten im GameArray
		GameArray[curSortPlayer - 1][6] = 0;
		// Zuruecksetzen von curMinPoints
		curMinPoints = 0;
	}


	// Siegerehrung
	printf("\n_______________________________________________________________\n");
	printf("\n\t\tSpieler %d gewinnt!", WinnerArray[0][1]);
	printf("\n_______________________________________________________________\n");

	printf("\nRangliste:\n\n");
	for (int curPlayer = 0; curPlayer < in_NumPlayers; curPlayer++)
	{
		printf("\t %d. Platz:\tSpieler %d\tPunkte: %d\n", WinnerArray[curPlayer][0], WinnerArray[curPlayer][1], WinnerArray[curPlayer][2]);

	}

	return 0;
}
