void Pathfinder(_Bool Direction[], char maze[][20], int row, int col, int* Crossing)
{
	// Nachbarschaft auf freie Wege untersuchen (bzw Weg zurueck zu Kreuzung):

	// Direction[1] -> Nachbar: oben
	Direction[1] = maze[row - 1][col] == ' ' || maze[row - 1][col] == 'F';			
	// Direction[2] -> Nachbar: unten															
	Direction[2] = maze[row + 1][col] == ' ' || maze[row + 1][col] == 'F';			
	// Direction[3] -> Nachbar: links
	Direction[3] = maze[row][col - 1] == ' ' || maze[row][col - 1] == 'F';
	// Direction[4] -> Nachbar: rechts
	Direction[4] = maze[row][col + 1] == ' ' || maze[row][col + 1] == 'F';

	// Direction[0]  == 1, wenn min ein Nachbarelement == ' ' (leer) ist oder 'F'
	Direction[0] = Direction[1] + Direction[2] + Direction[3] + Direction[4];


	// Kreuzung?	->	Mehr als eine Moeglichtkeit abzubiegen
	if (((int)Direction[1] + (int)Direction[2] + (int)Direction[3] + (int)Direction[4]) > 1)
	{
		*Crossing = 1;
	}
	else
	{
		*Crossing = 0;
	}

}