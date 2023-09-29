#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	double owed;
	double paid;
	double due;
	
	cout << "Customer owes $";
		cin >> owed;
	cout << "Customer pays $";
		cin >> paid;
	
	due = paid - owed;

	cout << "Change due is $" << fixed << setprecision(2) << due << endl;
			
// Assigning integers to determine change
		int dollars = due;									// Making the double an integer to figure out how many dollars there are
			
		double tempChange = (due - dollars)*100;			// tempChange is the floating points from the change due multiplied by 100 i.e (0.67 * 100 = 67)

		int quarter = (tempChange / 25);							

		int dimes = ((tempChange - (quarter*25)) / 10);	

		int nickel = ((tempChange - (quarter*25) -(dimes * 10)) / 5);

		double penny = (tempChange - (quarter*25) - (dimes * 10) - (nickel *5));


// If statements used to determine how many Quarters, Dimes, Nickels, and Pennies are needed to return
	if (dollars > 0)
	{
		cout << dollars << " Dollar(s)" << endl;
	}

	if (quarter > 0)
	{
		cout << quarter << " Quarter(s)" << endl;
	}

	if (dimes > 0)
	{
		cout << dimes << " Dime(s)" << endl;
	}

	if (nickel > 0)
	{
		cout << nickel << " Nickel(s)" << endl;
	}

	if (penny > 0)
	{
		cout << fixed<< setprecision(0) << penny << " Pennies" << endl;
	}

	return 0;
}