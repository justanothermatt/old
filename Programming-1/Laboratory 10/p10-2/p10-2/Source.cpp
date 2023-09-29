#include <iostream>

using namespace std;

bool isSortedIncreasing(int a[], int SIZE);
bool isSortedDecreasing(int a[], int SIZE);
bool hasAdjecentDuplicates(int a[], int SIZE);
bool hasDuplicates(int a[], int SIZE);

int main(void) {
	const int SIZE = 6;
	int a[SIZE];

	for (int i = 0; i < SIZE; i++) {
		cout << "Enter integer #" << i << ": ";
		cin >> a[i];
	}

	cout << endl;
	
	if (isSortedIncreasing(a, SIZE)) {
		cout << "The data is increasing.\n";
	}
	else
		cout << "The data is not increasing.\n";

	if (isSortedDecreasing(a, SIZE)) {
		cout << "The data is decreasing.\n";
	}
	else
		cout << "The data is not decreaing.\n";

	if (hasAdjecentDuplicates(a, SIZE)) {
		cout << "The data has adjacent duplicates.\n";
	}
	else
		cout << "The data has no adjacent duplicates.\n";

	if (hasDuplicates(a, SIZE)) {
		cout << "The data has duplicates.\n\n";
	}
	else{
		cout << "The data has no duplicates.\n\n";
	}
}


// Function definitions

bool isSortedIncreasing(int a[], int SIZE) {
	for (int i = 0; i < SIZE; i++) {

		if (a[i] < a[i+1]) { return true; }

		else return false;
	}
}

bool isSortedDecreasing(int a[], int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		if (a[i] < a[i + 1]) { return false; }
	}
}

bool hasAdjecentDuplicates(int a[], int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		if (a[i] == a[i + 1]) { return true; }
	}
	return false;
}

bool hasDuplicates(int a[], int SIZE) {
	int dubz = 0;
	for (int i = 0; i < SIZE; i++) {
		for (int j = i+1; j < SIZE; j++) {
			if (a[i] == a[j]) { dubz++; }
		}
	}
	if (dubz > 0) { return true; }
	else return false;
}