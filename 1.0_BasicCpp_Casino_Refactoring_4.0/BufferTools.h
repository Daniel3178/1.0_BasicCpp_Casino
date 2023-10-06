#pragma once

#include "CasinoGames.h"

namespace casino {
	struct Player;
	class CasinoGames;
}

namespace bufferTools 
{
	std::string IntToString(int anInt);
	void ClearInputBuffer();
	char GetPlayerCharFormat();
	int GetPlayerIntFormat();
	int GetPlayerIntGuess(casino::Player* aPlayer);
	char GetPlayerCharAnswer(uint8_t aCharInputOption);
	
	enum class CharInputOption
	{
		YesOrNoChoice = 1, 
		CrownAndAnchorSymbolChoice,
		EvenOrOddChoice,
		Roulette
	};
}