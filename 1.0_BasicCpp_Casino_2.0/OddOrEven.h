#pragma once
#include <string>
#include <iostream>

namespace oddOrEven {

	void RunEvenOrOdd(int& aCurrentBudget, int& aPlayerBet, bool& isGameActive, 
		std::array<std::array<std::string, 2>, 6>& aStatisticLst);
}