#include "Functionalities/Libraries.h"
#include "Functionalities/Variables.h"
#include "Functionalities/History.h"
#include "Functionalities/Sleep.h"
#include "Functionalities/Data_Validator.h"
#include "Functionalities/Addition.h"
#include "Functionalities/Subtraction.h"
#include "Functionalities/Multiplication.h"
#include "Functionalities/Division.h"
#include "Functionalities/Factorial.h"
#include "Functionalities/Animation.h"

int main()
{
	Count_01 = 0;
	string Operation;

	system("cls");

	Animation(0);

	Animation(2);

	cout << endl;

	while(true)
	{
		system("cls");

		cout << "Which operation do you wanna perform?" << endl << "1. Addition" << endl << "2. Subtraction" << endl << "3. Multliplication" << endl << "4. Division" << endl << "5. Factorial" << endl << "6. History" << endl << "7. Exit" << endl << "Enter your desired operation (i.e : 1 , 2 e.t.c): ";
		cin >> Operation;

		if(Operation == "1"){Addition();}
		else if(Operation == "2"){Subtraction();}
		else if(Operation == "3"){Multliplication();}
		else if(Operation == "4"){Division();}
		else if(Operation == "5"){Factorial();}
		else if(Operation == "6")
		{
			History(5, "");

			cout << "Press enter key to continue: ";

			cin.sync();
			getline(cin, input);
		}
		else if(Operation == "7")
		{
			break;
		}
		else
		{
			system("cls");

			cout << "! ! ! Invalid Operation ! ! !";

			Sleep(2);
		}
	}

	Count_01 = 0;

	system("cls");

	Animation(1);

	Animation(2);

	system("cls");
}