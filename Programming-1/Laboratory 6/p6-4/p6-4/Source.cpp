#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(void)
{
	srand(time(0));

	for (int drunk = 1; drunk <= 10; drunk++)
	{
		int y = 0;
		int x = 0;
		int num = 0;
		for (int i = 0; i <= 100; i++)
		{
			num = rand() % 4 + 1;
			if (num == 1) y++;
			if (num == 2) y--;
			if (num == 3) x++;
			if (num == 4) x--;
		}
		cout << "Drunkard #" << drunk << ": at intersection (" << x << ", " << y << ")" << endl;
	}

}