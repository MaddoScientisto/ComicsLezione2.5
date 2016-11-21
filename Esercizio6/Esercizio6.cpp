// Esercizio6.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "MaddoLib.h"

using namespace std;
using namespace Maddo;



// uso stringhe perch� � pi� facile concatenarle tra di loro
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

enum difficulty { VeryEasy = 1, Easy = 2, Medium = 3, Hard = 4, VeryHard = 5 };
string GetDifficulty() {

	bool isValid = false;
	string input;
	int diff;
	while (!isValid)
	{
		MaddoLib::Output("1: Very Easy\n2: Easy\n3: Medium\n4: Hard\n5: Very Hard\n");
		input = MaddoLib::Input("Inserire un numero da 1 a 5 per denotare la difficolt�: ");
		if (MaddoLib::isInteger(input))
		{
			diff = MaddoLib::toInt(input);

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

				input = "Mi dispiace ma questa difficolt� non esiste.";
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
		MaddoLib::OutputLine("La difficolt� selezionata �: " + diff);

		exit = MaddoLib::AskYesNo("Uscire dal programma?");
	}
	return 0;
}


