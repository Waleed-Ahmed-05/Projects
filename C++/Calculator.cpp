#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

string input;
int Count_01 = 0;
int Count_02 = 0;
float Number_01 = 0;
float Number_02 = 0;
float Result = 0;

void Addition()
{
	system("cls");
	Result = 0;
	cout << "How many numbers do you wanna add: ";
	cin >> Count_01;
	for(int i = 1;i <= Count_01;i++)
	{
		cout << "Enter number " << i << ": ";
		cin >> Number_01;
		Result = Result + Number_01;
	}
	cout << endl << "Addition of given numbers is " << Result << "." << endl << endl << "Press enter key to continue: ";
	cin.sync();
	getline(cin, input);
}
void Subtraction()
{
	system("cls");
	Result = 0;
	Count_02 = 0;
	Number_01 = Result;
	cout << "How many numbers do you wanna subtract: ";
	cin >> Count_01;
	if(Count_01 == 1)
	{
		system("cls");
		cout << "! ! ! Please enter more then one value for subtraction ! ! !";
		sleep(3);
	}
	else
	{
		while(Count_01 > 0)
		{
			cout << "Current Result: " << Result << "  || ";
			if(Number_01 == 0 && Count_02 == 0)
			{
				Count_01--;
				Count_02++;
				cout << " Enter number " << Count_02 << ":";
				cin >> Number_01;
				continue;
			}
			Count_02++;
			cout << " Enter number " << Count_02 << ":";
			cin >> Number_02;
			Result = Number_01 - Number_02;
			Number_01 = Result;
			Count_01--;
		}
		cout << endl << "Subtraction of given numbers is " << Result << "." << endl << endl << "Press enter key to continue: ";
		cin.sync();
		getline(cin, input);
	}
}
void Multliplication()
{
	system("cls");
	Result = 1;
	cout << "How many numbers do you wanna multiply: ";
	cin >> Count_01;
	for(int i = 1;i <= Count_01;i++)
	{
		cout << "Enter number " << i << ": ";
		cin >> Number_01;
		Result = Number_01 * Result;
	}
	cout << endl << "Multiplication of given numbers is " << Result << "." << endl << endl << "Press enter key to continue: ";
	cin.sync();
	getline(cin, input);
}
void Division()
{
	system("cls");
	Result = 0;
	Count_02 = 0;
	Number_01 = Result;
	cout << "How many numbers do you wanna divide: ";
	cin >> Count_01;
	if(Count_01 == 1)
	{
		system("cls");
		cout << "! ! ! Please enter more then one value for division ! ! !";
		sleep(3);
	}
	else
	{
		while(Count_01 > 0)
		{
			cout << "Current Result: " << Result << "  || ";
			if(Number_01 == 0 && Count_02 == 0)
			{
				Count_01--;
				Count_02++;
				cout << " Enter number " << Count_02 << ": ";
				cin >> Number_01;
				continue;
			}
			Count_02++;
			cout << " Enter number " << Count_02 << ":";
			cin >> Number_02;
			Result = Number_01 / Number_02;
			Number_01 = Result;
			Count_01--;
		}
		cout << endl << "Division of given numbers is " << Result << "." << endl << endl << "Press enter key to continue: ";
		cin.sync();
		getline(cin, input);
	}
}
void Factorial()
{
	system("cls");
	Result = 1;
	cout << "Enter a number to find it's factorial: ";
	cin >> Count_01;
	for(int i = 1;i <= Count_01;i++)
	{
		Result = i * Result;
	}
	cout << endl << "Factorial of given numbers is " << Result << "." << endl << endl << "Press enter key to continue: ";
	cin.sync();
	getline(cin, input);
}

int main()
{
	Count_01 = 0;
	string Operation;

	system("cls");
	cout << "Calculator has been Initialized";
	while(Count_01 < 5)
	{
		sleep(1);
		Count_01++;
		cout << " . ";
	}
	cout << endl;
	while(true)
	{
		system("cls");
		cout << "Which operation do you wanna perform?" << endl << "1. Addition" << endl << "2. Subtraction" << endl << "3. Multliplication" << endl << "4. Division" << endl << "5. Factorial" << endl << "6. Exit" << endl;
		cout << "Enter your desired operation (i.e : 1 , 2 e.t.c): ";
		cin >> Operation;
		if(Operation == "1")
		{
			Addition();
		}
		else if(Operation == "2")
		{
			Subtraction();
		}
		else if(Operation == "3")
		{
			Multliplication();
		}
		else if(Operation == "4")
		{
			Division();
		}
		else if(Operation == "5")
		{
			Factorial();
		}
		else if(Operation == "6")
		{
			break;
		}
		else
		{
			cout << "Invalid Operation" << endl;
		}
	}
	Count_01 = 0;
	system("cls");
	cout << "Shutting Down! Please Wait ";
	while(Count_01 < 5)
	{
		sleep(1);
		Count_01++;
		cout << " . ";
	}
	system("cls");
}

