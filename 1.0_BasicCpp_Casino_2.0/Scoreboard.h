#pragma once
#include <string>
#include <array>
#include <iostream>

namespace scoreboard {

	void DisplayScores(std::array<std::array<std::string, 2>, 6>& aStatisticLst);
	void SaveStatistics(std::string aGameName, std::string aScore, std::array<std::array<std::string, 2>, 6>& aStatisticLst);
	void CheckCurrentGameLimit(const char aGameName[], int* aProfitLoss, bool& aPlayerState, bool& aKeepPlayingState,
		const short& anUperLimit, const short& anLowerLimit, std::array<std::array<std::string, 2>, 6>& aStatisticLst);
	void RunBoard(std::array<std::array<std::string, 2>, 6>& aStatisticLst);
	void CheckBudget(int& aBudget, bool& isGameActive);
	void BettingDialouge(int& aBudget, int& aBet);
}
