void History(int Status,string Data)
{
	fstream History;
	
	History.open("History.txt",ios::app);

	if(Status == -1){History << Data;}
	else if(Status == 0){History << " = " << Data << endl;}
	else if(Status == 1){History << " + " << Data;}
	else if(Status == 2){History << " - " << Data;}
	else if(Status == 3){History << " * " << Data;}
	else if(Status == 4){History << " / " << Data;}

	if(Status == 5)
	{
		Count_01 = 0;
		Count_02 = 0;

		History.close();

		History.open("History.txt",ios::in);

		system("cls");
		
		while(!History.eof())
		{
			Count_01++;
			getline(History, Statement);
		}

		History.close();

		History.open("History.txt",ios::in);

		while(!History.eof())
		{
			Count_02++;
			getline(History, Statement);
			cout << Count_02 << ". " << Statement << endl << endl;
			if(Count_01 - 1 == Count_02){break;}
		}
	}

	History.close();
}