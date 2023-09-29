#include <iostream>
#include <cmath>

using namespace std;

bool all_the_same(int x, int y, int z);
bool all_different(int x, int y, int z);
bool sorted(int x, int y, int z);

int main(void) {
	int x;
	int y;
	int z;

	while (true)
	{
		cout << "Enter three numbers or Q to quit: ";
		cin >> x >> y >> z;
		if (cin.fail()) break;							//Break statment

		bool same = all_the_same(x, y, y);
		if (same)
			cout << "Numbers are the same. \n";
		if (!same)
			cout << "Numbers are not the same. \n";
		bool different = all_different(x, y, z);
		if (different)
			cout << "Numbers are different. \n";
		if (!different)
			cout << "Numbers are not different. \n";
		bool beenSorted = sorted(x, y, z);
		if (beenSorted)
			cout << "Numbers are sorted. \n";
		if (!beenSorted)
			cout << "Numbers are not sorted. \n";
	}
}

// Function definitions

bool all_the_same(int x, int y, int z) {
	if (x == y && x == z)
		return true;
	return false;
}
bool all_different(int x, int y, int z) {
	if (x != y && x != z)
		return true;
	return false;
}
bool sorted(int x, int y, int z) {
	if (x <= y && y <= z)
		return true;
	return false;
}