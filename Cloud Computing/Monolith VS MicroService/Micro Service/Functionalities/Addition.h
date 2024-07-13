void Addition()
{
	system("cls");

	Result = 0;

	Count_01 = Data_Validator(Count_01, "How many numbers do you wanna add: ");

	for(int i = 1;i <= Count_01;i++)
	{
		while(true)
		{
			cout << "Current Result: " << Result << "  ||  Enter number " << i << ": ";
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

		if(i == 1){History(-1, Input);}
		else{History(1, Input);}

		Result = Result + Number_01;
	}

	History(0, to_string(Result));

	cout << endl << "Addition of given numbers is " << Result << "." << endl << endl << "Press enter key to continue: ";

	cin.sync();
	getline(cin, input);
}