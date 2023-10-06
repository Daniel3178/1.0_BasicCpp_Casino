#pragma once

#include "CasinoGames.h"

namespace casino
{
	typedef struct Player Player;
	struct Player {
	
	private:

		std::string playerName;
		int playerTotalBudget;
		int playerBet;
		bool isPlayerLegit;
		bool isPlayerPlaying;

	public:

		Player(std::string aName);
		void IncreasePlayerTotalBudget(const int aValue);
		void DecreasePlayerTotalBudget(const int aValue);
		const int GetPlayerTotalBudget() const;
		void SetPlayerBet(const int aValue);
		const int GetPlayerBet() const;
		void SetPlayerLegit(const bool aBoolean);
		const bool GetPlayerLegit() const;
		void SetPlayerPlayingState(const bool aBoolean);
		const bool GetPlayerPlaying() const;
		const std::string GetPlayerName() const;

	} ;
}