void Factorial()
{
	system("cls");

	Result = 1;

	while(true)
	{
		cout << "Enter a number to find it's factorial: ";
		cin >> Input;
	
		istringstream Is_String(Input);

		if(Is_String >> Count_01 && Is_String.eof()){break;}
		else
		{
			system("cls");
			
			cout << "! ! ! Invalid input ! ! !";
			
			Sleep(2);

			system("cls");
		}
	}

	for(int i = 1;i <= Count_01;i++){Result = i * Result;}

	History(-1, to_string(Count_01) + "!");

	History(0, to_string(Result));

	cout << endl << "Factorial of given numbers is " << Result << "." << endl << endl << "Press enter key to continue: ";
	
	cin.sync();
	getline(cin, input);
}