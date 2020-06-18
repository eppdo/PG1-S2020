#include <stdio.h>

// function: Input auffuellen (Wenn Eingabe < 8 zeichen)
unsigned char* InputFill(unsigned char* in);

// function: Input Validierung (Eingabe besteht nur aus Zeichen 0 und 1)
int InputValidation(unsigned char* in);

// function: Addition
unsigned char Addition(unsigned char in1, unsigned char in2, unsigned int i);

// function: Bin -> Dec
unsigned short int ConvertBinToDec(unsigned char actChar,  int m);

int main(void)
{
 
    // Eingangswerte:              
    unsigned char in1[9];       // max 8 Zeichen
    unsigned char* in1p;
    unsigned char in2[9];       // max 8 Zeichen
    unsigned char* in2p;

    // Ausgabewert:
    unsigned char out[9] = " ";       // max 8 Zeichen

    // Validierungsflag
    unsigned int flagValidation;
    

    printf("Aufgabe 3: Bitoperatoren und bedingte Anweisung\n");
 
    // Eingabe Wert 1:
    printf("Eingabe Wert 1: ");
    scanf_s("%8s", in1, 9);         // 8 Zeichen String + \0 als abschliessendes Zeichen

        // Überprüfung der Eingangswerte
        flagValidation = InputValidation(in1);

            // Fehlerhafte Eingabe
            if (flagValidation == 1)
            {
                return 1;       // Game over
            }

        // Bei weniger als 8 Zeichen: Korrektur  des Strings
        in1p = InputFill(in1);

            // Zuweisung Wert von Pointer auf Variable (Pointer verweist auf statischen Wert in Funktion)
            for (int j = 0; j <= 8; j++)
            {
                in1[j] = in1p[j];
            }

    
    // Eingabe Wert 2:
    printf("Eingabe Wert 2: ");
    scanf_s("%8s", in2, 9);

        // Überprüfung der Eingangswerte
        flagValidation = InputValidation(in2);

            // Fehlerhafte Eingabe
            if (flagValidation == 1)
            {
                return 1;       // Game over
            }

        // Bei weniger als 8 Zeichen: Korrektur  des Strings
        in2p = InputFill(in2);

            // Zuweisung Wert von Pointer auf Variable (Pointer verweist auf statischen Wert in Funktion)
            for (int k = 0; k <= 8; k++)
            {
                in2[k] = in2p[k];
            }

        // Ausgabe der eingegebenen Werte:
        printf("\n\tWert 1 = \t%s\n\tWert 2 = \t%s\n", in1, in2);


        // Addition der Werte
        for (int i = 7; i >= 0; i--)
        {
            out[i] = Addition(in1[i], in2[i], i);

                if (out[i] == 'X')
                {
                    printf("Fehler! - Maximale Darstellbarkeit überschritten\n");
                    return 1;
                    break;

                }
                else if (out[i] == 'Y')
                {
                    printf("Fehler! - Irgendein Fehler :-| \n");
                    return 1;

                }
        }


    // Ausgabe eingegebene Werte:
        printf("\n\tErgebnis:\t%s\n", out);

        unsigned short int Result = (short int)out;
        printf("Ergebnis als short: %d\n", Result);

    // Umwandlung Ergebnis dezimal
        unsigned short int ResultDec = 0;
        for (int m = 7; m >= 0; m--)
        {
            ResultDec = ResultDec + ConvertBinToDec(out[m], m);
                //(unsigned char actChar, unsigned short int result, int m)
        }

        printf("Ergebnis (dec):\t%d\n", ResultDec);



    return 0;
}


