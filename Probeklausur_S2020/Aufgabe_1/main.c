#include <stdio.h>

// Register
unsigned short Reg_SSeg = 0x7FFF;

void func(int x)
{
	printf("\nOriginal\tregister: %x\n", Reg_SSeg);

	// disable register: En -> 1
	Reg_SSeg = Reg_SSeg | 0x8000;				// En == 1		0x8000	=	1000 0000 000 000
	printf("En==1\t\tregister: %x\n", Reg_SSeg);

	// set S1 - S7 == 0
	Reg_SSeg = (Reg_SSeg >> 7) << 7;
	printf("S1-S7==0\tregister: %x\n", Reg_SSeg);

	// number to segments
	switch (x)
	{
	case 1:
		Reg_SSeg = Reg_SSeg | 0x0006;							// 0x0006	=	0000 0000 0000 0110
		break;
	case 2:
		Reg_SSeg = Reg_SSeg | 0x006D;							// 0x006D	=	0000 0000 0110 1110
		break;
	case 3:
		Reg_SSeg = Reg_SSeg | 0x004F;							// 0x004F	=	0000 0000 0100 1111
		break;
	default:
		break;
	}

	printf("Set Seg.\tregister: %x\n", Reg_SSeg);

	// enable register: En = 0
	Reg_SSeg = Reg_SSeg ^ 0x8000;								// 0x8000	=	1000 0000 0000 0000

	printf("En==0\t\tregister: %x\n", Reg_SSeg);

}

int main (void)
{
	printf("Probeklausur PG1 - Sommersememster 2020: Aufgabe 1\n");
	printf("Sieben-Segment-Anzeige:\n");

	// Eingabe 
	int inp = 0;

	printf("Eingabe Wert 1 - 3: ");
	scanf_s("%d", &inp);

	func(inp);


	return 0;
}