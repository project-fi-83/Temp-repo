#include "Header.h"
#include <iostream>
using namespace std;
class Hero;

Boss::Boss()
{
	this->id = 0;
	this->name = " ";
	this->hp = 0;
	this->defence = 0;
	this->reward_c = 0;
}

	void Boss::attack(Hero & h) {
		int at = this->damage - 0.6*h.Get_defence();
		int af = h.Get_damage() - 0.6*this->defence + 0.5*h.Get_intelligence()+0.5*h.Get_mana();

		h.Change_xp(at);

		this->hp -= af;
		double reward_for_attack = reward_c / 30;
		After_fight_contribution(at, af, reward_for_attack);

	}
	void Boss::death(Hero & h) {
		if (this->hp <= 0) {
		
			cout << "You killed " << this->name << "!" << endl;
			h.Change_money(this->reward_c);
			if(this->id==3)	
			cout << this->name << " is dead. You have ceased your final deal and saved your village. \nNow people could sleep well. There is no threat for thier lives.\nBut be ready to face new dangerous..." << endl;

			this->boss_create(2);
		}
		else if (h.Get_xp() <= 0) {
			cout << "You lose!" << endl;

		}
		

	}

	void Boss::boss_create(int a) {
		switch (a)
		{
		case 1:
			this->id = 1;
			this->damage = 40;
			this->name = "Velzevul";
			this->hp = 450;
			this->reward_c = 300;

			this->defence = 30;
			break;
		case 2:
			this->id = 2;
			this->damage = 95;
			this->name = "Velzevul2";
			this->hp = 750;
			this->reward_c = 450;

			this->defence = 45;
			break;
		case 3:
			this->id = 3;
			this->damage = 120;
			this->name = "Drakula";
			this->hp = 1100;
			this->reward_c = 700;
			this->defence = 60;
			break;
		default:
			break;
		}

	}

	void Boss::Boss_Represent()
	{
		cout << "Your aim is to kill Drakula. It's your archenemy. He is great threat of your village" << endl;
		cout << " But before figth with him you need to cope with Velzevul and Velzevul2.\nGood luck)))" << endl;
	}

	int Boss::Get_id()
	{
		return this->id;
	}

	string Boss::Get_name()
	{
		return this->name;
	}

	double Boss::Get_hp()
	{
		return this->hp;
	}

	double Boss::Get_defence()
	{
		return this->defence;
	}

	double Boss::Get_damage()
	{
		return this->damage;
	}

	double Boss::Get_reward_c()
	{
		return this->reward_c;
	}

	bool Boss::Is_leader_dead()
	{
		if (this->id == 3)
		{
			if (this->hp <= 0)
			{
				return true;
			}
			return false;
		}
		return false;
	}

	void Boss::Change_hp(double value)
	{
		this->hp -= value;
	}

	Boss::~Boss()
	{
	}




