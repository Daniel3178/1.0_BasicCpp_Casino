#pragma once
//#include "BufferTools.h"
//#include "Dice.h"
//#include "Statistics.h"
#include "CasinoGames.h"
namespace casino
{
	class Bar_Dice : public CasinoGames
	{
	public:

		Bar_Dice(uint16_t aMinimumBet, uint16_t aMiximumBet);
		void Run(Player* aPlayer, bool& isGameActive,
			std::array<std::array<std::string, 2>, 6>& aStatisticLst) override;
		void PlayOrExit(Player* aPlayer, bool& isGameActive,
			std::array<std::array<std::string, 2>, 6>& aStatisticLst) override;
		void DisplayRules(casino::Player* aPlayer) override;


	};
}