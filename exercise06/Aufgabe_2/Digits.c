// Ermittlung: Anzahl der Ziffern

unsigned int Digits(unsigned int Number)
{

	if (Number >= 1000)
	{
		return 4;
	}
	else if (Number >= 100)
	{
		return 3;
	}
	else if (Number >= 10)
	{
		return 2;
	}
	else if (Number >= 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}