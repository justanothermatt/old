#include <iostream>

using namespace std;

int main()
{
	int number;

	cout << "Please enter a number: ";
	cin >> number;

	while (number > 0)
	{
		cout << number % 2 << endl;

		number = number / 2;
	}
	return 0;
}