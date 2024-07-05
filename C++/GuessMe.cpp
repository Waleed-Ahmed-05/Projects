#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <sstream>

using namespace std;

string Statement;
int Guess_01;
int Guess_02;
int Tries;

int Random(int Number)
{
    srand(time(0));
    Number = 1 + rand() % 100;
    return Number;
}
void Sleep(int Status)
{
    if(Status == 0){for(int i = 0;i < 40000000;i++){}}
    else if(Status == 1){for(int i = 0;i < 1000000000;i++){}}
}
void Animation(string Statement)
{
    for(int i = 0;i < sizeof(Statement);i++)
    {
        Sleep(0);
        cout << Statement[i];
    }
}
void Guess(int Random_Number,int Number)
{
    if(Number < Random_Number){Guess_01 = Number;}
    else if(Number > Random_Number){Guess_02 = Number;}
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
            
            Sleep(1);

            system("cls");
        }
    }

    return Number;
}

int main()
{
    system("cls");

    int Number;
    int Random_Number = Random(Random_Number);
    Guess_01 = 0;
    Guess_02 = 0;
    Tries = 0;

    system("cls");

    Number = Data_Validator(Number, "Enter any number to begin guessing: ");

    while(true)
    {
        system("cls");

        Tries++;

        Guess(Random_Number,Number);

        if(Random_Number == Number)
        {
            Animation("You have guessed right.");

            cout << " Tries: " << Tries << endl << endl;

            Animation("Do you wanna play again?");

            cout << " (Y/N):";
            cin >> Statement;

            if(Statement == "Y" || Statement == "y"){main();break;}
            else if(Statement == "N" || Statement == "n"){system("cls");break;}
            else{cout << "! ! ! Invalid input ! ! !";}
        }
        else
        {
            Animation("You have guessed wrong.");

            cout << " Tries: " << Tries << endl << endl << Guess_01 << "<  <" << Guess_02 << ".  ||  ";

            Number = Data_Validator(Number,"Try again:");
        }
    }
}