#include <iostream>
#include <string>
#include <vector>

using namespace std;

string Layout[12][10] =		{{"    ", " 1 ", " 2 ", " 3 ", " 4 ", " 5 ", " 6 ", " 7 ", " 8 ", "    "},
							{"    ", "___", "___", "___", "___", "___", "___", "___", "___", "    "},
							{" A |", " R ", " k ", " B ", " Q ", " K ", " B ", " k ", " R ", "| A "},
							{" B |", " P ", " P ", " P ", " P ", " P ", " P ", " P ", " P ", "| B "},
							{" C |", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "| C "},
							{" D |", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "| D "},
							{" E |", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "| E "},
							{" F |", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "| F "},
							{" G |", " P ", " P ", " P ", " P ", " P ", " P ", " P ", " P ", "| G "},
							{" H |", " R ", " k ", " B ", " Q ", " K ", " B ", " k ", " R ", "| H "},
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

vector<int> Move_Piece(string Move, string Uppercase, string Lowercase, string Numbers)
{
	vector<int> Location;
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
	Location.push_back(x);
	Location.push_back(y);
	return Location;
}

vector<int> Move()
{
	string Uppercase = "ABCDEFGH", Lowercase = "abcdefgh", Numbers = "12345678", Move;
	vector<int> From_To;
	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			cout << "\n Enter which piece you wanna move: ";
			cin >> Move;
		}
		if (i == 1)
		{
			cout << "\n Enter where do you wanna move the piece: ";
			cin >> Move;
		}
		if (Move.size() < 3 && Move.size() > 0)
		{
			if (Move_Validator(Move, Uppercase, Lowercase, Numbers))
			{
				vector<int> Location = Move_Piece(Move, Uppercase, Lowercase, Numbers);
				From_To.push_back(Location[0] + 2);
				From_To.push_back(Location[1] + 1);
			}
			else
			{
				cout << " ! ! ! Invalid Piece Move ! ! !";
				i--;
			}
		}
		else
		{
			cout << " ! ! ! Invalid Piece Move ! ! !";
			i--;
		}
	}
	return From_To;
}

void Pawn(int x, int y)
{

}

void Rook(int x, int y)
{

}

void Knight(int x, int y)
{

}

void Bishop(int x, int y)
{

}

void Queen(int x, int y)
{

}

void King(int x, int y)
{

}

void Identify_Piece_And_Surroundings(int Piece_Number, int x, int y)
{
	if (Piece_Number == 0)
	{
		Pawn(x, y);
	}
	else if (Piece_Number == 1)
	{
		Rook(x, y);
	}
	else if (Piece_Number == 2)
	{
		Knight(x, y);
	}
	else if (Piece_Number == 3)
	{
		Bishop(x, y);
	}
	else if (Piece_Number == 4)
	{
		Queen(x, y);
	}
	else if (Piece_Number == 5)
	{
		King(x, y);
	}
}

void Is_Move_Piece_Valid(vector<int> From_To)
{
	string Pieces[6] = {" P ", " R " , " k ", " B ", " Q ", " K "};
	int k = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (Layout[From_To[0 + k]][From_To[1 + k]] == Pieces[j])
			{
				Identify_Piece_And_Surroundings(j, From_To[0 + k], From_To[1 + k]);
				//cout << Layout[From_To[0 + k]][From_To[1 + k]];
			}
		}
		k = k + 2;
	}
}

int main()
{
	Load_And_Update_Board();
	vector<int> From_To = Move();
	Is_Move_Piece_Valid(From_To);
	//cout << Layout[From_To[0]][From_To[1]];
	//cout << Layout[From_To[2]][From_To[3]];
}