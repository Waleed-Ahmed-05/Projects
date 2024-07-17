#include <iostream>
#include <string>
#include <unistd.h>
//#include <stdlib.h>
#include <fstream>

using namespace std;

string Statement;

void Sleep()
{
    for(int i = 0;i < 1000000000;i++){}
}
void Create()
{
    fstream History;

    History.open("History.txt", ios::app);

    cout << "Name: ";
    cin >> Statement;

    History << Statement << ",";

    cin.sync();
    cout << "Description: ";
    getline(cin, Statement);

    History << Statement << endl;

    History.close();
}
void Delete()
{

}
void Update()
{

}
void View()
{
    
}

int main()
{
    while(true)
    {
        system("cls");

        cout  << "What do you wanna do regarding TODO lists?" << endl << "1. Create" << endl << "2. Delete" << endl << "3. Update" << endl << "4. View" << endl << "5. Exit" << endl <<"Enter you choice: ";
        cin >> Statement;

        if(Statement == "1"){system("cls");Create();}
        else if(Statement == "2"){Delete();}
        else if(Statement == "3"){Update();}
        else if(Statement == "4"){View();}
        else if(Statement == "5"){break;}
        else{system("cls");cout << "! ! ! Invalid Choice ! ! !";Sleep();}
    }

    system("cls");
}