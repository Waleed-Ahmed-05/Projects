#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

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
void Animation(int Status)
{
    if(Status == 0)
    {
        Statement = "You have guessed right.";
        for(int i = 0;i < sizeof(Statement);i++)
        {
            usleep(100000);
            cout << Statement[i];
        }
        cout << " Tries: " << Tries;
    }
    else if(Status == 1)
    {
        Statement = "You have guessed wrong.";
        for(int i = 0;i < sizeof(Statement);i++)
        {
            usleep(100000);
            cout << Statement[i];
        }
    }
}
void Guess(int Random_Number,int Number)
{
    if(Number < Random_Number)
    {
        Guess_01 = Number;
    }
    else if(Number > Random_Number)
    {
        Guess_02 = Number;
    }
}

int main()
{
    system("cls");
    int Number;
    int Random_Number = Random(Random_Number);
    Guess_01 = 0;
    Guess_02 = 0;
    Tries = 0;
    cout << "Enter any number to begin guessing: ";
    cin >> Number;
    while(true)
    {
        Tries++;
        system("cls");
        Guess(Random_Number,Number);
        if(Random_Number == Number)
        {
            Animation(0);
            cout << endl << "Do you wanna play again?(Y/N): ";
            cin >> Statement;
            if(Statement == "Y" || Statement == "y")
            {
                main();
                break;
            }
            else if(Statement == "N" || Statement == "n")
            {
                system("cls");
                break;
            }
            else
            {
                cout << "! ! ! Invalid input ! ! !";
            }
        }
        else
        {
            Animation(1);
            cout << endl << Guess_01 << "<  >" << Guess_02 << ".  ||  " << "Try again: ";
            cin >> Number;
        }
    }
}