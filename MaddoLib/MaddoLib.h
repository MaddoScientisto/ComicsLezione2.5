#pragma once

#include <String>
using namespace std;

namespace Maddo {
	class MaddoLib {
	public:
		static void Output(string text);
		static void OutputLine(string text);
		static string Input(string description);
		static bool isInteger(const std::string & s);
		static int toInt(const std::string & s);
		static bool AskYesNo(string message);

	};
}