#include "Header Files/Menus.h"
#include "Header Files/Add-on.h"
#include "Header Files/Configuration & Automation.h"

// This global variable is connected to Menus.h
string Choice;

int main()
{
	while(1)
	{
		Main_Menu();
		Margin();

		if(Choice == "1")
		{
			// Initialize_Git_Buddy();
			while(1)
			{
				Sub_Menu_01();
				Margin();

				if(Choice == "1")
				{
					Initialize_Git_Buddy(Choice);
				}
				else if (Choice == "2")
				{
					Initialize_Git_Buddy(Choice);
				}
				else if (Choice == "3")
				{
					break;
				}
				else
				{
					Invalid();
				}
				
				Margin();
			}
		}
		else if (Choice == "2")
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