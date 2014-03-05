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

class Creature:Revolver
{
private:
	int health;
	int power;
public:
	int wait;
	Creature(int h, int p)
	{
		health = h;
		power = p;
	}

	int GetHealth()
	{
		return health;
	}
	int RecieveAttack(int attack)
	{
		if (Fire() == 1)
			return health = health - attack;
		else 
		{
			Reload();
			wait = 3;
			return health;
		}
	}
	void Attack(Creature *creature)
	{
		creature->RecieveAttack(power);
	}
};

int main()
{
	Creature *c1 = new Creature(20, 1);
	Creature *c2 = new Creature(226, 1);
	cout << "Creature 1 HP: " << c1->GetHealth() << endl;
	cout << "Creature 2 HP: " << c2->GetHealth() << endl;
	while ((c1->GetHealth() >= 0) && (c2->GetHealth() >= 0))
	{
		c1->Attack(c2);
		if (c1->wait != 0)
		{
			cout << "Nabijeni hrace 1..." << endl;
			c1->wait = c1->wait - 1;
		}
		cout << "Creature 2 HP: " << c2->GetHealth() << endl;
		c2->Attack(c1);
		if (c2->wait != 0)
		{
			cout << "Nabijeni hrace 2..." << endl;
			c2->wait = c1->wait - 1;
		}
		cout << "Creature 1 HP: " << c1->GetHealth() << endl;
	}


	getchar();
	return 0;
}