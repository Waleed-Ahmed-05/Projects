void Division()
{
	system("cls");

	Result = 0;
	Count_02 = 0;
	Number_01 = Result;

	Count_01 = Data_Validator(Count_01, "How many numbers do you wanna divide: ");

	if(Count_01 == 1)
	{
		system("cls");
		
		cout << "! ! ! Please enter more then one value for division ! ! !";
		
		sleep(3);
	}
		else
	{
		while(Count_01 > 0)
		{	
			if(Number_01 == 0 && Count_02 == 0)
			{
				Count_01--;
				Count_02++;
				
				while(true)
				{
					cout << "Current Result: " << Result << "  || " << " Enter number " << Count_02 << ": ";
					cin >> Input;

					istringstream Is_String(Input);

					if(Is_String >> Number_01 && Is_String.eof()){break;}
					else
					{
						system("cls");
						
						cout << "! ! ! Invalid input ! ! !";
						
						Sleep(2);

						system("cls");
					}
				}

				History(-1, Input);
				
				continue;
			}
			Count_02++;
			
			while(true)
			{
				cout << "Current Result: " << Result << "  || " << " Enter number " << Count_02 << ":";
			    cin >> Input;

				istringstream Is_String(Input);

				if(Is_String >> Number_02 && Is_String.eof()){break;}
				else
				{
					system("cls");
					
					cout << "! ! ! Invalid input ! ! !";
					
					Sleep(2);

					system("cls");
				}
			}

			Result = Number_01 / Number_02;

			if(Count_02 == 2){History(4, Input);History(0, to_string(Result));}
			else{History(-1, to_string(Number_01));History(4, Input);History(0, to_string(Result));}

			Number_01 = Result;

			Count_01--;
		}
		
		cout << endl << "Division of given numbers is " << Result << "." << endl << endl << "Press enter key to continue: ";
		
		cin.sync();
		getline(cin, input);
	}
}