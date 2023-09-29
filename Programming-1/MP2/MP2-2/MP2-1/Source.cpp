#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string isTurnScoreLost(int die1, int die2);
string isGameScoreLost(int die1, int die2);

int main(void) {
	
	int die1 = 1;
	int die2 = 1;
	for(die2; die2 <= 6; die2++)
	{
		die1 = 1;
		for (die1; die1 <= 6; die1++) {
			cout << die1 << "   " << die2 << "   " << isTurnScoreLost(die1, die2) << "   " << isGameScoreLost(die1, die2) << endl;
		}
	}
}

// Function definitions

string isTurnScoreLost(int die1, int die2) {
	string turnScore;
	if (die1 == 1 || die2 == 1)
		turnScore = "true";
	else 
	turnScore = "false";
	return turnScore;
}
string isGameScoreLost(int die1 , int die2){
	string gameScore;
	if (die1 == 1 && die2 == 1)
		gameScore = "true";
	else 
	gameScore = "false";
	return gameScore;
}