#pragma once

#include "Player.h"
#include "BufferTools.h"
#include <random>
#include <array>

namespace casino 
{
	struct Player;
	class CasinoGames;
}
namespace dice
{
	std::array<uint8_t, 5> Get5DiceResult();
	uint8_t GetBotPlayerDiceSum();
	uint8_t GetPlayerDiceSum(casino::Player* aPlayer);
	uint8_t GenerateRouletteBollNum();
}