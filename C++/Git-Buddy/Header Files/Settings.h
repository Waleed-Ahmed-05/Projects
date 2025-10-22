#include "Libraries.h"

int Configure_Settings(string File_Name, int TimeInSeconds, string Status)
{
    string Data;
    fstream Settings;

    Settings.open(File_Name, ios::in);

    if(!Settings.good())
    {
        Settings.open(File_Name, ios::out);
        Settings.close();

        Settings.open(File_Name, ios::app);
        Settings << TimeInSeconds;
        Settings.close();
    }

	Settings.close();

    if(Status[0] == '1')
    {
        if(Status == "1")
        {
            Settings.open(File_Name, ios::in);
            getline(Settings, Data);
        }
        else if(Status == "1-1")
        {
            Data = '0';

            Settings.open(File_Name, ios::out);
            Settings.close();

            Settings.open(File_Name, ios::app);
            Settings << TimeInSeconds;
        }
        
        Settings.close();
    }
    
    return stoi(Data);
}
