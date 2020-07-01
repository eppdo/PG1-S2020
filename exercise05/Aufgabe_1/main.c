#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;
    unsigned int i = 0;
    unsigned int f = 0;

    printf("PG1 Uebung 5 - Aufgabe 1\n");
    printf("Eingabe des Endwertes n: ");
    // Ueberpruefung ob die Eingabe eine Zahl ist
        if (scanf_s("%d", &n) != 1 )
        {
            printf("Fehler! - Falsche Eingabe: Es sind nur positive Zahlen als Eingabe erlaubt\n");
            return 1;       // Game over
        }

    // Ueberpruefung ob die Eingabe eine positive Zahl ist
        if (n < 0)
        {
            printf("Fehler! - Falsche Eingabe: Es sind nur positive Zahlen als Eingabe erlaubt\n");
            return 1;       // Game Over
        }
        else
        {
            printf("n = %d\n", n);
        }

    // Verarbeitung der Eingabe
    for (i; i <= n; i++)
    {
        // Hilfsgroesse fuer overflow check
        unsigned int f_prev = f;

        // Berechnung f
        f = f + (2 * i + 3)*100000000;
        f = f + (2 * i + 3);

            // Overflow Abfrage: Wenn der Vorherige Wert > aktuelle Wert -> overflow
            if (f_prev > f)
            {
                printf("Overflow! - Maximale Darstellbarkeit erreicht!\n");
                return 1;
            }
            else
            {
                printf("\tSchritt %d/%d: Zwischenergebnis f = %u\n", i, n, f);      // %u fuer Ausgabe unsigned int
            }



    }


    // Ausgabe:
    printf("\nErgebnis der Summenberechnung: f = %d", f);


    return 0;
}


