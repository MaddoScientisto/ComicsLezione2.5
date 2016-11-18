// Esercizio3.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

//Scrivere un programma che permetta al giocatore di inserire il punteggio che ha ottenuto in un gioco, per poi terminare la sua esecuzione. Il punteggio può variare da 0 a 100. Se il giocatore inserisce il punteggio “100”, notiﬁcare al giocatore che ha ottenuto un punteggio perfetto. 



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

int main()
{
	bool exit = false;
	while (!exit) {


		bool isValid = false;
		string input;
		int score;
		while (!isValid)
		{
			input = Input("Inserire un punteggio da 1 a 100: ");
			if (isInteger(input))
			{
				score = toInt(input);
				if (score >= 0 && score <= 100)
				{
					isValid = true;
				}


			}
		}

		OutputLine("Punteggio inserito: " + to_string(score));

		OutputLine("Voto del giocatore: " + Categorize(score));

		exit = AskYesNo("Uscire dal programma?");
	}
	return 0;
}

