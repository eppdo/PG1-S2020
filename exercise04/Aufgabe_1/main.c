#include <stdio.h>

// InputProcessing function: Zur Verarbeitung der Eingabewerte
int InputProcessing(unsigned int Stkf, const unsigned int Stk1f, const unsigned int Rabatt1f, const unsigned int Stk2f, const unsigned int Rabatt2f, const unsigned int Stk3f, const unsigned int Rabatt3f);



int main(void)
{
    unsigned int Stk;
    float Preis;
    float Rabatt;
    float GesPreis;
    float PreisDiff;

    const float StkPreis = 0.80;       // Stückpreis je DVD-Rohling: 0,80 Euro

    const unsigned int Stk1 = 10;      // Stückzahl für Rabattstufe 1
    const unsigned int Rabatt1 = 3;           // 3 Prozent

    const unsigned int Stk2 = 50;      // Stückzahl für Rabattstufe 2
    const unsigned int Rabatt2 = 5;           // 5 Prozent

    const unsigned int Stk3 = 100;     // Stückzahl für Rabattstufe 3
    const unsigned int Rabatt3 = 8;           // 8 Prozent

    // Textausgabe
    printf("DVD-Rohling Verkauf: Kosten pro Stueck 0,80 Euro\n");
    printf("Rabatt:\tAb 10 Stk\t->\t3 %%\n\tAb 50 Stk\t->\t5 %%\n\tAb 100 Stk\t->\t8 %%\n\n");
    printf("Anzahl DVD-Rohlinge: ");

    // Eingabe:
    scanf_s("\n%d", &Stk);

    // Check das Stückzahl positiv ist:
    Stk = abs(Stk);

    // Verarbeitung der Eingabe:
    Rabatt = InputProcessing(Stk, Stk1, Rabatt1, Stk2, Rabatt2, Stk3, Rabatt3);

    // Berechnung Preis ohne Rabatt:
    Preis = Stk * StkPreis;

    // Berechnung Preis mit Rabatt:
    GesPreis = Preis * (1 - Rabatt / 100);

    // Berechnung Preisdifferenz:
    PreisDiff = Preis - GesPreis;



    // Ausgabe:
    // Anmerkung -> z.B. %.02f rundet auf 2 Nachkommastellen
    printf("--------------------------------------------------------------------------");
    printf("\nGewaehlte Anzahl DVD-Rohlinge:\t\t%d Stk\n", Stk);
    printf("Preis ohne Rabatt:\t\t\t%.2f Euro\n", Preis);


    if (PreisDiff != 0)
    {
        printf("Reduzierter Preis mit %.0f %% Rabatt:\t%.2f Euro\n", Rabatt, GesPreis);
        printf("\nGespart: %.2f Euro\n", PreisDiff);
    }



    return 0;

}
