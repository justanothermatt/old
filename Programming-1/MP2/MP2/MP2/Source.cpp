// MP2.cpp - Matt Waker - 10/19/2017
// This program simulates the game of Pig between a Human and the CPU
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function Prototypes
void instructions(void);
int rollDie(void);
bool isTurnScoreLost(int die1value, int die2value);
bool isGameScoreLost(int die1value, int die2value);
char getUserInput(void);

int main(void)
{
	// Variable Declaration
	int die1;
	int die2;
	int dieSum;
	int playerTurnScore = 0;		// Keeps track of turn score of human player
	int playerTotalScore = 0;		// Keeps track of total score of human player
	int cpuTurnScore = 0;			// Keeps track of turn score of cpu		
	int cpuTotalScore = 0;			// Keeps track of total score of cpu
	srand((unsigned)time(0));		//initialization of the random function

	//Constant Declarations
	const int CPU_SCORE_PARAMETER = 21;
	const int HIGHEST_GAME_SCORE = 100;

	//Output instructions to user
	instructions();

	while (true){		// Loop to keep game running while human player or CPU has not won

		// HUMAN PLAYER CODE

		playerTurnScore = 0;	// Resets the turn score for human player

								// Human player dice roll loop
		cout << "*************** Player 1's TURN ***************\n";
		do{
			die1 = rollDie();			// Stores the dice value in die1 for the current turn
			die2 = rollDie();			// Stores the dice value in die2 for the current turn
			dieSum = die1 + die2;		// Adds die1 and die2 together
			cout << "You rolled a " << die1 << " and a " << die2 << "\n";
			playerTurnScore += dieSum;	// Keeps track of the turn score throughout the loop

			if (isGameScoreLost(die1, die2)){				// Checks to see if the score for the game is lost
				cout << "\nYou lost your game score :(\n";
				playerTotalScore = 0;		// Resets game
				playerTurnScore = 0;		// score to 0
				break;		// Breaks out of do-while loop
			}
			
			if (isTurnScoreLost(die1, die2)){				// Checks to see if the score for the turn is lost
				cout << "\nYou lost your turn score :(\n";
				playerTurnScore = 0;		// Resets turn score to 0
				break;		// Breaks out of do-while loop
			}

			// Roll Again Statement
			if (getUserInput() == 's'){
				cout << "\nYou stored your points\n";
				break;						// Break statement
			}
		} while (true);

		// Post-Loop Calulations
		playerTotalScore += playerTurnScore;
		if (playerTotalScore >= HIGHEST_GAME_SCORE) { break; }
		cout << "Player GameScore: " << playerTotalScore << " Player TurnScore: " << playerTurnScore << "\n\n";

		// CPU CODE

		cpuTurnScore = 0;	// Resets the turn score for the cpu

							// CPU Dice Roll Loop
		cout << "*************** CPU's TURN ***************\n";
		do{
			die1 = rollDie();			// Stores the dice value in die1 for the current turn
			die2 = rollDie();			// Stores the dice value in die2 for the current turn
			dieSum = die1 + die2;		// Adds die1 and die2 together
			cout << "The CPU rolled a " << die1 << " and a " << die2 << "\n";
			cpuTurnScore += dieSum;		// Keeps track of the turn score throughout the loop

		
			if (isGameScoreLost(die1, die2)){				// Checks to see if the score for the game is lost
				cout << "\nThe CPU lost its game score!\n";
				cpuTotalScore = 0;		// Resets game
				cpuTurnScore = 0;		// score to 0
				break;
			}
			
			if (isTurnScoreLost(die1, die2)){				// Checks to see if the score for the turn is lost
				cout << "\nThe CPU lost its turn score!\n";
				cpuTurnScore = 0;		// Resets turn score to 0
				break;
			}

			// Roll Again Statement
			if (cpuTurnScore < CPU_SCORE_PARAMETER) { continue; }
			else{
				cout << "\nThe CPU stored its points!\n";
				break;
			}

		} while (true);

		// Post-Loop Calculations
		cpuTotalScore += cpuTurnScore;
		if (cpuTotalScore >= HIGHEST_GAME_SCORE) { break; }
		cout << "CPU GameScore: " << cpuTotalScore << "  CPU TurnScore: " << cpuTurnScore << "\n\n";
	}

	// Win Condition Outputs
	if (playerTotalScore >= 100){
		cout << "\n\nCongratulations, you won!\n";
		cout << "Player Score : " << playerTotalScore << "\nCPU Score: " << cpuTotalScore << "\n";
	}
	else{
		cout << "\n\nYou Lost! Better luck next time!\n";
		cout << "Player Score : " << playerTotalScore << "\nCPU Score: " << cpuTotalScore << "\n";
	}
}


// Function Definitions

// Instructions: outputs greeting and instructions to human player
// Parameters:  N/A
// Returns: N/A
void instructions(void){
	cout << "***** PIGS *****\n\n";
	cout << "How to play:\n\n";
	cout << " -Roll dice to beat the computer to a total of 100 points. The human player goes first.\n";
	cout << " -After each roll you can choose to either roll again to add to your turn score, or end your turn and add your turn score to your total game score.\n";
	cout << " -If either of your dice values are equal to 1, your turn ends and you lose your current turn score.\n";
	cout << " -If both of your dice values are equal to 1, your turn ends and you lose your turn score AND game score.\n\n";

}

// Function: rollDice: simulates the roll of a standard (6-sided) die.
// Parameters: N/A
// Returns: integer pip value (from 1 to 6) of the rolled die
int rollDie(void){
	const int NUMBER_OF_DIE_SIDES = 6;
	const int LOWEST_DIE_VALUE = 1;

	return rand() % NUMBER_OF_DIE_SIDES + LOWEST_DIE_VALUE;
}

// Function: isGameScoreLost: determines whether the game score is lost or not, given die values
// Parameters: int die1value, int die2value - die values in the game
// Returns: true if both die value equal 1; false otherwise
bool isGameScoreLost(int die1value, int die2value){
	if (die1value == 1 && die2value == 1)
		return true;
	return false;
}

// Function: isTurnScoreLost: determines whether the turn score is lost or not, given die values
// Parameters: int die1value, int die2value - die values in the game
// Returns: true if either die value equals 1; false otherwise
bool isTurnScoreLost(int die1value, int die2value){
	if (die1value == 1 || die2value == 1)
		return true;
	return false;
}

// Function: getUserInput: used as a wall to idiot-proof the input for playing again
// Parameters: N/A
// Returns: r or s, depending on the input
char getUserInput(void){
	char userInput;
	cout << "IF YOU WOULD LIKE TO ROLL AGAIN, PLEASE ENTER r. OTHERWISE ENTER s TO STORE YOUR DIE VALUES AND END YOUR TURN: ";
	while (cin >> userInput){
		if (userInput == 'r') return 'r';
		if (userInput == 's') return 's';
		else{
			cout << "INVALID ENTRY - ENTER r TO ROLL AGAIN OR s TO STORE YOUR VALUES AND END YOUR TURN.\n";
		}
	}
}