#include <iostream>
using namespace std;

//Yep, they're both using only one revolver... Deal with it :P

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
	Revolver::~Revolver();
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
	void Revolver::Reload()
	{
		kom->Bullet = 1;
		kom->Next->Bullet = 1;
		kom->Next->Next->Bullet = 1;
		kom->Next->Next->Next->Bullet = 1;
		kom->Next->Next->Next->Next->Bullet = 1;
		kom->Next->Next->Next->Next->Next->Bullet = 1;
	}
};

class Creature :Revolver
{
private:
	int health;
	int power;
public:
	int wait;
	Creature::Creature(int h, int p)
	{
		health = h;
		power = p;
	}
	Creature::~Creature();

	int Creature::GetHealth()
	{
		return health;
	}
	int Creature::RecieveAttack(int attack)
	{
		int bonusAttack = (rand() % 10 + 1);
		if (Fire() == 1)
			return health = health - attack - bonusAttack;
		else
		{
			Reload();
			wait = 3;
			return health;
		}
	}
	void Creature::Attack(Creature *creature)
	{
		creature->RecieveAttack(power);
	}
};

int main()
{
	Creature *c1 = new Creature(226, 10);
	Creature *c2 = new Creature(226, 10);
	cout << "Creature 1 Start HP: " << c1->GetHealth() << endl;
	cout << "Creature 2 Start HP: " << c2->GetHealth() << endl;
	while ((c1->GetHealth() >= 0) && (c2->GetHealth() >= 0))
	{
		c1->Attack(c2);
		if (c1->wait != 0)
		{
			cout << "Creature 1 i reloading... (" << c1->wait - 1 << " turns remaining)" << endl;
			c1->wait = c1->wait - 1;
		}
		else
		{
			cout << "Creature 2 HP: " << c2->GetHealth() << endl;
		}
		c2->Attack(c1);
		if (c2->wait != 0)
		{
			cout << "Creature 2 i reloading... (" << c2->wait << " turns remaining)" << endl;
			c2->wait = c2->wait - 1;
		}
		else
		{
			cout << "Creature 1 HP: " << c1->GetHealth() << endl;
		}
	}
	cout << "FIGHT ENDED!" << endl;
	//delete c1, c2;
	getchar();
	return 0;
}