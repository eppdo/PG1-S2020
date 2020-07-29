#include <stdio.h>


// Fibonacci (rekursiv)
int fib(int n)
{
	if (n != 0	&&	n != 1)
	{
		n = fib(n - 2) + fib(n - 1);
	}

	return n;
}

// Fibonacci (iterativ
int fib_it(int n)
{
	int out = 1;
	int n1 = 0;
	int n2 = 0;

	// Fibonacci Zahlen
	// n			0	1	2	3	4	5	6	7	8	...
	// fib(n)		0	1	1	2	3	5	8	13	21	...

	if (n == 0 || n == 1)
	{
		out = n;
	}
	else
	{
		for (int i = 2; i <= n; i++)
		{
			n2 = n1;			// n2	=	fib(n-2)				
			n1 = out;			// n1	=	fib(n-1)

			out = n1 + n2;		// out	=	fib(n)


		}
	}
	

	return out;
}


int main(void)
{
	printf("Probeklausur PG1 - Sommersememster 2020: Aufgabe 2\n");
	printf("Rekursion (Fibonacci):\n");

	// Eingabe 
	int inp = 0;

	printf("Eingabe: ");
	scanf_s("%d", &inp);

	// a)	rekursiv
	int n_rekursiv = fib(inp);

	// b) iterativ
	int n_iterativ = fib_it(inp);

	printf("Fibonacci Zahl:\t%d\t(rekursiv)\n", n_rekursiv);
	printf("Fibonacci Zahl:\t%d\t(iterativ)\n", n_iterativ);




	return 0;
}