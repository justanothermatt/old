#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string dayOfWeek(int month, int day, int year);
string monthOfYear(int month);

int main(void) {
	int numDay;
	int numMonth;
	int numYear;

	string day;
	string month;

	while (true) {
		cout << "Enter a date or Q to quit: ";
		cin >> numMonth >> numDay >> numYear;

		if (cin.fail()) { break;}
		day = dayOfWeek(numMonth, numDay, numYear);
		month = monthOfYear(numMonth);

		cout << day << ", " << month << " " << numDay << ", " << numYear << endl << endl;
	}
	return 0;
}

string dayOfWeek(int month, int day, int year) {
	
	int h = 0;
	int q = day;
	int y = year;
	int m = month;
	
	if (m == 1 || m == 2) {
	m = m + 12; 
	y = y - 1; 
	}

	h = (q + (((m + 1) * 26) / 10) + y + (y / 4) + (6 * (y / 100)) + (y / 400)) % 7;
	
	if (h == 0) { return "Saturday"; }
	if (h == 1) { return "Sunday"; }
	if (h == 2) { return "Monday"; }
	if (h == 3) { return "Tuesday"; }
	if (h == 4) { return "Wednesday"; }
	if (h == 5) { return "Thursday"; }
	if (h == 6) { return "Friday"; }
}

string monthOfYear(int month) {
	
	if (month == 1) { return "January"; }
	if (month == 2) { return "February"; }
	if (month == 3) { return "Macrh"; }
	if (month == 4) { return "April"; }
	if (month == 5) { return "May"; }
	if (month == 6) { return "June"; }
	if (month == 7) { return "July"; }
	if (month == 8) { return "August"; }
	if (month == 9) { return "September"; }
	if (month == 10) { return "October"; }
	if (month == 11) { return "November"; }
	if (month == 12) { return "December"; }
}