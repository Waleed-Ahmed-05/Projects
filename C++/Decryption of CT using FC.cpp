#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> Frequency_Counter(string CT, string Uppercase, string Lowercase)
{
	vector<int> FC(26, 0);
	for (int i = 0; i < CT.size(); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (CT[i] == Uppercase[j] || CT[i] == Lowercase[j])
			{
				FC[j]++;
			}
		}
	}
	return FC;
}

void Display_Frequency_Count(vector<int> FC, string Uppercase)
{
	cout << "\n";
	for (int i = 0; i < 26; i++)
	{
		cout << Uppercase[i] << ": " << FC[i] << "\n";
	}
}

int Character_Decryption(int Position, int Key)
{
	int DPTK = (Position - Key) % 26;
	if (DPTK < 0)
	{
		DPTK = 26 + DPTK;
	}
	return DPTK;
}

string Decrypt_Cipher_Text(int Key, string Uppercase, string Lowercase, string CT)
{
	string PT;
	bool Symbol_State;
	vector<int> Position = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
	for (int i = 0; i < CT.size(); i++)
	{
		Symbol_State = false;
		for (int j = 0; j < 26; j++)
		{
			if (CT[i] == Uppercase[j])
			{
				PT += Uppercase[Character_Decryption(Position[j], Key)];
				Symbol_State = true;
				break;
			}
			else if (CT[i] == Lowercase[j])
			{
				PT += Lowercase[Character_Decryption(Position[j], Key)];
				Symbol_State = true;
				break;
			}
		}
		if (!Symbol_State)
		{
			PT += CT[i];
		}
	}
	return PT;
}

int main()
{
	string Uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string Lowercase = "abcdefghijklmnopqrstuvwxyz";
	string CT;
	int Key;
	cout << "Enter a cipher text to perform a freqency count: ";
	getline(cin, CT);
	Display_Frequency_Count(Frequency_Counter(CT, Uppercase, Lowercase), Uppercase);
	cout << "\nEnter a key number to begin deciphering the CT: ";
	cin >> Key;
	cout << "\nYou decrypted plain text is '" << Decrypt_Cipher_Text(Key, Uppercase, Lowercase, CT) << "'\n";
}