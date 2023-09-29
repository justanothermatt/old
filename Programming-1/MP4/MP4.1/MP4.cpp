// MP4.cpp - Matt Walker - 11/30/2017
// This code reads in a text file and store either the enciphered or deciphered
// text in an output file based off of a Vigenere Cipher. All commands are passed
// through the command line as follows:
// Argument #: [  1  ] [              2               ] [	3   ] [    4     ] [     5     ]
//			   [MP4.1] [-e or -d, encipher or decipher] [key word] [input file] [output file]

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


// Function prototype
char encipher(char key, char plain);
char decipher(char key, char cipher);
void pressEnterToContinue(void);
void exitProgram(void);

// Global Constants
const int MAX_SIZE = 3000;		// Large value to account for large keywords
const int NUM_ARGUMENTS = 5;	// Number of arguments passed through the command line

int main(int argc, char*argv[])
{
	// Variable Declaration
	string	inputFileName;		// Stores the name of the input file
	string	outputFileName;		// Stores the name of the output file
	ifstream inputStream;		// Reference to open input file
	ofstream outputStream;		// Reference to open output file
	char keyWord[MAX_SIZE];		// Character array used to store the keyword
	char ch;					// Used for reading in one character from the input file

	// Storage of file names
	inputFileName = argv[argc - 2];		// input file name
	outputFileName = argv[argc - 1];	// output file name

	// Opens input file - verify that the file can be opened for reading
	inputStream.open(inputFileName.c_str());
	if (inputStream.fail())				// if the file fails to open, close the program
	{
		cout << "Sorry - cannot open input file.\n";
		pressEnterToContinue();
		exit(1);
	}

	// open output file - verify that the file can be opened for writing
	outputStream.open(outputFileName.c_str());
	if (outputStream.fail())			// if the file fails to open, close the program
	{
		cout << "Sorry - cannot open output file.\n";
		pressEnterToContinue();
		exit(1);
	}

	// storing key into char array
	string initKeyWord = argv[2];		// stores the initial keyword as a string for reference
	for (int i = 0; i < initKeyWord.length() - 1; i++)
	{
		keyWord[i] = initKeyWord[i];
	}
	// Command Prompt Commands
	if (argc != NUM_ARGUMENTS)		// Checks to see if the right amount of arguments are passed to the command prompt
	{

		exitProgram();
	}
	else
	{
		if (argv[1][0] == '-')
		{
			// Enciphering Code Segment
			if (argv[1][1] == 'e')
			{
				int count = 0;						// helps keep track of which key character to use 
				while (true) {
					inputStream.get(ch);			// read in one character from the input file 
					if (inputStream.eof()) break;	// encountered the end of file (i.e. no more characters) 				
					outputStream << encipher(argv[2][count %initKeyWord.length()], ch);		// stores enciphered character into output file
					count++;						// Increments count of key character tracker
				}

			}
			// Deciphering Code Segment
			if (argv[1][1] == 'd')
			{
				int count = 0;						// helps keep track of which key character to use 
				while (true) {
					inputStream.get(ch);			// read in one character from the input file 
					if (inputStream.eof()) break;	// encountered the end of file (i.e. no more characters) 
					outputStream << decipher(argv[2][count %initKeyWord.length()], ch);		//stores deciphered character into output file
					count++;						// Increments count of key character tracker
				}
			}

		}
		else
		{
			exitProgram();
		}
	}
	// close streams and tell the user that we are done
	inputStream.close();
	outputStream.close();
	cout << "Done!\n";
	pressEnterToContinue();
	return 0;
}

// Function definitions

// encipher:   converts a character to an enchiphered character
// Parameters: key - the character in the keyword that corresponds to the passed plain text
// Variables:  plain - the read character from the input file
// Returns:    enciphered character
char encipher(char key, char plain) {

	if (key < ' ' || key > '~' || plain < ' ' || plain > '~')	// if char not between ' ' and '~' (32 and 126), return it back
		return plain;
	if ((plain + key - ' ') > '~')
		return plain + key - ' ' - 95;	// if it goes above '~', subtract 95, 95 is how many chars are between ' ' and '~' incluive
	return plain + key - ' ';
}

// decipher:   converts an enchiphered character to the original character
// Parameters: key - the character in the keyword that corresponds to the passed plain text
// Variables:  cipher - the renciphered character from the input file
// Returns:    the character from the original input file at the corresponding position
char decipher(char key, char cipher)
{
	if (key < ' ' || key > '~' || cipher < ' ' || cipher > '~')	//if char not between ' ' and '~' (32 and 126), return it back
	{
		return cipher;
	}
	if (cipher - key + ' ' < ' ')
	{
		return cipher - key + ' ' + 95;	//if it goes above '~', add 95, 95 is how many chars are between ' ' and '~' incluive
	}
	return cipher - key + ' ';
}

// pressEnterToContinue: implements a system pause whenever needed.
// parameters: N/A
// returns: None
void pressEnterToContinue(void) {
	cout << "\nPress 'Enter' to continue... ";
	cin.ignore(1024, '\n');
	cin.clear();
	return;
}

// exitProgram: implements code to exit program when incorrect input is used
// parameters: N/A
// returns: None
void exitProgram(void)
{
	cout << "Something went wrong. Please try again with the correct input";
	pressEnterToContinue();
	exit(1);
}