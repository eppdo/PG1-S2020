#include <stdio.h>

void Print3DArray(void* array, int t_size, int a_size)
{
	void* Element;
	int idx = 0;

	for (int i = 0; i < a_size; i++)
	{
		// Zeilen und Spalten Zuordnung
		if (i % (a_size / 3) == 0 && i != 0)
		{
			printf("\n");
			idx++;
		}

		Element = ((char*)array + ((((i % (a_size / 3)) * 3) + idx) * t_size));

		switch (t_size)
		{
		case 1:	// char
			printf("%c\t", *(char*)Element);
			break;
		case 4:	// int
			printf("%d\t", *(int*)Element);
			break;
		default:	//float, double
			printf("%.3f\t", *(double*)Element);
			break;
		}


	}	// for (int i = 0; i < a_size; i++)

	printf("\n\n");


}	// void printArray3D(void* array, int t_size, int a_size)