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
	RandomNumber *xx = new RandomNumber();
	cout << xx->GetRandomNumber(0, 100) << endl;
	cout << xx->GetRandomNumber(0, 100) << endl;
	delete xx;

	system("pause");
	return 0;
}