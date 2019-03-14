#include<iostream>
#include<string>
#include "Header.h"
using namespace std;

void Wolf::Die_phrase()
{
	cout << "You killed facking wolf " << endl;
}

Wolf::Wolf()
{

	this->price_for_killing = 30;
	this->xp = 120;
	this->defence = 8;
	this->damage = 10;
	this->name = "Wolf level 2";
}
/////////////////////////////////////////////////////
Goblin::Goblin()
{
	this->name = "Goblin level 3";
	this->damage = 21;
	this->defence = 12;
	this->price_for_killing = 75;
	this->xp = 14;
}

void Goblin::Die_phrase()
{
	cout << "You killed goblin " << endl;
}
///////////////////////////////////////////
Monster::Monster()
{
	this->name = "Monster level 10";
	this->damage = 40;
	this->defence = 35;
	this->price_for_killing = 250;
	this->xp = 350;
}
void Monster::Die_phrase()
{
	cout << "You killed monster " << endl;
}
//Evil.cpp

//Inheritance(Evil).cpp
void Dragon::Die_phrase()
{
	cout << "You killed dragon" << endl;
}

Dragon::Dragon()
{
	this->price_for_killing = 80;
	this->xp = 150;
	this->defence = 12;
	this->damage = 23;
	this->name = "Dragon";
}

void Witch::Die_phrase()
{
	cout << "You killed witch" << endl;
}

Witch::Witch()
{
	this->price_for_killing = 60;
	this->xp = 110;
	this->defence = 11;
	this->damage = 18;
	this->name = "Witch";
}