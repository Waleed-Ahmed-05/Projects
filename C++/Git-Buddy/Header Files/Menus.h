#pragma once

#include "Add-on.h"

string Main_Menu()
{
	string Choice;
	cout << endl << "What do you wanna do?" << endl << endl;
	cout << "1. Configure GitHub" << endl;
	cout << "2. Configure Git Push/Pull Time" << endl;
	cout << "3. Exit" << endl << endl;
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
	cout << endl << "Enter the number of minutess you want to delay git: "; cin >> Time; Margin();
	return Time;
}
