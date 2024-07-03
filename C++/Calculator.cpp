#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

string input;
int Count = 0;
float Number01 = 0;
float Number02 = 0;
float Result = 0;

void Addition()
{
	system("cls");
	Result = 0;
	cout << "How many numbers do you wanna add: ";
	cin >> Count;
	for(int i = 1;i <= Count;i++)
	{
		cout << "Enter number " << i << ": ";
		cin >> Number01;
		Result = Result + Number01;
	}
	cout << endl << "Addition of given numbers is " << Result << "." << endl << endl << "Press enter key to continue: ";
	cin.sync();
	getline(cin, input);
}
void Subtraction()
{
	system("cls");
	Result = 0;
	Number01 = Result;
	cout << "How many numbers do you wanna subtract: ";
	cin >> Count;
	while(Count > 0)
	{
		cout << "Current Result: " << Result << "  || ";
		if(Number01 == 0)
		{
			Count--;
			cout << " Enter number : ";
			cin >> Number01;
			continue;
		}
		cout << " Enter number : ";
		cin >> Number02;
		Result = Number01 - Number02;
		Number01 = Result;
		Count--;
	}
	cout << endl << "Subtraction of given numbers is " << Result << "." << endl << endl << "Press enter key to continue: ";
	cin.sync();
	getline(cin, input);
}
void Multliplication()
{
	system("cls");
	Result = 1;
	cout << "How many numbers do you wanna multiply: ";
	cin >> Count;
	for(int i = 1;i <= Count;i++)
	{
		cout << "Enter number " << i << ": ";
		cin >> Number01;
		Result = Number01 * Result;
	}
	cout << endl << "Multiplication of given numbers is " << Result << "." << endl << endl << "Press enter key to continue: ";
	cin.sync();
	getline(cin, input);
}
void Division()
{
	system("cls");
	Result = 0;
	Number01 = Result;
	cout << "How many numbers do you wanna divide: ";
	cin >> Count;
	while(Count > 0)
	{
		cout << "Current Result: " << Result << "  || ";
		if(Number01 == 0)
		{
			Count--;
			cout << " Enter number : ";
			cin >> Number01;
			continue;
		}
		cout << " Enter number : ";
		cin >> Number02;
		Result = Number01 / Number02;
		Number01 = Result;
		Count--;
	}
	cout << endl << "Division of given numbers is " << Result << "." << endl << endl << "Press enter key to continue: ";
	cin.sync();
	getline(cin, input);
}
void Factorial()
{
	system("cls");
	Result = 1;
	cout << "Enter a number to find it's factorial: ";
	cin >> Count;
	for(int i = 1;i <= Count;i++)
	{
		Result = i * Result;
	}
	cout << endl << "Factorial of given numbers is " << Result << "." << endl << endl << "Press enter key to continue: ";
	cin.sync();
	getline(cin, input);
}

int main()
{
	Count = 0;
	string Operation;

	system("cls");
	cout << "Calculator has been Initialized";
	while(Count < 5)
	{
		sleep(1);
		Count++;
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
	Count = 0;
	system("cls");
	cout << "Shutting Down! Please Wait ";
	while(Count < 5)
	{
		sleep(1);
		Count++;
		cout << " . ";
	}
	system("cls");
}

