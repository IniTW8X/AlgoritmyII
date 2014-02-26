#include <iostream>
using namespace std;

int main()
{
	int c = 0;

	while (c >= -1 && c <= 100){
		cin >> c;
		if (c <= -1 || c >= 100) return 0;

		int *pole = new int[c];
		for (int i = 0; i < c; i++)
		{
			pole[i] = rand() % 100 + 1;
		}
		for (int i = 0; i < c; i++)
		{
			cout << pole[i] << endl;
		}
		delete pole;
	}
	system("pause");
	return 0;
}
