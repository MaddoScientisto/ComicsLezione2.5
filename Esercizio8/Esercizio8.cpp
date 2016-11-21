// Esercizio8.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "MaddoLib.h"

using namespace std;
using namespace Maddo;

bool IsNumberFive() {
	int value;
	string input = MaddoLib::Input("Inserire un numero diverso da 5: ");
	if (MaddoLib::isInteger(input)) {
		value = MaddoLib::toInt(input);

		return value == 5;
	}

}


int main()
{
	bool exit = false;
	while (!exit) {

		int i = 0;
		bool isValid = false;
		while (!isValid) {
			isValid = IsNumberFive();
			i++;

			if (isValid) {
				MaddoLib::OutputLine("Non devi inserire il numero 5!");
			}
			else if (i >= 10) {
				isValid = true;
				MaddoLib::OutputLine("Complimenti, hai più pazienza di me!");
			}

		}

		exit = MaddoLib::AskYesNo("\nUscire dal programma?");
	}
	return 0;
}


