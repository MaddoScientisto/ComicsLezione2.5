
#include "MaddoLib.h"
#include <string>
#include <iostream>

using namespace std;


namespace Maddo {
	void MaddoLib::Output(string text)
	{
		cout << text;
	}

	void MaddoLib::OutputLine(string text)
	{
		cout << text + "\n";
	}

	string MaddoLib::Input(string description)
	{
		string input;
		Output(description);
		cin >> input;
		OutputLine("");
		return input;
	}
	int MaddoLib::InputInt(string description, string notCorrect) {
		bool isValid = false;
		string input;
		int value;
		while (!isValid)
		{
			

			input = MaddoLib::Input(description);
			if (MaddoLib::isInteger(input)) {
				value = MaddoLib::toInt(input);

				if (value >= 0 && value <= 4)
				{
					isValid = true;
				}
			}
		}

		return value;
	}
	bool MaddoLib::isInteger(const std::string & s)
	{
		if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

		char * p;
		strtol(s.c_str(), &p, 10);

		return (*p == 0);
	}
	int MaddoLib::toInt(const std::string & s)
	{
		char * p;

		return strtol(s.c_str(), &p, 10);
		// attenzione non c'è controllo qui
	}
	bool MaddoLib::AskYesNo(string message)
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
}