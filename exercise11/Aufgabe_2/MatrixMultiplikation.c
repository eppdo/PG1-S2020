void MatrixMultiplikation(int* M1ptr, int* M2ptr, int* ErgMatPtr, int MRow, int MCol, int M1Col2Row)
{
	// Matrixmultiplikation -> "Zeile * Spalte"

	int RowM1 = 0;				//	Zeile aus Matrix 1
	int NewRow = 0;				//	Beginn neuer Zeile in Ergebnismatrix
	int ColM2 = 0;				//	Spalte aus Matrix 2
	int Sum = 0;				//	Summe aus "Zeile * Spalte"

	// Berechnen aller Elemente in Ergebnismatrix
	for (int i = 0; i < (MCol * MRow); i++)
	{
		Sum = 0;						// Zuruecksetzen von Summe aus "Zeile * Spalte" fuer neues Element

		if (i % MCol == 0 && i != 0)		// Neue Zeile in Ergebnismatrix
		{
			NewRow++;
		}
		RowM1 = NewRow * M1Col2Row;
		ColM2 = i % MCol;					// Zurueck zu Spalte 0 in Matrix 2


		// Berechne Summe aus Multiplikation aus Zeile * Spalte
		for (int j = 0; j < M1Col2Row; j++)
		{
			Sum += (*(M1ptr + RowM1) * *(M2ptr + ColM2));

			RowM1++;
			ColM2 += MCol;			// Naechste Spalte in Matrix 2
		}


		*(ErgMatPtr + i) = Sum;
	}
}
