#include <iostream>
#include <string>

using namespace std;

int countWords(string str);

int main(void) {
	string input;
	
	while (true) {
		cout << "Enter a string or Q to quit: ";
		getline(cin, input);
		if (input == "Q") {
			break;
			cout << "\"" << input << "\"" << endl;
		}
		else
			cout << "Word Count: " << countWords(input) << endl << endl;

	}
}

// Function Defs

int countWords(string str) {
	int count = 1;
	for (int i = 0; i <= (str.length() - 1); i++) {
		if (str[i] == ' ') {
			count++;

			if (str[++i] == ' ')
				count-- ;
		}
	}
	return count;
}