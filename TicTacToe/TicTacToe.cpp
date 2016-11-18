// TicTacToe.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>
#include "MaddoLib.h";

using namespace std;
using namespace Maddo;

const int ROWS = 3;
const int COLUMNS = 3;
char board[ROWS][COLUMNS] = { { 'O', 'X', 'O' },
{ ' ', 'X', 'X' },
{ 'X', 'O', 'O' } };

void OutputBoard()
{
	MaddoLib::OutputLine("Stato corrente del campo di gioco:");

	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLUMNS; ++j)
		{
			MaddoLib::Output(to_string(board[i][j]));

		}

		MaddoLib::OutputLine("");
	}
}

bool AskYesNo(string message)
{
	char input;
	MaddoLib::Output(message + " (S/N): ");
	cin >> input;
	MaddoLib::OutputLine(to_string(input));
	while (input != 'S' || input != 'N' || input != 's' || input != 'n')
	{
		MaddoLib::Output("Inserire S (si) o N (no): ");
		cin >> input;
		MaddoLib::OutputLine(to_string(input));
	}

	if (input == 'S' || input == 's')
	{
		return true;
	}
	else if (input == 'N' || input == 'n')
	{
		return false;
	}
	else
	{
		throw std::exception(); // non deve accadere
	}
}

int GetRowColumnNumber()
{
	int value;
	string input;
	bool ok = false;
	while (!ok)
	{
		input = MaddoLib::Input("Inserire riga (0-2): ");
		if (input.length() == 1)
		{
			if (input[0] >= 0 && input[0] <= 2)
			{
				return input[0];
			}
		}
	}
	return 0;
}

void GetCellInput()
{
	int x;
	int y;
	
	
	

}

char GetPlayerCharacter()
{
	bool isValid = false;
	char playerCharacter = 'X'; // Default giusto in caso
	while (!isValid)
	{
		string input = MaddoLib::Input("Inserire il carattere del giocatore (O o X): ");
		if (input.length() == 1 && (input[0] == 'O' || input[0] == 'X'))
		{
			isValid = true;
			playerCharacter = input[0];
			MaddoLib::OutputLine("Il carattere selezionato è: " + input.substr(0,1)); // devo fare così perché altrimenti mi manda in output il valore numerico oppure si corrompe il buffer
		}
		else
		{
			MaddoLib::OutputLine("Carattere non valido: " + input);
		}
	}
	

	return playerCharacter;
}

int main()
{
	char playerCharacter = GetPlayerCharacter();
	
	MaddoLib::OutputLine("Ayy Lmao " + playerCharacter);

	return 0;



	/*OutputBoard();

	cout << "\n'X' moves to the empty location.\n\n";
	board[1][0] = 'X';

	cout << "Now the tic-tac-toe board is:\n";
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLUMNS; ++j)
		{
			cout << board[i][j];
		}

		cout << endl;
	}

	cout << "\n'X' wins!";

	return 0;*/
}

