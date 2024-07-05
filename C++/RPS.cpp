#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

string Statement;
string Previous;

int Random(int Number)
{
    srand(time(0));
    Number = 1 + rand() % 100;
    return Number;
}
string RPS(int Number, string C_RPS)
{
    if(Number % 2 == 0){C_RPS = "R";}
    else if(Number % 3 == 0){C_RPS = "P";}
    else if(Number % 5 == 0){C_RPS = "S";}
    return C_RPS;
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
        Statement = "     You have lost.     ";

        for(int i = 0;i < sizeof(Statement);i++)
        {
            Sleep(1);
            cout << Statement[i];
        }
    }
    else if(Status == 1)
    {
        Statement = "     You have won.     ";

        for(int i = 0;i < sizeof(Statement);i++)
        {
            Sleep(1);
            cout << Statement[i];
        }
    }
    else if(Status == 2)
    {
        Statement = "Do you wanna play again";

        for(int i = 0;i < sizeof(Statement);i++)
        {
            Sleep(1);
            cout << Statement[i];
        }
    }
    else if(Status == 3)
    {
        Statement = "! ! ! It's a draw ! ! !";
        
        for(int i = 0;i < sizeof(Statement);i++)
        {
            Sleep(1);
            cout << Statement[i];
        }
    }
    else if(Status == 4)
    {
        Statement = "Please wait! Choices are being shuffled . . . . . . . . . . . . . . . . .";
        
        for(int i = 0;i < sizeof(Statement) + 50;i++)
        {
            Sleep(2);
            cout << Statement[i];
        }
    }
}

int main()
{
    system("cls");

    string Choice;
    string C_RPS = "NULL";
    int Rounds;

    while(true)
    {   
        system("cls");

        int Wins = 0;
        int Loses = 0;
        int Draws = 0;
        int Round_Count = 0;
        int Random_Number = 0;

        cout << "Please specify how many matches do you wanna play: ";
        cin >> Rounds;

        system("cls");

        while(Rounds > 0)
        {
            Rounds--;
            Round_Count++;

            Animation(4);

            while(true)
            {
                Random_Number = Random(Random_Number);
                C_RPS = RPS(Random_Number, C_RPS);

                if(C_RPS != "NULL" && C_RPS != Previous){break;}
                else{continue;}
            }

            Previous = C_RPS;

            system("cls");

            cout << C_RPS << "Round No. " << Round_Count << endl << endl << "Wins: " << Wins << "  ||  Loses: " << Loses  << "  ||  Draws: " << Draws << endl << endl;
            cout << "Enter R for Rock,P for Paper and S for Scissor: ";
            cin >> Choice;

            system("cls");

            if(((Choice == "p" || Choice == "P") && C_RPS == "R") || ((Choice == "s" || Choice == "S") && C_RPS == "P") || ((Choice == "r" || Choice == "R") && C_RPS == "S")){Wins++;}
            else if(Choice != "R" && Choice != "P" && Choice != "S" && Choice != "r" && Choice != "p" && Choice != "s")
            {
                Rounds++;
                Round_Count--;

                cout << "! ! ! Invalid choice ! ! !";

                Sleep(0);

                system("cls");
            }
            else if(((Choice == "p" || Choice == "P") && C_RPS == "P") || ((Choice == "s" || Choice == "S") && C_RPS == "S") || ((Choice == "r" || Choice == "R") && C_RPS == "R")){Draws++;}
            else{Loses++;}
        }

        if(Wins > Loses){Animation(1);}
        else if(Wins < Loses){Animation(0);}
        else if(Wins == Loses){Animation(3);}

        cout << endl << endl;

        while(Choice != "Y" || Choice != "y" || Choice != "N" || Choice != "n")
        {
            Animation(2);
            
            cout << " (Y/N): ";
            cin >> Choice;

            system("cls");

            if(Choice == "Y" || Choice == "y"){main();break;}
            else if(Choice == "N" || Choice == "n"){break;}
            else
            {
                cout << "! ! ! Invalid Choice ! ! !";

                Sleep(0);
                
                system("cls");
            }
        }
        
        break;
    }
}