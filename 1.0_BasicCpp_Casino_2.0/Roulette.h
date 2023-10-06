#pragma once
#include <random>

namespace roulette {
	enum class RouletteBetType {
		Straight = 1, RedOrBlack, EvenOrOdd, ColumnBet, Split, Corner
	};
	enum class Column {
		Column3 = 0, Column1, Column2
	};
	uint8_t GenerateRouletteBollNum();
	int8_t GetStraightNum();
	int8_t GetRedOrBlack_EvenOrOdd(uint8_t anOption);
	int8_t GetColumnNum();
	std::array<int8_t, 4> GetCornerSequence();
	std::array<int8_t, 2> GetSplitSequence();
	bool isNumAmongRed(uint8_t aNum);
	void CalculateTheOutcome(const int8_t* aStringToRead,
		const uint8_t aBetType, int& aCurrentBudget, int& aPlayerBet,
		int& aProfitLoss, bool& aPlayerState, bool& aKeepPlayingState,
		bool& isGameActive, std::array<std::array<std::string, 2>, 6>& aStatisticLst);
	void RunRoulette(int& aCurrentBudget, int& aPlayerBet, bool& isGameActive,
		std::array<std::array<std::string, 2>, 6>& aStatisticLst);
}