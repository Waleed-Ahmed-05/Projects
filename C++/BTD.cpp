#include <iostream>
#include <string>
#include <stdlib.h>
#include <cctype>
#include <sstream>

using namespace std;

string Statement,Input;
int Result;

void Sleep(int Status)
{
    if(Status == 0){for(int i = 0;i < 40000000;i++){}}
    else if(Status == 1){for(int i = 0;i < 1000000000;i++){}}
}
int Data_Validator(int Number, string Statement)
{
    while(true)
    {
		cout << Statement;
        cin >> Input;

        istringstream Is_String(Input);

        if(Is_String >> Number && Is_String.eof()){break;}
        else
        {
            system("cls");
            
            cout << "! ! ! Invalid input ! ! !";
            
            Sleep(1);

            system("cls");
        }
    }
    
    return Number;
}
int Multiplier(int Count_01)
{
    int Number = 1;

    while(Count_01 > 0)
    {
        Number = Number * 2;
        Count_01--;
    }

    return Number;
}
string Reverse(string Statement)
{
    int Count_01 = Statement.size();string Array = Statement;

    for(int i = 0;i < Statement.size();i++){Count_01--;Array[Count_01] = Statement[i];}

    Statement = Array;

    return Statement;
}
string Divisor(int Number)
{        
    int Number_01, Number_02;
    Statement = "";

    while(Number > 0)
    {
        Number_01 = Number / 2;
        Number_02 = Number % 2;
        Number = Number_01;

        Statement += to_string(Number_02);
    }

    Statement = Reverse(Statement);

    return Statement;
}
bool Binary_Validator(int Number)
{
    bool Valid = 1;

    while(Number > 0)
    {
        Result = Number % 10;

        if(Result != 0 && Result != 1){Valid = 0;break;}
        else{Valid = 1;}

        Number = Number / 10;
    }
    
    return Valid;
}
void BinToDec()
{
    int Number_01,Number_02,Count_01;

    while(true)
    {
        system("cls");

        int BTD = Data_Validator(BTD, "Enter any binary number: ");
        Result = 0,Count_01 = -1,Number_02 = BTD;

        if(Binary_Validator(BTD))
        {
            while(BTD > 0)
            {
                Count_01++;

                Number_01 = BTD % 10;
                
                if(Count_01 > 0){Result += Number_01 * Multiplier(Count_01);}
                else{Result = Number_01;}

                BTD = BTD / 10;

            }

            system("cls");
            
            cout << "Binary number " << Number_02 << " in decimal is " << Result << "." << endl << endl << "Press enter key to continue: ";

            cin.sync();
            getline(cin, Input);

            break;
        }
        else{system("cls");cout << "! ! ! Invalid binary number! ! !"; Sleep(1);}
    }
}
void DecToBin()
{
    system("cls");

    int BTD = Data_Validator(BTD ,"Enter any decimal number: ");

    Statement = Divisor(BTD);

    system("cls");

    cout << "Decimal number " << BTD << " in binary is " << Statement << "." << endl << endl << "Press enter key to continue: ";

    cin.sync();
    getline(cin, Input);
    
}
void History(){}

int main()
{
    while(true)
    {
        system("cls");

        cout << "What do you wanna do?" << endl << "1. Binary to Decimal conversion" << endl << "2. Decimal to Binary conversion" << endl << "3. History" << endl << "4. Exit" << endl << "Enter your choice: ";
        cin >> Statement;

        if(Statement == "1"){BinToDec();}
        else if(Statement == "2"){DecToBin();}
        else if(Statement == "3"){History();}
        else if(Statement == "4"){break;}
        else{system("cls");cout << "! ! ! Invalid choice ! ! !";Sleep(1);}
    }
}