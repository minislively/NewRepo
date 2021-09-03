#include <iostream>
#include <string>

using namespace std;

class Character
{
private:
	string name;
	int ragePoint;
	int hp;
	int damage;

public :
	Character(string name, int hp, int damage) : name(name), ragePoint(0), hp(hp), damage(damage){}

	~Character()
	{
		cout << "[객체가 소멸됩니다.]\n";
	}
	void pointUp() { ragePoint++; }
	void show()
	{
		cout << name << "[" << ragePoint << "] " << hp << " " << damage << "\n";
	}
};

int main()
{
	Character* slime1 = new Character("슬라임", 10, 20);
	slime1->pointUp();
	Character slime2(*slime1);
	slime2.pointUp();
	slime1->show();

	delete slime1;
	system("pause");
	return 0;
}