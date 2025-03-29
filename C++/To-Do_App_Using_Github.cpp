#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

vector<string> Data;
vector<string> User_Details(4, "Empty Field");

void Margin()
{
	cout << "------------------------------------------------------------------------" << endl;
}

string Main_Menu()
{
	string Choice;
	cout << "What do you wanna do?" << endl << endl;
	cout << "1. View To-Do List" << endl;
	cout << "2. Configure GitHub" << endl;
	cout << "3. Exit" << endl << endl;
	cout << "Enter your choice: "; cin >> Choice; Margin();
	return Choice;
}

void Invalid()
{
	cout << endl << "! ! ! Invalid choice ! ! !" << endl << endl;
	for (int i = 0; i < 1000000000; i++) {}
	Margin();
}

string Sub_Menu_01()
{
	string Choice;
	cout << endl << "What do you wanna do?" << endl << endl;
	cout << "1. Add a task to list" << endl;
	cout << "2. Remove a task form list" << endl;
	cout << "3. Go back" << endl << endl;
	cout << "Enter your desired choice: "; cin >> Choice; Margin();
	return Choice;
}

void Update_History(vector<string> Data)
{
	fstream History;
	History.open("History.txt", ios::out); History.close();
	History.open("History.txt", ios::app);
	for (int i = 0; i < Data.size(); i++)
	{
		History << Data[i] << endl;
	}
	History.close();
}

void History(int Status)
{
	string Temporary_Data;
	fstream History;

	History.open("History.txt", ios::app);
	if (Status == 1)
	{
		History.close();
		History.open("History.txt", ios::in);
		while (!History.eof())
		{
			getline(History, Temporary_Data);
			if (Temporary_Data != "")
			{
				Data.push_back(Temporary_Data);
			}
		}
	}
	else if (Status == 2)
	{
		cout << "Your TO-DO list tasks: " << endl;
		for (int i = 0; i < Data.size(); i++)
		{
			cout << i + 1 << ". " << Data[i] << endl;
		}
		Margin();
	}
	else if (Status == 3)
	{
		cout << endl << "! ! ! You are currently adding a new task to the TO-DO list" << endl << endl;
		cin.ignore();
		getline(cin, Temporary_Data);
		Data.push_back(Temporary_Data);
		Update_History(Data); Margin();
	}
	else if (Status == 4)
	{
		int Task_ID;
		cout << endl << "Please specify task number that you wanna remove from the list: "; cin >> Task_ID;
		if (Data.size() >= Task_ID && Task_ID > 0)
		{
			Data.erase(Data.begin() + Task_ID - 1);
			Update_History(Data); Margin();
		}
		else { Invalid(); }
	}
	History.close();
}

string Sub_Menu_02()
{
	string Choice;
	cout << endl << "What do you wanna do?" << endl << endl;
	cout << "1. Configure Github Username, E-mail & Remote Repository" << endl;
	cout << "2. Enable Configuration for new repository" << endl;
	cout << "3. Enable Configuration for existing repository" << endl;
	cout << "4. Go Back" << endl << endl;
	cout << "Enter your desired choice: "; cin >> Choice; Margin();
	return Choice;
}

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
		else { Commands.push_back("git remote add origin http://" + User_Details[3] + "@github.com / " + User_Details[0] + " / " + User_Details[2] + ".git"); }
	}
	if (Status == 2) { Commands.push_back("del History.txt"); Commands.push_back("git pull origin main"); }
	if (Status == 3 || Status == 1)
	{
		Commands.push_back("git add History.txt");
		Commands.push_back("git commit -m \"Push\"");
		Commands.push_back("git push -u origin main");
	}
	Commands.push_back("exit 0");

	Create_Shell_Script(Commands);
	system("Shell_Script.bat");
	Margin();
}

int main()
{
	History(1);
	while (1)
	{
		string Choice = Main_Menu();
		if (Choice == "1")
		{
			while (1)
			{
				History(2);
				Choice = Sub_Menu_01();
				if (Choice == "1") { History(3); Enable_Configuration(3); }
				else if (Choice == "2") { History(4); Enable_Configuration(3); }
				else if (Choice == "3") { break; }
				else { Invalid(); }
			}
		}
		else if (Choice == "2")
		{
			while (1)
			{
				Choice = Sub_Menu_02();
				if (Choice == "1") { User_Email_And_Repo_Configuration(); }
				else if (Choice == "2") { Enable_Configuration(1); }
				else if (Choice == "3") { Enable_Configuration(2); }
				else if (Choice == "4") { break; }
				else { Invalid(); }
			}
		}
		else if (Choice == "3") { break; }
		else { Invalid(); }
	}
}