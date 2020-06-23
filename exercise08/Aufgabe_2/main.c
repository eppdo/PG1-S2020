#include <stdio.h>

#define MaxMember 10			// Maximale Anzahl an Mitglieder
#define MaxChar 30			// Maximale Anzahl an Zeichen bei der Eingabe von char
#define MaxNbr 6			// Maximale Anzahl an Zeichen bei der Eingabe von Zahlen (Hausnr., PLZ)


int main(void)
{
	// char Array: Vornamen
	char FNameArr[MaxMember][MaxChar];

	// char Array: Nachnamen
	char LNameArr[MaxMember][MaxChar];

	// char Array: Strasse
	char StreetArr[MaxMember][MaxChar];

	// char Array: Hausnummer
	char HouseNbrArr[MaxMember][MaxChar];

	// char Array: Postleitzahl
	char ZipCodeArr[MaxMember][MaxChar];

	// char Array: Stadt
	char CityNameArr[MaxMember][MaxChar];



	// Summe der eingetragenen Mitglieder
	int SumMember = 0;

	// Auswahl der Funktion
	unsigned int flagFunction;

	// flag zum Beenden des Programms
	char flagShutDown = '0';

	// Liste mit belegten Plaetzen in der Mitgliederliste
	// 0 = false -> Freier Platz | 1 = true -> Platz belegt
	_Bool FreeMemberListPlace[MaxMember] = { 0 };

	// Laufvariable fuer belegeten Platz in FreeMemberPlace
	int idxMember = 0;

	// Freier Platz auf Mitgliederliste
	int FreeSpot = 0;




	// Headline
	printf("PG1 Uebungsblatt 8 - Aufgabe 2: Felder und Zeichenketten\n");
	printf("\n\tMitgliederverwaltung\n\n");


	while (flagShutDown == '0')
	{

		// Aufruf Menue
		//flagFunction = Menu(SumMember, MaxMember);



		printf("\n\nDerzeitige Mitgliederzahl:\t[%u/%d]\n\n", SumMember, MaxMember);
		printf("Was wollen Sie tun?\n\n");
		printf("\t[1]\tNeues Mitglied anlegen\n");

		if (SumMember > 0)												// Menuepunkte nur anzeigen, wenn breits ein Mitglied angelegt ist
		{
			printf("\t[2]\tEin bestimmtes Mitglied anzeigen\n");
			printf("\t[3]\tAlle Mitglieder anzeigen\n");
			printf("\t[4]\tEin bestimmtes Mitglied loeschen\n");
		}

		printf("\nSonstige Eingabe beendet das Programm!\n");

		printf("\nAuswahl: ");
		scanf_s("%d", &flagFunction);



		switch (flagFunction)
		{
		case 1:		// Neues Mitglied anlegen

			if (SumMember >= MaxMember)						// Pruefen ob maximale Anzahl an Mitglieder erreicht ist
			{
				printf("Maximale Anzahl an Mitglieder erreicht!\n");
				break;
			}


			printf("\nNeues Mitglied anlegen:\n\n");

			// Freien Platz auf der Liste finden
			for (int idxList = 0; idxList < 10; idxList++)
			{
				if (FreeMemberListPlace[idxList] == 0)
				{
					FreeSpot = idxList;
					break;
				}
			}


			// Eingabe Vorname
			printf("\tVorname:\t");
			scanf_s(" %s", &FNameArr[FreeSpot][0], MaxChar);

			// Eingabe Nachname
			printf("\tNachname:\t");
			scanf_s(" %s", &LNameArr[FreeSpot][0], MaxChar);

			// Eingabe Strasse
			printf("\tStrasse:\t");
			scanf_s(" %s", &StreetArr[FreeSpot][0], MaxChar);

			// Eingabe Hausnummer
			printf("\tHausnummer:\t");
			scanf_s(" %s", &HouseNbrArr[FreeSpot][0], MaxNbr);

			// Eingabe Postleitzahl
			printf("\tPostleitzahl:\t");
			scanf_s(" %s", &ZipCodeArr[FreeSpot][0], MaxNbr);

			// Eingabe Stadt
			printf("\tStadt:\t\t");
			scanf_s(" %s", &CityNameArr[FreeSpot][0], MaxChar);


			// Zaehler fuer die gesamte Anzahl der eingetragenen Mitglieder um 1 erhoehen
			SumMember++;

			// Platz auf Liste als belegt markieren
			FreeMemberListPlace[FreeSpot] = 1;

			break;

			// ---------------------------------------------------------------------------------------------

		case 2:	// Ein bestimmtes Mitglied anzeigen

			printf("Mitgliederliste:\n");
			for (int i = 0; i < SumMember; i++)
			{
				printf("\t[%d] - Mitglied #%d\n", i, i);
			}

			unsigned int flagMember;

			printf("\nWelches Mitglied soll angezeigt werden?\n");
			printf("\nAuswahl: ");
			scanf_s("%u", &flagMember);

			// Anzeige Mitglied
			printf("\nMitglied #%d\n", flagMember);

			printf("\n");
			// Vor- und Nachname
			printf("\t%s %s\n", (char*)&FNameArr[flagMember][0], (char*)&LNameArr[flagMember][0]);

			// Strasse und Hausnummer
			printf("\t%s %s\n", (char*)&StreetArr[flagMember][0], (char*)&HouseNbrArr[flagMember][0]);

			// PLZ und Stadt
			printf("\t%s %s\n", (char*)&ZipCodeArr[flagMember][0], (char*)&CityNameArr[flagMember][0]);

			printf("\n");

			break;

			// ---------------------------------------------------------------------------------------------

		case 3:		// Alle Mitglieder anzeigen

			idxMember = 0;

			printf("Mitgliederliste:\n");
			printf("\n\nDerzeitige Mitgliederzahl:\t[%u/%d]\n\n", SumMember, MaxMember);


			for (int i = 0; i < sizeof(FreeMemberListPlace); i++)					// Alle Mitglieder nacheinander ausgeben
			{
				if (FreeMemberListPlace[i] == 1)
				{
					printf("\tMitglied #%d\n\n", idxMember);

					printf("\n");
					// Vor- und Nachname
					printf("\t%s %s\n", (char*)&FNameArr[idxMember][0], (char*)&LNameArr[idxMember][0]);

					// Strasse und Hausnummer
					printf("\t%s %s\n", (char*)&StreetArr[idxMember][0], (char*)&HouseNbrArr[idxMember][0]);

					// PLZ und Stadt
					printf("\t%s %s\n", (char*)&ZipCodeArr[idxMember][0], (char*)&CityNameArr[idxMember][0]);

					printf("\n\n");
				}

				idxMember++;


			}
			break;

			// ---------------------------------------------------------------------------------------------

		case 4:					// Einzelnes Mitglied aus Verwaltung entfernen

			printf("Mitgliederliste:\n");
			for (int i = 0; i < SumMember; i++)
			{
				printf("\t[%d] - Mitglied #%d\n", i, i);
			}

			printf("\nWelches Mitglied soll angezeigt werden?\n");
			printf("\nAuswahl: ");
			scanf_s("%u", &flagMember);


			// overwrite memory - Speicher ueberschreiben 

			for (int i = 0; i < MaxChar; i++)
			{
				if (i == (MaxChar - 1))						// letztes Zeichen / sollte nicht notwendig sein
				{
					FNameArr[flagMember][i] = '\0';
					LNameArr[flagMember][i] = '\0';
					StreetArr[flagMember][i] = '\0';
					CityNameArr[flagMember][i] = '\0';
				}
				else
				{
					FNameArr[flagMember][i] = ' ';
					LNameArr[flagMember][i] = ' ';
					StreetArr[flagMember][i] = ' ';
					HouseNbrArr[flagMember][i] = ' ';
					ZipCodeArr[flagMember][i] = ' ';
					CityNameArr[flagMember][i] = ' ';
				}


				if (i < MaxNbr)								// Ueberschreiben von Hausnr. und PLZ 
				{											// (weniger Speicher als die anderen Arrays)
					if (i == (MaxNbr - 1))
					{
						HouseNbrArr[flagMember][i] = '\0';
						ZipCodeArr[flagMember][i] = '\0';
					}
					else
					{
						HouseNbrArr[flagMember][i] = ' ';
						ZipCodeArr[flagMember][i] = ' ';
					}

				}


			}	// (int i = 0; i < MaxChar; i++)


			SumMember--;								// Zaehler fuer die Gesamtanzahl um eins verringern
			FreeMemberListPlace[flagMember] = 0;		// Platz auf Belegungsliste freigeben


			break;
			// ---------------------------------------------------------------------------------------------
		default:
			return 0;		// Game Over: Prgm wird beendet
			break;
		}



		printf("\nWeiter mit Eingabe '0':\nAbbruch mit sonstiger Eingabe\n");
		printf("\nEingabe:\t");

		if ((scanf_s(" %c", &flagShutDown)) != 1)
		{
			return 1;		// Game Over: Prgm wird beendet
		}





	}	// while (flagShutDown == 0)





	return 0;
}