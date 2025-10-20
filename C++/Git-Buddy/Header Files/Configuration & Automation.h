#include "Libraries.h"

// Initialized global variables for Configuring GitHub and Initializing Git-Buddy 
string Username, Email, Repository, Token;

void Github_Configuration()
{
    // Used some local variables to check for valid user input
    string Choice;
    bool Loop = true;

    while(Loop)
    {
        cout << "\nEnter your github username: ";
        cin >> Username;
        cout << "Enter your github email: ";
        cin >> Email;
        cout << "Enter your github repository name: ";
        cin >> Repository;
        cout << "Enter your classic github token (enter 'none' if you don't have it): ";
        cin >> Token;

        while(1)
        {
            cout << "\nDo you wanna re-enter github credenials(Y/N): ";
            cin >> Choice;

            if(Choice == "Y" || Choice == "y")
            {
                break;
            }
            else if(Choice == "N" || Choice == "n")
            {
                Loop = false;
                break;
            }
            else
            {
                Margin();
                Invalid();
                Margin();
            }
        }
    }
}

void Initialize_Git_Buddy(string Choice)
{
    cout << endl;

    string Shell_Script_Command;

    system("git init");

    Shell_Script_Command = "git config --local user.name " + Username;

    system(Shell_Script_Command.c_str());

    Shell_Script_Command = "git config --local user.email " + Email;

    system(Shell_Script_Command.c_str());

    system("git branch -M main");

    if(Token == "none")
    {
        Shell_Script_Command = "git remote add origin https://github.com/" + Username + "/" + Repository + ".git";
    }
    else
    {
        Shell_Script_Command = "git remote add origin https://" + Token + "@github.com/" + Username + "/" + Repository + ".git";
    }

    system(Shell_Script_Command.c_str());

    if(Choice == "1")
    {
        system("git add . && git commit -m \"Commited via Git-Buddy\" && git push -u origin main");
    }
    else if(Choice == "2")
    {
        system("git pull origin main");
    }
}