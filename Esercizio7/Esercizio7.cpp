// Esercizio7.cpp : definisce il punto di ingresso dell'applicazione console.
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


		bool isValid = false;
		while (!isValid) {
			isValid = IsNumberFive();
		}
		MaddoLib::OutputLine("Non devi inserire il numero 5!");


		exit = MaddoLib::AskYesNo("\nUscire dal programma?");
	}
	return 0;
}


