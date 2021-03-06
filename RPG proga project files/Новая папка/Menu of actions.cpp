#include<iostream>
#include "Header.h"
#include<time.h>
using namespace std;


void Menu_of_actions(Hero & hero)
{
	srand(time(NULL));
	Wolf wolf;
	Goblin goblin;
	Monster monster;
	int choice;
	int r = 0;
	do {
		cout << "\n\t\t\t MENU OF ACTIONS" << endl << endl;
		cout << "Choose :" << endl;
		cout << " 1  -  Show characteristics " << endl;
		cout << " 2  -  Go to the Forest( Attack ) " << endl;
		cout << " 3  -  Shop " << endl;
		cout << " 4  -  Information about Enemies " << endl;
		cout << " 5  -  Special tasks " << endl;
		cout << " 6  -  Show inventar " << endl;
		cout << " 6  -  Exit " << endl;
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			Statistics(hero);
			break;
		case 2:
			r = rand() % 2;
			if (r == 0) Fight(hero, &wolf); 
			if (r == 1) Fight(hero, &goblin); 
			if (r == 2) Fight(hero, &monster); break;
		case 3:
			Shop(hero);
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			hero.Show_inventar();
			break;
		case 7:
			break;
		default:
			cout << "Wrong input" << endl;
			break;
		}
	} while (choice != 7);
}