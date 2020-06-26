void SetInput(char GameArray[][7], int PGRow, int Input, char PlayerChar)
{
	for (int i = (PGRow - 1); i >= 0; i--)
	{
		if (GameArray[i][Input] == ' ')
		{
			GameArray[i][Input] = PlayerChar;
			break;
		}
			
	}

}