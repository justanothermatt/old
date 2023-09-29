#include <iostream>
#include <cmath>

using namespace std;

int first_digit(int n);
int last_digit(int n);
int digits(int n);

int main(void) {

	int n;

	while (true) {
		cout << "Enter a number or Q to quit: ";
		cin >> n;
		if (cin.fail()) break;

		cout << "First digit: " << first_digit(n) << " ";
		cout << "Last digit: " << last_digit(n) << " ";
		cout << "Number of digits: " << digits(n) << endl;
	}
	return 0;
}

// Function defintions

int first_digit(int n) {
	while (n > 9)
		n /= 10;
		return n;
}
int last_digit(int n) {
	return n % 10;
}
int digits(int n) {
	
	int tempCount = 0;

	while (n > 0)
	{
		n /= 10;
		tempCount++;
	}
	return tempCount;
}