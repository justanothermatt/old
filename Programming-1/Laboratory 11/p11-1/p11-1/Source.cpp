#include <iostream>
#include <string>
using namespace std;


void arrayPrintout();

string seats[13][6]{
	{" 1  ", "A ", "B ", " ", "C ", "D "},
	{" 2  ", "A ", "B ", " ", "C ", "D "},
	{" 3  ", "A ", "B ", " ", "C ", "D "},
	{" 4  ", "A ", "B ", " ", "C ", "D "},
	{" 5  ", "A ", "B ", " ", "C ", "D "},
	{" 6  ", "A ", "B ", " ", "C ", "D "},
	{" 7  ", "A ", "B ", " ", "C ", "D "},
	{" 8  ", "A ", "B ", " ", "C ", "D "},
	{" 9  ", "A ", "B ", " ", "C ", "D "},
	{"10  ", "A ", "B ", " ", "C ", "D "},
	{"11  ", "A ", "B ", " ", "C ", "D "},
	{"12  ", "A ", "B ", " ", "C ", "D "},
	{"14  ", "A ", "B "}
};

int main(void) {
	arrayPrintout();
	int row;
	char let;
	int fat;

	while (true) {
		int invalid = 0;

		cout << "Where would you like to sit? (Or press Q to quit): ";
		cin >> row;
		cin >> let;

		if (cin.fail()) { return 0; }

		if (let == 'A') { fat = 1; }
		if (let == 'B') { fat = 2; }
		if (let == 'C') { fat = 4; }
		if (let == 'D') { fat = 5; }

		if (row == 14) { row = 13; }
		if (row == 13 && (let == 'C' || let == 'D')) { cout << "That seat doesn't exist\n"; invalid = 1; }

		if (row > 14) { cout << "That seat doesn't exist\n"; invalid = 1; }
		if (let > 68) { cout << "That seat doesn't exist\n"; invalid = 1; }

		if (seats[row - 1][fat] == "X ") { cout << "That seat is taken\n"; invalid = 1; }

		if (invalid == 0) { seats[row - 1][fat] = "X "; arrayPrintout(); }
	}
}

void arrayPrintout() {
	system("CLS");
	cout << "AVAILIBLE SEATS" << endl;
	for (int columms = 0; columms < 14; columms++) {
		for (int rows = 0; rows < 6; rows++) {
			cout << seats[columms][rows];
		}
		cout << endl;
	}
}