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
    Number = 1 + rand() % 3;
    return Number;
}
string RPS(int Number, string C_RPS)
{
    if(Number == 1){C_RPS = "R";}
    else if(Number == 2){C_RPS = "P";}
    else if(Number == 3){C_RPS = "S";}
    return C_RPS;
}
int Sleep(int Status)
{
    if(Status == 0)
    {for(int i = 0;i < 1000000000;i++){}}
    else if(Status == 1)
    {for(int i = 0;i < 40000000;i++){}}
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
            if(i == sizeof(Statement) - 1){Statement = "";}
        }
    }
}

int main()
{
    system("cls");
    string Choice;
    string C_RPS;
    int Rounds;

    while(true)
    {   
        system("cls");

        int Wins = 0;
        int Loses = 0;
        int Round_Count = 0;
        int Random_Number = Random(Random_Number);

        C_RPS = RPS(Random_Number, C_RPS);

        cout << "Please specify how many matches do you wanna play: ";
        cin >> Rounds;

        system("cls");

        while(Rounds > 0)
        {
            
            Rounds--;
            Round_Count++;

            cout << "Round No. " << Round_Count << endl << endl << "  Wins: " << Wins << "  ||  Loses: " << Loses << endl << endl;
            cout << "Enter R for Rock,P for Paper and S for Scissor: ";
            cin >> Choice;

            system("cls");

            if(Choice == C_RPS || (Choice == "r" && C_RPS == "R") || (Choice == "p" && C_RPS == "P" || (Choice == "s" && C_RPS == "S"))){Wins++;}
            else if(Choice != C_RPS && (Choice == "R" || Choice == "P" || Choice == "S" || Choice == "r" || Choice == "p" || Choice == "s")){Loses++;}
            else if(Choice != "R" && Choice != "P" && Choice != "S" || Choice != "r" || Choice != "p" || Choice != "s")
            {
                Rounds++;
                Round_Count--;

                cout << "! ! ! Invalid choice ! ! !";

                Sleep(0);
                system("cls");

            }
        }
        if(Wins > Loses){Animation(1);}
        else if(Wins < Loses){Animation(0);}

        cout << endl << endl;

        while(Choice != "Y" || Choice != "y" || Choice != "N" || Choice != "n")
        {
            Animation(2);cout << " (Y/N): ";

            cin >> Choice;

            system("cls");

            if(Choice == "Y" || Choice == "y"){main();break;}
            else if(Choice == "N" || Choice == "n"){break;}
            else{cout << "! ! ! Invalid Choice ! ! !";Sleep(0);system("cls");}
        }
        break;
    }
}