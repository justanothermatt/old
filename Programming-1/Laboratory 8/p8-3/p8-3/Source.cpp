#include <iostream>
#include <string>

using namespace std;

int romanCharValue(char r);
int convertRomanToInt(string s);

int main(void) {
	string input;
	while (true) {
		cout << "Enter Roman number or Q to quit: ";
		getline(cin, input);
		
		if (input == "Q") {
			break;
			cout << "\"" << input << "\"" << endl;
		}

		else {
			cout << input << " = " << convertRomanToInt(input) << endl;
		}
	}
}

// Function defs

int romanCharValue(char r) {
	if (r == 'I')
		return 1;
	if (r == 'V')
		return 5;
	if (r == 'X')
		return 10;
	if (r == 'L')
		return 50;
	if (r == 'C')
		return 100;
	if (r == 'D')
		return 500;
	if (r == 'M')
		return 1000;
	

}

int convertRomanToInt(string s) {
	int total = 0;
	
	for (int i = 0; i <= (s.length()-1); i++) {
		if ((romanCharValue(s[i]) >= romanCharValue(s[i + 1])) || s.length() == 1) {
			total += romanCharValue(s[i]);
		}
		else {
			total = total + (romanCharValue(s[i+1]) - romanCharValue(s[i]));
			s.erase(i, 1);
		}
	}
	return total;
}