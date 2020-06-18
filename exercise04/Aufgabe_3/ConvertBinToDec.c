#include <math.h>
unsigned short int ConvertBinToDec(unsigned char actChar, int m)
{
	unsigned short int out;
	unsigned short int var;
	
	if (actChar == '0')
	{
		var = 0;
	}
	else
	{
		var = 1;
	}

	out = var * pow(2, (7-m));

	return out;
}