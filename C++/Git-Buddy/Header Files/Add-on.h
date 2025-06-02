#pragma once

#include "Libraries.h"

void Margin()
{
	cout << "------------------------------------------------------------------------" << endl;
}

void Invalid()
{
	cout << endl << "! ! ! Invalid choice ! ! !" << endl << endl;
	for (int i = 0; i < 1000000000; i++) {}
	Margin();
}