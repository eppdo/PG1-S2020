int InputProcessing(unsigned int Stkf, const unsigned int Stk1f, const unsigned int Rabatt1f, const unsigned int Stk2f, const unsigned int Rabatt2f,  const unsigned int Stk3f, const unsigned int Rabatt3f)
{

    // Lokale Variable
   unsigned int Rabatt;

    // Verarbeitung der Eingabe:
    if (Stkf >= Stk1f && Stkf < Stk2f)              // Eingabe >= 10 UND Eingabe < 50
    {
        Rabatt = Rabatt1f;
    }
    else if (Stkf >= Stk2f && Stkf < Stk3f)         // Eingabe >= 50 UND Eingabe < 100
    {
        Rabatt = Rabatt2f;
    }
    else if (Stkf >= Stk3f)                       // Eingabe >= 100
    {
        Rabatt = Rabatt3f;
    }
    else
    {
        Rabatt = 0;                             // Sonstige Eingabe
    }

    return Rabatt;



}



