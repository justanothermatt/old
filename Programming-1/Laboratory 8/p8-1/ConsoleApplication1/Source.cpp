#include <iostream>
#include <string>

using namespace std;

int countVowel(string str);

int main(void) {
	string input;
	
	while (true) {
		cout << "Enter a string or Q to quit: ";
		getline( cin, input );
		
		if (input == "Q") {
			break;
			cout << "\"" << input << "\"" << endl;
		}
		else {
			cout << "Vowel count: " << countVowel(input) << endl << endl;
		}
	}
}

// Function Definitions

int countVowel(string str) {
	int count = 0;
	for (int i = 0; i <= (str.length() - 1); str[i++]) {
		if (str[i] == 'a' || str[i] == 'A' || str[i] == 'e' || str[i] == 'E' || str[i] == 'i' || str[i] == 'I' || str[i] == 'o' || str[i] == 'O' || str[i] == 'u' || str[i] == 'U') {
			count++;
		}
	}
	return count;
}