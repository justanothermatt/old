#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(void)
{
	double num;
	double n = 0;
	double avg = 0;
	double total = 0;
	double sqrTot = 0;
	double std = 0;
	cout << "Enter numbers - Q to quit: ";
	
	while (cin >> num)
	{
		n++;
		total += num;
		sqrTot += (num*num);
		avg = total / n;
	}
	
	std = sqrt((sqrTot - (total*total) / n) / (n - 1));
	
	cout << "n = " << n 
		 <<", Average = " << avg 
		 << ", Standard Deviation = " << std << endl;
}