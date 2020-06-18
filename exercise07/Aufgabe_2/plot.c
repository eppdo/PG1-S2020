void plot(char* Array, int ArrayRow, int ArrayCol)
{
	printf("\n\n\n");


	for (int i = 0; i < ArrayRow * ArrayCol; i++)
	{
		if (i % ArrayCol == 0)
		{
			printf("\n");
		}


		if (Array[i] == 'X')
		{
			printf("%c", Array[i]);
		}
		else
		{
			printf(" ");
		}

	}


}