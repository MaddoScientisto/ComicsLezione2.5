// Esercizio4.cpp : definisce il punto di ingresso dell'applicazione console.
//


#include "stdafx.h"
#include <iostream>
#include <string>
#include "MaddoLib.h"

using namespace std;
using namespace Maddo;


// uso stringhe perché è più facile concatenarle tra di loro
string Categorize(int score) {
	if (score >= 0 && score <= 59) {
		return "E";
	}
	else if (score >= 60 && score <= 69) {
		return "D";
	}
	else if (score >= 70 && score <= 79) {
		return "C";
	}
	else if (score >= 80 && score <= 89) {
		return "B";
	}
	else if (score >= 90 && score <= 100) {
		return "A";
	}


}

bool AskYesNo(string message)
{
	string input = " ";


	bool valid = false;

	while (!valid)
	{
		MaddoLib::Output(message + " (S/N): ");
		cin >> input;
		if (input[0] == 'S' || input[0] == 'N' || input[0] == 's' || input[0] == 'n') {
			valid = true;
		}

	}

	if (input[0] == 'S' || input[0] == 's')
	{
		return true;
	}
	else if (input[0] == 'N' || input[0] == 'n')
	{
		return false;
	}
	else
	{
		throw std::exception(); // non deve accadere
	}
}
enum difficulty { VeryEasy = 1, Easy = 2, Medium = 3, Hard = 4, VeryHard = 5 };
string GetDifficulty() {

	bool isValid = false;
	string input;
	int diff;
	while (!isValid)
	{
		MaddoLib::Output("1: Very Easy\n2: Easy\n3: Medium\n4: Hard\n5: Very Hard\n");
		input = MaddoLib::Input("Inserire un numero da 1 a 5 per scegliere la difficoltà: ");
		if (MaddoLib::isInteger(input))
		{
			diff = MaddoLib::toInt(input);
			switch (diff) {
			case VeryEasy:
				input = "Very Easy";
				isValid = true;
				break;
			case Easy:
				input = "Easy";
				isValid = true;
				break;
			case Medium:
				input = "Medium";
				isValid = true;
				break;

			case Hard:
				input = "Hard";
				isValid = true;
				break;
			case VeryHard:
				input = "Very Hard";
				isValid = true;
				break;
			default:
				MaddoLib::OutputLine("Valore non valido");
			}

		}
	}

	return input;

}

int main()
{
	bool exit = false;
	while (!exit) {

		string diff = GetDifficulty();
		MaddoLib::OutputLine("La difficoltà selezionata è: " + diff);

		exit = AskYesNo("Uscire dal programma?");
	}
	return 0;
}


