#include <iostream>
#include <string>

using namespace std;

int main() {
	cout << "Hello my name is Hal!" << endl;
	string userName;
	cout << "What is your name? ";
	getline(cin, userName);
	cout << "Hello ";
	cout << userName;
		return 0;
}