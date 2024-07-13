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
            
            Sleep(2);

            system("cls");
        }
    }
    
    return Number;
}