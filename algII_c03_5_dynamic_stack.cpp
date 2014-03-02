#include <iostream>
using namespace std;

class DStack
{
private:
	float *ocas;
	float *hlava;
	int velikost;

public:
	DStack(int size = 20);
	void push(float hodnota);
	int pocet_zaznamu() const;
	float pop();
	int full() const;
	int empty() const;
	~DStack();
};

DStack::DStack(int N)
{                       
	ocas = new float[N];
	hlava = ocas;
	velikost = N;
}

DStack::~DStack()                   
{                                  
	delete[] ocas;
}

int DStack::pocet_zaznamu() const  
{
	return (hlava - ocas);
}

void DStack::push(float hodnota)   
{
	if (full() == 1)
	{
		cout << "Stack overflow!" << endl;
	}
	else
	{
		*hlava = hodnota;
		hlava++;
	}
}

float DStack::pop()             
{
	if (empty() == 1)
	{
		cout << "Stack underflow!" << endl;
		return NULL;
	}
	else
	{
		hlava--;
		return *hlava;
	}
}


int DStack::full() const   
{
	return (pocet_zaznamu() >= velikost);
}


int DStack::empty() const      
{
	return (pocet_zaznamu() <= 0);
}


int main()
{
	DStack *S = new DStack(4);

	S->push(2.31);
	S->push(1.19);
	S->push(6.78);
	S->push(0.54);
	S->push(0.55);

	cout << S->pop() << endl;
	cout << S->pop() << endl;
	cout << S->pop() << endl;
	cout << S->pop() << endl;
	cout << S->pop() << endl;
	getchar();
	delete S;
	return 0;
}
