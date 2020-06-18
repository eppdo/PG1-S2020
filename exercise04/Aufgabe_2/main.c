#include <stdio.h>

// Function: Input aufnehmen
int InputCall(char* dateInput);

// Function: Input validieren
int InputCheck(unsigned int tag, unsigned int m, unsigned int j);


int main()
{
    unsigned int w;             // Wochentag - Gesucht
    unsigned int tag;           // Tag
    unsigned int m;             // Monat
    unsigned int j;             // Jahr

    int flagInputVal;           // Überprüfungsflag für die Inputvalidierung

    // Eingabe
    printf("Eingabe eines Datums zur Ermittlung des Wochentages:\n");

        // Tag:
        tag = InputCall("Tag"); 

        // Monat:
        m = InputCall("Monat");            
        unsigned int monat = m;     // Merker (workaround für Monat <= 2)

        // Jahr:
        j = InputCall("Jahr");
        unsigned int jahr = j;

        // Input Validation
        flagInputVal = InputCheck(tag, m, j);

        if (flagInputVal != 0)
        {
            printf("\n Wochentag kann nicht berechnet werden!\n");
            return 1;     // Game Over
        }

        printf("\n---------------------------------\n");

    // Verarbeitung: Berechnung des Wochentages
        // Anpassung Monat und Jahr:
        if (m <= 2) 
        {
            m = m + 12;
            j = j - 1;
        }

        w = (tag + 2 * m + (3 * m + 3) / 5 + j + j / 4 - j / 100 + j / 400 + 1) % 7;


        // Ausgabe
        printf("\nDer %d.%d.%d ist ein ", tag, monat, jahr);


        switch (w) 
        {
            case 0: printf("Sonntag\n"); break;
            case 1: printf("Montag\n"); break;
            case 2: printf("Dienstag\n"); break;
            case 3: printf("Mittwoch\n"); break;
            case 4: printf("Donnerstag\n"); break;
            case 5: printf("Freitag\n"); break;
            case 6: printf("Samstag\n"); break;
        default: printf(" - "); break;

        }

return 0;

}


