#include "Header.h"
#include <iostream>
using namespace std;

class boss {
private:
	int id; //1- lowest, 3 - final boss
	string name; //name
	double hp;
	int defence;
	int damage;
	int reward_c; // money reward

public:
	boss();
	void setboss() {

	}
	void getboss() {

	}
	void attack(Hero h) {
		double at = this->damage - 0.6*h.Get_defence();
		double af = h.Get_damage() - 0.6*this->defence;
		h.Change_xp(at);
		this->hp -= af;

	}
	void death(Hero h) {
		if (this->hp <= 0) {
			cout << "You win " << this->name << "!" << endl;
			h.Change_money(this->reward_c);

			this->boss_id(2);
		}
		else if (h.Get_xp() <= 0) {
			cout << "You lose!" << endl;

		}

	}

	void boss_id(int a) {
		switch (a)
		{
		case 1:
			this->boss_id = 1;
			this->damage = 40;
			this->name = "Velzevul";
			this->hp = 450;
			this->reward_c = 300;

			this->defence = 30;
			break;
		case 2:
			this->boss_id = 2;
			this->damage = 95;
			this->name = "Putin";
			this->hp = 750;
			this->reward_c = 450;

			this->defence = 45;
			break;
		case 3:
			this->boss_id = 3;
			this->damage = 120;
			this->name = "Kravzov - Experimental Battle Mechnoid";
			this->hp = 1100;
			this->reward_c = 700;

			this->defence = 60;
			break;
		default:
			break;
		}

	}
	~boss();
};
boss::boss() {
	this->id = 0;
	this->name = " ";
	this->attack = 0;
	this->hp = 0;
	this->defence = 0;
	this->reward_c = 0;
	
}
boss::~boss() {

}


