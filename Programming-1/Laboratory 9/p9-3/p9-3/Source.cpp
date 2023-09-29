#include <iostream>

using namespace std;

void sort3(int& a, int& b, int& c);

int main(void) {
	
	int v;
	int w;
	int x;

	while (true) {
		cout << "Enter three numbers or Q to quit: ";
		cin >> v >> w >> x;

		if (cin.fail()) { break; }
		sort3(v, w, x);
	}
	return 0;
}

void sort3(int& a, int& b, int& c) {
	int temp;
	
	if (c < b) { temp = b; b = c; c = temp; }
	if (b < a) { temp = a; a = b; b = temp; }
	if (c < b) { temp = c; c = b; b = temp; }

	cout << "Sorted: " << a << " " << b << " " << c << endl << endl;
}