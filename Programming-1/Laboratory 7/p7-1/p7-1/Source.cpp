#include <iostream>
#include <cmath>

using namespace std;

double smallest(double x, double y, double z);
double average(double x, double y, double z);

int main(void) {
	double x;
	double y;
	double z;

	cout << "Enter three numbers: ";
	cin >> x >> y >> z;
	
	cout << "The smallest value is: " << smallest(x, y, z) << endl;

	cout << "Average is: " << average(x, y, z) << endl;
		return 0;
}
// *** function definitions ***

// * smallest: returns the smallest of the argumnts
// * Parameters: double x, double y, double z - floating 
// * point values in a number set
// * Returns: smallest double of the set of 3 numbers
double smallest(double x, double y, double z)
{
	if (x < y && x < z)
	{
		return x;
	}
	if (y < z && y < x)
	{
		return y;
	}
	else
	{
		return z;
	}

}
// * average: finds the average of the 3 numbers passed
// * to the function
// * Parameters: double x, double y, double z - floating 
// * point values in a number set
// * Returns: average of the set of 3 numbers
double average(double x, double y, double z)
{
	double avg = (x + y + z) / 3.0;
	return avg;
}