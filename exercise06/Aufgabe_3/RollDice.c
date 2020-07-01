#include <stdio.h>

void RollDice(unsigned int* GameArray[9][7], int* Dice, char* NewRoll, int curPlayer, unsigned int maxDice)
{
	// Spielzug
	printf("\nSpieler %d - wirft: \n", curPlayer + 1);

	for (int DiceRoll = 0; DiceRoll < maxDice; DiceRoll++)
	{
		if (NewRoll[DiceRoll] == '1')
		{
			Dice[DiceRoll] = D6();
			GameArray[curPlayer][DiceRoll + 1] = Dice[DiceRoll];
			printf("\tWuerfel %d: %d\n", DiceRoll + 1, Dice[DiceRoll]);
		}
		else
		{
			printf("\tWuerfel %d: %d\n", DiceRoll + 1, GameArray[curPlayer][DiceRoll + 1]);
		}


	}

	// Summe der Würfelwerte
	unsigned int SumDice = 0;
	for (int NumDice = 1; NumDice <= maxDice; NumDice++)
	{
		SumDice = SumDice + (unsigned int)GameArray[curPlayer][NumDice];
	}
	GameArray[curPlayer][6] = SumDice;
	printf("Summe der Wuerfel: %d\n", SumDice);


}
