#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

string Statement;

int Random(int Number)
{
    srand(time(0));
    Number = 1 + rand() % 100;
    return Number;
}
void Sleep(int Status)
{
    if(Status == 0){for(int i = 0;i < 1000000000;i++){}}
    else if(Status == 1){for(int i = 0;i < 40000000;i++){}}
    else if(Status == 2){for(int i = 0;i < 80000000;i++){}}
}
void Animation(int Status)
{
    if(Status == 0)
    {
        Statement = "Initializing DiceRoller.cpp . . . . . . . . . . . . . . . . . . .";

        for(int i = 0;i < sizeof(Statement) + 43;i++)
        {
            Sleep(1);
            cout << Statement[i];
        }
    }
    else if(Status == 1)
    {
        Statement = "Please wait! Dices are being rolled . . . . . . . . . . . . . . . . . . .";
        
        for(int i = 0;i < sizeof(Statement) + 50;i++)
        {
            Sleep(2);
            cout << Statement[i];
        }
    }
    else if(Status == 2)
    {
        Statement = "Please wait! DiceRoller.cpp is being terminated . . . . . . . . . . . . . . . . . . .";
        
        for(int i = 0;i < sizeof(Statement) + 64;i++)
        {
            Sleep(1);
            cout << Statement[i];
        }
    }
}
int DR(int Number, int C_DR)
{
    if(Number % 2 == 0){C_DR = 1;}
    else if(Number % 3 == 0){C_DR = 2;}
    else if(Number % 4 == 0){C_DR = 3;}
    else if(Number % 5 == 0){C_DR = 4;}
    else if(Number % 6 == 0){C_DR = 5;}
    else if(Number % 7 == 0){C_DR = 6;}
    return C_DR;
}

int main()
{
    int Dice_01,Dice_02,C_DR = 0,Previous_01,Previous_02;

    system("cls");

    Animation(0);

    while(true)
    {   
        system("cls");

        cout << "What do you wanna do? " << endl << "1. Start Dice Simulation" << endl << "2. Exit" << endl << "Enter your choice: ";
        cin >> Statement;

        system("cls");

        if(Statement == "1")
        {
            while(true)
            {
                C_DR = DR(Random(Dice_01),C_DR);

                if(C_DR != 0 && C_DR != Previous_01){break;}
                else{continue;}
            }

            Dice_01 = C_DR;
            Previous_01 = Dice_01;

            Animation(1);

            system("cls");

            while(true)
            {
                C_DR = DR(Random(Dice_02),C_DR);

                if(C_DR != 0 && C_DR != Previous_02){break;}
                else{continue;}
            }
            
            Dice_02 = C_DR;
            Previous_02 = Dice_02;

            cout << "First Dice Rolled: " << Dice_01 << "  ||  Second Dice Rolled: " << Dice_02 << endl << endl << "Press enter key to continue: ";

            cin.sync();
            getline(cin,Statement);
        }
        else if(Statement == "2"){break;}
        else{cout << "! ! ! Invalid Choice ! ! !";Sleep(0);}
    }

    Animation(2);

    system("cls");
}