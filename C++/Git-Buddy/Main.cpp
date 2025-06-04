#include "Header Files/Libraries.h"
#include "Header Files/Menus.h"
#include "Header Files/Configuration & Automation.h"
#include "Header Files/Networking.h"

int main()
{
	while (1)
	{
		int Delay = Timer(0, 2);
		string Choice = Main_Menu();

		if (Choice == "1")
		{
			cout << endl << "Automation of Git Push has been started. You can press any key to stop the automation." << endl;
			while (!_kbhit())
			{
				if (Confirm_Network_Connection())
				{
					Enable_Configuration(3);
					this_thread::sleep_for(chrono::seconds(Delay));
				}
				else { cout << endl << "Can't continue cause network connection is closed." << endl; Margin(); break; }
			}
		}
		else if (Choice == "2")
		{
			while (1)
			{
				Choice = Sub_Menu_01();
				if (Choice == "1") { User_Email_And_Repo_Configuration(); }
				else if (Choice == "2") { Enable_Configuration(1); }
				else if (Choice == "3") { Enable_Configuration(2); }
				else if (Choice == "4") { break; }
				else { Invalid(); }
			}
		}
		else if (Choice == "3")
		{
			while (1)
			{
				int Minutes = Sub_Menu_02();
				Timer(Minutes * 60, 1);
				break;
			}
		}
		else if (Choice == "4") { break; }
		else { Invalid(); }
	}
}