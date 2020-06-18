#include <stdio.h>

int main(void)
{
    unsigned int S;
    unsigned int n;

    //unsigned int Register[32] = {0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1 };     // Beispiel Wert 1.282.470.013
    unsigned int Register = 0b01001100011100001111000001111101; // Beispiel Wert 1.282.470.013

    // Eingabge
    printf("Uebung 4 - Aufgabe 4: Bitoperatoren ohne Bedingte Ausfuehrung\n");
    printf("Register Wert (hex):\t%x\n", Register);
    printf("Groesse Register: %d Byte\n\n", sizeof(Register));

    printf("Eingabe Wert S: ");
    scanf_s("%d", &S);

    printf("Eingabe Wert n: ");
    scanf_s("%d", &n);

    // ----------------------------------------------------------------------------------------------------

    // Teilaufgabe 1. Extrahieren
    unsigned int Result1  = Register;

        // Verschieben des gesuchten Bitstrings nach links ( = "abschneiden" der vorangehenden Werte)
        Result1 = Result1 << ((sizeof(Register) * 8) - (S + n));
    
        // Verschieben des gesuchten Bitstrings an Anfang des Registers
        Result1 = Result1 >> ((sizeof(Register) * 8) - n);


    // Ausgabe:
    printf("\nErgebnis Teilaufgabe 1: %x\n", Result1);


    // ----------------------------------------------------------------------------------------------------

    // Teilaufgabe 2. Loeschen - Alles ausser Bitstring
    unsigned int Result2;
    unsigned int DelArea = Register;

    // Vorbereitung: Alle Werte ungleich des gesuchten Bereichs gleich 0 setzen
        // Verschieben des gesuchten Bereichs nach links ( = "abschneiden" der vorangehenden Werte)
        DelArea = DelArea << ((sizeof(Register) * 8) - (S + n));

        // Verschieben des gesuchten Bitstrings an Anfang des Registers
        DelArea = DelArea >> ((sizeof(Register) * 8) - n);

        // Verschieben des gesuchten Bitstrings an die urspruengliche Position (alle anderen Werte = 0)
        DelArea = DelArea << (S);

    // Register XOR DelArea
        Result2 = Register ^ DelArea;

    // Ausgabe:
    printf("\nErgebnis Teilaufgabe 2: %x\n", Result2);


    // ----------------------------------------------------------------------------------------------------


    // Teilaufgabe 3. Loeschen
    unsigned int Result3 = Register;


    // Verschieben des gesuchten Bereichs nach links ( = "abschneiden" der vorangehenden Werte)
    Result3 = Result3 << ((sizeof(Register) * 8) - (S + n));

    // Verschieben des gesuchten Bitstrings an Anfang des Registers
    Result3 = Result3 >> ((sizeof(Register) * 8) - n);

    // Verschieben des gesuchten Bitstrings an die urspruengliche Position (alle anderen Werte = 0)
    Result3 = Result3 << (S);

    // Ausgabe:
    printf("\nErgebnis Teilaufgabe 3: %x\n", Result3);


    // ----------------------------------------------------------------------------------------------------

    // Teilaufgabe 4.  Ersetzen
    unsigned int Result4 = Register;
    unsigned int Z;
    unsigned int zMax = 1;

    zMax = (zMax << n) - 1;

    printf("\nWerte fuer Z zwischen '0' und '%d' moeglich\n", zMax);
    printf("Eingabe Wert Z:");
    scanf_s("%d", &Z);

    // 1. Wie in Teilaufgabe 2: Zu ersetzenden Bereich mit 0 besetzen

        unsigned int DelArea4 = Register;

        // Vorbereitung: Alle Werte ungleich des gesuchten Bereichs gleich 0 setzen
            // Verschieben des gesuchten Bereichs nach links ( = "abschneiden" der vorangehenden Werte)
            DelArea4 = DelArea4 << ((sizeof(Register) * 8) - (S + n));

            // Verschieben des gesuchten Bitstrings an Anfang des Registers
            DelArea4 = DelArea4 >> ((sizeof(Register) * 8) - n);

            // Verschieben des gesuchten Bitstrings an die urspruengliche Position (alle anderen Werte = 0)
            DelArea4 = DelArea4 << S;

            // Register XOR DelArea
            unsigned int interimResult4 = Register ^ DelArea4;


    // 2. Ersetzende Werte auf die gleiche Position verschieben
            Z = Z << S;


    // 3. Zwischenergebnis XOR Z (entspricht einsetzen von Z)
            Result4 = interimResult4 ^ Z;


    // Ausgabe:
    printf("\nErgebnis Teilaufgabe 4: %x\n", Result4);
    

    return 0;
}



