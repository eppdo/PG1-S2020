unsigned char* InputFill(unsigned char* in)
{
	unsigned int i;
	unsigned int emptyBox = 0;
	static unsigned char out[9] = "00000000";

	// Check Stringlaenge
	for (i = 0; i <= 7; i++)
	{
		if (in[i] != '0' && in[i] != '1')
		{
			emptyBox = i;
			break;
		
		}
	}

	// "Verschieben" der Ziffern nach hinten und vorne auffuellen mit 0
	if (emptyBox > 0 && emptyBox <= 7)
	{
		// Verschiebewert
		unsigned int shiftVal = 7 - emptyBox;
		int j;
		
		for (j = (emptyBox - 1); j >= 0; j--)
		{
			out[j + shiftVal + 1] = in[j];
			
		}
	}
	else
	{
		return in;
	}

return &out;

}