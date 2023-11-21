// Author: Seth Jackson

// This program is a command line based game where the users enter numbers to choose attacks.
// The stats are updated after every turn and displayed to the console.

#include <iostream>
#include <fstream>
#include <string>
#include "attacks-struct.h"
#include "character-class.h"
#include "character-obj-selection.h"
#include "battle.h"

using namespace std;

int main()
{
	bool playAgain; // 4. Variable
	playAgain = true;

	do // 7. Iteration
	{
		cout << "Welcome to BattleFrogs" << '\n'; // 3. Output

		// Choose Character
		// Player 1
		Character player1;
		cout << '\n' << "Player 1:";
		player1 = selectCharacter(); // 8. Interaction // Array example found in character-obj-selection.cpp
		player1.playerID = 1;

		// Player 2
		Character player2;
		cout << '\n' << "Player 2:";
		player2 = selectCharacter();
		player2.playerID = 2;

		// Battle
		Character winner = battle(player1, player2);

		//Output Winner of the Game to a Text File... 6. File I/O
		ofstream outFile;
		outFile.open("winner.txt");
		outFile << "The winner is player " << winner.playerID;
		outFile.close();

		// Output Winner to Console
		cout << '\n' << "The Winner is player " << winner.playerID;

		// Play Again?
		cout << '\n' << "Would you like to play again?" << '\n' << "Enter  \"y\" to play again:" << '\n';
		char playStatus;
		cin >> playStatus; // 3. Input
		if (playStatus != 'y') // 9. Control Structure
		{
			playAgain = false;
		}
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		
		//Insert a new line so title is easy to read if the user plays again
		cout << '\n';
	}
	while (playAgain == true); // 7. Iteration
	

	return 0;
}