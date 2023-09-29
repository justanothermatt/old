#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	cout << "Enter number of asterisks per side: ";
	cin >> n;

	if (n < 3)
	{
		cout << "Please output a number larger than three: " << endl;
		cin >> n;
	}
	else
	{
	// For loops for top row
		for (int i = 0; n > i; i++)
		{
			cout << "*";
		}
		cout << " ";
		for (int i = 0; n > i; i++)
		{
			cout << "*";
		}
		cout << endl;
	// For loops for second row
		for (int rows = 0; rows < n-2; rows++)
		{
			for (int i = 0; n > i; i++)
			{
				cout << "*";
			}
				cout << " *";
			for (int i = 1; n - 1 > i; i++)
			{
				cout << " ";
			}
			cout << "*" << endl;
		}
		for (int i = 0; n > i; i++)
			{
				cout << "*";
			}
				cout << " ";
		for (int i = 0; n > i; i++)
		{
			cout << "*";
		}
			cout << endl;
	}
}