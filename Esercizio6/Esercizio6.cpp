// Esercizio6.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void Output(string text)
{
	cout << text;
}

void OutputLine(string text)
{
	cout << text + "\n";
}

string Input(string description)
{
	string input;
	Output(description);
	cin >> input;
	OutputLine("");
	return input;

}

inline bool isInteger(const std::string & s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char * p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}

inline int toInt(const std::string & s)
{
	char * p;

	return strtol(s.c_str(), &p, 10);
	// attenzione non c'è controllo qui

}

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
		Output(message + " (S/N): ");
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
		Output("1: Very Easy\n2: Easy\n3: Medium\n4: Hard\n5: Very Hard\n");
		input = Input("Inserire un numero da 1 a 5 per denotare la difficoltà: ");
		if (isInteger(input))
		{
			diff = toInt(input);

			if (diff == VeryEasy) {
				input = "Very Easy";
				isValid = true;
			}
			else if (diff == Easy) {
				input = "Easy";
				isValid = true;
			}
			else if (diff == Medium) {
				input = "Medium";
				isValid = true;
			}
			else if (diff == Hard) {
				input = "Hard";
				isValid = true;
			}
			else if (diff == VeryHard) {
				input = "Very Hard";
				isValid = true;
			}
			else {

				input = "Mi dispiace ma questa difficoltà non esiste.";
				isValid = true;
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
		OutputLine("La difficoltà selezionata è: " + diff);

		exit = AskYesNo("Uscire dal programma?");
	}
	return 0;
}


