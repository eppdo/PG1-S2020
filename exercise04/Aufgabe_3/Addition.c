unsigned char Addition(unsigned char in1, unsigned char in2, unsigned int i)
{
    // Merkervariable: Uebertrag
    static unsigned char flagTransfer[2];
        
        // Für ersten Durchlauf: Setzen von Merkervariable auf 0
        if (flagTransfer[0] == '\0')
        {
            flagTransfer[0] = '0';
        }

    // Ausgabewert:
    unsigned char out[2];


        // in1 = 0; in2 = 0; Ubertrag = 0
        if (in1 == '0' && in2 == '0' && flagTransfer[0] == '0')
        {
            out[0] = '0';

        }

        // in1 = 0; in2 = 0; Ubertrag = 1
        else if (in1 == '0' && in2 == '0' && flagTransfer[0] == '1')
        {
            out[0] = '1';
            flagTransfer[0] = '0';

        }

        // in1 = 1; in2 = 0; Ubertrag = 0 ODER in1 = 0; in2 = 1; Ubertrag = 0
        else if (in1 == '1' && in2 == '0' && flagTransfer[0] == '0' || in1 == '0' && in2 == '1' && flagTransfer[0] == '0')
        {
            out[0] = '1';

        }

        // in1 = 1; in2 = 0; Ubertrag = 1 ODER in1 = 0; in2 = 1; Ubertrag = 1
        else if (in1 == '1' && in2 == '0' && flagTransfer[0] == '1' || in1 == '0' && in2 == '1' && flagTransfer[0] == '1')
        {
            out[0] = '0';
            flagTransfer[0] = '1';

        }

        // in1 = 1; in2 = 1; Ubertrag = 0
        else if (in1 == '1' && in2 == '1' && flagTransfer[0] == '0')
        {
            out[0] = '0';
            flagTransfer[0] = '1';

        }

        // in1 = 1; in2 = 1; Ubertrag = 1
        else if (in1 == '1' && in2 == '1' && flagTransfer[0] == '1')
        {
            out[0] = '1';
            flagTransfer[0] = '1';

        }

        // Sonstiger Fehler
        else
        {
            return 'Y';
        }


    // Abfrage ob die max Darstellbarkeit von 8 Bit erreicht wird
    if (i == 0 && flagTransfer[0] == '1') 
    {
        return 'X';         // Game over
    }
    else
    {
        return out[0];      // passt
    }

    
}
