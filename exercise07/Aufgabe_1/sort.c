void sort(int* intArray, int idx)
{

	printf("%x\n", &intArray);
	int memoryInt = 0;			// Zwischenspeicher
	int abbortInt = 0;			// Abbruchkriterium

	for (int j = 1; j < idx; j++)
	{
		abbortInt = memoryInt;

		for (int i = 0; i < (idx - j); i++)
		{
			if (intArray[i] > intArray[i + 1])
			{
				memoryInt = intArray[i];
				intArray[i] = intArray[i + 1];
				intArray[i + 1] = memoryInt;
			}

		}

		if (memoryInt == abbortInt)
		{
			break;
		}

	}

}