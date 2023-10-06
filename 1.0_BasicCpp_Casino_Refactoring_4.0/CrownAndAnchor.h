#pragma once
#include "CasinoGames.h"

namespace casino 
{
	class CrownAndAnchor : public CasinoGames
	{
	public:
		CrownAndAnchor(uint16_t aMinimumBet, uint16_t aMaximumBet);
		void Run(Player* aPlayer, bool& isGameActive,
			std::array<std::array<std::string, 2>, 6>& aStatisticLst) override;
		void PlayOrExit(Player* aPlayer, bool& isGameActive,
			std::array<std::array<std::string, 2>, 6>& aStatisticLst) override;
		void BettingDialouge(casino::Player* aPlayer, casino::CasinoGames* aGame) override;
		void DisplayRules(casino::Player* aPlayer) override;

	};

}