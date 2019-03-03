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

bool Check_money(Hero h,int price);
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
	Evil(double x, string n, double dd, double df, double pfk);
	Evil(const Evil& e);

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
class Dragon : public Evil
{
public:
	void Die_phrase()override;
	Dragon();
};

class Witch : public Evil
{
public:
	void Die_phrase()override;
	Witch();
};

//////////////////////////////////
/*
	Boss class
*/
class Boss
{
private:
	int id; //1- lowest, 3 - final boss
	string name; //name
	double hp;
	int defence;
	double damage;
	double reward_c; // money reward
public:
	Boss();
	void attack(Hero & h);
	void death(Hero & h);
	void boss_create(int a);
	void Boss_Represent();
	int Get_id();
	string Get_name();
	double Get_hp();
	double Get_defence();
	double Get_damage();
	double Get_reward_c();
	bool Is_leader_dead();

	void Change_hp(double value);
	


	~Boss();



};




void Fight(Hero & hero, Evil * enemy);
void Boss_Fight(Hero &hero, Boss &boss);
void Condition(Hero hero, Evil * enemy);
void Condition_Boss(Hero hero,Boss boss);
void After_fight_contribution(double uron_to_hero, double uron_to_enemy, double zarabot_money);
void Shop(Hero &player);
void Menu_of_actions(Hero & hero, Boss & boss);

void Delete_evils(Evil *wolf, Evil * goblin, Evil * monster,Evil* witch,Evil * dragon);


void Display_Name(Evil * w, Evil* g, Evil* m, Evil* wh, Evil* d);
