void Animation(int Status)
{
    if(Status == 0)
    {
        Statement = "Calculator has been Initialized ";

        for(int i = 0;i < sizeof(Statement) + 8;i++)
        {
            Sleep(1);
            cout << Statement[i];
        }
    }
    else if(Status == 1)
    {
        Statement = "Shutting Down! Please Wait ";

        for(int i = 0;i < sizeof(Statement) + 3;i++)
        {
            Sleep(1);
            cout << Statement[i];
        }
    }
	else if(Status == 2)
	{
		Statement = ". . . . . . . . . . . . . . ";

		for(int i = 0;i < sizeof(Statement);i++)
        {
            Sleep(0);
            cout << Statement[i];
        }
	}
}