#include "Header.h"
#include<iostream>
#include<string>
using namespace std;


int main()
{
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
		cout << "\n Hello " << hero.Get_name() <<" !"<< endl;
		cout << "Welcome . Are you ready to become a Knight ?. Lets's start..." << endl;
		
		Menu_of_actions(hero);
	}
	else if (start_game == 2) cout << "Game over" << endl;
	

	
	system("pause");
	return 0;
}
