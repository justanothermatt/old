#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int sum = 0;

	for (int even = 0; even <= 100; even += 2)
		sum = sum + even;
	cout << "The sum of all the even numbers between 2 and 10, inclusive, is " << sum << endl;
	
	int out = 0;

	for (int squares = 0; squares <= 100; squares += 1)

		out = pow(squares, 2) + out;
	cout << "The sum of all squares between 1 and 100, inclusive, is " << out << endl;
		return 0;
}