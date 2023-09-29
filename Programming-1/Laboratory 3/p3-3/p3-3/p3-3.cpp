#include <iostream>

using namespace std;

int main() {
	int bookCost;
	int bookNum;
	double tax = 1.075;
	int shipping = 2;
		
	cout << "What is the cost for all books? : ";
		cin >> bookCost;
	cout << "How many books were purchased? : ";
		cin >> bookNum;

		cout << "Your order total is: " <<
			(bookCost * tax) + (shipping * bookNum) << endl;
		return 0;
}