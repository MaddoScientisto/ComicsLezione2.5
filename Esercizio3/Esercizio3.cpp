// Esercizio3.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "MaddoLib.h"

using namespace std;
using namespace Maddo;

//Scrivere un programma che permetta al giocatore di inserire il punteggio che ha ottenuto in un gioco, per poi terminare la sua esecuzione. Il punteggio può variare da 0 a 100. Se il giocatore inserisce il punteggio “100”, notiﬁcare al giocatore che ha ottenuto un punteggio perfetto. 



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



int main()
{
	bool exit = false;
	while (!exit) {

		bool isValid = false;
		string input;
		int score;
		while (!isValid)
		{
			input = MaddoLib::Input("Inserire un punteggio da 1 a 100: ");
			if (MaddoLib::isInteger(input))
			{
				score = MaddoLib::toInt(input);
				if (score >= 0 && score <= 100)
				{
					isValid = true;
				}
			}
		}

		MaddoLib::OutputLine("Punteggio inserito: " + to_string(score));

		MaddoLib::OutputLine("Voto del giocatore: " + Categorize(score));

		exit = MaddoLib::AskYesNo("Uscire dal programma?");
	}
	return 0;
}

