void VecAdd(int* a, int* b, int idx, int* erg_C)
{
	while (idx >= 1)
	{
		erg_C[idx - 1] = a[idx - 1] + b[idx - 1];
		idx--;
	}

}

