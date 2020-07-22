#include <math.h>

void swap(void* a, void* b, int t_size);

int compare_complex(const void* a, const void* b)
{
	// Betrag Komplexe Zahl = Wurzel aus (Re^2 + Im^2)

	// Komplexe Zahl 1
	float Re1 = *(float*)a;
	float Im1 = *(float*)((char*)a + sizeof(float));

		// Betrag von komplexer Zahl 1
		float abs1 = sqrt(pow(Re1, 2) + pow(Im1, 2));

	// Komplexe Zahl 2:
	float Re2 = *(float*)b; 	
	float Im2 = *(float*)((char*)b + sizeof(float));

		// Betrag von komplexer Zahl 2
		float abs2 = sqrt(pow(Re2, 2) + pow(Im2, 2));

	// Skalierungsfaktor zur Erhoehung der Genauigkeit bei Typcast zu int
	int sF = 1000;

	int retValue = (int)(sF * abs1 - sF * abs2);
	return retValue;
}