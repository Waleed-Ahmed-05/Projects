#pragma once

bool Confirm_Network_Connection()
{
	bool Status = 0;
	int Ping = system("ping www.google.com -n 1 > nul");
	
	if (Ping == 0)
	{
		Status = 1;
	}

	return Status;
}