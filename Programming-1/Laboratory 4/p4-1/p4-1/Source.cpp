#include <iostream>
#include <string>

using namespace std;

int main() {
	int temp;
	string tempScale;

	cout << "Please enter temperature value: " << endl;
	cin >> temp >> tempScale;

	if (tempScale == "C") {
		
		
	if (temp == 100)
	{
		cout << "Water is both a liquid and a gas at this temperature" << endl;
	}
		
		else if (temp <= 0) {
			cout << "Water is a solid at this temperature" << endl;
		}
		else if (temp > 0 && temp < 100) {
			cout << "Water is a liquid at this temperature" << endl;
		}
		else if (temp >= 100) {
			cout << "Water is a gas at this temperature" << endl;
		}
	}
	else if (tempScale == "F") {
		
		if (temp == 32)
		{
			cout << "Water is both a solid and a liquid at this temperature" << endl;
		}
		
		else if (temp <= 32) {
		cout << "Water is a solid at this temperature" << endl;
	}
		else if (temp > 0 && temp < 212) {
			cout << "Water is a liquid at this temperature" << endl;
		}
		else if (temp >= 212) {
			cout << "Water is a gas at this temperature" << endl;
		}
	}
	return 0;
}