#include <stdio.h>
#include <math.h>

int main(void)
{
// Aufgabe 1
// a)
    // i.
        double x;
        double erg_i;

        // Initialisierung
        x = 5;
    
        // Berechnung
        erg_i = pow(x, 2) + 3 * 5 + 17;

        printf("Aufgabe 1 a) - i: \t x^2+3x+17\n\tmit: x = %i \n\tx^2+3x+17= %i\n\n", x, erg_i);

        // --------------------------------------------------------------------------------------

    // ii.
        double a, b, c, d, erg_ii;

        // Initialisierung:
        a = 1;
        b = 2;
        c = 3;
        d = 4;

        // Berechnung:
        erg_ii = (a - 3) / (b + 2 * (c / (pow(d + 3, 3))));
        printf("Aufgabe 1 a) - ii: \n\tErgebnis: %f\n\n", erg_ii);

        // --------------------------------------------------------------------------------------

// b - 3 * (a <= b)

    int ab, bb, erg_b;

    // Initialisierung:
    ab = 1;
    bb = 2;

    // Berechnung:
    erg_b = 3 * (ab <= bb);
    printf("Aufgabe 1 b): 3 * (a <= b) \n\tErgebnis: %i\n\n", erg_b);

    // --------------------------------------------------------------------------------------

// c  - overflow

    unsigned short a_max, erg_c;

        // Initialisierung:
    a_max = 65535;      // 2^16-1

    // Berechnug:
    erg_c = a_max + 1;
    printf("Aufgabe 1 c):\n\tErgebnis (overflow short): a + 1 \n\tmit a = %i\n\tErgebnis = %i\n\n", a_max, erg_c);

    // --------------------------------------------------------------------------------------

// d -div/0 integer

    int ad, varZero, erg_d1, erg_d2;
    const int constZero = 0;

    // Initialisierung:
    ad = 1;
    varZero = 0;

    // Berechnung:
        //erg_d1 = ad / constZero;
        //printf("Aufgabe 1 d) - Teil1:\n\tDivision durch 0 (konstant):\n\tErgebnis: %i", erg_d1);

        //erg_d2 = ad / varZero;
        //printf("Aufgabe 1 d) - Teil2:\n\tDivision durch 0 (variabel):\n\tErgebnis: %i", erg_d2);

    // --------------------------------------------------------------------------------------

// e -div/0 float

    float ae, floatZero, erg_e1, erg_e2;
    const float constZero_float = 0.00;


    // Initialisierung:
    ae = 1;
    floatZero = 0.0;

    // Berechnung:
    erg_e1 = ae / constZero_float;
    printf("Aufgabe 1 e) - Teil1:\n\tDivision durch 0 (konstant) : \n\tErgebnis: %f\n\n", erg_e1);
    erg_e2 = ae / floatZero;
    printf("Aufgabe 1 e) - Teil2:\n\tDivision durch 0 (variabel) : \n\tErgebnis: %f", erg_e2);   


    return(0);
}


