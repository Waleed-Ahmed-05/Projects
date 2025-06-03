#pragma once

#include "Add-on.h"

string Main_Menu()
{
	string Choice;
	cout << endl << "What do you wanna do?" << endl << endl;
	cout << "1. Initialize Git-Buddy" << endl;
	cout << "2. Configure GitHub" << endl;
	cout << "3. Configure Git Push/Pull Time" << endl;
	cout << "4. Exit" << endl << endl;
	cout << "Enter your choice: "; cin >> Choice; Margin();
	return Choice;
}

string Sub_Menu_01()
{
	string Choice;
	cout << endl << "What do you wanna do?" << endl << endl;
	cout << "1. Configure Github Username, E-mail & Remote Repository" << endl;
	cout << "2. Enable Configuration for new repository" << endl;
	cout << "3. Enable Configuration for existing repository" << endl;
	cout << "4. Go Back" << endl << endl;
	cout << "Enter your desired choice: "; cin >> Choice; Margin();
	return Choice;
}

int Sub_Menu_02()
{
	int Time;
	cout << endl << "Enter the number of minutes you want to delay git: "; cin >> Time; Margin();
	return Time;
}
