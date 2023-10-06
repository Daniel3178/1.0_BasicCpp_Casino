#pragma once
#include <string>
#include <iostream>

namespace bufferTools {
	std::string IntToString(int anInt);
	void ClearInputBuffer();
	void DisplayCurrentBudget(int& aBudget);
	void DisplayRules();
	char GetUserCharFormat();
	int GetUserIntFormat();
	char GetUserCharInput(unsigned char aCharInputOption);
	void PlayOrExit(std::string const& aGameName, int& aProfitLoss, bool& isGameActive, bool& isKeepPlaying, bool const& isPlayerLegit,
		std::array<std::array<std::string, 2>, 6>& aStatisticLst, const unsigned char aRow);
	enum class CharInputOption
	{
		YesOrNoChoice = 1, CrownAndAnchorSymbolChoice, EvenOrOddChoice
	};
}