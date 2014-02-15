#include <iostream>
using namespace std;

class Bunka
{
private:
	int klic;
	float hodnota;

public:
	Bunka(int k, float h);
	~Bunka();
	float ziskejHodnotu();
	void nastavHodnotu(float h);
};

	Bunka::Bunka(int k, float h)
	{
		this->klic = k;
		this->hodnota = h;
		cout << "Objekt Bunka byl vytvoren." << endl;
	}
	Bunka::~Bunka()
	{
		cout << "Objekt Bunka byl uvolnen." << endl;
	}

	float Bunka::ziskejHodnotu()
	{
		return this->hodnota;
	}
	void Bunka::nastavHodnotu(float h)
	{
		hodnota = h;
	}


int main()
{
	//staticka cast
	cout << "STATICKY:" << endl;
	Bunka c11(1, 226272);
	cout << "Hodnota Bunky: " << c11.ziskejHodnotu() << "." << endl;
	c11.nastavHodnotu(22222);
	cout << "Hodnota Bunky po zmene: " << c11.ziskejHodnotu() << "." << endl;

	// dynamicka cast
	cout << endl << "DYNAMICKY:" << endl;
	Bunka *c12 = new Bunka(2, 33546);
	cout << "Hodnota Bunky: " << c12->ziskejHodnotu() << "." << endl;
	c12->nastavHodnotu(33333);
	cout << "Hodnota Bunky po zmene: " << c12->ziskejHodnotu() << "." << endl;
	delete c12;

	getchar();
	return 0;
}