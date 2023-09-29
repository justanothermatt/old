#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <string>

using namespace std;

void pressEnterToContinue( void );

int main(int argc, char *argv[]) {

	unsigned long int numLetters = 0;
	char			  ch;
	int				  letterIndex;
	string			  fileName;
	ifstream		  inputStream;
	int				  word = 0;
	int				  letter = 0;
	
	while (true) {
		cout << "File to append to: ";
		getline(cin, fileName);

		inputStream.open(fileName.c_str());

		if (inputStream.fail()) {
			cout << "File does not exist.\n";
			pressEnterToContinue();
			exit(1);
		}
		else {
			string	input;
			while (inputStream >> input) { word++; };
			inputStream.close();

			inputStream.open(fileName.c_str());

			while (true) {
				inputStream.get(ch);
				if (inputStream.eof()) break;
				if (!isspace(ch)) {
					++letter;
				}
			}
			inputStream.close();

			cout << "Words: " << word << endl;
			cout << "Characters: " << letter << endl;

			pressEnterToContinue();
			return 0;
		}
	}
}

// Function Definitions
void pressEnterToContinue(void) {
	cout << "\Press 'Enter' to continue... ";
	cin.ignore(1024, '\n');
	cin.clear();
	return;
}