#include "Libraries.h"

void Invalid()
{
	cout << "\n! ! ! Invalid Input ! ! !\n";
}

void Margin()
{
	cout << "\n---------------------------------------------------------------\n";
}

void Network_Connection_Status(char Status)
{
	if(Status == '1')
	{
		cout << "\nNetwork connection has been established.\n";
	}
	else if(Status == '2')
	{
		cout << "\nFailed to establish a network conection.\n";
	}
}
