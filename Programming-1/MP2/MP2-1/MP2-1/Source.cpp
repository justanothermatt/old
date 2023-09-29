#include <iostream>
#include <cmath>
#include <string>

using namespace std;

bool isTurnScoreLost(int die1, int die2);
bool isGameScoreLost(int die1, int die2);

int main(void) {
	
	int die1 =0;
	int die2 =0;
	string Turn;
	string Game;
	
	while (true) {

		cout << "Enter die 1 and die 2 values (Q to quit): ";
		cin >> die1 >> die2;
		
		if (isTurnScoreLost(die1, die2) == false) { Turn = "False"; }
		else { Turn = "True"; }

		if (isGameScoreLost(die1, die2) == false) { Game = "False"; }
		else { Game = "True"; }

		cout << "isTurnScoreLost = " << Turn << endl;
		cout << "isGameScoreLost = " << Game << endl;
		if (cin.fail()) break;
	}
}

// Function definitions

bool isTurnScoreLost(int die1, int die2) {
	if (die1 == 1 || die2 == 1)
		return true;
	return false;
}
bool isGameScoreLost(int die1 , int die2){
	if (die1 == 1 && die2 == 1)
		return true;
	return false;
}