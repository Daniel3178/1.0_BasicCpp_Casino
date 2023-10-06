#pragma once
#include <string>
#include <iostream>

namespace bar_dice {

	typedef unsigned char p_byte;
	int GetUserDiceResult();
	void DisplayBarInfo();
	int GetBotPlayerDiceResult();
	void RunBar_Dice(int& aCurrentBudget, bool& isGameActive,
		std::array<std::array<std::string, 2>, 6>& aStatisticLst, const unsigned char aRow);
}