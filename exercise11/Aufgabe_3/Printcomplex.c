#include <math.h>
#include <stdio.h>

void PrintComplex(void* array, int t_size, int a_size)
{
	for (int i = 0; i < a_size; i+=2)
	{
		float Re = *(float*)((char*)array + i * t_size);									// Real-Teil
		float Im = *(float*)((char*)array + ((i + 1) * t_size));							// Imaginaer-Teil
		printf("Re: %f\tIm: %f\t|c|: %f\n", Re, Im, sqrt(pow(Re, 2) + pow(Im, 2)));			
	}
	printf("\n\n");
}