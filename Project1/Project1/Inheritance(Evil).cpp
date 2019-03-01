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
	this->xp = 300;
	this->defence = 150;
	this->damage = 200;
	this->name = "Wolf level 2";
}
/////////////////////////////////////////////////////
Goblin::Goblin()
{
	this->name = "Goblin level 3";
	this->damage = 250;
	this->defence = 100;
	this->price_for_killing = 20;
	this->xp = 200;
}

void Goblin::Die_phrase()
{
	cout << "You killed goblin " << endl;
}
///////////////////////////////////////////
Monster::Monster()
{
	this->name = "Monster level 10";
	this->damage = 500;
	this->defence = 300;
	this->price_for_killing = 100;
	this->xp = 400;
}
void Monster::Die_phrase()
{
	cout << "You killed monster " << endl;
}
