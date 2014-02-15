#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

class vytah
{
private:
	int patro;
public:
	vytah(int p);
	~vytah();
	int zjistiPatro();
	void nahoru();
	void dolu();
};

vytah::vytah(int p)
{
	this->patro = p;
	cout << "Objekt vytah s parametrem patro = " << patro << " se vytvoril!" << endl;
}

vytah::~vytah()
{
	cout << endl << "Objekt vytah s parametrem patro = " << patro << " byl uvolnen!" << endl;
}

int vytah::zjistiPatro()
{
	return this->patro;
}

void vytah::nahoru()
{
	patro++;
}

void vytah::dolu()
{
	patro--;
}

int main()
{
	int randomNumber = 0;
	vytah *vytah01 = new vytah(0);

	for (int i = 0; i < 200; i++)
	{
		randomNumber = rand() % 2;
		if (randomNumber == 1)
		{
			if (vytah01->zjistiPatro() != 3){
				vytah01->nahoru();
				cout << vytah01->zjistiPatro() << "\t";
			}
		}
		else
		{
			if (vytah01->zjistiPatro() != 0){
				vytah01->dolu();
				cout << vytah01->zjistiPatro() << "\t";
			}
		}
	}

	delete vytah01;
	getchar();
	return 0;
}
