void VecAdd3D(int* a, int* b, int* erg_A)
{
	for (int i = 0; i < 3; i++)
	{
		erg_A[i] = a[i] + b[i];
	}
}