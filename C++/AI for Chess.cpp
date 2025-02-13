#include <iostream>
#include <string>
using namespace std;

string Layout[12][10] =		{{"    ", " 1 ", " 2 ", " 3 ", " 4 ", " 5 ", " 6 ", " 7 ", " 8 ", "    "},
							{"    ", "___", "___", "___", "___", "___", "___", "___", "___", "    "},
							{" A |", " R ", " K ", " B ", " Q ", " K ", " B ", " K ", " R ", "| A "},
							{" B |", " P ", " P ", " P ", " P ", " P ", " P ", " P ", " P ", "| B "},
							{" C |", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "| C "},
							{" D |", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "| D "},
							{" E |", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "| E "},
							{" F |", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "| F "},
							{" G |", " P ", " P ", " P ", " P ", " P ", " P ", " P ", " P ", "| G "},
							{" H |", " R ", " K ", " B ", " Q ", " K ", " B ", " K ", " R ", "| H "},
							{"    ", "---", "---", "---", "---", "---", "---", "---", "---", "    "},
							{"    ", " 1 ", " 2 ", " 3 ", " 4 ", " 5 ", " 6 ", " 7 ", " 8 ", "    "}};

void Load_And_Update_Board()
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << Layout[i][j];
		}
		cout << endl;
	}
}

bool Move_Validator(string Move, string Uppercase, string Lowercase, string Numbers)
{
	bool Alphabet_Status = false, Number_Status = false;
	for (int i = 0; i < 8; i++)
	{
		if (Move[0] == Uppercase[i] || Move[0] == Lowercase[i])
		{
			Alphabet_Status = true;
			break;
		}
	}
	for (int j = 0; j < 8; j++)
	{
		if (Move[1] == Numbers[j])
		{
			Number_Status = true;
			break;
		}
	}
	if (Alphabet_Status && Number_Status)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Move_Piece(string Move, string Uppercase, string Lowercase, string Numbers)
{
	int x, y;
	for (int i = 0; i < 8; i++)
	{
		if (Move[0] == Uppercase[i])
		{
			x = i;
			break;
		}
		else if (Move[0] == Lowercase[i])
		{
			x = i;
			break;
		}
	}
	for (int j = 0; j < 8; j++)
	{
		if (Move[1] == Numbers[j])
		{
			y = j;
			break;
		}
	}
	cout << Layout[x + 2][y + 1];
}

void Move()
{
	string Uppercase = "ABCDEFGH", Lowercase = "abcdefgh", Numbers = "12345678", Move;
	cout << "\n Enter which chess piece do you wanna move: ";
	cin >> Move;
	if (Move.size() < 3 && Move.size() > 0)
	{
		if (Move_Validator(Move, Uppercase, Lowercase, Numbers))
		{
			Move_Piece(Move, Uppercase, Lowercase, Numbers);
		}
		else
		{
			cout << " ! ! ! Invalid Piece Move ! ! !";
		}
	}
	else
	{
		cout << " ! ! ! Invalid Piece Move ! ! !";
	}
}

int main()
{
	Load_And_Update_Board();
	Move();
}