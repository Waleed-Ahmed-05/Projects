#include "Libraries.h"

// A global variable connection to share data across Main file and Header File.
extern string Choice;

void Main_Menu()
{
	// system("cls");

	cout << "\nWhat do you wanna do?\n\n"
		 << "1. Initialize Git-Buddy\n"
		 << "2. Configure Git-Buddy\n"
		 << "3. Exit\n\n"
		 << "Enter your choice: ";

	cin >> Choice;
}

void Sub_Menu_01()
{
	// system("cls");

	cout << "\nWhat do you wanna do?\n\n"
		 << "1. For New Repository\n"
		 << "2. For Existing Repository\n"
		 << "3. Go Back to Main Menu\n\n"
		 << "Enter your choice: ";

	cin >> Choice;
}

void Sub_Menu_02()
{
	// system("cls");

	cout << "\nWhat do you wanna do?\n\n"
		 << "1. Configure Github\n"
		 << "2. Change Git Push/Pull Time\n"
		 << "3. Go Back to Main Menu\n\n"
		 << "Enter your choice: ";

	cin >> Choice;
}