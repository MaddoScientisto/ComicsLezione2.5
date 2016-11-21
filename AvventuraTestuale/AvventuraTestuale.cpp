// AvventuraTestuale.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "MaddoLib.h";

using namespace std;
using namespace Maddo;

class ChoicesDefinitions
{
public:
	string Choices[4];
	ChoicesDefinitions() { };
	ChoicesDefinitions(string choice1, string choice2, string choice3, string choice4);
};

ChoicesDefinitions::ChoicesDefinitions(string choice1, string choice2, string choice3, string choice4)
{
	Choices[0] = choice1;
	Choices[1] = choice2;
	Choices[2] = choice3;
	Choices[3] = choice4;
}

class Stage {
public:
	int Number;
	string Name;
	string Description;
	ChoicesDefinitions Choices;
	int CorrectChoice;
	Stage();
	Stage(int number, string name, string description, ChoicesDefinitions defs, int correctChoice);
	bool IsChoiceCorrect(int c) {
		return (c == CorrectChoice);
	}
};

Stage::Stage() {  }

Stage::Stage(int number, string name, string description, ChoicesDefinitions defs, int correctChoice)
{
	Number = number;
	Name = name;
	Description = description;
	Choices = defs;
	CorrectChoice = correctChoice;

}

const int stagesCount = 10;

class StagesContainer
{
public:
	Stage stages[stagesCount];
	StagesContainer();
};

StagesContainer Init() {
	StagesContainer container;
	container.stages[0] = Stage(1, "Ingresso", "Sei nel salone principale.",
		ChoicesDefinitions("Esamina le armature", "Sali le scale", "Esamina L'orologio", "Esci"), 2);

	container.stages[1] = Stage(2, "Orologio", "Sei nell'orologio, senti il tempo scorrere.",
		ChoicesDefinitions("Vai avanti", "Vai indietro", "Vai alle 6", "Assaggia gli ingranaggi"), 2);

	container.stages[2] = Stage(3, "Le 6", "Sono le 6, è l'ora del soffi teir.",
		ChoicesDefinitions("Non ho capito", "Entra nel calendario", "Spara le pistole ai pallini", "Palla i pistini alle pallole"), 1);

	container.stages[3] = Stage(4, "Calendario", "Entri nel calendario e ti ritrovi all'interno di marzo, fuoriesci nel castello di prima ma nel passato.",
		ChoicesDefinitions("Sali le scale", "Scendi le scale", "Entra in cucina", "Chiedi al maggiordomo"), 3);

	container.stages[4] = Stage(5, "Il Maggiordomo", "Entri nel maggiordomo. Il suo nome è Battista. \nCosa fai?.",
		ChoicesDefinitions("Sali le scale", "Scendi nello stomaco", "Entra nel pancreas", "Osserva la cistifellea"), 3);

	container.stages[5] = Stage(6, "La Cistifellea del maggiordomo", "In realtà la cistifellea del maggiordomo era un portale per una dimensione perpendicolare.",
		ChoicesDefinitions("Sali le scale", "Scendi dal letto", "Entra in crisi", "Chiedi al maggiordomo"), 1);


	container.stages[6] = Stage(7, "La tua camera", "Ti svegli da un brutto sogno.",
		ChoicesDefinitions("Sali le scale", "Fai colazione", "Entra in cucina", "Chiedi al maggiordomo"), 0);


	container.stages[7] = Stage(8, "Il boss finale", "Ti si para davanti il boss finale: Il mega presidente Trumpinator 9000.\nCosa fai?",
		ChoicesDefinitions("Chiedi le scale", "Attacca il punto debole", "Genuflettiti", "Sali il maggiordomo"), 1);


	container.stages[8] = Stage(9, "Il boss finale Round 2", "Mega presidente Trumpinator 9000 ha coperto il suo punto debole.",
		ChoicesDefinitions("Sali sul boss finale", "Genuflettiti", "Genuflettiti", "Genuflettiti"), 0);


	container.stages[9] = Stage(10, "Epilogo", "Hai sconfitto Mega presidente Trumpinator 9000! O almeno è quello che pensi.\nImprovvisamente si rialza ma tu hai ancora un colpo in canna.\nCosa dici mentre tiri il colpo finale?",
		ChoicesDefinitions("Nothin personnel kid", "Scendi le scale", "Democracy was a mistake", "Chiedi al maggiordomo"), 0);

	return container;
}

bool AskChoice(Stage stage)
{
	bool isValid = false;
	string input;
	int value;
	while (!isValid)
	{
		MaddoLib::OutputLine("Stage " + to_string(stage.Number) + ": " + stage.Name);
		MaddoLib::OutputLine(stage.Description);
		for (int c = 0; c < 4; c++)
		{
			MaddoLib::OutputLine("[" + to_string(c) + "] " + stage.Choices.Choices[c]);
		}

		input = MaddoLib::Input("Effettuare una scelta tramite l'inserimento di un numero da 1 a 4: ");
		if (MaddoLib::isInteger(input)) {
			value = MaddoLib::toInt(input);

			if (value >= 0 && value <= 4)
			{
				isValid = true;
			}
		}
	}

	return (stage.CorrectChoice == value);

}

bool Game()
{
	StagesContainer container = Init();

	for (int stage = 0; stage < stagesCount; stage++)
	{

		if (AskChoice(container.stages[stage]))
		{
			MaddoLib::OutputLine("Puoi avanzare al prossimo stage");
		}
		else
		{
			MaddoLib::OutputLine("Sei morto in qualche maniera.\nGame Over");
			return false;
		}

	}

	MaddoLib::OutputLine("Appagante messaggio di vittoria! \nHai salvato il mondo da qualcosa, adesso puoi chiudere il gioco buonanotte a tutti.");
	MaddoLib::OutputLine("Fine");
	return true;
}

int main()
{
	bool exit = false;

	while (!exit) {

		Game();

		exit = MaddoLib::AskYesNo("\nUscire dal programma?");
	}
	return 0;
}

StagesContainer::StagesContainer()
{

}
