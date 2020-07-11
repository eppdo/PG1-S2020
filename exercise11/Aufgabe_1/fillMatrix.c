void fillMatrix(int Matrix[][4], int MRow, int MCol)
{
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			Matrix[row][col] = randInt();
		}
	}
}