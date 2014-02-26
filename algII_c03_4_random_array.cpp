#include <iostream>
using namespace std;
#define MAX 100

class RandomArray{
private:
	int p;
	//int pole[MAX];
public:
	int GetLastItem();
	void AddItem(int item);
	RandomArray();
	~RandomArray();
};

int RandomArray::GetLastItem()
{
	p--;
	return pole[p];
}
void RandomArray::AddItem(int item)
{
	int *novePole = new int[p+1];
	if (p != 0)
	{
		for (int i = 0; i < p; i++)
		{

		}
	}
}
RandomArray::RandomArray()
{
	p = 1;
	int *pole = new int[p];
	cout << "Objekt vytvoren." << endl;
}
RandomArray::~RandomArray()
{
	cout << "Objekt uvolnen." << endl;
}

int main()
{
	RandomArray *xx = new RandomArray();

	xx->AddItem(10);
	xx->AddItem(20);
	xx->AddItem(30);

	cout << xx->GetLastItem() << endl;
	cout << xx->GetLastItem() << endl;
	cout << xx->GetLastItem() << endl;

	delete xx;
	system("pause");
	return 0;
}