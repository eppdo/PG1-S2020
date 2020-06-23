void MatAdd3x3(int* ab, int* bb, int idx, int* erg_B)
{
	while (idx >= 1)
	{
		erg_B[idx - 1] = ab[idx - 1] + bb[idx - 1];
		idx--;
	}

}