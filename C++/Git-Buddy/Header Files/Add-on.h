#pragma once

void Margin()
{
	cout << "------------------------------------------------------------------------" << endl;
}

void Invalid()
{
	cout << endl << "! ! ! Invalid choice ! ! !" << endl << endl;
	this_thread::sleep_for(chrono::seconds(2));
	Margin();
}