#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <cctype>
#include <sstream>
#include <fstream>

using namespace std;

string Statement;
string input, Input;
int Count_01 = 0;
int Count_02 = 0;
float Number_01 = 0;
float Number_02 = 0;
float Result = 0;

void History(int Status,string Data)
{
	fstream History;
	
	History.open("History.txt",ios::app);

	if(Status == -1){History << endl << Data;}
	else if(Status == 0){History << " = " << Data;}
	else if(Status == 1){History << " + " << Data;}
	else if(Status == 2){History << " - " << Data;}
	else if(Status == 3){History << " * " << Data;}
	else if(Status == 4){History << " / " << Data;}

	if(Status == 5)
	{
		Count_01 = 0;

		History.close();

		History.open("History.txt",ios::in);

		system("cls");
		
		while(!History.eof())
		{
			Count_01++;
			getline(History, Statement);
			cout << Count_01 << ". " << Statement << endl << endl;
		}
	}

	History.close();
}
void Sleep(int Status)
{
    if(Status == 0){for(int i = 0;i < 100000000;i++){}}
    else if(Status == 1){for(int i = 0;i < 40000000;i++){}}
    if(Status == 2){for(int i = 0;i < 1000000000;i++){}}
}
int Data_Validator(int Number, string Statement)
{
    while(true)
    {
        string Input;
        
		cout << Statement;
        cin >> Input;

        istringstream Is_String(Input);

        if(Is_String >> Number && Is_String.eof()){break;}
        else
        {
            system("cls");
            
            cout << "! ! ! Invalid input ! ! !";
            
            Sleep(2);

            system("cls");
        }
    }
    
    return Number;
}
void Addition()
{
	system("cls");

	Result = 0;

	Count_01 = Data_Validator(Count_01, "How many numbers do you wanna add: ");

	for(int i = 1;i <= Count_01;i++)
	{
		while(true)
		{
			cout << "Current Result: " << Result << "  ||  Enter number " << i << ": ";
			cin >> Input;

			istringstream Is_String(Input);

			if(Is_String >> Number_01 && Is_String.eof()){break;}
			else
			{
				system("cls");
				
				cout << "! ! ! Invalid input ! ! !";
				
				Sleep(2);

				system("cls");
			}
		}

		if(i == 1){History(-1, Input);}
		else{History(1, Input);}

		Result = Result + Number_01;
	}

	History(0, to_string(Result));

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

	Count_01 = Data_Validator(Count_01, "How many numbers do you wanna subtract: ");

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
			if(Number_01 == 0 && Count_02 == 0)
			{
				Count_01--;
				Count_02++;

				while(true)
				{
					cout << "Current Result: " << Result << "  || " << " Enter number " << Count_02 << ": ";
					cin >> Input;

					istringstream Is_String(Input);

					if(Is_String >> Number_01 && Is_String.eof()){break;}
					else
					{
						system("cls");
						
						cout << "! ! ! Invalid input ! ! !";
						
						Sleep(2);

						system("cls");
					}
				}

				continue;
			}

			History(-1, Input);

			Count_02++;

			while(true)
			{
				cout << "Current Result: " << Result << "  || " << " Enter number " << Count_02 << ": ";
			    cin >> Input;

				istringstream Is_String(Input);

				if(Is_String >> Number_02 && Is_String.eof()){break;}
				else
				{
					system("cls");
					
					cout << "! ! ! Invalid input ! ! !";
					
					Sleep(2);

					system("cls");
				}
			}

			History(2, Input);

			Result = Number_01 - Number_02;
			Number_01 = Result;

			Count_01--;
		}

		History(0, to_string(Result));

		cout << endl << "Subtraction of given numbers is " << Result << "." << endl << endl << "Press enter key to continue: ";

		cin.sync();
		getline(cin, input);
	}
}
void Multliplication()
{
	system("cls");

	Result = 1;

	Count_01 = Data_Validator(Count_01, "How many numbers do you wanna multiply: ");

	for(int i = 1;i <= Count_01;i++)
	{
		while(true)
		{
			cout << "Current Result: " << Result << "  ||  Enter number " << i << ": ";
			cin >> Input;
			
			istringstream Is_String(Input);

			if(Is_String >> Number_01 && Is_String.eof()){break;}
			else
			{
				system("cls");
				
				cout << "! ! ! Invalid input ! ! !";
				
				Sleep(2);

				system("cls");
			}
		}

		if(i == 1){History(-1, Input);}
		else{History(3, Input);}

		Result = Number_01 * Result;
	}

	History(0, to_string(Result));

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

	Count_01 = Data_Validator(Count_01, "How many numbers do you wanna divide: ");

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
			if(Number_01 == 0 && Count_02 == 0)
			{
				Count_01--;
				Count_02++;
				
				while(true)
				{
					cout << "Current Result: " << Result << "  || " << " Enter number " << Count_02 << ": ";
					cin >> Input;

					istringstream Is_String(Input);

					if(Is_String >> Number_01 && Is_String.eof()){break;}
					else
					{
						system("cls");
						
						cout << "! ! ! Invalid input ! ! !";
						
						Sleep(2);

						system("cls");
					}
				}

				History(-1, Input);
				
				continue;
			}
			Count_02++;
			
			while(true)
			{
				cout << "Current Result: " << Result << "  || " << " Enter number " << Count_02 << ":";
			    cin >> Input;

				istringstream Is_String(Input);

				if(Is_String >> Number_02 && Is_String.eof()){break;}
				else
				{
					system("cls");
					
					cout << "! ! ! Invalid input ! ! !";
					
					Sleep(2);

					system("cls");
				}
			}

			Result = Number_01 / Number_02;

			if(Count_02 == 2){History(4, Input);History(0, to_string(Result));}
			else{History(-1, to_string(Number_01));History(4, Input);History(0, to_string(Result));}

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

	while(true)
	{
		cout << "Enter a number to find it's factorial: ";
		cin >> Input;
	
		istringstream Is_String(Input);

		if(Is_String >> Count_01 && Is_String.eof()){break;}
		else
		{
			system("cls");
			
			cout << "! ! ! Invalid input ! ! !";
			
			Sleep(2);

			system("cls");
		}
	}

	for(int i = 1;i <= Count_01;i++){Result = i * Result;}

	History(-1, to_string(Count_01) + "!");

	History(0, to_string(Result));

	cout << endl << "Factorial of given numbers is " << Result << "." << endl << endl << "Press enter key to continue: ";
	
	cin.sync();
	getline(cin, input);
}
void Animation(int Status)
{
    if(Status == 0)
    {
        Statement = "Calculator has been Initialized ";

        for(int i = 0;i < sizeof(Statement) + 8;i++)
        {
            Sleep(1);
            cout << Statement[i];
        }
    }
    else if(Status == 1)
    {
        Statement = "Shutting Down! Please Wait ";

        for(int i = 0;i < sizeof(Statement) + 3;i++)
        {
            Sleep(1);
            cout << Statement[i];
        }
    }
	else if(Status == 2)
	{
		Statement = ". . . . . . . . . . . . . . ";

		for(int i = 0;i < sizeof(Statement);i++)
        {
            Sleep(0);
            cout << Statement[i];
        }
	}
}

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
			History(5, " ");

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