#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
private: 
	int rank = 0;
	string name = "Name: ";
	string strad = "Street address: ";
	string city = "City: ";
	string state = "Two letter state abbreviation: ";
	string zip = "Zip Code: ";
public:
	Person();
	Person(string NAME, string STRAD, string CITY, string STATE, string ZIP);
	void printMailingLabel(void);
	bool setPersonalInfo(string NAME, string STRAD, string CITY, string STATE, string ZIP);
	bool Person::setRank(int RANK);
	int Person::getRank(void);
	string getZipCode();
};

void Person::printMailingLabel(void) {
	cout << name << endl << strad << endl << city << ", " << state << " " << zip << endl << endl;
}

int Person::getRank(void) {
	return rank;
}

bool Person::setPersonalInfo(string NAME, string STRAD, string CITY, string STATE, string ZIP) {
	name = NAME;
	strad = STRAD;
	city = CITY;
	state = STATE;
	zip = ZIP;
	return 1;
}

bool Person::setRank(int RANK) {
	rank = RANK;
	return 1;
}
Person::Person() {
	name = "test";
	strad= "test";
	city = "test";
	state = "test";
	zip = "test";
	rank = 0;
}

Person::Person(string NAME, string STRAD, string CITY, string STATE, string ZIP) {
	setPersonalInfo(NAME, STRAD, CITY, STATE, ZIP);
}

string Person::getZipCode() {
	return zip;
}

int main(void) {

	int entries;
	int max = 0;
	Person sort;
	string name = "Name: ";
	string strad = "Street address: ";
	string city = "City: ";
	string state = "Two letter state abbreviation: ";
	string zip = "Zip Code: ";


	cout << "Number of entries: ";
	cin >> entries;

	vector < Person> people(entries);
	cin.ignore();

	for (int i = 0; i < entries; i++) {

		cout << endl << "Record # " << i + 1 << ":" << endl;

		cout << "Enter name: ";
		getline(cin, name);
		cout << "Enter street address: ";
		getline(cin, strad);
		cout << "Enter city: ";
		getline(cin, city);
		cout << "Enter 2-letter state abbreviation: ";
		getline(cin, state);
		cout << "Enter zip code: ";
		getline(cin, zip);

		cout << endl;

		people[i] = Person(name, strad, city, state, zip);
	}

	cout << endl << "Your personalized mailing labels: " << endl << endl;

	for (int i = 0; i < entries; i++) {
		for (int j = 0; j < entries; j++) {
			if (people[i].getZipCode() <= people[j].getZipCode()) {
				sort = people[i];
				people[i] = people[j];
				people[j] = sort;
			}
		}
	}
	for (int i = 0; i < entries; i++) {
		people[i].printMailingLabel();
	}
}