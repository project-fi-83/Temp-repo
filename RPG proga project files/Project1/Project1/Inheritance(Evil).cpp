#include<iostream>
#include<string>
#include "Header.h"
using namespace std;

void Wolf::Die_phrase()
{
	cout << "You killed wolf" << endl;
}

Wolf::Wolf()
{

	this->price_for_killing = 30;
	this->xp = 120;
	this->defence = 8;
	this->damage = 10;
	this->name = "Wolf ";
}
/////////////////////////////////////////////////////
Goblin::Goblin()
{
	this->name = "Goblin";
	this->damage = 21;
	this->defence = 13;
	this->price_for_killing = 75;
	this->xp = 140;
}

void Goblin::Die_phrase()
{
	cout << "You killed goblin " << endl;
}
///////////////////////////////////////////
Monster::Monster()
{
	this->name = "The unknown monster";
	this->damage = 40;
	this->defence = 35;
	this->price_for_killing = 250;
	this->xp = 350;
}
void Monster::Die_phrase()
{
	cout << "You killed The Unknown monster " << endl;
}
