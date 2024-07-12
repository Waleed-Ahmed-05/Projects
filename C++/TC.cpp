#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cctype>
#include <fstream>
#include <sstream>

using namespace std;

string Statement, input;
float Temperature, Result;
char Symbol = 248;

void Sleep(int Status)
{
    if(Status == 0){for(int i = 0;i < 1000000000;i++){}}
    else if(Status == 1){for(int i = 0;i < 40000000;i++){}}
}
void Animation(int Status)
{
    if(Status == 0)
    {
        Statement = "TC.cpp is being initialized . . . . . . . . . . . . . . .";

        for(int i = 0;i < sizeof(Statement) + 33;i++)
        {
            Sleep(1);
            cout << Statement[i];
        }
    }
    else if(Status == 1)
    {
        Statement = "TC.cpp is being terminated . . . . . . . . . . . . . . .";

        for(int i = 0;i < sizeof(Statement) + 33;i++)
        {
            Sleep(1);
            cout << Statement[i];
        }
    }
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
            
            Sleep(0);

            system("cls");
        }
    }
    
    return Number;
}
void History(int Status, string Data_01, string Data_02)
{
    fstream History;

    History.open("History.txt", ios::app);

    if(Status == 0){History << "Converted " << Temperature << Symbol << "C to " << Result << Symbol << "F." << endl;}
    else if(Status == 1){History << "Converted " << Temperature << Symbol << "F to " << Result << Symbol << "C." << endl;}
    else if(Status == 2)
    {
        History.close();

		Temperature = 0;
	    Result = 0;

        History.open("History.txt", ios::in);

		system("cls");
		
		while(!History.eof())
		{
			Temperature++;
			getline(History, Statement);
		}

		History.close();

		History.open("History.txt",ios::in);

		while(!History.eof())
		{
			Result++;
			getline(History, Statement);
			cout << Result << ". " << Statement << endl << endl;
			if(Temperature - 1 == Result){break;}
		}
    }

    History.close();
}
void CTF()
{
    system("cls");

    Temperature = Data_Validator(Temperature, "Enter Temperature in Celcius: ");

    Result = (Temperature * 9/5) + 32;

    cout << endl << "Your Temperature in Fahrenheit is " << Result << "." << endl;

    History(0, to_string(Temperature), to_string(Result));

    cout << "Press enter key to continue: ";

    cin.sync();
    getline(cin, input);
}
void FTC()
{
    system("cls");

    Temperature = Data_Validator(Temperature, "Enter Temperature in Fahrenheit: ");

    Result = (Temperature - 32) * 5/9;

    cout << endl << "Your Temperature in Celcius is " << Result << "." << endl;
    
    History(1, to_string(Temperature), to_string(Result));

    cout << "Press enter key to continue: ";

    cin.sync();
    getline(cin, input);
}

int main()
{
    system("cls");
    
    Animation(0);

    while(true)
    {
        system("cls");

        cout << "What do you wanna do?" << endl << "1. Celcius to Fahrenheit" << endl << "2. Fahrenheit to Celcius" << endl << "3. History" << endl << "4. Exit" << endl << "Enter your choice: ";
        cin >> Statement;

        if(Statement == "1"){CTF();}
        else if(Statement == "2"){FTC();}
        else if(Statement == "3")
        {
            History(2, "", "");
            
            cout << "Press enter key to continue: ";

            cin.sync();
            getline(cin, input);
        }
        else if(Statement == "4"){break;}
        else{system("cls");cout << "! ! ! Invalid Choice ! ! !";Sleep(0);}
    }

    system("cls");

    Animation(1);

    system("cls");
}