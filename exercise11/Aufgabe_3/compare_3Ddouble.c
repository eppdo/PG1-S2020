#include <math.h>

int compare_3Ddouble(const void* a, const void* b)
{
	// Wurzel aus (x^2 + y^2 + z^2)
	// Vector a
	void* ax = (double*)((char*)a);									// X-Komponente Vector 1
	void* ay = (double*)((char*)a + sizeof(double));				// Y-Komponente Vector 1
	void* az = (double*)((char*)a + (2 * sizeof(double)));			// Z-Komponente Vector 1

	// Betrag von Vector 1
	double abs1 = sqrt(pow(*(double*)ax, 2) + pow(*(double*)ay, 2) + pow(*(double*)az, 2));		

	// Vector b
	void* bx = (double*)((char*)b);									// X-Komponente Vector 2
	void* by = (double*)((char*)b + sizeof(double));				// Y-Komponente Vector 2
	void* bz = (double*)((char*)b + (2 * sizeof(double)));			// Z-Komponente Vector 2

	// Betrag von Vector 2
	double abs2 = sqrt(pow(*(double*)bx, 2) + pow(*(double*)by, 2) + pow(*(double*)bz, 2));		

	//return (int)(*(double*)&abs1 - *(double*)&abs2);
	return (int)(abs1 - abs2);
}