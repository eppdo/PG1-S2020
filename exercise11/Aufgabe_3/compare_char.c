int compare_char(const void* a, const void* b)
{
	int aInt = 0;
	int bInt = 0;

	// Gleichsetzen von Gross- und Kleinbuchstaben (a)
	if (*(char*)a >= 0x61)
	{
		aInt = *(char*)a - 0x20;
	}
	else
	{
		aInt = *(char*)a;
	}

	// Gleichsetzen von Gross- und Kleinbuchstaben (b)
	if (*(char*)b >= 0x61)
	{
		bInt = *(char*)b - 0x20;
	}
	else
	{
		bInt = *(char*)b;
	}

	return aInt - bInt;

}