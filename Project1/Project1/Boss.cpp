//#include<iostream>
//#include "Header.h"
//using namespace std;
//
//class boss {
//private:
//	int id; //1- lowest, 3 - final boss
//	string name; //name
//	int hp;
//	int defence;
//	int damage;
//	int reward_c; // money reward
//	int reward_xp; // xp reward
//public:
//	boss();
//	void attack(Hero h) {
//		//Calculates attack of monster
//	}
//	void death(Hero h) {
//		//Monster is dead
//
//	}
//	void lose() {
//		//Lose of the Hero
//	}
//	void boss_id(int a) {
//		switch (a)
//		{
//		case 1:
//			this->boss_id = 1;
//			this->damage = 40;
//			this->name = "Velzevul";
//			this->hp = 1000;
//			this->reward_c = 600;
//			this->reward_xp = 450;
//			this->defence = 35;
//			break;
//		case 2:
//			this->boss_id = 2;
//			this->damage = 95;
//			this->name = "Velzevul2";
//			this->hp = 1800;
//			this->reward_c = 1100;
//			this->reward_xp = 750;
//			this->defence = 65;
//			break;
//		case 3:
//			this->boss_id = 3;
//			this->damage = 150;
//			this->name = "Velzevul3";
//			this->hp = 2900;
//			this->reward_c = 2250;
//			this->reward_xp = 1300;
//			this->defence = 90;
//			break;
//		default:
//			break;
//		}
//
//	}
//	~boss();
//};
//boss::boss() {
//	this->id = 0;
//	this->name = " ";
//	this->attack = 0;
//	this->hp = 0;
//	this->defence = 0;
//	this->reward_c = 0;
//	this->reward_xp = 0;
//}
//boss::~boss() {
//
//}
//void boss_create(int stage) {
//	boss boss;
//	switch (stage)
//	{
//	case 1:
//		boss.boss_id = 1;
//		boss_create(1);
//		break;
//	case 2:
//		boss.boss_id = 2;
//		boss_create(2);
//		break;
//	case 3:
//		boss.boss_id = 3;
//		boss_create(3);
//		break;
//	default:
//		break;
//	}
//}