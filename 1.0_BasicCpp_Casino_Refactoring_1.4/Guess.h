#pragma once
#include <string>
#include <array>
#include <iostream>
#include <random>

namespace guess {
	int GetUserGuess();
	std::string GetDieSum();
	void RunGuess(int& aCurrentBudget, int& aPlayerBet, bool& isGameActive,
		std::array<std::array<std::string, 2>, 6>& aStatisticLst, const unsigned char aRow);
}