#include <stdio.h>

// struct
struct v
{
	double x;
	double y;
	double z;
};

void func(void* a, void* b, void* ab, int t_size)
{
	for (int i = 0; i < 3; i++)
	{
		*(double*)((char*)ab + i * t_size) = (*(double*)((char*)a + i * t_size) + *(double*)((char*)b + i * t_size));
	}
}

int main(void)
{
	printf("Probeklausur PG1 - Sommersememster 2020: Aufgabe 3\n");
	printf("Komplexe Datentypen:\n");

	// init vector v1
	struct v v1;
	v1.x = 1;
	v1.y = 4;
	v1.z = 7;

	// init vector v2
	struct v v2;
	v2.x = 9;
	v2.y = 8;
	v2.z = 7;

	// init result vector v3
	struct v v3;
	v3.x = 0;
	v3.y = 0;
	v3.z = 0;

	func(&v1, &v2, &v3, sizeof(double));

	// show result
	printf("\nv1\t+\tv2\t=\tv3\n\n");
	printf("%.f\t \t%.f\t \t%.f\n", v1.x, v2.x, v3.x);
	printf("%.f\t+\t%.f\t=\t%.f\n", v1.y, v2.y, v3.y);
	printf("%.f\t \t%.f\t \t%.f\n", v1.z, v2.z, v3.z);


	return 0;
}