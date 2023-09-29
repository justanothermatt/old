// conversion.cpp - Matt Walker -0 24 August 2017
// Program will accept input in the form: number letter (e.g. 32 F)
// and will convert the specified temperature from Fahrenheit to Celsius
// or vice versa, depending on input (either C or F).

#include <iostream>		// import library that allows us to use cin and cout

using namespace std;	// considered "magic" until later...

const char FAHRENHEIT = 'F';
const char CELCIUS = 'C';

int main(void) {
	// enter "magic" formula floating-point output values
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(1);

	// variable declarations

	double inputTemperatures;
	double convertedTemperatures;
	char temperatureScale;
	char convertedScale;

	// get the temperature to be converted
	cout << "Please enter temperature - indicate scale with C or F: ";
	cin >> inputTemperatures >> temperatureScale;

	// determine if legal was entered
	if (temperatureScale != FAHRENHEIT && temperatureScale != CELCIUS) {
		// Bailing out program due to illegal input
		cout << "Sorry - temperature scale must be either in C or F.\n";
		return 1;
	}
	// determine what conversion formula to use
	if (temperatureScale == FAHRENHEIT) {
		convertedTemperatures = (inputTemperatures - 32) * 5.0 / 9.0;
		convertedScale = CELCIUS;
	}
	else { // input was in Celcius
		convertedTemperatures = 9.0 / 5.0 * inputTemperatures + 32.0;
		convertedScale = FAHRENHEIT;
	}

	//present result and terminate program execution
	cout << convertedTemperatures << " " << convertedScale << endl;
	return 0;
}