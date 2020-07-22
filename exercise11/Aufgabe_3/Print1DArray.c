#include <stdio.h>

void Print1DArray(void* array, int t_size, int a_size)
{
	for (int i = 0; i < a_size; i++)
	{
		switch (t_size)
		{
		case 1:
			printf("%c\t", *((char*)array + (i * t_size)));
			break;
		case 4:
			printf("%d\t", *((char*)array + (i * t_size)));
			break;
		default:
			printf("%f\t", *((char*)array + (i * t_size)));
			break;
		}		 

	}
	
	printf("\n\n");
}