// Esercizio9.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "MaddoLib.h"

using namespace std;
using namespace Maddo;





bool IsThisNumber(int v) {
	int value;
	string input = MaddoLib::Input("");
	if (MaddoLib::isInteger(input)) {
		value = MaddoLib::toInt(input);

		return value == v;
	}

}


int main()
{
	bool exit = false;
	while (!exit) {

		int i = 0;
		bool isValid = false;
		while (!isValid) {
			MaddoLib::OutputLine("Inserire un numero diverso da " + to_string(i));
			isValid = IsThisNumber(i);


			if (isValid) {
				MaddoLib::OutputLine("Non devi inserire il numero " + to_string(i) + " !");
			}
			i++;

		}

		exit = MaddoLib::AskYesNo("\nUscire dal programma?");
	}
	return 0;
}


