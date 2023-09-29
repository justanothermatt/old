#include <iostream>

using namespace std;

int main() {
	int carCost;
	double MPG;
	int milesPY;
	double gasCost;
	int yearsUse;
	int resaleCost;

	cout << "What is the cost of the car? : ";
		cin >> carCost;
	cout << "What is the estimated highway MPG? : ";
		cin >> MPG;
	cout << "What is the estimated miles driven per year? : ";
		cin >> milesPY;
	cout << "What is the cost of gas? (per Gallon) : ";
		cin >> gasCost;
	cout << "How many years will you use the car? : ";
		cin >> yearsUse;
	cout << "What is the reasale amount? : ";
		cin >> resaleCost;

	cout << "The net total cost of owning a car is: " <<
		(carCost + (((milesPY / MPG) * gasCost) * yearsUse)) - resaleCost << endl;
	return 0;	
}