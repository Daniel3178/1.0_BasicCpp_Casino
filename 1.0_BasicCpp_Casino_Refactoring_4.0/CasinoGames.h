#pragma once
#include <iostream>
#include<string>
#include<array>
#include"Player.h"
#include"BufferTools.h"
#include "Statistics.h"
#include "Dice.h"


namespace casino
{
	class CasinoGames
	{
	public:
		CasinoGames( uint16_t aMinimumBet, uint16_t aMaximumBet);
		const int16_t GetMax() const;
		const int16_t GetMin() const;
		void SetProfitLoss(const int aValue);
		void IncreaseProfitLoss(const int aValue);
		void DecreaseProfitLoss(const int aValue);
		const int GetProfitloss() const;
		std::string GetGameName() const;
		virtual void Run(Player* aPlayer,bool& isGameActive,
			std::array<std::array<std::string, 2>, 6>& aStatisticLst);
		virtual void PlayOrExit(Player* aPlayer, bool& isGameActive,
			std::array<std::array<std::string, 2>, 6>& aStatisticLst);
		virtual void BettingDialouge(casino::Player* aPlayer, casino::CasinoGames* aGame);
		virtual void DisplayRules(casino::Player* aPlayer);

	protected:
		int profitLoss;
		int16_t maxProfit;
		int16_t minLoss;
		uint16_t lowestPossibleBet;
		uint16_t highestPossibleBet;
		std::string gameName;

	};


}
