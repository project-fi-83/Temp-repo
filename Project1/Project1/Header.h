#pragma once
#include<string>
using namespace std;


// Считает количество урона который нанёс Герой 
/////////////////////////////////
class Monster;
class Wolf;
class Evil;
////////////////////////////////////////////////////////////////////////////////
class Hero
{
protected:
	string name;
	double xp;
	double defence;
	double money;
	int level;
	double mana;
	double damage;
	double intelligence;
	bool knife_e;
	bool woodenshield_e;
	bool sword_e;
	bool shield_heavy_e;
	bool book_e;
	bool stick_e;

	int health_points;
public:

	Hero(string name);
	void Add_health_points();
	void Change_mana( double value);
	void Change_intelligence(double value);
	void Change_xp(double x);
	void Change_defence(double value);
	void Change_damage(double value);
	void Change_money(double value);
	

	string Get_name();
	int Get_level();
	double Get_intelligence();
	double Get_mana();
	double Get_damage();
	double Get_money();
	double Get_xp();
	double Get_defence();
	int Get_health_points();

	double HP_info_level();
	void Regulate_hp();
	void Attack(Evil* enemy);
	void Use_health_point();

	void Level_control();
	
	int Check_inv(int a);
	void Show_inventar();
	friend void Statistics(Hero h);

	~Hero();
};

void Statistics(Hero h);
//////////////////////////////////////////////////////////////////////////////////////

class Evil
{
protected:
	double xp;
	string name;
	double damage;
	double price_for_killing;
	double defence;
public:
	double Get_defence();
	double Get_damage();
	double Get_xp();
	double Get_price_for_killing();
	void Change_xp(double value);
	string Get_name();
	virtual void Die_phrase();
	Evil();
};
//1-ый Наследник
class Wolf :public Evil
{
public:
	void Die_phrase()override;
	Wolf();
};
//2-ой наследник
class Goblin :public Evil
{
public:
	void Die_phrase()override;
	Goblin();
};
//3-ий наследник
class Monster :public Evil
{
public:
	void Die_phrase()override;
	Monster();
};

//////////////////////////////////
void Fight(Hero & hero, Evil * enemy);
void Condition(Hero hero, Evil * enemy);
void After_fight_contribution(double uron_to_hero, double uron_to_enemy, double zarabot_money);
void Shop(Hero &player);
void Menu_of_actions(Hero & hero);

void Delete_evils(Evil *wolf, Evil * goblin, Evil * monster);

