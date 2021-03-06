#include<iostream>
#include<string>
#include "Header.h"
using namespace std;

extern int count_for_fight;
extern double count_for_level;

void Hero::Add_health_points()
{
	this->health_points++;
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
	else cout << "No money" << endl;// ��� �������

}
string Hero::Get_name()
{
	return this->name;
}
int Hero::Get_level()
{
	return this->level;
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
		return 1000;
	case 2:
		return 2000;
	case 3:
		return 3000;
	case 4:
		return 4000;
	case 5:
		return 5000;
	case 6:
		return 6000;
	case 7:
		return 7000;
	case 8:
		return 8000;
	case 9:
		return 9000;
	default:
		break;
	}
}
// ���������� ������������� HP � ����������� �� ������

void Hero::Regulate_hp()
{
	switch (this->level)
	{
	case 1:
		this->xp = 1000;
		break;
	case 2:
		this->xp = 2000;
		break;
	case 3:
		this->xp = 3000;
		break;
	case 4:
		this->xp = 4000;
		break;
	case 5:
		this->xp = 5000;
		break;
	case 6:
		this->xp = 6000;
		break;
	case 7:
		this->xp = 7000;
		break;
	case 8:
		this->xp = 8000;
		break;
	default:
		break;
	}
}
// ����������� �� - ��� �� �� ���������


void Hero::Attack(Evil * enemy)
{
	double uron_to_hero;
	double uron_to_enemy;
	double price_for_attack;


	uron_to_enemy = this->damage - 0.1*enemy->Get_defence();
	count_for_level += uron_to_enemy;
	this->Level_control();
	uron_to_hero = enemy->Get_damage() - 0.1*this->defence;
	price_for_attack = enemy->Get_price_for_killing() / 50;


	enemy->Change_xp(uron_to_enemy);
	this->Change_xp(uron_to_hero);
	this->Change_money(-price_for_attack);

	After_fight_contribution(uron_to_hero, uron_to_enemy, price_for_attack);
}

void Hero::Use_health_point()
{
	if (this->health_points <= 5 && this->health_points > 0)
	{
		this->health_points--;
		cout << " Left : " << this->health_points << " health_points" << endl;
		this->xp += 300;
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
	this->mana = 20;
	this->money = 100000;
	this->xp = 1000;
	this->defence = 50;
	this->damage = 100;
}

void Hero::Level_control()
{
	if (count_for_level > 50 && count_for_level <= 100)
	{
		this->level = 2;
	}
	if (count_for_level > 100 && count_for_level <= 200)
	{
		this->level = 3;
	}
	if (count_for_level > 200 && count_for_level <= 350)
	{
		this->level = 4;
	}
	if (count_for_level > 350 && count_for_level <= 500)
	{
		this->level = 5;
	}
	if (count_for_level > 500 && count_for_level <= 700)
	{
		this->level = 6;
	}
	if (count_for_level > 700 && count_for_level <= 950)
	{
		this->level = 7;
	}
	if (count_for_level > 950 && count_for_level <= 1200)
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
			shield_heavy_e = true;
			return 1;
			break;
		}
	case 5:
		if (book_e == true) {

			return 0;
		}
		else {
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
	if (this->book_e == true) cout << " Book of knowledge" << endl;
	if (this->knife_e == true) cout << " Knife" << endl;
	if (this->shield_heavy_e == true) cout << " Heavy shield" << endl;
	if (this->stick_e == true) cout << "  Strange stick " << endl;
	if (this->sword_e == true) cout << " Sword " << endl;
	if (this->woodenshield_e == true) cout << " Wooden shield" << endl;
}
Hero::~Hero()
{}
