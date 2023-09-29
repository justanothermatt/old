#include <iostream>

using namespace std;

int main()
{
	int cardNumber;
	int stepOne = 0;
	int stepTwo = 0;
	int stepThree = 0;

	cout << "Please enter 8-digit card number: ";
	cin >> cardNumber;

// Digit (from right to left) variable declaration
	int digit8 = cardNumber % 10;
	
	int digit7 = ((cardNumber % 100) / 10)*2;
		int digit7_1 = digit7 / 10;
		int digit7_2 = digit7 % 10;
	
	int digit6 = (cardNumber % 1000) / 100;
	
	int digit5 = ((cardNumber % 10000) / 1000)*2;
		int digit5_1 = digit5 / 10;
		int digit5_2 = digit5 % 10;
	
	int digit4 = (cardNumber % 100000) / 10000;
	
	int digit3 = ((cardNumber % 1000000) / 100000)*2;
		int digit3_1 = digit3 / 10;
		int digit3_2 = digit3 % 10;
	
	int digit2 = (cardNumber % 10000000) / 1000000;
	
	int digit1 = ((cardNumber % 100000000) / 10000000)*2;
		int digit1_1 = digit1 / 10;
		int digit1_2 = digit1 % 10;

// Validation testing
	stepOne = digit8 + digit6 + digit4 + digit2;
	
	stepTwo = digit7_1 + digit7_2 + digit5_1 + digit5_2 + digit3_1 + digit3_2 + digit1_1 + digit1_2;
	
	stepThree = stepOne + stepTwo;

	if ((stepThree % 2) == 0)
	{
		cout << "Card is valid" << endl;
	}
	else
	{
		cout << "Card is not valid" << endl;
	}
	return 0;
}