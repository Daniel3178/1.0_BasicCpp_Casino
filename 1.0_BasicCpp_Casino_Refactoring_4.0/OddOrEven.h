#pragma once
#include "casinoGames.h"


namespace casino
{
	class OddOrEven : public CasinoGames
	{
	public:
		OddOrEven(uint16_t aMinimumBet, uint16_t aMiximumBet);
		void Run(Player* aPlayer, bool& isGameActive,
			std::array<std::array<std::string, 2>, 6>& aStatisticLst) override;
		void PlayOrExit(Player* aPlayer, bool& isGameActive,
			std::array<std::array<std::string, 2>, 6>& aStatisticLst) override;
		void BettingDialouge(casino::Player* aPlayer, casino::CasinoGames* aGame) override;
		void DisplayRules(casino::Player* aPlayer) override;

	private:
	};
}
