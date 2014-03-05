#include <iostream>
using namespace std;
#define MAX 6

class Revolver
{
private:
	struct Komora
	{
		int Bullet;
		Komora *Next;
	};
	Komora *kom;
	//Komora k1, k2, k3, k4, k5, k6;
public:
	Revolver::Revolver()
	{
		kom = new Komora;
		kom->Next = new Komora;
		kom->Next->Next = new Komora;
		kom->Next->Next->Next = new Komora;
		kom->Next->Next->Next->Next = new Komora;
		kom->Next->Next->Next->Next->Next = new Komora;

		kom->Bullet = 1;
		kom->Next->Bullet = 1;
		kom->Next->Next->Bullet = 1;
		kom->Next->Next->Next->Bullet = 1;
		kom->Next->Next->Next->Next->Bullet = 1;
		kom->Next->Next->Next->Next->Next->Bullet = 1;
	}
	~Revolver();
	bool Revolver::Fire()
	{
		if (kom->Bullet == 1)
		{
			kom->Bullet = 0;
			return 1;
		}
		else if (kom->Next->Bullet == 1)
		{
			kom->Next->Bullet = 0;
			return 1;
		}
		else if (kom->Next->Next->Bullet == 1)
		{
			kom->Next->Next->Bullet = 0;
			return 1;
		}
		else if (kom->Next->Next->Next->Bullet == 1)
		{
			kom->Next->Next->Next->Bullet = 0;
			return 1;
		}
		else if (kom->Next->Next->Next->Next->Bullet == 1)
		{
			kom->Next->Next->Next->Next->Bullet = 0;
			return 1;
		}
		else if (kom->Next->Next->Next->Next->Next->Bullet == 1)
		{
			kom->Next->Next->Next->Next->Next->Bullet = 0;
			return 1;
		}
		else return 0;
	}
	void Reload()
	{
		kom->Bullet = 1;
		kom->Next->Bullet = 1;
		kom->Next->Next->Bullet = 1;
		kom->Next->Next->Next->Bullet = 1;
		kom->Next->Next->Next->Next->Bullet = 1;
		kom->Next->Next->Next->Next->Next->Bullet = 1;
	}
};

int main()
{
	Revolver *rev = new Revolver;

	cout << rev->Fire();
	cout << rev->Fire();
	cout << rev->Fire();
	cout << rev->Fire();
	cout << rev->Fire();
	cout << rev->Fire();
	cout << rev->Fire() << endl;

	rev->Reload();

	cout << rev->Fire();
	cout << rev->Fire();
	cout << rev->Fire();
	cout << rev->Fire();
	cout << rev->Fire();
	cout << rev->Fire();
	cout << rev->Fire();

	getchar();
	return 0;
}