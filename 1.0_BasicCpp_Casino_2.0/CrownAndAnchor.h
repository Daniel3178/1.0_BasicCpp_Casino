#pragma once
#include <string>
#include <iostream>

namespace crownAndAnchor {
	void RunCrownAndAnchor(int& aCurrentBudget, int& aPlayerBet, bool& isGameActive,
		std::array<std::array<std::string, 2>, 6>& aStatisticLst);
}