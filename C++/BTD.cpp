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
int Counter(int Number)
{
    int Counter = 0;

    while(Number > 0)
    {
        Number = Number / 10;
        Counter++;
    }

    return Counter;
}
bool Binary_Validator(int Number)
{
    bool Valid;

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
    int Count_01,Count_02,Number_01,Number_02 = 1,Number_03;

    while(true)
    {
        system("cls");

        int BTD = Data_Validator(BTD, "Enter any binary number: ");
        Number_03 = BTD;

        if(Binary_Validator(BTD))
        {
            Count_01 = Counter(BTD);

            Result = 0;
            
            while(Count_01 > 0)
            {
                Count_01--;
                Count_02++;

                Number_01 = BTD % 10;
                Number_02 = Number_01;

                if(Count_02 != 1)
                {
                    for(int i = 0;i < Count_02;i++)
                    {
                        Number_02 = Number_02 * 2;
                    }
                }

                BTD = BTD / 10;
                Result = Result + Number_02;
            }
            
            cout << "Binary conversion of " << Number_03 << " into decimal is " << Result << "." << endl << endl << "Press enter key to continue: ";

            cin.sync();
            getline(cin, Input);
        }
        else{system("cls");cout << "! ! ! Invalid binary number ! ! !";Sleep(1);}
    }
}
void DecToBin()
{

}
void History()
{

}

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