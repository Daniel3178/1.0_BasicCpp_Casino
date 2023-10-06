#pragma once
#include <string>
#include <iostream>

namespace bar_dice {

	
	uint8_t GetUserDiceResult();
	void DisplayBarInfo();
	uint8_t GetBotPlayerDiceResult();
	void RunBar_Dice(int& aCurrentBudget, bool& isGameActive,
		std::array<std::array<std::string, 2>, 6>& aStatisticLst);
}