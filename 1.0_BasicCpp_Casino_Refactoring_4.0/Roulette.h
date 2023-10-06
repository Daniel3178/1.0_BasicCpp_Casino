#pragma once
#include "CasinoGames.h"
namespace casino
{
	class Roulette : public CasinoGames
	{
	public:
		Roulette(uint16_t aMinimumBet, uint16_t aMiximumBet);
		int8_t GetStraightNum();
		int8_t GetRedOrBlack_EvenOrOdd(uint8_t anOption);
		int8_t GetColumnNum();
		void DisplayRouletteBoard();
		std::array<int8_t, 4> GetCornerSequence();
		std::array<int8_t, 2> GetSplitSequence();
		bool IsNumAmongRed(uint8_t aNum);
		void CalculateTheOutcome(const int8_t* aStringToRead,
			const uint8_t aBetType, Player* aPlayer,
			bool& isGameActive, std::array<std::array<std::string, 2>, 6>& aStatisticLst);
		void Run(Player* aPlayer, bool& isGameActive,
			std::array<std::array<std::string, 2>, 6>& aStatisticLst) override;
		void BettingDialouge(casino::Player* aPlayer, casino::CasinoGames* aGame) override;
		void DisplayRules(casino::Player* aPlayer) override;

		enum class RouletteBetType {
			Straight = 1,
			RedOrBlack,
			EvenOrOdd,
			ColumnBet,
			Split, 
			Corner
		};

		enum class Column {
			Column3 = 0,
			Column1,
			Column2
		};
	};
}
