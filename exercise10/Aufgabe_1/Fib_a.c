#include <stdio.h>

unsigned int Fib_a(unsigned int n)
{
	// Rueckgabewert
	unsigned int out;

	if (n == 0 || n == 1)
	{
		out = n;
	}
	else
	{
		//return Fib_a(n - 2) + Fib_a(n - 1);
		out = Fib_a(n - 2) + Fib_a(n - 1);
	}

	return out;

}