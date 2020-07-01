#include <stdio.h>

unsigned int Fib_b(unsigned int n)
{
	unsigned int f_n2 = 0;
	unsigned int f_n1 = 1;
	unsigned int f_n;

	switch (n)
	{
	case 0:
		f_n = 0;
		break;

	case 1:
		f_n = 1;
		break;

	default:

		for (int i = 2; i <= n; i++)
		{
			// Berechnet f(n) = f(n - 2) + f(n - 1)
			f_n = f_n2 + f_n1;

			// Vorbereitung für naechsten Berechnungsschritt
			f_n2 = f_n1;
			f_n1 = f_n;

		}

		return f_n;
	}

}