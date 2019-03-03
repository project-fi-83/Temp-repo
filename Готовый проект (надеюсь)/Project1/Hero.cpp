#include<iostream>
#include<string>
#include "Header.h"
using namespace std;
extern int count_for_invent;
extern int count_for_fight;
extern double count_for_level;

void Hero::Add_health_points()
{
	if (this->health_points < 5&& this->Get_money()>25)
	{
		this->health_points++;
		this->Change_money(25) ;
	}
	else cout << "You already have maximum health points - 5 " << endl;
}

void Hero::Change_mana(double value)
{
	this->mana += value;
}

void Hero::Change_intelligence(double value)
{
	this->intelligence += value;
}

void Hero::Change_xp(double x)
{
	this->xp -= x;
}
void Hero::Change_defence(double value)
{
	this->defence += value;
}
void Hero::Change_damage(double value)
{
	this->damage += value;
}
void Hero::Change_money(double value)
{
	if (this->money > 0)	this->money -= value;
	else cout << "Not enought money" << endl;// Для магазин

}
string Hero::Get_name()
{
	return this->name;
}
int Hero::Get_level()
{
	return this->level;
}
double Hero::Get_intelligence()
{
	return this->intelligence;
}
double Hero::Get_mana()
{
	return this->mana;
}
double Hero::Get_damage()
{
	return this->damage;
}
double Hero::Get_money()
{
	return this->money;
}
double Hero::Get_xp()
{
	return this->xp;
}
double Hero::Get_defence()
{
	return this->defence;
}
int Hero::Get_health_points()
{
	return this->health_points;
}

double Hero::HP_info_level()
{
	switch (this->level)
	{
	case 1:
		return 100;
	case 2:
		return 120;
	case 3:
		return 140;
	case 4:
		return 160;
	case 5:
		return 200;
	case 6:
		return 230;
	case 7:
		return 260;
	case 8:
		return 300;
	default:
		break;
	}
}
// Количество максимального HP в зависимости от уровня

void Hero::Regulate_hp()
{
	switch (this->level)
	{
	case 1:
		this->xp = 100;
		break;
	case 2:
		this->xp = 120;
		break;
	case 3:
		this->xp = 140;
		break;
	case 4:
		this->xp = 160;
		break;
	case 5:
		this->xp = 200;
		break;
	case 6:
		this->xp = 230;
		break;
	case 7:
		this->xp = 260;
		break;
	case 8:
		this->xp = 300;
		break;
	default:
		break;
	}
}
// Регулировка НР - что бы не привысило


void Hero::Attack(Evil * enemy)
{
	double uron_to_hero;
	double uron_to_enemy;
	double price_for_attack;


	uron_to_enemy = this->damage - 0.3*enemy->Get_defence();
	count_for_level += uron_to_enemy;
	this->Level_control();
	uron_to_hero = enemy->Get_damage() - 0.3*this->defence;
	price_for_attack = enemy->Get_price_for_killing() / 25;


	enemy->Change_xp(uron_to_enemy);
	this->Change_xp(uron_to_hero);
	this->Change_money(-price_for_attack);

	After_fight_contribution(uron_to_hero, uron_to_enemy, price_for_attack);
}

void Hero::Use_health_point()
{
	if ( this->health_points > 0)// убрать условие меньше пяти
	{
		this->health_points--;
		cout << " Left : " << this->health_points << " health_points" << endl;
		this->xp += 50 + this->level * 10;
		if (this->xp > this->HP_info_level())
		{
			this->Regulate_hp();
		}
		cout << "Your HP :\t" << this->xp << endl;
	}
	else
	{
		cout << "No health_points" << endl;
	}
}


Hero::Hero(string name)
{
	this->health_points = 0;
	this->name = name;
	this->level = 1;
	this->mana = 15;
	this->intelligence = 5;
	this->money = 150;
	this->xp = 100;
	this->defence = 6;
	this->damage = 15;
}

void Hero::Level_control()
{
	if (count_for_level > 100 && count_for_level <= 200)
	{
		this->level = 2;
	}
	if (count_for_level > 200 && count_for_level <= 350)
	{
		this->level = 3;
	}
	if (count_for_level > 350 && count_for_level <= 500)
	{
		this->level = 4;
	}
	if (count_for_level > 500 && count_for_level <= 750)
	{
		this->level = 5;
	}
	if (count_for_level > 750 && count_for_level <= 1000)
	{
		this->level = 6;
	}
	if (count_for_level > 1000 && count_for_level <= 1500)
	{
		this->level = 7;
	}
	if (count_for_level > 1500 )
	{
		this->level = 8;
	}

}

int Hero::Check_inv(int a) {
	switch (a) {
	case 1:
		if (knife_e == true) {

			return 0;
			break;
		}
		else {
			count_for_invent++;
			knife_e = true;
			return 1;
			break;
		}
	case 2:
		if (woodenshield_e == true) {

			return 0;
			break;
		}
		else {
			count_for_invent++;
			woodenshield_e = true;
			return 1;
			break;
		}
	case 3:
		if (sword_e == true) {

			return 0;
			break;
		}
		else {
			count_for_invent++;
			sword_e = true;
			return 1;
			break;
		}
	case 4:
		if (shield_heavy_e == true) {

			return 0;
			break;
		}
		else {
			count_for_invent++;
			shield_heavy_e = true;
			return 1;
			break;
		}
	case 5:
		if (book_e == true) {

			return 0;
		}
		else {
			count_for_invent++;
			book_e = true;
			return 1;
			break;
		}
	case 6:
		if (stick_e == true) {

			return 0;
			break;
		}
		else {
			count_for_invent++;
			stick_e = true;
			return 1;
			break;
		}
	
	default:
		break;


	}

}
void Hero::Show_inventar()
{
	int count = 0;
	if (this->book_e == true)
	{
		cout << " Book of knowledge" << endl;
		count++;
	}
	if (this->knife_e == true)
	{
		cout << " Knife" << endl;
		count++;
	}
	if (this->shield_heavy_e == true)
	{
		cout << " Heavy shield" << endl;
		count++;
	}
	if (this->stick_e == true)
	{
		cout << "  Strange stick " << endl;
		count++;
	}
	if (this->sword_e == true) 
	{
		cout << " Sword " << endl;
		count++;
	}
	if (this->woodenshield_e == true) 
	{
		cout << " Wooden shield" << endl;
		count++;
	}
	if (count == 0)
	{
		cout << "Your inventary is Empty" << endl;
	}
	system("pause");
	system("cls");
}
Hero::~Hero()
{}
