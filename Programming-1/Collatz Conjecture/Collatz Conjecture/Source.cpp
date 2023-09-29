#include <iostream>

using namespace std;

int main(void) {

	int input = 0;
	int steps = 0;
	double half = .5;
	int three = 3;
	
	cout << "Please input a positive integer to be tested: ";
	cin >> input;

	while (true) {
		if (input != 1) {
			if ((input % 2) == 0) {
				input = (half*input);
				steps++;
				cout << input << endl;
			}
			else {
				input = ((three * input) + 1);
				steps++;
				cout << input << endl;
			}
		}
		else break;
	}
	cout << endl << "This number took " << steps << " steps to reach one." << endl;
}