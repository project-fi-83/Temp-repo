#include "Header.h"
#include<iostream>
#include<string>
using namespace std;


int main()
{
	int count = 0;
	int start_game;
	cout << "Welcome 'The Last Knight' game" << endl;
	cout << "  Enter your name :\n\t";
	string name;
	getline(cin, name);
	cout << "Press :" << endl;
	cout << " 1 - Start the game" << endl;
	cout << " 2 - Exit  " << endl;
	
	cin >> start_game;
	if (start_game == 1)
	{
		Hero hero(name);
		Boss boss;
		boss.boss_create(1);
		cout << "\n Hello " << hero.Get_name() <<" !"<< endl;
		cout << "Welcome . Are you ready to become a Knight ?. Lets's start..." << endl << endl;;
		boss.Boss_Represent();

		system("pause");

		system("cls");
		Menu_of_actions(hero,boss);
	}
	else 
	if (start_game==2)
	{
		count++;
		cout << "Close (Choose 2 )" << endl;
	}
	int new_game;
	if (count == 0)
	{
		
		cout << "You lose " << endl;
		cout << "1  -  Start new game " << endl;
		cout << "2  -  Finish" << endl;
		cin >> new_game;
		system("cls");
		if (new_game == 1)	main();
	}

		
	

	
	system("pause");
	return 0;
}
