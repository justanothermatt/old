#include <iostream>
#include <ctime>

using namespace std;

int main(void) {

	srand(time(0));
	int a[10];

	for (int i = 0; i < 10; i++) {
		a[i] = rand() % 8999 + 1000;
	}

	cout << "The random integers: ";
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
	cout << endl << endl << "Even indices:        ";
	
	for (int i = 0; i < 10; i += 2) {
		cout << a[i] << " ";
	}
	cout << endl << endl << "Even values:         ";

	for (int i = 0; i < 10; i++) {
		if (a[i] % 2 == 0) {
			cout << a[i] << " ";
		}
	}
	cout << endl << endl << "Reversed order:      ";

	for (int i = 9; i >= 0; i--) {
		cout << a[i] << " ";
	}
	cout << endl << endl << "First and last:      " << a[0] << " " << a[9] << endl << endl;
}