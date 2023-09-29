#include <iostream>
#include <ctime>

using namespace std;

void displayRun(int values[], int SIZE);
bool hasRun(int values[], int SIZE);

int main(void) {
	const int SIZE = 20;
	int a[SIZE];
	int walk = 0;
	int dead = 0;
	srand(time(0));

	while (walk == 0 || dead == 0) {
		for (int i = 0; i < SIZE; i++) {
			a[i] = rand() % 6 + 1;
		}
		if (!(hasRun(a, SIZE)))
		{
			cout << "No run: ";
			displayRun(a, SIZE);
			dead++;
		}
		if (hasRun(a, SIZE))
		{
			cout << "Has run: ";
			displayRun(a, SIZE);
			walk++;
		}
	}
}

void displayRun(int values[], int SIZE) {
	int adj = 0;
	for (int i = 0; i < SIZE; i++) {
		if (values[i] == values[i + 1] && adj == 0) {
			adj++;
			cout << "(";
		}
		cout << values[i];
		if (adj >= 1 && values[i] != values[i + 1]) {
			cout << ")";
			adj--;
		}
		cout << "  ";
	}
	cout << endl;
}

bool hasRun(int values[], int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		if (values[i] == values[i + 1]) { return true; }
	}
	return false;
}