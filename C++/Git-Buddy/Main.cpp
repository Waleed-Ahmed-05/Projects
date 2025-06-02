#include "Header Files/Libraries.h"
#include "Header Files/Menus.h"
#include "Header Files/Github-Configuration.h"
#include "Header Files/History.h"

int main()
{
	while (1)
	{
		History(1);
		string Choice = Main_Menu();
		if (Choice == "1")
		{
			while (1)
			{
				History(2);
				Choice = Sub_Menu_01();
				if (Choice == "1") { History(3); Enable_Configuration(3); }
				else if (Choice == "2") { History(4); Enable_Configuration(3); }
				else if (Choice == "3") { break; }
				else { Invalid(); }
			}
		}
		else if (Choice == "2")
		{
			while (1)
			{
				Choice = Sub_Menu_02();
				if (Choice == "1") { User_Email_And_Repo_Configuration(); }
				else if (Choice == "2") { Enable_Configuration(1); }
				else if (Choice == "3") { Enable_Configuration(2); }
				else if (Choice == "4") { break; }
				else { Invalid(); }
			}
		}
		else if (Choice == "3") { break; }
		else { Invalid(); }
	}
}