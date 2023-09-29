#include <iostream>

using namespace std;

int main() {
	int input;
	cout << "Please enter an integer: " << endl;
	cin >> input;

	if (input < 0) {
		input = input * -1;
	}
	
		if (input >= 0 && input < 10) {
			cout << "Your input has 1 digit" << endl;
		}
		else if (input >= 10 && input < 100) {
			cout << "Your input has 2 digits" << endl;
		}
		else if (input >= 100 && input < 1000) {
			cout << "Your input has 3 digits" << endl;
		}
		else if (input >= 1000 && input < 10000) {
			cout << "Your input has 4 digits" << endl;
		}
		else if (input >= 10000 && input < 100000) {
			cout << "Your input has 5 digits" << endl;
		}
		else if (input >= 100000 && input <= 200000) {
			cout << "Your input has 6 digits" << endl;
		}
	return 0;
}