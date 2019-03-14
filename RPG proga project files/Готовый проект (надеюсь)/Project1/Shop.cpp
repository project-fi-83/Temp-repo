#include<iostream>
#include<string>
#include "Header.h"
using namespace std;

void Menu(Hero player);

	int knife_c = 50;
	int shieldW_c = 40;
	int sword_c = 200;
	int shield_heavy_c = 190;
	int book_c = 300;
	int stick_c = 777;
	int heal_c = 25;

	
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
				
				system("cls");

					if (Check_money(player, knife_c) == true)
					{
						if (player.Check_inv(1) == 1)
						{
						cout << "You have bought a Small knife  for " << knife_c << "G." << endl;

						player.Change_damage(15);
						player.Change_defence(5);
						player.Change_money(knife_c);
						}
						else if (player.Check_inv(1) == 0)
						{
							system("cls");
							cout << "You already have this item!" << endl;
							break;
						}
					}
					else
					{
						cout << "Not enought money" << endl;
					}
		
					break;
			case 2:
				system("cls");

					if (Check_money(player, shieldW_c) == true)
					{
						if (player.Check_inv(2) == 1)
						{
						cout << "You have bought a Wooden shield  for " << shieldW_c << "G." << endl;
						player.Change_defence(15);
						player.Change_damage(5);
						player.Change_money(shieldW_c);
					}
						else if (player.Check_inv(2) == 0) {
							system("cls");
							cout << "You already have this item!" << endl;
							break;
						}
					}
					else
					{
						cout << "Not enought money" << endl;
					}
					break;
			case 3:
				system("cls");

				if (Check_money(player, sword_c) == true)
				{
					if (player.Check_inv(3) == 1) {

						cout << "You have bought a Long sword  for " << sword_c << "G." << endl;
						player.Change_damage(18);
						player.Change_damage(10);
						player.Change_money(sword_c);
					}

					else if (player.Check_inv(3) == 0) {
						system("cls");
						cout << "You already have this item!" << endl;
						break;
					}
				}
					else
					{
						cout << "Not enought money" << endl;
					}
				
					break;
			case 4:
				system("cls");
					if (Check_money(player, shield_heavy_c) == true)
					{
						if (player.Check_inv(4) == 1) {
							
						cout << "You have bought a Heavy shield  for " << shield_heavy_c << "G." << endl;
						player.Change_defence(35);
						player.Change_damage(10);
						player.Change_intelligence(4);
						player.Change_money(shield_heavy_c);
					}
						else if (player.Check_inv(4) == 0) {
							system("cls");
							cout << "You already have this item!" << endl;
							break;
						}
					}
					else
					{
						cout << "Not enought money" << endl;
					}
					break;
			case 5:
				system("cls");
				if (Check_money(player, book_c) == true)
				{
					if (player.Check_inv(5) == 1) {
						cout << "You have bought a Book of knowledge  for " << book_c << "G." << endl;
						player.Change_defence(30);
						player.Change_intelligence(50);
						player.Change_mana(45);
						player.Change_money(book_c);
					}
					else if (player.Check_inv(5) == 0) {
						system("cls");
						cout << "You already have this item!" << endl;
						break;
					}
				}
				else
				{
					cout << "Not enought money" << endl;
				}
					break;
			case 6:
				system("cls");
				if (Check_money(player, stick_c) == true)
				{
					if (player.Check_inv(6) == 1) {
						cout << "You have bought a Strange stick  for " << stick_c << "G." << endl;
						player.Change_damage(50);
						player.Change_defence(30);
						player.Change_intelligence(100);
						player.Change_mana(23);
						player.Change_money(stick_c);
					}
					else if (player.Check_inv(6) == 0) {
						system("cls");
						cout << "You already have this item!" << endl;
						break;
					}
				}
					else
					{
						cout << "Not enought money" << endl;
					}
				
				break;
			case 7:
				system("cls");
				if (Check_money(player, heal_c) == true) 
				{
					cout << "You have bought health point " << endl;
					player.Add_health_points();
					cout << "Health points :\t" << player.Get_health_points() << endl;
				}
				else
				{
					cout << "Not enought money" << endl;
				}
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
	cout << "1. Small knife (50G)\t +5 damage" << endl;
	cout << "2. Wooden shield (40G)\t +5 defence" << endl;
	cout << "3. Long sword (200G)\t +18 damage" << endl;
	cout << "4. Heavy shield (190G)\t +19 defence" << endl;
	cout << "5. Book of Knowledge (300G)\t +5 intelect" << endl;
	cout << "6. Strange stick (777G)\t ???" << endl;
	cout << "7. Heal potion (25G)\t heal 25 HP " << endl;
	cout << " 8. Finish " << endl;
}