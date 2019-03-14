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
			cout << "You win "<< this->name<<"!" << endl;
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
			this->hp = 1000;
			this->reward_c = 600;
			
			this->defence = 35;
			break;
		case 2:
			this->boss_id = 2;
			this->damage = 95;
			this->name = "Velzevul2";
			this->hp = 1800;
			this->reward_c = 1100;
			
			this->defence = 65;
			break;
		case 3:
			this->boss_id = 3;
			this->damage = 150;
			this->name = "Velzevul3";
			this->hp = 2900;
			this->reward_c = 2250;
			
			this->defence = 90;
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
	this->reward_xp = 0;
}
boss::~boss() {

}

}
