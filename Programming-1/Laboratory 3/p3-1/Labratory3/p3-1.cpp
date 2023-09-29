#include <iostream>

using namespace std;

int main() {
	int numberOne;
	int numberTwo;
		cout << "Please Input An Integer: " << endl;
		cin >> numberOne;
		cout << "Please Input Another Integer: " << endl;
		cin >> numberTwo;

			cout << "Sum: " << numberOne + numberTwo << endl;
			cout << "Difference: " << numberOne - numberTwo << endl;
			cout << "Product: " << numberOne * numberTwo << endl;
			cout << "Average: " << (numberOne + numberTwo) / 2.0;
	return 0;
}