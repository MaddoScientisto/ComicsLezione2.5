// Esercizio7.cpp : definisce il punto di ingresso dell'applicazione console.
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
	// attenzione non c'� controllo qui

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

bool IsNumberFive() {
	int value;
	string input = Input("Inserire un numero diverso da 5: ");
	if (isInteger(input)) {
		value = toInt(input);

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
		OutputLine("Non devi inserire il numero 5!");


		exit = AskYesNo("\nUscire dal programma?");
	}
	return 0;
}


