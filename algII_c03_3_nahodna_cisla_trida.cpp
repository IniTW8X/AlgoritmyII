#include <iostream>
using namespace std;

class RandomNumber{
private:
	int cislo;
public:
	RandomNumber();
	~RandomNumber();
	int GetRandomNumber(int min, int max);
};

int RandomNumber::GetRandomNumber(int min, int max)
{
	cislo = rand() % (max-min) + min;
	return cislo;
}
RandomNumber::RandomNumber()
{
	cislo = 0;
}
RandomNumber::~RandomNumber()
{
}

int main(){
	int c = 0;

	while (c >= -1 && c <= 100){
		cin >> c;
		if (c <= -1 || c >= 100) return 0;

		RandomNumber *xx = new RandomNumber[c];
		for (int i = 0; i < c; i++)
		{
			//xx[i] = RandomNumber();
			cout << xx[i].GetRandomNumber(0, 100) << endl;
		}
		delete [] xx;
	}
	system("pause");
	return 0;
}