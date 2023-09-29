#include <iostream>

using namespace std;

bool isCardValid(int digits[], int size);

int main() {
	const int SIZE_OF_CARD = 17;

	char card[SIZE_OF_CARD];
	int cardNum[SIZE_OF_CARD];

	while (true) {
		cout << "Enter 16-digit credit card # or Q to quit: ";
		cin.getline(card, SIZE_OF_CARD);

		if (card[0] == 'Q' || card[0] == 'q') return 0;

		for (int i = 0; i < SIZE_OF_CARD; i++) {
			if (card[i] == '0')
				cardNum[i] = 0;
			if (card[i] == '1')
				cardNum[i] = 1;
			if (card[i] == '2')
				cardNum[i] = 2;
			if (card[i] == '3')
				cardNum[i] = 3;
			if (card[i] == '4')
				cardNum[i] = 4;
			if (card[i] == '5')
				cardNum[i] = 5;
			if (card[i] == '6')
				cardNum[i] = 6;
			if (card[i] == '7')
				cardNum[i] = 7;
			if (card[i] == '8')
				cardNum[i] = 8;
			if (card[i] == '9')
				cardNum[i] = 9;
		}

		if (isCardValid(cardNum, SIZE_OF_CARD - 1))
			cout << "Card is Valid" << endl << endl;
		else
			cout << "Card is not Valid" << endl << endl;
	}
}

bool isCardValid(int digits[], int size) {
	for (int i = 0; i < size; i++) {
		if (i % 2 == 0) {
			digits[i] *= 2;
			int first = digits[i] / 10;
			int second = digits[i] % 10;
			digits[i] = first + second;
		}
	}

	int sum = 0;

	for (int i = 0; i < size; i++) sum += digits[i];
	sum %= 10;

	if (sum == 0) return true;
	else          return false;
}
