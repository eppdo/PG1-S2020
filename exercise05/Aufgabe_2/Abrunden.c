#include <math.h>
#include <stdio.h>

float Abrunden(float in, int Rundungsstelle)
{
	float out;

	out = floorf(in * pow(10, Rundungsstelle)) / pow(10, Rundungsstelle);
	//printf("Gerundet: %.2f\n", out);


	return out;
}
