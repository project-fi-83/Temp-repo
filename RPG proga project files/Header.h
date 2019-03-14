#pragma once
#include<string>
using namespace std;
class Wolf;
class Hero
{
protected:
	string name;
	double xp;
	double defence;
	int strength;
	int money;
	int level;
	int mana;
	double damage;
public:

	Hero();

	void Change_strenght(int value);
	void Change_xp(int x);
	void Change_defence(int value);
	void Change_damage(int value);
	void Change_money(int value);
	void Show_xp();
	double Get_defence()
	{
		return this->defence;
	}
	//friend void Damage_wolf(Hero & h, Wolf &w);
	~Hero();
};


class Evil
{
protected:
	double xp;
	string name;
	double damage;
	double price_for_killing;
	double defence;
public:
	double Get_damage();
	virtual void Attack(Hero & h, Evil * evil);
	Evil();
};

class Wolf :public Evil
{
public:
	Wolf();
	void Attack(Hero & h, Evil * evil) override;
	//friend void Damage_wolf(Hero & h, Wolf &w);
};







