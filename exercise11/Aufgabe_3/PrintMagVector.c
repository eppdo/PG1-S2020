#include <math.h>

void PrintMagVector(void* a, int t_size, int a_size)
{
	printf("Betrag der Vectorn:\n");
	for (int i = 0; i < a_size / 3; i++)
	{
		double ax = *(double*)((char*)a + ((i * 3) * t_size));
		double ay = *(double*)((char*)a + (((i * 3) + 1) * t_size));
		double az = *(double*)((char*)a + (((i * 3) + 2) * t_size));

		double magnitude = sqrt(pow(ax, 2) + pow(ay, 2) + pow(az, 2));

		printf("%.1f\t", magnitude);
	}

	printf("\n\n");
}