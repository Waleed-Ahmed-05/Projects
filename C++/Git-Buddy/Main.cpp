#include "Header Files/Menus.h"
#include "Header Files/Add-on.h"
#include "Header Files/Networking.h"
#include "Header Files/Settings.h"
#include "Header Files/Configuration & Automation.h"

// This global variable is connected to Menus.h
string Choice;

int main()
{
	int Delay = Configure_Settings("Settings.txt", 60, "1");

	while(1)
	{
		Main_Menu();
		Margin();

		if(Choice == "1")
		{
			while(true)
			{
				if(Ping_Network_Connection())
				{
					Initialize_Git_Buddy('3');
				}
				else
				{
					Network_Connection_Status('2');
				}

				Sleep(Delay);
			}
		}
		else if(Choice == "2")
		{
			while(1)
			{
				Sub_Menu_01();
				Margin();

				if(Choice == "1" && Ping_Network_Connection())
				{
					Initialize_Git_Buddy('1');
				}
				else if (Choice == "2" && Ping_Network_Connection())
				{
					Initialize_Git_Buddy('2');
				}
				else if (Choice == "3")
				{
					break;
				}
				else if((Choice == "1" || Choice == "2") && !Ping_Network_Connection())
				{
					Network_Connection_Status('2');
					Margin();
				}
				else
				{
					Invalid();
				}
				
				Margin();
			}
		}
		else if (Choice == "3")
		{
			while(1)
			{
				Sub_Menu_02();
				Margin();

				if(Choice == "1")
				{
					Github_Configuration();
					Margin();
					break;
				}
				else if(Choice == "2")
				{
					Configure_Settings("Settings.txt", Settings_Configuration(), "1-1");
					Delay = Configure_Settings("Settings.txt", 0, "1");
					Margin();
				}
				else if(Choice == "3")
				{
					break;
				}
				else
				{
					Invalid();
					Margin();
				}
			}
		}
		else if(Choice == "4")
		{
			break;
		}
		else
		{
			Invalid();
			Margin();
		}
	}
}