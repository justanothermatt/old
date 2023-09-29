// MP1.cpp - Matthew W. Walker - September 2017
// This program is used to determine the cost of a donut order at a coffee shop
// and will give the cashier the correct amount of change to supply to the customer

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
// Defining Variables
	int regDonut;
	int fillDonut;
	int dollar = 0;
	int quarter = 0;
	int dime = 0;
	int nickel = 0;
	int penny = 0;
	double regCost = 0;
	double fillCost = 0;
	double costTotal = 0;
	double payment;

// Defining Constants
	const int ONE_DONUT = 1;
	const int DONUT_PER_DOZ = 12;
	const double PRICE_REG = 0.50;			// Price of one regular donut
	const double PRICE_REG_DOZ = 5.25;		// Price of regular donut per dozen
	const double PRICE_FILL = 0.75;			// Price of one filled donut
	const double PRICE_FILL_DOZ = 8.25;		// Price of filled donut per dozen
	const double TAX_RATE = 1.04;			// Tax rate for this situation
	const int CENTS_PER_DOLLAR = 100;		// Amount of cents in a dollar
	const int CENTS_PER_QUARTER = 25;		// Amount of cents in a quarter
	const int CENTS_PER_DIME = 10;			// Amount of cents in a dime
	const int CENTS_PER_NICKEL = 5;			// Amount of cents in a nickel
	const int CENTS_PER_PENNY = 1;			// Amount of cents in a penny

// User Input
	cout << "How many regular donuts were purchased? : ";
	cin >> regDonut;
	cout << "How many filled donuts were purchased? : ";
	cin >> fillDonut;

// Temporary Storage
	int tempReg = regDonut;
	int tempFill = fillDonut;

// Storing cost of donuts 
	while (tempReg >= DONUT_PER_DOZ)		// Checks to see if there's a dozen regular donuts and then adds the price of a dozen to and subtracts 12 from the total ordered
	{
		regCost += PRICE_REG_DOZ;
		tempReg -= DONUT_PER_DOZ;
	}
	while (tempReg >= ONE_DONUT)			// If there's more then 0 regular donuts left then add the cost of one regular and subract one regular from tempReg
	{
		regCost += PRICE_REG;
		tempReg -= ONE_DONUT;
	}
	while (tempFill >= DONUT_PER_DOZ)		// Checks to see if there's a dozen filled donuts and then adds the price of a dozen and subtracts 12 from the total ordered
	{
		fillCost += PRICE_FILL_DOZ;
		tempFill -= DONUT_PER_DOZ;
	}
	while (tempFill >= ONE_DONUT)			//  If there's more then 0 filled donuts left then add the cost of one filled and subract one regular from tempReg
	{
		fillCost += PRICE_FILL;
		tempFill -= ONE_DONUT;
	}
	
	costTotal = fillCost + regCost;			// Calculates final cost before tax

// Output statements for how much the customer owes

	costTotal = costTotal * TAX_RATE;
	cout << "Customer owes $" << fixed << setprecision(2) << costTotal << endl;

// Customer input

	cout << "The customer pays: $";
	cin >> payment;

// Figuring out how much change is needed

	double change = payment - costTotal;

// Change output calculations

	if (change == 0)			// Correct change
	{
		cout << "Exact payment recieved - no change owed." << endl;
		return 0;
	}
	
	else						// Exact change not recieved
	{
		// Consideration for truncation errors
		int tempChange = (int)(100 * payment + 0.5) - (int)(100 * costTotal + 0.5);	//makes change easier to work with
	
		while (tempChange >= CENTS_PER_DOLLAR)
		{
			tempChange -= CENTS_PER_DOLLAR;
			dollar++;
		}
		while (tempChange >= CENTS_PER_QUARTER)
		{
			tempChange -= CENTS_PER_QUARTER;
			quarter++;
		}
		while (tempChange >= CENTS_PER_DIME)
		{
			tempChange -= CENTS_PER_DIME;
			dime++;
		}
		while (tempChange >= CENTS_PER_NICKEL)
		{
			tempChange -= CENTS_PER_NICKEL;
			nickel++;
		}
		while (tempChange >= CENTS_PER_PENNY)
		{
			tempChange -= CENTS_PER_PENNY;
			penny++;
		}
	}

// Output of correct change
	cout << "Change owed is $" << fixed << setprecision(2) << change << " - ";

	if (dollar > 0)
	{
		if (dollar == 1)
			cout << dollar << " dollar ";
		if (dollar > 1)
			cout << dollar << " dollars";
		//Determines whether to put a comma or period
		if (quarter == 0 && dime == 0 && nickel == 0 && penny == 0)
			cout << "." << endl;
		else
			cout << ", ";
	}
	if (quarter > 0)
	{
		if (quarter == 1)
			cout << quarter << " quarter";
		if (quarter > 1)
			cout << quarter << " quarters";
		//Determines whether to put a comma or period
		if (dime == 0 && nickel == 0 && penny == 0)
			cout << "." << endl;
		else
			cout << ", ";
	}
	if (dime > 0)
	{
		if (dime == 1)
			cout << dime << " dime";
		if (dime > 1)
			cout << dime << " dimes";
		//Determines whether to put a comma or period
		if (nickel == 0 && penny == 0)
			cout << "." << endl;
		else
			cout << ", ";

	}
	if (nickel > 0)
	{
		if (nickel == 1)
			cout << nickel << " nickel";
		//Determines whether to put a comma or period
		if (penny == 0)
			cout << "." << endl;
		else
			cout << ", ";
	}
	if (penny > 0)
	{
		if (penny == 1)
			cout << penny << " penny." << endl;
		else
			cout << penny << " pennies." << endl;
	}
	return 0;

	}