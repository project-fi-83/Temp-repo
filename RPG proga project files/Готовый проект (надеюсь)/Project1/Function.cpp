#include<iostream>
#include<string>
#include "Header.h"
using namespace std;
 
extern int count_for_fight;
extern double count_for_level;

void Statistics(Hero h) {
	system("cls");
	cout << "Level: " << h.level << "\t\t" << "Your balance: " << h.money << " $" << endl;
	cout << "HP: " << h.xp << endl;
	cout << "Mana : " << h.mana << endl;
	cout << "Intelligence :" << h.Get_intelligence() << endl;
	cout << "Defence: " << h.defence << endl;
	cout << "Damage: " << h.damage << endl << endl;
}

bool Check_money(Hero h, int price)
{
	if (h.Get_money()-price >= 0 ) return true;
	else return false;
}

void Fight(Hero & hero, Evil * enemy)
{

	int choice = 0;
	do
	{

		if (count_for_fight <= 0) cout << "You have faced " << enemy->Get_name() << endl;

		cout << "\nChoose action : " << endl;
		cout << "\t\tYour HP :  " << hero.Get_xp() << endl;
		cout << "1. Attack" << endl;
		cout << "2. Use zillya" << endl;
		cout << "3. Back to village" << endl;
		
		cin >> choice;
		switch (choice)
		{
		case 1:
			count_for_fight++;
			system("cls");
			cout << "Before fighting : " << endl << endl;
			Condition(hero, enemy);
			system("pause");
			system("cls");
			cout << "______________________________________________________________________________" << endl;
			cout << "\n Fighting..." << endl << endl;
			system("pause");
			system("cls");
			hero.Attack(enemy);
			cout << "______________________________________________________________________________" << endl;
			cout << "After fighting : " << endl << endl;
			Condition(hero, enemy);
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			hero.Use_health_point();
			break;
		case 3:
			cout << "You go back to the village..." << endl;
			count_for_fight = 0;
			system("pause");
			system("cls");
			break;
	
		default:
			cout << "Wrong input !!!" << endl;
			break;
		}

	} while (hero.Get_xp() > 0 && enemy->Get_xp() > 0 && choice != 3);


	

}
///////////////////////////////////////////////
void Boss_Fight(Hero & hero, Boss & boss)
{
	int choice = 0;
	do
	{

		if (count_for_fight <= 0) cout << " You need to kill " << boss.Get_name() << " to move on" << endl;

		cout << "\nChoose action : " << endl;
		cout << "\t\tYour HP :  " << hero.Get_xp() << endl;
		cout << "1. Attack" << endl;
		cout << "2. Use zillya" << endl;
		cout << "3. Back to village" << endl;

		cin >> choice;
		switch (choice)
		{
		case 1:
			count_for_fight++;
			system("cls");
			cout << "Before fighting : " << endl << endl;
			Condition_Boss(hero, boss);
			system("pause");
			system("cls");
			cout << "______________________________________________________________________________" << endl;
			cout << "\n Fighting..." << endl << endl;
			system("pause");
			system("cls");
			boss.attack(hero);
			cout << "______________________________________________________________________________" << endl;
			cout << "After fighting : " << endl << endl;
			Condition_Boss(hero, boss);
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			hero.Use_health_point();
			break;
		case 3:
			cout << "You go back to the village..." << endl;
			count_for_fight = 0;
			system("pause");
			system("cls");
			break;

		default:
			cout << "Wrong input !!!" << endl;
			break;
		}


	} while (hero.Get_xp() > 0 && boss.Get_hp() > 0 && choice != 3 && boss.Is_leader_dead() == 0);
}
//////////////////////////////////////////////////
void Condition(Hero hero, Evil * enemy)
{
	if (hero.Get_xp() <= 0)
	{
		cout << "______________________________________________________________________________" << endl;
		cout << "You die ((((((((((((" << endl;
		count_for_fight = 0;
		cout << "Your HP = " << 0 << "\tYour money = " << hero.Get_money() << endl << endl;
	}
	else
	{
		cout << "______________________________________________________________________________" << endl;
		cout << "Your HP = " << hero.Get_xp() << "\tYour money = " << hero.Get_money() << endl << endl;
	}
	if (enemy->Get_xp() <= 0)
	{
		cout << "______________________________________________________________________________" << endl;
		double tmp;
		tmp = enemy->Get_price_for_killing();
		enemy->Die_phrase();
		cout <<"\t+" << tmp << "  to your balace." << endl;
		hero.Change_money(-tmp);
		count_for_fight = 0;
		cout << enemy->Get_name() << " HP = " << 0 << endl;
	}
	else
	{
		cout << "______________________________________________________________________________" << endl;
		cout << enemy->Get_name() << " HP = " << enemy->Get_xp() << endl;
	}
	cout << "Damage = " << enemy->Get_damage() << endl << endl;
}
void Condition_Boss(Hero hero, Boss boss)
{
	if (hero.Get_xp() <= 0)
	{
		cout << "______________________________________________________________________________" << endl;
		cout << "You die ((((((((((((" << endl;
		count_for_fight = 0;
		cout << "Your HP = " << 0 << "\tYour money = " << hero.Get_money() << endl << endl;
	}
	else
	{
		cout << "______________________________________________________________________________" << endl;
		cout << "Your HP = " << hero.Get_xp() << "\tYour money = " << hero.Get_money() << endl << endl;
	}
	if (boss.Get_hp() <= 0)
	{
		cout << "______________________________________________________________________________" << endl;
		double tmp;
		tmp = boss.Get_reward_c();
		boss.death(hero);
		cout << "\t+" << tmp << "  to your balace." << endl;
		hero.Change_money(-tmp);
		count_for_fight = 0;
		cout << boss.Get_name() << " HP = " << 0 << endl;
	}
	else
	{
		cout << "______________________________________________________________________________" << endl;
		cout << boss.Get_name() << " HP = " << boss.Get_hp() << endl;
	}
	cout << "Damage = " << boss.Get_damage() << endl << endl;
}
void After_fight_contribution(double uron_to_hero, double uron_to_enemy, double zarabot_money)
{
	
	cout << "______________________________________________________________________________" << endl;
	cout << "\t\tResult of attack" << endl;
	cout << "\n\nHero : \n  -" << uron_to_hero << "HP" << "\tMoney " << "+" << zarabot_money << endl;
	cout << " Enemy :" << "\n -" << uron_to_enemy << " Hp" << endl << endl;
	cout << "______________________________________________________________________________" << endl;

}


void Delete_evils(Evil *wolf, Evil * goblin, Evil * monster,Evil * witch, Evil * dragon)
{
	delete wolf;
	delete goblin;
	delete monster;
	delete witch;
	delete dragon;
}
///////////////////
void Display_Name(Evil* w, Evil* g, Evil* m, Evil* wh, Evil* d)
{
	cout << "The list of enemies you can meet in The Forest : " << endl;
	cout << w->Get_name() << endl;
	cout << g->Get_name() << endl;
	cout << m->Get_name() << endl;
	cout << wh->Get_name() << endl;
	cout << d->Get_name() << endl;
}












