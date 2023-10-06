#pragma once
#include "Player.h"
#include "BufferTools.h"
#include <array>

namespace casino {
	struct Player;
	class CasinoGames;
}
namespace statistics
{
	void DisplayStatistic(std::array<std::array<std::string, 2>, 6>& aStatisticLst);
	void SaveStatistic(std::string* aGameName, 
		const std::string* aStatistic, std::array<std::array<std::string, 2>, 6>& aStatisticLst);
	void CheckCurrentGameLimit(casino::Player* aPlayer, casino::CasinoGames* aGame,
		std::array<std::array<std::string, 2>, 6>& aStatisticLst);
	void CheckBudget(casino::Player* aPlayer, bool& isGameActive);
}
