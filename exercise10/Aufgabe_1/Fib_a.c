#include <stdio.h>

unsigned int Fib_a(unsigned int n)
{
	if (n == 0 || n == 1)
	{
		return n;
	}
	else
	{
		return Fib_a(n - 2) + Fib_a(n - 1);
	}

}