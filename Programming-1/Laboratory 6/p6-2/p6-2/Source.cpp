#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	int numStars;
	cout << "Enter a number of asterisks per side: ";
	cin >> numStars;

	//Upper triangle
	for (int i = 1; i <= numStars; i++)
	{
		for (int a = numStars - i; a >= 0; a--) { cout << " "; }
		for (int b = 0; b <= i - 2; b++) { cout << "*"; }
		for (int c = 1; c <= i; c++) { cout << "*"; }
		cout << endl;
	}

	//Bottom triangle
	for (int i = numStars; i >= 1; i--)
	{
		for (int a = 0; a <= (1 + numStars) - i; a++) { cout << " "; }
		for (int b = i - 2; b >= 0; b--) { cout << "*"; }
		for (int c = i - 3; c >= 0; c--) { cout << "*"; }
		cout << endl;

	}
}