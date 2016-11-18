// Esercizio9.cpp : definisce il punto di ingresso dell'applicazione console.
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

bool IsThisNumber(int v) {
	int value;
	string input = Input("");
	if (isInteger(input)) {
		value = toInt(input);

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
			OutputLine("Inserire un numero diverso da " + to_string(i));
			isValid = IsThisNumber(i);
			

			if (isValid) {
				OutputLine("Non devi inserire il numero" + to_string(i) + " !");
			}
			i++;
			/*else if (i >= 10) {
				isValid = true;
				OutputLine("Complimenti, hai più pazienza di me!");
			}*/

		}



		exit = AskYesNo("\nUscire dal programma?");
	}
	return 0;
}


