#include<iostream>
#include<string>
#include "Header.h"
using namespace std;

void Menu(Hero player);
	int knife_c = 25;
	int shieldW_c = 20;
	int sword_c = 150;
	int shield_heavy_c = 170;
	int book_c = 200;
	int stick_c = 1000;
	int heal_c = 15;

	
	int buy_a = 0;

void Shop(Hero &player)
{
		do
		{
			Menu(player);
			cin >> buy_a;
			switch (buy_a)
			{
			case 1:
				if (player.Check_inv(1) == 1)
				{
					system("cls");

					cout << "You have bought a Small knife +5 damage for " << knife_c << "G." << endl;
					player.Change_damage(15);
					player.Change_defence(5);
					player.Change_money(knife_c);

					break;
				}
				else if (player.Check_inv(1) == 0)
				{
					system("cls");
					cout << "You already have this item!" << endl;
					break;
				}
				else
				{
					break;
				}

			case 2:
				if (player.Check_inv(2) == 1)
				{
					system("cls");

					cout << "You have bought a Wooden shield +5 defence for " << shieldW_c << "G." << endl;
					player.Change_defence(15);
					player.Change_damage(5);
					player.Change_money(shieldW_c);

					break;
				}
				else if (player.Check_inv(2) == 0) {
					system("cls");
					cout << "You already have this item!" << endl;
					break;
				}
				else {
					break;
				}

			case 3:
				if (player.Check_inv(3) == 1) {
					system("cls");

					cout << "You have bought a Long sword +18 damage for " << sword_c << "G." << endl;
					player.Change_damage(18);
					player.Change_damage(10);
					player.Change_money(sword_c);

					break;
				}
				else if (player.Check_inv(3) == 0) {
					system("cls");
					cout << "You already have this item!" << endl;
					break;
				}
				else {
					break;
				}
			case 4:
				if (player.Check_inv(4) == 1) {
					system("cls");

					cout << "You have bought a Heavy shield +19 defence for " << shield_heavy_c << "G." << endl;
					player.Change_defence(19);
					player.Change_damage(10);
					player.Change_intelligence(4);
					player.Change_money(shield_heavy_c);

					break;
				}
				else if (player.Check_inv(4) == 0) {
					system("cls");
					cout << "You already have this item!" << endl;
					break;
				}
				else {
					break;
				}
			case 5:
				if (player.Check_inv(5) == 1) {
					system("cls");

					cout << "You have bought a Book of knowledge +5 intelect for " << book_c << "G." << endl;
					player.Change_defence(30);
					player.Change_intelligence(50);
					player.Change_mana(45);
					player.Change_money(book_c);

					break;
				}
				else if (player.Check_inv(5) == 0) {
					system("cls");
					cout << "You already have this item!" << endl;
					break;
				}
				else {
					break;
				}
			case 6:
				if (player.Check_inv(6) == 1) {
					system("cls");

					cout << "You have bought a Strange stick  for " << stick_c << "G." << endl;
					player.Change_damage(50);
					player.Change_defence(30);
					player.Change_intelligence(100);
					player.Change_mana(23);
					player.Change_money(stick_c);

					break;
				}
				else if (player.Check_inv(6) == 0) {
					system("cls");
					cout << "You already have this item!" << endl;
					break;
				}
				else {
					break;
				}
			case 7:
				system("cls");
				cout << "You have bought health point " << endl;
				player.Add_health_points();
				cout << "Health points :\t" << player.Get_health_points() << endl;
				break;
			default:
				system("cls");
				break;
			}
		} while (buy_a != 8);
	
}

	   	 
void Menu(Hero hero)

{
	static int count = 0;
	count++;
	if (count == 1) cout << "Welcome to the shop!" << endl;
	cout << "Choose, what you want to buy!\t\t Your balance :  " << hero.Get_money() << endl;
	cout << "1. Small knife (25G)\t +5 damage" << endl;
	cout << "2. Wooden shield (20G)\t +5 defence" << endl;
	cout << "3. Long sword (150G)\t +18 damage" << endl;
	cout << "4. Heavy shield (170G)\t +19 defence" << endl;
	cout << "5. Book of Knowledge (200G)\t +5 intelect" << endl;
	cout << "6. Strange stick (1000G)\t ???" << endl;
	cout << "7. Heal potion (15G)\t heal 25 HP " << endl;
	cout << " 8. Finish " << endl;
}