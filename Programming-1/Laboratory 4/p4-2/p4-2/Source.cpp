#include <iostream>

using namespace std;

int main() {
	double one;
	double two;
	double three;

	cout << "Please enter three numbers" << endl;
	cin >> one >> two >> three;

	if (one > two && one > three) {
		cout << one << endl;
	}
	else if (two > one && two > three) {
		cout << two << endl;
	}
	else if (three > one && three > two) {
		cout << three << endl;
	}

	return 0;

	}
