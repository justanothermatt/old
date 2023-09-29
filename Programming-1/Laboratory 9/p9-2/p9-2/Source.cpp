#include <iostream>

using namespace std;

bool isPrime(int n);

int main(void) {
	int n;

	while (true) {
		cout << "Enter an integer or Q to quit: ";
		cin >> n;

		if (cin.fail()) { break; }

		if (isPrime(n)) {
			cout << n << " is prime" << endl << endl;
		}
		else {
			cout << n << " is not prime" << endl << endl;
		}
	}
}

bool isPrime(int n) {
	for (int i = 2; i < n; i++) {
		if ((n % i) == 0) {
			return false;
		}
	}
	return true;
}