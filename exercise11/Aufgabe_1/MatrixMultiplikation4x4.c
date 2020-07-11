void MatrixMultiplikation4x4(int* M1ptr, int* M2ptr, int* ErgMatPtr)
{
	// Matrixmultiplikation -> "Zeile * Spalte"

	int RowM1 = 0;				//	Zeile aus Matrix 1
	int NewRow = 0;				//	Beginn neuer Zeile in Ergebnismatrix
	int ColM2 = 0;				//	Spalte aus Matrix 2
	int Sum = 0;				//	Summe aus "Zeile * Spalte"

	// Berechnen aller Elemente in Ergebnismatrix
	for (int i = 0; i < 16; i++)
	{
		Sum = 0;						// Zuruecksetzen von Summe aus "Zeile * Spalte" fuer neues Element

		if (i % 4 == 0 && i != 0)		// Neue Zeile in Ergebnismatrix
		{
			NewRow++;
		}
		RowM1 = NewRow * 4;
		ColM2 = i % 4;					// Zurueck zu Spalte 0 in Matrix 2


		// Berechne Summe aus Multiplikation aus Zeile * Spalte
		for (int j = 0; j < 4; j++)
		{
			Sum += (*(M1ptr + RowM1) * *(M2ptr + ColM2));

			RowM1++;
			ColM2 += 4;			// Naechste Spalte in Matrix 2
		}


		*(ErgMatPtr + i) = Sum;
	}
}
