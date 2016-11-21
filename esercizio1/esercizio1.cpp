// esercizio1.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "MaddoLib.h"

using namespace std;
using namespace Maddo;
//Scrivere un programma che permetta al giocatore di inserire il punteggio che ha ottenuto in un gioco, per poi terminare la sua esecuzione. Il punteggio può variare da 0 a 100. Se il giocatore inserisce il punteggio “100”, notiﬁcare al giocatore che ha ottenuto un punteggio perfetto. 

int main()
{
	bool isValid = false;
	string input;
	int score;
	while (!isValid)
	{
		input = MaddoLib::Input("Inserire un punteggio da 1 a 100: ");
		if (MaddoLib::isInteger(input) )
		{
			score = MaddoLib::toInt(input);
			if (score >= 0 && score <= 100)
			{
				isValid = true;
			}
			

		}
	}

	MaddoLib::OutputLine("Punteggio inserito: " + to_string(score));

	if (score == 100)
	{
		MaddoLib::OutputLine("Congratulazioni: Punteggio perfetto!");
	}

    return 0;
}

