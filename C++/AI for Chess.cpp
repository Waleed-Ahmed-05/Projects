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
// Used for loading chess board
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
// Used for validating the input entered from the user such A4, H5 e.t.c
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
// Used for identifying the location of piece that user wants to move from and move it to such as [B,1 - C,1] refers [2,1 - 3,1]
vector<int> Piece_Location(string Move, string Uppercase, string Lowercase, string Numbers)
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
// Used for taking inputs, validate them and finding their locations
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
				vector<int> Location = Piece_Location(Move, Uppercase, Lowercase, Numbers);
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

void Pawn(int x1, int y1, int x2, int y2)
{

}

void Rook(int x1, int y1, int x2, int y2)
{

}

void Knight(int x1, int y1, int x2, int y2)
{

}

void Bishop(int x1, int y1, int x2, int y2y)
{

}

void Queen(int x1, int y1, int x2, int y2)
{

}

void King(int x1, int y1, int x2, int y2)
{

}
// Used for identifying chess pieces and calling their corresponding functions
void Identify_Piece_And_Surroundings(int Piece_Number, int x1, int y1, int x2, int y2)
{
	if (Piece_Number == 0)
	{
		Pawn(x1, y1, x2, y2);
	}
	else if (Piece_Number == 1)
	{
		Rook(x1, y1, x2, y2);
	}
	else if (Piece_Number == 2)
	{
		Knight(x1, y1, x2, y2);
	}
	else if (Piece_Number == 3)
	{
		Bishop(x1, y1, x2, y2);
	}
	else if (Piece_Number == 4)
	{
		Queen(x1, y1, x2, y2);
	}
	else if (Piece_Number == 5)
	{
		King(x1, y1, x2, y2);
	}
}
// Used for moving chess piece based on it's location and their surroundings
void Move_Piece(vector<int> From_To)
{
	string Pieces[6] = {" P ", " R " , " k ", " B ", " Q ", " K "};
	for (int j = 0; j < 6; j++)
	{
		if (Layout[From_To[0]][From_To[1]] == Pieces[j])
		{
			Identify_Piece_And_Surroundings(j, From_To[0], From_To[1], From_To[2], From_To[3]);
			break;
			//cout << Layout[From_To[0 + k]][From_To[1 + k]];
		}
	}
}

int main()
{
	Load_And_Update_Board();
	vector<int> From_To = Move();
	Move_Piece(From_To);
	//cout << Layout[From_To[0]][From_To[1]];
	//cout << Layout[From_To[2]][From_To[3]];
}