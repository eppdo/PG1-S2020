// PG1 Uebungsblatt 10 - Aufgabe 1: Fibonacci Zahlen
#include <stdio.h>

// function: Fibonacci (mit Rekursion) - a
unsigned int Fib_a(unsigned int n);

// function: Fibonacci (ohne Rekursion) - b
unsigned int Fib_b(unsigned int n);


int main(void)
{

	unsigned int n = 0;							// Startwert
	unsigned int result_a;						// Ergebnis a)
	unsigned int result_b;						// Ergebnis b)

	// Header
	printf("PG1 Uebungsblatt 10 - Aufgabe 1: Rekursion - Fibonacci-Zahlen\n\n");


		// Eingabe von n zur Berechnung der Fibonacci-Zahl f(n)
		printf("\nBerechnung Fibonacci\nEingabe von n:\t");
		scanf_s("%u", &n);

		// Aufgabe 1a)	-	Berechnung von f(n) mittels Rekursion
		result_a = Fib_a(n);

		// Ausgabe Aufgabe 1a)
		printf("\nAufgabe 1 a) - Mit Rekursion\n");
		printf("\nFibonacci:\nn\t->\t%u\t\tf(n)\t->\t%u\n\n", n, result_a);


		// Aufgabe 1b)	-	Berechnung von f(n) ohne Rekursion (iterativ)
		result_b = Fib_b(n);

		// Ausgabe Ausgabe 1b)
		printf("\nAufgabe 1 b) - Ohne Rekursion\n");
		printf("\nFibonacci:\nn\t->\t%u\t\tf(n)\t->\t%u\n\n", n, result_b);


}