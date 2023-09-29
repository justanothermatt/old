#include <iostream>
#include <string>

using namespace std;

unsigned int strlength(char *str);
int charcnt(char* str, char c);
void reverse(char* str);
int strcompare(char *str1, char *str2);

int main(void) {

	char str1[80];
	char str2[80];
	char ch;
	string one;
	string two;

	cout << "Enter String 1: ";
	getline(cin, one);
	for (int i = 0; i < one.length(); i++) {
		str1[i] = one.at(i);
	}
	str1[one.length() + 1] = '\0';

	cout << "Enter string 2: ";
	getline(cin, two);
	for (int i = 0; i < two.length(); i++) {
		str2[i] = two.at(i);
	}
	str2[two.length() + 1] = '\0';

	cout << "Enter a character: ";
	cin >> ch;

	cout << endl;

	cout << "String 1 is " << strlength(str1) << " characters long." << endl;
	cout << "String 2 is " << strlength(str2) << " characters long." << endl << endl;

	cout << "The charcater '" << ch << "' appears " << charcnt(str1, ch) << " time(s) in string 1." << endl;
	cout << "The charcater '" << ch << "' appears " << charcnt(str2, ch) << " time(s) in string 2." << endl << endl;

	cout << "String 1 reversed is: \"";
	reverse(str1);
	cout << "\"\n";
	cout << "String 2 reversed is: \"";
	reverse(str2);
	cout << "\"\n\n";

	int compare = strcompare(str1, str2);
	if (compare == 1) { cout << "String 1 lexicographically comes before string 2" << endl; }
	else { cout << "String 1 lexicographically comes after string 2" << endl << endl; }

}

unsigned int strlength(char *str) {
	int count = -1;
	for (int i = 0; i < 80; i++) {
		if (str[i] != '\0') { count++; }
		else { return count; }
	}
	return count;
}

int charcnt(char* str, char c) {
	int count = 0;

	for (int i = 0; i < 80; i++) {
		if (str[i] == c) { count++; }
	}
	return count;
}

void reverse(char* str) {
	int length = strlength(str) - 1;
	for (length; length >= 0; length--) {
		cout << str[length];
	}
}

int strcompare(char *str1, char *str2) {
	for (int i = 0; i <= 80; i++) {
		if (str1[i]) { return 1; }
		if (str2[i] > str1[i]) { return 2; }
	}
}