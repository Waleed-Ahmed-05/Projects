#pragma once

#include "Add-on.h"

vector<string> Data;

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