#include <iostream>
using namespace std;

class Creature
{
private:
	int health;
	int power;
public:
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
		return health = health - attack;
	}
	void Attack(Creature *creature)
	{
		creature->RecieveAttack(power);
	}
};

int main()
{
	Creature *c1 = new Creature(20, 2);
	Creature *c2 = new Creature(226, 4);
	cout << "Creature 1 HP: " << c1->GetHealth() << endl;
	cout << "Creature 2 HP: " << c2->GetHealth() << endl;
	while ((c1->GetHealth() >= 0) && (c2->GetHealth() >= 0)){
		c1->Attack(c2);
		cout << "Creature 2 HP: " << c2->GetHealth() << endl;
		c2->Attack(c1);
		cout << "Creature 1 HP: " << c1->GetHealth() << endl;
	}


	getchar();
	return 0;
}