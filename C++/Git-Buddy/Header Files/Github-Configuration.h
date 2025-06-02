#pragma once

#include "Add-on.h"

vector<string> User_Details(4, "Empty Field");

void User_Email_And_Repo_Configuration()
{
	string Username, Email, Repo_Name, Token;
	cout << "Enter you GitHub username: "; cin >> Username;
	cout << "Enter you Github email account: "; cin >> Email;
	cout << "Enter your Github repository name exactly such as (Cloud-Computing) e.t.c: "; cin >> Repo_Name;
	cout << "Provide Github classic token for configuration (enter None if you don't want to provide token): "; cin >> Token;
	User_Details[0] = Username;
	User_Details[1] = Email;
	User_Details[2] = Repo_Name;
	User_Details[3] = Token;
	Margin();
}

void Create_Shell_Script(vector<string> Commands)
{
	string Temporary_Data;
	fstream Shell_Script;

	Shell_Script.open("Shell_Script.bat", ios::out); Shell_Script.close();
	Shell_Script.open("Shell_Script.bat", ios::app);
	for (int i = 0; i < Commands.size(); i++)
	{
		Shell_Script << Commands[i] << endl;
	}
	Shell_Script.close();
}

void Enable_Configuration(int Status)
{
	vector<string> Commands;

	if (Status == 1 || Status == 2)
	{
		Commands.push_back("git init");
		Commands.push_back("git branch -m main");
		Commands.push_back("git config user.name " + User_Details[0]);
		Commands.push_back("git config user.email " + User_Details[1]);
		if (User_Details[3] == "None") { Commands.push_back("git remote add origin http://github.com/" + User_Details[0] + "/" + User_Details[2] + ".git"); }
		else { Commands.push_back("git remote add origin http://" + User_Details[3] + "@github.com/" + User_Details[0] + "/" + User_Details[2] + ".git"); }
	}
	if (Status == 2) { Commands.push_back("del History.txt"); Commands.push_back("git pull origin main"); }
	if (Status == 3 || Status == 1)
	{
		Commands.push_back("git add History.txt");
		Commands.push_back("git commit -m \"Push\"");
		Commands.push_back("git push -u origin main");
	}
	Commands.push_back("@echo off");
	Commands.push_back("del \"%~f0\"");
	Commands.push_back("exit");

	Create_Shell_Script(Commands);
	system("Shell_Script.bat");
	Margin();
}