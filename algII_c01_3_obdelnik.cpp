#include <iostream>
using namespace std;

class Rectangle
{
private:
	float dimA;
	float dimB;
public:
	Rectangle(float A, float B);
	~Rectangle();
	float getArea();
	float getPerimeter();
	float getdimA();
	float getdimB();
	void setdimA(float newA);
	void setdimB(float newB);
};
Rectangle::Rectangle(float A, float B)
{
	dimA = A;
	dimB = B;
	cout << "Objekt vytvoren!" << endl;
}
Rectangle::~Rectangle()
{
	cout << "Objekt uvolnen!" << endl;
}
float Rectangle::getArea()
{
	return dimA*dimB;
}
float Rectangle::getPerimeter()
{
	return (2 * dimA) + (2 * dimB);
}
float Rectangle::getdimA()
{
	return dimA;
}
float Rectangle::getdimB()
{
	return dimB;
}
void Rectangle::setdimA(float newA)
{
	dimA = newA;
}
void Rectangle::setdimB(float newB)
{
	dimB = newB;
}

int main()
{
	int A = 1, B = 1;
	Rectangle *c11 = new Rectangle(A, B);
	cout << "Strana A: " << c11->getdimA() << endl;
	cout << "Strana B: " << c11->getdimB() << endl;
	cout << "---------------------" << endl;
	cout << "Obsah: "<< c11->getArea() << endl;
	cout << "Obvod: "<< c11->getPerimeter() << endl;
	cout << "---------------------" << endl;

	while (A != 0 && B != 0)
	{
		cout << "Zadejte strany obdelnika: " << endl;
		cin >> A >> B;
		if (A == 0 || B == 0)
		{
			cout << "Cyklus ukoncen." << endl;
			break;
		}
		c11->setdimA(A);
		c11->setdimB(B);
		cout << "Strana A: " << c11->getdimA() << endl;
		cout << "Strana B: " << c11->getdimB() << endl;
		cout << "---------------------" << endl;
		cout << "Obsah: " << c11->getArea() << endl;
		cout << "Obvod: " << c11->getPerimeter() << endl;
		cout << "---------------------" << endl;
	}
	delete c11;
	system("pause");
}