#include <stdio.h>

void printMatrix(int Matrix[][4], char string[8])
{
	printf("\nMatrix %s:\n\n", string);
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			printf("%d\t", Matrix[row][col]);
		}
		printf("\n");
	}
}
