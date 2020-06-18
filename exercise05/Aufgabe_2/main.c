#include <stdio.h>

// function: abrunden
float Abrunden(float in, int Rundungsstelle);

int main(void)
{
    unsigned int Einkommen;                         // Euro

    const float Eingangssteuersatz = 5;             // Prozent
    const float MaxSteuersatz = 50;                 // Prozent
    const float Stufensatz = 0.2;                   // Prozent
    const unsigned int Stufenhoehe = 200;           // Euro
    const int EinkommenSteuerfrei = 10000;          // Euro

    float Steuern = 0;                              // Euro
    float Steuersatz = 5;                           // Prozent
    unsigned int VersteuerndesEinkommen;            // Euro


    printf("PG1 Uebung 5: Aufgabe 5 - Schleifen und bedingte Ausfuehrungen\n");
    printf("Eingabe Einkommen [in Euro]: ");
    scanf_s("%d", &Einkommen);

    VersteuerndesEinkommen = Einkommen;

    for (int i = 0; Einkommen > (EinkommenSteuerfrei + i * Stufenhoehe); i++)
    {
        // Einkommen > 10.000 Euro
        if (Einkommen < EinkommenSteuerfrei)
        {
            Steuersatz = 0;
            break;
        }

        // Berechnung Steuersatz: Bei i == 0 -> (1%(i+1)) == 0, bei i >0 -> (1%(i+1)) == 1
        Steuersatz = Steuersatz + (1 % (i + 1)) * Stufensatz;
        printf("Steuersatz: %.2f %%\t", Steuersatz);

        // Berechnung zu versteuerndes Einkommen
        VersteuerndesEinkommen = VersteuerndesEinkommen - (i == 0) * EinkommenSteuerfrei - (i != 0) * Stufenhoehe;

        // Max Steuersatz erreicht:
        if (Steuersatz >= MaxSteuersatz)
        {
            Steuern = Steuern + VersteuerndesEinkommen * Steuersatz / 100;                 
            printf("Steuern: %.2f Euro\t", Steuern);
            Steuern = Abrunden(Steuern, 2);
            break;
        }

        // Berechnung Steuern:
        if (VersteuerndesEinkommen > Stufenhoehe)
        {
            Steuern = Steuern + Stufenhoehe * Steuersatz / 100;

        }
        else if (VersteuerndesEinkommen >= 0 && VersteuerndesEinkommen <= Stufenhoehe)
        {
            Steuern = Steuern + VersteuerndesEinkommen * Steuersatz / 100;
        }
        else
        {
            return 1;       // Game Over
        }


        
        printf("Steuern: %.2f Euro\t", Steuern);
        Steuern = Abrunden(Steuern, 2);
    }


    // Ausgabe
    printf("\nDas Einkommen betraegt: %d Euro\n\tZu Zahlende Steuern: \t\t\t%d Euro\n\tDer maximale Steuersatz betraegt: \t%.1f %%\n", Einkommen, (int)Steuern, Steuersatz);

    

    return 0;
}


